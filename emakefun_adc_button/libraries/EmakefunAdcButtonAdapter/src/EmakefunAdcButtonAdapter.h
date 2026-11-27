#pragma once
#include <Arduino.h>
#include <adc_button.h>

namespace EmakefunAdcButtonAdapter {
inline em::AdcButton*& inst() { static em::AdcButton* p = nullptr; return p; }
inline void begin(uint8_t pin) {
  if (inst()) { delete inst(); inst() = nullptr; }
  inst() = new em::AdcButton(pin);
}
inline void tick() { if (inst()) inst()->Tick(); }
inline uint8_t keyType() { return inst() ? static_cast<uint8_t>(inst()->GetButtonType()) : 0; }
inline bool isPressed(uint8_t key) { return inst() ? inst()->IsPressed(static_cast<em::AdcButton::ButtonType>(key)) : false; }
}
