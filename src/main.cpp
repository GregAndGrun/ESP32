// main.cpp SHOULD ALWAYS COINTAN ONLY TWO METHODS: 
// setup() 
// loop()

#include <Arduino.h>
#include <WiFi.h>
#include <ArduinoJson.h>
#include <wifi/wifi-service.h>
#include <services/pin-service.h>
#include <http/http-server.h>
#include <Adafruit_SH1106.h>
#include <Adafruit_GFX.h>
#include <ESP32Servo.h>

// If you want to register a pin define it first as below:
#define SERVO_PIN 23
#define BTN_PIN 19

// TODO: User should pass these values instead of hardcoding it here
#define SSID "***"
#define PASSWORD "***"

#define OLED_RESET -1
Adafruit_SH1106 display(OLED_RESET);
Servo myServo;  

bool buttonPressed = false;

void setup() {

  // OLED Display Configuration
  display.begin(SH1106_I2C_ADDRESS, 0x3C);  // The I2C address is specified here
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.print("Hello, world!");
  display.display();
  
  // Servo configuration
  myServo.attach(SERVO_PIN);
  myServo.write(0);

  // Buttons configuration
  registerPin(BTN_PIN, INPUT_PULLUP);

  // Other services Configuration
  initWifi(SSID, PASSWORD);
  initHttpServer();
}
 
void loop() {
  //handleClient();

  if (digitalRead(BTN_PIN) == LOW && !buttonPressed) {
    buttonPressed = true;  
    display.setCursor(0,0);
    display.clearDisplay();
    display.print("Button is pressed");
    display.display();

    myServo.write(90);
  }
  if (digitalRead(BTN_PIN) == HIGH) {
    buttonPressed = false;
    display.setCursor(0,0);
    display.clearDisplay();
    display.print("Button is not pressed");
    display.display();

    myServo.write(5);
  }
}
