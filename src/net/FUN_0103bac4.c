/*
 * Function: FUN_0103bac4
 * Entry:    0103bac4
 * Prototype: longlong * __stdcall FUN_0103bac4(longlong * param_1, undefined4 param_2, uint param_3, int param_4)
 */


longlong * FUN_0103bac4(longlong *param_1,undefined4 param_2,uint param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  longlong lVar3;
  
  if (param_4 == -1 && param_3 == 0xffffffff) {
    uVar2 = 0xffffffff;
  }
  else {
    if (param_3 != 0 || param_4 != 0) {
      iVar1 = (-1 - param_4) - (uint)(0xfffffffe < param_3);
      lVar3 = CONCAT44(iVar1,-2 - param_3);
      if (iVar1 < 0) {
        lVar3 = FUN_01038a44();
        lVar3 = lVar3 + CONCAT44(param_4,param_3);
      }
      goto LAB_0103baf8;
    }
    uVar2 = 0;
  }
  lVar3 = CONCAT44(uVar2,uVar2);
LAB_0103baf8:
  *param_1 = lVar3;
  return param_1;
}


