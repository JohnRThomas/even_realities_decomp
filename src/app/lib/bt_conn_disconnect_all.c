/*
 * Function: bt_conn_disconnect_all
 * Entry:    00059c3c
 * Prototype: void __stdcall bt_conn_disconnect_all(uint8_t id)
 */


/* exclude_from_export_ai */

void bt_conn_disconnect_all(uint8_t id)

{
  bt_conn_foreach(BT_CONN_TYPE_ALL,(void *)0x84be5,(void *)0x0);
  return;
}


