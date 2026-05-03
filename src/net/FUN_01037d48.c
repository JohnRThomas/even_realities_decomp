/*
 * Function: FUN_01037d48
 * Entry:    01037d48
 * Prototype: undefined __stdcall FUN_01037d48(int * param_1, int * param_2, uint param_3, int param_4)
 */


void FUN_01037d48(int *param_1,int *param_2,uint param_3,int param_4)

{
  FUN_01037cd4(param_1,param_2,param_3,param_4);
  if (param_4 != -1 || param_3 != 0xffffffff) {
    FUN_0103874c(param_1 + 6,&LAB_0103ba88_1,param_3,param_4);
    return;
  }
  return;
}


