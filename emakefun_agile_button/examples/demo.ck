{
  "format": "ck-project",
  "schema_version": 1,
  "migration_version": 1,
  "name": "Emakefun 智能按键模块 演示",
  "options": "{}",
  "board": "arduino:avr:uno",
  "board_package_id": "arduino:avr:uno",
  "xml": "{\"blocks\": {\"languageVersion\": 0, \"blocks\": [{\"type\": \"controls_setup_custom\", \"id\": \"emakefun_agile_button-setup\", \"inputs\": {\"DO\": {\"block\": {\"type\": \"emakefun_agile_button_begin\", \"id\": \"emakefun_agile_button-init\", \"inputs\": {\"PIN\": {\"shadow\": {\"type\": \"math_number\", \"fields\": {\"NUM\": 2}}}}, \"fields\": {\"ACTIVE\": \"1\"}}}}, \"x\": 36, \"y\": 38}, {\"type\": \"controls_loop_custom\", \"id\": \"emakefun_agile_button-loop\", \"inputs\": {\"DO\": {\"block\": {\"type\": \"controls_delay\", \"id\": \"w1\", \"inputs\": {\"DELAY_TIME\": {\"shadow\": {\"type\": \"math_number\", \"fields\": {\"NUM\": 200}}}}}}}, \"x\": 420, \"y\": 38}]}}"
}
