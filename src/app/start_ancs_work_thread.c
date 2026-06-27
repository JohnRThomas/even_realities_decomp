/*
 * Function: start_ancs_work_thread
 * Entry:    00019a8c
 * Prototype: undefined __stdcall start_ancs_work_thread(void * param_1)
 */


void start_ancs_work_thread(void *param_1)

{
  k_timeout_t delay;
  char cVar1;
  GlassesState *pGVar2;
  undefined4 extraout_r2;
  uint in_stack_ffffffec;
  
  pGVar2 = __get_dashboard_state();
  if ((*(char *)pGVar2 == '\x02') && (cVar1 = FUN_00033d5c(), cVar1 != '\x01')) {
    delay.ticks._4_4_ = 0;
    delay.ticks._0_4_ = in_stack_ffffffec;
    z_impl_k_thread_create
              (&ancs_work_thread,&ancs_work_thread_stack,0x1400,(k_thread_entry_t)0x198d9,param_1,
               (void *)0x0,(void *)0x0,-0xb,0,delay);
    if (2 < LOG_LEVEL) {
      if (BLE_DEBUG != 0) {
        ble_printk("%s(): exit\n\n","start_ancs_work_thread",extraout_r2,BLE_DEBUG);
        return;
      }
      printk("%s(): exit\n\n");
      return;
    }
  }
  return;
}


