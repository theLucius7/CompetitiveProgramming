# 贡献指南

先阅读[组织贡献规范](https://github.com/xw7qwq/.github/blob/main/CONTRIBUTING.md)，再按本仓库的分支职责和验证要求提交改动。详细的[代码与归档规范](https://github.com/xw7qwq/codeflare/blob/docs/project-guide/docs/conventions.md)与[维护流程](https://github.com/xw7qwq/codeflare/blob/docs/project-guide/docs/maintenance.md)位于文档源分支。

## 分支和 Pull Request

| 目标分支 | 内容 |
| --- | --- |
| `main` | 算法源码、模板、来源收据与归档工具 |
| `docs/project-guide` | 项目文档、API 契约与文档站源码 |
| `gh-pages` | 题库网站源码、数据快照和生成的 `docs/` 网站 |

从对应目标创建短期工作分支，例如 `fix/archive-import`、`docs/update-tooling` 或 `sync/contest-submissions`。完成验证后向该目标发起 PR，说明改动原因和实际检查结果；检查通过后合并，确认来源提交已被目标包含再删除工作分支。保留三个长期分支，不把网站分支整体合入算法分支。

归档脚本只处理本地文件，不提交或推送 Git；新增提交来源与源码也应通过工作分支和 PR 合入 `main`。文档发布工作流会直接更新 `gh-pages/docs/`，该目录是生成结果，不能手工修改。文档和网站的人工变更同样通过 PR。

## 提交前验证

在仓库根目录运行：

```sh
python3 -m unittest discover -s scripts/tests -p 'test_archive_*.py'
python3 scripts/archive_verify.py
git diff --check
```

`Archive` 工作流在 `main`、`docs/project-guide` 的每次 PR 和推送执行离线测试与只读完整性审计，稳定检查名为 `archive`。审计核对已导入源码的来源收据、哈希、字节数与编码，不执行算法，也不证明算法 AC。

单题修改需要单独编译并提供原题链接、复现输入和预期输出；模板修改应提供最小调用与边界验证。文档和网站的附加检查见各自分支 README。保留源码原有路径和已核实的来源，不把编译成功或文件存在写成评测通过。

## 提交规范

采用 `类型(范围): 具体动作`，例如 `fix(archive): validate submission identity` 或 `docs(tooling): explain local setup`。按路径暂存并审阅差异；不提交编译产物、本地样例、临时缓存或登录凭据，不做无关的批量重命名和格式化。引用第三方材料时保留来源和许可；仓库没有统一许可证，不能自动为历史内容补写授权。
