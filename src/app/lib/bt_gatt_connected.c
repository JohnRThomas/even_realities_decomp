/*
 * Function: bt_gatt_connected
 * Entry:    0005f974
 * Prototype: void __stdcall bt_gatt_connected(bt_conn * conn)
 */


/* exclude_from_export */

void bt_gatt_connected(bt_conn *conn)

{
  bool bVar1;
  bt_security_t bVar2;
  int iVar3;
  char local_50 [4];
  char *local_4c;
  char *buf;
  char acStack_40 [4];
  bt_conn *local_3c;
  byte local_38;
  char acStack_34 [36];
  
  buf = acStack_40;
  local_38 = 1;
  local_3c = conn;
  bVar1 = bt_addr_le_is_bonded(conn->id,&(conn->le).dst);
  if (bVar1) {
    if (conn->id == '\0') {
      buf = (char *)0x0;
    }
    else {
      u8_to_dec(buf,'\x04',conn->id);
    }
    bt_settings_encode_key(acStack_34,0x24,"ccc",&(conn->le).dst,buf);
    settings_load_subtree_direct(acStack_34,(settings_load_direct_cb)0x5e239,acStack_34);
  }
  bt_gatt_foreach_attr(1,0xffff,(bt_gatt_attr_func_t)0x5e801,&local_3c);
  bVar2 = bt_conn_get_security(conn);
  if ((bVar2 < local_38) && (iVar3 = bt_conn_set_security(conn,local_38), iVar3 != 0)) {
    local_4c = "Failed to set security for bonded peer (%d)";
    local_50[0] = '\x03';
    local_50[1] = '\0';
    local_50[2] = '\0';
    local_50[3] = '\0';
    LOG_ERR(&PTR_s_bt_gatt_0008b8d8,0x1880,local_50);
  }
  return;
}


