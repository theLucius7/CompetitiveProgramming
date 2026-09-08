const { REPOSITORY, problemFromPath, formatNumber, formatSubmissionTime, fetchTextWithTimeout, readerUrl } = Archive;
const PAGE_SIZE = 60;

const state = {
  problems: [],
  commits: [],
  submissionDates: new Map(),
  selectedPlatform: "全部",
  query: "",
  sort: "submittedAt",
  visibleCount: PAGE_SIZE,
};

const elements = {
  syncIndicator: document.querySelector("#sync-indicator"),
  syncStatus: document.querySelector("#sync-status"),
  commitList: document.querySelector("#commit-list"),
  updatesStatus: document.querySelector("#updates-status"),
  resultCount: document.querySelector("#result-count"),
  search: document.querySelector("#problem-search"),
  sort: document.querySelector("#problem-sort"),
  platformFilters: document.querySelector("#platform-filters"),
  problemList: document.querySelector("#problem-list"),
  emptyState: document.querySelector("#empty-state"),
  loadMore: document.querySelector("#load-more"),
};

function renderCommits() {
  const fragment = document.createDocumentFragment();
  for (const commit of state.commits) {
    const row = document.createElement("li");
    row.className = "commit-row";
    const link = document.createElement("a");
    link.className = "commit-title";
    link.href = commit.url;
    link.target = "_blank";
    link.rel = "noreferrer";
    link.textContent = commit.subject || "无提交说明";
    const sha = document.createElement("code");
    sha.className = "commit-sha";
    sha.textContent = commit.sha.slice(0, 7);
    const time = document.createElement("time");
    time.dateTime = commit.committedAt;
    time.title = formatSubmissionTime(commit.committedAt, true);
    time.textContent = formatSubmissionTime(commit.committedAt);
    row.append(link, sha, time);
    fragment.append(row);
  }
  elements.commitList.replaceChildren(fragment);
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
    const row = document.createElement("a");
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
    row.href = readerUrl(problem.path);
    row.target = "_blank";
    row.rel = "noopener noreferrer";
    row.setAttribute("aria-label", `查看 ${problem.title} 的代码（新标签页）`);
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
    arrow.textContent = "↗";
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
  renderFilters();
  renderProblems();
}

function setSyncStatus(message, mode = "") {
  elements.syncStatus.textContent = message;
  elements.syncIndicator.className = `sync-indicator${mode ? ` ${mode}` : ""}`;
}

async function fetchJson(url, options = {}) {
  return JSON.parse(await fetchTextWithTimeout(url, { cache: "no-cache", ...options }));
}

const githubHeaders = {
  Accept: "application/vnd.github+json",
  "X-GitHub-Api-Version": "2022-11-28",
};

async function initProblems() {
  let hasSnapshot = false;
  try {
    const snapshot = await fetchJson("./data/site-data.json");
    if (!Array.isArray(snapshot.problems) || !snapshot.problems.length) throw new Error("Empty snapshot");
    state.problems = snapshot.problems.map((problem) => ({
      ...problem,
      searchText: `${problem.title} ${problem.platform} ${problem.path}`.toLocaleLowerCase(),
    }));
    state.submissionDates = new Map(state.problems.map((problem) => [problem.path, problem.submittedAt || null]));
    hasSnapshot = true;
    updateAllViews();
    elements.syncStatus.title = `文件提交时间来自 ${formatSubmissionTime(snapshot.generatedAt, true)} 生成的快照。`;
  } catch {
    // The live tree can still recover the problem list when the snapshot is unavailable.
  }

  setSyncStatus("正在检查 main 代码列表…", "syncing");
  try {
    const endpoint = `https://api.github.com/repos/${REPOSITORY.owner}/${REPOSITORY.name}/git/trees/${REPOSITORY.branch}?recursive=1`;
    const payload = await fetchJson(endpoint, { headers: githubHeaders });
    if (payload.truncated || !Array.isArray(payload.tree)) throw new Error("Incomplete tree");
    const problems = payload.tree
      .filter((item) => item.type === "blob")
      .map((item) => problemFromPath(item.path, state.submissionDates.get(item.path) || null))
      .filter(Boolean);
    if (!problems.length) throw new Error("No problems in live tree");
    state.problems = problems;
    if (state.selectedPlatform !== "全部" && !problems.some((problem) => problem.platform === state.selectedPlatform)) {
      state.selectedPlatform = "全部";
    }
    updateAllViews();
    setSyncStatus("main · 代码列表已检查", "live");
    if (!hasSnapshot) elements.syncStatus.title = "文件提交时间暂不可用；GitHub 目录接口不包含逐文件提交时间。";
  } catch {
    setSyncStatus(hasSnapshot ? "main · 部署快照（在线检查暂不可用）" : "代码列表载入失败，请刷新重试");
    if (!hasSnapshot) elements.resultCount.textContent = "暂不可用";
  }
}

function normalizeCommits(items, fromGithub = false) {
  if (!Array.isArray(items)) throw new Error("Invalid commits response");
  return items.slice(0, 6).map((item) => {
    const committedAt = fromGithub ? item.commit?.committer?.date : item.committedAt;
    const subject = fromGithub ? item.commit?.message?.split("\n")[0] : item.subject;
    if (!/^[0-9a-f]{40}$/.test(item.sha) || typeof subject !== "string" || !committedAt || !Number.isFinite(Date.parse(committedAt))) {
      throw new Error("Invalid commit");
    }
    return {
      sha: item.sha,
      subject,
      committedAt: new Date(committedAt).toISOString(),
      url: `https://github.com/${REPOSITORY.owner}/${REPOSITORY.name}/commit/${item.sha}`,
    };
  });
}

async function initUpdates() {
  let hasSnapshot = false;
  try {
    const snapshot = await fetchJson("./data/recent-commits.json");
    state.commits = normalizeCommits(snapshot.commits);
    renderCommits();
    hasSnapshot = true;
    elements.updatesStatus.textContent = "部署快照 · 正在检查最新提交…";
  } catch {
    // Repository updates load independently of the solution list.
  }
  try {
    const endpoint = `https://api.github.com/repos/${REPOSITORY.owner}/${REPOSITORY.name}/commits?sha=${REPOSITORY.branch}&per_page=6`;
    state.commits = normalizeCommits(await fetchJson(endpoint, { headers: githubHeaders }), true);
    renderCommits();
    elements.updatesStatus.textContent = state.commits.length
      ? `最近 ${state.commits.length} 次提交 · 已检查`
      : "main 暂无提交";
  } catch {
    elements.updatesStatus.textContent = hasSnapshot
      ? "部署快照 · 最新提交检查暂不可用"
      : "提交记录暂不可用，可通过“全部提交”查看";
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

elements.loadMore.addEventListener("click", () => {
  state.visibleCount += PAGE_SIZE;
  renderProblems();
});

document.addEventListener("keydown", (event) => {
  if (event.key === "/" && !["INPUT", "TEXTAREA", "SELECT"].includes(document.activeElement.tagName)) {
    event.preventDefault();
    elements.search.focus();
  }
});

Promise.allSettled([initProblems(), initUpdates()]);
