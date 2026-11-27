#pragma once
#include <Arduino.h>
#include <Wire.h>
#include <color_sensor_nlcs21.h>

namespace EmakefunNlcs21Adapter {
inline emakefun::ColorSensorNlcs21*& inst() { static emakefun::ColorSensorNlcs21* p = nullptr; return p; }
inline emakefun::ColorSensorNlcs21::Color& last() { static emakefun::ColorSensorNlcs21::Color c; return c; }
inline bool begin(uint8_t gain, uint8_t itime, uint8_t addr = 0x38) {
  Wire.begin();
  if (inst()) { delete inst(); inst() = nullptr; }
  inst() = new emakefun::ColorSensorNlcs21(
      static_cast<emakefun::ColorSensorNlcs21::Gain>(gain),
      static_cast<emakefun::ColorSensorNlcs21::IntegrationTime>(itime),
      addr, Wire);
  return inst()->Initialize() == emakefun::ColorSensorNlcs21::kOK;
}
inline bool sample() { return inst() ? inst()->GetColor(&last()) : false; }
inline uint16_t r() { return last().r; }
inline uint16_t g() { return last().g; }
inline uint16_t b() { return last().b; }
inline uint16_t c() { return last().c; }
}
