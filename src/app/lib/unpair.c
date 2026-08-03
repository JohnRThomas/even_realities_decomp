/*
 * Function: unpair
 * Entry:    0005662c
 * Prototype: void __stdcall unpair(int id)
 */


/* exclude_from_export_ai */

void unpair(int id)

{
  uint8_t id_00;
  bt_keys *keys;
  bt_addr_le_t *in_r1;
  code *pcVar1;
  int iVar2;
  bt_conn *conn;
  
  id_00 = (uint8_t)id;
  conn = bt_conn_lookup_addr_le(id_00,in_r1);
  if (conn == (bt_conn *)0x0) {
LAB_0005664c:
    keys = bt_keys_find_addr(id_00,in_r1);
    if (keys == (bt_keys *)0x0) goto LAB_00056658;
  }
  else {
    if (conn->type != BT_CONN_TYPE_LE) {
      bt_conn_disconnect(conn,'\x13');
      bt_conn_unref(conn);
      goto LAB_0005664c;
    }
    keys = (bt_keys *)(conn->le).keys;
    (conn->le).keys = (undefined *)0x0;
    bt_conn_disconnect(conn,'\x13');
    bt_conn_unref(conn);
    if (keys == (bt_keys *)0x0) goto LAB_0005664c;
  }
  bt_keys_clear(keys);
LAB_00056658:
  bt_gatt_clear(id_00,in_r1);
  if (DAT_2000b700 == (int *)0x0) {
    return;
  }
  iVar2 = *DAT_2000b700;
  if (iVar2 != 0) {
    iVar2 = iVar2 + -0xc;
  }
  pcVar1 = (code *)DAT_2000b700[-1];
  if (pcVar1 == (code *)0x0) goto LAB_00056678;
  do {
    (*pcVar1)(id);
LAB_00056678:
    if (iVar2 == 0) {
      return;
    }
    do {
      pcVar1 = *(code **)(iVar2 + 8);
      if (*(int *)(iVar2 + 0xc) == 0) {
        iVar2 = 0;
        if (pcVar1 == (code *)0x0) {
          return;
        }
        break;
      }
      iVar2 = *(int *)(iVar2 + 0xc) + -0xc;
    } while (pcVar1 == (code *)0x0);
  } while( true );
}


