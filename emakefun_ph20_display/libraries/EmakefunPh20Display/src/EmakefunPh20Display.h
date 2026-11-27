#pragma once
#include <Arduino.h>

namespace EmakefunPh20Display {
inline void setLed(uint8_t pin, bool on) { pinMode(pin, OUTPUT); digitalWrite(pin, on ? HIGH : LOW); }
inline void setTraffic(uint8_t rPin, uint8_t yPin, uint8_t gPin, uint8_t state) {
  pinMode(rPin, OUTPUT); pinMode(yPin, OUTPUT); pinMode(gPin, OUTPUT);
  digitalWrite(rPin, state == 1 ? HIGH : LOW);
  digitalWrite(yPin, state == 2 ? HIGH : LOW);
  digitalWrite(gPin, state == 3 ? HIGH : LOW);
}
inline void setRgb(uint8_t rPin, uint8_t gPin, uint8_t bPin, int r, int g, int b) {
  pinMode(rPin, OUTPUT); pinMode(gPin, OUTPUT); pinMode(bPin, OUTPUT);
  analogWrite(rPin, constrain(r, 0, 255));
  analogWrite(gPin, constrain(g, 0, 255));
  analogWrite(bPin, constrain(b, 0, 255));
}
}
