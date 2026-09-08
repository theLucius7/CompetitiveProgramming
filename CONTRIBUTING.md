# 贡献指南

先阅读[组织贡献规范](https://github.com/xw7qwq/.github/blob/main/CONTRIBUTING.md)。修改前先确定目标分支：算法代码以 `main` 为基线，文档以 `docs/project-guide` 为基线，网站以 `gh-pages` 为基线。分支职责和同步见[维护流程](docs/maintenance.md)。

## 一次变更

1. 检查 `git status --short --branch`，保留已有未提交工作。
2. 从对应基线建立描述清楚的工作分支，例如 `fix/cf-1000-e` 或 `docs/update-tooling`。
3. 按[代码与归档规范](docs/conventions.md)修改，尽量让一次提交只承担一个目的。
4. 新文件按路径纳入 Git 跟踪，完成下表中与修改相关的检查，再查看暂存差异。
5. 明确说明改动原因和验证范围，推送工作分支后向对应目标发起 PR，检查通过后合并。
6. 确认来源提交已包含于目标分支后删除短期工作分支；保留 `main`、`docs/project-guide`、`gh-pages` 三个长期分支。

| 修改类型 | 提交前证据 |
| --- | --- |
| 单题算法 | 单独编译，列出样例/边界/反例结果；AC 需要 OJ 记录 |
| 模板 | 最小调用程序和边界验证，说明接口是否变化 |
| 重命名或移动 | 来源映射可追踪，CPH 路径规则与 Pages 收录规则核对 |
| 归档工具或导入源码 | 离线归档测试与只读来源审计，见下方命令 |
| 文档 | 文档检查、API 契约检查与构建，见[维护流程](docs/maintenance.md) |
| 网站 | 按[网站维护](docs/pages.md)验证资源、快照和相关交互 |

代码分支暂未包含文档检查脚本时，只运行该分支可用的相关检查；需要更新文档时在文档分支进行同步。归档测试和完整性审计在仓库根目录执行：

```sh
python3 -m unittest discover -s scripts/tests -p 'test_archive_*.py'
python3 scripts/archive_verify.py
```

`archive` 检查核对工具行为与有来源收据的源码完整性，不执行算法，也不证明算法 AC。归档工具只读写本地文件，不自动提交或推送 Git；新增源码通过 `sync/` 等短期分支的 PR 合入 `main`，不覆盖既有源码。操作与来源收据格式见[归档工具说明](scripts/README.md)。

人工修改都通过 PR；文档发布工作流仍直接更新 `gh-pages/docs/`。这是生成目录，不能手工修改，也不把 `gh-pages` 整体合入其他分支。

## 提交信息

采用 `类型(范围): 具体动作`，例如：

```text
fix(codeforces): handle disconnected graph in 1000E
feat(atcoder): add abc231 A solution
docs(tooling): explain local relay configuration
refactor(layout): move verified source paths
```

常用类型为 `feat`、`fix`、`refactor`、`docs`、`chore`。正文补充必要的动机、来源和测试结果，不把“编译成功”写成“全部通过”。

按文件暂存并审阅，以下是仅修改 README 的例子：

```sh
git add README.md
git diff --cached --check
git diff --cached
git commit -m "docs(readme): clarify repository navigation"
```

## 评审说明

使用下面的信息即可，不必为简单修改填写长篇报告：

```text
原因：原有行为或缺失信息。
变更：修改的文件与结果。
验证：实际运行的命令、样例及其结果。
限制：尚未验证的范围；若无则省略。
```

讨论算法时提供题目链接、最小反例和预期输出。涉及第三方代码时保留来源及适用许可；本仓库目前未声明统一许可证，不自动为已有代码添加授权。
