/*
 * Function: auth_cancel
 * Entry:    000185a0
 * Prototype: undefined __stdcall auth_cancel(bt_conn * param_1)
 */


void auth_cancel(bt_conn *param_1)

{
  k_work_delayable *addr;
  size_t len;
  undefined4 extraout_r2;
  char acStack_28 [32];
  
  addr = k_work_delayable_from_work((k_work *)param_1);
  bt_addr_le_to_str((bt_addr_le_t *)addr,acStack_28,len);
  printk("Pairing cancelled: %s\n",acStack_28);
  if (0 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): bt_conn_disconnect because Pairing cancelled\n");
    }
    else {
      ble_printk("%s(): bt_conn_disconnect because Pairing cancelled\n","auth_cancel",extraout_r2,
                 BLE_DEBUG);
    }
  }
  bt_conn_disconnect(param_1,'\x13');
  return;
}


