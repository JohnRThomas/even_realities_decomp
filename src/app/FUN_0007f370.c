/*
 * Function: FUN_0007f370
 * Entry:    0007f370
 * Prototype: uint __stdcall FUN_0007f370(void)
 */


uint FUN_0007f370(void)

{
  longlong lVar1;
  ulonglong uVar2;
  
  uVar2 = sys_clock_tick_get();
  lVar1 = (uVar2 & 0xffffffff) * 1000;
  return (uint)lVar1 >> 0xf |
         ((int)(uVar2 >> 0x20) * 1000 + (int)((ulonglong)lVar1 >> 0x20)) * 0x20000;
}


