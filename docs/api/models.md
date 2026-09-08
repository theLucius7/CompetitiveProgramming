# 数据模型

[下载完整 JSON Schema](../../site/public/api/site-data.schema.json)。下列字段表在文档构建时直接从同一 schema 生成，避免手工维护两套定义。

<!-- API_MODELS -->

<!-- UPDATES_MODELS -->

## 业务约束

除结构校验外，发布检查要求：

- 每个 `path` 唯一，必须是安全的仓库相对路径，第一段与 `platform` 一致。
- 文件扩展名与 `language` 一致；`githubUrl` 和 `rawUrl` 与仓库配置及逐段编码后的路径一致。
- `contributions` 是真实日期到正整数的字典，计数合计必须等于 `commitCount`。
- 非空 Rating 使用非负整数；最高值不得低于当前值。此处是契约门禁，网页运行时没有完整执行这些检查。

- 最近提交最多六条，完整 SHA 唯一；URL 必须与仓库及 SHA 精确匹配。其顺序来自 Git 历史，不要求时间戳递减。

日历和 Rating 是保留的兼容数据，当前首页不展示，Rating 不再主动刷新；`generatedAt` 不表示 Rating 的更新时间。

允许 `submittedAt` 未知，允许平台 Rating 为 `null`。不要求响应预排序，不锁定题目数量，不要求 `sourceRef` 与链接分支相同，也不把 Git 时钟误差作为算法错误。
