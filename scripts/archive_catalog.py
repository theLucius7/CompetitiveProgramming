"""Pure additions for officially verified contest problem tables missing in qwq.

These mappings establish archive directory associations. They never assert that
a global problem submission occurred inside a contest session, and never rewrite
submission contest IDs or the caller's dashboard/history objects.
"""

from __future__ import annotations

from collections import defaultdict
from copy import deepcopy
from datetime import datetime
import math
import re

from archive_plan import validate_segment


CATALOG_PATH = "archive/contest-mappings.json"
MAPPING_KIND = "official_contest_problem_table"
_FIELDS = {"id", "name", "mappingKind", "sourceUrl", "verifiedAt", "evidenceUrls", "problemIndices"}


def _qoj_id(value: str) -> str:
    if not isinstance(value, str) or re.fullmatch(r"qoj:[1-9][0-9]*", value) is None:
        raise ValueError(f"Invalid QOJ identifier: {value!r}")
    return value


def _table(value: dict) -> dict[str, str]:
    if not isinstance(value, dict) or not value:
        raise ValueError("problemIndices must be a nonempty object")
    result = {}
    for pid, index in value.items():
        _qoj_id(pid)
        if not isinstance(index, str) or re.fullmatch(r"[A-Z][A-Z0-9]*", index) is None:
            raise ValueError("QOJ contest indices must be explicit uppercase letters/numbers")
        if index in result.values():
            raise ValueError("Duplicate contest-local problem index")
        result[pid] = index
    return result


def _supplements(catalog: dict) -> list[dict]:
    if (not isinstance(catalog, dict) or set(catalog) != {"schemaVersion", "contests"}
            or type(catalog["schemaVersion"]) is not int or catalog["schemaVersion"] != 1
            or not isinstance(catalog["contests"], list)):
        raise ValueError("Expected contest mappings schemaVersion 1 with only contests")
    seen_contests, owners, result = set(), {}, []
    for item in catalog["contests"]:
        if not isinstance(item, dict) or set(item) != _FIELDS:
            raise ValueError("Unknown or missing contest mapping fields")
        cid = _qoj_id(item["id"])
        if cid in seen_contests:
            raise ValueError("Duplicate supplemented contest ID")
        seen_contests.add(cid)
        if item["mappingKind"] != MAPPING_KIND:
            raise ValueError("Only official contest problem-table directory associations are allowed")
        if item["sourceUrl"] != "https://qoj.ac/contest/" + cid.split(":")[1]:
            raise ValueError("Contest sourceUrl must be the matching official QOJ URL")
        name = item["name"]
        if (not isinstance(name, str) or not name.strip() or len(name) > 500
                or any(ord(c) < 32 or ord(c) == 127 for c in name)):
            raise ValueError("Invalid contest name")
        timestamp = item["verifiedAt"]
        if not isinstance(timestamp, str) or re.fullmatch(r"[0-9]{4}-[0-9]{2}-[0-9]{2}T[0-9]{2}:[0-9]{2}:[0-9]{2}Z", timestamp) is None:
            raise ValueError("verifiedAt must be an explicit UTC timestamp")
        datetime.strptime(timestamp, "%Y-%m-%dT%H:%M:%SZ")
        table = _table(item["problemIndices"])
        evidence = item["evidenceUrls"]
        if not isinstance(evidence, list) or not evidence or any(not isinstance(url, str) for url in evidence):
            raise ValueError("evidenceUrls must contain official QOJ problem URLs")
        if len(set(evidence)) != len(evidence):
            raise ValueError("Duplicate problem evidence URL")
        allowed = {"https://qoj.ac/problem/" + pid.split(":")[1] for pid in table}
        if any(url not in allowed for url in evidence):
            raise ValueError("Problem evidence URL must match an included official QOJ problem")
        for pid in table:
            if pid in owners:
                raise ValueError("A supplemented problem cannot be assigned to multiple contests")
            owners[pid] = cid
        result.append(item)
    return result


def _history(submissions: list[dict], handle: str, accepted: list[dict]) -> dict[str, set[str | None]]:
    if not isinstance(submissions, list) or any(not isinstance(row, dict) for row in submissions):
        raise ValueError("Submissions must be a list of standard record objects")
    records = submissions
    # Match build_plan's per-platform fallback: one explicit QOJ record makes
    # that platform's supplied history authoritative, even for another owner.
    if not any(record.get("platform") == "qoj" for record in submissions):
        if not isinstance(accepted, list) or any(not isinstance(row, dict) for row in accepted):
            raise ValueError("Dashboard accepted records must be an object list")
        records = []
        for record in accepted:
            if record.get("platform") == "qoj":
                fallback = dict(record)
                fallback["handle"] = record.get("handle") or handle
                fallback["verdict"] = record.get("verdict") or "AC"
                fallback.setdefault("epoch", 0)
                records.append(fallback)
    associations, seen = defaultdict(set), {}
    for record in records:
        if record.get("platform") != "qoj":
            continue
        owner = validate_segment(record.get("handle"))
        if owner.casefold() != handle.casefold():
            continue
        pid = _qoj_id(record.get("problemId"))
        cid = _qoj_id(record["contestId"]) if record.get("contestId") is not None else None
        sid = record.get("id")
        if isinstance(sid, bool) or not isinstance(sid, (int, str)) or re.fullmatch(r"[1-9][0-9]*", str(sid)) is None:
            raise ValueError("Invalid QOJ submission ID")
        if record.get("url") != "https://qoj.ac/submission/" + str(sid):
            raise ValueError("Submission must have its matching official QOJ URL")
        epoch = record.get("epoch")
        if isinstance(epoch, bool) or not isinstance(epoch, (int, float)) or not math.isfinite(epoch) or epoch < 0:
            raise ValueError("Invalid submission timestamp")
        verdict = record.get("verdict")
        if not isinstance(verdict, str) or not verdict.strip():
            raise ValueError("Submission verdict is required")
        if str(sid) in seen and seen[str(sid)] != (pid, cid):
            raise ValueError("Conflicting QOJ submission identity")
        seen[str(sid)] = (pid, cid)
        associations[pid].add(cid)
    return associations


