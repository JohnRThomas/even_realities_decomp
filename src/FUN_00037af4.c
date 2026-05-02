/*
 * Function: FUN_00037af4
 * Entry:    00037af4
 * Prototype: undefined __stdcall FUN_00037af4(undefined4 param_1, int * param_2)
 */


void FUN_00037af4(undefined4 param_1,int *param_2)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  ulonglong uVar4;
  
  if (*(char *)((int)param_2 + 6) == '\x01') {
    DAT_2000a9a0 = 0;
    *(undefined1 *)((int)param_2 + 6) = 0;
  }
  uVar4 = sys_clock_tick_get();
  lVar1 = (uVar4 & 0xffffffff) * 1000;
  uVar3 = (uint)lVar1 >> 0xf |
          ((int)(uVar4 >> 0x20) * 1000 + (int)((ulonglong)lVar1 >> 0x20)) * 0x20000;
  uVar2 = uVar3;
  if ((DAT_2000a9a0 != 0) && (uVar2 = DAT_2000a9a0, 999 < uVar3 - DAT_2000a9a0)) {
    *param_2 = *param_2 - (uVar3 - DAT_2000a9a0) / 1000;
    uVar2 = uVar3;
  }
  DAT_2000a9a0 = uVar2;
  return;
}


