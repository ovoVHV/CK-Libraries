/**
 * @file md20.h
 */
#pragma once

#ifndef _EM_MD20_H_
#define _EM_MD20_H_

#include <WString.h>
#include <Wire.h>
#include <stdint.h>

namespace em {

class Md20 {
 public:
  static constexpr uint8_t kDefaultI2cAddress = 0x16;

  static constexpr uint8_t kMotorNum = 4;

  /**
   * @~Chinese
   * @enum ErrorCode
   * @brief 错误码。
   */
  /**
   * @~English
   * @enum ErrorCode
   * @brief Error codes.
   */
  enum ErrorCode : uint32_t {
    /**
     * @~Chinese
     * @brief 成功。
     */
    /**
     * @~English
     * @brief Success.
     */
    kOK = 0,

    /**
     * @~Chinese
     * @brief I2C数据太长，无法装入传输缓冲区。
     */
    /**
     * @~English
     * @brief I2C data too long to fit in transmit buffer.
     */
    kI2cDataTooLongToFitInTransmitBuffer = 1,

    /**
     * @~Chinese
     * @brief 在I2C发送地址时收到NACK。
     */
    /**
     * @~English
     * @brief NACK received on I2C transmit of address.
     */
    kI2cReceivedNackOnTransmitOfAddress = 2,

    /**
     * @~Chinese
     * @brief 在I2C发送数据时收到NACK。
     */
    /**
     * @~English
     * @brief NACK received on I2C transmit of data.
     */
    kI2cReceivedNackOnTransmitOfData = 3,

    /**
     * @~Chinese
     * @brief 其他I2C错误。
     */
    /**
     * @~English
     * @brief Other I2C errors.
     */
    kI2cOtherError = 4,

    /**
     * @~Chinese
     * @brief I2C通讯超时。
     */
    /**
     * @~English
     * @brief I2C communication timed out.
     */
    kI2cTimeout = 5,

    /**
     * @~Chinese
     * @brief 参数错误。
     */
    /**
     * @~English
     * @brief Invalid parameter.
     */
    kInvalidParameter = 6,

    /**
     * @~Chinese
     * @brief 未知错误。
     */
    /**
     * @~English
     * @brief Unknown error.
     */
    kUnknownError = 7,
  };

  enum State : uint8_t {
    kIdle = 0,
    kRuningWithPwmDuty = 1,
    kRuningWithSpeed = 2,
    kRuningToPosition = 3,
    kReachedPosition = 4,
  };

  enum PhaseRelation : uint8_t {
    kAPhaseLeads = 0,
    kBPhaseLeads = 1,
  };

  class Motor {
    friend Md20;

   public:
    ErrorCode Init(const uint16_t ppr, const uint16_t reduction_ration, const PhaseRelation phase_relation);
    ErrorCode Reset();
    ErrorCode RunSpeed(const int32_t speed);

   private:
    Motor(const Motor&) = delete;
    Motor& operator=(const Motor&) = delete;
    Motor(const uint8_t index, const uint8_t i2c_address, TwoWire& wire)
        : index_(index), i2c_address_(i2c_address), wire_(wire) {
    }
    ErrorCode WaitCommandEmptied();
    const uint8_t index_ = 0;
    const uint8_t i2c_address_ = 0;
    TwoWire& wire_ = Wire;
  };

  /**
   * @~Chinese
   * @brief 构造函数，指定 I2C 地址和 TwoWire 对象。
   * @param i2c_address I2C 地址，默认为 @ref kDefaultI2cAddress 。
   * @param wire TwoWire 对象引用，默认为 Wire。
   */
  /**
   * @~English
   * @brief Constructor, specifying I2C address and TwoWire object.
   * @param i2c_address I2C address, defaults to @ref kDefaultI2cAddress.
   * @param wire TwoWire object reference, defaults to Wire.
   */
  explicit Md20(const uint8_t i2c_address = kDefaultI2cAddress, TwoWire& wire = Wire);

  /**
   * @~Chinese
   * @brief 构造函数，使用默认 I2C 地址和指定的 TwoWire 对象。
   * @param wire TwoWire 对象引用。
   */
  /**
   * @~English
   * @brief Constructor using the default I2C address and a specified TwoWire object.
   * @param wire TwoWire object reference.
   */
  explicit Md20(TwoWire& wire) : Md20(kDefaultI2cAddress, wire) {
  }

  /**
   * @~Chinese
   * @brief 初始化函数，对设备进行初始化
   * @return 返回值请参考 @ref ErrorCode 。
   */
  /**
   * @~English
   * @brief Initialization function to initialize the device.
   * @return Please refer to @ref ErrorCode for the return value.
   */
  ErrorCode Init();

  Motor& operator[](const size_t pos) {
    return *motors_[pos];
  }

 private:
  Md20(const Md20&) = delete;
  Md20& operator=(const Md20&) = delete;

  const uint8_t i2c_address_ = kDefaultI2cAddress;
  TwoWire& wire_ = Wire;
  Motor* motors_[kMotorNum] = {nullptr};
};
}  // namespace em
#endif