def apply_contest_mappings(dashboard: dict, submissions: list[dict], catalog: dict | None = None) -> dict:
    """Return an independent dashboard with verified missing contests appended.

    Pass ``None`` when CATALOG_PATH does not exist; this returns a deep copy of
    the unchanged dashboard. Only actual, attributed submission records activate
    a new contest's ``hasSubmissions``; the complete table alone does not activate
    it. An unscoped submission may activate a unique official directory mapping,
    but its original ``contestId`` stays null. Records explicitly associated with
    another contest do not activate this mapping.

    As in build_plan, explicit QOJ history replaces that platform's dashboard AC
    evidence. If no QOJ records were supplied, dashboard.accepted is used under
    the validated dashboard owner; missing verdicts mean AC. These fallback
    records still undergo the same QOJ identity and official-URL checks.

    Existing qwq memberships are never overwritten. Conflicting existing tables,
    another contest claiming a supplemented problem, duplicate supplement claims,
    unsafe URLs/IDs, or unknown catalog fields raise ValueError. An existing
    identical complete table is preserved; actual history may only promote its
    copied ``hasSubmissions`` flag to true, never downgrade it. That flag means
    archive association here, not proof of an in-contest submission session.
    This function performs no I/O and never mutates any of its arguments.
    """
    if not isinstance(dashboard, dict):
        raise ValueError("Dashboard must be an object")
    if catalog is None:
        return deepcopy(dashboard)
    if dashboard.get("schemaVersion") != 2:
        raise ValueError("Expected qwq dashboard schemaVersion 2")
    handle = validate_segment(dashboard.get("handle"))
    supplements = _supplements(catalog)
    history = _history(submissions, handle, dashboard.get("accepted", []))
    contests = dashboard.get("contests", [])
    problems = dashboard.get("problems", [])
    if (not isinstance(contests, list) or not isinstance(problems, list)
            or any(not isinstance(row, dict) for row in [*contests, *problems])):
        raise ValueError("Dashboard contests and problems must be object lists")
    existing, memberships, problem_rows = {}, defaultdict(set), defaultdict(list)
    for contest in contests:
        if contest.get("platform") != "qoj":
            continue
        cid = _qoj_id(contest.get("id"))
        if cid in existing:
            raise ValueError("Duplicate QOJ contest in dashboard")
        existing[cid] = contest
        ids, indices = contest.get("problems", []), contest.get("problemIndices", {})
        if not isinstance(ids, list) or not isinstance(indices, dict):
            raise ValueError("Malformed existing QOJ contest table")
        for pid in [*ids, *indices]:
            memberships[_qoj_id(pid)].add(cid)
    for problem in problems:
        if problem.get("platform") != "qoj":
            continue
        pid = _qoj_id(problem.get("id"))
        problem_rows[pid].append(problem)
        if problem.get("contestId") is not None:
            memberships[pid].add(_qoj_id(problem["contestId"]))
    additions, activations = [], set()
    for item in supplements:
        cid, table = item["id"], item["problemIndices"]
        for pid, index in table.items():
            if memberships[pid] - {cid}:
                raise ValueError(f"Existing qwq mapping gives {pid} another contest; attribution is ambiguous")
            for problem in problem_rows[pid]:
                previous = problem.get("index")
                if (problem.get("contestId") == cid and previous is not None
                        and previous != pid.split(":")[1]
                        and (not isinstance(previous, str) or previous.upper() != index)):
                    raise ValueError(f"Existing qwq problem index conflicts for {pid}")
        has_submissions = any(history[pid] & {None, cid} for pid in table)
        if cid in existing:
            current = existing[cid]
            if (set(current.get("problems", [])) != set(table)
                    or current.get("problemIndices") != table
                    or current.get("url", item["sourceUrl"]) != item["sourceUrl"]):
                raise ValueError(f"Supplement conflicts with existing qwq contest {cid}")
            if has_submissions:
                activations.add(cid)
            continue
        additions.append({
            "id": cid, "platform": "qoj", "name": item["name"], "url": item["sourceUrl"],
            "problems": list(table), "problemIndices": deepcopy(table), "catalogComplete": True,
            "hasSubmissions": has_submissions,
            "catalogSource": {"file": CATALOG_PATH, "mappingKind": MAPPING_KIND,
                              "sourceUrl": item["sourceUrl"], "verifiedAt": item["verifiedAt"],
                              "evidenceUrls": list(item["evidenceUrls"])},
        })
    result = deepcopy(dashboard)
    result.setdefault("contests", []).extend(additions)
    for contest in result["contests"]:
        if contest.get("id") in activations:
            contest["hasSubmissions"] = True
    return result
