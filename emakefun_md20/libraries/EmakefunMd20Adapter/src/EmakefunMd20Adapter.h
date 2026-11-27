#pragma once
#include <Arduino.h>
#include <Wire.h>
#include <md20.h>

namespace EmakefunMd20Adapter {
inline em::Md20*& inst() { static em::Md20* p = nullptr; return p; }
inline bool begin(uint8_t addr = 0x16) {
  Wire.begin();
  if (inst()) { delete inst(); inst() = nullptr; }
  inst() = new em::Md20(addr, Wire);
  return inst()->Init() == em::Md20::kOK;
}
inline void initMotor(uint8_t idx, uint16_t ppr, uint16_t ratio, uint8_t phase) {
  if (inst() && idx < 4) (*inst())[idx].Init(ppr, ratio, static_cast<em::Md20::PhaseRelation>(phase));
}
inline void runSpeed(uint8_t idx, int32_t rpm) { if (inst() && idx < 4) (*inst())[idx].RunSpeed(rpm); }
inline void resetMotor(uint8_t idx) { if (inst() && idx < 4) (*inst())[idx].Reset(); }
}
