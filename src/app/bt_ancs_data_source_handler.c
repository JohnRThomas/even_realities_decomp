/*
 * Function: bt_ancs_data_source_handler
 * Entry:    00018d40
 * Prototype: undefined __stdcall bt_ancs_data_source_handler(undefined4 param_1, byte * param_2)
 */


void bt_ancs_data_source_handler(undefined4 param_1,byte *param_2)

{
  void *pvVar1;
  uint uVar2;
  GlassesState *pGVar3;
  
  pvVar1 = FUN_00018320();
  if (0 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): bt_ancs_data_source_handler response->command_id %d\n");
    }
    else {
      ble_printk("%s(): bt_ancs_data_source_handler response->command_id %d\n",
                 "bt_ancs_data_source_handler",(uint)*param_2,BLE_DEBUG);
    }
  }
  if (*param_2 == 0) {
    if (*(int *)(param_2 + 8) == 0) {
      GLOBAL_STATE.sem_7.limit = *(uint *)(param_2 + 4);
      GLOBAL_STATE.sem_7.poll_events.next = *(void **)(param_2 + 8);
      GLOBAL_STATE.sem_7.poll_events.prev = *(void **)(param_2 + 0xc);
      DAT_2001095f = '\x01';
    }
  }
  else if (((*param_2 == 1) && (DAT_2001095f != '\0')) &&
          (GLOBAL_STATE.sem_8.wait_q.next != DAT_2000231c)) {
    uVar2 = FUN_0007f370();
    pGVar3 = __get_dashboard_state();
    if (9999 < uVar2 - *(int *)&pGVar3->field_0xae8) {
      while ((pGVar3 = __get_dashboard_state(), pGVar3->field_0x1 == '\x01' ||
             (pGVar3 = __get_dashboard_state(), pGVar3->field_0x1 == '\b'))) {
        z_impl_k_sleep((k_timeout_t)0x28000);
      }
      pGVar3 = __get_dashboard_state();
      if (((((pGVar3->field_0xd5 != '\v') &&
            (pGVar3 = __get_dashboard_state(), pGVar3->field_0xd5 != '\n')) &&
           ((pGVar3 = __get_dashboard_state(), pGVar3->field_0xd5 != '\t' &&
            ((((pGVar3 = __get_dashboard_state(), pGVar3->field_0xd5 != '\f' &&
               (pGVar3 = __get_dashboard_state(), pGVar3->field_0xd5 != '\x10')) &&
              (pGVar3 = __get_dashboard_state(), pGVar3->field_0xd5 != '\x14')) &&
             ((pGVar3 = __get_dashboard_state(), pGVar3->field_0xd5 != '\x0e' &&
              (pGVar3 = __get_dashboard_state(), pGVar3->field_0xd5 != '\x0f')))))))) &&
          (pGVar3 = __get_dashboard_state(), pGVar3->field_0xd5 != '\x11')) &&
         ((pGVar3 = __get_dashboard_state(), pGVar3->field_0xd5 != '\x12' &&
          (pGVar3 = __get_dashboard_state(), pGVar3->field_0xd5 != '\x13')))) {
        DAT_2000231c = GLOBAL_STATE.sem_8.wait_q.next;
        *(uint *)((int)pvVar1 + 0x1e4) = (uint)(byte)GLOBAL_STATE.sem_8.wait_q.prev;
        enqueue_ancs((void *)((int)pvVar1 + 0x34));
        if (0 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk(
                  "%s(): =========================>bt_ancs_get_attr_data_sem %d evt_id %d action %d\n"
                  );
          }
          else {
            ble_printk("%s(): =========================>bt_ancs_get_attr_data_sem %d evt_id %d action %d\n"
                       ,"bt_ancs_data_source_handler",GLOBAL_STATE.sem_8.wait_q.next,
                       (uint)(byte)GLOBAL_STATE.sem_8.wait_q.prev);
          }
        }
        memset((void *)((int)pvVar1 + 0x34),0,0x1b4);
        k_sem_give((k_sem *)((int)pvVar1 + 0x1e8));
        DAT_2001095f = '\0';
      }
    }
  }
  return;
}


