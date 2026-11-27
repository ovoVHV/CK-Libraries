#pragma once
#include <Arduino.h>
#include <Wire.h>
#include <dm11.h>

namespace EmakefunDm11Adapter {
inline em::Dm11*& inst() { static em::Dm11* p = nullptr; return p; }
inline bool begin(uint16_t freqHz = 1000, uint8_t addr = 0x15) {
  Wire.begin();
  if (inst()) { delete inst(); inst() = nullptr; }
  inst() = new em::Dm11(addr, Wire);
  return inst()->Init(freqHz) == em::Dm11::kOK;
}
inline void setPwm(uint8_t ch, uint16_t duty) {
  if (!inst() || ch >= 4) return;
  if (duty > em::Dm11::kMaxPwmDuty) duty = em::Dm11::kMaxPwmDuty;
  inst()->PwmDuty(static_cast<em::Dm11::PwmChannel>(ch), duty);
}
inline void setMotor(uint8_t motorIdx, int16_t speed) {
  if (!inst() || motorIdx > 1) return;
  if (speed > 4095) speed = 4095;
  if (speed < -4095) speed = -4095;
  uint8_t c0 = motorIdx == 0 ? 0 : 2;
  uint8_t c1 = motorIdx == 0 ? 1 : 3;
  if (speed >= 0) {
    setPwm(c0, static_cast<uint16_t>(speed));
    setPwm(c1, 0);
  } else {
    setPwm(c0, 0);
    setPwm(c1, static_cast<uint16_t>(-speed));
  }
}
inline void stopAll() { for (uint8_t i = 0; i < 4; ++i) setPwm(i, 0); }
}
