/*
 * @Author: CuiYao 
 * @Date: 2022-11-02 10:37:44 
 * @Last Modified by:   CuiYao 
 * @Last Modified time: 2022-11-02 10:37:44 
 */
#include <WiFiManager.h> 

WiFiManager wifiManager;
//在WiFiManager进入配置模式时被调用
void configModeCallback (WiFiManager *myWiFiManager) {
  Serial.println("Entered config mode");
  Serial.println(WiFi.softAPIP());
  //如果使用了自动生成的SSID，打印
  Serial.println(myWiFiManager->getConfigPortalSSID());
}
//清除WIFI
void wifi_reset(){
  wifiManager.resetSettings();
  delay(2000);
  ESP.reset(); 
}

//连接WIFI
void wifi_connect() {
  wifiManager.setAPCallback(configModeCallback);
  if (!wifiManager.autoConnect()) {
    Serial.println("failed to connect and hit timeout");
    //连接WIFI后自动重启
    ESP.reset();
    delay(1000);
  }
  Serial.println("connected...yeey (^_^)");
}