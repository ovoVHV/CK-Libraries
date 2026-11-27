#ifndef EMAKEFUN_GESTURE_RECOGNIZER_H_
#define EMAKEFUN_GESTURE_RECOGNIZER_H_

#include <Wire.h>
#include <stdint.h>

namespace emakefun {

/**
 * @class GestureRecognizer
 * @brief 手势识别传感器
 */
class GestureRecognizer {
 public:
  /**
   * @brief 手势识别传感器默认I2C地址
   */
  static constexpr uint8_t kDefaultI2cAddress = 0x39; /**< 0x39: 默认I2C地址 */

  /**
   * @enum ErrorCode
   * @brief 错误码
   */
  enum ErrorCode : uint32_t {
    kOK = 0,                                  /**< 0：成功 */
    kI2cDataTooLongToFitInTransmitBuffer = 1, /**< 1：I2C数据太长，无法装入传输缓冲区 */
    kI2cReceivedNackOnTransmitOfAddress = 2,  /**< 2：在I2C发送地址时收到NACK */
    kI2cReceivedNackOnTransmitOfData = 3,     /**< 3：在I2C发送数据时收到NACK */
    kI2cOtherError = 4,                       /**< 4：其他I2C错误 */
    kI2cTimeout = 5,                          /**< 5：I2C通讯超时 */
    kInvalidParameter = 6,                    /**< 6：参数错误 */
    kUnknownError = 7,                        /**< 7: 未知错误*/
  };
  /**
   * @enum Gesture
   * @brief 手势类型
   */
  enum Gesture : uint8_t {
    kGestureNone = 0x0,           /**< 0x00: 无手势动作*/
    kGestureRightSwipe = 0x01,    /**< 0x01: 右移动作*/
    kGestureLeftSwipe = 0x02,     /**< 0x02: 左移动作*/
    kGestureBackwardSwipe = 0x03, /**< 0x03: 后移动作*/
    kGestureForwardSwipe = 0x04,  /**< 0x04: 前移动作*/
    kGestureUpward = 0x05,        /**< 0x05: 上拉动作*/
    kGestureDownward = 0x06,      /**< 0x06: 下压动作*/
    kGestureExited = 0x07,        /**< 0x07: 离开感应区*/
    kGestureHover = 0x08,         /**< 0x08: 悬停*/
  };

  /**
   * @brief 构造函数
   * @param [in] wire TwoWire对象，默认为Arduino Wire
   * @param [in] i2c_address 手势识别传感器I2C地址，默认值为0x39
   */
  explicit GestureRecognizer(TwoWire& wire = Wire, const uint8_t i2c_address = kDefaultI2cAddress);

  ErrorCode Initialize();

  /**
   * @brief 获取识别到的手势
   * @return 手势类型，参考枚举: @ref GestureRecognizer::Gesture
   */
  Gesture GetGesture();

 private:
  GestureRecognizer(const GestureRecognizer&) = delete;
  GestureRecognizer& operator=(const GestureRecognizer&) = delete;

  TwoWire& wire_ = Wire;
  const uint8_t i2c_address_ = kDefaultI2cAddress;
};
}  // namespace emakefun

#endif