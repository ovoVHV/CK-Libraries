#pragma once
#include <Arduino.h>
#include <Wire.h>
#include <gesture_recognizer.h>

namespace EmakefunGestureAdapter {
inline emakefun::GestureRecognizer*& inst() { static emakefun::GestureRecognizer* p = nullptr; return p; }
inline uint8_t& cached() { static uint8_t g = 0; return g; }
inline bool begin(uint8_t addr = 0x39) {
  Wire.begin();
  if (inst()) { delete inst(); inst() = nullptr; }
  inst() = new emakefun::GestureRecognizer(Wire, addr);
  return inst()->Initialize() == emakefun::GestureRecognizer::kOK;
}
inline uint8_t read() {
  cached() = inst() ? static_cast<uint8_t>(inst()->GetGesture()) : 0;
  return cached();
}
inline bool isGesture(uint8_t g) { return cached() == g; }
}
