const REPOSITORY = {
  owner: "theLucius7",
  name: "CompetitiveProgramming",
  branch: "main",
};

const PAGE_SIZE = 60;
const SUPPORTED_EXTENSIONS = new Set(["cpp", "cc", "cxx", "c", "py", "java", "rs", "go", "kt"]);
const IGNORED_ROOTS = new Set(["Templates", ".cph", ".vscode", ".github", "assets", "data", "scripts"]);
const MONTHS_ZH = ["1月", "2月", "3月", "4月", "5月", "6月", "7月", "8月", "9月", "10月", "11月", "12月"];
const HIGHLIGHT_LANGUAGES = {
  "C++": "cpp",
  C: "c",
  Python: "python",
  Java: "java",
  Rust: "rust",
  Go: "go",
  Kotlin: "kotlin",
};

const state = {
  problems: [],
  contributions: {},
  commitCount: 0,
  ratings: {
    atcoder: null,
    codeforces: null,
  },
  submissionDates: new Map(),
  selectedPlatform: "全部",
  query: "",
  sort: "submittedAt",
  visibleCount: PAGE_SIZE,
  currentCode: "",
  codeCache: new Map(),
  codeRequestId: 0,
  lastFocusedElement: null,
};

const elements = {
  syncIndicator: document.querySelector("#sync-indicator"),
  syncStatus: document.querySelector("#sync-status"),
  statSolutions: document.querySelector("#stat-solutions"),
  statPlatforms: document.querySelector("#stat-platforms"),
  statCommits: document.querySelector("#stat-commits"),
  statActiveDays: document.querySelector("#stat-active-days"),
  atcoderRating: document.querySelector("#atcoder-rating"),
  atcoderRatingMeta: document.querySelector("#atcoder-rating-meta"),
  codeforcesRating: document.querySelector("#codeforces-rating"),
  codeforcesRatingMeta: document.querySelector("#codeforces-rating-meta"),
  calendarMonths: document.querySelector("#calendar-months"),
  calendarGrid: document.querySelector("#calendar-grid"),
  activityRange: document.querySelector("#activity-range"),
  activitySummary: document.querySelector("#activity-summary"),
  resultCount: document.querySelector("#result-count"),
  search: document.querySelector("#problem-search"),
  sort: document.querySelector("#problem-sort"),
  platformFilters: document.querySelector("#platform-filters"),
  problemList: document.querySelector("#problem-list"),
  emptyState: document.querySelector("#empty-state"),
  loadMore: document.querySelector("#load-more"),
  backdrop: document.querySelector("#drawer-backdrop"),
  drawer: document.querySelector("#code-drawer"),
  drawerClose: document.querySelector("#drawer-close"),
  drawerPlatform: document.querySelector("#drawer-platform"),
  drawerTitle: document.querySelector("#drawer-title"),
  drawerPath: document.querySelector("#drawer-path"),
  drawerSubmissionTime: document.querySelector("#drawer-submission-time"),
  drawerProblemLink: document.querySelector("#drawer-problem-link"),
  drawerGithubLink: document.querySelector("#drawer-github-link"),
  copyCode: document.querySelector("#copy-code"),
  codeState: document.querySelector("#code-state"),
  codeShell: document.querySelector("#code-shell"),
  codeContent: document.querySelector("#code-content"),
  lineNumbers: document.querySelector("#line-numbers"),
};

function encodePath(path) {
  return path.split("/").map(encodeURIComponent).join("/");
}

function cleanToken(value) {
  return decodeURIComponent(value)
    .replace(/[_-]+/g, " ")
    .replace(/\s+/g, " ")
    .trim();
}

function uppercaseProblem(value) {
  return cleanToken(value).replace(/^([a-z])(\d?)$/i, (_, letter, number) => `${letter.toUpperCase()}${number}`);
}

function atCoderContestName(contest) {
  const match = contest.match(/^([a-z]+)(\d+)$/i);
  return match ? `${match[1].toUpperCase()} ${Number(match[2])}` : contest.toUpperCase();
}

