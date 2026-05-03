/*
 * Function: FUN_0102079c
 * Entry:    0102079c
 * Prototype: uint __stdcall FUN_0102079c(undefined4 param_1, undefined4 param_2, undefined4 param_3)
 */


uint FUN_0102079c(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  AAR_NS *pAVar3;
  AAR_NS *extraout_r3;
  
  if ((char)DAT_210014dc == '\0') {
    FUN_01009500(0x3c,0x274,param_3,0);
    uVar1 = extraout_r2;
    pAVar3 = extraout_r3;
  }
  else {
    pAVar3 = &Peripherals::AAR_NS;
    uVar2 = Peripherals::AAR_NS.EVENTS_RESOLVED;
    uVar1 = 0;
    if (uVar2 != 0) {
      uVar2 = Peripherals::AAR_NS.STATUS;
      return (uint)(uVar2 != 0);
    }
  }
  uVar1 = FUN_01009500(0x3c,0x275,uVar1,pAVar3);
  uVar2 = FUN_010207d4(uVar1,0,extraout_r2_00);
  return uVar2;
}


