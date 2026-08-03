/*
 * Function: z_nrf_rtc_timer_compare_read
 * Entry:    00066880
 * Prototype: uint32_t __stdcall z_nrf_rtc_timer_compare_read(int32_t chan)
 */


/* exclude_from_export */

uint32_t z_nrf_rtc_timer_compare_read(int32_t chan)

{
  if (1 < (uint)chan) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","chan >= 0 && chan < (1 + 1)",
            "WEST_TOPDIR/zephyr/drivers/timer/nrf_rtc_timer.c",195);
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  return (&Peripherals::RTC1_S.CC_0_)[chan];
}


