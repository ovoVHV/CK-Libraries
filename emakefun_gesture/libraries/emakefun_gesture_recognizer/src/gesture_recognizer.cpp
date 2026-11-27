#include "gesture_recognizer.h"

namespace emakefun {
namespace {
enum MemoryAddress : uint8_t {
  kMemoryAddressGesture = 0x01,
};
}

GestureRecognizer::GestureRecognizer(TwoWire& wire, const uint8_t i2c_address) : wire_(wire), i2c_address_(i2c_address) {
}

GestureRecognizer::ErrorCode GestureRecognizer::Initialize() {
  wire_.beginTransmission(i2c_address_);
  return static_cast<ErrorCode>(wire_.endTransmission());
}

GestureRecognizer::Gesture GestureRecognizer::GetGesture() {
  wire_.beginTransmission(i2c_address_);
  wire_.write(kMemoryAddressGesture);
  const auto ret = wire_.endTransmission();
  if (ret != 0) {
    return kGestureNone;
  }

  wire_.requestFrom(i2c_address_, static_cast<uint8_t>(1));
  if (wire_.available()) {
    return static_cast<GestureRecognizer::Gesture>(wire_.read());
  }
  return kGestureNone;
}
}  // namespace emakefun