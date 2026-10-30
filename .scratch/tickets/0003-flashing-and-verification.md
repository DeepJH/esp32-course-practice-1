# [Ticket #3] docs: provide CLI and VS Code PlatformIO flashing guides and verify build

- **状态**: COMPLETED
- **关联远程工单**: https://github.com/DeepJH/esp32-course-practice-1/issues/3
- **关联规格**: docs/specs/0001-esp32-onboard-led-blink.md (AC-5)

## 任务目标
编写完备的烧录指引文档（包含针对 `/dev/ttyACM0` 的终端一键上传命令，以及 VS Code PlatformIO 扩展的图形化烧录步骤），并在 `README.md` 中向用户呈现。

## 验收清单
- [x] 详细记录 `pio run -t upload` 及其参数用法
- [x] 详细记录 VS Code PlatformIO 界面操作步骤
- [x] 包含常见串口权限与驱动排错说明
