/*
 * Function: FUN_0007b0f4
 * Entry:    0007b0f4
 * Prototype: undefined __stdcall FUN_0007b0f4(int * param_1, undefined4 param_2, int param_3)
 */


void FUN_0007b0f4(int *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  DAT_2000d60c = 0;
  iVar1 = FUN_00083fa0(param_2,param_3);
  if ((iVar1 == -1) && (DAT_2000d60c != 0)) {
    *param_1 = DAT_2000d60c;
  }
  return;
}


