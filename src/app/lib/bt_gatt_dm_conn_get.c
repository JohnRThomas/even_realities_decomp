/*
 * Function: bt_gatt_dm_conn_get
 * Entry:    00082c60
 * Prototype: bt_conn * __stdcall bt_gatt_dm_conn_get(bt_gatt_dm * dm)
 */


/* exclude_from_export */

bt_conn * bt_gatt_dm_conn_get(bt_gatt_dm *dm)

{
  return dm->conn;
}


