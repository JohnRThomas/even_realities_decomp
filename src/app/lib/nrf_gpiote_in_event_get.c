/*
 * Function: nrf_gpiote_in_event_get
 * Entry:    00068894
 * Prototype: nrf_gpiote_event_t __stdcall nrf_gpiote_in_event_get(uint8_t index)
 */


/* exclude_from_export */

nrf_gpiote_event_t nrf_gpiote_in_event_get(uint8_t index)

{
  if (7 < index) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","index < 8",
            "WEST_TOPDIR/modules/hal/nordic/nrfx/hal/nrf_gpiote.h",682);
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  return (uint)index * 4 + 0x100;
}


