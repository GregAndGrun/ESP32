#include <Arduino.h>

void registerPin(uint8_t number, uint8_t mode){
    pinMode(number, mode);
    // TODO: store pin configuration somewhere
}
