from copy import deepcopy
import json
from pathlib import Path
import sys
import tempfile
import unittest
from unittest import mock


SCRIPTS = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(SCRIPTS))
from archive_catalog import apply_contest_mappings
from archive_plan import build_plan


def catalog():
    return {"schemaVersion": 1, "contests": [{
        "id": "qoj:2603", "name": "BAPC 2025",
        "mappingKind": "official_contest_problem_table",
        "sourceUrl": "https://qoj.ac/contest/2603", "verifiedAt": "2026-09-08T05:29:24Z",
        "evidenceUrls": ["https://qoj.ac/problem/14856", "https://qoj.ac/problem/14863"],
        "problemIndices": {f"qoj:{14855+i}": chr(65+i) for i in range(12)},
    }]}


def history():
    return [{"platform": "qoj", "id": sid, "problemId": f"qoj:{pid}", "contestId": None,
             "handle": "Lucius7", "verdict": "AC", "language": "C++23", "epoch": epoch,
             "url": f"https://qoj.ac/submission/{sid}"}
            for sid, pid, epoch in [(2356370, 14856, 1778551752), (2348529, 14863, 1778381633)]]


def dashboard():
    return {"schemaVersion": 2, "handle": "Lucius7", "generatedAt": "2026-09-08T04:01:15Z",
            "contests": [], "attempted": ["qoj:14856", "qoj:14863"], "accepted": [],
            "problems": [{"platform": "qoj", "id": f"qoj:{pid}", "contestId": None,
                          "index": str(pid)} for pid in (14856, 14863)]}


