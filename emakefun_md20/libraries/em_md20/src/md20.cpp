/**
 * @file md20.cpp
 */
#include "md20.h"

#include <Arduino.h>

namespace em {

namespace {
enum Cmd : uint8_t {
  kReset = 1,
  kInit = 2,
  kSetSpeedP = 3,
  kSetSpeedI = 4,
  kSetSpeedD = 4,
  kSetPositionP = 6,
  kSetPositionI = 7,
  kSetPositionD = 8,
  kSetPosition = 9,
  kSetPulseCount = 10,
  kStop = 11,
  kRunPwmDuty = 12,
  kRunSpeed = 13,
  kMoveTo = 14,
  kMove = 15,
};

enum Address : uint8_t {
  kMajorVersion = 0x01,
  kMinorVersion = 0x02,
  kPathVersion = 0x03,

  kCmdTypeBegin = 0x10,

  kState = 0x60,
  kSpeedP = 0x62,
  kSpeedI = 0x64,
  kSpeedD = 0x66,
  kPositionP = 0x68,
  kPositionI = 0x6A,
  kPositionD = 0x6C,
  kSpeed = 0x70,
  kPosition = 0x74,
  kPulseCount = 0x78,
  kPwmDuty = 0x7C,
};

constexpr uint8_t kCmdOffset = 0x11;
constexpr uint8_t kMotorInfoOffset = 0x20;
}  // namespace

Md20::Md20(const uint8_t i2c_address, TwoWire& wire)
    : i2c_address_(i2c_address),
      wire_(wire),
      motors_{
          new Md20::Motor(0, i2c_address, wire),
          new Md20::Motor(1, i2c_address, wire),
          new Md20::Motor(2, i2c_address, wire),
          new Md20::Motor(3, i2c_address, wire),
      } {
}

Md20::ErrorCode Md20::Motor::Init(const uint16_t ppr, const uint16_t reduction_ration, const PhaseRelation phase_relation) {
  WaitCommandEmptied();
  wire_.beginTransmission(i2c_address_);
  wire_.write(kCmdTypeBegin + index_ * kCmdOffset);
  wire_.write(kInit);
  wire_.write(reinterpret_cast<const uint8_t*>(&ppr), sizeof(ppr));
  wire_.write(reinterpret_cast<const uint8_t*>(&reduction_ration), sizeof(reduction_ration));
  wire_.write(reinterpret_cast<const uint8_t*>(&phase_relation), sizeof(phase_relation));
  return static_cast<Md20::ErrorCode>(wire_.endTransmission());
}

Md20::ErrorCode Md20::Motor::Reset() {
  WaitCommandEmptied();
  wire_.beginTransmission(i2c_address_);
  wire_.write(kCmdTypeBegin + index_ * kCmdOffset);
  wire_.write(kReset);
  return static_cast<Md20::ErrorCode>(wire_.endTransmission());
}

Md20::ErrorCode Md20::Motor::RunSpeed(const int32_t speed) {
  WaitCommandEmptied();
  wire_.beginTransmission(i2c_address_);
  wire_.write(kCmdTypeBegin + index_ * kCmdOffset);
  wire_.write(kRunSpeed);
  wire_.write(reinterpret_cast<const uint8_t*>(&speed), sizeof(speed));
  return static_cast<Md20::ErrorCode>(wire_.endTransmission());
}

Md20::ErrorCode Md20::Motor::WaitCommandEmptied() {
loop:
  wire_.beginTransmission(i2c_address_);
  wire_.write(kCmdTypeBegin + index_ * kCmdOffset);
  auto error_code = static_cast<Md20::ErrorCode>(wire_.endTransmission());
  if (error_code != kOK) {
    return error_code;
  }

  if (1 != wire_.requestFrom(i2c_address_, static_cast<uint8_t>(1))) {
    return kUnknownError;
  }

  if (wire_.available() > 0) {
    if (0 == wire_.read()) {
      return kOK;
    } else {
      goto loop;
    }
  }
}

Md20::ErrorCode Md20::Init() {
  for (auto motor : motors_) {
    motor->Reset();
  }
  return kOK;
}

}  // namespace em