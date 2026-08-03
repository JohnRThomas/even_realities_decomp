/*
 * Function: bt_gatt_dm_service_get
 * Entry:    00082c6a
 * Prototype: bt_gatt_dm_attr * __stdcall bt_gatt_dm_service_get(bt_gatt_dm * dm)
 */


/* exclude_from_export */

bt_gatt_dm_attr * bt_gatt_dm_service_get(bt_gatt_dm *dm)

{
  return (bt_gatt_dm_attr *)&dm->u16;
}


