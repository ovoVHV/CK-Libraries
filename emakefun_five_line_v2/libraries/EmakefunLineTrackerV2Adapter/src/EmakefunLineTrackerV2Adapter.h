#pragma once
#include <Arduino.h>
#include <Wire.h>
#include <line_tracker.h>

namespace EmakefunLineTrackerV2Adapter {
inline LineTracker*& inst() { static LineTracker* p = nullptr; return p; }
inline void begin(uint8_t addr = 0x50) {
  Wire.begin();
  if (inst()) { delete inst(); inst() = nullptr; }
  inst() = new LineTracker(addr);
}
inline void setSensitivity(uint16_t s) { if (inst()) inst()->SetSensitivity(s); }
inline uint16_t value(uint8_t ch) { return (inst() && ch < 5) ? inst()->GetSensorValue(ch) : 0; }
inline bool onBlack(uint8_t ch) { return (inst() && ch < 5) ? inst()->GetSensorState(ch) : false; }
inline uint8_t states() { return inst() ? inst()->GetSensorStates() : 0; }
}
