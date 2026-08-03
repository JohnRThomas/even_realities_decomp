/*
 * Function: log_core_init
 * Entry:    000507c8
 * Prototype: uint32_t __stdcall log_core_init(bool blocking, bool can_sleep)
 */


/* exclude_from_export_ai */

uint32_t log_core_init(bool blocking,bool can_sleep)

{
  uint32_t extraout_r0;
  
  panic_mode = 0;
  dropped_cnt = 0;
  buffered_cnt = 0;
  log_set_timestamp_func(0x825c1,0x8000);
  z_log_msg_init();
  return extraout_r0;
}


