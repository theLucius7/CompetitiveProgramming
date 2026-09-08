# 比赛提交源码归档

`archive_sync.py` 将 Lucius7 在 AtCoder、Codeforces、QOJ 的本人提交整理到现有比赛目录。比赛与题目映射来自 [qwq dashboard](https://thelucius7.github.io/qwq/data/dashboard.json)，要求 `schemaVersion: 2`、`handle: Lucius7`。`archive_plan.py` 是独立的离线规划模块，不获取网络数据、不写源码。

## 范围和选择规则

- 正式参赛、练习、虚拟参赛均在范围内。只处理有实际提交的比赛及已尝试的题目；不会为未提交的题目生成空文件。
- 同一题优先选择最新 AC，识别 `AC`、`OK`、`Accepted`；没有 AC 时选择最新尝试，包括 WA、TLE 等。保留全部候选供审计，导入器只接受当前排序第一的提交。
- AtCoder 和 Codeforces 可刷新全提交历史，包含未 AC 的记录。传入历史按平台替换 dashboard 的 AC 候选；尚未取得历史的平台继续使用 `dashboard.accepted`，其未解决尝试保留在清单中。公开 API 的完整性取决于平台返回的数据和分页是否成功。
- 提交记录里的真实比赛 ID 优先；AtCoder、Codeforces 的可信提交 URL 也可确定场次。共享题只进入实际提交的比赛。QOJ 记录缺场次且映射到多个比赛时标记为 `ambiguous`，不猜测归属。
- 目录形式为 `AtCoder/<比赛小写>/<题号小写>.<扩展名>`、`Codeforces/<比赛数字>/<原题号大写>.<扩展名>`、`QOJ/<比赛数字>/<题号小写>.<扩展名>`。数字题号也被保留。
- 已有受支持语言的源码或已知题号别名都会被识别。例如 `QOJ/3758/18279.cpp` 已代表比赛题号 `h`，不会另建 `h.cpp`。匹配使用完整文件名，不会把 Codeforces 的 `C1.cpp` 当作 `C.cpp`。
- 不覆盖、不重命名已有源码。语言决定固定扩展名，支持 C/C++、Python/PyPy、Java、Rust、Go、Kotlin、C#、JavaScript、TypeScript 等；未知语言报错，不默认保存为 C++。

## 生成或刷新清单

在 macOS 或 Linux 的仓库根目录使用 Python 3.10 或更新版本，无额外 Python 包依赖；进程锁使用系统提供的 `fcntl`：

```sh
python3 scripts/archive_sync.py plan --refresh-history
```

该命令读取公开 qwq 快照，并分页获取 AtCoder、Codeforces 的提交元数据。元数据获取失败时保留已有历史，在 `.archive/metadata-errors.json` 记录原因。访问限制或限流会停止相应请求；不会因此取得原本不可访问的源码。

使用本地 dashboard 快照生成清单，不刷新远端历史：

```sh
python3 scripts/archive_sync.py plan --dashboard .archive/dashboard.json
```

重新扫描现有文件并查看状态：

```sh
python3 scripts/archive_sync.py status
```

`status` 会先恢复尚未结束的导入事务，再重新生成 `.archive/plan.json`；恢复可能补完已经验证的源码或来源收据。它不会自行选择和采集新源码。修改规划器或更新历史后，应刷新清单再解读旧的状态数量。

| 状态 | 含义 | 下一步 |
| --- | --- | --- |
| `existing` | 已有匹配的源码 | 保留现有文件 |
| `missing` | 有候选提交，缺少本地源码 | 打开第一候选的提交页面，读取完整源码 |
| `needs_submission` | 知道曾尝试，但没有候选提交记录 | 补充该平台的提交历史 |
| `ambiguous` | 场次、比赛题号或目标文件归属有歧义 | 补充真实场次或题目映射后重建清单 |

每项包含 `key`、`platform`、`contestId`、`problemId`、`index`、不带扩展名的相对 `targetStem`、`existing` 路径、排序后的 `candidates` 和 `reason`。候选里的语言可能为空，例如 dashboard 的 AC 摘要，需要从实际提交页面补全。

## 通过正常浏览器导入源码

```sh
python3 scripts/archive_sync.py serve --port 4181
```

服务仅监听本机 `127.0.0.1`。在正常浏览器中打开 `http://127.0.0.1:4181/` 查看队列。到相应 OJ 的候选提交页面读取本人完整源码与可见元数据，再将 JSON 数组填入本地页面，类型选择“源码”。每批接受 **1–50 条源码记录**，同批 `key` 不得重复。此流程不保证每个 OJ 都允许匿名访问；需要认证时，应在该 OJ 的正常页面登录。提交被限制访问时，保留未完成状态。

页面只展示前 50 个待处理项，避免大型清单影响表单响应；导入后刷新会显示下一批。总数量仍覆盖完整范围，完整队列保存在 `.archive/plan.json`。

源码记录格式如下，尖括号字段须替换为清单和提交页面的真实值；不要将示例文本当作源码导入：

```json
[
  {
    "key": "<entry.key>",
    "platform": "<entry.platform>",
    "id": "<entry.candidates[0].id>",
    "problemId": "<entry.problemId>",
    "contestId": "<entry.contestId>",
    "handle": "Lucius7",
    "language": "<提交页面显示的语言>",
    "verdict": "<提交页面显示的结果>",
    "url": "<当前候选的真实提交页面 URL>",
    "code": "<完整源码，保留换行与空白>",
    "captureFormat": "plaintext_pre"
  }
]
```

`codeSize` 可选，源码导入时必须是正整数字节数，最大为 2,000,000；入口也接受仅含数字的字符串。页面显示的 `262 Byte` 应先转换为 `262`。源码统一保存为 UTF-8、LF 换行，源码自身也受同样的字节上限限制。页面和候选历史若都提供长度，两者都会独立校验；任一不匹配都会拒绝导入。

`captureFormat` 可选，只允许 `plaintext_pre` 和 `rendered_lines`，分别表示直接读取纯文本代码块和从页面渲染的逐行节点重建。`sourceLines` 可选，必须为正整数，按**最终源码先统一为 LF，再用 `split("\n")` 得到的数组长度**计算，即 LF 数量加一。末尾存在 LF 时，最后一个空段也要计数；例如 `"a\n"` 是 2 行。不要使用会丢掉末尾空段的计数方法。

导入器核对所有者、提交 ID、比赛、题目、页面 URL、结果及语言。候选已知语言时，页面语言必须映射为同一扩展名。通过验证后才发布源码并写入来源收据；目标已存在时不会覆盖。

### 浏览器采集时保留原始内容

- Codeforces 团队参赛的作者列可能有多个个人主页链接。应确认其中包含 `Lucius7`，不能只检查第一个作者链接，也不能把团队名当作本人账号。
- Codeforces 的代码 `pre` 可能被渲染为 `ol > li`。此时应按顺序读取每个 `li` 的文本，再用单个 LF 连接，记录 `captureFormat: "rendered_lines"`。只有一整行恰好是单个 NBSP（`\u00a0`）时，才把它还原为空字符串；其余空格、缩进及字符保持原样。直接读取整个渲染块的拼接文本可能丢失行边界。
- 对纯文本代码块保留完整文本，记录 `captureFormat: "plaintext_pre"`，不要对源码使用 `trim()`。行数应从最终提交给入口的 `code` 计算。
- 已观察到两份 QOJ 提交的 DOM 代码末尾比已知原始源码多一个 LF。采集阶段只有在原文本无法通过已知字节数校验、且删除**单个末尾 LF**后恰好匹配时，才可作此还原；有多个长度来源时必须全部满足。无法据此确定时保留错误并核对页面，不能反复删除换行或跳过长度校验。

长度校验同时考虑原始 CRLF：将文本统一为 LF 后，设 UTF-8 字节数为 `B`、LF 数量为 `N`，已知原始字节数必须为 `B` 或 `B + N`。QOJ 的单个末尾 LF 还原也使用这条规则，并在还原后重新计算 `sourceLines`。入口本身始终执行长度检查，不会自动删除多余的末尾 LF。

### QOJ 整表历史

QOJ 完整历史通过同一页面的“QOJ 提交历史”类型导入。顶层必须是封装对象，且只能包含以下四个字段：

| 字段 | 类型与要求 |
| --- | --- |
| `records` | 全部标准提交记录组成的数组，长度必须等于 `expectedCount` |
| `pages` | 从 1 开始、连续且升序的整数页码数组，完整覆盖每页 10 条的全部页面 |
| `complete` | 布尔值，必须为 `true`，表示已核对并采集完整历史 |
| `expectedCount` | 正整数，最大为 100,000，来自实际历史总数 |

例如确认总数为 69 条时，`expectedCount` 为 `69`，`pages` 为 `[1, 2, 3, 4, 5, 6, 7]`，`records` 必须放入全部 69 条记录。**69 条和 7 页只是例子，不是固定配置。** 新总数应按实际页面重新核对。导入总数不得少于 dashboard 已知的 QOJ 提交数，也不得少于之前保存的 QOJ 历史。

每条记录使用标准字段 `platform`、`id`、`problemId`、`contestId`、`epoch`、`language`、`verdict`、`url`、`handle`，可附 `codeSize`。`platform` 必须为 `qoj`，`handle` 必须为 `Lucius7`；提交 ID 为正整数或其数字字符串，整表中不得重复。`epoch` 为 Unix 秒；确实不知道场次时 `contestId` 使用 `null`，不要凭全局题号猜场次。整表通过验证后替换本地 QOJ 历史文件，其他平台历史保留。

本地入口校验来源、Host 与会话令牌，不读取或保存浏览器 Cookie。源码须先通过正常浏览器可访问的提交页面取得；工具不会执行归档的源码。

## 文件和来源记录

`.archive/` 保存运行中的 dashboard、各平台历史、元数据错误和最新规划清单。源码仍放在各 OJ 原有比赛目录下。导入收据写入 `archive/submissions.json`，记录平台、本人账号、比赛和题目、提交 ID、提交时间、语言、结果、来源 URL、归档路径、SHA-256、字节数、导入时间、dashboard 时间以及 `normal_browser` 采集方式。提交时提供的 `captureFormat` 和 `sourceLines` 也会进入收据。已有源码不会被伪造补写为本次导入记录。

## 已核对的比赛目录归属补充

`archive/contest-mappings.json` 保存经官方页面核对、但 qwq 暂时缺失的完整比赛题目表。每项必须包含比赛 ID、名称、`mappingKind: "official_contest_problem_table"`、精确官方比赛 `sourceUrl`、UTC `verifiedAt`、题目证据 `evidenceUrls` 和完整 `problemIndices`。该文件单独纳入版本管理，可追溯目录归属的依据和核对时间。

目前的补充项是 [QOJ 2603：BAPC 2025](https://qoj.ac/contest/2603) 的 A–L 完整题目表。其中 [14856：Boggle Sort](https://qoj.ac/problem/14856) 对应 B，[14863：Intermill Logistics](https://qoj.ac/problem/14863) 对应 I。两条提交详情中的题目链接均指向全局题目页，未显示比赛面包屑；这里采用官方比赛题目表确定 `QOJ/2603/b`、`QOJ/2603/i` 的**目录归属**，并不声称提交是在该比赛场次内完成的。

`archive_catalog.apply_contest_mappings(dashboard, submissions, catalog)` 只返回补充后的独立内存副本，不读写文件，不改变原始 dashboard 或历史中的 `contestId`。缺文件时传 `catalog=None`，结果与原规划兼容。新增目录的 `hasSubmissions` 从实际本人提交历史推导，含义是该官方题目表中有实际已提交题目；完整表本身不能触发归档。当前只有 B、I 有提交，因此不会为其余十道未提交题生成源码项。

补充模块追加缺失比赛，已有完全一致的题目表保持原样。若后续 qwq 已有该完整表但 `hasSubmissions` 为假，可依据本人真实历史仅在返回副本中把该标志提升为真，以保留已经证实的归档目录关联；不会把原有真值降级，也不表示赛内提交。它拒绝未知字段、非官方或不匹配的 URL、非法 ID／题号、重复题号，以及和现有 qwq 表或其他补充比赛产生的归属冲突。它不会覆盖既有映射，也不会为多场复用题猜测目录。新增内存比赛项的 `catalogSource` 保留来源文件、证据链接、核对时间和映射类型。

## 锁与中断恢复

修改仓库状态的操作通过 `.archive/process.lock` 串行执行，包括不同服务进程。锁文件可以一直存在，实际锁由操作系统维护；进程退出会释放锁。**中断后不要删除 `process.lock`、`pending-import.json` 或对应的源码临时文件。** 删除锁文件可能破坏进程间互斥，删除事务日志可能丢失恢复依据。

每次源码导入先持久保存 `.archive/pending-import.json`，再写入并验证临时源码，然后以不覆盖现有路径的方式发布，并保存来源收据。中断后运行 `status`、`plan`，或重新打开本地入口队列，会先自动恢复已有事务：完整且校验一致的数据补完发布或收据，不完整且尚未发布的临时数据由恢复流程清理。遇到目标内容、来源收据或事务指纹冲突时会保留现场并报错；不要手动删除日志来继续导入，应先核对冲突原因。

## 只读完整性审计

```sh
python3 scripts/archive_verify.py
```

`archive_verify.py` 只读取当前仓库内的清单、收据和源码，不执行归档源码、不联网、不写文件，也不会调用导入器或恢复待处理事务。可用 `--root /绝对路径/仓库` 指定要审计的仓库。

审计逐份核对 `archive/submissions.json` 中的安全路径、无符号链接、文件 SHA-256、字节数、UTF-8、LF、可选 `sourceLines` 和 `captureFormat`，并检查归档路径与平台提交 ID 的唯一性。若存在 `.archive/plan.json`，还会检查收据的比赛／题目 key、目标文件名及语言扩展名与规划一致。

收据元数据和路径先验证，再以每批最多 8 份源码并发读取，每份最多 2,000,000 字节。文件读取仍通过不跟随符号链接的目录描述符完成；源码内容不会积压在结果队列中，错误按收据顺序输出。

成功时退出码为 0，JSON 输出包含导入记录数、通过验证数、各平台数、未 AC 数和剩余缺口。剩余缺口使用已保存计划的题目范围与当前文件计算，不依赖旧计划的状态计数；未保存计划时该值为 `null`。任何完整性错误都会输出具体错误，并以非零退出码结束。该审计覆盖有导入收据的源码完整性，已有历史源码只参与剩余缺口判断。

## 离线测试

规划器拒绝路径穿越、非法段、符号链接父目录、不可信提交 URL 和非法语言标签。运行补充 catalog、规划器、导入器和只读验证器的全套单测：

```sh
python3 -m unittest discover -s scripts/tests -p 'test_archive_*.py'
```
