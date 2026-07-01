/*
 * Function: request_ancs_attr_ext
 * Entry:    00019390
 * Prototype: int __stdcall request_ancs_attr_ext(size_t param_1, uint param_2)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int request_ancs_attr_ext(size_t param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = FUN_00018320();
  iVar2 = bt_ancs_get_notif_attrs
                    ((bt_ancs_client *)&DAT_20006cc8,0x20006c8c,(bt_ancs_write_cb)0x183a1);
  uVar3 = 0;
  do {
    if ((((_DAT_20006c84 == (char *)0x0) && (_DAT_20006c80 != 0)) && (*_DAT_20006c88 != '\0')) &&
       (*(char *)(iVar1 + 0x44) != '\0')) goto LAB_00019406;
    z_impl_k_sleep((k_timeout_t)0x21);
    uVar3 = uVar3 + 1 & 0xffff;
  } while (uVar3 != 0x3e9);
  if (0 < LOG_LEVEL) {
    param_1 = strlen((char *)_DAT_20006c88);
    param_2 = (uint)*(byte *)(iVar1 + 0x44);
    if (BLE_DEBUG == 0) {
      printk("%s(): notif_attr_app_id_latest.attr_id %d notif_attr_app_id_latest.attr_len %d strlen(notif_attr_app_id_latest.attr_data) %d c->notifi_data.app_identifier %d\n"
             ,"request_ancs_attr_ext",_DAT_20006c84,(uint)_DAT_20006c80,param_1,param_2);
    }
    else {
      ble_printk("%s(): notif_attr_app_id_latest.attr_id %d notif_attr_app_id_latest.attr_len %d strlen(notif_attr_app_id_latest.attr_data) %d c->notifi_data.app_identifier %d\n"
                 ,"request_ancs_attr_ext",_DAT_20006c84,(uint)_DAT_20006c80);
    }
  }
  if (_DAT_20006c84 == (char *)0x0) {
LAB_00019406:
    if ((_DAT_20006c80 != 0) && (*_DAT_20006c88 != '\0')) {
      if (BLE_DEBUG == 0) {
        printk("Request for %s: retry_time %d\n");
      }
      else {
        ble_printk("Request for %s: retry_time %d\n",(char *)_DAT_20006c88,uVar3,BLE_DEBUG,param_1,
                   param_2);
      }
      for (; uVar3 < 200; uVar3 = uVar3 + 1 & 0xffff) {
        iVar2 = app_attr_get((bt_ancs_client *)&DAT_20006cc8,_DAT_20006c88,(uint)_DAT_20006c80,
                             (bt_ancs_write_cb)0x183a1);
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
    printk("notif_attr_app_id_latest.attr_id (%d/%d) retry_time %d\n",_DAT_20006c84,
           (uint)_DAT_20006c80,uVar3);
  }
  else {
    ble_printk("notif_attr_app_id_latest.attr_id (%d/%d) retry_time %d\n",_DAT_20006c84,
               (uint)_DAT_20006c80,uVar3);
  }
  return iVar2;
}


