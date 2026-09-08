import copy
import importlib.util
import tempfile
import unittest
from pathlib import Path


SPEC = importlib.util.spec_from_file_location("archive_plan", Path(__file__).parents[1] / "archive_plan.py")
PLAN = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(PLAN)
build_plan = PLAN.build_plan


def contest(platform, slug, problems, submitted=True, indices=None):
    result = {"id": platform + ":" + slug, "platform": platform,
              "hasSubmissions": submitted, "problems": problems}
    if indices is not None:
        result["problemIndices"] = dict(zip(problems, indices))
    return result


def dashboard(contests=None, attempted=None, accepted=None, problems=None):
    return {"schemaVersion": 2, "handle": "Lucius7", "generatedAt": "2026-09-08T04:01:15Z",
            "contests": contests or [], "attempted": attempted or [],
            "accepted": accepted or [], "problems": problems or []}


def submission(platform="atcoder", pid="atcoder:abc231_a", cid="atcoder:abc231",
               sid=101, epoch=1, verdict="AC", language="GNU C++17", url=None):
    if url is None:
        if platform == "qoj":
            url = f"https://qoj.ac/submission/{sid}"
        elif cid:
            slug = cid.split(":", 1)[1]
            if platform == "atcoder":
                url = f"https://atcoder.jp/contests/{slug}/submissions/{sid}"
            else:
                url = f"https://codeforces.com/contest/{slug}/submission/{sid}"
    return {"platform": platform, "problemId": pid, "contestId": cid, "id": sid,
            "epoch": epoch, "verdict": verdict, "language": language, "url": url, "handle": "Lucius7"}


