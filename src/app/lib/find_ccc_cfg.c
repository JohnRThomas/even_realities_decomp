/*
 * Function: find_ccc_cfg
 * Entry:    0005cef4
 * Prototype: bt_gatt_ccc_cfg * __stdcall find_ccc_cfg(bt_conn * conn, _bt_gatt_ccc * ccc)
 */


/* exclude_from_export_ai */

bt_gatt_ccc_cfg * find_ccc_cfg(bt_conn *conn,_bt_gatt_ccc *ccc)

{
  bool bVar1;
  
  if (conn == (bt_conn *)0x0) {
    bVar1 = bt_addr_le_eq((bt_addr_le_t *)((int)ccc + 1),(bt_addr_le_t *)&DAT_000f0b50);
  }
  else {
    bVar1 = bt_conn_is_peer_addr_le(conn,(uint8_t)*ccc,(bt_addr_le_t *)((int)ccc + 1));
  }
  if (bVar1 == false) {
    ccc = (bt_gatt_ccc_cfg *)0x0;
  }
  return ccc;
}


