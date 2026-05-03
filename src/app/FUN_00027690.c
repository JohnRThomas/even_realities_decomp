/*
 * Function: FUN_00027690
 * Entry:    00027690
 * Prototype: undefined4 __stdcall FUN_00027690(void)
 */


undefined4 FUN_00027690(void)

{
  bool bVar1;
  undefined4 uVar2;
  int64_t iVar3;
  
  bVar1 = FUN_00027674();
  if (bVar1) {
    iVar3 = sys_clock_tick_get();
    DAT_200083f0 = (int)iVar3;
    uVar2 = 1;
  }
  else {
    iVar3 = sys_clock_tick_get();
    if ((int)iVar3 - DAT_200083f0 < 0) {
      sys_clock_tick_get();
    }
    uVar2 = 0;
  }
  return uVar2;
}


