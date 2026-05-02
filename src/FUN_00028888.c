/*
 * Function: FUN_00028888
 * Entry:    00028888
 * Prototype: undefined __stdcall FUN_00028888(int param_1)
 */


void FUN_00028888(int param_1)

{
  longlong lVar1;
  uint uVar2;
  ulonglong uVar3;
  
  uVar3 = sys_clock_tick_get();
  lVar1 = (uVar3 & 0xffffffff) * 1000;
  uVar2 = (uint)lVar1 >> 0xf |
          ((int)(uVar3 >> 0x20) * 1000 + (int)((ulonglong)lVar1 >> 0x20)) * 0x20000;
  *(float *)(param_1 + 0x40) = (float)(uVar2 - *(int *)(param_1 + 0x3c)) / 1000.0;
  *(uint *)(param_1 + 0x38) = uVar2;
  *(uint *)(param_1 + 0x3c) = uVar2;
  return;
}


