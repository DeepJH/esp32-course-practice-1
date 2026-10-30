# Spec 0001: ESP32 板载蓝色 LED 500ms 周期闪烁程序

## 1. 概述与用户故事 (User Stories)
- **US-1**: 作为开发者/学习者，我希望烧录固件后，ESP32 核心板上的内置贴片蓝色 LED 能以 500ms 间隔交替闪烁，以便确认核心板工作正常且无需任何外接接线。
- **US-2**: 作为开发者，我希望在终端中通过标准命令（如 `pio run -t upload`）一键完成编译与固件烧录。
- **US-3**: 作为 VS Code 用户，我希望工程完全兼容 VS Code PlatformIO 插件，在图形化界面中点击一键即可完成构建与上传。

## 2. 硬件映射与电气规格 (Hardware Specifications)
- **主控芯片**：ESP32-D0WD-V3 (ESP-WROOM-32 模组)
- **目标板型**：30-pin ESP32 DevKit v1
- **LED 引脚**：`GPIO 2` (板载贴片蓝色 LED)
- **驱动电平**：
  - `HIGH (3.3V)` -> LED 点亮
  - `LOW (0V)` -> LED 熄灭
- **时序规格**：
  - 点亮时长：500 ms (误差范围 < ±5%)
  - 熄灭时长：500 ms (误差范围 < ±5%)
  - 闪烁周期：1000 ms (频率 1.0 Hz)

## 3. 工程设计与架构 (Project Architecture)
```
esp32-course-practice-1/
├── platformio.ini       # PlatformIO 构建与板级配置
├── src/
│   └── main.cpp         # 固件入口与闪烁主逻辑
├── include/             # 预留头文件目录
├── docs/
│   ├── adr/
│   └── specs/
├── .scratch/            # 本地切片任务跟踪
└── GLOSSARY.md
```

### `platformio.ini` 配置要求
- `platform = espressif32`
- `board = esp32doit-devkit-v1`
- `framework = arduino`
- `monitor_speed = 115200`
- `upload_speed = 921600` (或自适应)

## 4. 验收清单 (Acceptance Criteria)
- [ ] AC-1: `platformio.ini` 配置文件完整有效，支持 `esp32doit-devkit-v1` 板型与 Arduino 框架。
- [ ] AC-2: `src/main.cpp` 编译零警告零错误，`GPIO 2` 被正确初始化为推挽输出模式 (`OUTPUT`)。
- [ ] AC-3: 主循环在 500ms 保持 HIGH，500ms 保持 LOW，严格交替。
- [ ] AC-4: 通过 `pio run` 能够在本地干净编译产出 `firmware.bin` 和 `partitions.bin`。
- [ ] AC-5: 提供完整的烧录指引（含 CLI 与 VS Code GUI 两种途径）。
