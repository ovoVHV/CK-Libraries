#pragma once
#include <Arduino.h>
#include <midi.h>
#ifndef ESP32
#include <SoftwareSerial.h>
#endif

namespace EmakefunMidiAdapter {
#ifndef ESP32
inline SoftwareSerial*& ser() { static SoftwareSerial* s = nullptr; return s; }
#endif
inline em::Midi*& inst() { static em::Midi* p = nullptr; return p; }
inline void begin(uint8_t rxPin, uint8_t txPin) {
  if (inst()) { delete inst(); inst() = nullptr; }
#ifndef ESP32
  if (ser()) { delete ser(); ser() = nullptr; }
  ser() = new SoftwareSerial(rxPin, txPin);
  ser()->begin(31250);
  inst() = new em::Midi(*ser());
#else
  Serial2.begin(31250, SERIAL_8N1, rxPin, txPin);
  inst() = new em::Midi(Serial2);
#endif
}
inline void setTimbre(uint8_t ch, uint8_t bank, uint8_t timbre) { if (inst()) inst()->SetChannelTimbre(ch, bank, timbre); }
inline void setVolume(uint8_t ch, uint8_t vol) { if (inst()) inst()->SetChannelVolume(ch, vol); }
inline void noteOn(uint8_t ch, uint8_t note, uint8_t vel) { if (inst()) inst()->NoteOn(ch, note, vel); }
inline void noteOff(uint8_t ch, uint8_t note) { if (inst()) inst()->NoteOff(ch, note); }
inline void allOff(uint8_t ch) { if (inst()) inst()->ChannelAllNotesOff(ch); }
inline void reset() { if (inst()) inst()->MidiReset(); }
}
