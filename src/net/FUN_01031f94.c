/*
 * Function: FUN_01031f94
 * Entry:    01031f94
 * Prototype: undefined __stdcall FUN_01031f94(void)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01031f94(void)

{
  Peripherals::RTC1_NS.TASKS_STOP = 1;
  FUN_0102f308('\x16');
  Peripherals::RTC1_NS.INTENCLR = 0xf0003;
  Peripherals::RTC1_NS.EVTENCLR = 0xf0003;
  _DAT_e000e280 = 0x400000;
  return;
}


