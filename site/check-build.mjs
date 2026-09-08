import assert from 'node:assert/strict';
import { readFile, readdir, stat } from 'node:fs/promises';
import path from 'node:path';
import { fileURLToPath } from 'node:url';

const siteRoot = path.dirname(fileURLToPath(import.meta.url));
const output = path.join(siteRoot, '.vitepress/dist');
const base = new URL('https://thelucius7.github.io/CompetitiveProgramming/docs/');
const documents = [];
async function collect(directory) {
  for (const entry of await readdir(directory, { withFileTypes: true })) {
    const full = path.join(directory, entry.name);
    if (entry.isDirectory()) await collect(full);
    else if (entry.name.endsWith('.html')) documents.push(full);
  }
}
await collect(output);
const routeMap = JSON.parse(await readFile(path.join(siteRoot, '.content/routes.json'), 'utf8'));
for (const route of Object.keys(routeMap)) await stat(path.join(output, route.replace(/\.md$/, '.html')));
const checked = new Set();
for (const document of documents) {
  const html = await readFile(document, 'utf8');
  for (const match of html.matchAll(/(?:href|src)="([^"]+)"/g)) {
    const url = new URL(match[1].replaceAll('&amp;', '&'), new URL(path.relative(output, document), base));
    if (url.origin !== base.origin || !url.pathname.startsWith(base.pathname)) continue;
    let local = decodeURIComponent(url.pathname.slice(base.pathname.length));
    if (!local || local.endsWith('/')) local += 'index.html';
    const target = path.resolve(output, local);
    assert(target.startsWith(output + path.sep), `path escaped build: ${url.href}`);
    if (!checked.has(target)) {
      assert((await stat(target)).isFile(), `not a file: ${url.href}`);
      checked.add(target);
    }
    if (url.hash && target.endsWith('.html')) {
      const body = await readFile(target, 'utf8');
      const fragment = decodeURIComponent(url.hash.slice(1));
      assert(body.includes(`id="${fragment}"`), `missing HTML anchor: ${url.href}`);
    }
  }
}
const models = await readFile(path.join(output, 'api/models.html'), 'utf8');
for (const name of ['SiteSnapshot', 'Repository', 'Problem', 'Ratings', 'AtCoderRating', 'CodeforcesRating', 'RecentCommitsSnapshot', 'Commit']) {
  assert(models.includes(`id="${name.toLowerCase()}"`), `missing generated model: ${name}`);
}
await stat(path.join(output, 'api/openapi.json'));
await stat(path.join(output, 'api/site-data.schema.json'));
await stat(path.join(output, 'api/recent-commits.schema.json'));
console.log(`Build OK: ${documents.length} HTML pages, ${checked.size} local targets, all schema model tables.`);
