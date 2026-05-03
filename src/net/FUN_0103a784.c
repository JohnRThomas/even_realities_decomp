/*
 * Function: FUN_0103a784
 * Entry:    0103a784
 * Prototype: undefined4 __stdcall FUN_0103a784(int param_1)
 */


undefined4 FUN_0103a784(int param_1)

{
  undefined4 extraout_r1;
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x10);
  *(undefined4 *)(iVar1 + 0x378) = **(undefined4 **)(param_1 + 4);
  FUN_0103b994(iVar1 + 0x1b0);
  FUN_0103a776((undefined4 *)(iVar1 + 0x37c),0);
  return extraout_r1;
}


