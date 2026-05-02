/*
 * Function: FUN_0004aa00
 * Entry:    0004aa00
 * Prototype: undefined __stdcall FUN_0004aa00(uint param_1, int param_2, undefined4 param_3)
 */


void FUN_0004aa00(uint param_1,int param_2,undefined4 param_3)

{
  int extraout_r1;
  int iVar1;
  undefined4 extraout_r2;
  
  iVar1 = param_2;
  if (param_1 != DAT_2000aa3c) {
    FUN_00080d5e(param_1,param_2,param_3);
    iVar1 = extraout_r1;
    param_3 = extraout_r2;
    DAT_2000aa3c = param_1;
  }
  if (param_2 != DAT_2000aa38) {
    FUN_00080d46(param_2,iVar1,param_3);
    DAT_2000aa38 = param_2;
  }
  return;
}


