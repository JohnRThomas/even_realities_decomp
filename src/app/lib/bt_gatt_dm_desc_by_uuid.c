/*
 * Function: bt_gatt_dm_desc_by_uuid
 * Entry:    00082d08
 * Prototype: bt_gatt_dm_attr * __stdcall bt_gatt_dm_desc_by_uuid(bt_gatt_dm * dm, bt_gatt_dm_attr * attr_chrc, bt_uuid * uuid)
 */


/* exclude_from_export */

bt_gatt_dm_attr * bt_gatt_dm_desc_by_uuid(bt_gatt_dm *dm,bt_gatt_dm_attr *attr_chrc,bt_uuid *uuid)

{
  int iVar1;
  
  do {
    attr_chrc = bt_gatt_dm_desc_next(dm,attr_chrc);
    if (attr_chrc == (bt_gatt_dm_attr *)0x0) {
      return (bt_gatt_dm_attr *)0x0;
    }
    iVar1 = bt_uuid_cmp(uuid,(bt_uuid *)*attr_chrc);
  } while (iVar1 != 0);
  return attr_chrc;
}


