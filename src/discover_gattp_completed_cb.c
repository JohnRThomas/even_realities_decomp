/*
 * Function: discover_gattp_completed_cb
 * Entry:    00018a98
 * Prototype: undefined __stdcall discover_gattp_completed_cb(bt_gatt_dm * param_1, bt_ancs_client * param_2)
 */


void discover_gattp_completed_cb(bt_gatt_dm *param_1,bt_ancs_client *param_2)

{
  bt_conn *pbVar1;
  size_t sVar2;
  int iVar3;
  char *fmt;
  
  pbVar1 = bt_gatt_dm_conn_get(param_1);
  sVar2 = bt_gatt_dm_attr_cnt(param_1);
  if (sVar2 < 2) {
    printk("GATT Service could not be found during the discovery\n");
  }
  else {
    printk("The discovery procedure for GATT Service succeeded\n");
    iVar3 = ____bt_ancs_handles_assign(param_1,param_2);
    if (iVar3 == 0) {
      iVar3 = bt_gattp_subscribe_service_changed((bt_gattp *)param_2,(bt_gattp_indicate_cb)0x18b31);
      if (iVar3 == 0) goto LAB_00018ac6;
      fmt = "Cannot subscribe to Service Changed indication (err %d)\n";
    }
    else {
      fmt = "Could not init GATT Service client object, error: %d\n";
    }
    printk(fmt,iVar3);
  }
LAB_00018ac6:
  iVar3 = bt_gatt_dm_data_release(param_1);
  if (iVar3 != 0) {
    printk("Could not release the discovery data, error code: %d\n",iVar3);
  }
  discover_ancs(pbVar1,0);
  return;
}


