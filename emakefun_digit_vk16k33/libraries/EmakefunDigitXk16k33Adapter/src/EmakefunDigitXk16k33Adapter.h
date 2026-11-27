#pragma once
#include <Arduino.h>
#include <Wire.h>
#include <digit_display_xk16k33.h>

namespace EmakefunDigitXk16k33Adapter {
inline emakefun::DigitDisplayXk16k33& inst() { static emakefun::DigitDisplayXk16k33 d; return d; }
inline bool begin() { Wire.begin(); return inst().Initialize() == emakefun::Xk16k33::kOK; }
inline void setBrightness(uint8_t b) { inst().SetBrightness(b); }
inline void setBlink(uint8_t rate) { inst().SetBlinkRate(static_cast<emakefun::Xk16k33::BlinkRate>(rate)); }
inline void showNumber(double v, uint8_t dec) { inst().ShowNumber(v, emakefun::DigitDisplayXk16k33::kDec, dec); inst().Display(); }
inline void showColon(bool on) { inst().ShowColon(on); inst().Display(); }
inline void clear() { inst().Clear(); inst().Display(); }
}
