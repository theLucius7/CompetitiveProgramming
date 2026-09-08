# 接入与契约

## 服务地址

```text
https://codeflare.lucius7.dev
```

| 方法 | 路径 | 说明 |
| --- | --- | --- |
| `GET` | `/data/site-data.json` | 完整题库部署快照；[请求与响应](snapshot.md) |
| `GET` | `/data/recent-commits.json` | main 最近六次提交；[请求与响应](updates.md) |

接口公开只读，不需要登录或密钥。快照是静态文件，没有服务端分页、搜索参数、写入接口或统一错误 JSON；题库页面中的检索、排序和每次显示 60 条均在浏览器执行。

## 机器可读规范

[OpenAPI 3.1 规范](../../site/public/api/openapi.json) · [题库 Schema](../../site/public/api/site-data.schema.json) · [最近提交 Schema](../../site/public/api/recent-commits.schema.json)

API 集合契约版本为 `2.0.0`，记录于上述规范文件。本版使用 CodeFlare 独立域名和新仓库标识，字段结构不变，旧固定值校验器需要更新；详见[迁移与兼容说明](standards.md#兼容与变更)。响应本身当前没有 `schemaVersion` 字段，也没有 `/v1` 路径。机器可读规范描述现有数据，而非承诺不存在的后端功能。

所有模型明确区分必填和可空；对象不允许未声明字段，除贡献日历的动态日期键。发布文档前，自动检查会用该契约验证真实部署快照，防止文档与数据结构分离。

## 最小调用

```sh
curl --fail --location \
  'https://codeflare.lucius7.dev/data/site-data.json'
```

```js
const response = await fetch(
  'https://codeflare.lucius7.dev/data/site-data.json',
  { signal: AbortSignal.timeout(10000) },
);
if (!response.ok) throw new Error(`HTTP ${response.status}`);
const snapshot = await response.json();
console.log(snapshot.generatedAt, snapshot.problems[0].githubUrl);
```

JavaScript 示例需要支持 `fetch` 和 `AbortSignal.timeout` 的运行时。先检查 HTTP 状态，再解析并验证数据；严格校验命令见[规范](standards.md)。

## 数据新鲜度

`generatedAt` 是 JSON 的生成时刻，不代表每道题最近修改时刻。`submittedAt` 是生成时从 Git 历史取得的时间，可能为 `null`，也不是 OJ 评测时间。源码正文需通过源码地址单独加载，不包含在快照中。

旧版非 ASCII 路径漏收已修复，历史说明见[题库维护文档](../pages.md)。

题库快照中的 `commitCount`、`contributions`、`ratings` 为兼容旧接入而保留；首页不再展示这些统计。Rating 不再主动刷新，`generatedAt` 不能用于判断它的新鲜度。接入者应区分快照、外部实时接口与 OJ 原站的更新时机。
