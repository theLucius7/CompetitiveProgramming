# 维护流程

## 分支职责

`main` 保存算法档案，`docs/project-guide` 保存文档站源码及其源码基线，`gh-pages` 保存题库网站与 `docs/` 文档构建产物。文档发布不需要把文档分支合并到 `main`。每次从对应分支创建工作分支；同一个分支的变更先完成验证，再推送或评审。[GitHub flow](https://docs.github.com/en/get-started/using-github/github-flow) 是这一流程的参考。

文档分支可合入新的 `main` 来更新来源；这是更新源码清单的可选维护步骤，不是部署前提。文档变更直接推送文档分支后，由工作流更新 `gh-pages/docs/`。题库根网站仍按[Pages 维护](pages.md)操作。

## 文档站预览与部署

在线地址：[CompetitiveProgramming Docs](https://thelucius7.github.io/CompetitiveProgramming/docs/)。使用 VitePress，默认入口就是 API 与项目规范；全文搜索、导航、代码高亮和深色模式在站点内提供。

从仓库根目录执行，需要 Node.js 22+：

```sh
npm --prefix site ci
npm --prefix site run dev
```

开发服务器地址为 `http://127.0.0.1:4174/CompetitiveProgramming/docs/`。Markdown 的唯一维护源是 `docs/` 和根 README / CONTRIBUTING；运行中的内容重新生成命令为 `npm --prefix site run prepare:docs`，随后浏览器更新。结束服务器用 `Ctrl+C`。

发布前执行：

```sh
python3 scripts/docs.py check
npm --prefix site run check:api
npm --prefix site run build
git diff --check
```

将检查过的文档、配置和锁文件提交并 `git push origin docs/project-guide` 即开始发布，无需再向 `main` 推送。`site/.content/`、`site/.vitepress/dist/` 和 `node_modules` 是生成目录，不提交。已安装依赖中的 Vite 使用锁定的修复版本；更新依赖时保留 `package-lock.json` 并重新检查和构建。

发布工作流先校验 Markdown、OpenAPI、JSON Schema 和真实快照，再构建静态网站。模型字段表直接来自 schema；源码链接会转换为 GitHub 链接，避免部署后指向不存在的本地目录。

只有 `docs/project-guide` 的推送会发布。发布 job 下载已验证产物，确认仍对应文档分支最新提交，再只替换带管理标记的 `gh-pages/docs/`；过期运行安全跳过。检查暂存路径范围后普通推送，随后显式请求 Pages 构建，并核对公开的 `docs/build-info.json` 与页面响应。PR 和其他文档分支只做检查与构建。任一步失败时查看 [Actions](https://github.com/theLucius7/CompetitiveProgramming/actions)，不能将“已经 push”当成部署成功。

需要回滚时，在文档源分支对造成问题的提交执行明确的 `git revert <提交SHA>`，验证后重新推送。不要手改生成的 `gh-pages/docs/`，否则下一次构建会覆盖手工内容。

## 更新文档与源码清单

在完整克隆的仓库根目录执行，先处理自己的未提交工作：

```sh
git status --short --branch
git fetch origin
git switch docs/project-guide
git merge --ff-only origin/docs/project-guide
git merge origin/main
python3 scripts/docs.py generate --ref origin/main
python3 scripts/docs.py check
git diff --check
git diff --stat
```

如果尚无本地文档分支，使用 `git switch --track origin/docs/project-guide` 创建；如果出现冲突，逐项审阅再继续，不用整批覆盖方式丢弃原有修改。合入主分支后，还要人工核对目录习惯、工具行为和网站兼容性：生成统计不能代替这些检查。

`generate` 只写 `docs/catalog.md`。它解析 Git 的 NUL 分隔路径，保留中文、空格等文件名；记录完整源提交 SHA 和提交时间，不使用机器当前日期。统计内容是所选提交中的源码与其他跟踪文件，不是工作目录里的未提交文件。

更新说明与生成清单一起提交：

```sh
git add docs/catalog.md
# 若还有人工文档修改，逐项加入相应路径。
git diff --cached --check
git diff --cached
git commit -m "docs(catalog): refresh source inventory"
git push origin docs/project-guide
```

清单未变化且没有文档改动时，不需要空提交。如果站点也依赖此次源码变化，另在 `gh-pages` 更新网站快照。

## 本地检查与 CI

```sh
python3 scripts/docs.py check
git diff --check
```

检查脚本仅使用 Git 和 Python 3.10+ 标准库。它读取本套文档，校验必需文档、一个一级标题、基础空白格式、代码围栏、仓库内相对链接与 Markdown 标题锚点；并根据清单记录的提交重算目录，检查当前检出源码路径与基线是否一致。新增文档和本地链接目标需先通过 `git add <路径>` 纳入跟踪；只存在于本机的文件不算可发布的链接目标。

检查范围是根 `README.md`、`CONTRIBUTING.md` 和 `docs/` 中所有 Markdown，不强制重写历史笔记。脚本不访问网络、不运行算法、不检查每个外站链接或 OJ 评测结果，也不证明所有命令在所有系统可用。它支持本套文档使用的行内链接和 ATX 标题，不是通用 Markdown 渲染器。

[文档工作流](../.github/workflows/docs.yml) 在 `docs/**` 分支推送和相关路径的 PR 中运行校验与构建；校验 job 为只读，独立发布 job 使用 `contents: write` 与 `pages: write` 更新文档产物并请求 Pages 构建。工作流编写方式参考 [GitHub Actions 官方文档](https://docs.github.com/en/actions/get-started/quickstart)。

失败时先看输出路径和原因：

| 失败 | 修复方式 |
| --- | --- |
| 缺少相对链接目标 | 检查大小写、编码、分支和是否忘记跟踪新文件 |
| 标题锚点失效 | 同步修改标题与引用，保持导航可达 |
| 清单与源提交不一致 | 不手改生成区；按上面的命令重新生成 |
| 当前源码路径与基线不同 | 先同步 `main` 并审阅变更，再以 `origin/main` 生成清单 |
| 缺少清单所指提交 | 完整克隆；浅克隆先 `git fetch --unshallow origin`，普通克隆先 `git fetch origin` |
| 配置未被 Git 识别 | 使用 `git check-ignore -v <路径>`，按需更新精确白名单 |

## 文档质量约定

新增说明写入最贴近任务的一篇，并在[文档导航](README.md)中增加入口。事实要有代码、配置、命令结果或官方资料作为依据；有日期的审计记录与实时状态分开。短示例给出执行目录、依赖和预期结果，不把伪代码写成已验证命令。

统计只维护在自动清单；描述来源时使用固定提交，链接到最新内容时明确其会变化。涉及分支策略、题目命名、数据口径或工具行为的修改，更新对应规范与验证记录。
