# CK-Libraries（CK LAB 第三方标准积木库仓库）

本仓库收录面向 **CK LAB（V1.0.61+）** 的标准 `schema v2` 硬件积木库，当前已完整适配 **Emakefun（易创空间）全系列传感器、执行器、显示、语音/MIDI 与 PH2.0 通用模块（共 32 个积木库、154 个积木）**。

每个积木库均按 CK LAB 官方 `schema v2` 规范构建：
- 完整 8 段语义元数据（`ck-blocks.json` v2）与声明式代码生成规则（`blocks/ck-generator.json`），支持证据护照静态检查与安全运行边界校验；
- 内置品牌字段 `vendor: "Emakefun"`、离线品牌 Logo（`assets/emakefun.png`）与官方模块实物缩略图（`assets/icon.*`），在 CK LAB 库管理器中自动归入 **Emakefun** 品牌分类并离线展示；
- 打包官方上游 Arduino 驱动源码与薄适配器，经 `arduino-cli` 真实编译验证（Arduino Uno AVR + ESP32-S3）。

## 在 CK LAB 中一键在线导入

1. 打开 **CK LAB V1.0.61+**，进入左侧 **「积木与库」→「在线获取」→「CK 积木库」**；
2. 平台选择 **GitHub**，仓库地址填入：
   ```text
   https://github.com/ovoVHV/CK-Libraries
   ```
3. 点击 **「读取仓库」**，顶部将自动出现 **Emakefun** 品牌分类标签及全部模块实物图；
4. 按需点击 **「安装」** 即可离线使用（支持当前开发板架构自动筛选）。

## Emakefun 全系列适配清单（共 32 个库）

### 一、Emakefun 专用传感器与输入模块（15 个）

