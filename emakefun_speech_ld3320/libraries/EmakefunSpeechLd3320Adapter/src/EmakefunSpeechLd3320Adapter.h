#pragma once
#include <Arduino.h>
#include <Wire.h>
#include <speech_recognizer.h>

namespace EmakefunSpeechLd3320Adapter {
inline emakefun::SpeechRecognizer*& inst() { static emakefun::SpeechRecognizer* p = nullptr; return p; }
inline bool begin(uint8_t addr = 0x30) {
  Wire.begin();
  if (inst()) { delete inst(); inst() = nullptr; }
  inst() = new emakefun::SpeechRecognizer(Wire, addr);
  return inst()->Initialize() == emakefun::SpeechRecognizer::kOK;
}
inline void setMode(uint8_t mode) { if (inst()) inst()->SetRecognitionMode(static_cast<emakefun::SpeechRecognizer::RecognitionMode>(mode)); }
inline void setTimeout(uint32_t ms) { if (inst()) inst()->SetTimeout(ms); }
inline void addKeyword(uint8_t idx, const String& kw) { if (inst()) inst()->AddKeyword(idx, kw); }
inline int16_t recognize() { return inst() ? inst()->Recognize() : -1; }
inline uint8_t event() { return inst() ? static_cast<uint8_t>(inst()->GetEvent()) : 0; }
}
