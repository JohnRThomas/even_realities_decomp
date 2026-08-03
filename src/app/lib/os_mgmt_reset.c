/*
 * Function: os_mgmt_reset
 * Entry:    00055700
 * Prototype: undefined4 __stdcall os_mgmt_reset(undefined4 param_1, undefined4 param_2)
 */


/* exclude_from_export */

undefined4 os_mgmt_reset(undefined4 param_1,undefined4 param_2)

{
  k_timeout_t duration;
  
  duration.ticks._4_4_ = 0x2000;
  duration.ticks._0_4_ = param_2;
  k_timer_start((k_timer *)&DAT_20003830,duration,(k_timeout_t)0x0);
  return 0;
}


