{
  "format": "ck-project",
  "schema_version": 1,
  "migration_version": 1,
  "name": "Emakefun NLCS21 颜色传感器 演示",
  "options": "{}",
  "board": "arduino:avr:uno",
  "board_package_id": "arduino:avr:uno",
  "xml": "{\"blocks\": {\"languageVersion\": 0, \"blocks\": [{\"type\": \"controls_setup_custom\", \"id\": \"emakefun_color_nlcs21-setup\", \"inputs\": {\"DO\": {\"block\": {\"type\": \"emakefun_color_nlcs21_begin\", \"id\": \"emakefun_color_nlcs21-init\", \"inputs\": {\"ADDR\": {\"shadow\": {\"type\": \"math_number\", \"fields\": {\"NUM\": 56}}}}, \"fields\": {\"GAIN\": \"0\", \"ITIME\": \"3\"}}}}, \"x\": 36, \"y\": 38}, {\"type\": \"controls_loop_custom\", \"id\": \"emakefun_color_nlcs21-loop\", \"inputs\": {\"DO\": {\"block\": {\"type\": \"controls_delay\", \"id\": \"w1\", \"inputs\": {\"DELAY_TIME\": {\"shadow\": {\"type\": \"math_number\", \"fields\": {\"NUM\": 200}}}}}}}, \"x\": 420, \"y\": 38}]}}"
}
