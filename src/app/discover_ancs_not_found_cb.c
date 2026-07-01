/*
 * Function: discover_ancs_not_found_cb
 * Entry:    00018a70
 * Prototype: undefined __stdcall discover_ancs_not_found_cb(bt_conn * param_1)
 */


void discover_ancs_not_found_cb(bt_conn *param_1)

{
  printk("ANCS could not be found during the discovery\n");
  atomic_and((atomic_t *)&ancs_discovery_flags,-2);
  discover_ancs(param_1,1);
  return;
}


