# 文档导航

[在线文档](https://thelucius7.github.io/CompetitiveProgramming/docs/)按“API 接入、项目规范、维护”组织。路径与统计来自 Git，行为说明来自当前源码；新增规则适用于后续变更，不表示所有历史代码已经符合。

| 文档 | 回答的问题 |
| --- | --- |
| [API 接入](api/index.md) | 如何获取题库快照和机器可读规范？ |
| [数据模型](api/models.md) | 字段类型、可空性与校验要求是什么？ |
| [错误与兼容规范](api/standards.md) | 如何处理失败、未知数据与契约变更？ |
| [项目结构](structure.md) | 平台目录、模板、草稿、工具和网站分别在哪里？ |
| [目录清单](catalog.md) | 当前审计了哪个提交？各目录有多少源码？ |
| [快速开始](quick-start.md) | 如何选对编译器，编译并验证一道题？ |
| [代码与归档规范](conventions.md) | 路径、命名、注释、测试状态如何保持一致？ |
| [开发工具](tooling.md) | VS Code、CPH、Companion relay 如何迁移和启动？ |
| [贡献指南](../CONTRIBUTING.md) | 一次修改如何组织、检查和提交？ |
| [维护流程](maintenance.md) | 分支如何同步，文档如何更新、验证和发布？ |
| [GitHub Pages](pages.md) | 网站如何取数据、本地运行、发布和排障？ |

## 阅读与维护约定

先读目标任务对应的一篇；同一事实只在一个位置维护，其他文档链接过去。文件名使用小写英文，正文使用中文，命令使用可复制的完整步骤。生成内容只通过脚本更新，不手工修改数值。

`python3 scripts/docs.py check` 检查文档源的必需入口、相对链接、标题锚点、基础格式和目录清单一致性；`npm --prefix site run check:api` 校验机器契约与真实数据，`npm --prefix site run build` 构建网站。部署流程见[维护文档](maintenance.md)。

[返回仓库 README](../README.md)
