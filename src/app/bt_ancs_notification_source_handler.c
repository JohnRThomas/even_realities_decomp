/*
 * Function: bt_ancs_notification_source_handler
 * Entry:    00019048
 * Prototype: void __stdcall bt_ancs_notification_source_handler(bt_ancs_client * client, int err, undefined4 * param_3)
 */


void bt_ancs_notification_source_handler(bt_ancs_client *client,int err,undefined4 *param_3)

{
  void *pvVar1;
  uint uVar2;
  GlassesState *pGVar3;
  int iVar4;
  undefined4 extraout_r1;
  undefined4 extraout_r2;
  
  iVar4 = err;
  pvVar1 = FUN_00018320();
  if (err == 0) {
    printk("\nNotification UID:         %u\nEvent:       %s\n",*param_3,
           (&PTR_s_Added_0008c1c8)[*(byte *)(param_3 + 1)],&PTR_s_Added_0008c1c8,client,iVar4);
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
           (pGVar3 = __get_dashboard_state(), pGVar3->field_0xd5 != '\t')) &&
          (((pGVar3 = __get_dashboard_state(), pGVar3->field_0xd5 != '\f' &&
            (pGVar3 = __get_dashboard_state(), pGVar3->field_0xd5 != '\x10')) &&
           ((pGVar3 = __get_dashboard_state(), pGVar3->field_0xd5 != '\x14' &&
            ((pGVar3 = __get_dashboard_state(), pGVar3->field_0xd5 != '\x0e' &&
             (pGVar3 = __get_dashboard_state(), pGVar3->field_0xd5 != '\x0f')))))))) &&
         ((pGVar3 = __get_dashboard_state(), pGVar3->field_0xd5 != '\x11' &&
          ((((pGVar3 = __get_dashboard_state(), pGVar3->field_0xd5 != '\x12' &&
             (pGVar3 = __get_dashboard_state(), pGVar3->field_0xd5 != '\x13')) &&
            (*(byte *)(param_3 + 1) < 3)) &&
           (iVar4 = enqueue_uid_drop_package_(param_3,extraout_r1,extraout_r2), iVar4 == 0)))))) {
        if (0 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): ============================>bt_ancs_get_attr_req_sem %d count %d notif->evt_id %d\n"
                   ,"bt_ancs_notification_source_handler",*param_3,
                   *(undefined4 *)((int)pvVar1 + 0x208),(uint)*(byte *)(param_3 + 1));
          }
          else {
            ble_printk("%s(): ============================>bt_ancs_get_attr_req_sem %d count %d notif->evt_id %d\n"
                       ,"bt_ancs_notification_source_handler",*param_3,
                       *(undefined4 *)((int)pvVar1 + 0x208));
          }
        }
        memset((void *)((int)pvVar1 + 0x34),0,0x1b4);
        if (*(char *)(param_3 + 1) == '\x02') {
          *(undefined4 *)((int)pvVar1 + 0x3c) = *param_3;
        }
        k_sem_give((k_sem *)((int)pvVar1 + 0x200));
        return;
      }
    }
  }
  return;
}


