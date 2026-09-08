"""Pure, offline planning of submitted contest problems and local source files.

``build_plan`` never creates directories, fetches URLs, or changes source files.
Explicit ``submissions`` replaces the dashboard's AC-only candidate history for
the platforms present in that list. Other platforms keep the dashboard fallback.
Dashboard attempts remain visible when history is incomplete. Candidates are
accepted-first, then newest-first; missing language information is preserved as
``None`` for the source-fetching layer to resolve.
"""

from __future__ import annotations

import math
import re
from collections import Counter, defaultdict
from pathlib import Path
from urllib.parse import urlsplit


PLATFORM_DIRS = {"atcoder": "AtCoder", "codeforces": "Codeforces", "qoj": "QOJ"}
SOURCE_EXTENSIONS = frozenset({
    ".cpp", ".cc", ".cxx", ".c++", ".c", ".py", ".pyw", ".java", ".rs",
    ".go", ".kt", ".kts", ".cs", ".js", ".mjs", ".cjs", ".ts", ".tsx",
    ".jsx", ".rb", ".php", ".hs", ".ml", ".fs", ".fsx", ".swift", ".d",
    ".pas", ".p", ".scala", ".pl", ".lua", ".r", ".jl", ".f", ".f90",
    ".f95", ".cob", ".asm",
})
_AC = frozenset({"ac", "ok", "accepted"})


def validate_segment(s: str) -> str:
    """Return an unchanged safe ASCII path component, or raise ValueError."""
    if (not isinstance(s, str) or len(s) > 255 or ".." in s
            or re.fullmatch(r"[A-Za-z0-9_-][A-Za-z0-9_.-]*", s) is None):
        raise ValueError(f"Unsafe path segment: {s!r}")
    return s


def language_extension(language: str) -> str:
    """Map an explicit judge language label to a fixed, dotted source suffix.

    Compiler/version suffixes are allowed, but an unknown language never falls
    back to C++. Missing labels must be resolved before a source file is saved.
    """
    if (not isinstance(language, str) or not language or len(language) > 200
            or ".." in language
            or re.fullmatch(r"[A-Za-z0-9+#()., _-]+", language) is None):
        raise ValueError(f"Unsafe or missing language: {language!r}")
    label = language.strip().lower()
    patterns = (
        (r"(?:gnu |clang )?(?:c\+\+|g\+\+)(?:\d+)?", ".cpp"),
        (r"(?:gnu |clang )?c(?:89|90|99|11|17|18|23)?", ".c"),
        (r"(?:python|pypy)(?:\d+(?:\.\d+)*)?", ".py"),
        (r"(?:java|openjdk)(?:\d+)?", ".java"),
        (r"rust", ".rs"), (r"(?:go|golang)", ".go"),
        (r"kotlin", ".kt"), (r"(?:c#|csharp|mono c#)", ".cs"),
        (r"(?:javascript|node\.js|nodejs)", ".js"),
        (r"typescript", ".ts"), (r"ruby", ".rb"), (r"php", ".php"),
        (r"(?:haskell|ghc)", ".hs"), (r"ocaml", ".ml"),
        (r"(?:f#|fsharp)", ".fs"), (r"swift", ".swift"),
        (r"(?:d|dmd|ldc)", ".d"), (r"(?:pascal|free pascal|fpc)", ".pas"),
        (r"scala", ".scala"), (r"perl", ".pl"), (r"(?:lua|luajit)", ".lua"),
        (r"r", ".r"), (r"julia", ".jl"), (r"(?:fortran|gfortran)", ".f90"),
        (r"(?:cobol|gnucobol)", ".cob"), (r"(?:assembly|nasm)", ".asm"),
    )
    for pattern, extension in patterns:
        if re.match(r"^(?:" + pattern + r")(?=$|[\s(])", label):
            return extension
    raise ValueError(f"Unsupported language: {language!r}")


def _platform(value: str) -> str | None:
    if not isinstance(value, str):
        raise ValueError("Platform must be a string")
    return value if value in PLATFORM_DIRS else None


def _objects(value: list, name: str) -> list[dict]:
    if not isinstance(value, list) or any(not isinstance(item, dict) for item in value):
        raise ValueError(f"{name} must be a list of objects")
    return value


def _contest_id(value: str, platform: str) -> str:
    if not isinstance(value, str) or not value.startswith(platform + ":"):
        raise ValueError(f"Invalid {platform} contest ID: {value!r}")
    slug = validate_segment(value[len(platform) + 1:])
    if platform == "atcoder":
        slug = slug.lower()
    elif re.fullmatch(r"[0-9]+", slug) is None:
        raise ValueError(f"Contest ID must be numeric: {value!r}")
    return platform + ":" + slug


