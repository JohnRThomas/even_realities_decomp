/*
 * Function: gatt_sub_find
 * Entry:    0005cf1c
 * Prototype: gatt_sub * __stdcall gatt_sub_find(bt_conn * conn)
 */


/* exclude_from_export */

gatt_sub * gatt_sub_find(bt_conn *conn)

{
  bool bVar1;
  gatt_sub *pgVar2;
  int iVar3;
  
  iVar3 = 0;
  pgVar2 = (gatt_sub *)&DAT_2000b8f8;
  while( true ) {
    if (conn == (bt_conn *)0x0) {
      bVar1 = bt_addr_le_eq(&pgVar2->peer,(bt_addr_le_t *)&DAT_000f0b50);
    }
    else {
      bVar1 = bt_conn_is_peer_addr_le(conn,pgVar2->id,&pgVar2->peer);
    }
    if (bVar1 != false) break;
    iVar3 = iVar3 + 1;
    pgVar2 = pgVar2 + 1;
    if (iVar3 == 3) {
      return (gatt_sub *)0x0;
    }
  }
  return pgVar2;
}


