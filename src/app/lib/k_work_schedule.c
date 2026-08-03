/*
 * Function: k_work_schedule
 * Entry:    000766c0
 * Prototype: int __stdcall k_work_schedule(k_work_delayable * dwork, k_timeout_t delay)
 */


/* exclude_from_export */

int k_work_schedule(k_work_delayable *dwork,k_timeout_t delay)

{
  int iVar1;
  undefined4 in_r3;
  k_timeout_t delay_00;
  
  delay_00.ticks._0_4_ = (undefined4)((ulonglong)delay.ticks >> 0x20);
  delay_00.ticks._4_4_ = in_r3;
  iVar1 = k_work_schedule_for_queue((k_work_q *)&k_sys_work_q,dwork,delay_00);
  return iVar1;
}