function problemFromPath(path) {
  const segments = path.split("/");
  if (segments.length < 2 || IGNORED_ROOTS.has(segments[0])) return null;

  const fileName = segments.at(-1);
  const extension = fileName.includes(".") ? fileName.split(".").pop().toLowerCase() : "";
  if (!SUPPORTED_EXTENSIONS.has(extension)) return null;

  const platform = segments[0];
  const stem = fileName.slice(0, -(extension.length + 1));
  const item = {
    path,
    platform,
    language: languageFromExtension(extension),
    title: cleanToken(stem),
    problemUrl: platformHome(platform),
    githubUrl: `https://github.com/${REPOSITORY.owner}/${REPOSITORY.name}/blob/${REPOSITORY.branch}/${encodePath(path)}`,
    rawUrl: `https://raw.githubusercontent.com/${REPOSITORY.owner}/${REPOSITORY.name}/${REPOSITORY.branch}/${encodePath(path)}`,
    submittedAt: state.submissionDates.get(path) || null,
  };

  if (platform === "AtCoder" && segments.length >= 3) {
    const contest = segments[1];
    const problem = uppercaseProblem(stem);
    item.title = `${atCoderContestName(contest)} · Problem ${problem}`;
    item.problemUrl = `https://atcoder.jp/contests/${encodeURIComponent(contest)}/tasks/${encodeURIComponent(contest)}_${encodeURIComponent(stem.toLowerCase())}`;
  } else if (platform === "Codeforces" && segments.length >= 3) {
    const contest = segments[1];
    const problem = uppercaseProblem(stem);
    const area = Number(contest) >= 100000 ? "gym" : "contest";
    item.title = `${area === "gym" ? "Gym" : "Codeforces"} ${contest} · ${problem}`;
    item.problemUrl = `https://codeforces.com/${area}/${encodeURIComponent(contest)}/problem/${encodeURIComponent(problem)}`;
  } else if (platform === "CSES") {
    const match = stem.match(/^(\d+)[_-]?(.*)$/);
    if (match) {
      item.title = cleanToken(match[2]) || `Task ${match[1]}`;
      item.problemUrl = `https://cses.fi/problemset/task/${match[1]}`;
    }
  } else if (platform === "Luogu") {
    item.title = stem.toUpperCase();
    item.problemUrl = `https://www.luogu.com.cn/problem/${encodeURIComponent(stem)}`;
  } else if (platform === "LOJ") {
    item.title = `LibreOJ #${stem}`;
    item.problemUrl = `https://loj.ac/p/${encodeURIComponent(stem)}`;
  } else if (platform === "Lanqiao") {
    item.title = `蓝桥云课 #${stem}`;
    item.problemUrl = `https://www.lanqiao.cn/problems/${encodeURIComponent(stem)}/learning/`;
  } else if (platform === "SPOJ") {
    item.title = stem.toUpperCase();
    item.problemUrl = `https://www.spoj.com/problems/${encodeURIComponent(stem.toUpperCase())}/`;
  } else if (platform === "ProjectEuler") {
    const problemNumber = (segments[1] || "").replace(/^P/i, "");
    const solutionNumber = cleanToken(stem);
    item.title = `Problem ${problemNumber}${solutionNumber ? ` · Solution ${solutionNumber}` : ""}`;
    item.problemUrl = `https://projecteuler.net/problem=${encodeURIComponent(problemNumber)}`;
  } else if (platform === "NowCoder" && segments.length >= 3) {
    const contest = segments[1];
    const problem = uppercaseProblem(stem);
    item.title = `Contest ${contest} · ${problem}`;
    item.problemUrl = `https://ac.nowcoder.com/acm/contest/${encodeURIComponent(contest)}/${encodeURIComponent(problem)}`;
  } else if (platform === "VJudge" && segments.length >= 3) {
    const contest = segments[1];
    const problem = uppercaseProblem(stem);
    item.title = `Contest ${contest} · ${problem}`;
    item.problemUrl = `https://vjudge.net/contest/${encodeURIComponent(contest)}#problem/${encodeURIComponent(problem)}`;
  } else if (platform === "QOJ" && segments.length >= 3) {
    const contest = segments[1];
    item.title = `Contest ${contest} · ${uppercaseProblem(stem)}`;
    item.problemUrl = `https://qoj.ac/contest/${encodeURIComponent(contest)}`;
  } else if (platform === "HDU") {
    if (segments.length === 2 && /^\d+$/.test(stem)) {
      item.title = `HDU ${stem}`;
      item.problemUrl = `https://acm.hdu.edu.cn/showproblem.php?pid=${encodeURIComponent(stem)}`;
    } else if (segments.length >= 3) {
      item.title = `HDU ${segments[1]} · ${uppercaseProblem(stem)}`;
      item.problemUrl = "https://acm.hdu.edu.cn/";
    }
  } else if (platform === "Mati" && segments.length >= 3) {
    item.title = `Contest ${segments[1]} · ${cleanToken(stem)}`;
    item.problemUrl = "https://www.matiji.net/";
  } else if (platform === "L7OJ" && segments.length >= 3) {
    item.title = `${cleanToken(segments[1]).toUpperCase()} · ${uppercaseProblem(stem)}`;
  } else if (platform === "SMQYOJ") {
    item.title = cleanToken(stem).toUpperCase();
    item.problemUrl = "https://www.smqyoj.com/training";
  }

  item.searchText = `${item.title} ${item.platform} ${item.path}`.toLocaleLowerCase();
  return item;
}

