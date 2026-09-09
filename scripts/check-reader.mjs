#!/usr/bin/env node
// Non-browser regression tests for the standalone reader and native list links.
import assert from 'node:assert/strict';
import { readFileSync, existsSync } from 'node:fs';
import { fileURLToPath } from 'node:url';
import path from 'node:path';
import vm from 'node:vm';

const root = path.resolve(path.dirname(fileURLToPath(import.meta.url)), '..');
const read = (file) => readFileSync(path.join(root, file), 'utf8');
const shared = read('archive.js');
const app = read('app.js');
const readerScript = read('reader.js');
const snapshot = JSON.parse(read('data/site-data.json'));
const recent = JSON.parse(read('data/recent-commits.json'));
const source = 'int main() {\r\n  // <script>alert(1)</script>\r\n  return 0;\r\n}\r\n';
const flush = async () => { for (let i = 0; i < 8; i++) await new Promise(setImmediate); };

class Element {
  constructor(tag = 'div') {
    this.tagName = tag.toUpperCase(); this.children = []; this.dataset = {};
    this.attributes = {}; this.events = {}; this.style = {}; this.hidden = false;
    this.classList = { add() {}, remove() {}, contains() { return false; } };
  }
  set textContent(value) { this.text = value; this.children = []; this.html = ''; }
  get textContent() { return this.text || ''; }
  set innerHTML(value) { this.html = value; }
  get innerHTML() { return this.html || ''; }
  append(...items) { for (const item of items) this.children.push(...(item.tagName === '#FRAGMENT' ? item.children : [item])); }
  replaceChildren(...items) { this.children = []; this.append(...items); }
  setAttribute(key, value) { this.attributes[key] = value; }
  addEventListener(event, callback) { this.events[event] = callback; }
  focus() {}
}

