/*
 * Function: bt_conn_connected
 * Entry:    00084c02
 * Prototype: void __stdcall bt_conn_connected(bt_conn * conn)
 */


/* exclude_from_export */

void bt_conn_connected(bt_conn *conn)

{
  bt_l2cap_connected(conn);
  notify_connected(conn);
  return;
}


