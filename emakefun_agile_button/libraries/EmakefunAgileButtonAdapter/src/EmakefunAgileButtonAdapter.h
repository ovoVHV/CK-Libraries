#pragma once
#include <Arduino.h>
#include <agile_button.h>

namespace EmakefunAgileButtonAdapter {
inline AgileButton*& inst() { static AgileButton* p = nullptr; return p; }
inline uint8_t& lastClicks() { static uint8_t c = 0; return c; }
inline bool& longPressed() { static bool lp = false; return lp; }
inline void onEvt(const AgileButton::Event& e) {
  if (e.event_type == AgileButton::kButtonClick) {
    lastClicks() = static_cast<const AgileButton::ButtonClickEvent&>(e).click_count;
  } else if (e.event_type == AgileButton::kButtonLongPressBegin) {
    longPressed() = true;
  }
}
inline void begin(uint8_t pin, uint8_t activeLow = 1) {
  if (inst()) { delete inst(); inst() = nullptr; }
  lastClicks() = 0;
  longPressed() = false;
  inst() = new AgileButton(pin, activeLow ? LOW : HIGH, activeLow ? INPUT_PULLUP : INPUT);
  inst()->SetEventHandler(onEvt);
}
inline void tick() { if (inst()) inst()->Tick(); }
inline bool takeClick(uint8_t count) {
  if (lastClicks() == count) { lastClicks() = 0; return true; }
  return false;
}
inline bool takeLongPress() {
  if (longPressed()) { longPressed() = false; return true; }
  return false;
}
}
