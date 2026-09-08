#!/usr/bin/env python3
"""Read-only integrity audit of imported sources; never imports archive_sync."""

from __future__ import annotations

import sys

# Importing the shared, pure language/path helpers must not create bytecode files.
sys.dont_write_bytecode = True

import argparse
from concurrent.futures import ThreadPoolExecutor
from contextlib import contextmanager
import hashlib
import json
import os
from pathlib import Path
import re
import stat

from archive_plan import PLATFORM_DIRS, SOURCE_EXTENSIONS, language_extension, validate_segment


_AC = {"AC", "OK", "ACCEPTED", "AC ✓"}
_STATUSES = {"existing", "missing", "needs_submission", "ambiguous"}


def _parts(relative: str, *, metadata: bool = False) -> tuple[str, ...]:
    if not isinstance(relative, str) or not relative or "\\" in relative:
        raise ValueError("Expected a safe relative path")
    parts = tuple(relative.split("/"))
    for index, part in enumerate(parts):
        if metadata and index == 0 and part == ".archive":
            continue
        if not metadata and index == len(parts) - 1:
            suffix = Path(part).suffix
            if suffix.lower() in SOURCE_EXTENSIONS and ".." not in part:
                validate_segment(part[:-len(suffix)])
                continue
        validate_segment(part)
    return parts


@contextmanager
def _directory(root: Path, parts: tuple[str, ...]):
    """Walk below the trusted root through directory FDs, without symlinks."""
    descriptors = []
    try:
        flags = os.O_RDONLY | os.O_DIRECTORY | os.O_NOFOLLOW
        descriptors.append(os.open(root, flags))
        for part in parts:
            descriptors.append(os.open(part, flags, dir_fd=descriptors[-1]))
        yield descriptors[-1]
    finally:
        for descriptor in reversed(descriptors):
            os.close(descriptor)


def _read(root: Path, relative: str, limit: int, *, optional: bool = False, metadata: bool = False) -> bytes | None:
    parts = _parts(relative, metadata=metadata)
    try:
        with _directory(root, parts[:-1]) as directory:
            descriptor = os.open(parts[-1], os.O_RDONLY | os.O_NOFOLLOW | os.O_NONBLOCK, dir_fd=directory)
            with os.fdopen(descriptor, "rb") as stream:
                information = os.fstat(stream.fileno())
                if not stat.S_ISREG(information.st_mode):
                    raise ValueError(f"Not a regular file: {relative}")
                if information.st_size > limit:
                    raise ValueError(f"File exceeds audit size limit: {relative}")
                body = stream.read(information.st_size + 1)
                if len(body) != information.st_size:
                    raise ValueError(f"File changed while being audited: {relative}")
                return body
    except FileNotFoundError:
        if optional:
            return None
        raise


def _json(root: Path, relative: str, *, optional: bool = False) -> dict | None:
    body = _read(root, relative, 50_000_000, optional=optional, metadata=True)
    if body is None:
        return None
    result = json.loads(body.decode("utf-8"))
    if not isinstance(result, dict):
        raise ValueError(f"Expected a JSON object: {relative}")
    return result


def _identity(row: dict) -> tuple[str, str, str, str]:
    platform = row.get("platform")
    if platform not in PLATFORM_DIRS:
        raise ValueError("Unknown archive platform")
    cid, pid = row.get("contestId"), row.get("problemId")
    prefix = platform + ":"
    if not isinstance(cid, str) or not cid.startswith(prefix):
        raise ValueError("Invalid contest ID")
    contest = validate_segment(cid[len(prefix):])
    if platform == "atcoder" and contest != contest.lower():
        raise ValueError("AtCoder archive contest IDs must be lowercase")
    if platform != "atcoder" and not re.fullmatch(r"[0-9]+", contest):
        raise ValueError("Numeric contest ID required")
    if not isinstance(pid, str) or not pid.startswith(prefix):
        raise ValueError("Invalid problem ID")
    problem = pid[len(prefix):]
    if platform == "codeforces":
        if not re.fullmatch(r"[0-9]+:[A-Z0-9]+", problem):
            raise ValueError("Invalid Codeforces problem ID")
    else:
        validate_segment(problem)
        if platform == "qoj" and not problem.isdigit():
            raise ValueError("Numeric QOJ problem ID required")
    return platform, cid, pid, cid + "/" + pid


def _source_parts(path: str, platform: str, cid: str) -> tuple[str, ...]:
    parts = _parts(path)
    if len(parts) != 3 or parts[:2] != (PLATFORM_DIRS[platform], cid.split(":", 1)[1]):
        raise ValueError("Source path does not match its platform and contest")
    return parts


