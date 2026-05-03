/*
 * Function: FUN_01012f14
 * Entry:    01012f14
 * Prototype: undefined __stdcall FUN_01012f14(int param_1, int param_2)
 */


void FUN_01012f14(int param_1,int param_2)

{
  *(int *)(param_1 + 0x1c) = param_2;
  *(undefined1 *)(param_2 + 9) = *(undefined1 *)(param_1 + 0x60);
  *(undefined4 *)(param_2 + 10) = *(undefined4 *)(param_1 + 0x61);
  *(undefined2 *)(param_2 + 0xe) = *(undefined2 *)(param_1 + 0x65);
  return;
}


