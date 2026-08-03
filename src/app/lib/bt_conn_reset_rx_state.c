/*
 * Function: bt_conn_reset_rx_state
 * Entry:    00084b8e
 * Prototype: void __stdcall bt_conn_reset_rx_state(bt_conn * conn)
 */


/* exclude_from_export */

void bt_conn_reset_rx_state(bt_conn *conn)

{
  if (conn->rx != (net_buf *)0x0) {
    net_buf_unref(conn->rx);
    conn->rx = (net_buf *)0x0;
  }
  return;
}


