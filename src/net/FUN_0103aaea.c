/*
 * Function: FUN_0103aaea
 * Entry:    0103aaea
 * Prototype: undefined __stdcall FUN_0103aaea(undefined * param_1, int param_2, int param_3, undefined4 param_4)
 */


void FUN_0103aaea(undefined *param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  
  do {
    iVar1 = (*(code *)param_1)(param_2,param_3,param_4);
    param_3 = param_3 - iVar1;
    param_2 = param_2 + iVar1;
  } while (param_3 != 0);
  return;
}


