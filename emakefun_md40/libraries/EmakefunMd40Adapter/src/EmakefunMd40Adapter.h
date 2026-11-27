#pragma once
#include <Arduino.h>
#include <Wire.h>
#include <md40.h>

namespace EmakefunMd40Adapter {
inline em::Md40*& inst() { static em::Md40* p = nullptr; return p; }
inline void begin(uint8_t addr = 0x16) {
  Wire.begin();
  if (inst()) { delete inst(); inst() = nullptr; }
  inst() = new em::Md40(addr, Wire);
  inst()->Init();
}
inline void setDc(uint8_t idx) { if (inst() && idx < 4) (*inst())[idx].SetDcMode(); }
inline void setEncoder(uint8_t idx, uint16_t ppr, uint16_t ratio, uint8_t phase) {
  if (inst() && idx < 4) (*inst())[idx].SetEncoderMode(ppr, ratio, static_cast<em::Md40::Motor::PhaseRelation>(phase));
}
inline void runSpeed(uint8_t idx, int32_t rpm) { if (inst() && idx < 4) (*inst())[idx].RunSpeed(rpm); }
inline void runPwm(uint8_t idx, int16_t duty) { if (inst() && idx < 4) (*inst())[idx].RunPwmDuty(duty); }
inline void moveTo(uint8_t idx, int32_t pos, int32_t spd) { if (inst() && idx < 4) (*inst())[idx].MoveTo(pos, spd); }
inline void moveRel(uint8_t idx, int32_t off, int32_t spd) { if (inst() && idx < 4) (*inst())[idx].Move(off, spd); }
inline void stop(uint8_t idx) { if (inst() && idx < 4) (*inst())[idx].Stop(); }
inline int32_t speed(uint8_t idx) { return (inst() && idx < 4) ? (*inst())[idx].speed() : 0; }
inline int32_t position(uint8_t idx) { return (inst() && idx < 4) ? (*inst())[idx].position() : 0; }
}
