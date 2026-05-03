/*
 * Function: FUN_01018950
 * Entry:    01018950
 * Prototype: undefined4 __stdcall FUN_01018950(undefined * param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 */


undefined4 FUN_01018950(undefined *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if ((DAT_21000ff9 == '\0') && (DAT_21000ff4 != (uint *)0x0)) {
    param_1 = (undefined *)FUN_01023250((uint)DAT_21000ff8,DAT_21000ff4,0,param_4);
  }
  switch(DAT_21001000) {
  case 0:
  case 1:
  case 3:
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
  case 2:
    uVar1 = 0;
    FUN_0101877c();
    break;
  case 4:
    if (DAT_21001038 != '\0') {
      FUN_01017714(1);
      DAT_21001000 = 8;
      return 0;
    }
    FUN_01017714(0);
    DAT_21001000 = 7;
    return 0;
  default:
    uVar1 = 0xc;
  }
  return uVar1;
}