function languageFromExtension(extension) {
  return ({
    cpp: "C++",
    cc: "C++",
    cxx: "C++",
    c: "C",
    py: "Python",
    java: "Java",
    rs: "Rust",
    go: "Go",
    kt: "Kotlin",
  })[extension] || extension.toUpperCase();
}

function platformHome(platform) {
  return ({
    AtCoder: "https://atcoder.jp/",
    Codeforces: "https://codeforces.com/",
    CSES: "https://cses.fi/problemset/",
    HDU: "https://acm.hdu.edu.cn/",
    Lanqiao: "https://www.lanqiao.cn/problems/",
    LOJ: "https://loj.ac/",
    Luogu: "https://www.luogu.com.cn/",
    Mati: "https://www.matiji.net/",
    NowCoder: "https://ac.nowcoder.com/acm/contest/vip-index",
    ProjectEuler: "https://projecteuler.net/archives",
    QOJ: "https://qoj.ac/",
    SMQYOJ: "https://www.smqyoj.com/training",
    SPOJ: "https://www.spoj.com/problems/classical/",
    VJudge: "https://vjudge.net/",
  })[platform] || `https://github.com/${REPOSITORY.owner}/${REPOSITORY.name}`;
}

function formatNumber(value) {
  return new Intl.NumberFormat("zh-CN").format(value || 0);
}

function formatSubmissionTime(value, long = false) {
  if (!value) return "时间未知";
  const date = new Date(value);
  if (Number.isNaN(date.getTime())) return "时间未知";
  return new Intl.DateTimeFormat("zh-CN", {
    year: "numeric",
    month: "2-digit",
    day: "2-digit",
    hour: "2-digit",
    minute: "2-digit",
    hour12: false,
    ...(long ? { timeZoneName: "short" } : {}),
  }).format(date);
}

function localDateKey(date) {
  const year = date.getFullYear();
  const month = String(date.getMonth() + 1).padStart(2, "0");
  const day = String(date.getDate()).padStart(2, "0");
  return `${year}-${month}-${day}`;
}

function addDays(date, amount) {
  const copy = new Date(date);
  copy.setDate(copy.getDate() + amount);
  return copy;
}

function levelForCount(count, max) {
  if (!count) return 0;
  if (max <= 4) return Math.min(count, 4);
  const ratio = count / max;
  if (ratio <= 0.25) return 1;
  if (ratio <= 0.5) return 2;
  if (ratio <= 0.75) return 3;
  return 4;
}

