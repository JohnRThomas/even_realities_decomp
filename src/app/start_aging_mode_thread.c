/*
 * Function: start_aging_mode_thread
 * Entry:    000345f4
 * Prototype: undefined __stdcall start_aging_mode_thread(void)
 */


void start_aging_mode_thread(void)

{
  k_timeout_t delay;
  k_tid_t puVar1;
  uint in_stack_ffffffec;
  
  if (DAT_2001abbf != '\0') {
    printk("[%s-%d], thread has started !\n","start_aging_mode_thread",0xc21);
    return;
  }
  delay.ticks._4_4_ = 0;
  delay.ticks._0_4_ = in_stack_ffffffec;
  puVar1 = z_impl_k_thread_create
                     ((k_thread *)&DAT_20004a18,(k_thread_stack_t *)&DAT_200287e0,0x400,
                      (k_thread_entry_t *)0x34449,(void *)0x0,(void *)0x0,(void *)0x0,-0xc,0,delay);
  if (puVar1 == (k_tid_t)0x0) {
    DAT_2001abbf = '\x01';
  }
  return;
}


