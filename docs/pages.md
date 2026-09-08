# GitHub Pages 维护

[站点](https://thelucius7.github.io/CompetitiveProgramming/)提供题目检索、源码阅读、提交日历与 Rating。它是纯静态页面，没有 npm 构建步骤，也不在浏览器中编译或执行题解。

## 分支与发布边界

| 分支 | 职责 | 更新后影响 |
| --- | --- | --- |
| `main` | OJ 源码、算法模板和练习档案 | 站点在线查询此分支的文件树和源码；不会自动重生成部署快照 |
| `gh-pages` | 独立的网站文件、静态资源和数据快照 | GitHub Pages 的发布来源；网站改动在此分支维护 |
| `docs/project-guide` | 本文、仓库 README 与维护规范 | 文档工作分支；不作为 Pages 发布来源 |

不要将 `main` 或文档分支整体合并进 `gh-pages`。网站修改应基于 `gh-pages` 开展；新增题解仍进入 `main`。

2026-09-08 核对的 Pages 设置：`Settings → Pages → Build and deployment` 使用 **Deploy from a branch**，分支 `gh-pages`，目录 `/(root)`，HTTPS 已启用，无自定义域名。最新构建为 `built`，对应 `0e17763`。后续维护请重新查询实际状态，不把此记录当作实时状态。

## 网站文件

以下路径相对于 `gh-pages` 根目录，而非本文所在分支：

```text
index.html                    页面、链接与代码抽屉
styles.css                    布局、日历色阶与代码样式
app.js                        检索、排序、在线同步与代码加载
data/site-data.json            可提交的部署快照
scripts/generate-data.mjs      从 Git 文件树和历史生成快照
assets/                       AtCoder、Codeforces 本地图标
vendor/highlight.min.js        本地 Highlight.js
vendor/github-dark.min.css     代码高亮主题
vendor/HIGHLIGHTJS-LICENSE.txt 第三方许可证
favicon.svg                   网站图标
.nojekyll                     直接提供静态资源
```

## 本地预览与快照生成

需要 Git、Python 3；生成快照还需要支持全局 `fetch` 的 Node.js（Node.js 18+，建议使用仍受支持的 LTS 版本）。以下命令从仓库根目录执行，示例工作目录应尚不存在：

```bash
git fetch origin main gh-pages
git worktree add --detach ../CompetitiveProgramming-pages origin/gh-pages
cd ../CompetitiveProgramming-pages
git switch -c pages/update-snapshot
node scripts/generate-data.mjs origin/main
python3 -m http.server 4173 --bind 127.0.0.1
```

浏览 [本地预览](http://127.0.0.1:4173/)，结束时在服务器终端按 `Ctrl+C`。只预览既有部署时可以跳过分支创建和快照生成；不要直接双击 HTML，页面需要 HTTP 加载 JSON。

生成器实际写入 `data/site-data.json`，参数用于选择读取的 Git 文件树和历史；省略参数时读取本地 `main`。使用 `origin/main` 可以避免本地 `main` 落后于刚拉取的远端分支。仓库必须保留完整历史，否则时间和日历会不完整；浅克隆应先执行 `git fetch --unshallow origin`。

生成器中的网站仓库分支仍固定为 `main`，参数不会更改源码链接目标。命令还会请求 Rating 接口；接口失败时相应 Rating 写为 `null`，因此提交前应检查是否意外丢失已有数据。目前没有自动刷新快照的工作流，也没有为生成器的 Rating 请求设置超时。

## 数据来源和已知边界

页面先加载部署快照，再并行尝试题库、日历和 Rating 三个在线更新。`Promise.allSettled` 等到三项都成功或失败后，才将成功项写入状态并统一重绘；失败项保留已有数据。Rating 内部也等待两个平台请求都结束，才返回成功平台的数据。因此，一个请求一直未结束会拖延其他已完成结果的展示。快照不包含源码正文，不能保证离线阅读代码。

| 内容 | 数据来源与行为 |
| --- | --- |
| 题目列表 | GitHub `git/trees/main?recursive=1`；从路径推断平台、题号、语言和题目链接，支持按 OJ、名称或路径搜索，每次显示 60 条 |
| 提交时间 | 生成器读取 `git log <ref> --name-only --format=@@COMMIT@@%cI`，为路径记录遍历中首次遇到的提交者时间；并非 OJ 提交时间，也没有为每个文件实时查询历史 |
| 默认排序 | 按 `submittedAt` 从新到旧，同一时间按路径排序；缺少时间时显示“时间未知”并排在有效日期之后 |
| 贡献日历 | 快照按 `git log` 的作者日期、`Asia/Taipei` 时区统计；在线来源为仓库 `stats/commit_activity`，按返回时间转为 UTC 日期。展示 53 周，零提交为白色，其余分为四级绿色 |
| AtCoder Rating | `https://kenkoooo.com/atcoder/proxy/users/Lucius7/history/json`，这是第三方代理；取有效 rated 场次的最后一条 `NewRating`，同时计算最高 Rating 和比赛数 |
| Codeforces Rating | `https://codeforces.com/api/user.info?handles=Lucius7`，读取 `rating`、`maxRating` 和 `rank`；成功的平台单独更新，失败的平台保留快照值 |

日历反映仓库提交，不是整个 GitHub 账号的贡献图。快照与在线统计的来源、日期口径不同，午夜附近的归属或总数可能不同；绿色深浅按已载入数据中的每日最大值划分。提交时间显示使用浏览器本地时区。

在线刷新题库时，已有路径沿用快照中的时间。新文件会出现，但没有快照记录就显示“时间未知”；已修改文件的时间也要重新生成快照才会更新。页面的“实时同步”提示不代表提交时间也已实时刷新。

### 路径解析

`app.js` 和 `scripts/generate-data.mjs` 各有一份 `problemFromPath` 规则。调整目录或新增 OJ 时需要同时检查两份实现：

- 第一层目录被当作平台；文件必须位于子目录中，并使用 `cpp`、`cc`、`cxx`、`c`、`py`、`java`、`rs`、`go` 或 `kt` 扩展名。
- `Templates`、`.cph`、`.vscode`、`.github`、`assets`、`data`、`scripts` 被排除；根目录独立源码也不进入题库。
- 例如 `AtCoder/<contest>/<problem>.cpp`、`Codeforces/<contest>/<problem>.cpp` 用于拼接题目链接；部分平台只能跳转到比赛页或平台主页，并非全部具备精确题目链接。
- 非排除的未知顶层目录也可能被当成 OJ；因此不能仅凭页面出现条目就判断路径兼容。

现有生成器有非 ASCII 路径漏收问题：它使用 `git ls-tree -r --name-only`，没有启用 `-z` 或关闭 `core.quotepath`。在默认 Git 路径转义设置下，含中文或 `é` 等字符的路径带外层双引号和八进制转义，扩展名被读成 `cpp"`，因此被过滤。例如真实路径 `HDU/1230/xyz_问题.cpp`、`NowCoder/133882/Pokémon_GET_daze.cpp` 会受影响。生成器读取提交历史时虽然关闭了路径转义，但不能补回已从文件树阶段遗漏的条目。

2026-09-08 对 `main` 的 `7cca2a6` 核对结果如下，不能把旧快照数量当作全仓 OJ 源码数量：

| 核对对象 | 可识别条目数 | 依据 |
| --- | ---: | --- |
| 真实 Git 路径 | 1,291 | `git ls-tree -rz --name-only origin/main` 获取未转义路径，再应用网站的目录和扩展名规则 |
| GitHub 在线树 | 1,291 | 树接口返回同一提交、`truncated: false`，路径无 Git 显示转义 |
| 当前生成器的默认文件树输出 | 1,257 | 34 个非 ASCII 路径被转义后过滤 |
| 部署快照 | 1,257 | `generatedAt` 为 `2026-09-04T05:48:48.809Z`，路径集合与上述生成器结果一致 |

缺少的 34 份分别位于 HDU（4）、L7OJ（27）、NowCoder（3）。在线树成功载入后可以补出这些文件，但快照没有它们的提交时间，所以仍显示“时间未知”。这些记录证明当前快照与真实题库存在差异；本次文档整理未修改生成器或网站。

### 源码与高亮

打开代码时先查当前页面内存缓存，再请求 GitHub Contents API，超时为 5 秒；失败后并行尝试 jsDelivr 和 `raw.githubusercontent.com`，各自超时为 7 秒，取首个成功响应。三者均失败时显示错误，并提供 GitHub 源码链接。缓存只在当前页面会话有效，修改后的同路径代码可能需要刷新页面才能看到。

本地 Highlight.js `11.12.0` 与 GitHub Dark 主题按已识别语言高亮，支持 C++、C、Python、Java、Rust、Go、Kotlin；语法不可用或渲染异常时回退为纯文本。行号由源码行数生成，复制按钮复制原始源码。升级第三方资源时保留许可证文件。

## 验证与发布

在网站工作目录中先做静态检查：

```bash
node --check app.js
node --check scripts/generate-data.mjs
node -e 'const fs=require("node:fs"); const d=JSON.parse(fs.readFileSync("data/site-data.json","utf8")); console.log({generatedAt:d.generatedAt, sourceRef:d.sourceRef, problems:d.problems.length, unknownDates:d.problems.filter(p=>!p.submittedAt).length, ratings:d.ratings});'
git diff --check
git diff --stat
```

启动本地服务器后，在另一终端检查资源响应，并实际检查列表筛选、默认日期排序、代码打开/复制、加载提示消失、窄屏布局和个人链接：

```bash
curl --fail --head http://127.0.0.1:4173/
curl --fail --head http://127.0.0.1:4173/data/site-data.json
curl --fail --head http://127.0.0.1:4173/vendor/highlight.min.js
```

按仓库协作流程审阅网站差异后，将网站工作分支合入 `gh-pages`。仅更新 `main` 不会刷新已提交的 JSON。推送后用 GitHub Pages 设置页或下列只读命令检查发布；构建成功还应核对线上功能，不能用语法检查代替页面验证。

```bash
gh api repos/theLucius7/CompetitiveProgramming/pages --jq '{status,source,https_enforced,html_url}'
gh api repos/theLucius7/CompetitiveProgramming/pages/builds/latest --jq '{status,commit,error}'
curl --fail --head https://thelucius7.github.io/CompetitiveProgramming/
```

## 常见故障

| 现象 | 检查与处理 |
| --- | --- |
| 新题目没出现，或 OJ / 题目链接错误 | 先查 `main` 路径是否匹配两份解析规则、是否处于排除目录，再检查树接口；当前实现未检查 GitHub 树响应的 `truncated` 标记，大仓库需留意响应完整性 |
| 新文件时间未知、修改时间未更新 | 在最新 `origin/main` 上重生成快照，检查 JSON 中该路径的 `submittedAt`，然后发布到 `gh-pages` |
| 已显示代码但仍有“正在载入代码” | 检查线上 `app.js` 与 `styles.css` 是否为同次发布，尤其保留 `[hidden] { display: none !important; }`；清除缓存后重试 |
| 代码加载失败 | 检查 GitHub Contents API、jsDelivr、raw 域名的网络响应，以及文件是否仍存在于 `main`；使用抽屉中的 GitHub 链接核对源码 |
| 长时间显示“正在同步” | 浏览器网络面板检查树、统计、Rating 请求；这些在线数据请求没有统一超时，且视图更新等待全部结束。代码请求的超时机制并不覆盖它们 |
| 日历保持旧数据 | 统计接口最多请求三次；每次返回 `202` 后分别等待 1.3、2.6、3.9 秒，三次均为 `202` 时抛错并保留快照。其他非成功响应会立即失败，不经过这组重试；成功结果也要等待并行的题库和 Rating 请求结束才展示 |
| Rating 未更新或显示不可用 | 检查两个接口是否响应、浏览器是否允许跨域；代码允许某个平台单独失败。勿手工把未知 Rating 写为零 |
| 部署后仍看到旧页面 | 核对最新 Pages 构建的 `commit` 是否为预期提交，再检查资源缓存；URL 查询参数可辅助刷新，但不能代替成功部署 |

本文以 `gh-pages` 的实际代码和 Pages API 核对结果为依据；以上机制记录现状，不表示这些边界已经在网站中修复。
