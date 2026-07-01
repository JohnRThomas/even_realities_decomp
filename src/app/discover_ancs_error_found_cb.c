/*
 * Function: discover_ancs_error_found_cb
 * Entry:    000189a8
 * Prototype: undefined __stdcall discover_ancs_error_found_cb(bt_conn * param_1)
 */


void discover_ancs_error_found_cb(bt_conn *param_1)

{
  printk("The discovery procedure for ANCS failed, err %d\n");
  atomic_and((atomic_t *)&ancs_discovery_flags,-2);
  discover_ancs(param_1,1);
  return;
}


