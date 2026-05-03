/*
 * Function: pairing_failed
 * Entry:    00018548
 * Prototype: undefined __stdcall pairing_failed(bt_conn * param_1, undefined4 param_2)
 */


void pairing_failed(bt_conn *param_1,undefined4 param_2)

{
  k_work_delayable *addr;
  size_t len;
  undefined4 extraout_r2;
  char acStack_30 [36];
  
  addr = k_work_delayable_from_work((k_work *)param_1);
  bt_addr_le_to_str((bt_addr_le_t *)addr,acStack_30,len);
  printk("Pairing failed conn: %s, reason %d\n",acStack_30,param_2);
  if (0 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): bt_conn_disconnect because Pairing failed\n");
    }
    else {
      ble_printk("%s(): bt_conn_disconnect because Pairing failed\n","pairing_failed",extraout_r2,
                 BLE_DEBUG);
    }
  }
  bt_conn_disconnect(param_1,'\x13');
  return;
}