function renderStats() {
  const platforms = new Set(state.problems.map((problem) => problem.platform));
  const activeDays = Object.values(state.contributions).filter(Boolean).length;
  elements.statSolutions.textContent = formatNumber(state.problems.length);
  elements.statPlatforms.textContent = formatNumber(platforms.size);
  elements.statCommits.textContent = formatNumber(state.commitCount);
  elements.statActiveDays.textContent = formatNumber(activeDays);
}

function renderRatings() {
  const atcoder = state.ratings.atcoder;
  const codeforces = state.ratings.codeforces;
  elements.atcoderRating.textContent = atcoder?.rating == null ? "—" : formatNumber(atcoder.rating);
  elements.atcoderRatingMeta.textContent = atcoder
    ? `MAX ${formatNumber(atcoder.maxRating)} · ${formatNumber(atcoder.contests)} CONTESTS`
    : "RATING 暂不可用";
  elements.codeforcesRating.textContent = codeforces?.rating == null ? "—" : formatNumber(codeforces.rating);
  elements.codeforcesRatingMeta.textContent = codeforces
    ? `${String(codeforces.rank || "UNRATED").toUpperCase()} · MAX ${formatNumber(codeforces.maxRating)}`
    : "RATING 暂不可用";
}

function renderCalendar() {
  const today = new Date();
  today.setHours(12, 0, 0, 0);
  const end = addDays(today, 6 - today.getDay());
  const start = addDays(end, -(53 * 7 - 1));
  const counts = Object.values(state.contributions);
  const max = Math.max(1, ...counts);
  const fragment = document.createDocumentFragment();

  elements.calendarGrid.replaceChildren();
  elements.calendarMonths.replaceChildren();

  let previousMonth = -1;
  for (let index = 0; index < 53 * 7; index += 1) {
    const date = addDays(start, index);
    const dateKey = localDateKey(date);
    const count = state.contributions[dateKey] || 0;
    const cell = document.createElement("span");
    const level = levelForCount(count, max);
    cell.className = `calendar-cell level-${level}${date > today ? " outside" : ""}`;
    cell.setAttribute("role", "gridcell");
    cell.setAttribute("aria-label", `${dateKey}：${count} 次提交`);
    cell.title = `${dateKey} · ${count} 次提交`;
    fragment.append(cell);

    if (date.getDay() === 0 && date.getMonth() !== previousMonth) {
      const month = document.createElement("span");
      month.textContent = MONTHS_ZH[date.getMonth()];
      month.style.left = `${(Math.floor(index / 7) / 53) * 100}%`;
      elements.calendarMonths.append(month);
      previousMonth = date.getMonth();
    }
  }
  elements.calendarGrid.append(fragment);

  const startKey = localDateKey(start);
  const endKey = localDateKey(today);
  const rangeCommitCount = Object.entries(state.contributions)
    .filter(([date]) => date >= startKey && date <= endKey)
    .reduce((sum, [, count]) => sum + count, 0);
  const rangeActiveDays = Object.entries(state.contributions)
    .filter(([date, count]) => date >= startKey && date <= endKey && count > 0).length;
  elements.activityRange.textContent = `${startKey} — ${endKey}`;
  elements.activitySummary.textContent = `最近一年 ${formatNumber(rangeCommitCount)} 次提交 · ${formatNumber(rangeActiveDays)} 个活跃日`;
}

function platformCounts() {
  return state.problems.reduce((counts, problem) => {
    counts.set(problem.platform, (counts.get(problem.platform) || 0) + 1);
    return counts;
  }, new Map());
}

function renderFilters() {
  const counts = platformCounts();
  const entries = [["全部", state.problems.length], ...[...counts.entries()].sort((a, b) => b[1] - a[1] || a[0].localeCompare(b[0]))];
  const fragment = document.createDocumentFragment();

  for (const [name, count] of entries) {
    const button = document.createElement("button");
    const number = document.createElement("span");
    button.type = "button";
    button.className = `filter-chip${state.selectedPlatform === name ? " active" : ""}`;
    button.textContent = name;
    button.dataset.platform = name;
    button.setAttribute("aria-pressed", String(state.selectedPlatform === name));
    number.textContent = formatNumber(count);
    button.append(number);
    fragment.append(button);
  }
  elements.platformFilters.replaceChildren(fragment);
}

