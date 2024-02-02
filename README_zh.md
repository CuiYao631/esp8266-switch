
<div align="center">
<h1 align="center">esp8266-switch</h1>
   
[![GitHub release](https://img.shields.io/github/v/release/CuiYao631/esp8266-switch)](https://github.com/CuiYao631/esp8266-switch/releases)
![GitHub All Releases](https://img.shields.io/github/downloads/CuiYao631/esp8266-switch/total)
[![GitHub stars](https://img.shields.io/github/stars/CuiYao631/esp8266-switch)](https://github.com/CuiYao631/esp8266-switch/stargazers)
[![GitHub forks](https://img.shields.io/github/forks/CuiYao631/esp8266-switch)](https://github.com/CuiYao631/esp8266-switch/fork)
<h4 align="center"><a href="https://github.com/CuiYao631/esp8266-switch/blob/main/README.md">English</a> | <a>简体中文</a></h4>
</div>

## 介绍
esp8266-HomeKit 开关控制器，使用esp8266-HomeKit库，实现了一个简单的开关控制器，可以通过Siri控制开关，也可以通过苹果的Home APP控制开关。


## 操作
1. 短按按钮，开关切换
2. 长按按钮5秒，清除配网信息，清除HomeKit配对信息，重启
3. 在配网时，如果手机连接的是5G的WiFi，会导致配网失败，需要将手机连接到2.4G的WiFi，才能配网成功。
4. HomeKit： IOS 手机需要安装 Home APP 才能使用 Siri 控制开关,打开 Home APP 后,点击右上角的 + 号,选择添加配件,扫描二维码,即可添加配件,添加成功后,可以在 Home APP 中控制开关,也可以使用 Siri 控制开关。
   
## 二维码
![二维码](/qrcode.png)</div>



## 代码
修改控制引脚
```c
#define LED_PIN 2 // switch PIN 开关控制引脚
#define BTN_PIN 0 // Button PIN 按钮控制引脚
```

## BUG
1. [已修复](https://github.com/CuiYao631/esp8266-switch/releases/tag/v0.0.3)~~使用的配网库为 WiFiManager, 清除配网信息重启后,发现还是可以连接到之前配置好的 Wifi 中,暂时还没有解决该问题,或者更换配网库,如果有解决方案,请告知我,谢谢!~~