class ArchiveCatalogTests(unittest.TestCase):
    def setUp(self):
        self.temporary = tempfile.TemporaryDirectory()
        self.root = Path(self.temporary.name)

    def tearDown(self):
        self.temporary.cleanup()

    def test_missing_catalog_none_is_compatible_and_performs_no_io(self):
        data = dashboard()
        with mock.patch("builtins.open", side_effect=AssertionError("No catalog I/O allowed")):
            result = apply_contest_mappings(data, history(), None)
        self.assertEqual(result, data)
        self.assertIsNot(result, data)
        result["problems"][0]["index"] = "changed"
        self.assertEqual(data["problems"][0]["index"], "14856")

    def test_complete_table_creates_only_two_submitted_problem_entries(self):
        data, records, supplement = dashboard(), history(), catalog()
        before = deepcopy((data, records, supplement))
        result = apply_contest_mappings(data, records, supplement)
        self.assertEqual((data, records, supplement), before)
        added = result["contests"][0]
        self.assertTrue(added["hasSubmissions"])
        self.assertEqual(len(added["problems"]), 12)
        self.assertEqual(added["catalogSource"]["sourceUrl"], "https://qoj.ac/contest/2603")
        entries = build_plan(result, self.root, records)["entries"]
        self.assertEqual([e["targetStem"] for e in entries], ["QOJ/2603/b", "QOJ/2603/i"])
        self.assertEqual([e["status"] for e in entries], ["missing", "missing"])
        self.assertTrue(all(e["candidates"][0]["contestId"] is None for e in entries))
        self.assertEqual(result["problems"], data["problems"])
        result["contests"][0]["problemIndices"]["qoj:14855"] = "Z"
        self.assertEqual(supplement["contests"][0]["problemIndices"]["qoj:14855"], "A")
        self.assertFalse((self.root / "QOJ").exists())

    def test_no_history_does_not_activate_catalog_or_attempts(self):
        result = apply_contest_mappings(dashboard(), [], catalog())
        self.assertFalse(result["contests"][0]["hasSubmissions"])
        self.assertEqual(build_plan(result, self.root, [])["entries"], [])

    def test_only_real_owner_and_matching_or_unknown_contest_activate(self):
        for change in [{"handle": "OtherUser"}, {"contestId": "qoj:9999"}]:
            records = history()
            for record in records:
                record.update(change)
            result = apply_contest_mappings(dashboard(), records, catalog())
            self.assertFalse(result["contests"][0]["hasSubmissions"])
        records = history()
        for record in records:
            record.update(contestId="qoj:2603", verdict="WA")
        result = apply_contest_mappings(dashboard(), records, catalog())
        self.assertTrue(result["contests"][0]["hasSubmissions"])
        self.assertEqual(build_plan(result, self.root, records)["counts"]["missing"], 2)

    def test_existing_identical_table_is_preserved_and_idempotent(self):
        first = apply_contest_mappings(dashboard(), history(), catalog())
        again = apply_contest_mappings(first, history(), catalog())
        self.assertEqual(first, again)
        self.assertIsNot(first, again)
        first["contests"][0]["customExistingField"] = "preserve"
        self.assertEqual(apply_contest_mappings(first, history(), catalog()), first)

    def test_matching_future_qwq_table_false_flag_keeps_confirmed_archive_tasks(self):
        data = apply_contest_mappings(dashboard(), history(), catalog())
        data["contests"][0]["hasSubmissions"] = False
        data["contests"][0].pop("catalogSource")
        before = deepcopy(data)
        records = history()
        result = apply_contest_mappings(data, records, catalog())
        self.assertEqual(data, before)
        expected = deepcopy(before)
        expected["contests"][0]["hasSubmissions"] = True
        self.assertEqual(result, expected)
        entries = build_plan(result, self.root, records)["entries"]
        self.assertEqual([e["targetStem"] for e in entries], ["QOJ/2603/b", "QOJ/2603/i"])
        self.assertTrue(all(record["contestId"] is None for record in records))
        self.assertEqual(apply_contest_mappings(result, [], catalog()), result)

    def test_existing_contest_conflict_is_rejected_without_mutation(self):
        data = apply_contest_mappings(dashboard(), history(), catalog())
        data["contests"][0]["problemIndices"]["qoj:14856"] = "Z"
        before = deepcopy(data)
        with self.assertRaises(ValueError):
            apply_contest_mappings(data, history(), catalog())
        self.assertEqual(data, before)
        data = dashboard()
        data["contests"] = [{"id": "qoj:2603", "platform": "qoj", "problems": []}]
        with self.assertRaises(ValueError):
            apply_contest_mappings(data, history(), catalog())

    def test_existing_other_contest_or_global_mapping_is_not_overwritten(self):
        data = dashboard()
        data["contests"] = [{"id": "qoj:9999", "platform": "qoj", "problems": ["qoj:14856"]}]
        with self.assertRaisesRegex(ValueError, "another contest"):
            apply_contest_mappings(data, history(), catalog())
        data = dashboard()
        data["problems"][0]["contestId"] = "qoj:9999"
        with self.assertRaisesRegex(ValueError, "another contest"):
            apply_contest_mappings(data, history(), catalog())
        data["problems"][0].update(contestId="qoj:2603", index="Z")
        with self.assertRaisesRegex(ValueError, "index conflicts"):
            apply_contest_mappings(data, history(), catalog())

    def test_duplicate_contest_or_multiple_membership_is_rejected(self):
        data = catalog()
        data["contests"].append(deepcopy(data["contests"][0]))
        with self.assertRaises(ValueError):
            apply_contest_mappings(dashboard(), history(), data)
        data["contests"][1].update(id="qoj:9999", sourceUrl="https://qoj.ac/contest/9999")
        with self.assertRaisesRegex(ValueError, "multiple contests"):
            apply_contest_mappings(dashboard(), history(), data)

    def test_unknown_fields_and_schema_are_rejected(self):
        for location in ("top", "contest"):
            data = catalog()
            target = data if location == "top" else data["contests"][0]
            target["hasSubmissions"] = True
            with self.subTest(location=location), self.assertRaises(ValueError):
                apply_contest_mappings(dashboard(), history(), data)
        for version in (True, 2, "1"):
            data = catalog()
            data["schemaVersion"] = version
            with self.subTest(version=version), self.assertRaises(ValueError):
                apply_contest_mappings(dashboard(), history(), data)

    def test_source_and_evidence_urls_must_be_exact_official_urls(self):
        for url in ["http://qoj.ac/contest/2603", "https://qoj.ac.evil/contest/2603",
                    "https://qoj.ac@evil/contest/2603", "https://qoj.ac/contest/2603?x=1",
                    "https://qoj.ac/contest/2603#x", "https://qoj.ac/contest/2604"]:
            data = catalog()
            data["contests"][0]["sourceUrl"] = url
            with self.subTest(url=url), self.assertRaises(ValueError):
                apply_contest_mappings(dashboard(), history(), data)
        for evidence in [["https://evil/qoj/14856"], ["https://qoj.ac/problem/99999"],
                         ["https://qoj.ac/problem/%31%34%38%35%36"], [],
                         ["https://qoj.ac/problem/14856"] * 2]:
            data = catalog()
            data["contests"][0]["evidenceUrls"] = evidence
            with self.subTest(evidence=evidence), self.assertRaises(ValueError):
                apply_contest_mappings(dashboard(), history(), data)

    def test_ids_indices_and_verification_time_are_strict(self):
        for field, value in [("id", "qoj:../2603"), ("id", "qoj:0"),
                             ("mappingKind", "claimed_submission_contest"),
                             ("verifiedAt", "2026-09-08"), ("verifiedAt", "2026-02-31T05:29:24Z")]:
            data = catalog()
            data["contests"][0][field] = value
            with self.subTest(field=field, value=value), self.assertRaises(ValueError):
                apply_contest_mappings(dashboard(), history(), data)
        for index in ("b", "1", "..", "B/../x", "A"):
            data = catalog()
            data["contests"][0]["problemIndices"]["qoj:14856"] = index
            with self.subTest(index=index), self.assertRaises(ValueError):
                apply_contest_mappings(dashboard(), history(), data)

    def test_invalid_history_cannot_activate_a_contest(self):
        for field, value in [("id", True), ("id", 0), ("epoch", float("nan")),
                             ("url", "https://qoj.ac/submission/2348529"),
                             ("problemId", "qoj:../14856"), ("contestId", "qoj:../2603"),
                             ("handle", "../Lucius7"), ("verdict", "")]:
            records = history()
            records[0][field] = value
            with self.subTest(field=field, value=value), self.assertRaises(ValueError):
                apply_contest_mappings(dashboard(), records, catalog())

    def test_tracked_catalog_preserves_verified_full_bapc_table(self):
        data = json.loads((SCRIPTS.parent / "archive/contest-mappings.json").read_text(encoding="utf-8"))
        item = data["contests"][0]
        self.assertEqual(item["problemIndices"], catalog()["contests"][0]["problemIndices"])
        self.assertEqual(item["evidenceUrls"], catalog()["contests"][0]["evidenceUrls"])
        result = apply_contest_mappings(dashboard(), history(), data)
        self.assertEqual(build_plan(result, self.root, history())["counts"]["missing"], 2)


if __name__ == "__main__":
    unittest.main()