function filteredProblems() {
  const query = state.query.trim().toLocaleLowerCase();
  const problems = state.problems.filter((problem) => {
    const platformMatches = state.selectedPlatform === "全部" || problem.platform === state.selectedPlatform;
    const queryMatches = !query || problem.searchText.includes(query);
    return platformMatches && queryMatches;
  });

  const collator = new Intl.Collator("zh-CN", { numeric: true, sensitivity: "base" });
  problems.sort((a, b) => {
    if (state.sort === "submittedAt") {
      const timeDifference = (Date.parse(b.submittedAt) || 0) - (Date.parse(a.submittedAt) || 0);
      return timeDifference || collator.compare(a.path, b.path);
    }
    if (state.sort === "title") return collator.compare(a.title, b.title) || collator.compare(a.path, b.path);
    if (state.sort === "path") return collator.compare(a.path, b.path);
    return collator.compare(a.platform, b.platform) || collator.compare(a.title, b.title);
  });
  return problems;
}

function renderProblems() {
  const problems = filteredProblems();
  const visible = problems.slice(0, state.visibleCount);
  const fragment = document.createDocumentFragment();

  for (const problem of visible) {
    const row = document.createElement("article");
    const main = document.createElement("div");
    const title = document.createElement("span");
    const meta = document.createElement("div");
    const path = document.createElement("span");
    const mobileTime = document.createElement("time");
    const platform = document.createElement("span");
    const submissionTime = document.createElement("time");
    const language = document.createElement("span");
    const arrow = document.createElement("span");

    row.className = "problem-row";
    row.tabIndex = 0;
    row.setAttribute("role", "button");
    row.setAttribute("aria-label", `查看 ${problem.title} 的代码`);
    row.dataset.path = problem.path;
    main.className = "problem-main";
    title.className = "problem-title";
    title.textContent = problem.title;
    meta.className = "problem-meta";
    path.className = "problem-path";
    path.textContent = problem.path;
    mobileTime.className = "problem-date-mobile";
    mobileTime.dateTime = problem.submittedAt || "";
    mobileTime.textContent = formatSubmissionTime(problem.submittedAt);
    platform.className = "platform-badge";
    platform.textContent = problem.platform;
    submissionTime.className = "submission-time";
    submissionTime.dateTime = problem.submittedAt || "";
    submissionTime.textContent = formatSubmissionTime(problem.submittedAt);
    language.className = "language-badge";
    language.textContent = problem.language;
    arrow.className = "row-arrow";
    arrow.textContent = "→";
    arrow.setAttribute("aria-hidden", "true");

    meta.append(path, mobileTime);
    main.append(title, meta);
    row.append(main, platform, submissionTime, language, arrow);
    fragment.append(row);
  }

  elements.problemList.replaceChildren(fragment);
  elements.resultCount.textContent = `${formatNumber(problems.length)} 份题解`;
  elements.emptyState.hidden = problems.length > 0;
  elements.loadMore.hidden = visible.length >= problems.length;
  if (!elements.loadMore.hidden) {
    elements.loadMore.textContent = `再显示 ${formatNumber(Math.min(PAGE_SIZE, problems.length - visible.length))} 份`;
  }
}

function updateAllViews() {
  renderRatings();
  renderStats();
  renderCalendar();
  renderFilters();
  renderProblems();
}

function setSyncStatus(message, mode = "") {
  elements.syncStatus.textContent = message;
  elements.syncIndicator.className = `sync-indicator${mode ? ` ${mode}` : ""}`;
}

async function fetchTextWithTimeout(url, options = {}, timeoutMs = 6000) {
  const controller = new AbortController();
  const timeoutId = window.setTimeout(() => controller.abort(), timeoutMs);
  try {
    const response = await fetch(url, { ...options, signal: controller.signal });
    if (!response.ok) throw new Error(`HTTP ${response.status}`);
    return await response.text();
  } finally {
    window.clearTimeout(timeoutId);
  }
}

