# 开发工具

单题编译不依赖编辑器插件；可先按[快速开始](quick-start.md)确认编译器。以下工具是当前仓库已有的可选工作流。

## VS Code / CPH

[settings.json](../.vscode/settings.json) 定义默认语言、模板位置、保存目录、文件名模板和 OJ URL 映射。迁移到其他机器时，先检查这些设置：

| 设置 | 需要适配的内容 |
| --- | --- |
| `cph.general.defaultLanguageTemplateFileLocation` | 本机仓库内 `Templates/templates/cph.cpp` 的绝对路径 |
| `cph.general.saveLocation` | 本机仓库 `.cph` 的绝对路径 |
| `cph.general.fileNameTemplate` / `fileNameTemplateOverrides` | 目标 OJ 的目录与题号规则 |
| `cph.general.ojMapping` | URL 正则和来源名称；与 relay 的规则分别维护 |

当前配置包含 ShortestPath 规则，但源快照不含 `ShortestPath/` 目录；配置存在不代表已有此平台题解。不同版本插件是否识别这些设置，需要在本机扩展中核对。

[tasks.json](../.vscode/tasks.json) 只编译活动文件，使用 GNU++23 和一个仓库外的个人编译 wrapper。换机器后把 `command` 改为真实 GNU C++ 编译器，移除不适用于当前架构的 CPU 参数，再检查输出路径；仓库没有提供该 wrapper，不能原样执行就假定可用。

本机路径调整属于个人配置；提交前检查差异，避免把另一台机器的绝对路径覆盖为自己的路径。

## Competitive Companion relay

[relay 脚本](../.cph/scripts/competitive-companion-relay.mjs) 使用 Node.js 内置模块，无 npm 包依赖。它接收题目导入请求，匹配来源路径、生成或迁移源码、处理 `.prob` 元数据，并可打开编辑器。

从仓库根目录手动启动，默认端口为 `4243`：

```sh
CC_RELAY_REPO_ROOT="$PWD" CC_RELAY_DISABLE_OPEN=1 \
  node .cph/scripts/competitive-companion-relay.mjs
```

在另一终端检查服务是否已响应：

```sh
curl --fail http://127.0.0.1:4243/
```

GET 响应包含 `ok`、端口和仓库位置；POST 的 `ok` 仅表示任务已入队，完成情况以日志和实际文件为准。导入方需要把请求发送到同一端口。结束前台服务使用 `Ctrl+C`。

| 环境变量 | 默认或用途 |
| --- | --- |
| `CC_RELAY_REPO_ROOT` | 默认取用户目录下的 `Developer/CompetitiveProgramming`；建议显式指定 |
| `CC_RELAY_CODE_CLI` | 默认是 macOS VS Code CLI 的应用内路径 |
| `CC_RELAY_TEMPLATE_FILE` | 默认仓库内 `Templates/templates/cph.cpp` |
| `CC_RELAY_PORT` | `4243` |
| `CC_RELAY_POLL_TIMEOUT_MS` | `2500`，等待导入文件的轮询时限 |
| `CC_RELAY_DISABLE_OPEN` | 设为 `1` 时不自动打开编辑器 |

导入会写文件，并可能移动或删除临时源码、清理重复 `.prob`；`CC_RELAY_DISABLE_OPEN=1` 只关闭打开编辑器，不关闭这些写操作。当前服务没有指定监听地址，不能将它描述为仅绑定回环地址；应在受信任的本机环境运行，并核对实际监听端口。

## macOS 常驻配置

[LaunchAgent 配置](../.cph/scripts/com.l7.competitive-companion-relay.plist) 记录了 Node、脚本、工作目录和日志的个人绝对路径，并启用了 `RunAtLoad` / `KeepAlive`。克隆仓库不会安装该服务。

需要常驻运行时，先验证上面的手动启动，再按本机路径制作并检查 LaunchAgent；不要直接套用别人的路径或同时启动两个同端口实例。查看启动问题时先确认端口占用、Node 路径、模板文件和日志。

## 本地数据

`.prob`、样例、编译产物和日志默认不跟踪，见 [`.gitignore`](../.gitignore)。导入后检查源码目标路径、原题链接、已有文件是否受到影响，再进行编译和样例验证。
