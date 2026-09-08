# CodeFlare

Lucius7 的算法竞赛源码、模板与练习归档。以 C++ 为主，按 Online Judge（OJ）和比赛组织，配套静态网站提供源码检索与阅读。

[访问网站](https://codeflare.lucius7.dev) · [算法模板](Templates/templates) · [归档工具](scripts/README.md) · [问题反馈](https://github.com/xw7qwq/codeflare/issues) · [OJFlare](https://ojflare.lucius7.dev)

## 项目内容

- **题目源码**：按平台、比赛和题号保存独立程序，覆盖 AtCoder、Codeforces、QOJ、洛谷、CSES 等 OJ。
- **算法模板**：整理数据结构、图论、字符串和数论等常用实现，位于 [`Templates/templates/`](Templates/templates)。
- **在线阅读**：网站支持按平台、比赛和关键词筛选源码，以及语法高亮、行号、复制与原始文件链接。
- **可追溯归档**：归档工具验证提交身份和源码完整性，并保存提交来源、结果、文件大小和 SHA-256。

这是个人学习与竞赛记录。仓库包含未完成草稿、未 AC 提交和不带 `main` 的模板片段；文件存在不代表已经通过评测，每份程序应按原题单独验证。

## 快速开始

仅浏览源码无需安装依赖；运行 C++ 程序需要 GNU G++，归档工具需要 macOS 或 Linux、Python 3.10+ 和 Git。各题使用的语言特性可能不同，编译标准应以具体源码为准。

```sh
git clone https://github.com/xw7qwq/codeflare.git
cd codeflare
```

例如编译并运行一份独立的 C++ 程序：

```sh
g++ -std=gnu++17 -O2 -Wall -Wextra AtCoder/abc052/b.cpp -o /tmp/codeflare-abc052-b
/tmp/codeflare-abc052-b <<'EOF'
5
IIDID
EOF
```

预期输出为 `2`。此示例使用 GNU 标准库头文件 `bits/stdc++.h`；macOS 自带的 `g++` 通常是 Apple Clang，请将命令中的 `g++` 替换为本机安装的 GNU G++ 可执行文件。

仓库没有统一的应用入口或全仓构建命令。运行其他题目时，替换源码路径，并使用对应 OJ 的输入与输出进行核对。

## 仓库结构

| 路径 | 内容 |
| --- | --- |
| [`AtCoder/`](AtCoder)、[`Codeforces/`](Codeforces)、[`QOJ/`](QOJ) | 按比赛目录组织的源码，例如 `AtCoder/abc052/b.cpp` |
| [`Luogu/`](Luogu)、[`CSES/`](CSES)、[`NowCoder/`](NowCoder) 等 | 其他 OJ 的题目与练习，保留原有目录形式 |
| [`Templates/`](Templates) | 算法模板与片段 |
| [`archive/submissions.json`](archive/submissions.json) | 经导入工具验证的提交来源与源码校验信息 |
| [`archive/contest-mappings.json`](archive/contest-mappings.json) | 根据官方题目表核对的补充比赛映射 |
| [`scripts/`](scripts) | 归档规划、导入、完整性审计及离线测试 |
| [`.cph/scripts/`](.cph/scripts) | Competitive Companion / CPH 辅助脚本 |
| [`.vscode/`](.vscode) | 作者使用的 VS Code 和 CPH 配置 |

VS Code 配置中包含作者机器上的绝对路径和编译器设置。使用前请按本机目录、编译器和平台修改；命令行编译无需依赖这些编辑器配置。

## 源码归档与验证

归档器面向账号 `Lucius7` 的 AtCoder、Codeforces 和 QOJ 提交。同一题优先选取最新 AC，没有 AC 时选取最新尝试；不会覆盖已有源码。候选规划、正常浏览器导入、QOJ 历史补充及中断恢复的完整操作见[归档工具说明](scripts/README.md)。

在仓库根目录执行只读完整性审计：

```sh
python3 scripts/archive_verify.py
```

此命令检查来源收据对应文件的路径、哈希、字节数和编码，不联网、不执行题目源码。它验证已导入文件的完整性，不验证算法正确性，也不为历史文件补写来源记录。

修改归档工具后，运行现有离线测试：

```sh
python3 -m unittest discover -s scripts/tests -p 'test_archive_*.py'
```

## 网站与文档维护

各分支职责不同，修改前请先选择对应分支：

| 分支 | 内容与入口 |
| --- | --- |
| [`main`](https://github.com/xw7qwq/codeflare/tree/main) | 本 README、算法源码、模板及归档工具 |
| [`gh-pages`](https://github.com/xw7qwq/codeflare/tree/gh-pages) | 题库网站、源码阅读器、数据快照与生成的文档；[网站维护说明](https://github.com/xw7qwq/codeflare/blob/gh-pages/README.md) |
| [`docs/project-guide`](https://github.com/xw7qwq/codeflare/tree/docs/project-guide) | 文档站源码、API 契约与项目规范；[文档维护说明](https://github.com/xw7qwq/codeflare/blob/docs/project-guide/README.md) |

网站地址为 **[codeflare.lucius7.dev](https://codeflare.lucius7.dev)**。GitHub Pages 从 `gh-pages` 根目录发布；该分支中的 `docs/` 是生成结果，文档内容应在 `docs/project-guide` 修改。网站与文档的本地预览、构建和校验命令见各分支 README。

## 贡献与反馈

欢迎通过 [Issue](https://github.com/xw7qwq/codeflare/issues) 或 Pull Request 反馈源码问题、目录映射错误及文档改进。

1. 说明涉及的文件、原题链接和问题现象；算法修正请附复现输入、预期输出及验证结果。
2. 保持现有平台、比赛和题号目录约定。模板与完整题目程序分别存放，避免无关的批量重命名或格式化。
3. 归档来源记录由工具生成，不能把未核实的结果标记为 AC。使用导入流程时遵循[归档工具说明](scripts/README.md)。
4. 提交前检查差异；不提交编译产物、本地样例、临时缓存或登录凭据。工具变更应运行上方离线测试。

更详细的[代码与归档规范](https://github.com/xw7qwq/codeflare/blob/docs/project-guide/docs/conventions.md)和[贡献指南](https://github.com/xw7qwq/codeflare/blob/docs/project-guide/CONTRIBUTING.md)位于文档分支。

## 相关项目

| 项目 | 用途 | 网站 |
| --- | --- | --- |
| [CodeFlare](https://github.com/xw7qwq/codeflare) | 算法源码、模板归档与在线阅读 | [codeflare.lucius7.dev](https://codeflare.lucius7.dev) |
| [OJFlare](https://github.com/xw7qwq/ojflare) | 多平台提交记录、比赛目录与个人刷题统计 | [ojflare.lucius7.dev](https://ojflare.lucius7.dev) |

## 许可证

仓库目前未声明统一的开源许可证。原题与第三方材料的权利归各自权利人所有；如需再分发或用于其他项目，请先确认相应授权。