async function loadProblemCode(problem) {
  if (state.codeCache.has(problem.path)) return state.codeCache.get(problem.path);

  const encodedPath = encodePath(problem.path);
  const apiUrl = `https://api.github.com/repos/${REPOSITORY.owner}/${REPOSITORY.name}/contents/${encodedPath}?ref=${encodeURIComponent(REPOSITORY.branch)}`;
  const cdnUrl = `https://cdn.jsdelivr.net/gh/${REPOSITORY.owner}/${REPOSITORY.name}@${REPOSITORY.branch}/${encodedPath}`;
  let code;

  try {
    code = await fetchTextWithTimeout(apiUrl, {
      headers: {
        Accept: "application/vnd.github.raw+json",
        "X-GitHub-Api-Version": "2022-11-28",
      },
    }, 5000);
  } catch {
    code = await Promise.any([
      fetchTextWithTimeout(cdnUrl, {}, 7000),
      fetchTextWithTimeout(problem.rawUrl, {}, 7000),
    ]);
  }

  state.codeCache.set(problem.path, code);
  return code;
}

function renderCode(code, language) {
  const grammar = HIGHLIGHT_LANGUAGES[language];
  const highlighter = window.hljs;
  elements.codeContent.className = "";

  if (grammar && highlighter?.getLanguage(grammar)) {
    try {
      const result = highlighter.highlight(code, { language: grammar, ignoreIllegals: true });
      elements.codeContent.className = `hljs language-${grammar}`;
      elements.codeContent.innerHTML = result.value;
      return;
    } catch {
      // Fall through to safe plain-text rendering.
    }
  }

  elements.codeContent.className = "hljs";
  elements.codeContent.textContent = code;
}

async function openCodeDrawer(problem) {
  const requestId = ++state.codeRequestId;
  state.lastFocusedElement = document.activeElement;
  state.currentCode = "";
  elements.drawerPlatform.textContent = `${problem.platform} · ${problem.language}`;
  elements.drawerTitle.textContent = problem.title;
  elements.drawerPath.textContent = problem.path;
  elements.drawerSubmissionTime.textContent = `最后提交 · ${formatSubmissionTime(problem.submittedAt, true)}`;
  elements.drawerProblemLink.href = problem.problemUrl;
  elements.drawerGithubLink.href = problem.githubUrl;
  elements.copyCode.textContent = "复制代码";
  elements.codeShell.hidden = true;
  elements.codeState.hidden = false;
  elements.codeState.setAttribute("aria-busy", "true");
  elements.codeState.textContent = "正在载入代码…";
  elements.backdrop.hidden = false;
  elements.drawer.setAttribute("aria-hidden", "false");
  document.body.classList.add("drawer-open");
  requestAnimationFrame(() => {
    elements.drawer.classList.add("open");
    elements.drawerClose.focus();
  });

  try {
    const code = await loadProblemCode(problem);
    if (requestId !== state.codeRequestId) return;
    state.currentCode = code;
    renderCode(code, problem.language);
    const lineCount = Math.max(1, code.split("\n").length);
    elements.lineNumbers.textContent = Array.from({ length: lineCount }, (_, index) => index + 1).join("\n");
    elements.codeState.hidden = true;
    elements.codeShell.hidden = false;
  } catch {
    if (requestId !== state.codeRequestId) return;
    elements.codeState.textContent = "载入失败，请使用上方的 GitHub 链接查看源码。";
  } finally {
    if (requestId === state.codeRequestId) elements.codeState.setAttribute("aria-busy", "false");
  }
}

function closeCodeDrawer() {
  state.codeRequestId += 1;
  elements.drawer.classList.remove("open");
  elements.drawer.setAttribute("aria-hidden", "true");
  document.body.classList.remove("drawer-open");
  window.setTimeout(() => {
    elements.backdrop.hidden = true;
    state.lastFocusedElement?.focus?.();
  }, 240);
}