def _problem_id(value: str, platform: str) -> str:
    if not isinstance(value, str) or not value.startswith(platform + ":"):
        raise ValueError(f"Invalid {platform} problem ID: {value!r}")
    slug = value[len(platform) + 1:]
    if platform == "codeforces":
        match = re.fullmatch(r"([0-9]+):([A-Za-z0-9]+)", slug)
        if not match:
            raise ValueError(f"Invalid Codeforces problem ID: {value!r}")
        slug = match[1] + ":" + match[2].upper()
    else:
        validate_segment(slug)
        if platform == "qoj" and not slug.isdigit():
            raise ValueError(f"QOJ problem ID must be numeric: {value!r}")
    return platform + ":" + slug


def _problem_platform(value: str) -> str | None:
    if not isinstance(value, str):
        raise ValueError("Problem ID must be a string")
    return _platform(value.split(":", 1)[0])


def _index(value: str, platform: str) -> str:
    value = validate_segment(value)
    return value.upper() if platform == "codeforces" else value.lower()


def _submission_url(url: str | None, platform: str, submission_id: str) -> str | None:
    """Validate a submission URL and return its contest ID when encoded."""
    if url is None or url == "":
        return None
    if not isinstance(url, str) or any(ord(c) < 32 or ord(c) == 127 for c in url):
        raise ValueError("Invalid submission URL")
    parsed = urlsplit(url)
    hosts = {"atcoder": {"atcoder.jp"}, "codeforces": {"codeforces.com", "www.codeforces.com"},
             "qoj": {"qoj.ac"}}
    if (parsed.scheme != "https" or parsed.netloc not in hosts[platform]
            or parsed.query or parsed.fragment or parsed.username or parsed.password):
        raise ValueError(f"Untrusted submission URL: {url!r}")
    if platform == "atcoder":
        match = re.fullmatch(r"/contests/([A-Za-z0-9_-]+)/submissions/([0-9]+)/?", parsed.path)
    elif platform == "codeforces":
        match = re.fullmatch(r"/(?:contest|gym)/([0-9]+)/submission/([0-9]+)/?", parsed.path)
        if not match:
            match = re.fullmatch(r"/problemset/submission/([0-9]+)/([0-9]+)/?", parsed.path)
    else:
        match = re.fullmatch(r"/submission/([0-9]+)/?", parsed.path)
    if not match or match[match.lastindex] != submission_id:
        raise ValueError(f"Invalid or mismatched submission URL: {url!r}")
    return None if platform == "qoj" else _contest_id(platform + ":" + match[1], platform)


def _candidate(record: dict, handle: str, accepted: bool = False) -> dict | None:
    if not isinstance(record, dict):
        raise ValueError("Submission records must be objects")
    platform = _platform(record.get("platform", ""))
    if platform is None:
        return None
    record_handle = record.get("handle") or handle
    validate_segment(record_handle)
    if record_handle.casefold() != handle.casefold():
        return None
    pid = _problem_id(record.get("problemId"), platform)
    sid = record.get("id")
    if isinstance(sid, bool) or not isinstance(sid, (str, int)) or not re.fullmatch(r"[0-9]+", str(sid)):
        raise ValueError(f"Invalid submission ID: {sid!r}")
    epoch = record.get("epoch", 0)
    if isinstance(epoch, bool) or not isinstance(epoch, (int, float)) or not math.isfinite(epoch) or epoch < 0:
        raise ValueError(f"Invalid submission epoch: {epoch!r}")
    language = record.get("language")
    if language:
        language_extension(language)
    elif language is not None and language != "":
        raise ValueError("Language must be a string or null")
    verdict = record.get("verdict") or ("AC" if accepted else "UNKNOWN")
    if not isinstance(verdict, str) or any(ord(c) < 32 or ord(c) == 127 for c in verdict):
        raise ValueError("Invalid submission verdict")
    explicit_cid = record.get("contestId")
    cid = _contest_id(explicit_cid, platform) if explicit_cid is not None else None
    url = record.get("url")
    url_cid = _submission_url(url, platform, str(sid))
    if cid and url_cid and cid != url_cid:
        raise ValueError("Submission contest ID conflicts with its URL")
    candidate = {"platform": platform, "id": sid, "problemId": pid, "contestId": cid or url_cid,
                 "epoch": epoch, "language": language or None, "verdict": verdict,
                 "url": url, "handle": record_handle}
    if "codeSize" in record:
        size = record["codeSize"]
        if size is not None and (isinstance(size, bool) or not isinstance(size, int) or size < 0):
            raise ValueError("Submission codeSize must be a nonnegative byte count or null")
        candidate["codeSize"] = size
    return candidate


