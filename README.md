# CompetitiveProgramming

theLucius7 的算法竞赛源码、模板与练习归档，以 C++ 为主，按 OJ 和比赛组织。

[在线文档 / API 参考](https://thelucius7.github.io/CompetitiveProgramming/docs/) · [在线题库](https://thelucius7.github.io/CompetitiveProgramming/) · [目录清单](docs/catalog.md) · [贡献指南](CONTRIBUTING.md)

## 从这里开始

| 需要做什么 | 入口 |
| --- | --- |
| 接入题库数据、查阅字段与错误规范 | [API 参考](docs/api/index.md)、[在线文档](https://thelucius7.github.io/CompetitiveProgramming/docs/) |
| 查找题目、查看代码和提交日期 | [在线题库](https://thelucius7.github.io/CompetitiveProgramming/) |
| 了解所有平台、模板和工具的位置 | [项目结构](docs/structure.md)、[自动生成的目录清单](docs/catalog.md) |
| 在本地编译一道题 | [快速开始](docs/quick-start.md) |
| 添加题解、记录验证结果 | [代码与归档规范](docs/conventions.md)、[贡献指南](CONTRIBUTING.md) |
| 配置编辑器和题目导入 | [开发工具](docs/tooling.md) |
| 更新文档或维护网站 | [维护流程](docs/maintenance.md)、[GitHub Pages](docs/pages.md) |

## 分支

| 分支 | 内容 |
| --- | --- |
| [`main`](https://github.com/theLucius7/CompetitiveProgramming/tree/main) | 算法源码、模板和已有开发工具 |
| [`docs/project-guide`](https://github.com/theLucius7/CompetitiveProgramming/tree/docs/project-guide) | 文档站源码、API 契约、项目规范与构建检查；推送后自动发布 |
| [`gh-pages`](https://github.com/theLucius7/CompetitiveProgramming/tree/gh-pages) | 题库网站、数据快照和生成的 `docs/` 文档网站 |

文档无需合并到 `main`。推送 `docs/project-guide` 后，工作流构建文档并仅更新 `gh-pages/docs/`。源码清单记录所依据的主分支提交；刷新与部署方法见[维护流程](docs/maintenance.md)。

## 本地查看

```sh
git clone --branch docs/project-guide https://github.com/theLucius7/CompetitiveProgramming.git
cd CompetitiveProgramming
python3 scripts/docs.py check
```

文档可直接在 GitHub 或 Markdown 阅读器中浏览，无需启动网站或安装 Python 包。检查脚本需要 Git 和 Python 3.10+；单题编译需要对应语言的工具链，见[快速开始](docs/quick-start.md)。

本地运行文档网站需要 Node.js 22+：

```sh
npm --prefix site ci
npm --prefix site run dev
```

预览地址为 `http://127.0.0.1:4174/CompetitiveProgramming/docs/`。OpenAPI 和 JSON Schema 下载入口位于 [API 文档](docs/api/index.md)。

## 内容说明

每份源码独立使用，没有全仓统一可执行程序。仓库包含未完成草稿和不带 `main` 的模板片段；文件存在、提交到 Git 或网页可见，都不代表已经通过 OJ。数量口径和记录基线见[目录清单](docs/catalog.md)。

原题以对应 OJ 页面为准。仓库目前未声明统一的开源许可证，本文档未新增授权条款。

## 账号

[AtCoder](https://atcoder.jp/users/Lucius7) · [Codeforces](https://codeforces.com/profile/Lucius7) · [X](https://x.com/theLucius7) · [博客](https://blog.lucius7.cn) · [GitHub](https://github.com/theLucius7)
