/*
 * Function: FUN_010204f4
 * Entry:    010204f4
 * Prototype: undefined __stdcall FUN_010204f4(void)
 */


void FUN_010204f4(void)

{
  FUN_01020888(2);
  DAT_210014d8 = 1;
  Peripherals::AAR_NS.EVENTS_END = 0;
  Peripherals::AAR_NS.EVENTS_RESOLVED = 0;
  Peripherals::AAR_NS.EVENTS_NOTRESOLVED = 0;
  Peripherals::AAR_NS.TASKS_START = 1;
  return;
}


