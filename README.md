# CodeFlare · 项目文档

CodeFlare 是以 C++ 为主的算法竞赛源码、模板与练习归档，按 OJ 和比赛组织。本分支 `docs/project-guide` 维护项目指南、静态题库的 API 契约与 VitePress 文档站。

[项目网站](https://codeflare.lucius7.dev) · [在线文档](https://codeflare.lucius7.dev/docs/) · [源码仓库](https://github.com/xw7qwq/codeflare) · [目录清单](docs/catalog.md) · [贡献指南](CONTRIBUTING.md)

## 文档导航

| 需要做什么 | 入口 |
| --- | --- |
| 接入题库数据、查阅字段与错误规范 | [API 参考](docs/api/index.md) |
| 了解所有平台、模板和工具的位置 | [项目结构](docs/structure.md)、[自动生成的目录清单](docs/catalog.md) |
| 在本地编译一道题 | [快速开始](docs/quick-start.md) |
| 添加题解、记录验证结果 | [代码与归档规范](docs/conventions.md)、[贡献指南](CONTRIBUTING.md) |
| 配置编辑器和题目导入 | [开发工具](docs/tooling.md) |
| 更新文档或维护网站 | [维护流程](docs/maintenance.md)、[GitHub Pages 维护](docs/pages.md) |
| 浏览全部文档主题 | [文档导航](docs/README.md) |

API 文档描述静态 JSON 快照及网站依赖的外部接口，不是在线评测服务。OpenAPI 和 JSON Schema 的下载入口位于 [API 参考](docs/api/index.md)。

## 分支职责

| 分支 | 内容 |
| --- | --- |
| [`main`](https://github.com/xw7qwq/codeflare/tree/main) | 算法源码、模板和已有开发工具 |
| [`docs/project-guide`](https://github.com/xw7qwq/codeflare/tree/docs/project-guide) | 本分支：文档源、API 契约、项目规范和构建检查 |
| [`gh-pages`](https://github.com/xw7qwq/codeflare/tree/gh-pages) | 题库网站、数据快照和生成的 `docs/` 文档网站 |

文档无需合并到 `main`。推送本分支后，工作流构建文档并仅更新 `gh-pages/docs/`。源码清单记录所依据的主分支提交，刷新方法见[维护流程](docs/maintenance.md)。

## 快速开始

### 阅读与检查 Markdown

直接在 GitHub 或 Markdown 阅读器中浏览文档，无需运行网站。检查脚本需要 Git 和 Python 3.10+，不依赖第三方 Python 包。

```sh
git clone --branch docs/project-guide https://github.com/xw7qwq/codeflare.git codeflare-docs
cd codeflare-docs
python3 scripts/docs.py check
```

请保留完整 Git 历史与远程分支引用，清单校验和 API 检查会读取指定提交及 `origin/gh-pages`。单题编译需要对应语言的工具链，见[快速开始](docs/quick-start.md)。

### 预览文档网站

在仓库根目录执行，需要 Node.js 22+ 和 npm：

```sh
npm --prefix site ci
npm --prefix site run dev
```

打开 <http://127.0.0.1:4174/docs/>，按 `Ctrl+C` 停止服务。

开发服务器启动时会将 Markdown 转换到 `site/.content/`。编辑源文档后，可在另一个终端运行 `npm --prefix site run prepare:docs` 重新生成页面内容。

## 项目结构

| 路径 | 用途 |
| --- | --- |
| [README.md](README.md)、[CONTRIBUTING.md](CONTRIBUTING.md) | 项目入口与贡献约定 |
| [docs/](docs/) | 指南、API 说明与源码目录清单 |
| [scripts/docs.py](scripts/docs.py) | Markdown、相对链接、标题锚点和源码清单检查 |
| [site/package.json](site/package.json) | 文档站依赖、开发与构建命令 |
| [site/.vitepress/](site/.vitepress/) | 站点配置和主题 |
| [site/public/api/](site/public/api/) | OpenAPI 与 JSON Schema 契约 |
| [site/prepare.mjs](site/prepare.mjs)、[site/check-build.mjs](site/check-build.mjs) | 内容转换与构建产物检查 |
| [site/publish.mjs](site/publish.mjs) | 文档产物发布与上线验证 |
| [.github/workflows/docs.yml](.github/workflows/docs.yml) | 文档校验、构建与发布工作流 |

`site/.content/`、`site/.vitepress/dist/` 和 `site/node_modules/` 是生成目录；修改 Markdown 源文件与配置，不提交生成目录。算法源码的分类与数量以[项目结构](docs/structure.md)和[目录清单](docs/catalog.md)为准。

## 验证与贡献

安装文档站依赖后，在仓库根目录运行：

```sh
python3 scripts/docs.py check
npm --prefix site run check:api
npm --prefix site run build
git diff --check
```

上述命令分别校验文档与清单、API 契约及快照、静态站点构建和空白格式。API 检查默认读取本地 `origin/gh-pages` 中的两份数据快照；这些检查不评测算法，也不证明远端网站已经部署成功。

从 `docs/project-guide` 创建文档工作分支，按路径提交修改，并在 Pull Request 中说明原因、变更与验证结果。新增 Markdown 或链接目标需先纳入 Git 跟踪。完整要求见[贡献指南](CONTRIBUTING.md)。

## 域名与部署

CodeFlare 使用独立域名 **[codeflare.lucius7.dev](https://codeflare.lucius7.dev)**，文档站发布到 [/docs/](https://codeflare.lucius7.dev/docs/)，静态 API 位于 `/data/`。

GitHub Pages 的发布来源应为 `gh-pages` 分支根目录，自定义域名设置为 `codeflare.lucius7.dev`。文档发布脚本会核验目标仓库、来源分支与域名，只更新受管理的 `docs/` 目录，保留题库和域名配置。

API 集合 `2.0.0` 使用新域名与 `xw7qwq/codeflare` 仓库标识，响应字段结构保持不变。迁移和兼容范围见[错误与兼容规范](docs/api/standards.md)。源码清单仍保留原提交 SHA、时间与统计口径。

工作流在 `docs/**` 分支推送或符合路径条件的 Pull Request 中运行检查；发布作业仅针对 `docs/project-guide` 的推送。以 [Actions](https://github.com/xw7qwq/codeflare/actions)、公开页面和 `docs/build-info.json` 核对发布结果，详细流程见[维护文档](docs/maintenance.md)。

## 内容与许可

每份算法源码独立使用，没有全仓统一可执行程序。归档包含未完成草稿和不带 `main` 的模板片段；文件存在、提交到 Git 或网页可见，都不代表已通过 OJ。原题以对应 OJ 页面为准。

仓库目前未声明统一的开源许可证。引用题面、第三方代码或依赖时，保留其来源并遵守各自许可；本文档不新增授权条款。

## 相关项目

[OJFlare](https://github.com/xw7qwq/ojflare) 使用独立域名 [ojflare.lucius7.dev](https://ojflare.lucius7.dev)，与 CodeFlare 分别维护和部署。
