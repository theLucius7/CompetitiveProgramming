# GitHub Pages 维护

[根题库](https://thelucius7.github.io/CompetitiveProgramming/)展示 main 最近六次提交、题目检索与源码阅读。首页不再展示 Rating 或贡献日历，也不再请求其在线接口。根题库是纯静态网站，不在浏览器中执行题解。[文档站](https://thelucius7.github.io/CompetitiveProgramming/docs/)使用 VitePress，独立流程见[文档部署](maintenance.md)。

## 分支与发布边界

| 分支 | 职责 | 更新后影响 |
| --- | --- | --- |
| `main` | OJ 源码与练习档案 | 网页在线读取文件树、最近提交和源码；不自动重生成 JSON |
| `gh-pages` | 根题库、静态快照、生成的 `docs/` | GitHub Pages 发布来源，目录为 `/(root)` |
| `docs/project-guide` | 文档源、API Schema 与发布校验 | 推送后独立发布至 `gh-pages/docs/`；无需向 main 推送 |

不要把 main 或文档分支整体合入 gh-pages。网站源码修改基于 gh-pages；文档修改基于 docs/project-guide。文档工作流只更新生成的 docs 目录，保留根题库。

## 网站文件

路径相对于 gh-pages 根目录：

```text
index.html                    题库页面与最近提交列表
styles.css                    题库布局与系统深浅色
app.js                        检索、排序和独立在线检查
archive.js                    共享路径校验、题目解析与请求工具
code.html                     独立全屏源码阅读页
reader.js                     源码、提交时间、复制与高亮
reader.css                    全视口阅读布局与系统深浅色
data/site-data.json            题库快照，保留旧统计字段
data/recent-commits.json       最近六次提交快照
scripts/generate-data.mjs      从 Git 文件树和历史生成两份快照
scripts/check-reader.mjs       非浏览器阅读页与题库回归测试
vendor/                       本地 Highlight.js、主题及许可证
favicon.svg                   网站图标
.nojekyll                     直接提供静态资源
docs/                         自动发布的文档网站，勿手工修改
```

## 生成与预览

需要 Git、Node.js（建议受支持的 LTS）和 Python 3。保留完整 Git 历史，示例工作目录应尚不存在：

```bash
git fetch origin main gh-pages
git worktree add --detach ../CompetitiveProgramming-pages origin/gh-pages
cd ../CompetitiveProgramming-pages
git switch -c pages/update-snapshot
node scripts/generate-data.mjs origin/main
python3 -m http.server 4173 --bind 127.0.0.1
```

浏览[本地预览](http://127.0.0.1:4173/)，结束时按 Ctrl+C。省略生成器参数时读取本地 main；建议使用刚获取的 origin/main。参数不会改变源码链接中的 main 分支。浅克隆先补齐历史，否则提交数量和时间不完整。

生成器写入两份 JSON。题库的 `commitCount`、`contributions` 继续生成以兼容旧契约；`ratings` 仅保留已有历史值，未知时为 null，不再请求 Rating 服务。生成时刻不等于 Rating 更新时间。

## 页面更新机制

题目与最近提交是两个独立流程：各自先读部署快照，再检查 GitHub；单个 JSON 请求最多 6 秒，使用缓存重新验证。失败的在线请求保留该列表的快照并注明，不会阻塞另一列表。快照与在线请求都失败时停止加载提示，显示错误入口。

| 内容 | 来源与规则 |
| --- | --- |
| 最近提交 | `commits?sha=main&per_page=6`；显示消息首行、SHA 与提交者时间，点击进入提交详情 |
| 提交顺序 | Git/API 返回顺序，最多六次，含合并提交；不按日期二次排序 |
| 题目列表 | `git/trees/main?recursive=1`；拒绝被截断的树；按路径识别 OJ、题号和语言，每页 60 条 |
| 文件提交时间 | 生成器遍历 Git 历史，记录每个路径首次遇到的 `%cI`（提交者时间），不是 OJ 评测时间 |
| 默认题目排序 | `submittedAt` 从新到旧，相同时间按路径，未知时间置后 |

显示日期使用浏览器本地时区。最近提交的时间是 `commit.committer.date`，不是快照生成时间，也不是作者日期。提交说明作为纯文本插入页面。

在线文件树不包含逐文件提交时间，已有文件继续使用快照日期。新增文件没有快照记录时显示“时间未知”；修改后的文件日期也需重生成快照。因此状态只说“代码列表已检查”，不宣称所有数据实时同步。源码正文需联网单独读取。

## 路径解析与完整性

`archive.js` 与生成器各有 `problemFromPath`；题库和阅读页共用前者，新增 OJ 或改路径时检查两份规则：

- 子目录内支持 cpp、cc、cxx、c、py、java、rs、go、kt；第一段作为平台。
- 排除 Templates、.cph、.vscode、.github、assets、data、scripts；根目录独立源码不收录。
- 部分平台只能推导比赛页或平台首页，不保证每条均为精确原题地址。
- 未排除的新目录也可能被当作 OJ，需核对实际语义。

旧生成器没有用 NUL 分隔 Git 文件树，导致中文等非 ASCII 路径转义后漏收。现改用 `git ls-tree -r -z --name-only`。对 main 的 `7cca2a6` 核对：新快照和真实可识别路径均为 **1,291** 条，全部有提交日期；旧快照为 1,257 条。补齐的 34 条分布为 HDU 4、L7OJ 27、NowCoder 3。该数量是此提交的核对记录，不是契约固定值。

## 源码与高亮

题目行使用原生链接，在新标签页打开 `code.html?path=...`；原题库的筛选和滚动位置不变。阅读页占据完整视口，源码区域独立横纵滚动，无半屏抽屉、遮罩或关闭按钮。可直接复制阅读页地址访问；“题库”是正常导航链接，不依赖上一页历史或原标签页对象。

阅读页校验路径后立即请求 GitHub Contents API（5 秒超时），失败时并行尝试 jsDelivr 和 raw.githubusercontent.com（各 7 秒），取首个成功结果。均失败则结束加载状态，提供重试按钮及 GitHub 源码入口。提交时间从快照独立读取，失败或缺失时显示未知，不阻塞代码。

仅接受合法的仓库相对源码路径；URL 参数解码一次，不允许空段、路径穿越、反斜杠或控制字符。仓库与 main 分支固定，不接受自定义源码服务器地址。

本地 Highlight.js 11.12.0 与 GitHub 浅色／深色主题跟随系统外观，失败回退纯文本。渲染时统一换行，行号不将文件末尾的换行符计为额外一行；复制保留原始完整内容（包括 CRLF）。当前阅读页保留源码原文供复制，不再使用题库按路径索引的内存缓存。保留 `[hidden] { display: none !important; }`，避免成功后仍显示加载提示。

## 校验与发布

```bash
node --check app.js
node --check archive.js
node --check reader.js
node --check scripts/generate-data.mjs
node scripts/check-reader.mjs
git diff --check
curl --fail --head http://127.0.0.1:4173/
curl --fail --head http://127.0.0.1:4173/data/recent-commits.json
```

两份 JSON 均应通过[API 校验](api/standards.md)。审阅网站变更后推送 gh-pages，保留 docs 目录。修改文档及契约则推送 docs/project-guide；若增加数据端点，先发布数据文件，再运行依赖真实远端快照的文档校验。

```bash
gh api repos/theLucius7/CompetitiveProgramming/pages --jq '{status,source,https_enforced,html_url}'
gh api repos/theLucius7/CompetitiveProgramming/pages/builds/latest --jq '{status,commit,error}'
curl --fail --head https://thelucius7.github.io/CompetitiveProgramming/
```

构建成功后核对公共资源与预期版本，不能把本地语法检查当作已上线。

## 常见故障

| 现象 | 处理 |
| --- | --- |
| 新题目未出现 | 检查 main 路径、排除规则、树接口是否失败或截断 |
| 文件日期未知或落后 | 从最新 origin/main 重生成两份快照并发布 |
| 最近提交保持旧数据 | 在线接口可能超时或限流，页面会注明使用部署快照；通过“全部提交”核对 GitHub |
| 代码已显示但仍有加载文字 | 核对 code.html、reader.js、reader.css 同次发布，以及 hidden 样式 |
| 代码加载失败 | 检查 Contents、jsDelivr、raw 来源；打开 GitHub 源码链接 |
| 部署后仍为旧页面 | 核对 Pages 构建提交、公共资源与缓存，不能只靠 URL 查询参数判断部署 |
