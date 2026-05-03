/*
 * Function: FUN_00025b58
 * Entry:    00025b58
 * Prototype: undefined __stdcall FUN_00025b58(void * param_1)
 */


void FUN_00025b58(void *param_1)

{
  k_timeout_t delay;
  k_timeout_t delay_00;
  uint in_stack_ffffffdc;
  
  z_impl_k_sem_init((k_sem *)&DAT_200083c4,0,0x14);
  delay.ticks._4_4_ = 0;
  delay.ticks._0_4_ = in_stack_ffffffdc;
  z_impl_k_thread_create
            ((k_thread *)&DAT_20003fd8,(k_thread_stack_t *)&DAT_200226e0,0x800,
             (k_thread_entry_t)0x25539,param_1,(void *)0x0,(void *)0x0,-0xc,0,delay);
  delay_00.ticks._4_4_ = 0;
  delay_00.ticks._0_4_ = in_stack_ffffffdc;
  z_impl_k_thread_create
            ((k_thread *)&DAT_200040b0,(k_thread_stack_t *)&DAT_20022ee0,0x1400,
             (k_thread_entry_t)0x258fd,param_1,(void *)0x0,(void *)0x0,-0xb,0,delay_00);
  return;
}


