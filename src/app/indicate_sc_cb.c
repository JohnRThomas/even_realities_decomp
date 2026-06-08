/*
 * Function: indicate_sc_cb
 * Entry:    00018b30
 * Prototype: undefined __stdcall indicate_sc_cb(undefined4 * param_1, undefined4 param_2, int param_3)
 */


/* WARNING: Struct "GlassesState": ignoring multiple overlapping fields */

void indicate_sc_cb(undefined4 *param_1,undefined4 param_2,int param_3)

{
  if (param_3 != 0) {
    return;
  }
  DAT_2001095e = DAT_2001095e + 1;
  if (DAT_2001095e < 5) {
    GLOBAL_STATE.sem_8.count = GLOBAL_STATE.sem_8.count | 4;
    discover_ancs((bt_conn *)*param_1,1);
    return;
  }
  DAT_2001095e = 0;
  if (0 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): disconnect because can not discover ancs.\n");
    }
    else {
      ble_printk("%s(): disconnect because can not discover ancs.\n","indicate_sc_cb",0,BLE_DEBUG);
    }
  }
  bt_conn_disconnect((bt_conn *)*param_1,'\x13');
  return;
}


