/*
 * Function: FUN_01027a58
 * Entry:    01027a58
 * Prototype: int __stdcall FUN_01027a58(undefined4 * param_1, uint param_2, undefined4 param_3)
 */


int FUN_01027a58(undefined4 *param_1,uint param_2,undefined4 param_3)

{
  undefined4 extraout_r2;
  int iVar1;
  
  if ((param_2 != 0) && (param_2 < 8)) {
    FUN_01009500(0x15,0x19a,param_3,param_2);
    param_3 = extraout_r2;
  }
  if (param_2 == 0) {
    if (param_1 != (undefined4 *)0x0) {
      *param_1 = 0;
    }
    iVar1 = 0;
  }
  else {
    if (param_1 != (undefined4 *)0x0) {
      if (0xffff < param_2) {
        FUN_01009500(0x15,0x1ac,param_3,param_2);
      }
      FUN_010279f6((undefined4 *)*param_1,(short)param_2);
    }
    iVar1 = param_2 + 4;
  }
  return iVar1;
}


