/*
 * Function: FUN_010207d4
 * Entry:    010207d4
 * Prototype: undefined __stdcall FUN_010207d4(undefined4 param_1, undefined4 param_2, undefined4 param_3)
 */


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_010207d4(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  uint uVar2;
  
  if ((char)DAT_210014dc != '\0') {
    uVar1 = Peripherals::AAR_NS.EVENTS_RESOLVED;
    if (uVar1 == 0) {
      Peripherals::AAR_NS.INTENSET = 2;
      uVar2 = _DAT_e000ed10 & 0x10;
      _DAT_e000ed10 = _DAT_e000ed10 | 0x10;
      uVar1 = Peripherals::AAR_NS.EVENTS_RESOLVED;
      while (uVar1 == 0) {
        _DAT_e000e280 = 0x4000;
        FUN_0102aa1e();
        uVar1 = Peripherals::AAR_NS.EVENTS_RESOLVED;
      }
      if (uVar2 == 0) {
        _DAT_e000ed10 = _DAT_e000ed10 & 0xffffffef;
      }
      Peripherals::AAR_NS.INTENCLR = 2;
    }
    return;
  }
  FUN_01009500(0x3c,0x280,param_3,0);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


