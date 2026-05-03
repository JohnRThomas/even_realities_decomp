/*
 * Function: FUN_01020470
 * Entry:    01020470
 * Prototype: undefined __stdcall FUN_01020470(void)
 */


void FUN_01020470(void)

{
  FUN_01020888(2);
  DAT_210014d8 = 1;
  Peripherals::AAR_NS.EVENTS_END = 0;
  Peripherals::AAR_NS.EVENTS_RESOLVED = 0;
  Peripherals::AAR_NS.EVENTS_NOTRESOLVED = 0;
  Peripherals::AAR_NS.SUBSCRIBE_START = 0x80000003;
  return;
}


