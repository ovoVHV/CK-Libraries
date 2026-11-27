{
  "format": "ck-project",
  "schema_version": 1,
  "migration_version": 1,
  "name": "Emakefun PM2.5 粉尘传感器 演示",
  "options": "{}",
  "board": "arduino:avr:uno",
  "board_package_id": "arduino:avr:uno",
  "xml": "{\"blocks\": {\"languageVersion\": 0, \"blocks\": [{\"type\": \"controls_setup_custom\", \"id\": \"emakefun_pm25-setup\", \"inputs\": {\"DO\": {\"block\": {\"type\": \"emakefun_pm25_begin\", \"id\": \"emakefun_pm25-init\", \"inputs\": {\"ILED_PIN\": {\"shadow\": {\"type\": \"math_number\", \"fields\": {\"NUM\": 7}}}, \"DUST_PIN\": {\"shadow\": {\"type\": \"math_number\", \"fields\": {\"NUM\": 14}}}}}}}, \"x\": 36, \"y\": 38}, {\"type\": \"controls_loop_custom\", \"id\": \"emakefun_pm25-loop\", \"inputs\": {\"DO\": {\"block\": {\"type\": \"controls_delay\", \"id\": \"w1\", \"inputs\": {\"DELAY_TIME\": {\"shadow\": {\"type\": \"math_number\", \"fields\": {\"NUM\": 200}}}}}}}, \"x\": 420, \"y\": 38}]}}"
}
