// main.cpp SHOULD ALWAYS COINTAN ONLY TWO METHODS: 
// setup() 
// loop()

#include <Arduino.h>
#include <WiFi.h>
#include <ArduinoJson.h>
#include <wifi/wifi-service.h>
#include <services/pin-service.h>
#include <http/http-server.h>

// If you want to register a pin define it first as below:
// #define PIN_NAME 4
#define USB_BAUD_RATE 921600

// TODO: User should pass these values instead of hardcoding it here
#define SSID "WIFI_NETWORK_NAME"
#define PASSWORD "WIFI_NETWORK_PASSWORD"

void setup() {
  Serial.begin(USB_BAUD_RATE);

  // registerPin()
  initWifi(SSID, PASSWORD);
  initHttpServer();
}
 
void loop() {
  handleClient();
}