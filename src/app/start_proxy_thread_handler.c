/*
 * Function: start_proxy_thread_handler
 * Entry:    0004b358
 * Prototype: int __stdcall start_proxy_thread_handler(void * param_1)
 */


int start_proxy_thread_handler(void *param_1)

{
  k_timeout_t delay;
  uint in_stack_ffffffec;
  
  delay.ticks._4_4_ = 0;
  delay.ticks._0_4_ = in_stack_ffffffec;
  DAT_2000aa70 = z_impl_k_thread_create
                           ((k_thread *)&DAT_20004de8,(k_thread_stack_t *)&DAT_20028be0,0x800,
                            (k_thread_entry_t)0x4b4d1,param_1,(void *)0x0,(void *)0x0,-0xc,0,delay);
  return -(uint)(DAT_2000aa70 == (k_tid_t)0x0);
}


