# 题库 API 与项目规范

[题目与代码](https://thelucius7.github.io/CompetitiveProgramming/) · [API 接入](api/index.md) · [代码规范](conventions.md)

## API 参考

题库提供公开、只读的 JSON 数据快照，包含题目路径、原题链接、源码地址、Git 提交日期、贡献日历与 Rating。

```http
GET https://thelucius7.github.io/CompetitiveProgramming/data/site-data.json
```

| 文档 | 内容 |
| --- | --- |
| [接入与契约](api/index.md) | 服务地址、调用边界与机器可读规范 |
| [数据快照](api/snapshot.md) | 请求、响应、示例与字段约束 |
| [数据模型](api/models.md) | 每个对象的必填项、类型、可空值与语义 |
| [源码与外部接口](api/dependencies.md) | GitHub、AtCoder、Codeforces 数据来源 |
| [错误与兼容规范](api/standards.md) | 状态码、失败处理、时间口径、版本管理与校验 |

## 项目规范

[项目结构](structure.md) · [源码清单](catalog.md) · [编译指南](quick-start.md) · [代码与归档](conventions.md) · [贡献流程](../CONTRIBUTING.md)

## 维护入口

文档源位于 `docs/project-guide`，推送该分支后自动构建并发布到当前地址，无需合并到 `main`。详见[文档部署](maintenance.md)。题库网站的维护见 [Pages 文档](pages.md)。
