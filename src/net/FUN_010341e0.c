/*
 * Function: FUN_010341e0
 * Entry:    010341e0
 * Prototype: undefined4 __stdcall FUN_010341e0(undefined4 * param_1)
 */


undefined4 FUN_010341e0(undefined4 *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 extraout_r1;
  
  if (DAT_21006458 == '\0') {
    if (param_1 == (undefined4 *)0x0) {
      uVar2 = 0xffffffea;
    }
    else {
      DAT_21000688 = *param_1;
      uVar1 = FUN_0103afcc(&DAT_21000688);
      Peripherals::RADIO_NS.BASE1 =
           uVar1 << 0x18 | (uVar1 >> 8 & 0xff) << 0x10 | (uVar1 >> 0x10 & 0xff) << 8 | uVar1 >> 0x18
      ;
      uVar2 = extraout_r1;
    }
  }
  else {
    uVar2 = 0xfffffff0;
  }
  return uVar2;
}


