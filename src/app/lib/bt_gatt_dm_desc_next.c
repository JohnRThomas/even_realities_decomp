/*
 * Function: bt_gatt_dm_desc_next
 * Entry:    00082cda
 * Prototype: bt_gatt_dm_attr * __stdcall bt_gatt_dm_desc_next(bt_gatt_dm * dm, bt_gatt_dm_attr * prev)
 */


/* exclude_from_export */

bt_gatt_dm_attr * bt_gatt_dm_desc_next(bt_gatt_dm *dm,bt_gatt_dm_attr *prev)

{
  ushort uVar1;
  bt_gatt_dm_attr *pbVar2;
  int iVar3;
  undefined4 local_c;
  
  local_c = prev;
  pbVar2 = bt_gatt_dm_attr_next(dm,prev);
  if (pbVar2 != (bt_gatt_dm_attr *)0x0) {
    uVar1 = (ushort)local_c;
    local_c = (bt_gatt_dm_attr *)CONCAT22(0x2803,uVar1 & 0xff00);
    iVar3 = bt_uuid_cmp((bt_uuid *)&local_c,(bt_uuid *)*pbVar2);
    if (iVar3 != 0) {
      return pbVar2;
    }
  }
  return (bt_gatt_dm_attr *)0x0;
}


