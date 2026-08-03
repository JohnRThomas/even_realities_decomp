/*
 * Function: bt_conn_lookup_addr_le
 * Entry:    0005a120
 * Prototype: bt_conn * __stdcall bt_conn_lookup_addr_le(uint8_t id, bt_addr_le_t * peer)
 */


/* exclude_from_export_ai */

bt_conn * bt_conn_lookup_addr_le(uint8_t id,bt_addr_le_t *peer)

{
  bool bVar1;
  bt_conn *conn;
  
  conn = bt_conn_ref(&acl_conns);
  if (conn != (bt_conn *)0x0) {
    if ((conn->type == BT_CONN_TYPE_LE) && (bVar1 = bt_conn_is_peer_addr_le(conn,id,peer), bVar1)) {
      return conn;
    }
    bt_conn_unref(conn);
  }
  return (bt_conn *)0x0;
}


