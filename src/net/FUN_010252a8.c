/*
 * Function: FUN_010252a8
 * Entry:    010252a8
 * Prototype: undefined __stdcall FUN_010252a8(void)
 */


void FUN_010252a8(void)

{
  Peripherals::CLOCK_NS.TASKS_HFCLKSTOP = 1;
  Peripherals::CLOCK_NS.EVENTS_HFCLKSTARTED = 0;
  DAT_21001bf7 = 0;
  return;
}


