/*
 * Function: disconnected_cb
 * Entry:    0005d670
 * Prototype: void __stdcall disconnected_cb(bt_conn * conn, uint8_t reason)
 */


/* exclude_from_export */

void disconnected_cb(bt_conn *conn,uint8_t reason)

{
  bool bVar1;
  bt_conn *conn_00;
  bt_conn *in_r2;
  int iVar2;
  uint8_t *puVar3;
  bt_addr_le_t *peer;
  
  iVar2._0_1_ = conn->id;
  iVar2._1_1_ = conn->sec_level;
  iVar2._2_1_ = conn->required_sec_level;
  iVar2._3_1_ = conn->encrypt;
  if ((iVar2 == 0x5d711) && (puVar3 = *(uint8_t **)&conn->err, *(short *)(puVar3 + 10) != 0)) {
    if (*(short *)(puVar3 + 8) != 0) {
      peer = (bt_addr_le_t *)(puVar3 + 1);
      bVar1 = bt_conn_is_peer_addr_le(in_r2,*puVar3,peer);
      if (bVar1) {
        bVar1 = bt_addr_le_is_bonded(in_r2->id,&(in_r2->le).dst);
        if (bVar1) {
          bt_addr_le_copy(peer,&(in_r2->le).dst);
        }
        else {
          if (puVar3 == &DAT_20002a40) {
            sc_clear(in_r2);
          }
          bt_addr_le_copy(peer,(bt_addr_le_t *)&DAT_000f0b50);
          *puVar3 = '\0';
          puVar3[8] = '\0';
          puVar3[9] = '\0';
        }
      }
      else {
        conn_00 = bt_conn_lookup_addr_le(*puVar3,peer);
        if (conn_00 != (bt_conn *)0x0) {
          if (conn_00->state == 7) {
            bt_conn_unref(conn_00);
            return;
          }
          bt_conn_unref(conn_00);
        }
      }
    }
    puVar3[10] = '\0';
    puVar3[0xb] = '\0';
    if (*(code **)(puVar3 + 0xc) != (code *)0x0) {
      (**(code **)(puVar3 + 0xc))(conn);
    }
  }
  return;
}


