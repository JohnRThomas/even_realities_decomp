/*
 * Function: FUN_0102f4a0
 * Entry:    0102f4a0
 * Prototype: undefined __stdcall FUN_0102f4a0(int param_1, undefined4 param_2, int param_3, undefined4 param_4, undefined4 param_5, undefined4 param_6, undefined4 param_7)
 */


void FUN_0102f4a0(int param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6,undefined4 param_7)

{
  *(undefined4 *)(param_3 + -0x20) = param_4;
  *(undefined4 *)(param_3 + -0x1c) = param_5;
  *(undefined4 *)(param_3 + -0x18) = param_6;
  *(code **)(param_3 + -8) = FUN_0102cbfc;
  *(undefined4 *)(param_3 + -0x14) = param_7;
  *(undefined4 *)(param_3 + -4) = 0x1000000;
  *(int *)(param_1 + 0x50) = param_3 + -0x20;
  *(undefined4 *)(param_1 + 0x8c) = 0;
  return;
}


