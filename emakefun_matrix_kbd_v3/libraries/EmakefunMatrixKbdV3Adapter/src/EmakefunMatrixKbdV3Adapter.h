#pragma once
#include <Arduino.h>
#include <Wire.h>
#include <matrix_keyboard.h>

namespace EmakefunMatrixKbdV3Adapter {
inline emakefun::MatrixKeyboard*& inst() { static emakefun::MatrixKeyboard* p = nullptr; return p; }
inline bool begin(uint8_t addr = 0x65) {
  Wire.begin();
  if (inst()) { delete inst(); inst() = nullptr; }
  inst() = new emakefun::MatrixKeyboard(Wire, addr);
  return inst()->Initialize() == emakefun::MatrixKeyboard::ErrorCode::kOK;
}
inline void tick() { if (inst()) inst()->Tick(); }
inline String keyText() {
  if (!inst()) return String("");
  char c = inst()->GetCurrentPressedKey();
  if (c == '\0') return String("");
  char buf[2] = {c, '\0'};
  return String(buf);
}
inline bool pressed(uint16_t keyMask) { return inst() ? inst()->Pressed(static_cast<emakefun::MatrixKeyboard::Key>(keyMask)) : false; }
inline bool pressing(uint16_t keyMask) { return inst() ? inst()->Pressing(static_cast<emakefun::MatrixKeyboard::Key>(keyMask)) : false; }
}
