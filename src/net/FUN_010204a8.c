/*
 * Function: FUN_010204a8
 * Entry:    010204a8
 * Prototype: undefined __stdcall FUN_010204a8(void)
 */


void FUN_010204a8(void)

{
  uint uVar1;
  
  if (DAT_210014d8 != '\0') {
    DAT_210014d9._0_1_ = 0;
    Peripherals::AAR_NS.SUBSCRIBE_START = 0;
    uVar1 = Peripherals::AAR_NS.EVENTS_END;
    if ((uVar1 == 0) || (uVar1 = Peripherals::AAR_NS.EVENTS_RESOLVED, uVar1 == 0)) {
      DAT_210014d9._0_1_ = 0;
      DAT_210014d9._1_1_ = 0x10;
    }
    else {
      uVar1 = Peripherals::AAR_NS.EVENTS_NOTRESOLVED;
      if (uVar1 == 0) {
        uVar1 = Peripherals::AAR_NS.STATUS;
        DAT_210014d9._0_1_ = 1;
        DAT_210014d9._1_1_ = (undefined1)uVar1;
      }
      else {
        DAT_210014d9._1_1_ = 0x10;
      }
    }
    DAT_210014d8 = '\0';
  }
  FUN_01020888(0);
  return;
}


