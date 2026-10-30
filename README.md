# ESP32 板载内置蓝色 LED 闪烁工程

本项目基于 PlatformIO + Arduino 框架开发，面向经典 30 引脚 **ESP32 DevKit v1 (ESP-WROOM-32)** 开发板，控制板载内置贴片蓝色 LED 以 500ms 周期（亮 500ms，灭 500ms）交替闪烁。

---

## 硬件规格与引脚连接

> [!NOTE] **内置板载 LED 说明**
> - **无需任何额外外接元件与杜邦线**。
> - 在 30-pin ESP32 DevKit v1 开发板上，板载贴片蓝色 LED 已在 PCB 内部直接走线连接至 **`GPIO 2`**（对应开发板排针标号 `D2`）。
> - 驱动逻辑为正逻辑：`HIGH`（高电平 / 3.3V）点亮，`LOW`（低电平 / 0V）熄灭。
> - 红色 LED 为常亮电源指示灯（PWR），连接电源即亮。

---

## 烧录方式一：终端命令行一键烧录 (推荐，无需开 GUI)

系统当前已安装 PlatformIO Core CLI 环境，且开发板已连接至 `/dev/ttyACM0`。

### 1. 编译工程
在当前项目根目录下运行：
```bash
~/.platformio/penv/bin/pio run
```

### 2. 一键烧录到 ESP32
```bash
~/.platformio/penv/bin/pio run -t upload
```
*提示：如果需要显式指定串口，可追加 `--upload-port /dev/ttyACM0`：*
```bash
~/.platformio/penv/bin/pio run -t upload --upload-port /dev/ttyACM0
```

### 3. 查看运行日志（串口监视器）
```bash
~/.platformio/penv/bin/pio device monitor -b 115200
```
*(退出监视器可按 `Ctrl + C` 或 `Ctrl + ]`)*

---

## 烧录方式二：VS Code + PlatformIO 图形化一键烧录

如果您习惯使用 VS Code 图形界面开发：

1. **打开工程**：
   - 打开 VS Code，选择 `File -> Open Folder...`，打开当前工程目录：
     `/home/deepjh/workspace/esp32-course-practice-1`
2. **等待 PlatformIO 插件加载**：
   - VS Code 会自动检测根目录下的 `platformio.ini` 并完成环境初始化。
3. **底部状态栏一键操作**：
   - 底部状态栏（左下角）提供快捷图标：
     - 点击 **`✓` (PlatformIO: Build)**：执行编译。
     - 点击 **`→` (PlatformIO: Upload)**：一键烧录固件到开发板。
     - 点击 **`🔌` (PlatformIO: Serial Monitor)**：打开 115200 波特率串口控制台。
4. **侧边栏操作路径**：
   - 点击 VS Code 最左侧的 **PlatformIO（外星人/小蜂鸟图标）**；
   - 展开 `esp32doit-devkit-v1` -> `General` -> 点击 **`Upload`** 即可。

---

## 常见排错与注意事项

1. **自动下载与 BOOT 按键**：
   - 该板载 CH9102/CH343 电路支持自动 DTR/RTS 复位进入下载模式。
   - 如果烧录时终端出现 `Connecting........_____.....` 无法连接，只需**长按开发板上的 BOOT 按键** 1~2 秒，待进度条开始跳动即可松手。
2. **Linux 串口访问权限**：
   - 当前系统中 `/dev/ttyACM0` 权限为 `666`，可直接免 root 读写。
   - 如在其他 Linux 系统提示 `Permission denied`，可执行：
     ```bash
     sudo usermod -a -G dialout,uucp $USER
     ```
     重新登录后即可生效。
