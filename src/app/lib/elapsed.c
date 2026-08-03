/*
 * Function: elapsed
 * Entry:    00077e10
 * Prototype: int32_t __stdcall elapsed(void)
 */


/* exclude_from_export */

int32_t elapsed(void)

{
  uint64_t uVar1;
  
  if (_current._68_4_ == 0) {
    uVar1 = z_nrf_rtc_timer_read();
    return (int)uVar1 - DAT_20006890;
  }
  return 0;
}


