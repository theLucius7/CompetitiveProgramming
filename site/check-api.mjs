import assert from 'node:assert/strict';
import { execFileSync } from 'node:child_process';
import { readFile } from 'node:fs/promises';
import path from 'node:path';
import { fileURLToPath } from 'node:url';
import Ajv from 'ajv/dist/2020.js';
import addFormats from 'ajv-formats';
import SwaggerParser from '@apidevtools/swagger-parser';

const siteRoot = path.dirname(fileURLToPath(import.meta.url));
const schema = JSON.parse(await readFile(path.join(siteRoot, 'public/api/site-data.schema.json'), 'utf8'));
const specification = path.join(siteRoot, 'public/api/openapi.json');
await SwaggerParser.validate(specification);
const ajv = new Ajv({ strict: true, allErrors: true });
addFormats(ajv);
const validate = ajv.compile(schema);
const source = process.argv[2];
const snapshot = JSON.parse(source
  ? await readFile(path.resolve(source), 'utf8')
  : execFileSync('git', ['show', 'origin/gh-pages:data/site-data.json'], { cwd: siteRoot, encoding: 'utf8', maxBuffer: 16 * 1024 * 1024 }));

function check(value) {
  assert(validate(value), JSON.stringify(validate.errors, null, 2));
  const seen = new Set();
  const languages = { cpp: 'C++', cc: 'C++', cxx: 'C++', c: 'C', py: 'Python', java: 'Java', rs: 'Rust', go: 'Go', kt: 'Kotlin' };
  for (const problem of value.problems) {
    const parts = problem.path.split('/');
    assert(parts.length >= 2 && parts.every((part) => part && part !== '.' && part !== '..'), 'invalid repository path');
    assert(!/[\\\u0000-\u001f\u007f]/.test(problem.path), 'invalid path characters');
    assert(!seen.has(problem.path), `duplicate path: ${problem.path}`);
    seen.add(problem.path);
    assert.equal(problem.platform, parts[0], 'platform mismatch');
    assert.equal(problem.language, languages[parts.at(-1).split('.').at(-1).toLowerCase()], 'language mismatch');
    const encoded = parts.map(encodeURIComponent).join('/');
    const { owner, name, branch } = value.repository;
    assert.equal(problem.githubUrl, `https://github.com/${owner}/${name}/blob/${branch}/${encoded}`, 'GitHub URL mismatch');
    assert.equal(problem.rawUrl, `https://raw.githubusercontent.com/${owner}/${name}/${branch}/${encoded}`, 'raw URL mismatch');
  }
  assert.equal(Object.values(value.contributions).reduce((total, count) => total + count, 0), value.commitCount, 'commit total mismatch');
  for (const rating of Object.values(value.ratings)) {
    if (rating?.rating != null && rating.maxRating != null) assert(rating.maxRating >= rating.rating, 'maximum rating below current rating');
  }
}
check(snapshot);

const invalid = [
  ['missing required field', (s) => { delete s.generatedAt; }],
  ['undeclared field', (s) => { s.schemaVersion = 'invented'; }],
  ['invalid calendar date', (s) => { s.contributions['2026-02-30'] = 1; s.commitCount += 1; }],
  ['invalid count', (s) => { s.commitCount = -1; }],
];
if (snapshot.problems.length) invalid.push(
  ['duplicate path', (s) => { s.problems.push(structuredClone(s.problems[0])); }],
  ['invalid timestamp', (s) => { s.problems[0].submittedAt = 'yesterday'; }],
  ['wrong source URL', (s) => { s.problems[0].rawUrl = 'https://raw.githubusercontent.com/wrong'; }],
);
for (const [name, mutate] of invalid) {
  const broken = structuredClone(snapshot);
  mutate(broken);
  assert.throws(() => check(broken), name);
}
const nullable = structuredClone(snapshot);
nullable.ratings = { atcoder: null, codeforces: null };
if (nullable.problems.length) nullable.problems[0].submittedAt = null;
check(nullable);
console.log(`API contract OK: OpenAPI 3.1, JSON Schema 2020-12, ${snapshot.problems.length} records, ${invalid.length} invalid-data cases rejected.`);
