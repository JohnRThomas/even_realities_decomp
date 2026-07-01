/*
 * Function: ancs_disconnected
 * Entry:    00018bd4
 * Prototype: undefined __stdcall ancs_disconnected(k_work * param_1, undefined4 param_2)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ancs_disconnected(k_work *param_1,undefined4 param_2)

{
  k_work_delayable *addr;
  GlassesState *pGVar1;
  undefined4 extraout_r1;
  size_t len;
  k_timeout_t timeout;
  char acStack_30 [36];
  
  *(undefined1 *)(_DAT_20006c98 + 0x365) = 0;
  DAT_20007ef4 = 0;
  addr = k_work_delayable_from_work(param_1);
  bt_addr_le_to_str((bt_addr_le_t *)addr,acStack_30,len);
  if (0 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): from %s (reason 0x%02x)\n","ancs_disconnected",acStack_30,param_2);
    }
    else {
      ble_printk("%s(): from %s (reason 0x%02x)\n","ancs_disconnected",acStack_30,param_2);
    }
  }
  *(undefined1 *)(_DAT_20006c98 + 0x367) = 0;
  while (pGVar1 = __get_dashboard_state(), (pGVar1->__work_mode_sem).count != 0) {
    pGVar1 = __get_dashboard_state();
    timeout.ticks._4_4_ = 0xffffffff;
    timeout.ticks._0_4_ = extraout_r1;
    z_impl_k_sem_take(&pGVar1->__work_mode_sem,timeout);
  }
  FUN_00018ba8();
  return;
}


