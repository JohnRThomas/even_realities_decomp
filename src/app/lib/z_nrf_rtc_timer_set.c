/*
 * Function: z_nrf_rtc_timer_set
 * Entry:    00066a20
 * Prototype: int __stdcall z_nrf_rtc_timer_set(int32_t chan, uint64_t target_time, z_nrf_rtc_timer_compare_handler_t handler, void * user_data)
 */


/* exclude_from_export */

int z_nrf_rtc_timer_set(int32_t chan,uint64_t target_time,z_nrf_rtc_timer_compare_handler_t handler,
                       void *user_data)

{
  int iVar1;
  
  if (chan != 1) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","chan > 0 && chan < (1 + 1)",
            "WEST_TOPDIR/zephyr/drivers/timer/nrf_rtc_timer.c",397);
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  iVar1 = compare_set(1,target_time,handler,user_data,false);
  return iVar1;
}


