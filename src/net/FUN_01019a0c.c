/*
 * Function: FUN_01019a0c
 * Entry:    01019a0c
 * Prototype: uint __stdcall FUN_01019a0c(int param_1, int param_2, undefined4 param_3)
 */


uint FUN_01019a0c(int param_1,int param_2,undefined4 param_3)

{
  undefined4 extraout_r2;
  uint uVar1;
  uint extraout_r3;
  
  uVar1 = (uint)DAT_21001000;
  if (uVar1 == 3) {
    uVar1 = param_1 - 2;
    if (uVar1 < 2) {
      if (param_2 != 0) {
        uVar1 = FUN_01019ee0();
      }
      DAT_2100104a = 0;
      DAT_21001000 = 0;
      DAT_2100104c = 0;
      return uVar1;
    }
    FUN_01009500(0x32,0xc52,param_3,3);
    param_3 = extraout_r2;
    uVar1 = extraout_r3;
  }
  FUN_01009500(0x32,0xc44,param_3,uVar1);
  if (DAT_21000ff4 != 0) {
    DAT_21000ff4 = 0;
    DAT_21000ff9 = 0;
    Peripherals::DPPIC_NS.CHENCLR = 1 << DAT_21000ff8;
    return 0;
  }
  return 0xc;
}


