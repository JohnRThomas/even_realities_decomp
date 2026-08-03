/*
 * Function: find_cf_cfg
 * Entry:    0005ceb0
 * Prototype: gatt_cf_cfg * __stdcall find_cf_cfg(bt_conn * conn)
 */


/* exclude_from_export */

gatt_cf_cfg * find_cf_cfg(bt_conn *conn)

{
  bool bVar1;
  gatt_cf_cfg *pgVar2;
  int iVar3;
  
  iVar3 = 0;
  pgVar2 = (gatt_cf_cfg *)&DAT_2000b8b4;
  while( true ) {
    if (conn == (bt_conn *)0x0) {
      bVar1 = bt_addr_le_eq(&pgVar2->peer,(bt_addr_le_t *)&DAT_000f0b50);
    }
    else {
      bVar1 = bt_conn_is_peer_addr_le(conn,pgVar2->id,&pgVar2->peer);
    }
    if (bVar1 != false) break;
    iVar3 = iVar3 + 1;
    pgVar2 = (gatt_cf_cfg *)(pgVar2[1].peer.a.val + 1);
    if (iVar3 == 3) {
      return (gatt_cf_cfg *)0x0;
    }
  }
  return pgVar2;
}


