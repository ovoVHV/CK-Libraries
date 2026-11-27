#pragma once
#include <Arduino.h>
#include <Wire.h>
#include <gpio_expansion_board.h>

namespace EmakefunGpioBoardAdapter {
inline GpioExpansionBoard*& inst() { static GpioExpansionBoard* p = nullptr; return p; }
inline void begin(uint8_t addr = 0x24) {
  Wire.begin();
  if (inst()) { delete inst(); inst() = nullptr; }
  inst() = new GpioExpansionBoard(addr);
}
inline void setMode(uint8_t pin, uint8_t mode) { if (inst()) inst()->SetGpioMode(static_cast<GpioExpansionBoard::GpioPin>(pin), static_cast<GpioExpansionBoard::GpioMode>(mode)); }
inline void writeDigital(uint8_t pin, uint8_t lvl) { if (inst()) inst()->SetGpioLevel(static_cast<GpioExpansionBoard::GpioPin>(pin), lvl); }
inline uint8_t readDigital(uint8_t pin) { return inst() ? inst()->GetGpioLevel(static_cast<GpioExpansionBoard::GpioPin>(pin)) : 0; }
inline uint16_t readAdc(uint8_t pin) { return inst() ? inst()->GetGpioAdcValue(static_cast<GpioExpansionBoard::GpioPin>(pin)) : 0; }
inline void setPwmFreq(uint16_t freq) { if (inst()) inst()->SetPwmFrequency(freq); }
inline void setPwmDuty(uint8_t pin, uint16_t duty) { if (inst()) inst()->SetPwmDuty(static_cast<GpioExpansionBoard::GpioPin>(pin), duty); }
inline void setServo(uint8_t pin, float angle) { if (inst()) inst()->SetServoAngle(static_cast<GpioExpansionBoard::GpioPin>(pin), angle); }
}