function environment({ page = 'code.html', query = '?path=AtCoder%2Fabc231%2Fa.cpp', mode = 'ok', hljs, failCopy = false, codeText = source } = {}) {
  const html = read(page);
  const elements = new Map([...html.matchAll(/\bid="([^"]+)"/g)].map((m) => [m[1], new Element()]));
  const timers = new Map(), requests = [], copies = [];
  let sequence = 0;
  const context = {
    console, URLSearchParams, URL, AbortController,
    document: {
      title: '', activeElement: new Element('body'),
      querySelector(selector) { const result = elements.get(selector.slice(1)); assert(result, 'unknown selector ' + selector); return result; },
      createElement: (tag) => new Element(tag), createDocumentFragment: () => new Element('#fragment'), addEventListener() {},
    },
    window: {
      location: { search: query }, hljs,
      setTimeout(callback, delay) { const id = ++sequence; timers.set(id, { callback, delay }); return id; },
      clearTimeout(id) { timers.delete(id); },
    },
    navigator: { clipboard: { async writeText(text) { if (failCopy) throw new Error('denied'); copies.push(text); } } },
    async fetch(url, options = {}) {
      requests.push({ url, options });
      const metadata = url === './data/site-data.json';
      const content = url.includes('/contents/');
      if ((mode === 'metadata-hang' && metadata) || mode === 'hang') {
        return new Promise((resolve, reject) => options.signal.addEventListener('abort', () => reject(new Error('timeout')), { once: true }));
      }
      if ((mode === 'all-fail') || (mode === 'fallback' && content) || (mode === 'metadata-fail' && metadata)) return { ok: false, status: 503 };
      let body;
      if (metadata) body = JSON.stringify(snapshot);
      else if (url.includes('recent-commits.json')) body = JSON.stringify(recent);
      else if (url.includes('/git/trees/')) body = JSON.stringify({ truncated: false, tree: snapshot.problems.map((p) => ({ type: 'blob', path: p.path })) });
      else if (url.includes('/commits?')) body = JSON.stringify(recent.commits.map((c) => ({ sha: c.sha, commit: { message: c.subject, committer: { date: c.committedAt } } })));
      else body = mode === 'empty' ? '' : codeText;
      return { ok: true, text: async () => body };
    },
  };
  vm.createContext(context);
  vm.runInContext(shared, context);
  vm.runInContext(page === 'code.html' ? readerScript : app, context);
  return { context, elements, timers, requests, copies, run: (code) => vm.runInContext(code, context) };
}

const normal = environment();
await flush();
assert.equal(normal.run('readerState.problem.path'), 'AtCoder/abc231/a.cpp');
assert.equal(normal.elements.get('reader-state').hidden, true);
assert.equal(normal.elements.get('reader-state').attributes['aria-busy'], 'false');
assert.equal(normal.elements.get('code-scroller').hidden, false);
assert.equal(normal.elements.get('line-numbers').textContent, '1\n2\n3\n4');
assert.equal(normal.elements.get('reader-lines').textContent, '4 行');
assert(normal.elements.get('code-content').textContent.includes('<script>'));
assert.equal(normal.elements.get('code-content').innerHTML, '');
await normal.run('copyCode()');
assert.equal(normal.copies[0], source, 'copy must preserve original CRLF');
assert.equal(normal.requests.length, 2, 'reader must not load tree or recent commits');

const longSource = Array.from({ length: 10000 }, (_, index) => `// source line ${index + 1}`).join('\n');
const longFile = environment({ codeText: longSource }); await flush();
assert.equal(longFile.elements.get('reader-lines').textContent, '10000 行');
assert.equal(longFile.elements.get('code-content').textContent, longSource);
assert(longFile.elements.get('line-numbers').textContent.endsWith('\n10000'));
await longFile.run('copyCode()'); assert.equal(longFile.copies[0], longSource);

for (const item of snapshot.problems) {
  const problem = normal.run(`Archive.problemFromPath(${JSON.stringify(item.path)})`);
  assert(problem, item.path);
  const url = normal.run(`Archive.readerUrl(${JSON.stringify(item.path)})`);
  assert.equal(new URL(url, 'https://codeflare.lucius7.dev/').searchParams.get('path'), item.path);
  assert(!/%2f/i.test(url), `directory separators must remain readable: ${item.path}`);
  assert.equal(problem.githubUrl, item.githubUrl);
}
assert.equal(normal.run('Archive.readerUrl("AtCoder/abc231/a.cpp")'), './code.html?path=AtCoder/abc231/a.cpp');
for (const sourcePath of ['AtCoder/abc231/a.cpp', 'Custom/100% ready.cpp', 'Custom/a#b&c?d+e=f.cpp', 'Custom/中文 题目.cpp', 'Custom/a%2Fb.cpp']) {
  const readableUrl = normal.run(`Archive.readerUrl(${JSON.stringify(sourcePath)})`);
  for (const href of [readableUrl, './code.html?path=' + encodeURIComponent(sourcePath)]) {
    const url = new URL(href, 'https://codeflare.lucius7.dev/');
    assert.equal(url.searchParams.get('path'), sourcePath);
    assert.equal(url.searchParams.size, 1, 'filename characters must not create extra parameters');
    assert.equal(url.hash, '', 'filename characters must not create a fragment');
    const env = environment({ query: url.search });
    await flush();
    assert.equal(env.run('readerState.problem.path'), sourcePath);
    assert.equal(env.elements.get('reader-state').hidden, true, href);
  }
}
for (const invalid of ['', '../secret.cpp', '/AtCoder/a.cpp', 'AtCoder/../a.cpp', 'AtCoder//a.cpp', 'AtCoder/./a.cpp', 'AtCoder\\a.cpp', 'AtCoder/a.html', 'AtCoder/a\u0000.cpp', 'Templates/test.cpp']) {
  const env = environment({ query: '?path=' + encodeURIComponent(invalid) });
  await flush();
  assert.equal(env.requests.length, 0, invalid);
  assert.equal(env.elements.get('reader-state').attributes['aria-busy'], 'false');
}

for (const mode of ['metadata-fail', 'metadata-hang', 'fallback', 'empty']) {
  const env = environment({ mode }); await flush();
  assert.equal(env.elements.get('reader-state').hidden, true, mode);
  assert.equal(env.elements.get('copy-code').disabled, false, mode);
  if (mode === 'fallback') assert.equal(env.requests.length, 4);
  if (mode === 'empty') {
    assert.equal(env.elements.get('reader-lines').textContent, '0 行');
    await env.run('copyCode()'); assert.equal(env.copies[0], '');
  }
  for (const { callback } of [...env.timers.values()]) callback();
  await flush();
}

const failed = environment({ mode: 'all-fail' }); await flush();
assert.equal(failed.elements.get('reader-state').hidden, false);
assert.equal(failed.elements.get('reader-state').attributes['aria-busy'], 'false');
assert.equal(failed.elements.get('retry-code').hidden, false);
assert.equal(failed.elements.get('copy-code').disabled, true);
failed.context.fetch = async () => ({ ok: true, text: async () => source });
await failed.run('showCode()');
assert.equal(failed.elements.get('reader-state').hidden, true, 'retry must recover');

const timeout = environment({ mode: 'hang' }); await flush();
assert.deepEqual([...timeout.timers.values()].map((t) => t.delay).sort(), [5000, 6000]);
for (const { callback } of [...timeout.timers.values()]) callback(); await flush();
for (const { callback } of [...timeout.timers.values()]) callback(); await flush();
assert.equal(timeout.elements.get('reader-state').attributes['aria-busy'], 'false');
assert.equal(timeout.elements.get('retry-code').hidden, false);

const brokenHighlight = environment({ hljs: { getLanguage: () => true, highlight() { throw new Error('grammar'); } } });
await flush(); assert(brokenHighlight.elements.get('code-content').textContent.includes('<script>'));
const highlighted = environment({ hljs: { getLanguage: () => true, highlight: () => ({ value: '<span class="hljs-keyword">int</span>' }) } });
await flush(); assert(highlighted.elements.get('code-content').innerHTML.includes('hljs-keyword'));
const deniedCopy = environment({ failCopy: true }); await flush(); await deniedCopy.run('copyCode()');
assert(deniedCopy.elements.get('copy-status').textContent.includes('复制未获允许'));

const home = environment({ page: 'index.html' }); await flush();
const rows = home.elements.get('problem-list').children;
assert.equal(rows.length, 60);
for (const row of rows) {
  assert.equal(row.tagName, 'A'); assert.equal(row.target, '_blank');
  assert.equal(row.rel, 'noopener noreferrer'); assert.equal(row.attributes.role, undefined);
  assert(row.href.startsWith('./code.html?path='));
}
assert(!('click' in home.elements.get('problem-list').events), 'native links must not be intercepted');
assert(!home.requests.some(({ url }) => /\/contents\/|raw\.githubusercontent|cdn\.jsdelivr/.test(url)));
assert(!/drawer|highlight\.min/.test(read('index.html')));
assert(!/openCodeDrawer|closeCodeDrawer|drawer-open/.test(app));

const readerHtml = read('code.html');
for (const match of readerHtml.matchAll(/(?:src|href)="(\.\/[^"?#]+)(?:[^" ]*)"/g)) assert(existsSync(path.join(root, match[1])), match[1]);
assert(!/window\.close|opener|history\.back|requestFullscreen/.test(readerScript));
assert(readerHtml.includes('href="./#problem-library"'));
assert(readerHtml.includes('github-light.css'));
assert(readerHtml.includes('github-dark.min.css" media="(prefers-color-scheme: dark)"'));
assert(read('reader.css').includes('grid-template-rows: auto minmax(0, 1fr) auto'));
assert(read('reader.css').includes('height: 100dvh'));
assert(!/760px|translateX|drawer/.test(read('reader.css')));
console.log(`Reader checks passed: ${snapshot.problems.length} readable path roundtrips, legacy links, special-character filenames, native new-tab links, direct entry, independent loading, fallback/timeout/retry, safe text, line numbers, clipboard and theme assets.`);
