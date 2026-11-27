#pragma once
#include <Arduino.h>

namespace EmakefunPh20Actuators {
inline void setSwitch(uint8_t pin, bool on) { pinMode(pin, OUTPUT); digitalWrite(pin, on ? HIGH : LOW); }
inline void setPwm(uint8_t pin, int speed) {
  pinMode(pin, OUTPUT);
  if (speed < 0) speed = 0;
  if (speed > 255) speed = 255;
  analogWrite(pin, speed);
}
inline void driveDualPinMotor(uint8_t ia, uint8_t ib, int speed) {
  pinMode(ia, OUTPUT); pinMode(ib, OUTPUT);
  if (speed > 255) speed = 255;
  if (speed < -255) speed = -255;
  if (speed >= 0) { analogWrite(ia, speed); analogWrite(ib, 0); }
  else { analogWrite(ia, 0); analogWrite(ib, -speed); }
}
inline void buzzerTone(uint8_t pin, unsigned int freq, unsigned long durMs) {
  pinMode(pin, OUTPUT);
  if (durMs > 0) tone(pin, freq, durMs); else tone(pin, freq);
}
inline void buzzerStop(uint8_t pin) { noTone(pin); }
}
