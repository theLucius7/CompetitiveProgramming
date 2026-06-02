#!/opt/homebrew/bin/node

import crypto from "node:crypto";
import { spawn } from "node:child_process";
import { promises as fs, readdirSync, statSync } from "node:fs";
import http from "node:http";
import os from "node:os";
import path from "node:path";

const homeDir = os.homedir();
const repoRoot = process.env.CC_RELAY_REPO_ROOT || path.join(homeDir, "Desktop", "CompetitiveProgramming");
const cphDir = path.join(repoRoot, ".cph");
const codeCli =
	process.env.CC_RELAY_CODE_CLI ||
	"/Applications/Visual Studio Code.app/Contents/Resources/app/bin/code";
const templateFilePath =
	process.env.CC_RELAY_TEMPLATE_FILE ||
	path.join(repoRoot, "+oOo0oO0+", "templates", "cph.cpp");
const listenPort = Number(process.env.CC_RELAY_PORT || 4243);
const pollTimeoutMs = Number(process.env.CC_RELAY_POLL_TIMEOUT_MS || 2500);
const disableOpen = process.env.CC_RELAY_DISABLE_OPEN === "1";
const freshWindowMs = 15_000;

const defaultOjCategories = new Map([
	["atcoder", "=qwqwqwq="],
	["codeforces", "=qwqwqwq="],
	["luogu", "=qwqwqwq="],
	["qoj", "=qwqwqwq="],
	["cses", "=ovovovo="],
	["hdu", "=ovovovo="],
	["l7oj", "=ovovovo="],
	["lanqiao", "=ovovovo="],
	["loj", "=ovovovo="],
	["mati", "=ovovovo="],
	["nowcoder", "=ovovovo="],
	["smqyoj", "=ovovovo="],
	["vjudge", "=ovovovo="],
]);

const fallbackCppTemplate = `#include <bits/stdc++.h>

using i64 = long long;

int main() {
\tstd::ios::sync_with_stdio(false);
\tstd::cin.tie(nullptr);

\treturn 0;
}
`;

let workQueue = Promise.resolve();

function log(message, extra = "") {
	const stamp = new Date().toISOString();
	console.log(`[${stamp}] ${message}${extra ? ` ${extra}` : ""}`);
}

function sleep(ms) {
	return new Promise((resolve) => setTimeout(resolve, ms));
}

