/*
 * Function: ble_write_thread
 * Entry:    00017f84
 * Prototype: undefined4 __stdcall ble_write_thread(uint8_t * param_1, undefined4 param_2)
 */


undefined4 ble_write_thread(uint8_t *param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  GlassesState *pGVar3;
  undefined4 extraout_r1;
  undefined4 uVar4;
  undefined4 extraout_r1_00;
  k_timeout_t timeout;
  
  iVar2 = FUN_00019cec();
  cVar1 = FUN_00033d5c();
  uVar4 = extraout_r1;
  if ((cVar1 != '\0') ||
     (((iVar2 != 0 && (pGVar3 = __get_dashboard_state(), pGVar3->field_0xae3 == '\0')) &&
      (pGVar3 = __get_dashboard_state(), uVar4 = extraout_r1_00,
      (pGVar3->__work_mode_sem).count != 0)))) {
    timeout.ticks._4_4_ = 0xffffffff;
    timeout.ticks._0_4_ = uVar4;
    z_impl_k_mutex_lock((k_mutex *)&GLOBAL_STATE.sem_1,timeout);
    iVar2 = bt_nus_send((bt_conn *)0x0,param_1,(uint16_t)param_2);
    z_impl_k_mutex_unlock((k_mutex *)&GLOBAL_STATE.sem_1);
    if (iVar2 == 0) {
      return 0;
    }
    printk("Failed to send data over BLE connection: ret %d len %d \n",iVar2,param_2);
  }
  return 0xffffffff;
}


