/*
 * Function: bt_long_wq_reschedule
 * Entry:    00056484
 * Prototype: int __stdcall bt_long_wq_reschedule(k_work_delayable * dwork, k_timeout_t timeout)
 */


/* exclude_from_export */

int bt_long_wq_reschedule(k_work_delayable *dwork,k_timeout_t timeout)

{
  int iVar1;
  undefined4 in_r3;
  k_timeout_t delay;
  
  delay.ticks._0_4_ = (undefined4)((ulonglong)timeout.ticks >> 0x20);
  delay.ticks._4_4_ = in_r3;
  iVar1 = k_work_reschedule_for_queue((k_work_q *)&k_sys_work_q,dwork,delay);
  return iVar1;
}


