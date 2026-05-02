/*
 * Function: discover_gattp_not_found_cb
 * Entry:    00018b14
 * Prototype: undefined __stdcall discover_gattp_not_found_cb(bt_conn * param_1)
 */


void discover_gattp_not_found_cb(bt_conn *param_1)

{
  printk("GATT Service could not be found during the discovery\n");
  discover_ancs(param_1,0);
  return;
}


