# 领域术语表 (GLOSSARY)

本文档定义了本项目涉及的硬件、驱动、工程框架及规范术语，供团队与代理统一上下文。

### 板载内置 LED (Onboard LED)
焊接在 ESP32 核心板 PCB 正面的贴片发光二极管（SMD LED），位于微控制器屏蔽罩与电源指示灯之间。硬件电路上出厂即与 ESP32 芯片的引脚直接物理连线，无需任何外接导线或元器件。

### GPIO 2
ESP32 芯片上的通用输入输出（General Purpose Input/Output）第 2 号引脚。在当前 30 引脚 ESP32 DevKit v1 开发板上，板载蓝色贴片 LED 硬件连接至该引脚，采用高电平（HIGH / 3.3V）驱动导通点亮，低电平（LOW / 0V）截止熄灭。

### ESP32 DevKit v1 (30-pin)
基于乐鑫（Espressif）ESP-WROOM-32 模组的双核 32 位低功耗微控制器开发板，具备 30 个双排引脚，集成 CH9102/CH343 USB-to-UART 桥接芯片与 AMS1117 3.3V 稳压芯片。

### PlatformIO
面向嵌入式开发的现代跨平台集成构建系统与包管理器，支持在命令行（PlatformIO Core CLI）与现代 IDE（VS Code / CLion）中无缝编译、测试与烧录固件。

### 闪烁时序 (Blink Timing)
微控制器控制指示灯周期性亮灭的占空比时序。本项目定义为 500ms 保持高电平（亮）+ 500ms 保持低电平（灭），交替循环，周期 1000ms（频率 1Hz）。
