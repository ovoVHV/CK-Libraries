{
  "format": "ck-project",
  "schema_version": 1,
  "migration_version": 1,
  "name": "Emakefun ASR 串口语音识别 演示",
  "options": "{}",
  "board": "arduino:avr:uno",
  "board_package_id": "arduino:avr:uno",
  "xml": "{\"blocks\": {\"languageVersion\": 0, \"blocks\": [{\"type\": \"controls_setup_custom\", \"id\": \"emakefun_asr_serial-setup\", \"inputs\": {\"DO\": {\"block\": {\"type\": \"emakefun_asr_serial_begin\", \"id\": \"emakefun_asr_serial-init\", \"inputs\": {\"RX\": {\"shadow\": {\"type\": \"math_number\", \"fields\": {\"NUM\": 2}}}, \"TX\": {\"shadow\": {\"type\": \"math_number\", \"fields\": {\"NUM\": 3}}}}}}}, \"x\": 36, \"y\": 38}, {\"type\": \"controls_loop_custom\", \"id\": \"emakefun_asr_serial-loop\", \"inputs\": {\"DO\": {\"block\": {\"type\": \"controls_delay\", \"id\": \"w1\", \"inputs\": {\"DELAY_TIME\": {\"shadow\": {\"type\": \"math_number\", \"fields\": {\"NUM\": 200}}}}}}}, \"x\": 420, \"y\": 38}]}}"
}
