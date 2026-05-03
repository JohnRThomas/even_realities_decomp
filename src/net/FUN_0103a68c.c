/*
 * Function: FUN_0103a68c
 * Entry:    0103a68c
 * Prototype: undefined4 __stdcall FUN_0103a68c(int param_1, int param_2, int * param_3, uint * param_4, uint param_5, int param_6)
 */


undefined4 FUN_0103a68c(int param_1,int param_2,int *param_3,uint *param_4,uint param_5,int param_6)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  if (param_2 == 0) {
    uVar1 = 0xfffffffe;
  }
  else if ((param_3 == (int *)0x0) || (param_4 == (uint *)0x0)) {
    uVar1 = 0xffffffea;
  }
  else {
    uVar3 = param_6 + (uint)(0xfffffffe < param_5);
    if (uVar3 == 0 && (1 < param_5 + 1) <= uVar3) {
      if ((*param_4 == 0) ||
         (uVar3 = *(uint *)(*(int *)(param_1 + 0x10) + 0x380), *param_4 <= uVar3)) {
        do {
          iVar2 = FUN_0103b5bc(param_2,(int)param_4);
          if (iVar2 != 0) {
            *param_3 = iVar2;
            return 0;
          }
        } while (param_6 == -1 && param_5 == 0xffffffff);
        uVar1 = 0xffffff97;
      }
      else {
        uVar1 = 0xfffffff4;
        *param_4 = uVar3;
      }
    }
    else {
      uVar1 = 0xffffff7a;
    }
  }
  return uVar1;
}


