#pragma once
#include <Arduino.h>
#include <temperature_sensor_nl50.h>

namespace EmakefunNl50Adapter {
inline emakefun::TemperatureSensorNl50*& inst() { static emakefun::TemperatureSensorNl50* p = nullptr; return p; }
inline void begin(uint8_t pin) {
  if (inst()) { delete inst(); inst() = nullptr; }
  inst() = new emakefun::TemperatureSensorNl50(pin);
  inst()->Initialize();
}
inline float readC() { return inst() ? inst()->Read() : 0.0f; }
}
