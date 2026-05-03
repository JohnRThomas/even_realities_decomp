/*
 * Function: FUN_0004c7ac
 * Entry:    0004c7ac
 * Prototype: undefined4 __stdcall FUN_0004c7ac(void * param_1)
 */


undefined4 FUN_0004c7ac(void *param_1)

{
  k_timeout_t delay;
  uint in_stack_ffffffec;
  
  delay.ticks._4_4_ = 0;
  delay.ticks._0_4_ = in_stack_ffffffec;
  DAT_2000aa7c = z_impl_k_thread_create
                           ((k_thread *)&DAT_20004ef8,(k_thread_stack_t *)&DAT_200293e0,0x1400,
                            (k_thread_entry_t)0x4c461,param_1,(void *)0x0,(void *)0x0,-0xe,0,delay);
  return 0;
}


