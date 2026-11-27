#pragma once
#include <Arduino.h>
#include <Wire.h>
#include <tts20.h>

namespace EmakefunTts20Adapter {
inline em::Tts20*& inst() { static em::Tts20* p = nullptr; return p; }
inline void begin(uint8_t addr = 0x40) {
  Wire.begin();
  if (inst()) { delete inst(); inst() = nullptr; }
  inst() = new em::Tts20(addr, Wire);
  inst()->Init();
}
inline void play(const String& text) { if (inst()) inst()->Play(text); }
inline bool isBusy() { return inst() ? inst()->IsBusy() : false; }
inline void pause() { if (inst()) inst()->Pause(); }
inline void resume() { if (inst()) inst()->Resume(); }
inline void stop() { if (inst()) inst()->Stop(); }
}