function sanitizePathComponent(value) {
	return value
		.normalize("NFKC")
		.replace(/[<>:"/\\|?*\u0000-\u001f]/g, "_")
		.replace(/\s+/g, " ")
		.trim()
		.replace(/[. ]+$/g, "") || "untitled";
}

function safeLower(value) {
	return value.toLowerCase();
}

function md5Hex(value) {
	return crypto.createHash("md5").update(value).digest("hex");
}

function isDirectory(filePath) {
	try {
		return statSync(filePath).isDirectory();
	} catch {
		return false;
	}
}

function ojRoot(ojName) {
	const defaultCategory = defaultOjCategories.get(ojName) || "";
	const defaultPath = defaultCategory ? path.join(repoRoot, defaultCategory, ojName) : "";
	if (defaultPath && isDirectory(defaultPath)) {
		return defaultPath;
	}

	try {
		for (const entry of readdirSync(repoRoot, { withFileTypes: true })) {
			if (!entry.isDirectory()) {
				continue;
			}

			const candidate = path.join(repoRoot, entry.name, ojName);
			if (isDirectory(candidate)) {
				return candidate;
			}
		}
	} catch {
		// Fall through to the default category below.
	}

	const directPath = path.join(repoRoot, ojName);
	if (isDirectory(directPath)) {
		return directPath;
	}

	return defaultPath || directPath;
}

function insideRepo(filePath) {
	const normalizedRoot = path.resolve(repoRoot) + path.sep;
	const normalizedFile = path.resolve(filePath);
	return normalizedFile === path.resolve(repoRoot) || normalizedFile.startsWith(normalizedRoot);
}

function parseProblemPayload(rawBody) {
	const text = rawBody.toString("utf8").trim();
	if (!text) {
		throw new Error("empty request body");
	}

	const jsonText = text.startsWith("json\n") ? text.slice(5) : text;
	const payload = JSON.parse(jsonText);
	return Array.isArray(payload) ? payload : [payload];
}

function fallbackFileName(problem) {
	const base =
		problem?.name ||
		problem?.url ||
		`problem-${Date.now()}`;
	return `${sanitizePathComponent(base).replace(/\s+/g, "_")}.cpp`;
}

function resolveCodeforcesTarget(url) {
	const match =
		url.pathname.match(/^\/(?:contest|gym)\/(\d+)\/problem\/([A-Za-z0-9]+)$/) ||
		url.pathname.match(/^\/problemset\/problem\/(\d+)\/([A-Za-z0-9]+)$/);
	if (!match) {
		return null;
	}

	const [, contestId, index] = match;
	return path.join(ojRoot("codeforces"), contestId, `${safeLower(index)}.cpp`);
}

function resolveAtCoderTarget(url) {
	const match = url.pathname.match(/^\/contests\/([a-z0-9]+)\/tasks\/([a-z0-9_]+)$/i);
	if (!match) {
		return null;
	}

	const [, contestId, taskId] = match;
	const suffix = taskId.startsWith(`${contestId}_`)
		? taskId.slice(contestId.length + 1)
		: taskId.split("_").pop();
	return path.join(ojRoot("atcoder"), contestId.toLowerCase(), `${safeLower(suffix)}.cpp`);
}

function resolveLuoguTarget(url) {
	const match = url.pathname.match(/^\/problem\/([A-Za-z0-9]+)$/);
	if (!match) {
		return null;
	}

	const [, problemId] = match;
	return path.join(ojRoot("luogu"), `${problemId}.cpp`);
}

function resolveNowcoderTarget(url) {
	const contestMatch = url.pathname.match(/^\/acm\/contest\/(\d+)\/([A-Za-z0-9]+)$/);
	if (contestMatch) {
		const [, contestId, index] = contestMatch;
		return path.join(ojRoot("nowcoder"), contestId, `${safeLower(index)}.cpp`);
	}

	return null;
}

function resolveCsesTarget(url) {
	const match = url.pathname.match(/^\/problemset\/task\/(\d+)\/?$/);
	if (!match) {
		return null;
	}

	return path.join(ojRoot("cses"), `${match[1]}.cpp`);
}

function resolveLibreOjTarget(url) {
	const match = url.pathname.match(/^\/problem\/(\d+)\/?$/);
	if (!match) {
		return null;
	}

	return path.join(ojRoot("loj"), `${match[1]}.cpp`);
}

function resolveQojTarget(url, problem) {
	const contestMatch = url.pathname.match(/^\/contest\/(\d+)\/problem\/([A-Za-z0-9_+-]+)\/?$/);
	if (contestMatch) {
		const [, contestId, index] = contestMatch;
		return path.join(ojRoot("qoj"), contestId, `${safeLower(index)}.cpp`);
	}

	const problemMatch = url.pathname.match(/^\/problem\/(\d+)\/?$/);
	if (!problemMatch) {
		return null;
	}

	const groupId = String(problem?.group || "").match(/\b(?:contest|qoj)\s*#?\s*(\d+)\b/i)?.[1];
	if (groupId) {
		return path.join(ojRoot("qoj"), groupId, `${problemMatch[1]}.cpp`);
	}

	return path.join(ojRoot("qoj"), `${problemMatch[1]}.cpp`);
}

function resolveVjudgeTarget(url) {
	const contestMatch = url.pathname.match(/^\/contest\/(\d+)(?:\/#problem\/([A-Za-z0-9_+-]+))?\/?$/);
	const hashMatch = url.hash.match(/^#problem\/([A-Za-z0-9_+-]+)$/);
	if (contestMatch) {
		const [, contestId, pathIndex] = contestMatch;
		const index = pathIndex || hashMatch?.[1];
		if (index) {
			return path.join(ojRoot("vjudge"), contestId, `${safeLower(index)}.cpp`);
		}
	}

	const problemMatch = url.pathname.match(/^\/problem\/([A-Za-z0-9_-]+)\/?$/);
	if (problemMatch) {
		return path.join(ojRoot("vjudge"), `${sanitizePathComponent(problemMatch[1])}.cpp`);
	}

	return null;
}

function resolveHduTarget(url) {
	const problemId = url.searchParams.get("pid") || url.pathname.match(/^\/showproblem\.php\/(\d+)\/?$/)?.[1];
	if (!problemId) {
		return null;
	}

	const contestId = url.searchParams.get("cid");
	if (contestId) {
		return path.join(ojRoot("hdu"), contestId, `${safeLower(problemId)}.cpp`);
	}

	return path.join(ojRoot("hdu"), `${safeLower(problemId)}.cpp`);
}

function resolveTargetPath(problem) {
	const rawUrl = problem?.url;
	if (!rawUrl) {
		return path.join(repoRoot, fallbackFileName(problem));
	}

	const url = new URL(rawUrl);
	const host = url.hostname.toLowerCase();

	if (host.endsWith("luogu.com.cn")) {
		return resolveLuoguTarget(url) || path.join(ojRoot("luogu"), fallbackFileName(problem));
	}

	if (host.endsWith("codeforces.com")) {
		return resolveCodeforcesTarget(url) || path.join(ojRoot("codeforces"), fallbackFileName(problem));
	}

	if (host.endsWith("atcoder.jp")) {
		return resolveAtCoderTarget(url) || path.join(ojRoot("atcoder"), fallbackFileName(problem));
	}

	if (host.endsWith("nowcoder.com")) {
		return resolveNowcoderTarget(url) || path.join(ojRoot("nowcoder"), fallbackFileName(problem));
	}

	if (host.endsWith("cses.fi")) {
		return resolveCsesTarget(url) || path.join(ojRoot("cses"), fallbackFileName(problem));
	}

	if (host.endsWith("loj.ac")) {
		return resolveLibreOjTarget(url) || path.join(ojRoot("loj"), fallbackFileName(problem));
	}

	if (host.endsWith("qoj.ac")) {
		return resolveQojTarget(url, problem) || path.join(ojRoot("qoj"), fallbackFileName(problem));
	}

	if (host.endsWith("vjudge.net")) {
		return resolveVjudgeTarget(url) || path.join(ojRoot("vjudge"), fallbackFileName(problem));
	}

	if (host.endsWith("hdu.edu.cn")) {
		return resolveHduTarget(url) || path.join(ojRoot("hdu"), fallbackFileName(problem));
	}

	return path.join(repoRoot, fallbackFileName(problem));
}

async function readJson(filePath) {
	const text = await fs.readFile(filePath, "utf8");
	return JSON.parse(text);
}

async function listProbFiles() {
	try {
		const entries = await fs.readdir(cphDir, { withFileTypes: true });
		return entries
			.filter((entry) => entry.isFile() && entry.name.endsWith(".prob"))
			.map((entry) => path.join(cphDir, entry.name));
	} catch (error) {
		if (error && error.code === "ENOENT") {
			return [];
		}

		throw error;
	}
}

async function findRecentProb(problem, requestStartedAt) {
	const files = await listProbFiles();
	const candidates = [];

	for (const filePath of files) {
		const stat = await fs.stat(filePath);
		if (stat.mtimeMs < requestStartedAt - freshWindowMs) {
			continue;
		}

		let data;
		try {
			data = await readJson(filePath);
		} catch {
			continue;
		}

		if (data?.url === problem.url) {
			candidates.push({ filePath, data, mtimeMs: stat.mtimeMs });
		}
	}

	candidates.sort((left, right) => right.mtimeMs - left.mtimeMs);
	return candidates[0] || null;
}

async function pollForProb(problem, requestStartedAt) {
	const deadline = Date.now() + pollTimeoutMs;

	while (Date.now() <= deadline) {
		const probEntry = await findRecentProb(problem, requestStartedAt);
		if (probEntry) {
			return probEntry;
		}

		await sleep(150);
	}

	return null;
}

async function ensureParentDir(filePath) {
	await fs.mkdir(path.dirname(filePath), { recursive: true });
}

async function loadCppTemplate() {
	try {
		const content = await fs.readFile(templateFilePath, "utf8");
		return content.endsWith("\n") ? content : `${content}\n`;
	} catch {
		return fallbackCppTemplate;
	}
}

async function ensureCppFile(filePath) {
	try {
		await fs.access(filePath);
	} catch {
		await ensureParentDir(filePath);
		await fs.writeFile(filePath, await loadCppTemplate(), "utf8");
	}
}

async function removeFileIfPresent(filePath) {
	try {
		await fs.unlink(filePath);
	} catch (error) {
		if (!error || error.code !== "ENOENT") {
			throw error;
		}
	}
}

async function moveOrDropTempSource(sourcePath, targetPath) {
	if (!sourcePath || sourcePath === targetPath) {
		return;
	}

	if (!insideRepo(sourcePath)) {
		return;
	}

	await ensureParentDir(targetPath);

	try {
		await fs.access(targetPath);
		await removeFileIfPresent(sourcePath);
		return;
	} catch {
		// Target does not exist, continue.
	}

	try {
		await fs.rename(sourcePath, targetPath);
	} catch (error) {
		if (error && error.code === "ENOENT") {
			return;
		}

		if (error && error.code === "EXDEV") {
			let content;
			try {
				content = await fs.readFile(sourcePath);
			} catch (readError) {
				if (readError && readError.code === "ENOENT") {
					return;
				}

				throw readError;
			}

			await fs.writeFile(targetPath, content);
			await removeFileIfPresent(sourcePath);
			return;
		}

		throw error;
	}
}

async function writeProbFile(probFilePath, problem, targetPath) {
	const probData = {
		...problem,
		srcPath: targetPath,
		interactive: Boolean(problem?.interactive),
		tests: Array.isArray(problem?.tests) ? problem.tests : [],
		testType: problem?.testType || "single",
		input: problem?.input || { type: "stdin" },
		output: problem?.output || { type: "stdout" },
	};

	await fs.mkdir(cphDir, { recursive: true });
	await fs.writeFile(probFilePath, JSON.stringify(probData), "utf8");
}

function canonicalProbFilePath(_problem, targetPath) {
	const baseName = path.basename(targetPath);
	return path.join(cphDir, `.${baseName}_${md5Hex(targetPath)}.prob`);
}

async function findAnyProb(problem) {
	const files = await listProbFiles();
	const candidates = [];

	for (const filePath of files) {
		let data;
		try {
			data = await readJson(filePath);
		} catch {
			continue;
		}

		if (data?.url !== problem.url) {
			continue;
		}

		const stat = await fs.stat(filePath);
		candidates.push({ filePath, data, mtimeMs: stat.mtimeMs });
	}

	candidates.sort((left, right) => right.mtimeMs - left.mtimeMs);
	return candidates[0] || null;
}

function isLocalPlaceholderForTarget(data, targetPath) {
	return (
		Boolean(data?.local) &&
		(data?.srcPath === targetPath || data?.url === targetPath)
	);
}

async function pruneDuplicateProbFiles(problem, keepFilePath, targetPath) {
	const files = await listProbFiles();

	for (const filePath of files) {
		if (filePath === keepFilePath) {
			continue;
		}

		let data;
		try {
			data = await readJson(filePath);
		} catch {
			continue;
		}

		if (
			data?.url !== problem.url &&
			data?.srcPath !== targetPath &&
			!isLocalPlaceholderForTarget(data, targetPath)
		) {
			continue;
		}

		await removeFileIfPresent(filePath);
	}
}

async function createOrUpdateCanonicalProb(problem, targetPath) {
	const probFilePath = canonicalProbFilePath(problem, targetPath);
	await writeProbFile(probFilePath, problem, targetPath);
	await pruneDuplicateProbFiles(problem, probFilePath, targetPath);
	return probFilePath;
}

function openInVsCode(targetPath) {
	if (disableOpen) {
		return;
	}

	spawn(codeCli, ["-r", repoRoot, targetPath], {
		detached: true,
		stdio: "ignore",
	});
}

async function syncProblem(problem) {
	const requestStartedAt = Date.now();
	const targetPath = resolveTargetPath(problem);
	const recentProb = await pollForProb(problem, requestStartedAt);
	const probSource = recentProb?.data ? { ...problem, ...recentProb.data } : problem;

	if (recentProb?.data?.srcPath) {
		await moveOrDropTempSource(recentProb.data.srcPath, targetPath);
	}

	await ensureCppFile(targetPath);
	await createOrUpdateCanonicalProb(probSource, targetPath);
	log("generated problem", path.relative(repoRoot, targetPath));
	openInVsCode(targetPath);
}

async function handleProblems(problems) {
	for (const problem of problems) {
		if (!problem || typeof problem !== "object") {
			continue;
		}

		if (!problem.url) {
			log("skipped problem without url");
			continue;
		}

		await syncProblem(problem);
	}
}

function enqueueWork(problems) {
	workQueue = workQueue
		.then(() => handleProblems(problems))
		.catch((error) => {
			log("relay error", error instanceof Error ? error.stack || error.message : String(error));
		});
}

async function readRequestBody(request) {
	const chunks = [];

	for await (const chunk of request) {
		chunks.push(chunk);
	}

	return Buffer.concat(chunks);
}

const server = http.createServer(async (request, response) => {
	if (request.method === "GET") {
		response.writeHead(200, { "Content-Type": "application/json; charset=utf-8" });
		response.end(
			JSON.stringify({
				ok: true,
				port: listenPort,
				repoRoot,
			}),
		);
		return;
	}

	if (request.method !== "POST") {
		response.writeHead(405);
		response.end();
		return;
	}

	try {
		const rawBody = await readRequestBody(request);
		const problems = parseProblemPayload(rawBody);
		enqueueWork(problems);
		response.writeHead(200, { "Content-Type": "text/plain; charset=utf-8" });
		response.end("ok\n");
	} catch (error) {
		const message = error instanceof Error ? error.message : String(error);
		log("bad request", message);
		response.writeHead(400, { "Content-Type": "text/plain; charset=utf-8" });
		response.end(`${message}\n`);
	}
});

server.listen(listenPort, () => {
	log("competitive companion relay listening", `port=${listenPort}`);
	log("repo root", repoRoot);
});
