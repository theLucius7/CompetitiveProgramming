import copy
import hashlib
import html
import io
import json
from pathlib import Path
import subprocess
import sys
import tempfile
from types import SimpleNamespace
import unittest
from unittest import mock
from urllib.parse import urlencode

SCRIPTS = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(SCRIPTS))
import archive_sync as sync


def source_record():
    code = 'int main() {}\n'
    return {'key': 'atcoder:abc231/atcoder:abc231_a', 'platform': 'atcoder', 'id': 101,
            'contestId': 'atcoder:abc231', 'problemId': 'atcoder:abc231_a',
            'handle': 'Lucius7', 'url': 'https://atcoder.jp/contests/abc231/submissions/101',
            'epoch': 1, 'verdict': 'AC', 'language': 'GNU C++17',
            'codeSize': len(code.encode()), 'code': code}


class ArchiveSyncTests(unittest.TestCase):
    def setUp(self):
        self.temporary = tempfile.TemporaryDirectory()
        self.root = Path(self.temporary.name)
        self.state = self.root / '.archive'
        self.manifest = self.root / 'archive/submissions.json'
        self.patch = mock.patch.multiple(sync, ROOT=self.root, STATE=self.state, MANIFEST=self.manifest)
        self.patch.start()
        self.record = source_record()
        self.dashboard = {
            'schemaVersion': 2, 'handle': 'Lucius7', 'generatedAt': '2026-09-08T04:01:15Z',
            'sources': {'qoj': {'submissionCount': 69}},
            'contests': [
                {'platform': 'atcoder', 'id': 'atcoder:abc231', 'hasSubmissions': True,
                 'problems': ['atcoder:abc231_a'], 'problemIndices': {'atcoder:abc231_a': 'A'}},
                {'platform': 'qoj', 'id': 'qoj:3758', 'hasSubmissions': True,
                 'problems': ['qoj:18279'], 'problemIndices': {'qoj:18279': 'H'}}],
            'problems': [], 'accepted': [self.record], 'attempted': ['atcoder:abc231_a'],
        }
        sync.atomic_json(self.state / 'dashboard.json', self.dashboard)
        sync.atomic_json(self.state / 'atcoder-history.json', [self.record])
        self.entry = sync.build_plan(self.dashboard, self.root, [self.record])['entries'][0]
        self.target = self.root / 'AtCoder/abc231/a.cpp'

    def tearDown(self):
        self.patch.stop()
        self.temporary.cleanup()

    def verify(self, record=None, candidate=None):
        return sync.verify_record(record or self.record, self.entry, candidate or self.record)

    def test_both_page_and_history_sizes_are_verified(self):
        truncated = dict(self.record, code='x', codeSize=1)
        with self.assertRaisesRegex(ValueError, 'history reports'):
            self.verify(truncated)
        with self.assertRaisesRegex(ValueError, 'page reports'):
            self.verify(dict(self.record, codeSize=1))
        for size in (True, 0, -1, 1.5, 'unknown'):
            with self.subTest(size=size), self.assertRaises(ValueError):
                self.verify(dict(self.record, codeSize=size))

    def test_crlf_and_lf_byte_sizes_are_supported_independently(self):
        candidate = dict(self.record, codeSize=2)
        self.assertEqual(self.verify(dict(self.record, code='x\r\n', codeSize='3'), candidate), ('.cpp', b'x\n'))

    def test_language_must_match_candidate_extension(self):
        with self.assertRaisesRegex(ValueError, 'language differs'):
            self.verify(dict(self.record, language='Python 3'))
        self.assertEqual(self.verify(dict(self.record, language='C++ 17'))[0], '.cpp')

    def test_capture_format_and_line_count_are_validated_and_preserved(self):
        captured = dict(self.record, captureFormat='rendered_lines', sourceLines=2)
        self.assertEqual(sync.import_sources([captured])[0]['status'], 'imported')
        receipt = sync.read_json(self.manifest)['submissions'][0]
        self.assertEqual(receipt['captureFormat'], 'rendered_lines')
        self.assertEqual(receipt['sourceLines'], 2)
        self.verify(dict(self.record, captureFormat='plaintext_pre', sourceLines=2))
        for fields in ({'captureFormat': 'unknown'}, {'sourceLines': True}, {'sourceLines': 0}, {'sourceLines': 1}):
            with self.subTest(fields=fields), self.assertRaises(ValueError):
                self.verify(dict(self.record, **fields))

    def test_page_identity_and_accepted_verdict(self):
        for field, value in [('id', 102), ('handle', 'someone'), ('problemId', 'atcoder:abc231_b'),
                             ('contestId', 'atcoder:abc232'), ('verdict', 'WA'),
                             ('url', self.record['url'] + '?other=1'),
                             ('url', self.record['url'].replace('atcoder.jp', 'example.com'))]:
            with self.subTest(field=field), self.assertRaises(ValueError):
                self.verify(dict(self.record, **{field: value}))
        with self.assertRaisesRegex(ValueError, 'accepted'):
            self.verify(dict(self.record, verdict='WA'), dict(self.record, verdict=' AC '))

    def test_empty_nul_oversize_and_malformed_source(self):
        for code in ('', '   ', '\x00', 'x' * 2_000_001, None):
            with self.subTest(code_type=type(code).__name__), self.assertRaises(ValueError):
                self.verify(dict(self.record, code=code))
        with self.assertRaises(ValueError):
            sync.import_sources([None])
        with self.assertRaises(ValueError):
            sync.import_sources([self.record, self.record])

    def test_latest_ac_is_selected_ahead_of_newer_attempt(self):
        newer = dict(self.record, id=102, epoch=20, verdict='WA',
                     url=self.record['url'].replace('/101', '/102'))
        sync.atomic_json(self.state / 'atcoder-history.json', [self.record, newer])
        self.assertEqual(sync.import_sources([newer])[0]['status'], 'error')
        self.assertFalse(self.target.exists())
        self.assertEqual(sync.import_sources([self.record])[0]['status'], 'imported')

    def test_official_catalog_enables_unscoped_qoj_import_without_rewriting_history(self):
        catalog = {'schemaVersion': 1, 'contests': [{
            'id': 'qoj:2603', 'name': 'BAPC 2025',
            'mappingKind': 'official_contest_problem_table',
            'sourceUrl': 'https://qoj.ac/contest/2603',
            'verifiedAt': '2026-09-08T05:29:24Z',
            'evidenceUrls': ['https://qoj.ac/problem/14856'],
            'problemIndices': {'qoj:14855': 'A', 'qoj:14856': 'B', 'qoj:14863': 'I'},
        }]}
        sync.atomic_json(self.root / 'archive/contest-mappings.json', catalog)
        self.dashboard['sources']['qoj']['submissionCount'] = 1
        sync.atomic_json(self.state / 'dashboard.json', self.dashboard)
        dashboard_before = (self.state / 'dashboard.json').read_bytes()
        history_record = {'platform': 'qoj', 'id': 2356370, 'problemId': 'qoj:14856',
                          'contestId': None, 'handle': 'Lucius7', 'epoch': 1778551752,
                          'url': 'https://qoj.ac/submission/2356370',
                          'verdict': 'AC', 'language': 'C++23'}
        envelope = {'records': [history_record], 'pages': [1], 'complete': True, 'expectedCount': 1}
        self.assertEqual(sync.import_qoj_history(envelope)['counts']['missing'], 2)
        entry = next(row for row in sync.current_plan()['entries'] if row['platform'] == 'qoj')
        self.assertEqual(entry['targetStem'], 'QOJ/2603/b')
        self.assertIsNone(entry['candidates'][0]['contestId'])
        record = dict(history_record, key=entry['key'], contestId=entry['contestId'],
                      code='int main() {}\n', captureFormat='plaintext_pre', sourceLines=2)
        self.assertEqual(sync.import_sources([record])[0]['status'], 'imported')
        self.assertEqual((self.root / 'QOJ/2603/b.cpp').read_text(), record['code'])
        self.assertEqual(sync.read_json(self.state / 'qoj-history.json'), envelope)
        self.assertEqual((self.state / 'dashboard.json').read_bytes(), dashboard_before)
        self.assertEqual(sync.current_plan()['counts']['total'], 2)

    def test_import_is_idempotent_and_preserves_existing_aliases(self):
        self.assertEqual(sync.import_sources([self.record])[0]['status'], 'imported')
        self.assertEqual(self.target.read_bytes(), self.record['code'].encode())
        before = self.manifest.read_bytes()
        self.assertEqual(sync.import_sources([self.record])[0]['status'], 'existing')
        self.assertEqual(self.manifest.read_bytes(), before)
        self.assertFalse((self.state / 'pending-import.json').exists())
        self.target.rename(self.target.with_suffix('.cc'))
        self.assertEqual(sync.import_sources([self.record])[0]['status'], 'existing')
        self.assertFalse(self.target.exists())

    def test_existing_files_and_symlink_parents_are_never_overwritten(self):
        self.target.parent.mkdir(parents=True)
        self.target.write_bytes(b'user file')
        self.assertEqual(sync.import_sources([self.record])[0]['status'], 'existing')
        self.assertEqual(self.target.read_bytes(), b'user file')
        with self.assertRaises(ValueError):
            sync.safe_file('../outside.cpp')
        outside = self.root / 'unrelated'
        outside.mkdir()
        (self.root / 'alias').symlink_to(outside, target_is_directory=True)
        with self.assertRaises(ValueError):
            sync.safe_file('alias/a.cpp')

    def test_failed_manifest_write_recovers_receipt_without_rewriting_source(self):
        original = sync.atomic_json
        def fail_manifest(path, value):
            if path == self.manifest:
                raise OSError('simulated unavailable manifest storage')
            return original(path, value)
        with mock.patch.object(sync, 'atomic_json', side_effect=fail_manifest):
            self.assertEqual(sync.import_sources([self.record])[0]['status'], 'error')
        self.assertTrue(self.target.exists())
        inode = self.target.stat().st_ino
        self.assertTrue((self.state / 'pending-import.json').exists())
        self.assertEqual(sync.current_plan()['counts']['existing'], 1)
        receipts = sync.read_json(self.manifest)['submissions']
        self.assertEqual(len(receipts), 1)
        self.assertEqual(receipts[0]['sha256'], hashlib.sha256(self.record['code'].encode()).hexdigest())
        self.assertEqual(self.target.stat().st_ino, inode)
        self.assertIsNone(sync.recover_import())

    def test_interrupted_publication_recovers_complete_temporary_source(self):
        with mock.patch.object(sync.os, 'link', side_effect=OSError('simulated interruption')):
            self.assertEqual(sync.import_sources([self.record])[0]['status'], 'error')
        self.assertFalse(self.target.exists())
        self.assertEqual(sync.recover_import(), 'imported')
        self.assertEqual(self.target.read_text(), self.record['code'])
        self.assertEqual(len(sync.read_json(self.manifest)['submissions']), 1)

    def interrupted_before_publication(self):
        with mock.patch.object(sync.os, 'link', side_effect=OSError('simulated interruption')):
            sync.import_sources([self.record])
        pending = sync.read_json(self.state / 'pending-import.json')
        return self.root / pending['temporary']

    def test_partial_temporary_source_is_discarded_and_can_be_reimported(self):
        temporary = self.interrupted_before_publication()
        temporary.write_bytes(b'int')
        self.assertEqual(sync.recover_import(), 'aborted')
        self.assertFalse(self.target.exists())
        self.assertFalse(temporary.exists())
        self.assertFalse(self.manifest.exists())
        self.assertEqual(sync.import_sources([self.record])[0]['status'], 'imported')

    def test_external_file_racing_publication_is_preserved_not_claimed(self):
        self.interrupted_before_publication()
        self.target.write_bytes(self.record['code'].encode())
        with self.assertRaisesRegex(ValueError, 'not published by this transaction'):
            sync.recover_import()
        self.assertFalse(self.manifest.exists())
        self.assertEqual(self.target.read_bytes(), self.record['code'].encode())

    def qoj_export(self, count=69):
        return {'complete': True, 'expectedCount': count,
                'pages': list(range(1, (count + 9) // 10 + 1)),
                'records': [dict(platform='qoj', handle='Lucius7', id=i + 1,
                                 contestId='qoj:3758', problemId='qoj:18279', epoch=i + 1,
                                 language='C++ 17', verdict='AC', url=f'https://qoj.ac/submission/{i + 1}')
                            for i in range(count)]}

    def test_full_qoj_export_replaces_old_verdicts_and_keeps_other_histories(self):
        old = self.qoj_export()['records']
        old[0]['verdict'] = 'WA'
        sync.atomic_json(self.state / 'qoj-history.json', old)
        result = sync.import_qoj_history(self.qoj_export())
        self.assertEqual(result['qojHistory'], 69)
        stored = sync.read_json(self.state / 'qoj-history.json')
        self.assertTrue(stored['complete'])
        self.assertEqual(stored['records'][0]['verdict'], 'AC')
        self.assertEqual(len(sync.histories()), 70)
        self.assertEqual(sync.import_qoj_history(self.qoj_export(70))['qojHistory'], 70)

    def test_qoj_incomplete_invalid_pages_counts_and_duplicate_ids_are_rejected(self):
        original = self.qoj_export()
        sync.import_qoj_history(original)
        before = (self.state / 'qoj-history.json').read_bytes()
        bad = [original['records'], dict(original, complete=False), dict(original, pages=[1, 2, 4]),
               dict(original, pages=[True, 2, 3, 4, 5, 6, 7]), dict(original, expectedCount=68),
               self.qoj_export(68), dict(original, expectedCount=True)]
        duplicate = copy.deepcopy(original)
        duplicate['records'][1] = duplicate['records'][0]
        bad.append(duplicate)
        wrong_owner = copy.deepcopy(original)
        wrong_owner['records'][0]['handle'] = 'another'
        bad.append(wrong_owner)
        for payload in bad:
            with self.subTest(payload_type=type(payload).__name__), self.assertRaises(ValueError):
                sync.import_qoj_history(payload)
            self.assertEqual((self.state / 'qoj-history.json').read_bytes(), before)

    def test_repository_lock_blocks_a_separate_process(self):
        code = ('import sys; from pathlib import Path; sys.path.insert(0, sys.argv[1]); '
                'import archive_sync as s; s.ROOT=Path(sys.argv[2]); s.STATE=s.ROOT/".archive"; '
                'print("ready",flush=True)\n'
                'with s.repository_lock(): print("acquired",flush=True)\n')
        process = None
        try:
            with sync.repository_lock():
                process = subprocess.Popen([sys.executable, '-B', '-c', code, str(SCRIPTS), str(self.root)],
                                           stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
                self.assertEqual(process.stdout.readline().strip(), 'ready')
                with self.assertRaises(subprocess.TimeoutExpired):
                    process.communicate(timeout=0.15)
            output, error = process.communicate(timeout=5)
            self.assertEqual(process.returncode, 0, error)
            self.assertIn('acquired', output)
        finally:
            if process is not None and process.poll() is None:
                process.kill()
                process.communicate()


class IntakeRequestTests(unittest.TestCase):
    def handler(self, method='POST', *, host='127.0.0.1:4181', origin='http://127.0.0.1:4181',
                token='expected', kind='sources', payload=None):
        handler = object.__new__(sync.intake_handler('expected'))
        body = urlencode({'token': token, 'kind': kind, 'payload': json.dumps(payload or [])}).encode()
        handler.path = '/'
        handler.server = SimpleNamespace(server_port=4181)
        handler.headers = {'Host': host, 'Origin': origin, 'Content-Length': str(len(body)),
                           'Content-Type': 'application/x-www-form-urlencoded'}
        handler.rfile = io.BytesIO(body)
        handler.respond = mock.Mock()
        return handler

    def test_get_rejects_wrong_host_before_exposing_token_or_plan(self):
        handler = self.handler(host='example.com:4181')
        with mock.patch.object(sync, 'current_plan') as planner:
            handler.do_GET()
        self.assertEqual(handler.respond.call_args.args[0], 403)
        planner.assert_not_called()

    def test_queue_is_bounded_without_changing_complete_counts(self):
        handler = self.handler()
        plan = {'counts': {'missing': 51}, 'entries': [
            {'status': 'missing', 'key': f'entry-{number}'} for number in range(51)]}
        with mock.patch.object(sync, 'current_plan', return_value=plan):
            handler.do_GET()
        status, body = handler.respond.call_args.args
        self.assertEqual(status, 200)
        queue = json.loads(html.unescape(body.split('<pre id="queue">', 1)[1].split('</pre>', 1)[0]))
        self.assertEqual(queue['counts']['missing'], 51)
        self.assertEqual(len(queue['entries']), 50)
        self.assertEqual(queue['entries'][-1]['key'], 'entry-49')

    def test_post_rejects_csrf_unknown_kind_and_wrong_host_before_mutation(self):
        for values in ({'origin': 'https://example.com'}, {'host': 'localhost:4181'},
                       {'token': 'wrong'}, {'kind': 'unexpected'}):
            with self.subTest(values=values):
                handler = self.handler(**values)
                with mock.patch.object(sync, 'import_sources') as sources, mock.patch.object(sync, 'import_qoj_history') as qoj:
                    handler.do_POST()
                self.assertEqual(handler.respond.call_args.args[0], 400)
                sources.assert_not_called()
                qoj.assert_not_called()

    def test_valid_form_routes_the_complete_qoj_envelope(self):
        payload = {'records': [], 'pages': [], 'complete': True, 'expectedCount': 0}
        handler = self.handler(kind='qoj-history', payload=payload)
        with mock.patch.object(sync, 'import_qoj_history', return_value={'qojHistory': 69}) as qoj:
            handler.do_POST()
        qoj.assert_called_once_with(payload)
        self.assertEqual(handler.respond.call_args.args[0], 200)


if __name__ == '__main__':
    unittest.main()
