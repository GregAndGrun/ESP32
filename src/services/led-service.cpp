#include <Arduino.h>
#include <helpers/serializers/json-serializer.h>

void turnOnLed(uint8_t pinNumber) {
    // TODO: Use pin-service and check if pinNumber are registered
    digitalWrite(pinNumber, HIGH);
    Serial.println("led-service: " + String(pinNumber) + " is tuned ON");
}

void turnOffLed(uint8_t pinNumber) {
    // TODO: Use pin-service and check if pinNumber are registered
    digitalWrite(pinNumber, LOW);
    Serial.println("led-service: " + String(pinNumber) + " is tuned OFF");
}
