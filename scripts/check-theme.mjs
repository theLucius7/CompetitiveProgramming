#!/usr/bin/env node
// Source-level design-system checks; no browser or extra dependencies required.
import assert from 'node:assert/strict';
import { readFileSync, existsSync } from 'node:fs';
import { fileURLToPath } from 'node:url';
import path from 'node:path';

const root = path.resolve(path.dirname(fileURLToPath(import.meta.url)), '..');
const read = (file) => readFileSync(path.join(root, file), 'utf8');
const theme = read('theme.css');
const declarations = (block) => Object.fromEntries([...block.matchAll(/(--[\w-]+):\s*([^;]+);/g)].map((m) => [m[1], m[2].trim()]));
const roots = [...theme.matchAll(/:root\s*\{([^}]+)\}/g)];
assert.equal(roots.length, 2, 'one light palette and one system-dark override');
const light = declarations(roots[0][1]);
const dark = { ...light, ...declarations(roots[1][1]) };
assert(theme.includes('@media (prefers-color-scheme: dark)'));
assert(theme.includes('@media (prefers-reduced-motion: reduce)'));
assert.match(theme, /\[hidden\]\s*\{\s*display:\s*none\s*!important;/);
assert.match(theme, /:focus-visible[\s\S]*?outline:\s*2px solid var\(--accent\)/);
assert(theme.includes('.ui-button[aria-pressed="true"]'));
assert.equal(light['--control-height'], '44px');

let themeAsset;
for (const [htmlFile, cssFile] of [['index.html', 'styles.css'], ['code.html', 'reader.css']]) {
  const html = read(htmlFile);
  const links = [...html.matchAll(/<link rel="stylesheet" href="([^"]+)"/g)].map((m) => m[1]);
  const shared = links.filter((href) => href.startsWith('./theme.css?'));
  assert.equal(shared.length, 1, `${htmlFile}: load shared theme exactly once`);
  if (themeAsset) assert.equal(shared[0], themeAsset, 'pages must use the same theme revision');
  themeAsset = shared[0];
  assert(links.indexOf(shared[0]) < links.findIndex((href) => href.startsWith('./' + cssFile)), 'theme before layout');
  const avatar = html.match(/<img class="brand-avatar"[^>]+>/)?.[0];
  assert(avatar && html.includes('class="brand-name"'), `${htmlFile}: shared avatar branding`);
  assert(avatar.includes('src="https://avatars.githubusercontent.com/u/59860644?v=4"'));
  assert(avatar.includes('width="36"') && avatar.includes('height="36"'), 'reserve avatar dimensions');
  assert(avatar.includes('alt="theLucius7 的 GitHub 头像"'));
  assert(!html.includes('brand-mark'), 'do not restore the L7 text mark');
  assert(html.includes('ui-button'));
  assert(html.includes(`content="${light['--bg']}" media="(prefers-color-scheme: light)"`));
  assert(html.includes(`content="${dark['--bg']}" media="(prefers-color-scheme: dark)"`));
  for (const match of html.matchAll(/(?:src|href)="(\.\/[^"?#]+)(?:[^" ]*)"/g)) {
    assert(existsSync(path.join(root, match[1])), `${htmlFile}: missing ${match[1]}`);
  }
  const css = read(cssFile).replace(/\/\*[\s\S]*?\*\//g, '');
  assert(!/:root|prefers-color-scheme|#[\da-f]{3,8}\b|\b(?:rgb|hsl)a?\(/i.test(css), `${cssFile}: no page-local palette`);
  assert(!/--[\w-]+\s*:/.test(css), `${cssFile}: tokens belong in theme.css`);
  for (const [, token] of css.matchAll(/var\((--[\w-]+)/g)) assert(token in light, `${cssFile}: unknown ${token}`);
}
for (const [, token] of theme.matchAll(/var\((--[\w-]+)/g)) assert(token in light, `unknown ${token}`);
assert(read('app.js').includes('button.className = "ui-button filter-chip";'));
assert.match(read('reader.css'), /\.line-numbers, \.code-grid pre\s*\{[^}]*font: var\(--text-body\)\/1\.75 var\(--font-mono\)/);
assert(read('reader.css').includes('grid-template-rows: auto minmax(0, 1fr) auto'));

function luminance(hex) {
  assert.match(hex, /^#[\da-f]{6}$/i);
  const [r, g, b] = hex.slice(1).match(/../g).map((part) => {
    const value = parseInt(part, 16) / 255;
    return value <= 0.04045 ? value / 12.92 : ((value + 0.055) / 1.055) ** 2.4;
  });
  return 0.2126 * r + 0.7152 * g + 0.0722 * b;
}
let minimum = Infinity;
const pairs = [
  ...['--bg', '--surface', '--surface-soft'].flatMap((bg) => ['--ink', '--muted', '--accent'].map((fg) => [fg, bg])),
  ['--accent-deep', '--accent-soft'], ['--ink', '--selection'],
  ['--syntax-built-in', '--surface'], ['--syntax-section', '--surface'],
];
for (const [mode, palette] of Object.entries({ light, dark })) {
  for (const [fg, bg] of pairs) {
    const values = [luminance(palette[fg]), luminance(palette[bg])].sort((a, b) => b - a);
    const ratio = (values[0] + 0.05) / (values[1] + 0.05);
    assert(ratio >= 4.5, `${mode} ${fg}/${bg}: ${ratio.toFixed(2)}:1 is below 4.5:1`);
    minimum = Math.min(minimum, ratio);
  }
}

// Optional cross-branch check: node scripts/check-theme.mjs /path/to/docs/site/.vitepress/theme/style.css
if (process.argv[2]) {
  const adapter = readFileSync(path.resolve(process.argv[2]), 'utf8');
  const docsLight = declarations(adapter.match(/:root\s*\{([^}]+)\}/)[1]);
  const docsDark = { ...docsLight, ...declarations(adapter.match(/\.dark\s*\{([^}]+)\}/)[1]) };
  const mapping = {
    '--vp-c-bg': '--surface', '--vp-c-bg-alt': '--bg', '--vp-c-bg-elv': '--surface',
    '--vp-c-bg-soft': '--surface-soft', '--vp-c-text-1': '--ink', '--vp-c-text-2': '--muted',
    '--vp-c-text-3': '--muted', '--vp-c-divider': '--line', '--vp-c-border': '--line-strong',
    '--vp-c-gutter': '--line', '--vp-c-brand-1': '--accent', '--vp-c-brand-2': '--accent-deep',
    '--vp-c-brand-3': '--accent', '--vp-c-brand-soft': '--accent-soft',
    '--vp-font-family-base': '--font-sans', '--vp-font-family-mono': '--font-mono',
  };
  for (const [palette, docs] of [[light, docsLight], [dark, docsDark]]) {
    for (const [target, source] of Object.entries(mapping)) assert.equal(docs[target], palette[source], `docs adapter: ${target}`);
  }
  assert(!adapter.includes('@import'), 'docs must not import the root reset');
}
console.log(`Theme checks passed: shared assets/components/tokens, system themes, reader typography; minimum tested text contrast ${minimum.toFixed(2)}:1.${process.argv[2] ? ' Docs adapter matches.' : ''}`);