| 积木库 ID | 名称 | 分类 | 支持架构 | 积木数 | 官方驱动 / 参考 |
| :--- | :--- | :--- | :--- | :---: | :--- |
| `emakefun_color_nlcs11` | Emakefun NLCS11 颜色传感器 | 传感器与输入模块 | AVR, ESP32 | 6 | [emakefun_color_sensor_nlcs11](https://github.com/emakefun-arduino-library/emakefun_color_sensor_nlcs11) |
| `emakefun_color_nlcs21` | Emakefun NLCS21 颜色传感器 | 传感器与输入模块 | AVR, ESP32 | 6 | [emakefun_color_sensor_nlcs21](https://github.com/emakefun-arduino-library/emakefun_color_sensor_nlcs21) |
| `emakefun_color_v1` | Emakefun 颜色识别传感器 V1 | 传感器与输入模块 | AVR, ESP32 | 4 | [emakefun_color_sensor](https://github.com/emakefun-arduino-library/emakefun_color_sensor) |
| `emakefun_gesture` | Emakefun 手势识别传感器 | 传感器与输入模块 | AVR, ESP32 | 4 | [emakefun_gesture_recognizer](https://github.com/emakefun-arduino-library/emakefun_gesture_recognizer) |
| `emakefun_mpu6050` | Emakefun MPU6050 六轴陀螺仪 | 传感器与输入模块 | AVR, ESP32 | 4 | [emakefun_mpu6050](https://github.com/emakefun-arduino-library/emakefun_mpu6050) |
| `emakefun_five_line_v3` | Emakefun 五路循迹传感器 V3 | 传感器与输入模块 | AVR, ESP32 | 6 | [emakefun_five_line_tracker_v3](https://github.com/emakefun-arduino-library/emakefun_five_line_tracker_v3) |
| `emakefun_five_line_v2` | Emakefun 五路循迹传感器 V2 | 传感器与输入模块 | AVR, ESP32 | 5 | [emakefun_five_line_tracker](https://github.com/emakefun-arduino-library/emakefun_five_line_tracker) |
| `emakefun_nl50_temp` | Emakefun NL50 温度传感器 | 传感器与输入模块 | AVR, ESP32 | 2 | [emakefun_temperature_sensor_nl50](https://github.com/emakefun-arduino-library/emakefun_temperature_sensor_nl50) |
| `emakefun_pm25` | Emakefun PM2.5 粉尘传感器 | 传感器与输入模块 | AVR, ESP32 | 2 | [em_pm25_sensor](https://github.com/emakefun-arduino-library/em_pm25_sensor) |
| `emakefun_speech_ld3320` | Emakefun LD3320 语音识别 V2 | 传感器与输入模块 | AVR, ESP32 | 6 | [emakefun_speech_recognizer](https://github.com/emakefun-arduino-library/emakefun_speech_recognizer) |
| `emakefun_asr_serial` | Emakefun ASR 串口语音识别 | 传感器与输入模块 | AVR, ESP32 | 5 | [em_asr_speech_recognition](https://github.com/emakefun-arduino-library/em_asr_speech_recognition) |
| `emakefun_matrix_kbd_v3` | Emakefun 触摸矩阵键盘 V3 | 传感器与输入模块 | AVR, ESP32 | 5 | [emakefun_matrix_keyboard_v3](https://github.com/emakefun-arduino-library/emakefun_matrix_keyboard_v3) |
| `emakefun_matrix_kbd_v2` | Emakefun 触摸矩阵键盘 V2 | 传感器与输入模块 | AVR, ESP32 | 2 | [emakefun_matrix_keyboard](https://github.com/emakefun-arduino-library/emakefun_matrix_keyboard) |
| `emakefun_adc_button` | Emakefun ADC 五键模块 | 传感器与输入模块 | AVR, ESP32 | 4 | [em_adc_button](https://github.com/emakefun-arduino-library/em_adc_button) |
| `emakefun_agile_button` | Emakefun 智能按键模块 | 传感器与输入模块 | AVR, ESP32 | 5 | [emakefun_agile_button](https://github.com/emakefun-arduino-library/emakefun_agile_button) |

### 二、Emakefun 语音 / MIDI / 电机驱动 / 显示与扩展模块（12 个）

| 积木库 ID | 名称 | 分类 | 支持架构 | 积木数 | 官方驱动 / 参考 |
| :--- | :--- | :--- | :--- | :---: | :--- |
| `emakefun_tts20` | Emakefun TTS20 语音合成模块 | Communication | AVR, ESP32 | 6 | [em_tts20](https://github.com/emakefun-arduino-library/em_tts20) |
| `emakefun_tts_v2` | Emakefun 语音合成模块 V2 | Communication | AVR, ESP32 | 5 | [emakefun_tts](https://github.com/emakefun-arduino-library/emakefun_tts) |
| `emakefun_midi` | Emakefun MIDI 音乐合成器 | Device Control | AVR, ESP32 | 6 | [em_midi](https://github.com/emakefun-arduino-library/em_midi) |
| `emakefun_dm11` | Emakefun DM11 双路电机驱动 | Device Control | AVR, ESP32 | 4 | [em_dm11](https://github.com/emakefun-arduino-library/em_dm11) |
| `emakefun_md20` | Emakefun MD20 四路编码电机 | Device Control | AVR, ESP32 | 4 | [em_md20](https://github.com/emakefun-arduino-library/em_md20) |
| `emakefun_md40` | Emakefun MD40 四路电机驱动板 | Device Control | AVR, ESP32 | 9 | [em_md40](https://github.com/emakefun-arduino-library/em_md40) |
| `emakefun_encoder_board` | Emakefun 编码电机驱动板 | Device Control | AVR, ESP32 | 7 | [emakefun_encoder_motor_board](https://github.com/emakefun-arduino-library/emakefun_encoder_motor_board) |
| `emakefun_gpio_board` | Emakefun I2C GPIO 扩展板 | Device Control | AVR, ESP32 | 7 | [emakefun_gpio_expansion_board](https://github.com/emakefun-arduino-library/emakefun_gpio_expansion_board) |
| `emakefun_digit_vk16k33` | Emakefun VK16K33 四位数码管 | 显示与灯光模块 | AVR, ESP32 | 5 | [emakefun_digit_display_xk16k33](https://github.com/emakefun-arduino-library/emakefun_digit_display_xk16k33) |
| `emakefun_digit_tm1650` | Emakefun 四位数码管 V1 | 显示与灯光模块 | AVR, ESP32 | 5 | [emakefun_digit_display](https://github.com/emakefun-arduino-library/emakefun_digit_display) |
| `emakefun_esp32_servo` | Emakefun ESP32 舵机驱动 | Device Control | ESP32 | 3 | [em_esp32_servo](https://github.com/emakefun-arduino-library/em_esp32_servo) |
| `emakefun_esp32_encoder` | Emakefun ESP32 编码电机 | Device Control | ESP32 | 6 | [em_esp32_encoder_motor](https://github.com/emakefun-arduino-library/em_esp32_encoder_motor) |

### 三、Emakefun RUS-04 炫彩超声波与 PH2.0 通用模块套件（5 个）

| 积木库 ID | 名称 | 分类 | 支持架构 | 积木数 | 官方驱动 / 参考 |
| :--- | :--- | :--- | :--- | :---: | :--- |
| `emakefun_rus04` | Emakefun RUS-04 RGB 超声波 | 传感器与输入模块 | AVR, ESP32 | 3 | [emakefun-docs](https://github.com/emakefun/emakefun-docs) |
| `emakefun_ph20_input` | Emakefun PH2.0 基础输入模块 | 传感器与输入模块 | AVR, ESP32 | 7 | [emakefun-docs](https://github.com/emakefun/emakefun-docs) |
| `emakefun_ph20_sensors` | Emakefun PH2.0 环境与光声传感器 | 传感器与输入模块 | AVR, ESP32 | 3 | [emakefun-docs](https://github.com/emakefun/emakefun-docs) |
| `emakefun_ph20_actuators` | Emakefun PH2.0 基础执行器模块 | Device Control | AVR, ESP32 | 5 | [emakefun-docs](https://github.com/emakefun/emakefun-docs) |
| `emakefun_ph20_display` | Emakefun PH2.0 灯光与交通灯模块 | 显示与灯光模块 | AVR, ESP32 | 3 | [emakefun-docs](https://github.com/emakefun/emakefun-docs) |

## 版权与上游致谢

- CK 积木描述、适配器与元数据采用 **Apache-2.0** 协议发布；
- 各模块内嵌的上游 Arduino 驱动库与产品参考资料来自 Emakefun 官方开源仓库：[emakefun-arduino-library](https://github.com/emakefun-arduino-library) 与 [emakefun/emakefun-docs](https://github.com/emakefun/emakefun-docs)，均保留其原始许可与版权声明。
