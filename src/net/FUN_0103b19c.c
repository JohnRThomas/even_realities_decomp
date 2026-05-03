/*
 * Function: FUN_0103b19c
 * Entry:    0103b19c
 * Prototype: undefined __stdcall FUN_0103b19c(int * param_1, uint param_2, undefined4 param_3, int param_4)
 */


void FUN_0103b19c(int *param_1,uint param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  
  iVar1 = 0x10000 << (param_2 & 0xff);
  if (param_4 == 0) {
    *(int *)(*param_1 + 0x308) = iVar1;
  }
  else {
    *(undefined4 *)(*param_1 + param_2 * 4 + 0x140) = 0;
    *(int *)(*param_1 + 0x304) = iVar1;
  }
  *(undefined4 *)(*param_1 + (param_2 + 0x150) * 4) = param_3;
  return;
}


