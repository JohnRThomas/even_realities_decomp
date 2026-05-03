/*
 * Function: FUN_0100d7a4
 * Entry:    0100d7a4
 * Prototype: undefined __stdcall FUN_0100d7a4(int param_1, uint param_2, int param_3)
 */


void FUN_0100d7a4(int param_1,uint param_2,int param_3)

{
  *(short *)(param_1 + 0x48) = (short)param_3;
  *(undefined4 *)(param_1 + 0x40) = 0;
  *(uint *)(param_1 + 0x44) = (param_3 * 10000 + (param_2 - 1)) / param_2;
  return;
}