async function copyCurrentCode() {
  if (!state.currentCode) return;
  try {
    await navigator.clipboard.writeText(state.currentCode);
    elements.copyCode.textContent = "已复制 ✓";
    window.setTimeout(() => { elements.copyCode.textContent = "复制代码"; }, 1600);
  } catch {
    elements.copyCode.textContent = "复制失败";
  }
}

async function loadSnapshot() {
  const response = await fetch("./data/site-data.json");
  if (!response.ok) throw new Error("Snapshot unavailable");
  const snapshot = await response.json();
  state.problems = snapshot.problems.map((problem) => ({
    ...problem,
    searchText: `${problem.title} ${problem.platform} ${problem.path}`.toLocaleLowerCase(),
  }));
  state.submissionDates = new Map(state.problems.map((problem) => [problem.path, problem.submittedAt || null]));
  state.contributions = snapshot.contributions;
  state.commitCount = snapshot.commitCount;
  state.ratings = snapshot.ratings || state.ratings;
  updateAllViews();
  const generatedDate = new Date(snapshot.generatedAt).toLocaleString("zh-CN", {
    year: "numeric", month: "short", day: "numeric", hour: "2-digit", minute: "2-digit",
  });
  setSyncStatus(`已载入部署快照 · ${generatedDate}`);
}

async function fetchLiveProblems() {
  const endpoint = `https://api.github.com/repos/${REPOSITORY.owner}/${REPOSITORY.name}/git/trees/${REPOSITORY.branch}?recursive=1`;
  const response = await fetch(endpoint, { headers: { Accept: "application/vnd.github+json" } });
  if (!response.ok) throw new Error(`Tree API ${response.status}`);
  const payload = await response.json();
  const problems = payload.tree
    .filter((item) => item.type === "blob")
    .map((item) => problemFromPath(item.path))
    .filter(Boolean);
  if (!problems.length) throw new Error("No problems in live tree");
  return problems;
}

async function fetchLiveActivity() {
  const endpoint = `https://api.github.com/repos/${REPOSITORY.owner}/${REPOSITORY.name}/stats/commit_activity`;
  for (let attempt = 0; attempt < 3; attempt += 1) {
    const response = await fetch(endpoint, { headers: { Accept: "application/vnd.github+json" } });
    if (response.status === 202) {
      await new Promise((resolve) => window.setTimeout(resolve, 1300 * (attempt + 1)));
      continue;
    }
    if (!response.ok) throw new Error(`Activity API ${response.status}`);
    const weeks = await response.json();
    const contributions = {};
    let commitCount = 0;
    for (const week of weeks) {
      week.days.forEach((count, dayIndex) => {
        const date = new Date((week.week + dayIndex * 86400) * 1000).toISOString().slice(0, 10);
        contributions[date] = count;
        commitCount += count;
      });
    }
    return { contributions, commitCount };
  }
  throw new Error("Activity is still being generated");
}

async function fetchLiveRatings() {
  const atcoderUrl = "https://kenkoooo.com/atcoder/proxy/users/Lucius7/history/json";
  const codeforcesUrl = "https://codeforces.com/api/user.info?handles=Lucius7";
  const [atcoderResult, codeforcesResult] = await Promise.allSettled([
    fetch(atcoderUrl).then((response) => {
      if (!response.ok) throw new Error(`AtCoder rating API ${response.status}`);
      return response.json();
    }),
    fetch(codeforcesUrl).then((response) => {
      if (!response.ok) throw new Error(`Codeforces rating API ${response.status}`);
      return response.json();
    }),
  ]);

  const ratings = {};
  if (atcoderResult.status === "fulfilled" && atcoderResult.value.length) {
    const ratedContests = atcoderResult.value.filter((contest) => contest.IsRated && Number.isFinite(contest.NewRating));
    const latest = ratedContests.at(-1);
    ratings.atcoder = {
      rating: latest?.NewRating ?? null,
      maxRating: Math.max(0, ...ratedContests.map((contest) => contest.NewRating)),
      contests: ratedContests.length,
    };
  }
  if (codeforcesResult.status === "fulfilled" && codeforcesResult.value.status === "OK") {
    const user = codeforcesResult.value.result?.[0];
    if (user) {
      ratings.codeforces = {
        rating: user.rating ?? null,
        maxRating: user.maxRating ?? user.rating ?? null,
        rank: user.rank ?? "unrated",
      };
    }
  }
  if (!ratings.atcoder && !ratings.codeforces) throw new Error("Rating APIs unavailable");
  return ratings;
}

