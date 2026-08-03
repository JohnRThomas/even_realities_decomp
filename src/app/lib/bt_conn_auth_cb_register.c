/*
 * Function: bt_conn_auth_cb_register
 * Entry:    0005a5a8
 * Prototype: int __stdcall bt_conn_auth_cb_register(bt_conn_auth_cb * cb)
 */


/* exclude_from_export_ai */

int bt_conn_auth_cb_register(bt_conn_auth_cb *cb)

{
  if (cb != (bt_conn_auth_cb *)0x0) {
    if (DAT_2000b708 != (bt_conn_auth_cb *)0x0) {
      return -0x78;
    }
    if ((cb->passkey_confirm == (undefined *)0x0) &&
       ((((cb->pairing_accept != (undefined *)0x0 || (cb->passkey_display != (undefined *)0x0)) ||
         (cb->passkey_display_keypress != (undefined *)0x0)) ||
        (cb->oob_data_request != (undefined *)0x0)))) {
      return -0x16;
    }
  }
  DAT_2000b708 = cb;
  return 0;
}


