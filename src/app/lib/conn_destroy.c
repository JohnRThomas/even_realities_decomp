/*
 * Function: conn_destroy
 * Entry:    00084be4
 * Prototype: void __stdcall conn_destroy(bt_conn * conn, void * data)
 */


/* exclude_from_export_ai */

void conn_destroy(bt_conn *conn,void *data)

{
  if (conn->state - 7 < 2) {
    bt_conn_set_state(conn,1);
  }
  bt_conn_set_state(conn,0);
  return;
}


