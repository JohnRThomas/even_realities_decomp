/*
 * Function: bt_conn_is_peer_addr_le
 * Entry:    00084c9e
 * Prototype: bool __stdcall bt_conn_is_peer_addr_le(bt_conn * conn, uint8_t id, bt_addr_le_t * peer)
 */


/* exclude_from_export */

bool bt_conn_is_peer_addr_le(bt_conn *conn,uint8_t id,bt_addr_le_t *peer)

{
  bool bVar1;
  int iVar2;
  bt_addr_le_t *m2;
  
  if (conn->id == id) {
    iVar2 = memcmp(peer,&conn->le,7);
    if (iVar2 == 0) {
      bVar1 = true;
    }
    else {
      if (conn->role == '\0') {
        m2 = &(conn->le).resp_addr;
      }
      else {
        m2 = &(conn->le).init_addr;
      }
      iVar2 = memcmp(peer,m2,7);
      bVar1 = iVar2 == 0;
    }
  }
  else {
    bVar1 = false;
  }
  return bVar1;
}


