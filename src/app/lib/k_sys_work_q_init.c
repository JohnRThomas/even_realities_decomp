/*
 * Function: k_sys_work_q_init
 * Entry:    00075d24
 * Prototype: int __stdcall k_sys_work_q_init(void)
 */


/* exclude_from_export */

int k_sys_work_q_init(void)

{
  uint in_r3;
  char *local_10;
  uint local_c;
  
  local_10 = "sysworkq";
  local_c = in_r3 & 0xffffff00;
  k_work_queue_start((k_work_q *)&k_sys_work_q,(k_thread_stack_t *)&DAT_20031868,0x1000,-1,
                     (k_work_queue_config *)&local_10);
  return 0;
}


