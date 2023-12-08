/*
 * @Author: CuiYao 
 * @Date: 2022-11-02 10:37:44 
 * @Last Modified by:   CuiYao 
 * @Last Modified time: 2022-11-02 10:37:44 
 */


#include <ESP8266HTTPClient.h> 
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h> 

WiFiManager wifiManager;
//gets called when WiFiManager enters configuration mode
void configModeCallback (WiFiManager *myWiFiManager) {
  Serial.println("Entered config mode");
  Serial.println(WiFi.softAPIP());
  //if you used auto generated SSID, print it
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
  //wifiManager.setConnectTimeout(180);

  //wifiManager.setTimeout(180);

  wifiManager.setAPCallback(configModeCallback);
  if (!wifiManager.autoConnect()) {
    Serial.println("failed to connect and hit timeout");
    //reset and try again, or maybe put it to deep sleep
    ESP.reset();
    delay(1000);
  }
  Serial.println("connected...yeey (^_^)");
}