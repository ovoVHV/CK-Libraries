#pragma once
#include <Arduino.h>
#include <Wire.h>
#include <color_sensor.h>

namespace EmakefunColorV1Adapter {
inline emakefun::ColorSensor*& inst() { static emakefun::ColorSensor* p = nullptr; return p; }
inline bool begin(uint8_t addr = 0x43) {
  Wire.begin();
  if (inst()) { delete inst(); inst() = nullptr; }
  inst() = new emakefun::ColorSensor(addr, Wire);
  return inst()->Initialize() == emakefun::ColorSensor::kOK;
}
inline uint8_t r() { return inst() ? inst()->R() : 0; }
inline uint8_t g() { return inst() ? inst()->G() : 0; }
inline uint8_t b() { return inst() ? inst()->B() : 0; }
}