class ArchivePlanTests(unittest.TestCase):
    def setUp(self):
        self.temporary = tempfile.TemporaryDirectory()
        self.root = Path(self.temporary.name)

    def tearDown(self):
        self.temporary.cleanup()

    def source(self, relative):
        path = self.root / relative
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text("existing source\n", encoding="utf-8")
        return path

    def atcoder(self):
        return dashboard([contest("atcoder", "abc231", ["atcoder:abc231_a", "atcoder:abc231_b", "atcoder:abc231_c"])],
                         ["atcoder:abc231_a", "atcoder:abc231_b"])

    def test_empty_dashboard_and_status_contract(self):
        plan = build_plan(dashboard(), self.root)
        self.assertEqual(plan["schemaVersion"], 1)
        self.assertEqual(plan["handle"], "Lucius7")
        self.assertEqual(plan["dashboardGeneratedAt"], "2026-09-08T04:01:15Z")
        self.assertEqual(plan["entries"], [])
        self.assertEqual(plan["counts"], dict(total=0, existing=0, missing=0, needs_submission=0, ambiguous=0))

    def test_attempted_unsolved_is_kept_and_unattempted_is_not_added(self):
        data = self.atcoder()
        plan = build_plan(data, self.root, [submission()])
        self.assertEqual([e["targetStem"] for e in plan["entries"]], ["AtCoder/abc231/a", "AtCoder/abc231/b"])
        self.assertEqual([e["status"] for e in plan["entries"]], ["missing", "needs_submission"])
        self.assertFalse((self.root / "AtCoder").exists())

    def test_candidates_ac_first_newest_first_including_unsolved(self):
        records = [submission(sid=1, epoch=1, verdict="Accepted"),
                   submission(sid=2, epoch=2, verdict="OK"),
                   submission(sid=3, epoch=5, verdict="WA"),
                   submission(sid=4, epoch=4, verdict="AC"),
                   submission(sid=5, epoch=5, verdict="WA"),
                   submission(pid="atcoder:abc231_b", sid=6, epoch=6, verdict="TLE")]
        plan = build_plan(self.atcoder(), self.root, records)
        self.assertEqual([r["id"] for r in plan["entries"][0]["candidates"]], [4, 2, 1, 5, 3])
        self.assertEqual(plan["entries"][1]["candidates"][0]["verdict"], "TLE")
        self.assertEqual(plan["entries"][1]["status"], "missing")

    def test_dashboard_accepted_fallback_parses_real_contest(self):
        data = self.atcoder()
        data["accepted"] = [{"platform": "atcoder", "id": 101, "problemId": "atcoder:abc231_a",
                             "epoch": 1, "url": "https://atcoder.jp/contests/abc231/submissions/101"}]
        record = build_plan(data, self.root)["entries"][0]["candidates"][0]
        self.assertEqual(record["verdict"], "AC")
        self.assertEqual(record["contestId"], "atcoder:abc231")
        self.assertIsNone(record["language"])
        self.assertEqual(build_plan(data, self.root, [])["entries"][0]["status"], "missing")

    def test_partial_platform_history_keeps_other_platforms_fallback(self):
        data = self.atcoder()
        data["contests"].append(contest("qoj", "3758", ["qoj:18279"], indices=["H"]))
        data["accepted"] = [submission("qoj", "qoj:18279", None)]
        data["accepted"].append(submission(sid=1))
        raw = submission(sid=2, verdict="WA")
        raw["codeSize"] = 1234
        entries = build_plan(data, self.root, [raw])["entries"]
        self.assertEqual([r["id"] for r in entries[0]["candidates"]], [2])
        self.assertEqual(entries[0]["candidates"][0]["codeSize"], 1234)
        self.assertEqual(entries[-1]["platform"], "qoj")
        self.assertEqual(entries[-1]["status"], "missing")

    def test_qoj_global_problem_id_is_existing_alias_of_h(self):
        data = dashboard([contest("qoj", "3758", ["qoj:18279"], indices=["H"])], ["qoj:18279"],
                         problems=[{"id": "qoj:18279", "platform": "qoj", "contestId": "qoj:3758", "index": "18279"}])
        existing = self.source("QOJ/3758/18279.cpp")
        result = build_plan(data, self.root)["entries"][0]
        self.assertEqual(result["targetStem"], "QOJ/3758/h")
        self.assertEqual(result["existing"], ["QOJ/3758/18279.cpp"])
        self.assertEqual(result["status"], "existing")
        self.assertEqual(existing.read_text(), "existing source\n")
        self.assertFalse((self.root / "QOJ/3758/h.cpp").exists())

    def test_existing_multiple_extensions_and_exact_cf_index(self):
        data = dashboard([contest("codeforces", "2200", ["codeforces:2200:C", "codeforces:2200:C1"])],
                         ["codeforces:2200:C", "codeforces:2200:C1"])
        self.source("Codeforces/2200/C1.cpp")
        entries = build_plan(data, self.root)["entries"]
        self.assertEqual(entries[0]["existing"], [])
        self.assertEqual(entries[1]["existing"], ["Codeforces/2200/C1.cpp"])
        self.source("Codeforces/2200/C.py")
        self.source("Codeforces/2200/2200C.rs")
        self.source("Codeforces/2200/C.txt")
        self.assertEqual(build_plan(data, self.root)["entries"][0]["existing"],
                         ["Codeforces/2200/2200C.rs", "Codeforces/2200/C.py"])

    def test_atcoder_case_and_global_task_alias(self):
        data = dashboard([contest("atcoder", "ABC231", ["atcoder:abc231_a"], indices=["A"])], ["atcoder:abc231_a"])
        self.source("AtCoder/abc231/abc231_a.java")
        entry = build_plan(data, self.root)["entries"][0]
        self.assertEqual(entry["contestId"], "atcoder:abc231")
        self.assertEqual(entry["index"], "a")
        self.assertEqual(entry["status"], "existing")

    def test_contests_without_submissions_are_excluded(self):
        data = self.atcoder()
        data["contests"][0]["hasSubmissions"] = False
        self.assertEqual(build_plan(data, self.root)["entries"], [])
        entries = build_plan(data, self.root, [submission(verdict="WA")])["entries"]
        self.assertEqual([e["problemId"] for e in entries], ["atcoder:abc231_a", "atcoder:abc231_b"])

    def test_shared_atcoder_task_only_in_true_submission_contest(self):
        pid = "atcoder:arc067_a"
        data = dashboard([contest("atcoder", "abc052", [pid], indices=["C"]),
                          contest("atcoder", "arc067", [pid], indices=["A"])], [pid])
        record = submission(pid=pid, cid="atcoder:abc052")
        result = build_plan(data, self.root, [record])["entries"]
        self.assertEqual(len(result), 1)
        self.assertEqual(result[0]["targetStem"], "AtCoder/abc052/c")
        record["contestId"] = None
        self.assertEqual(build_plan(data, self.root, [record])["entries"][0]["targetStem"], "AtCoder/abc052/c")

    def test_qoj_shared_unknown_contest_is_ambiguous(self):
        pid = "qoj:18279"
        data = dashboard([contest("qoj", "3758", [pid], indices=["H"]),
                          contest("qoj", "4000", [pid], indices=["A"])], [pid])
        records = [submission("qoj", pid, None)]
        entries = build_plan(data, self.root, records)["entries"]
        self.assertEqual([e["status"] for e in entries], ["ambiguous", "ambiguous"])
        records[0]["contestId"] = "qoj:3758"
        entries = build_plan(data, self.root, records)["entries"]
        self.assertEqual(len(entries), 1)
        self.assertEqual(entries[0]["targetStem"], "QOJ/3758/h")
        self.assertEqual(entries[0]["status"], "missing")

    def test_qoj_multi_mapping_is_ambiguous_even_if_other_contest_inactive(self):
        pid = "qoj:18279"
        data = dashboard([contest("qoj", "3758", [pid], indices=["H"]),
                          contest("qoj", "4000", [pid], submitted=False, indices=["A"])], [pid])
        entries = build_plan(data, self.root, [submission("qoj", pid, None)])["entries"]
        self.assertEqual(len(entries), 1)
        self.assertEqual(entries[0]["status"], "ambiguous")

    def test_qoj_missing_index_is_ambiguous(self):
        data = dashboard([contest("qoj", "3758", ["qoj:18279"])], ["qoj:18279"])
        self.assertEqual(build_plan(data, self.root)["entries"][0]["status"], "ambiguous")

    def test_codeforces_trusted_problemset_and_gym_urls(self):
        data = dashboard([contest("codeforces", "2200", ["codeforces:2200:A"])], ["codeforces:2200:A"])
        for url in ["https://codeforces.com/problemset/submission/2200/101",
                    "https://www.codeforces.com/gym/2200/submission/101"]:
            records = [submission("codeforces", "codeforces:2200:A", None, url=url)]
            self.assertEqual(build_plan(data, self.root, records)["entries"][0]["contestId"], "codeforces:2200")

    def test_codeforces_numeric_problem_indices(self):
        data = dashboard([contest("codeforces", "921", ["codeforces:921:01"])], ["codeforces:921:01"])
        self.assertEqual(build_plan(data, self.root)["entries"][0]["targetStem"], "Codeforces/921/01")

    def test_duplicate_submissions_deduplicated_and_input_unchanged(self):
        data = self.atcoder()
        record = submission()
        records = [record, copy.deepcopy(record)]
        previous = copy.deepcopy((data, records))
        result = build_plan(data, self.root, records)
        self.assertEqual(len(result["entries"][0]["candidates"]), 1)
        self.assertEqual((data, records), previous)
        records[1]["problemId"] = "atcoder:abc231_b"
        with self.assertRaises(ValueError):
            build_plan(data, self.root, records)

    def test_different_handle_and_out_of_scope_platform_are_ignored(self):
        record = submission()
        record["handle"] = "OtherUser"
        result = build_plan(self.atcoder(), self.root, [record, {"platform": "luogu"}])
        self.assertEqual(result["counts"]["needs_submission"], 2)

    def test_target_collisions_are_ambiguous(self):
        data = dashboard([contest("atcoder", "abc231", ["atcoder:abc231_a", "atcoder:abc231_b"], indices=["A", "A"])],
                         ["atcoder:abc231_a", "atcoder:abc231_b"])
        self.assertEqual(build_plan(data, self.root)["counts"]["ambiguous"], 2)

    def test_symlink_source_parents_and_files_are_rejected(self):
        external = self.root / "external"
        external.mkdir()
        (self.root / "AtCoder").symlink_to(external, target_is_directory=True)
        with self.assertRaises(ValueError):
            build_plan(self.atcoder(), self.root)
        (self.root / "AtCoder").unlink()
        (self.root / "AtCoder/abc231").mkdir(parents=True)
        (self.root / "AtCoder/abc231/a.cpp").symlink_to(external / "a.cpp")
        with self.assertRaises(ValueError):
            build_plan(self.atcoder(), self.root)

    def test_unsafe_metadata_rejected(self):
        for unsafe in ["..", "../a", "/tmp/x", "a/b", "a\\b", "a\x00b", "a\nb", "a..b", "C:", "", "."]:
            with self.subTest(segment=repr(unsafe)):
                with self.assertRaises(ValueError):
                    PLAN.validate_segment(unsafe)
                data = self.atcoder()
                data["contests"][0]["problemIndices"] = {"atcoder:abc231_a": unsafe}
                with self.assertRaises(ValueError):
                    build_plan(data, self.root)
        for cid in ["atcoder:../x", "codeforces:22/00", "qoj:x"]:
            data = dashboard([{"id": cid, "platform": cid.split(":")[0], "problems": []}])
            with self.assertRaises(ValueError):
                build_plan(data, self.root)

    def test_unsafe_urls_and_contest_mismatches_rejected(self):
        urls = ["http://atcoder.jp/contests/abc231/submissions/101",
                "https://atcoder.jp.evil.example/contests/abc231/submissions/101",
                "https://atcoder.jp@evil.example/contests/abc231/submissions/101",
                "https://atcoder.jp/contests/abc231/submissions/102",
                "https://atcoder.jp/contests/abc999/submissions/101",
                "https://atcoder.jp/contests/%2e%2e/submissions/101",
                "https://atcoder.jp/contests/abc231/submissions/101?next=evil",
                "https://atcoder.jp/contests/abc231/submissions/101\n",
                "file:///tmp/source.cpp", "javascript:alert(1)"]
        for url in urls:
            with self.subTest(url=url), self.assertRaises(ValueError):
                build_plan(self.atcoder(), self.root, [submission(url=url)])

    def test_invalid_record_values_rejected(self):
        for field, value in [("id", "../1"), ("id", True), ("epoch", float("nan")),
                             ("epoch", -1), ("language", "Unknown 1.0"),
                             ("language", "C++17;touch pwn"), ("problemId", "atcoder:../a"),
                             ("verdict", "AC\n"), ("handle", "../User"), ("codeSize", "123;evil")]:
            with self.subTest(field=field, value=value):
                record = submission()
                record[field] = value
                with self.assertRaises(ValueError):
                    build_plan(self.atcoder(), self.root, [record])

    def test_malformed_collection_shapes_raise_valueerror(self):
        for field, value in [("accepted", [None]), ("contests", ["bad"]),
                             ("problems", {}), ("attempted", "atcoder:abc231_a")]:
            data = self.atcoder()
            data[field] = value
            with self.subTest(field=field), self.assertRaises(ValueError):
                build_plan(data, self.root)

    def test_languages_are_explicit_and_never_default_to_cpp(self):
        labels = {"C++": ".cpp", "GNU G++23 14.2 (64 bit, winlibs)": ".cpp",
                  "C++ 20 (gcc 12.2)": ".cpp", "C11": ".c", "GNU C11 5.1.0": ".c",
                  "Python 3.13": ".py", "PyPy3 (7.3.15)": ".py", "Java 21": ".java",
                  "Rust 1.89": ".rs", "Go 1.24": ".go", "Kotlin 2.2": ".kt",
                  "C# 8, .NET Core 3.1": ".cs", "JavaScript (Node.js 22)": ".js",
                  "TypeScript 5.6": ".ts", "Ruby 3.4": ".rb", "Haskell (GHC 9.8)": ".hs",
                  "OCaml 5.3": ".ml", "F# (.NET 9)": ".fs", "Free Pascal 3.2": ".pas"}
        for label, extension in labels.items():
            with self.subTest(label=label):
                self.assertEqual(PLAN.language_extension(label), extension)
        for label in [None, "", "Brainfuck", "C++evil", "JavaScripty", "Python ../../pwn", "C++\n", "C++;evil"]:
            with self.subTest(label=label), self.assertRaises(ValueError):
                PLAN.language_extension(label)


if __name__ == "__main__":
    unittest.main()
