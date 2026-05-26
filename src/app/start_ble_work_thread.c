/*
 * Function: start_ble_work_thread
 * Entry:    00023fd8
 * Prototype: int __stdcall start_ble_work_thread(void * param_1)
 */


int start_ble_work_thread(void *param_1)

{
  k_timeout_t delay;
  uint in_stack_ffffffe4;
  
  z_impl_k_mutex_init((k_mutex *)&DAT_20007f54);
  k_timer_init((k_timer *)&DAT_20003ec8,(k_timer_expiry_t)0x1a211,(k_timer_stop_t)0x0);
  delay.ticks._4_4_ = 0;
  delay.ticks._0_4_ = in_stack_ffffffe4;
  z_impl_k_thread_create
            ((k_thread *)&DAT_20003f00,(k_thread_stack_t *)&DAT_2001f6e0,0x3000,
             (k_thread_entry_t)0x23d69,param_1,(void *)0x0,(void *)0x0,-0xf,0,delay);
  return 0;
}


