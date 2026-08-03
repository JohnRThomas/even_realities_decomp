/*
 * Function: z_nrf_rtc_timer_capture_task_address_get
 * Entry:    0006684c
 * Prototype: uint32_t __stdcall z_nrf_rtc_timer_capture_task_address_get(int32_t chan)
 */


/* exclude_from_export */

uint32_t z_nrf_rtc_timer_capture_task_address_get(int32_t chan)

{
  uint32_t uVar1;
  
  if (1 < (uint)chan) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","chan >= 0 && chan < (1 + 1)",
            "WEST_TOPDIR/zephyr/drivers/timer/nrf_rtc_timer.c",141);
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  uVar1 = 0x50015044;
  if (chan == 0) {
    uVar1 = 0;
  }
  return uVar1;
}


