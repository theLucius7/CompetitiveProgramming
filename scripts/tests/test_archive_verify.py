import copy
import hashlib
import importlib.util
import json
import subprocess
import sys
import tempfile
import threading
import unittest
from unittest import mock
from pathlib import Path


SCRIPTS = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(SCRIPTS))
SPEC = importlib.util.spec_from_file_location("archive_verify", SCRIPTS / "archive_verify.py")
VERIFY = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(VERIFY)


class ArchiveVerifyTests(unittest.TestCase):
    def setUp(self):
        self.temporary = tempfile.TemporaryDirectory()
        self.root = Path(self.temporary.name)
        self.source = self.root / "AtCoder/abc231/a.cpp"
        self.source.parent.mkdir(parents=True)
        self.source.write_bytes(b"int main() {}\n")
        self.receipt = {
            "platform": "atcoder", "id": 123, "problemId": "atcoder:abc231_a",
            "contestId": "atcoder:abc231", "handle": "Lucius7", "language": "GNU C++17",
            "verdict": "AC", "path": "AtCoder/abc231/a.cpp", "lineEndings": "LF",
            "captureFormat": "plaintext_pre", "sourceLines": 2,
        }
        self.fingerprint()
        self.manifest = {"schemaVersion": 1, "handle": "Lucius7", "submissions": [self.receipt]}
        self.entry = {
            "key": "atcoder:abc231/atcoder:abc231_a", "platform": "atcoder",
            "contestId": "atcoder:abc231", "problemId": "atcoder:abc231_a",
            "targetStem": "AtCoder/abc231/a", "existing": [],
            "candidates": [{"id": 123}], "status": "missing",
        }
        self.plan = {"schemaVersion": 1, "handle": "Lucius7", "entries": [self.entry]}
        self.save()

    def tearDown(self):
        self.temporary.cleanup()

    def fingerprint(self):
        body = self.source.read_bytes()
        self.receipt.update(bytes=len(body), sha256=hashlib.sha256(body).hexdigest())

    def save(self, with_plan=True):
        (self.root / "archive").mkdir(exist_ok=True)
        (self.root / "archive/submissions.json").write_text(json.dumps(self.manifest), encoding="utf-8")
        if with_plan:
            (self.root / ".archive").mkdir(exist_ok=True)
            (self.root / ".archive/plan.json").write_text(json.dumps(self.plan), encoding="utf-8")

    def audit(self):
        return VERIFY.verify_archive(self.root)

    def test_valid_import_and_stale_plan_remaining_are_read_only(self):
        journal = self.root / ".archive/pending-import.json"
        journal.write_text("do not recover or delete this sentinel", encoding="utf-8")
        before = {str(p.relative_to(self.root)): (p.read_bytes(), p.stat().st_mtime_ns)
                  for p in self.root.rglob("*") if p.is_file()}
        result = self.audit()
        self.assertTrue(result["ok"], result["errors"])
        self.assertEqual(result["imported"], 1)
        self.assertEqual(result["verified"], 1)
        self.assertEqual(result["byPlatform"]["atcoder"], 1)
        self.assertEqual(result["nonAccepted"], 0)
        self.assertEqual(result["remaining"]["total"], 0)
        after = {str(p.relative_to(self.root)): (p.read_bytes(), p.stat().st_mtime_ns)
                 for p in self.root.rglob("*") if p.is_file()}
        self.assertEqual(before, after)

    def test_no_plan_is_allowed_and_remaining_is_unknown(self):
        (self.root / ".archive/plan.json").unlink()
        result = self.audit()
        self.assertTrue(result["ok"])
        self.assertFalse(result["planPresent"])
        self.assertIsNone(result["remaining"])

    def test_empty_manifest_succeeds_but_missing_manifest_fails(self):
        self.manifest["submissions"] = []
        self.save()
        self.assertTrue(self.audit()["ok"])
        (self.root / "archive/submissions.json").unlink()
        self.assertFalse(self.audit()["ok"])

    def test_changed_bytes_missing_file_and_hash_mismatch_fail(self):
        self.source.write_bytes(b"int main() { return 1; }\n")
        self.assertFalse(self.audit()["ok"])
        self.source.unlink()
        self.assertFalse(self.audit()["ok"])

    def test_duplicate_path_and_submission_id_are_rejected(self):
        self.manifest["submissions"].append(copy.deepcopy(self.receipt))
        self.save()
        self.assertIn("Duplicate source path", " ".join(self.audit()["errors"]))
        second = self.manifest["submissions"][1]
        second["path"] = "AtCoder/abc231/b.cpp"
        second["problemId"] = "atcoder:abc231_b"
        second["id"] = "123"
        self.save()
        self.assertIn("Duplicate platform/submission ID", " ".join(self.audit()["errors"]))

    def test_source_content_must_be_utf8_lf_and_nonempty(self):
        for body in [b"int main() {}\r\n", b"int main() {}\r", b"\xff\n", b"\x00\n", b"   \n"]:
            with self.subTest(body=body):
                self.source.write_bytes(body)
                self.fingerprint()
                self.save()
                self.assertFalse(self.audit()["ok"])

    def test_source_lines_counts_final_empty_segment(self):
        for body, count in [(b"x", 1), (b"x\n", 2), (b"x\n\n", 3)]:
            self.source.write_bytes(body)
            self.fingerprint()
            self.receipt["sourceLines"] = count
            self.save()
            self.assertTrue(self.audit()["ok"])
            self.receipt["sourceLines"] = count - 1
            self.save()
            self.assertFalse(self.audit()["ok"])

    def test_optional_capture_fields_follow_intake_contract(self):
        for capture in ["plaintext_pre", "rendered_lines"]:
            self.receipt["captureFormat"] = capture
            self.save()
            self.assertTrue(self.audit()["ok"])
        self.receipt.pop("captureFormat")
        self.receipt.pop("sourceLines")
        self.save()
        self.assertTrue(self.audit()["ok"])
        self.receipt["captureFormat"] = "raw_html"
        self.save()
        self.assertFalse(self.audit()["ok"])

    def test_unsafe_source_paths_fail_before_read(self):
        for path in ["../secret.cpp", "/tmp/secret.cpp", "AtCoder/abc231/../a.cpp",
                     "AtCoder//abc231/a.cpp", "AtCoder\\abc231\\a.cpp", "AtCoder/abc231/a\n.cpp",
                     "Codeforces/abc231/a.cpp", ".archive/a.cpp"]:
            with self.subTest(path=path):
                self.receipt["path"] = path
                self.save()
                self.assertFalse(self.audit()["ok"])

    def test_symlink_source_file_and_parent_are_rejected(self):
        saved = self.root / "original.cpp"
        self.source.rename(saved)
        self.source.symlink_to(saved)
        self.assertFalse(self.audit()["ok"])
        self.source.unlink()
        saved.rename(self.source)
        archive_dir = self.root / "AtCoder"
        archive_dir.rename(self.root / "saved-atcoder")
        archive_dir.symlink_to(self.root / "saved-atcoder", target_is_directory=True)
        self.assertFalse(self.audit()["ok"])

    def test_symlink_metadata_and_symlink_root_are_rejected(self):
        manifest = self.root / "archive/submissions.json"
        actual = self.root / "manifest.json"
        manifest.rename(actual)
        manifest.symlink_to(actual)
        self.assertFalse(self.audit()["ok"])
        manifest.unlink()
        actual.rename(manifest)
        link = self.root / "root-link"
        link.symlink_to(self.root, target_is_directory=True)
        self.assertFalse(VERIFY.verify_archive(link)["ok"])
        (self.root / ".archive/plan.json").rename(self.root / "plan.json")
        (self.root / ".archive/plan.json").symlink_to(self.root / "plan.json")
        self.assertFalse(self.audit()["ok"])

    def test_plan_identity_target_language_and_duplicate_keys_are_checked(self):
        self.entry["targetStem"] = "AtCoder/abc231/b"
        self.save()
        self.assertIn("planned target", " ".join(self.audit()["errors"]))
        self.entry["targetStem"] = "AtCoder/abc231/a"
        self.receipt["language"] = "Python 3"
        self.save()
        self.assertIn("extension", " ".join(self.audit()["errors"]))
        self.receipt["language"] = "GNU C++17"
        self.plan["entries"].append(copy.deepcopy(self.entry))
        self.save()
        self.assertIn("duplicate plan key", " ".join(self.audit()["errors"]))

    def test_invalid_receipt_metadata_is_rejected(self):
        original = copy.deepcopy(self.receipt)
        for field, value in [("bytes", True), ("bytes", 0), ("sha256", "not-a-hash"),
                             ("sourceLines", True), ("lineEndings", "CRLF"), ("id", -1),
                             ("handle", "OtherUser"), ("language", "Unknown"), ("verdict", "")]:
            with self.subTest(field=field):
                self.receipt.clear()
                self.receipt.update(original)
                self.receipt[field] = value
                self.save()
                self.assertFalse(self.audit()["ok"])

    def test_remaining_uses_current_files_and_recognizes_qoj_alias(self):
        second = copy.deepcopy(self.entry)
        second.update(key="atcoder:abc231/atcoder:abc231_b", problemId="atcoder:abc231_b",
                      targetStem="AtCoder/abc231/b", status="existing")
        third = copy.deepcopy(second)
        third.update(key="atcoder:abc231/atcoder:abc231_c", problemId="atcoder:abc231_c",
                     targetStem="AtCoder/abc231/c", candidates=[], status="needs_submission")
        qoj = {"key": "qoj:3758/qoj:18279", "platform": "qoj", "contestId": "qoj:3758",
               "problemId": "qoj:18279", "targetStem": "QOJ/3758/h", "candidates": [],
               "existing": ["QOJ/3758/18279.cpp"], "status": "existing"}
        target = self.root / "QOJ/3758/18279.cpp"
        target.parent.mkdir(parents=True)
        target.write_text("old archive\n", encoding="utf-8")
        self.plan["entries"].extend([second, third, qoj])
        self.save()
        result = self.audit()
        self.assertTrue(result["ok"], result["errors"])
        self.assertEqual(result["remaining"]["missing"], 1)
        self.assertEqual(result["remaining"]["needs_submission"], 1)
        self.assertEqual(result["remaining"]["total"], 2)
        plus_suffix = target.with_suffix(".c++")
        target.rename(plus_suffix)
        qoj["existing"] = ["QOJ/3758/18279.c++"]
        self.save()
        self.assertTrue(self.audit()["ok"])
        self.assertEqual(self.audit()["remaining"]["total"], 2)

    def test_nonaccepted_counts_and_cli_exit_codes_without_execution(self):
        self.receipt["verdict"] = "WA"
        python_source = self.source.with_suffix(".py")
        self.source.rename(python_source)
        self.source = python_source
        self.source.write_bytes(b"raise RuntimeError('archived sources must never execute')\n")
        self.receipt.update(path="AtCoder/abc231/a.py", language="PyPy 3")
        self.fingerprint()
        self.save()
        command = [sys.executable, str(SCRIPTS / "archive_verify.py"), "--root", str(self.root)]
        result = subprocess.run(command, capture_output=True, text=True, check=False, cwd=self.root)
        self.assertEqual(result.returncode, 0, result.stdout + result.stderr)
        self.assertEqual(json.loads(result.stdout)["nonAccepted"], 1)
        self.assertFalse((self.root / "__pycache__").exists())
        self.source.write_bytes(b"changed source")
        result = subprocess.run(command, capture_output=True, text=True, check=False, cwd=self.root)
        self.assertEqual(result.returncode, 1)
        self.assertFalse(json.loads(result.stdout)["ok"])

    def test_source_reads_are_batched_at_most_eight_with_stable_errors(self):
        self.manifest["submissions"] = []
        self.plan["entries"] = []
        for index in range(9):
            letter = chr(ord("a") + index)
            receipt = copy.deepcopy(self.receipt)
            receipt.update(id=index + 1, problemId=f"atcoder:abc231_{letter}",
                           path=f"AtCoder/abc231/{letter}.cpp")
            (self.root / receipt["path"]).write_bytes(b"int main() {}\n")
            entry = copy.deepcopy(self.entry)
            entry.update(key=f"atcoder:abc231/atcoder:abc231_{letter}",
                         problemId=receipt["problemId"], targetStem=f"AtCoder/abc231/{letter}")
            self.manifest["submissions"].append(receipt)
            self.plan["entries"].append(entry)
        self.save()
        original = VERIFY._read
        barrier, lock = threading.Barrier(8), threading.Lock()
        active = peak = calls = 0

        def watched(root, relative, limit, **kwargs):
            nonlocal active, peak, calls
            if not relative.endswith(".cpp"):
                return original(root, relative, limit, **kwargs)
            with lock:
                active += 1
                calls += 1
                peak = max(peak, active)
                position = calls
            try:
                if position <= 8:
                    barrier.wait(timeout=5)
                return original(root, relative, limit, **kwargs)
            finally:
                with lock:
                    active -= 1

        with mock.patch.object(VERIFY, "_read", side_effect=watched):
            result = self.audit()
        self.assertTrue(result["ok"], result["errors"])
        self.assertEqual((peak, calls), (8, 9))
        self.manifest["submissions"][0]["sha256"] = "0" * 64
        self.manifest["submissions"][1]["handle"] = "OtherUser"
        self.save()
        errors = self.audit()["errors"]
        self.assertTrue(errors[0].startswith("AtCoder/abc231/a.cpp:"))
        self.assertTrue(errors[1].startswith("AtCoder/abc231/b.cpp:"))


if __name__ == "__main__":
    unittest.main()