def _plan_entries(plan: dict, handle: str) -> dict[str, dict]:
    if type(plan.get("schemaVersion")) is not int or plan["schemaVersion"] != 1 or plan.get("handle") != handle or not isinstance(plan.get("entries"), list):
        raise ValueError("Invalid plan schema or owner")
    result = {}
    for entry in plan["entries"]:
        if not isinstance(entry, dict):
            raise ValueError("Plan entries must be objects")
        platform, cid, _, key = _identity(entry)
        if entry.get("key") != key or key in result:
            raise ValueError("Invalid or duplicate plan key")
        _source_parts(entry.get("targetStem"), platform, cid)
        if entry.get("status") not in _STATUSES or not isinstance(entry.get("candidates"), list):
            raise ValueError("Invalid plan status or candidates")
        if not isinstance(entry.get("existing"), list):
            raise ValueError("Invalid existing source list")
        for existing in entry["existing"]:
            _source_parts(existing, platform, cid)
            if Path(existing).suffix.lower() not in SOURCE_EXTENSIONS:
                raise ValueError("Existing plan source has an unsupported extension")
        result[key] = entry
    return result


def _remaining(root: Path, entries: dict[str, dict]) -> dict:
    """Use saved plan membership plus current files; do not regenerate the plan."""
    directories = {}
    counts = {name: 0 for name in ("missing", "needs_submission", "ambiguous")}
    platforms = {name: dict(counts) for name in PLATFORM_DIRS}
    for entry in entries.values():
        platform, cid, _, _ = _identity(entry)
        parts = _source_parts(entry["targetStem"], platform, cid)
        parent = parts[:2]
        if parent not in directories:
            try:
                with _directory(root, parent) as descriptor:
                    directories[parent] = {
                        name: os.stat(name, dir_fd=descriptor, follow_symlinks=False).st_mode
                        for name in os.listdir(descriptor)
                        if Path(name).suffix.lower() in SOURCE_EXTENSIONS
                    }
            except FileNotFoundError:
                directories[parent] = {}
        aliases = {parts[-1] + suffix for suffix in SOURCE_EXTENSIONS}
        aliases.update(Path(path).name for path in entry["existing"])
        exists = False
        for name, mode in directories[parent].items():
            # Uppercase source suffixes remain recognized (e.g. historical .C).
            canonical = Path(name).stem == parts[-1] and Path(name).suffix.lower() in SOURCE_EXTENSIONS
            if canonical or name in aliases:
                if not stat.S_ISREG(mode):
                    raise ValueError(f"Planned source is not a regular file: {'/'.join(parent)}/{name}")
                exists = True
        if entry["status"] == "ambiguous":
            status = "ambiguous"
        elif exists:
            continue
        else:
            status = "missing" if entry["candidates"] else "needs_submission"
        counts[status] += 1
        platforms[platform][status] += 1
    return {"total": sum(counts.values()), **counts, "byPlatform": platforms,
            "basis": "saved_plan_entries_and_current_files"}


def _verify_source(root: Path, job: dict) -> str | None:
    """Read one prevalidated receipt's source; return only a compact error."""
    try:
        body = _read(root, job["path"], 2_000_000)
        if len(body) != job["bytes"] or hashlib.sha256(body).hexdigest() != job["sha256"]:
            raise ValueError("Source bytes or SHA-256 differ from receipt")
        source = body.decode("utf-8")
        if "\r" in source or "\x00" in source or not source.strip():
            raise ValueError("Source must be nonempty UTF-8 with LF line endings and no NUL")
        if job["sourceLines"] is not None and job["sourceLines"] != source.count("\n") + 1:
            raise ValueError("sourceLines differs from LF split count")
        return None
    except (ValueError, OSError, TypeError, KeyError) as error:
        return str(error)


