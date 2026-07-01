/*
 * Function: discover_ancs_completed_cb
 * Entry:    000189d0
 * Prototype: undefined __stdcall discover_ancs_completed_cb(bt_gatt_dm * param_1, bt_ancs_client * param_2)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void discover_ancs_completed_cb(bt_gatt_dm *param_1,bt_ancs_client *param_2)

{
  bt_conn *pbVar1;
  int iVar2;
  char *fmt;
  
  pbVar1 = bt_gatt_dm_conn_get(param_1);
  printk("The discovery procedure for ANCS succeeded\n");
  iVar2 = bt_ancs_handles_assign(param_1,param_2);
  if (iVar2 == 0) {
    _ancs_discovery_flags = _ancs_discovery_flags | 2;
    iVar2 = bt_ancs_subscribe_notification_source(param_2,(bt_ancs_ns_notif_cb)0x19049);
    if (iVar2 != 0) {
      printk("Failed to enable Notification Source notification (err %d)\n",iVar2);
    }
    iVar2 = bt_ancs_subscribe_data_source(param_2,(bt_ancs_ds_notif_cb)0x18d41);
    if (iVar2 == 0) goto LAB_000189f4;
    fmt = "Failed to enable Data Source notification (err %d)\n";
  }
  else {
    fmt = "Could not init ANCS client object, error: %d\n";
  }
  printk(fmt,iVar2);
LAB_000189f4:
  iVar2 = bt_gatt_dm_data_release(param_1);
  if (iVar2 != 0) {
    printk("Could not release the discovery data, error code: %d\n",iVar2);
  }
  atomic_and((atomic_t *)&ancs_discovery_flags,-2);
  discover_ancs(pbVar1,1);
  return;
}


