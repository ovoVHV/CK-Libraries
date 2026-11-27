#pragma once
#include <Arduino.h>
#include <Wire.h>
#include <color_sensor_nlcs11.h>

namespace EmakefunNlcs11Adapter {
inline emakefun::ColorSensorNlcs11*& inst() { static emakefun::ColorSensorNlcs11* p = nullptr; return p; }
inline emakefun::ColorSensorNlcs11::Color& last() { static emakefun::ColorSensorNlcs11::Color c; return c; }
inline bool begin(uint8_t gain, uint8_t itime, uint8_t addr = 0x43) {
  Wire.begin();
  if (inst()) { delete inst(); inst() = nullptr; }
  inst() = new emakefun::ColorSensorNlcs11(
      static_cast<emakefun::ColorSensorNlcs11::Gain>(gain),
      static_cast<emakefun::ColorSensorNlcs11::IntegrationTime>(itime),
      addr, Wire);
  return inst()->Initialize() == emakefun::ColorSensorNlcs11::kOK;
}
inline bool sample() { return inst() ? inst()->GetColor(&last()) : false; }
inline uint16_t r() { return last().r; }
inline uint16_t g() { return last().g; }
inline uint16_t b() { return last().b; }
inline uint16_t c() { return last().c; }
}