def verify_archive(root: Path) -> dict:
    """Return an audit report; read only inside root and never execute sources.

    ``ok`` is false on any validation error. ``imported`` counts manifest rows;
    ``verified`` counts rows whose files passed every check. When a plan exists,
    ``remaining`` uses its membership and current source files, without writing
    a refreshed plan or recovering a pending import. Absent plans yield null.
    """
    root = Path(root).absolute()
    report = {"schemaVersion": 1, "ok": False, "handle": None, "imported": 0, "verified": 0,
              "byPlatform": {name: 0 for name in PLATFORM_DIRS}, "nonAccepted": 0,
              "planPresent": False, "remaining": None, "errors": []}
    try:
        if root.is_symlink() or not root.is_dir():
            raise ValueError("Archive root must be a real directory")
        manifest = _json(root, "archive/submissions.json")
        if type(manifest.get("schemaVersion")) is not int or manifest["schemaVersion"] != 1 or not isinstance(manifest.get("submissions"), list):
            raise ValueError("Invalid manifest schema")
        handle = validate_segment(manifest.get("handle"))
        report["handle"] = handle
        report["imported"] = len(manifest["submissions"])
        plan = _json(root, ".archive/plan.json", optional=True)
        report["planPresent"] = plan is not None
        entries = _plan_entries(plan, handle) if plan is not None else None
    except (ValueError, OSError, TypeError, KeyError) as error:
        report["errors"].append(str(error))
        return report
    seen_paths, seen_submissions = set(), set()
    jobs, failures = [], {}
    for number, receipt in enumerate(manifest["submissions"], 1):
        label = f"receipt {number}"
        try:
            if not isinstance(receipt, dict):
                raise ValueError("Receipt must be an object")
            platform, cid, _, key = _identity(receipt)
            path = receipt.get("path")
            parts = _source_parts(path, platform, cid)
            label = path
            if path in seen_paths:
                raise ValueError("Duplicate source path")
            seen_paths.add(path)
            sid = receipt.get("id")
            if isinstance(sid, bool) or not isinstance(sid, (str, int)) or not re.fullmatch(r"[1-9][0-9]*", str(sid)):
                raise ValueError("Invalid submission ID")
            identity = (platform, str(sid))
            if identity in seen_submissions:
                raise ValueError("Duplicate platform/submission ID")
            seen_submissions.add(identity)
            if receipt.get("handle") != handle:
                raise ValueError("Receipt owner differs from manifest owner")
            extension = language_extension(receipt.get("language"))
            if Path(parts[-1]).suffix != extension:
                raise ValueError("Source extension differs from receipt language")
            if entries is not None:
                if key not in entries:
                    raise ValueError("Receipt has no matching plan key")
                if path != entries[key]["targetStem"] + extension:
                    raise ValueError("Source path differs from planned target and language")
            if receipt.get("lineEndings") != "LF":
                raise ValueError("Receipt must declare LF line endings")
            if "captureFormat" in receipt and receipt["captureFormat"] not in {"plaintext_pre", "rendered_lines"}:
                raise ValueError("Invalid captureFormat")
            expected_bytes, expected_hash = receipt.get("bytes"), receipt.get("sha256")
            if type(expected_bytes) is not int or not 0 < expected_bytes <= 2_000_000:
                raise ValueError("Invalid receipt byte count")
            if not isinstance(expected_hash, str) or not re.fullmatch(r"[0-9a-f]{64}", expected_hash):
                raise ValueError("Invalid receipt SHA-256")
            lines = None
            if "sourceLines" in receipt:
                lines = receipt["sourceLines"]
                if type(lines) is not int or lines <= 0:
                    raise ValueError("sourceLines must be a positive integer")
            verdict = receipt.get("verdict")
            if not isinstance(verdict, str) or not verdict.strip():
                raise ValueError("Missing submission verdict")
            jobs.append({"number": number, "path": path, "platform": platform,
                         "bytes": expected_bytes, "sha256": expected_hash, "sourceLines": lines,
                         "nonAccepted": verdict.strip().upper() not in _AC})
        except (ValueError, OSError, TypeError, KeyError) as error:
            failures[number] = f"{label}: {error}"
    # At most eight bounded (2 MB each) source reads are in flight. No source
    # contents leave a worker, and results stay deterministic by receipt number.
    if jobs:
        with ThreadPoolExecutor(max_workers=8) as executor:
            for start in range(0, len(jobs), 8):
                batch = jobs[start:start + 8]
                outcomes = executor.map(lambda job: _verify_source(root, job), batch)
                for job, error in zip(batch, outcomes):
                    if error is not None:
                        failures[job["number"]] = f"{job['path']}: {error}"
                    else:
                        report["verified"] += 1
                        report["byPlatform"][job["platform"]] += 1
                        report["nonAccepted"] += job["nonAccepted"]
    report["errors"].extend(failures[number] for number in sorted(failures))
    if entries is not None:
        try:
            report["remaining"] = _remaining(root, entries)
        except (ValueError, OSError, TypeError, KeyError) as error:
            report["errors"].append(f"plan: {error}")
    report["ok"] = not report["errors"]
    return report


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--root", type=Path, default=Path(__file__).resolve().parents[1],
                        help="Repository root to audit (default: this script's repository)")
    args = parser.parse_args(argv)
    result = verify_archive(args.root)
    print(json.dumps(result, ensure_ascii=False, indent=2))
    return 0 if result["ok"] else 1


if __name__ == "__main__":
    raise SystemExit(main())
