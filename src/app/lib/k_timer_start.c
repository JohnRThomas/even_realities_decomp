/*
 * Function: k_timer_start
 * Entry:    0007841c
 * Prototype: void __stdcall k_timer_start(k_timer * timer, k_timeout_t duration, k_timeout_t period)
 */


/* exclude_from_export */

void k_timer_start(k_timer *timer,k_timeout_t duration,k_timeout_t period)

{
  int iVar1;
  bool bVar2;
  k_timeout_t timeout;
  undefined4 in_stack_00000004;
  
  iVar1 = (int)((ulonglong)duration.ticks >> 0x20);
  if ((int)period.ticks == -1 && iVar1 == -1) {
    return;
  }
  if ((int)(((int)period.ticks + 1) - (uint)(iVar1 != -1)) < 0 ==
      (SBORROW4((int)period.ticks,-1) != SBORROW4((int)period.ticks + 1,(uint)(iVar1 != -1)))) {
    if ((int)period.ticks < (int)(uint)(iVar1 == 0)) {
      iVar1 = 1;
      period.ticks._0_4_ = 0;
    }
    bVar2 = iVar1 != 0;
    iVar1 = iVar1 + -1;
    period.ticks._0_4_ = (int)period.ticks + -1 + (uint)bVar2;
  }
  z_abort_timeout(&timer->timeout);
  *(int *)&(timer->period).ticks = (int)((ulonglong)period.ticks >> 0x20);
  *(undefined4 *)((int)&(timer->period).ticks + 4) = in_stack_00000004;
  timer->status = 0;
  timeout.ticks._4_4_ = (int)period.ticks;
  timeout.ticks._0_4_ = iVar1;
  z_add_timeout(&timer->timeout,(_timeout_func_t)0x782ad,timeout);
  return;
}


