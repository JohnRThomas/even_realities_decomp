/*
 * Function: sc_work_submit
 * Entry:    0005d60c
 * Prototype: void __stdcall sc_work_submit(k_timeout_t timeout)
 */


/* exclude_from_export */

void sc_work_submit(k_timeout_t timeout)

{
  k_timeout_t delay;
  
  delay.ticks._0_4_ = (undefined4)((ulonglong)timeout.ticks >> 0x20);
  delay.ticks._4_4_ = 0x148;
  k_work_reschedule((k_work_delayable *)&DAT_200065f8,delay);
  return;
}


