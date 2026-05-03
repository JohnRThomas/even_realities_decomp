/*
 * Function: FUN_0100f9a8
 * Entry:    0100f9a8
 * Prototype: undefined __stdcall FUN_0100f9a8(int param_1, int param_2)
 */


void FUN_0100f9a8(int param_1,int param_2)

{
  *(undefined2 *)(param_1 + 0x20) = 0x1b;
  *(undefined2 *)(param_1 + 0x1c) = 0x1b;
  *(undefined4 *)(param_1 + 0x14) = 0x1b001b;
  *(undefined2 *)(param_1 + 0x10) = 0x1b;
  *(undefined4 *)(param_1 + 8) = 0x1b001b;
  *(undefined4 *)(param_1 + 0x2a) = 0x1b001b;
  *(undefined2 *)(param_1 + 0x24) = 0x1b;
  if (param_2 == 0) {
    *(undefined2 *)(param_1 + 0x22) = 0x148;
    *(undefined2 *)(param_1 + 0x1e) = 0x148;
    *(undefined1 **)(param_1 + 0x18) = &DAT_01480148;
    *(undefined2 *)(param_1 + 0x12) = 0x148;
    *(undefined1 **)(param_1 + 0xc) = &DAT_01480148;
    *(undefined1 **)(param_1 + 0x2e) = &DAT_01480148;
    return;
  }
  *(undefined2 *)(param_1 + 0x22) = 0xa90;
  *(undefined2 *)(param_1 + 0x1e) = 0xa90;
  *(undefined1 **)(param_1 + 0x18) = &DAT_0a900a90;
  *(undefined2 *)(param_1 + 0x12) = 0x148;
  *(undefined1 **)(param_1 + 0xc) = &DAT_0a900a90;
  *(undefined1 **)(param_1 + 0x2e) = &DAT_0a900a90;
  return;
}


