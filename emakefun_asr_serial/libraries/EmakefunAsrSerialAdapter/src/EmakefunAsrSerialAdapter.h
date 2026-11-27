#pragma once
#include <Arduino.h>
#include <asr_speech_recognition.h>

namespace EmakefunAsrSerialAdapter {
#ifndef ESP32
inline SoftwareSerial*& ser() { static SoftwareSerial* s = nullptr; return s; }
#endif
inline em::AsrSpeechRecognition*& inst() { static em::AsrSpeechRecognition* p = nullptr; return p; }
inline void begin(uint8_t rxPin, uint8_t txPin) {
  if (inst()) { delete inst(); inst() = nullptr; }
#ifndef ESP32
  if (ser()) { delete ser(); ser() = nullptr; }
  ser() = new SoftwareSerial(rxPin, txPin);
  ser()->begin(9600);
  inst() = new em::AsrSpeechRecognition(*ser());
#else
  Serial2.begin(9600, SERIAL_8N1, rxPin, txPin);
  inst() = new em::AsrSpeechRecognition(Serial2);
#endif
}
inline void broadcast(uint8_t id) { if (inst()) inst()->broadcast_sound_operation(id); }
inline void setVolume(uint8_t vol) { if (inst()) inst()->set_volume_operation(vol); }
inline void playSound(uint8_t cmd) { if (inst()) inst()->play_sound_operation(cmd); }
inline void exitWakeup() { if (inst()) inst()->exit_wakeup_operation(); }
inline void reset() { if (inst()) inst()->reset_operation(); }
}
