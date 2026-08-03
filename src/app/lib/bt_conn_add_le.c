/*
 * Function: bt_conn_add_le
 * Entry:    0005a0e0
 * Prototype: bt_conn * __stdcall bt_conn_add_le(uint8_t id, bt_addr_le_t * peer)
 */


/* exclude_from_export */

bt_conn * bt_conn_add_le(uint8_t id,bt_addr_le_t *peer)

{
  bt_conn *conn;
  uint8_t uVar1;
  uint8_t uVar2;
  uint8_t uVar3;
  
  conn = bt_conn_new(&acl_conns,1);
  if (conn != (bt_conn *)0x0) {
    conn->id = id;
    uVar1 = (peer->a).val[0];
    uVar2 = (peer->a).val[1];
    uVar3 = (peer->a).val[2];
    (conn->le).dst.type = peer->type;
    (conn->le).dst.a.val[0] = uVar1;
    (conn->le).dst.a.val[1] = uVar2;
    (conn->le).dst.a.val[2] = uVar3;
    *(undefined2 *)((conn->le).dst.a.val + 3) = *(undefined2 *)((peer->a).val + 3);
    (conn->le).dst.a.val[5] = (peer->a).val[5];
    conn->sec_level = 2;
    conn->required_sec_level = 2;
    conn->type = BT_CONN_TYPE_LE;
    (conn->le).interval_min = 0x18;
    (conn->le).interval_max = 0x28;
  }
  return conn;
}


