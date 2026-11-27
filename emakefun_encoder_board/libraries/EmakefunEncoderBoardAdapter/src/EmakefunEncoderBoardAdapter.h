#pragma once
#include <Arduino.h>
#include <Wire.h>
#include <encoder_motor_board.h>

namespace EmakefunEncoderBoardAdapter {
inline emakefun::EncoderMotorBoard*& inst() { static emakefun::EncoderMotorBoard* p = nullptr; return p; }
inline bool begin(uint8_t addr = 0x09) {
  Wire.begin();
  if (inst()) { delete inst(); inst() = nullptr; }
  inst() = new emakefun::EncoderMotorBoard(addr);
  return inst()->Initialize(&Wire);
}
inline emakefun::EncoderMotorBoard::EncoderMotor* motor(uint8_t idx) {
  if (!inst() || idx >= 4) return nullptr;
  return const_cast<emakefun::EncoderMotorBoard::EncoderMotor*>(&((*inst())[idx]));
}
inline void runSpeed(uint8_t idx, int16_t rpm) { if (auto* m = motor(idx)) m->RunSpeed(rpm); }
inline void runPwm(uint8_t idx, int16_t pwm) { if (auto* m = motor(idx)) m->RunPwm(pwm); }
inline void movePos(uint8_t idx, int32_t pos, uint16_t spd) { if (auto* m = motor(idx)) m->MovePosition(pos, spd); }
inline void stop(uint8_t idx) { if (auto* m = motor(idx)) m->Stop(); }
inline float speed(uint8_t idx) { auto* m = motor(idx); return m ? m->CurrentSpeed() : 0.0f; }
inline int32_t position(uint8_t idx) { auto* m = motor(idx); return m ? m->CurrentPosition() : 0; }
}
