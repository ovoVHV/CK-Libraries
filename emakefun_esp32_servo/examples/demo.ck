{
  "format": "ck-project",
  "schema_version": 1,
  "migration_version": 1,
  "name": "Emakefun ESP32 舵机驱动 演示",
  "options": "{}",
  "board": "esp32:esp32:esp32s3",
  "board_package_id": "esp32:esp32:esp32s3",
  "xml": "{\"blocks\": {\"languageVersion\": 0, \"blocks\": [{\"type\": \"controls_setup_custom\", \"id\": \"emakefun_esp32_servo-setup\", \"inputs\": {\"DO\": {\"block\": {\"type\": \"emakefun_esp32_servo_begin\", \"id\": \"emakefun_esp32_servo-init\", \"inputs\": {\"PIN\": {\"shadow\": {\"type\": \"math_number\", \"fields\": {\"NUM\": 4}}}}, \"fields\": {\"CH\": \"0\"}}}}, \"x\": 36, \"y\": 38}, {\"type\": \"controls_loop_custom\", \"id\": \"emakefun_esp32_servo-loop\", \"inputs\": {\"DO\": {\"block\": {\"type\": \"controls_delay\", \"id\": \"w1\", \"inputs\": {\"DELAY_TIME\": {\"shadow\": {\"type\": \"math_number\", \"fields\": {\"NUM\": 200}}}}}}}, \"x\": 420, \"y\": 38}]}}"
}
