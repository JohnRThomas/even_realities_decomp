/*
 * Function: sys_timepoint_calc
 * Entry:    00089e4c
 * Prototype: k_timepoint_t __stdcall sys_timepoint_calc(k_timeout_t timeout)
 */


/* exclude_from_export */

k_timepoint_t sys_timepoint_calc(k_timeout_t timeout)

{
  longlong lVar1;
  int iVar2;
  uint in_r2;
  undefined4 uVar3;
  int in_r3;
  int64_t iVar4;
  
  if (in_r3 == -1 && in_r2 == 0xffffffff) {
    uVar3 = 0xffffffff;
  }
  else {
    if (in_r2 != 0 || in_r3 != 0) {
      iVar2 = (-1 - in_r3) - (uint)(0xfffffffe < in_r2);
      lVar1 = CONCAT44(iVar2,-2 - in_r2);
      if (iVar2 < 0) {
        iVar4 = sys_clock_tick_get();
        lVar1 = iVar4 + CONCAT44(in_r3,in_r2);
      }
      goto LAB_00089e80;
    }
    uVar3 = 0;
  }
  lVar1 = CONCAT44(uVar3,uVar3);
LAB_00089e80:
  *(longlong *)timeout.ticks = lVar1;
  return (k_timepoint_t)(longlong *)timeout.ticks;
}


