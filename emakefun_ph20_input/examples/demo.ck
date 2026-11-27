{
  "format": "ck-project",
  "schema_version": 1,
  "migration_version": 1,
  "name": "Emakefun PH2.0 基础输入模块 演示",
  "options": "{}",
  "board": "arduino:avr:uno",
  "board_package_id": "arduino:avr:uno",
  "xml": "{\"blocks\": {\"languageVersion\": 0, \"blocks\": [{\"type\": \"controls_setup_custom\", \"id\": \"emakefun_ph20_input-setup\", \"inputs\": {\"DO\": {\"block\": {\"type\": \"emakefun_ph20_input_enc_begin\", \"id\": \"emakefun_ph20_input-init\", \"inputs\": {\"CLK\": {\"shadow\": {\"type\": \"math_number\", \"fields\": {\"NUM\": 2}}}, \"DT\": {\"shadow\": {\"type\": \"math_number\", \"fields\": {\"NUM\": 3}}}}}}}, \"x\": 36, \"y\": 38}, {\"type\": \"controls_loop_custom\", \"id\": \"emakefun_ph20_input-loop\", \"inputs\": {\"DO\": {\"block\": {\"type\": \"controls_delay\", \"id\": \"w1\", \"inputs\": {\"DELAY_TIME\": {\"shadow\": {\"type\": \"math_number\", \"fields\": {\"NUM\": 200}}}}}}}, \"x\": 420, \"y\": 38}]}}"
}
