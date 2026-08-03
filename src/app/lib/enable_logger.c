/*
 * Function: enable_logger
 * Entry:    00050514
 * Prototype: int __stdcall enable_logger(void)
 */


/* exclude_from_export_ai */

int enable_logger(void)

{
  k_timeout_t delay;
  uint in_stack_ffffffe4;
  
  k_timer_init((k_timer *)&DAT_20005888,(k_timer_expiry_t)0x506b5,(k_timer_stop_t)0x0);
  delay.ticks._4_4_ = 0;
  delay.ticks._0_4_ = in_stack_ffffffe4;
  z_impl_k_thread_create
            ((k_thread *)&DAT_200053a8,(k_thread_stack_t *)&DAT_2002abe0,0x800,
             (k_thread_entry_t *)0x5098d,(void *)0x0,(void *)0x0,(void *)0x0,0xe,0,delay);
  k_thread_name_set(&DAT_200053a8,"logging");
  return 0;
}


