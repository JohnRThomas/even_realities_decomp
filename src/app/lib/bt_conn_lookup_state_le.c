/*
 * Function: bt_conn_lookup_state_le
 * Entry:    0005a1b4
 * Prototype: bt_conn * __stdcall bt_conn_lookup_state_le(uint8_t id, bt_addr_le_t * peer, bt_conn_state_t state)
 */


/* exclude_from_export */

bt_conn * bt_conn_lookup_state_le(uint8_t id,bt_addr_le_t *peer,bt_conn_state_t state)

{
  bool bVar1;
  bt_conn *conn;
  
  conn = bt_conn_ref(&acl_conns);
  if (conn != (bt_conn *)0x0) {
    if (((conn->type == BT_CONN_TYPE_LE) &&
        (((peer == (bt_addr_le_t *)0x0 || (bVar1 = bt_conn_is_peer_addr_le(conn,id,peer), bVar1)) &&
         (conn->state == state)))) && (conn->id == id)) {
      return conn;
    }
    bt_conn_unref(conn);
  }
  return (bt_conn *)0x0;
}


