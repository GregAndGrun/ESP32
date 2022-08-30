#include "WiFi.h"

void onWifiEvent(WiFiEvent_t event, arduino_event_info_t info){
  switch(event){
    case SYSTEM_EVENT_STA_CONNECTED:
      Serial.println("Station Mode Started");
      break;
    case SYSTEM_EVENT_STA_GOT_IP:
      Serial.println("Connected to :" + String(WiFi.SSID()));
      Serial.print("Got IP: ");
      Serial.println(WiFi.localIP());
      break;
    case SYSTEM_EVENT_STA_DISCONNECTED:
      Serial.println("Disconnected from station, attempting reconnection");
      WiFi.reconnect();
      break;
    default:
      break;
  }
}

void initWifi(char* ssid, char* pass){
  WiFi.onEvent(onWifiEvent);
  WiFi.begin(ssid, pass);
}