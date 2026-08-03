/*
 * Function: k_cycle_get_32
 * Entry:    00088426
 * Prototype: uint32_t __stdcall k_cycle_get_32(void)
 */


/* exclude_from_export */

uint32_t k_cycle_get_32(void)

{
  uint64_t uVar1;
  
  uVar1 = z_nrf_rtc_timer_read();
  return (uint32_t)uVar1;
}


