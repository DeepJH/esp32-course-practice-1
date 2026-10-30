# ADR 0001: ESP32 开发框架与板载 LED 驱动架构选型

## 状态 (Status)
已接受 (Accepted) - 2026-10-30

## 背景 (Context)
用户需要在一块 30 引脚 ESP-WROOM-32 开发板上运行 LED 闪烁程序，要求控制板载内置的蓝色 LED，以 500ms 间隔交替闪烁，并提供命令行及 VS Code + PlatformIO 的双轨烧录与验证指南。

当前系统已识别到 USB 串口设备 `/dev/ttyACM0`（CH9102/CH343 芯片），并安装有 PlatformIO Core CLI。

## 决策 (Decision)
1. **开发框架选型**：采用 PlatformIO + Arduino 框架（`platform = espressif32`, `board = esp32doit-devkit-v1`, `framework = arduino`）。
2. **硬件引脚与极性**：
   - 驱动引脚使用 `GPIO 2`（对应物理板载贴片蓝色 LED）。
   - 驱动电平为正逻辑：`HIGH` 为点亮，`LOW` 为熄灭。
3. **时钟与时序控制**：采用清晰直观的 500ms 周期切换逻辑，便于在嵌入式硬件初学者或课程实验场景中直观验证。
4. **双轨烧录支持**：
   - 本地构建配置统一通过 `platformio.ini` 管理。
   - 交付方案包含 PlatformIO Core 命令（`pio run -t upload`）以及 VS Code PlatformIO 图形化按钮一键烧录。

## 备选方案与权衡 (Consequences & Alternatives Considered)
- **方案 A (已采纳): PlatformIO + Arduino 框架**
  - *优点*：库依赖与工具链由 PlatformIO 自动统一管理；编译轻量高效；代码语义通俗；同时完全适配 VS Code GUI 和 CLI。
  - *缺点*：相较 ESP-IDF 封装略高，但完全满足课程实践与通用外设开发要求。
- **方案 B: 原生 ESP-IDF C 框架**
  - *缺点*：构建环境较重，初次编译耗时长，对课程入门级项目而言复杂度过高。
