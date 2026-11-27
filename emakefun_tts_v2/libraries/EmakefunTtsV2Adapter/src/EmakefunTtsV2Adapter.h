#pragma once
#include <Arduino.h>
#include <Wire.h>
#include <tts.h>

namespace EmakefunTtsV2Adapter {
inline emakefun::Tts*& inst() { static emakefun::Tts* p = nullptr; return p; }
inline bool begin(uint8_t addr = 0x40) {
  Wire.begin();
  if (inst()) { delete inst(); inst() = nullptr; }
  inst() = new emakefun::Tts(addr, Wire);
  return inst()->Initialize() == emakefun::Tts::kOK;
}
inline void play(const String& text, uint8_t enc = 4) {
  if (inst()) inst()->Play(text, static_cast<emakefun::Tts::TextEncodingType>(enc));
}
inline void pushCache(const String& text, uint8_t idx) { if (inst()) inst()->PushTextToCache(text, idx); }
inline void playCache(uint8_t count) { if (inst()) inst()->PlayFromCache(emakefun::Tts::kUtf8, count); }
inline void pause() { if (inst()) inst()->Pause(); }
inline void resume() { if (inst()) inst()->Resume(); }
inline void stop() { if (inst()) inst()->Stop(); }
}
