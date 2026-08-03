/*
 * Function: bt_ancs_do_ds_notif_cb
 * Entry:    00082f78
 * Prototype: void __stdcall bt_ancs_do_ds_notif_cb(bt_ancs_client * ancs_c, bt_ancs_attr_response * response)
 */


/* exclude_from_export */

void bt_ancs_do_ds_notif_cb(bt_ancs_client *ancs_c,bt_ancs_attr_response *response)

{
  if (*(code **)(ancs_c + 0x1064) != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00082f80. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(ancs_c + 0x1064))();
    return;
  }
  return;
}


