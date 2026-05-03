/*
 * Function: FUN_0101113c
 * Entry:    0101113c
 * Prototype: undefined __stdcall FUN_0101113c(int param_1, undefined1 * param_2)
 */


void FUN_0101113c(int param_1,undefined1 *param_2)

{
  undefined4 uVar1;
  
  *param_2 = 0x17;
  uVar1 = *(undefined4 *)(param_1 + 0xd);
  *(undefined4 *)(param_2 + 3) = *(undefined4 *)(param_1 + 9);
  *(undefined4 *)(param_2 + 7) = uVar1;
  return;
}


