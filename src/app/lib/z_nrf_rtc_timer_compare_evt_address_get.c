/*
 * Function: z_nrf_rtc_timer_compare_evt_address_get
 * Entry:    00066818
 * Prototype: uint32_t __stdcall z_nrf_rtc_timer_compare_evt_address_get(int32_t chan)
 */


/* exclude_from_export */

uint32_t z_nrf_rtc_timer_compare_evt_address_get(int32_t chan)

{
  if (1 < (uint)chan) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","chan >= 0 && chan < (1 + 1)",
            "WEST_TOPDIR/zephyr/drivers/timer/nrf_rtc_timer.c",134);
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  return chan * 4 + 0x50015140;
}


