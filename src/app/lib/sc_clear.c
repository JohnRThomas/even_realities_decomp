/*
 * Function: sc_clear
 * Entry:    0005d33c
 * Prototype: void __stdcall sc_clear(bt_conn * conn)
 */


/* exclude_from_export */

void sc_clear(bt_conn *conn)

{
  bool bVar1;
  gatt_sc_cfg *cfg;
  bt_conn_le *addr;
  char local_20 [4];
  char *local_1c;
  int iStack_18;
  
  addr = &conn->le;
  bVar1 = bt_addr_le_is_bonded(conn->id,&addr->dst);
  if (bVar1) {
    iStack_18 = bt_gatt_clear_sc(conn->id,&addr->dst);
    if (iStack_18 != 0) {
      local_1c = "Failed to clear SC %d";
      local_20[0] = '\x03';
      local_20[1] = '\0';
      local_20[2] = '\0';
      local_20[3] = '\0';
      LOG_ERR(&PTR_s_bt_gatt_0008b8d8,0x1840,local_20);
    }
  }
  else {
    cfg = find_sc_cfg(conn->id,&addr->dst);
    if (cfg != (gatt_sc_cfg *)0x0) {
      clear_sc_cfg(cfg);
    }
  }
  return;
}


