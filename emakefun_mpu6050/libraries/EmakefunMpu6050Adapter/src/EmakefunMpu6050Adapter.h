#pragma once
#include <Arduino.h>
#include <Wire.h>
#include <mpu6050.h>

namespace EmakefunMpu6050Adapter {
inline Mpu6050*& inst() { static Mpu6050* p = nullptr; return p; }
inline bool begin(uint8_t addr = 0x68) {
  Wire.begin();
  if (inst()) { delete inst(); inst() = nullptr; }
  inst() = new Mpu6050(addr);
  return inst()->Setup();
}
inline bool update() { return inst() ? inst()->UpdateMotionInfo() : false; }
inline float euler(uint8_t axis) {
  if (!inst()) return 0.0f;
  auto e = inst()->GetEuler();
  return axis == 0 ? e.yaw : (axis == 1 ? e.pitch : e.roll);
}
inline int16_t accel(uint8_t axis) {
  if (!inst()) return 0;
  auto a = inst()->GetAcceleration();
  return axis == 0 ? a.x : (axis == 1 ? a.y : a.z);
}
}
