/*
 * Function: request_ancs_attr_ext
 * Entry:    00019390
 * Prototype: int __stdcall request_ancs_attr_ext(size_t param_1, uint param_2)
 */


int request_ancs_attr_ext(size_t param_1,uint param_2)

{
  void *pvVar1;
  int iVar2;
  uint uVar3;
  
  pvVar1 = FUN_00018320();
  iVar2 = bt_ancs_get_notif_attrs
                    ((bt_ancs_client *)&GLOBAL_STATE.field_0xec,0x20006c8c,(bt_ancs_write_cb)0x183a1
                    );
  uVar3 = 0;
  do {
    if ((((GLOBAL_STATE.sem_7.poll_events.next == (void *)0x0) &&
         ((ushort)GLOBAL_STATE.sem_7.limit != 0)) &&
        (*(char *)GLOBAL_STATE.sem_7.poll_events.prev != '\0')) &&
       (*(char *)((int)pvVar1 + 0x44) != '\0')) goto LAB_00019406;
    z_impl_k_sleep((k_timeout_t)0x21);
    uVar3 = uVar3 + 1 & 0xffff;
  } while (uVar3 != 0x3e9);
  if (0 < LOG_LEVEL) {
    param_1 = ____strlen(GLOBAL_STATE.sem_7.poll_events.prev);
    param_2 = (uint)*(byte *)((int)pvVar1 + 0x44);
    if (BLE_DEBUG == 0) {
      printk("%s(): notif_attr_app_id_latest.attr_id %d notif_attr_app_id_latest.attr_len %d strlen(notif_attr_app_id_latest.attr_data) %d c->notifi_data.app_identifier %d\n"
             ,"request_ancs_attr_ext",GLOBAL_STATE.sem_7.poll_events.next,
             (uint)(ushort)GLOBAL_STATE.sem_7.limit,param_1,param_2);
    }
    else {
      ble_printk("%s(): notif_attr_app_id_latest.attr_id %d notif_attr_app_id_latest.attr_len %d strlen(notif_attr_app_id_latest.attr_data) %d c->notifi_data.app_identifier %d\n"
                 ,"request_ancs_attr_ext",GLOBAL_STATE.sem_7.poll_events.next,
                 (uint)(ushort)GLOBAL_STATE.sem_7.limit);
    }
  }
  if (GLOBAL_STATE.sem_7.poll_events.next == (void *)0x0) {
LAB_00019406:
    if (((ushort)GLOBAL_STATE.sem_7.limit != 0) &&
       (*(char *)GLOBAL_STATE.sem_7.poll_events.prev != '\0')) {
      if (BLE_DEBUG == 0) {
        printk("Request for %s: retry_time %d\n");
      }
      else {
        ble_printk("Request for %s: retry_time %d\n",GLOBAL_STATE.sem_7.poll_events.prev,uVar3,
                   BLE_DEBUG);
      }
      for (; uVar3 < 200; uVar3 = uVar3 + 1 & 0xffff) {
        iVar2 = app_attr_get((bt_ancs_client *)&GLOBAL_STATE.field_0xec,
                             GLOBAL_STATE.sem_7.poll_events.prev,
                             (uint)(ushort)GLOBAL_STATE.sem_7.limit,(bt_ancs_write_cb)0x183a1);
        if (iVar2 == 0) goto LAB_00019432;
        z_impl_k_sleep((k_timeout_t)0xa4);
      }
      if (iVar2 != 0) {
        printk("Failed requesting attributes for a given app (err: %d)\n",iVar2);
      }
    }
  }
LAB_00019432:
  if (BLE_DEBUG == 0) {
    printk("notif_attr_app_id_latest.attr_id (%d/%d) retry_time %d\n",
           GLOBAL_STATE.sem_7.poll_events.next,(uint)(ushort)GLOBAL_STATE.sem_7.limit,uVar3,param_1,
           param_2);
  }
  else {
    ble_printk("notif_attr_app_id_latest.attr_id (%d/%d) retry_time %d\n",
               GLOBAL_STATE.sem_7.poll_events.next,(uint)(ushort)GLOBAL_STATE.sem_7.limit,uVar3);
  }
  return iVar2;
}