def _existing_sources(root: Path, platform: str, cid: str, index: str, pid: str) -> list[str]:
    parent = root
    for segment in (PLATFORM_DIRS[platform], cid.split(":", 1)[1]):
        parent = parent / validate_segment(segment)
        if parent.is_symlink():
            raise ValueError(f"Source parent is a symlink: {parent}")
        if parent.exists() and not parent.is_dir():
            raise ValueError(f"Source parent is not a directory: {parent}")
    if not parent.exists():
        return []
    problem_slug = pid.split(":", 1)[1]
    aliases = {index}
    if platform == "codeforces":
        number, problem_index = problem_slug.split(":")
        aliases.update({number + problem_index, number + "_" + problem_index})
    else:
        aliases.add(validate_segment(problem_slug))
    found = []
    for path in parent.iterdir():
        if path.stem in aliases and path.suffix.lower() in SOURCE_EXTENSIONS:
            if path.is_symlink():
                raise ValueError(f"Source file is a symlink: {path}")
            if path.is_file():
                found.append(path.relative_to(root).as_posix())
    return sorted(found)


def build_plan(dashboard: dict, root: Path, submissions: list[dict] | None = None) -> dict:
    """Plan source archives for AtCoder, Codeforces and QOJ, without writes.

    Returns ``schemaVersion``, ``handle``, ``dashboardGeneratedAt``, ``entries``
    and status ``counts`` (including ``total``). Every entry has a stable key
    ``contestId/problemId``, canonical relative ``targetStem`` without a suffix,
    all exact existing source aliases, and normalized candidate submissions.
    ``missing`` means candidates exist; ``needs_submission`` means only an
    attempt is known. ``ambiguous`` entries must not be downloaded: their actual
    contest, contest-local index, or target ownership is unresolved. Shared
    problems with unknown submission contests produce ambiguous entries only
    for contests marked as having submissions. Explicit record contests and
    trusted AtCoder/Codeforces submission URLs establish actual participation.

    Unsafe metadata, unsupported specified languages, and symlink source parents
    raise ValueError. The explicitly supplied root is trusted; its own symlink
    and all paths below it are rejected before examining candidate source files.
    """
    if not isinstance(dashboard, dict) or dashboard.get("schemaVersion") != 2:
        raise ValueError("Expected dashboard schemaVersion 2")
    handle = validate_segment(dashboard.get("handle"))
    root = Path(root).absolute()
    if root.is_symlink():
        raise ValueError("Archive root must not be a symlink")
    if root.exists() and not root.is_dir():
        raise ValueError("Archive root must be a directory")
    contests = {}
    memberships = defaultdict(set)
    indices = defaultdict(set)
    catalog = {}
    active = set()
    for contest in _objects(dashboard.get("contests", []), "Contests"):
        platform = _platform(contest.get("platform", ""))
        if platform is None:
            continue
        cid = _contest_id(contest.get("id"), platform)
        contests[cid] = platform
        if contest.get("hasSubmissions") is True:
            active.add(cid)
        mapping = contest.get("problemIndices", {})
        problem_ids = contest.get("problems", [])
        if not isinstance(mapping, dict) or not isinstance(problem_ids, list):
            raise ValueError("Contest problems must be a list and problemIndices an object")
        for raw_pid in problem_ids:
            pid = _problem_id(raw_pid, platform)
            memberships[pid].add(cid)
            if raw_pid in mapping:
                indices[cid, pid].add(_index(mapping[raw_pid], platform))
    for problem in _objects(dashboard.get("problems", []), "Problems"):
        platform = _platform(problem.get("platform", ""))
        if platform is None:
            continue
        pid = _problem_id(problem.get("id"), platform)
        cid = _contest_id(problem["contestId"], platform) if problem.get("contestId") else None
        catalog[pid] = (cid, problem.get("index"))
        if cid in contests:
            memberships[pid].add(cid)
    attempted = set()
    attempted_ids = dashboard.get("attempted", [])
    if not isinstance(attempted_ids, list):
        raise ValueError("Attempted must be a list of problem IDs")
    for raw_pid in attempted_ids:
        platform = _problem_platform(raw_pid)
        if platform is not None:
            attempted.add(_problem_id(raw_pid, platform))
    if submissions is not None and not isinstance(submissions, list):
        raise ValueError("Submissions must be a list or null")
    history_platforms = set()
    for raw in submissions or []:
        if not isinstance(raw, dict):
            raise ValueError("Submission records must be objects")
        platform = _platform(raw.get("platform", ""))
        if platform is not None:
            history_platforms.add(platform)
    raw_records = [(raw, False) for raw in submissions or []]
    raw_records.extend((raw, True) for raw in _objects(dashboard.get("accepted", []), "Accepted")
                       if raw.get("platform") not in history_platforms)
    records = {}
    for raw, is_accepted in raw_records:
        record = _candidate(raw, handle, accepted=is_accepted)
        if record is None:
            continue
        key = (record["platform"], str(record["id"]))
        if key in records and records[key] != record:
            raise ValueError(f"Conflicting duplicate submission: {key}")
        records[key] = record
        attempted.add(record["problemId"])
        if record["contestId"]:
            active.add(record["contestId"])
            contests[record["contestId"]] = record["platform"]
    by_problem = defaultdict(list)
    for record in records.values():
        by_problem[record["problemId"]].append(record)
    entries = []
    for pid in sorted(attempted):
        platform = _problem_platform(pid)
        problem_records = by_problem[pid]
        known = {r["contestId"] for r in problem_records if r["contestId"]}
        unknown = [r for r in problem_records if not r["contestId"]]
        mappings = memberships[pid]
        selected = set(known)
        if unknown or not problem_records:
            selected.update(mappings & active)
        for cid in sorted(selected):
            ambiguous = False
            reason = ""
            candidates = [r for r in problem_records if r["contestId"] == cid]
            if unknown and len(mappings) == 1 and cid in mappings:
                candidates.extend(unknown)
            elif unknown and cid in mappings and cid not in known:
                ambiguous = True
                reason = "Submission contest is unknown and the problem maps to multiple contests"
                candidates.extend(unknown)
            elif not problem_records and len(mappings) > 1:
                ambiguous = True
                reason = "Attempt has no submission record to identify its actual contest"
            possible = indices[cid, pid]
            if len(possible) == 1:
                index = next(iter(possible))
            else:
                catalog_cid, catalog_index = catalog.get(pid, (None, None))
                slug = pid.split(":", 1)[1]
                if platform == "codeforces" and slug.split(":")[0] == cid.split(":")[1]:
                    index = _index(slug.split(":")[1], platform)
                elif catalog_cid == cid and catalog_index is not None:
                    index = _index(catalog_index, platform)
                elif platform == "atcoder" and slug.lower().startswith(cid.split(":")[1] + "_"):
                    index = _index(slug[len(cid.split(":")[1]) + 1:], platform)
                else:
                    index = _index(slug.replace(":", "_"), platform)
                    ambiguous = True
                    reason = "Contest-local problem index is unavailable"
                if len(possible) > 1:
                    ambiguous = True
                    reason = "Conflicting contest-local problem indices"
                if platform == "qoj" and index == slug:
                    ambiguous = True
                    reason = "QOJ global problem ID has no contest-local index mapping"
            candidates.sort(key=lambda r: (r["verdict"].strip().lower() not in _AC,
                                           -r["epoch"], -int(r["id"])))
            existing = _existing_sources(root, platform, cid, index, pid)
            status = "ambiguous" if ambiguous else "existing" if existing else "missing" if candidates else "needs_submission"
            if not reason:
                reason = {"existing": "Source already exists under a recognized filename",
                          "missing": "Submitted problem has candidates but no local source",
                          "needs_submission": "Attempt is known but no submission candidate is available"}[status]
            entries.append({"key": cid + "/" + pid, "platform": platform, "contestId": cid,
                            "problemId": pid, "index": index,
                            "targetStem": "/".join((PLATFORM_DIRS[platform], cid.split(":", 1)[1], index)),
                            "existing": existing, "candidates": candidates, "status": status, "reason": reason})
    targets = Counter(e["targetStem"] for e in entries)
    for entry in entries:
        if targets[entry["targetStem"]] > 1:
            entry["status"] = "ambiguous"
            entry["reason"] = "Multiple problems map to the same target filename"
    counts = {status: 0 for status in ("existing", "missing", "needs_submission", "ambiguous")}
    counts.update(Counter(entry["status"] for entry in entries))
    counts["total"] = len(entries)
    return {"schemaVersion": 1, "handle": handle, "dashboardGeneratedAt": dashboard.get("generatedAt"),
            "entries": entries, "counts": counts}
