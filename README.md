# Competitive Programming Pages

This orphan branch contains the static GitHub Pages site for
[`theLucius7/CompetitiveProgramming`](https://github.com/theLucius7/CompetitiveProgramming).

The page ships with a generated snapshot and refreshes the `main` branch tree and
six latest main commits from GitHub's public API when opened. Each list loads
independently with bounded request timeouts and a deployment snapshot fallback.
The homepage no longer displays or fetches Rating and contribution-calendar data.
Legacy statistics remain in `data/site-data.json` for API compatibility;
`data/recent-commits.json` provides commit messages, timestamps and links.

Solution links open `code.html?path=...` in a new tab, leaving the library's
filters and scroll position in place. The full-page reader follows the system
theme and loads source independently from optional submission metadata. It
supports syntax highlighting, line numbers, source links and copying the exact
original text. Run `node scripts/check-reader.mjs` for non-browser regressions.

[Solution archive](https://thelucius7.github.io/CompetitiveProgramming/) ·
[API documentation](https://thelucius7.github.io/CompetitiveProgramming/docs/)

The `docs/` directory is built automatically from `docs/project-guide` and must
not be edited here. Push documentation changes to that source branch; no merge
into `main` is required. The workflow checks the API contract, publishes only
`gh-pages/docs/`, and verifies the Pages build.

To refresh the local fallback snapshot:

```bash
node scripts/generate-data.mjs main
```
