#pragma once
#include <Arduino.h>

namespace EmakefunPh20Sensors {
inline int readAnalog(uint8_t pin) { return analogRead(pin); }
inline bool readDigital(uint8_t pin, bool activeHigh) {
  pinMode(pin, INPUT);
  int v = digitalRead(pin);
  return activeHigh ? (v == HIGH) : (v == LOW);
}
}
