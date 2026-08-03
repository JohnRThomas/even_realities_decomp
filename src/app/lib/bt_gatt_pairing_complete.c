/*
 * Function: bt_gatt_pairing_complete
 * Entry:    0008678a
 * Prototype: void __stdcall bt_gatt_pairing_complete(bt_conn * conn, bool bonded)
 */


/* exclude_from_export_ai */

void bt_gatt_pairing_complete(bt_conn *conn,bool bonded)

{
  if (bonded) {
    bt_gatt_store_ccc(conn->id,&(conn->le).dst);
    bt_gatt_store_cf(conn->id,&(conn->le).dst);
    return;
  }
  return;
}


