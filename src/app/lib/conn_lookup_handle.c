/*
 * Function: conn_lookup_handle
 * Entry:    00084ba0
 * Prototype: bt_conn * __stdcall conn_lookup_handle(bt_conn * conns, size_t size, uint16_t handle)
 */


/* exclude_from_export */

bt_conn * conn_lookup_handle(bt_conn *conns,size_t size,uint16_t handle)

{
  bt_conn *conn;
  size_t sVar1;
  
  sVar1 = 0;
  do {
    if (sVar1 == size) {
      return (bt_conn *)0x0;
    }
    conn = bt_conn_ref(conns + sVar1);
    if (conn != (bt_conn *)0x0) {
      if (((conn->state == 1) || (conn->state - 7 < 2)) && (conn->handle == handle)) {
        return conn;
      }
      bt_conn_unref(conn);
    }
    sVar1 = sVar1 + 1;
  } while( true );
}


