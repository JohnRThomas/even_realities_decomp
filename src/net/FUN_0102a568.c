/*
 * Function: FUN_0102a568
 * Entry:    0102a568
 * Prototype: undefined __stdcall FUN_0102a568(int param_1, int param_2, undefined4 param_3)
 */


void FUN_0102a568(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 4);
  iVar1 = param_2 + iVar2;
  *(int *)(param_1 + 4) = iVar1;
  FUN_01024538(iVar1 - 0x62,iVar1,param_3,iVar2);
  return;
}


