/*
 * Function: FUN_010104b4
 * Entry:    010104b4
 * Prototype: undefined __stdcall FUN_010104b4(int param_1, undefined1 * param_2)
 */


void FUN_010104b4(int param_1,undefined1 *param_2)

{
  undefined4 uVar1;
  
  *param_2 = 9;
  *(undefined2 *)(param_2 + 3) = *(undefined2 *)(param_1 + -0x3cc);
  uVar1 = *(undefined4 *)(param_1 + 0xb);
  *(undefined4 *)(param_2 + 9) = *(undefined4 *)(param_1 + 0xf);
  *(undefined4 *)(param_2 + 5) = uVar1;
  *(undefined2 *)(param_2 + 0xd) = *(undefined2 *)(param_1 + 0x13);
  return;
}


