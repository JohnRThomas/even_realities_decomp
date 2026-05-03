/*
 * Function: FUN_01038c08
 * Entry:    01038c08
 * Prototype: undefined __stdcall FUN_01038c08(int * param_1, undefined4 param_2, uint param_3, int param_4, int param_5, int param_6)
 */


void FUN_01038c08(int *param_1,undefined4 param_2,uint param_3,int param_4,int param_5,int param_6)

{
  bool bVar1;
  
  if (param_4 == -1 && param_3 == 0xffffffff) {
    return;
  }
  if ((int)((param_4 + 1) - (uint)(param_3 != 0xffffffff)) < 0 ==
      (SBORROW4(param_4,-1) != SBORROW4(param_4 + 1,(uint)(param_3 != 0xffffffff)))) {
    if (param_4 < (int)(uint)(param_3 == 0)) {
      param_3 = 1;
      param_4 = 0;
    }
    bVar1 = param_3 != 0;
    param_3 = param_3 - 1;
    param_4 = param_4 + -1 + (uint)bVar1;
  }
  FUN_01038898(param_1);
  param_1[10] = param_5;
  param_1[0xb] = param_6;
  param_1[0xc] = 0;
  FUN_0103874c(param_1,&LAB_01038abc_1,param_3,param_4);
  return;
}


