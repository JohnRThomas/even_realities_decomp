/*
 * Function: FUN_01021fac
 * Entry:    01021fac
 * Prototype: undefined __stdcall FUN_01021fac(undefined4 param_1, undefined4 param_2, uint param_3, undefined4 param_4)
 */


void FUN_01021fac(undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  uint extraout_r2;
  undefined8 uVar1;
  
  uVar1 = CONCAT44(param_2,param_1);
  if (0xfb < param_3) {
    uVar1 = FUN_01009500(0x26,0x2e6,param_3,param_4);
    param_3 = extraout_r2;
  }
  DAT_21001664 = (int)((ulonglong)uVar1 >> 0x20);
  DAT_21001668 = (int)uVar1;
  DAT_2100166c = (short)param_3;
  return;
}


