const { REPOSITORY, HIGHLIGHT_LANGUAGES, problemFromPath, encodePath, formatSubmissionTime, fetchTextWithTimeout } = Archive;
const reader = {
  title: document.querySelector("#reader-title"),
  path: document.querySelector("#reader-path"),
  submittedAt: document.querySelector("#reader-submitted-at"),
  problemLink: document.querySelector("#reader-problem-link"),
  githubLink: document.querySelector("#reader-github-link"),
  language: document.querySelector("#reader-language"),
  lines: document.querySelector("#reader-lines"),
  state: document.querySelector("#reader-state"),
  message: document.querySelector("#reader-message"),
  retry: document.querySelector("#retry-code"),
  scroller: document.querySelector("#code-scroller"),
  code: document.querySelector("#code-content"),
  lineNumbers: document.querySelector("#line-numbers"),
  copy: document.querySelector("#copy-code"),
  copyLabel: document.querySelector("#copy-label"),
  copyStatus: document.querySelector("#copy-status"),
};
const readerState = { problem: null, code: null, loading: false, copyTimer: null };

async function loadProblemCode(problem) {
  const encoded = encodePath(problem.path);
  const base = `${REPOSITORY.owner}/${REPOSITORY.name}`;
  try {
    return await fetchTextWithTimeout(
      `https://api.github.com/repos/${base}/contents/${encoded}?ref=${REPOSITORY.branch}`,
      { headers: { Accept: "application/vnd.github.raw+json", "X-GitHub-Api-Version": "2022-11-28" }, cache: "no-cache" },
      5000,
    );
  } catch {
    return Promise.any([
      fetchTextWithTimeout(`https://cdn.jsdelivr.net/gh/${base}@${REPOSITORY.branch}/${encoded}`, {}, 7000),
      fetchTextWithTimeout(problem.rawUrl, { cache: "no-cache" }, 7000),
    ]);
  }
}

function renderCode(code, language) {
  const text = code.replace(/\r\n?/g, "\n");
  const grammar = HIGHLIGHT_LANGUAGES[language];
  reader.code.className = "hljs";
  reader.code.textContent = text;
  if (grammar && window.hljs?.getLanguage?.(grammar)) {
    try {
      reader.code.innerHTML = window.hljs.highlight(text, { language: grammar, ignoreIllegals: true }).value;
      reader.code.className = `hljs language-${grammar}`;
    } catch {
      reader.code.textContent = text;
    }
  }
  // Do not count the normal final newline as an additional source line.
  const count = text ? text.split("\n").length - Number(text.endsWith("\n")) : 0;
  reader.lineNumbers.textContent = Array.from({ length: count }, (_, index) => index + 1).join("\n");
  reader.lines.textContent = `${count} 行`;
}

async function showCode() {
  if (!readerState.problem || readerState.loading) return;
  readerState.loading = true;
  readerState.code = null;
  reader.copy.disabled = true;
  reader.scroller.hidden = true;
  reader.state.hidden = false;
  reader.state.setAttribute("aria-busy", "true");
  reader.message.textContent = "正在载入代码…";
  reader.retry.hidden = true;
  try {
    const code = await loadProblemCode(readerState.problem);
    readerState.code = code;
    renderCode(code, readerState.problem.language);
    reader.scroller.hidden = false;
    reader.state.hidden = true;
    reader.copy.disabled = false;
  } catch {
    reader.message.textContent = "代码暂时无法载入。可重试，或在 GitHub 查看。";
    reader.retry.hidden = false;
  } finally {
    readerState.loading = false;
    reader.state.setAttribute("aria-busy", "false");
  }
}

async function loadSubmissionTime(problem) {
  try {
    const data = JSON.parse(await fetchTextWithTimeout("./data/site-data.json", { cache: "no-cache" }));
    const match = data.problems?.find((item) => item.path === problem.path);
    if (match?.submittedAt && Number.isFinite(Date.parse(match.submittedAt))) {
      reader.submittedAt.dateTime = match.submittedAt;
      reader.submittedAt.textContent = `最后提交 · ${formatSubmissionTime(match.submittedAt)}`;
      reader.submittedAt.title = `Git 提交者时间，来自部署快照。 ${formatSubmissionTime(match.submittedAt, true)}`;
    }
  } catch {
    // Metadata is optional and never gates source loading.
  }
}

async function copyCode() {
  if (readerState.code === null) return;
  window.clearTimeout(readerState.copyTimer);
  reader.copyLabel.textContent = "复制代码";
  reader.copyStatus.textContent = "";
  try {
    await navigator.clipboard.writeText(readerState.code);
    reader.copyLabel.textContent = "已复制";
    reader.copyStatus.textContent = "已复制完整源码";
  } catch {
    reader.copyStatus.textContent = "复制未获允许，请选中代码复制";
  }
  readerState.copyTimer = window.setTimeout(() => {
    reader.copyLabel.textContent = "复制代码";
    reader.copyStatus.textContent = "";
  }, 2200);
}

function initReader() {
  const sourcePath = new URLSearchParams(window.location.search).get("path");
  const problem = problemFromPath(sourcePath);
  if (!problem) {
    reader.title.textContent = "无法打开代码";
    reader.message.textContent = "代码地址无效，请从题库选择文件。";
    reader.state.setAttribute("aria-busy", "false");
    return;
  }
  readerState.problem = problem;
  document.title = `${problem.title} · ${problem.language} · Lucius7`;
  reader.title.textContent = problem.title;
  reader.path.textContent = problem.path;
  reader.path.title = problem.path;
  reader.language.textContent = problem.language;
  reader.problemLink.href = problem.problemUrl;
  reader.problemLink.hidden = false;
  reader.githubLink.href = problem.githubUrl;
  reader.githubLink.hidden = false;
  // These requests deliberately start independently.
  return Promise.allSettled([showCode(), loadSubmissionTime(problem)]);
}

reader.copy.addEventListener("click", copyCode);
reader.retry.addEventListener("click", showCode);
initReader();
