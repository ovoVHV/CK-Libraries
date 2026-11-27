#pragma once
#include <Arduino.h>
#include <Wire.h>
#include <five_line_tracker_v3.h>

namespace EmakefunLineTrackerV3Adapter {
inline emakefun::FiveLineTracker*& inst() { static emakefun::FiveLineTracker* p = nullptr; return p; }
inline bool begin(uint8_t addr = 0x50) {
  Wire.begin();
  if (inst()) { delete inst(); inst() = nullptr; }
  inst() = new emakefun::FiveLineTracker(Wire, addr);
  return inst()->Initialize() == emakefun::FiveLineTracker::kOK;
}
inline void setHigh(uint8_t ch, uint16_t v) { if (inst() && ch < 5) inst()->HighThreshold(ch, v); }
inline void setLow(uint8_t ch, uint16_t v) { if (inst() && ch < 5) inst()->LowThreshold(ch, v); }
inline uint16_t analogVal(uint8_t ch) { return (inst() && ch < 5) ? inst()->AnalogValue(ch) : 0; }
inline bool digitalVal(uint8_t ch) { return (inst() && ch < 5) ? (inst()->DigitalValue(ch) != 0) : false; }
inline uint8_t mask() { return inst() ? inst()->DigitalValues() : 0; }
}
