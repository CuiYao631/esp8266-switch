
<div align="center">
<h1 align="center">esp8266-switch</h1>

[![GitHub release](https://img.shields.io/github/v/release/CuiYao631/esp8266-switch)](https://github.com/CuiYao631/esp8266-switch/releases)
![GitHub All Releases](https://img.shields.io/github/downloads/CuiYao631/esp8266-switch/total)
[![GitHub stars](https://img.shields.io/github/stars/CuiYao631/esp8266-switch)](https://github.com/CuiYao631/esp8266-switch/stargazers)
[![GitHub forks](https://img.shields.io/github/forks/CuiYao631/esp8266-switch)](https://github.com/CuiYao631/esp8266-switch/fork)
<h4 align="center"><strong>English</strong> | <a href="https://github.com/CuiYao631/esp8266-switch/blob/main/README_zh.md">
简体中文</a></h4>
</div>

## introduce
The esp8266 HomeKit switch controller uses the esp8266 HomeKit library to implement a simple switch controller that can be controlled through Siri or Apple's Home app.


## operate
1. Short press the button to switch between switches
2. Press and hold the button for 5 seconds to clear the distribution network information, HomeKit pairing information, and restart
3. During network configuration, if the phone is connected to 5G WiFi, it will cause network configuration failure. It is necessary to connect the phone to 2.4G WiFi in order to successfully configure the network.
4. HomeKit: IOS phones require the installation of the Home app to use Siri to control the switch. After opening the Home app, click on the+sign in the upper right corner, select Add Accessories, scan the QR code to add accessories. After successful addition, you can control the switch in the Home app or use Siri to control the switch.。
   
## QR code
![QR code](/qrcode.png)</div>



## code
Modify control pins
```c
#define LED_PIN 2 // switch PIN Switch control pin
#define BTN_PIN 0 // Button PIN Button control pin
```

## BUG
1. The distribution network library used is WiFiManager. After clearing the distribution network information and restarting, it was found that you can still connect to the previously configured WiFi. The problem has not been resolved yet, or you can replace the distribution network library. If there is a solution, please let me know. Thank you!
