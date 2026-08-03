/*
 * Function: bt_nus_send
 * Entry:    000527c4
 * Prototype: int __stdcall bt_nus_send(bt_conn * conn, uint8_t * data, uint16_t len)
 */


/* exclude_from_export */

int bt_nus_send(bt_conn *conn,uint8_t *data,uint16_t len)

{
  bool bVar1;
  int iVar2;
  bt_gatt_notify_params bStack_28;
  undefined **local_24;
  uint8_t *puStack_20;
  uint16_t local_1c;
  undefined4 local_18;
  
  memset(&bStack_28,0,0x18);
  local_24 = &PTR_DAT_0008e8d0;
  local_18 = 0x5279d;
  puStack_20 = data;
  local_1c = len;
  if ((conn == (bt_conn *)0x0) ||
     (bVar1 = bt_gatt_is_subscribed(conn,(bt_gatt_attr *)&PTR_DAT_0008e8d0,1), bVar1)) {
    iVar2 = bt_gatt_notify_cb(conn,&bStack_28);
  }
  else {
    iVar2 = -0x16;
  }
  return iVar2;
}


