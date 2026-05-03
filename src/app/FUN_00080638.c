/*
 * Function: FUN_00080638
 * Entry:    00080638
 * Prototype: undefined8 __stdcall FUN_00080638(void)
 */


undefined8 FUN_00080638(void)

{
  longlong lVar1;
  uint uVar2;
  ulonglong uVar3;
  
  uVar3 = sys_clock_tick_get();
  lVar1 = (uVar3 & 0xffffffff) * 1000;
  uVar2 = (int)(uVar3 >> 0x20) * 1000 + (int)((ulonglong)lVar1 >> 0x20);
  return CONCAT44(uVar2 >> 0xf,(uint)lVar1 >> 0xf | uVar2 * 0x20000);
}


