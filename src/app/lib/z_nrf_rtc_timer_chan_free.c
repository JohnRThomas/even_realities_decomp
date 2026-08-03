/*
 * Function: z_nrf_rtc_timer_chan_free
 * Entry:    00066b40
 * Prototype: void __stdcall z_nrf_rtc_timer_chan_free(int32_t chan)
 */


/* exclude_from_export */

void z_nrf_rtc_timer_chan_free(int32_t chan)

{
  if (chan == 1) {
    DAT_2000bcbc = DAT_2000bcbc | 2;
    return;
  }
  _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","chan > 0 && chan < (1 + 1)",
          "WEST_TOPDIR/zephyr/drivers/timer/nrf_rtc_timer.c",599);
                    /* WARNING: Subroutine does not return */
  k_panic();
}


