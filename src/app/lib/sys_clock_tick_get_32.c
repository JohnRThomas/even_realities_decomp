/*
 * Function: sys_clock_tick_get_32
 * Entry:    00089e40
 * Prototype: uint32_t __stdcall sys_clock_tick_get_32(void)
 */


/* exclude_from_export */

uint32_t sys_clock_tick_get_32(void)

{
  int64_t iVar1;
  
  iVar1 = sys_clock_tick_get();
  return (uint32_t)iVar1;
}


