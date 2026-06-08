/*
 * Function: discover_ancs_error_found_cb
 * Entry:    000189a8
 * Prototype: undefined __stdcall discover_ancs_error_found_cb(bt_conn * param_1)
 */


/* WARNING: Struct "GlassesState": ignoring multiple overlapping fields */

void discover_ancs_error_found_cb(bt_conn *param_1)

{
  printk("The discovery procedure for ANCS failed, err %d\n");
  atomic_and((atomic_t *)&GLOBAL_STATE.sem_8.count,-2);
  discover_ancs(param_1,1);
  return;
}


