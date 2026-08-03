/*
 * Function: long_wq_init
 * Entry:    00056440
 * Prototype: int __stdcall long_wq_init(void)
 */


/* exclude_from_export_ai */

int long_wq_init(void)

{
  char *pcStack_18;
  undefined4 uStack_14;
  
  pcStack_18 = "BT_LW_WQ";
  uStack_14 = 0;
  k_work_queue_init((k_work_q *)&k_sys_work_q);
  k_work_queue_start((k_work_q *)&k_sys_work_q,(k_thread_stack_t *)&DAT_2002bbe0,0x518,10,
                     (k_work_queue_config *)&pcStack_18);
  return 0;
}


