/*
 * Function: bt_gatt_dm_attr_next
 * Entry:    00082cb2
 * Prototype: bt_gatt_dm_attr * __stdcall bt_gatt_dm_attr_next(bt_gatt_dm * dm, bt_gatt_dm_attr * prev)
 */


/* exclude_from_export */

bt_gatt_dm_attr * bt_gatt_dm_attr_next(bt_gatt_dm *dm,bt_gatt_dm_attr *prev)

{
  dword *pdVar1;
  bool bVar2;
  
  pdVar1 = &dm->u16;
  if ((prev != (bt_gatt_dm_attr *)0x0) && (bVar2 = prev < pdVar1, pdVar1 = (dword *)prev, bVar2)) {
    return (bt_gatt_dm_attr *)0x0;
  }
  pdVar1 = pdVar1 + 2;
  if (&dm->u16 + *(int *)((int)&dm[5].STATE_NUM_ + 3) * 2 <= pdVar1) {
    pdVar1 = (dword *)0x0;
  }
  return (bt_gatt_dm_attr *)pdVar1;
}


