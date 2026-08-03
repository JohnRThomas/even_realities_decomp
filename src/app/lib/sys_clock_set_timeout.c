/*
 * Function: sys_clock_set_timeout
 * Entry:    00066b84
 * Prototype: void __stdcall sys_clock_set_timeout(int32_t ticks, bool idle)
 */


/* exclude_from_export */

void sys_clock_set_timeout(int32_t ticks,bool idle)

{
  uint uVar1;
  uint64_t uVar2;
  
  if (ticks == -1) {
    ticks = 0x7fffff;
  }
  else if (ticks < 2) {
    ticks = 1;
  }
  else if (0x7ffffe < ticks) {
    ticks = 0x7fffff;
  }
  uVar2 = z_nrf_rtc_timer_read();
  uVar1 = (int)uVar2 - DAT_20006890;
  if (0x7fffff < uVar1) {
    ticks = 0;
  }
  uVar1 = ticks + uVar1;
  if (0x7ffffe < uVar1) {
    uVar1 = 0x7fffff;
  }
  compare_set(0,CONCAT44(DAT_20006894 + (uint)CARRY4(uVar1,DAT_20006890),uVar1 + DAT_20006890),
              (z_nrf_rtc_timer_compare_handler_t)0x66785,(void *)0x0,false);
  return;
}


