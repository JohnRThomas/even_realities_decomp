/*
 * Function: FUN_0100ffd0
 * Entry:    0100ffd0
 * Prototype: undefined __stdcall FUN_0100ffd0(int param_1, undefined1 param_2, undefined1 param_3)
 */


void FUN_0100ffd0(int param_1,undefined1 param_2,undefined1 param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  *(undefined1 *)(iVar1 + 0x14b) = param_2;
  *(undefined1 *)(iVar1 + 0x14a) = param_3;
  return;
}


