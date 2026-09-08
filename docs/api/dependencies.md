# 源码与外部接口

这些接口属于 GitHub、Codeforces 或第三方服务，不属于本站 API。访问限制和返回约定以对应服务为准。

## 源码文本

快照不包含源码正文。可以打开 `githubUrl` 查看 GitHub 文件，或读取 `rawUrl` 获取文本。程序化获取时也可使用 GitHub Contents API：

```sh
curl --fail --location \
  -H 'Accept: application/vnd.github.raw+json' \
  -H 'X-GitHub-Api-Version: 2022-11-28' \
  'https://api.github.com/repos/theLucius7/CompetitiveProgramming/contents/AtCoder/abc231/a.cpp?ref=main'
```

此请求返回原始文本，不能按默认 JSON / Base64 响应解析。文件路径应逐段 URL 编码，保留 `/` 分隔；源码仅用于阅读，不应在接入时自动执行。

当前题库网页先请求 Contents API，5 秒超时后并行尝试 jsDelivr 和 `rawUrl`，两路各 7 秒超时。成功文本保存在当前页面内存中，按路径索引；没有持久化缓存、TTL 或 SHA 完整性验证。完整实现边界见[网站维护](../pages.md)。

## 数据依赖

| 来源 | 请求 | 用途 |
| --- | --- | --- |
| GitHub 文件树 | `GET https://api.github.com/repos/theLucius7/CompetitiveProgramming/git/trees/main?recursive=1` | 在线题目路径；大仓库需检查 `truncated` |
| GitHub 提交活动 | `GET https://api.github.com/repos/theLucius7/CompetitiveProgramming/stats/commit_activity` | 仓库统计日历；可能先返回 `202` |
| AtCoder 历史代理 | `GET https://kenkoooo.com/atcoder/proxy/users/Lucius7/history/json` | 第三方代理的 rated 历史；不是本站或 AtCoder 官方 API |
| Codeforces 用户 | `GET https://codeforces.com/api/user.info?handles=Lucius7` | 要求业务状态 `OK`；读取 `rating`、`maxRating`、`rank` |

AtCoder 使用有效 rated 记录中的最新值、最高值和场次数；Codeforces 使用用户对象。整个平台不可用与用户没有 Rating 记录不是同一状态，见[数据模型](models.md)。

## 请求限制

GitHub REST API 有匿名与认证请求限制，遇到限额时读取实际的限流响应头，遵循服务返回的重试要求。不要在公开静态页面内嵌个人访问令牌，也不要用并发重试绕过限制。[GitHub 官方限流说明](https://docs.github.com/en/rest/using-the-rest-api/rate-limits-for-the-rest-api)

外部调用失败时，接入者应保留已验证的数据并显示更新时间；不要把“请求失败”改写成“当天没有提交”或“Rating 为零”。
