#include <Arduino.h>

/**
 * @file main.cpp
 * @brief ESP32 板载内置蓝色 LED 闪烁程序 (ESP-WROOM-32 30-pin)
 *
 * 硬件连接说明：
 * 在 ESP32 DevKit v1 (30 引脚) 开发板上，板载内置贴片蓝色 LED
 * 内部硬件直接走线连接至 GPIO 2 (D2)。
 * 驱动电平为正逻辑：HIGH 点亮，LOW 熄灭。
 */

// 板载内置蓝色 LED 绑定引脚
#ifndef LED_BUILTIN_PIN
#define LED_BUILTIN_PIN 2
#endif

// 闪烁交替间隔时间 (毫秒)
constexpr uint32_t BLINK_INTERVAL_MS = 500;

void setup() {
    // 初始化串口通信，波特率设为 115200
    Serial.begin(115200);
    delay(200);
    Serial.println();
    Serial.println(F("=================================================="));
    Serial.println(F("  ESP32 Onboard LED Blink Program Started"));
    Serial.println(F("=================================================="));
    Serial.printf("[INFO] Target Hardware : ESP32 DevKit v1 (30-pin)\n");
    Serial.printf("[INFO] Onboard LED Pin : GPIO %d\n", LED_BUILTIN_PIN);
    Serial.printf("[INFO] Blink Interval  : %u ms\n", BLINK_INTERVAL_MS);

    // 初始化板载 LED 引脚为推挽输出模式
    pinMode(LED_BUILTIN_PIN, OUTPUT);

    // 初始状态置低电平（熄灭）
    digitalWrite(LED_BUILTIN_PIN, LOW);
}

void loop() {
    // 点亮板载蓝色 LED
    digitalWrite(LED_BUILTIN_PIN, HIGH);
    Serial.println(F("[LED Status] ON  (HIGH)"));
    delay(BLINK_INTERVAL_MS);

    // 熄灭板载蓝色 LED
    digitalWrite(LED_BUILTIN_PIN, LOW);
    Serial.println(F("[LED Status] OFF (LOW)"));
    delay(BLINK_INTERVAL_MS);
}
