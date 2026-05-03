/*
 * Function: FUN_0100d310
 * Entry:    0100d310
 * Prototype: uint __stdcall FUN_0100d310(void)
 */


uint FUN_0100d310(void)

{
  uint uVar1;
  bool bVar2;
  
  bVar2 = FUN_01020520();
  if (!bVar2) {
    return 0xff;
  }
  if (DAT_210014d8 != '\0') {
    uVar1 = Peripherals::AAR_NS.EVENTS_END;
    if (((uVar1 != 0) && (uVar1 = Peripherals::AAR_NS.EVENTS_RESOLVED, uVar1 != 0)) &&
       (uVar1 = Peripherals::AAR_NS.EVENTS_NOTRESOLVED, uVar1 == 0)) {
      uVar1 = Peripherals::AAR_NS.STATUS;
      return uVar1 & 0xff;
    }
    return 0x10;
  }
  return (uint)DAT_210014d9._1_1_;
}


