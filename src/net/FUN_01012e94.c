/*
 * Function: FUN_01012e94
 * Entry:    01012e94
 * Prototype: undefined __stdcall FUN_01012e94(int param_1, undefined1 param_2)
 */


void FUN_01012e94(int param_1,undefined1 param_2)

{
  *(undefined2 *)(param_1 + 0x40) = 0;
  if (*(short *)(param_1 + 2) == 0x1d) {
    param_2 = 0;
  }
  *(undefined1 *)(param_1 + 0xd) = param_2;
  return;
}


