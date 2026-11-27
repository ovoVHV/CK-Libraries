#pragma once
#include <Arduino.h>

namespace EmakefunPh20Input {
inline bool readDigitalActive(uint8_t pin, bool activeLow) {
  pinMode(pin, activeLow ? INPUT_PULLUP : INPUT);
  int v = digitalRead(pin);
  return activeLow ? (v == LOW) : (v == HIGH);
}
inline int readAnalogVal(uint8_t pin) { return analogRead(pin); }
inline int readPercent(uint8_t pin) {
#ifdef ESP32
  return map(analogRead(pin), 0, 4095, 0, 100);
#else
  return map(analogRead(pin), 0, 1023, 0, 100);
#endif
}
struct EncoderState { uint8_t clk = 2, dt = 3; int lastClk = HIGH; long count = 0; };
inline EncoderState& enc() { static EncoderState e; return e; }
inline void encoderBegin(uint8_t clkPin, uint8_t dtPin) {
  enc().clk = clkPin; enc().dt = dtPin; enc().count = 0;
  pinMode(clkPin, INPUT_PULLUP); pinMode(dtPin, INPUT_PULLUP);
  enc().lastClk = digitalRead(clkPin);
}
inline void encoderTick() {
  int c = digitalRead(enc().clk);
  if (c != enc().lastClk && c == LOW) {
    if (digitalRead(enc().dt) != c) enc().count++; else enc().count--;
  }
  enc().lastClk = c;
}
inline long encoderCount() { return enc().count; }
}
