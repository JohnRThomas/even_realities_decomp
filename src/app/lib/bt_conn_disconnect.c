/*
 * Function: bt_conn_disconnect
 * Entry:    00084e60
 * Prototype: int __stdcall bt_conn_disconnect(bt_conn * conn, uint8_t reason)
 */


/* exclude_from_export_ai */

int bt_conn_disconnect(bt_conn *conn,uint8_t reason)

{
  int iVar1;
  
  iVar1 = k_work_cancel_delayable((k_work_delayable *)&(conn->le).keys);
  return iVar1;
}