async function syncLiveData() {
  setSyncStatus("正在同步 main 分支…", "syncing");
  const [problemResult, activityResult, ratingResult] = await Promise.allSettled([
    fetchLiveProblems(),
    fetchLiveActivity(),
    fetchLiveRatings(),
  ]);

  let updated = false;
  if (problemResult.status === "fulfilled") {
    state.problems = problemResult.value;
    if (state.selectedPlatform !== "全部" && !state.problems.some((problem) => problem.platform === state.selectedPlatform)) {
      state.selectedPlatform = "全部";
    }
    updated = true;
  }
  if (activityResult.status === "fulfilled") {
    state.contributions = activityResult.value.contributions;
    state.commitCount = activityResult.value.commitCount;
    updated = true;
  }
  if (ratingResult.status === "fulfilled") {
    state.ratings = { ...state.ratings, ...ratingResult.value };
    updated = true;
  }
  updateAllViews();

  if (problemResult.status === "fulfilled" && activityResult.status === "fulfilled" && ratingResult.status === "fulfilled") {
    setSyncStatus("已与 main 分支实时同步", "live");
  } else if (updated) {
    setSyncStatus("已同步仓库；部分统计使用部署快照", "live");
  } else {
    setSyncStatus("实时同步暂不可用，当前显示部署快照");
  }
}

elements.search.addEventListener("input", (event) => {
  state.query = event.target.value;
  state.visibleCount = PAGE_SIZE;
  renderProblems();
});

elements.sort.addEventListener("change", (event) => {
  state.sort = event.target.value;
  state.visibleCount = PAGE_SIZE;
  renderProblems();
});

elements.platformFilters.addEventListener("click", (event) => {
  const button = event.target.closest("button[data-platform]");
  if (!button) return;
  state.selectedPlatform = button.dataset.platform;
  state.visibleCount = PAGE_SIZE;
  renderFilters();
  renderProblems();
});

elements.problemList.addEventListener("click", (event) => {
  const row = event.target.closest("[data-path]");
  if (!row) return;
  const problem = state.problems.find((item) => item.path === row.dataset.path);
  if (problem) openCodeDrawer(problem);
});

elements.problemList.addEventListener("keydown", (event) => {
  if (event.key !== "Enter" && event.key !== " ") return;
  const row = event.target.closest("[data-path]");
  if (!row) return;
  event.preventDefault();
  const problem = state.problems.find((item) => item.path === row.dataset.path);
  if (problem) openCodeDrawer(problem);
});

elements.loadMore.addEventListener("click", () => {
  state.visibleCount += PAGE_SIZE;
  renderProblems();
});

elements.drawerClose.addEventListener("click", closeCodeDrawer);
elements.backdrop.addEventListener("click", closeCodeDrawer);
elements.copyCode.addEventListener("click", copyCurrentCode);

document.addEventListener("keydown", (event) => {
  if (event.key === "Escape" && elements.drawer.classList.contains("open")) closeCodeDrawer();
  if (event.key === "/" && !elements.drawer.classList.contains("open") && !["INPUT", "TEXTAREA", "SELECT"].includes(document.activeElement.tagName)) {
    event.preventDefault();
    elements.search.focus();
  }
});

(async function init() {
  try {
    await loadSnapshot();
  } catch {
    setSyncStatus("部署快照载入失败，正在尝试实时同步…", "syncing");
  }
  await syncLiveData();
})();
