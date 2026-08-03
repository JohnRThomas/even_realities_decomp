/*
 * Function: discovery_complete
 * Entry:    00051c04
 * Prototype: void __stdcall discovery_complete(bt_gatt_dm * dm, void * context)
 */


/* exclude_from_export */

void discovery_complete(bt_gatt_dm *dm,void *context)

{
  DAT_2000ac6c = DAT_2000ac6c | 2;
  if (bt_gatt_dm_cb_ptr->completed == (completed *)0x0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00051c22. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*bt_gatt_dm_cb_ptr->completed)(&bt_gatt_dm_inst,bt_gatt_dm_inst.context);
  return;
}


