/*
 * Function: FUN_010188e8
 * Entry:    010188e8
 * Prototype: undefined4 __stdcall FUN_010188e8(undefined * param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 */


undefined4 FUN_010188e8(undefined *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if ((DAT_21000ff9 == '\0') && (DAT_21000ff4 != (uint *)0x0)) {
    param_1 = (undefined *)FUN_01023250((uint)DAT_21000ff8,DAT_21000ff4,0,param_4);
  }
  if (1 < DAT_21001000) {
    if (DAT_21001000 == 2) {
      FUN_0101877c();
      return 0;
    }
    return 0xc;
  }
  if (DAT_2100100c != '\0') {
    FUN_010210b0();
    param_1 = (undefined *)FUN_010204a8();
    DAT_2100100c = '\0';
  }
  DAT_2100104a = 0;
  DAT_2100104c = 0;
  DAT_21001000 = 1;
  FUN_0101bcf4(param_1);
  return 0;
}


