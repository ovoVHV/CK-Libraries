#pragma once
#include <Arduino.h>
#include <pm25_sensor.h>

namespace EmakefunPm25Adapter {
inline em::Pm25Sensor*& inst() { static em::Pm25Sensor* p = nullptr; return p; }
inline void begin(uint8_t iledPin, uint8_t dustPin) {
  if (inst()) { delete inst(); inst() = nullptr; }
  inst() = new em::Pm25Sensor(iledPin, dustPin);
  inst()->Init();
}
inline float readUgM3() { return inst() ? inst()->Read() : 0.0f; }
}
