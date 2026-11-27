#pragma once
#include <Arduino.h>

namespace EmakefunRus04 {
inline uint8_t& ioPin() { static uint8_t p = 7; return p; }
inline uint8_t& rgbPin() { static uint8_t p = 6; return p; }
inline void begin(uint8_t io, uint8_t rgb) {
  ioPin() = io;
  rgbPin() = rgb;
  pinMode(io, OUTPUT);
  digitalWrite(io, LOW);
  pinMode(rgb, OUTPUT);
  digitalWrite(rgb, LOW);
}
inline float distanceCm(uint8_t pin) {
  pinMode(pin, OUTPUT);
  digitalWrite(pin, LOW);
  delayMicroseconds(2);
  digitalWrite(pin, HIGH);
  delayMicroseconds(12);
  digitalWrite(pin, LOW);
  pinMode(pin, INPUT);
  unsigned long dur = pulseIn(pin, HIGH, 30000UL);
  pinMode(pin, OUTPUT);
  digitalWrite(pin, LOW);
  if (dur == 0) return 0.0f;
  return dur * 0.017f;
}
inline float readDistance() { return distanceCm(ioPin()); }
inline void setProbeColor(uint8_t r, uint8_t g, uint8_t b) {
#ifdef ESP32
  rgbLedWrite(rgbPin(), r, g, b);
#else
  // Simple bit-bang for 6x WS2812B LEDs on 16MHz AVR (GRB order)
  uint8_t pin = rgbPin();
  pinMode(pin, OUTPUT);
  uint8_t mask = digitalPinToBitMask(pin);
  volatile uint8_t* out = portOutputRegister(digitalPinToPort(pin));
  uint8_t hi = *out | mask;
  uint8_t lo = *out & ~mask;
  uint8_t grb[3] = {g, r, b};
  noInterrupts();
  for (uint8_t led = 0; led < 6; ++led) {
    for (uint8_t c = 0; c < 3; ++c) {
      uint8_t val = grb[c];
      for (uint8_t bit = 0x80; bit; bit >>= 1) {
        if (val & bit) {
          *out = hi; __builtin_avr_delay_cycles(10);
          *out = lo; __builtin_avr_delay_cycles(4);
        } else {
          *out = hi; __builtin_avr_delay_cycles(4);
          *out = lo; __builtin_avr_delay_cycles(10);
        }
      }
    }
  }
  interrupts();
  delayMicroseconds(60);
#endif
}
}
