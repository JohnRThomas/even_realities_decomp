/*
 * Function: FUN_01011118
 * Entry:    01011118
 * Prototype: undefined __stdcall FUN_01011118(int param_1, undefined1 * param_2)
 */


void FUN_01011118(int param_1,undefined1 *param_2)

{
  undefined2 *puVar1;
  
  *param_2 = 6;
  puVar1 = *(undefined2 **)(param_1 + 0xf);
  *(undefined2 *)(param_2 + 3) = *puVar1;
  param_2[5] = *(undefined1 *)((int)puVar1 + 0xcd);
  *(undefined4 *)(DAT_210014c0 + 0x78) = 0;
  return;
}


