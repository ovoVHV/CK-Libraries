#pragma once
#include <Arduino.h>
#include <encoder_motor.h>

namespace EmakefunEsp32EncoderAdapter {
inline em::EncoderMotor*& inst() { static em::EncoderMotor* p = nullptr; return p; }
inline void begin(uint8_t posPin, uint8_t negPin, uint8_t aPin, uint8_t bPin, uint32_t ppr, uint32_t ratio) {
  if (inst()) { delete inst(); inst() = nullptr; }
  inst() = new em::EncoderMotor(posPin, negPin, aPin, bPin, ppr, ratio, em::EncoderMotor::kAPhaseLeads);
  inst()->Init();
}
inline void runSpeed(int16_t rpm) { if (inst()) inst()->RunSpeed(rpm); }
inline void runPwm(int16_t duty) { if (inst()) inst()->RunPwmDuty(duty); }
inline void stop() { if (inst()) inst()->Stop(); }
inline int32_t speedRpm() { return inst() ? inst()->SpeedRpm() : 0; }
inline long pulseCount() { return inst() ? static_cast<long>(inst()->EncoderPulseCount()) : 0; }
inline void resetPulse() { if (inst()) inst()->ResetPulseCount(); }
}
