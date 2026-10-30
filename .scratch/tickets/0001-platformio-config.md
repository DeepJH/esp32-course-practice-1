# [Ticket #1] feat: configure PlatformIO project structure and platformio.ini

- **状态**: COMPLETED
- **关联远程工单**: https://github.com/DeepJH/esp32-course-practice-1/issues/1
- **关联规格**: docs/specs/0001-esp32-onboard-led-blink.md (AC-1)

## 任务目标
初始化 PlatformIO 工程结构，配置 `platformio.ini`（包含 `esp32doit-devkit-v1` 开发板、`arduino` 框架、串口监视器波特率与上传参数）。

## 验收清单
- [x] 具备规范的 `platformio.ini` 文件
- [x] 具备 `src/` 与 `include/` 源码目录及 `.gitignore`
- [x] PlatformIO 能够成功解析该工程环境
