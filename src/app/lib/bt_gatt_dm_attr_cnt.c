/*
 * Function: bt_gatt_dm_attr_cnt
 * Entry:    00082c64
 * Prototype: size_t __stdcall bt_gatt_dm_attr_cnt(bt_gatt_dm * dm)
 */


/* exclude_from_export */

size_t bt_gatt_dm_attr_cnt(bt_gatt_dm *dm)

{
  return *(size_t *)((int)&dm[5].STATE_NUM_ + 3);
}


