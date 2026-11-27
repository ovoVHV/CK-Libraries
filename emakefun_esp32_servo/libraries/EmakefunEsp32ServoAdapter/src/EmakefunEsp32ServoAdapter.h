#pragma once
#include <Arduino.h>
#include <servo.h>

namespace EmakefunEsp32ServoAdapter {
inline em::Servo*& slot(uint8_t ch) {
  static em::Servo* s[4] = {nullptr, nullptr, nullptr, nullptr};
  return s[ch < 4 ? ch : 0];
}
inline bool begin(uint8_t ch, uint8_t pin) {
  auto*& s = slot(ch);
  if (s) { delete s; s = nullptr; }
  s = new em::Servo(pin);
  return s->Init();
}
inline void writeAngle(uint8_t ch, uint16_t angle) { if (auto* s = slot(ch)) s->Write(angle); }
inline void writeUs(uint8_t ch, double us) { if (auto* s = slot(ch)) s->writeMicroseconds(us); }
}
