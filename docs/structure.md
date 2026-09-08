# 项目结构

仓库采用单题文件归档，没有统一应用入口或包管理器。完整目录和数量见[目录清单](catalog.md)；这一页解释组织方式。

## 源码层

| 类型 | 位置与惯例 |
| --- | --- |
| AtCoder | [`AtCoder/`](../AtCoder/) 下按比赛分目录，如 `abc231/a.cpp`；比赛与题号通常小写 |
| Codeforces | [`Codeforces/`](../Codeforces/) 下按比赛编号分目录，如 `1000/E.cpp`；题号通常大写 |
| 独立题号 | [`Luogu/`](../Luogu/)、[`LOJ/`](../LOJ/)、[`Lanqiao/`](../Lanqiao/)、[`SPOJ/`](../SPOJ/) 多用平台题号 |
| CSES | [`CSES/`](../CSES/) 用题号加名称，如 `1068_Weird_Algorithm.cpp` |
| 比赛或自定义归档 | [`HDU/`](../HDU/)、[`L7OJ/`](../L7OJ/)、[`Mati/`](../Mati/)、[`NowCoder/`](../NowCoder/)、[`QOJ/`](../QOJ/)、[`SMQYOJ/`](../SMQYOJ/)、[`VJudge/`](../VJudge/)、[`ProjectEuler/`](../ProjectEuler/) 保留已有命名；不能仅凭目录数字认定原题编号 |
| 复用代码 | [`Templates/templates/`](../Templates/templates/) 存放算法片段和 CPH 起始模板 |
| 其他笔记 | [`Templates/templates all/`](../Templates/templates%20all/) 是历史笔记目录，不属于提交代码 |
| 未归档源码 | 根目录的独立 `.cpp`；具体文件见[清单](catalog.md)，不要猜测其 OJ 来源 |

目录区分来源，文件内容决定用途。比如 [`SPOJ/TEST.cpp`](../SPOJ/TEST.cpp) 是未实现骨架；不能因其位于 OJ 目录就标记为 AC。多个文件也可能是同一题的不同尝试，因此源码文件数不是独立题目数。

## 模板入口

| 类别 | 示例 |
| --- | --- |
| 并查集与区间数据结构 | [dsu.cpp](../Templates/templates/dsu.cpp)、[fenwick.cpp](../Templates/templates/fenwick.cpp)、[LazySegmentTree.cpp](../Templates/templates/LazySegmentTree.cpp)、[st.cpp](../Templates/templates/st.cpp) |
| 字符串 | [kmp.cpp](../Templates/templates/kmp.cpp)、[Z.cpp](../Templates/templates/Z.cpp)、[manacher.cpp](../Templates/templates/manacher.cpp)、[trie.cpp](../Templates/templates/trie.cpp) |
| 图与树 | [scc.cpp](../Templates/templates/scc.cpp)、[TwoSat.cpp](../Templates/templates/TwoSat.cpp)、[hld.cpp](../Templates/templates/hld.cpp)、[lca.cpp](../Templates/templates/lca.cpp) |
| 数学 | [comb.cpp](../Templates/templates/comb.cpp)、[exgcd.cpp](../Templates/templates/exgcd.cpp)、[sieve.cpp](../Templates/templates/sieve.cpp)、[BigInt.cpp](../Templates/templates/BigInt.cpp) |
| 新题骨架 | [cph.cpp](../Templates/templates/cph.cpp)；需要实现题目逻辑 |

这些是定位入口，不是统一 API 或正确性保证。复用前检查下标起点、边界、初始化、数值类型和依赖；模板可能没有 `main`，应放入最小调用程序验证。

## 工具与文档层

| 路径 | 职责 |
| --- | --- |
| [`.vscode/settings.json`](../.vscode/settings.json) | CPH 命名、来源映射和模板位置 |
| [`.vscode/tasks.json`](../.vscode/tasks.json) | 作者本机编译任务，包含仓库外命令 |
| [`.cph/scripts/`](../.cph/scripts/) | Competitive Companion relay 和 macOS 启动配置 |
| [`.gitignore`](../.gitignore) | 默认忽略、按需放行源码/文档/工具；样例与编译产物不提交 |
| [`docs/`](./) | 本套文档；`catalog.md` 为生成文件 |
| [`scripts/docs.py`](../scripts/docs.py) | 文档校验和源码清单生成，仅依赖 Python 标准库与 Git |
| [`scripts/README.md`](../scripts/README.md) | 归档规划、浏览器导入、QOJ 比赛映射、来源完整性审计与离线测试 |
| [`archive/submissions.json`](../archive/submissions.json)、[`archive/contest-mappings.json`](../archive/contest-mappings.json) | 已核实的源码来源收据与官方比赛题目表补充 |
| [`site/package.json`](../site/package.json)、[`site/package-lock.json`](../site/package-lock.json) | 文档站构建、API 校验依赖与固定版本 |
| [`site/.vitepress/config.mts`](../site/.vitepress/config.mts) | 文档导航、搜索、部署路径与主题配置 |
| [`site/public/api/`](../site/public/api/) | OpenAPI 与 JSON Schema，机器可读的规范源 |
| [`site/publish.mjs`](../site/publish.mjs) | 只更新 `gh-pages/docs/` 并验证公开发布 |
| [`.github/workflows/docs.yml`](../.github/workflows/docs.yml) | 文档检查、构建与自动部署；不依赖合入 main |
| [`.github/workflows/archive.yml`](../.github/workflows/archive.yml) | 每次 PR 和推送的离线归档测试与来源完整性审计 |

源分支还跟踪了少量历史 `.DS_Store`，详见清单。忽略规则不会自动移除已跟踪文件；后续清理应使用独立变更，不计入算法文件。

网站文件仅在 `gh-pages`，见[网站维护文档](pages.md)。网站收录规则与这里的全仓统计不同。
