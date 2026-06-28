/*
 * Function: start_mic_transm_thread
 * Entry:    00034658
 * Prototype: undefined __stdcall start_mic_transm_thread(void)
 */


void start_mic_transm_thread(void)

{
  k_timeout_t delay;
  uint in_stack_ffffffec;
  
  delay.ticks._4_4_ = 0;
  delay.ticks._0_4_ = in_stack_ffffffec;
  z_impl_k_thread_create
            ((k_thread *)&DAT_20004940,(k_thread_stack_t *)&DAT_200283e0,0x400,
             (k_thread_entry_t *)0x33499,(void *)0x0,(void *)0x0,(void *)0x0,-0xc,0,delay);
  return;
}


