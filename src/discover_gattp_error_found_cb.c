/*
 * Function: discover_gattp_error_found_cb
 * Entry:    0001898c
 * Prototype: undefined __stdcall discover_gattp_error_found_cb(bt_conn * param_1)
 */


void discover_gattp_error_found_cb(bt_conn *param_1)

{
  printk("The discovery procedure for GATT Service failed, err %d\n");
  discover_ancs(param_1,0);
  return;
}


