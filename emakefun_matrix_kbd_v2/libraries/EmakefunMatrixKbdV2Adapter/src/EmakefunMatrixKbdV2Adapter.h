#pragma once
#include <Arduino.h>
#include <Wire.h>
#include <matrix_keyboard.h>

namespace EmakefunMatrixKbdV2Adapter {
inline MatrixKeyboard*& inst() { static MatrixKeyboard* p = nullptr; return p; }
inline bool begin(uint8_t addr = 0x50) {
  Wire.begin();
  if (inst()) { delete inst(); inst() = nullptr; }
  inst() = new MatrixKeyboard(addr);
  return inst()->Setup();
}
inline String touchedKey() {
  if (!inst()) return String("");
  char c = inst()->GetTouchedKey();
  if (c == '\0') return String("");
  char buf[2] = {c, '\0'};
  return String(buf);
}
}
