# [Ticket #2] feat: implement onboard blue LED blink logic (GPIO 2, 500ms period)

- **状态**: COMPLETED
- **关联远程工单**: https://github.com/DeepJH/esp32-course-practice-1/issues/2
- **关联规格**: docs/specs/0001-esp32-onboard-led-blink.md (AC-2, AC-3, AC-4)

## 任务目标
在 `src/main.cpp` 中实现 ESP32 板载内置蓝色贴片 LED 的闪烁逻辑，使用 `GPIO 2`，高电平点亮 500ms，低电平熄灭 500ms。

## 验收清单
- [x] `GPIO 2` 正确配置为推挽输出模式 (`OUTPUT`)
- [x] 500ms 点亮，500ms 熄灭严格交替循环
- [x] `pio run` 本地编译通过并生成目标固件二进制包 (`firmware.bin`)
