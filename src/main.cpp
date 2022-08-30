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
#define LED_RED_DIOD 25
#define USB_BAUD_RATE 921600

// TODO: User should pass these values instead of hardcoding it here
#define SSID "gregandgrun"
#define PASSWORD "N1epam1etam"

void setup() {
  Serial.begin(USB_BAUD_RATE);

  registerPin(LED_RED_DIOD, OUTPUT);
  initWifi(SSID, PASSWORD);
  initHttpServer();
}
 
void loop() {
  handleClient();
}
