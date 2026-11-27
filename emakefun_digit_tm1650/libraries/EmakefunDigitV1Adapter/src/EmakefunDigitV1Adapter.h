#pragma once
#include <Arduino.h>
#include <Wire.h>
#include <digit_display.h>

namespace EmakefunDigitV1Adapter {
inline DigitDisplay*& inst() { static DigitDisplay* p = nullptr; return p; }
inline void begin(uint8_t addr = 0x70) {
  Wire.begin();
  if (inst()) { delete inst(); inst() = nullptr; }
  inst() = new DigitDisplay(addr);
  inst()->Setup();
}
inline void showNumber(double v, uint8_t dec) { if (inst()) inst()->ShowNumber(v, DigitDisplay::kDec, dec); }
inline void showColon(bool on) { if (inst()) inst()->ShowColon(on); }
inline void setBrightness(uint8_t b) { if (inst()) inst()->SetBrightness(b); }
inline void clear() { if (inst()) inst()->Clear(); }
}
