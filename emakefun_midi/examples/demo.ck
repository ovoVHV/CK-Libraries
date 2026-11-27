{
  "format": "ck-project",
  "schema_version": 1,
  "migration_version": 1,
  "name": "Emakefun MIDI 音乐合成器 演示",
  "options": "{}",
  "board": "arduino:avr:uno",
  "board_package_id": "arduino:avr:uno",
  "xml": "{\"blocks\": {\"languageVersion\": 0, \"blocks\": [{\"type\": \"controls_setup_custom\", \"id\": \"emakefun_midi-setup\", \"inputs\": {\"DO\": {\"block\": {\"type\": \"emakefun_midi_begin\", \"id\": \"emakefun_midi-init\", \"inputs\": {\"RX\": {\"shadow\": {\"type\": \"math_number\", \"fields\": {\"NUM\": 2}}}, \"TX\": {\"shadow\": {\"type\": \"math_number\", \"fields\": {\"NUM\": 3}}}}}}}, \"x\": 36, \"y\": 38}, {\"type\": \"controls_loop_custom\", \"id\": \"emakefun_midi-loop\", \"inputs\": {\"DO\": {\"block\": {\"type\": \"controls_delay\", \"id\": \"w1\", \"inputs\": {\"DELAY_TIME\": {\"shadow\": {\"type\": \"math_number\", \"fields\": {\"NUM\": 200}}}}}}}, \"x\": 420, \"y\": 38}]}}"
}
