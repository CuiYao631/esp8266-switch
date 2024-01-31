/*
 * ESP8266 智能开关
 * @Author: CuiYao
 * @Date: 2024-01-31 17:39:00
 * @Last Modified by:   CuiYao
 * @Last Modified time: 2024-01-31 17:39:00
 */
#include <ESP8266WiFi.h>
#include <EasyButton.h>
#include <Ticker.h>
#include <arduino_homekit_server.h>
#include "wifi_info.h"    //加载WIFI

#define LED_PIN 2 // switch PIN
#define BTN_PIN 0 // Button PIN
#define LOG_D(fmt, ...)   printf_P(PSTR(fmt "\n") , ##__VA_ARGS__);
const int duration = 5000;                  // Button长按触发时间
int inputValue = 0;

Ticker ticker;                      // 初始化定时器
EasyButton button(BTN_PIN);         // 开关初始化

void setup() {
  pinMode(LED_PIN, OUTPUT);                            // 设置引脚为输出模式
  Serial.begin(115200);                                // 初始化串口
  ticker.attach(0.1, buttonRead);                      // 定时器
  wifi_connect();                                      // 初始化WIFI
  button.onPressed(onPressed);                         // 定义按键单按事件回调
  button.onPressedFor(duration, onPressedForDuration); // 定义按键长按事件回调
  digitalWrite(LED_PIN, HIGH);                         // 默认为关闭
  my_homekit_setup();                                  // 初始化HomeKit
  Serial.println("Initialization completed (^_^) ");
}


// 检测按键状态(定时器)
void buttonRead()
{
  button.read();
}
// 检测HomeKit状态
void loop() {
  my_homekit_loop();
	delay(10);
}

// access your HomeKit characteristics defined in my_accessory.c
extern "C" homekit_server_config_t config;
extern "C" homekit_characteristic_t cha_switch_on;
static uint32_t next_heap_millis = 0;
//Called when the switch value is changed by iOS Home APP
void cha_switch_on_setter(const homekit_value_t value) {
	bool on = value.bool_value;
	cha_switch_on.value.bool_value = on;	//sync the value
	LOG_D("Switch: %s", on ? "ON" : "OFF");
	digitalWrite(LED_PIN, on ? LOW : HIGH);
}
//初始化Homekit设置 
void my_homekit_setup() {
	cha_switch_on.setter = cha_switch_on_setter;
	arduino_homekit_setup(&config);
}
// 单击事件函数
void onPressed()
{
  inputValue = digitalRead(LED_PIN);
  if (inputValue == LOW) {
    Serial.println("OFF");
    cha_switch_on.value.bool_value = false;
    homekit_characteristic_notify(&cha_switch_on, cha_switch_on.value);
    digitalWrite(LED_PIN, HIGH);
  } else {
    Serial.println("ON");
    cha_switch_on.value.bool_value = true;
    homekit_characteristic_notify(&cha_switch_on, cha_switch_on.value);
    digitalWrite(LED_PIN, LOW);
  }
}
// 长按事件函数
void onPressedForDuration()
{
   //清除HomeKit信息
  homekit_storage_reset();
  // 清除WIFI信息
  wifi_reset();
 
}

void my_homekit_loop() {
	arduino_homekit_loop();
	const uint32_t t = millis();
	if (t > next_heap_millis) {
		// show heap info every 5 seconds
		next_heap_millis = t + 5 * 1000;
		LOG_D("Free heap: %d, HomeKit clients: %d",
				ESP.getFreeHeap(), arduino_homekit_connected_clients_count());

	}
}