/*
 * Function: bt_gatt_dm_attr_chrc_val
 * Entry:    00082c38
 * Prototype: bt_gatt_chrc * __stdcall bt_gatt_dm_attr_chrc_val(bt_gatt_dm_attr * attr)
 */


/* exclude_from_export */

bt_gatt_chrc * bt_gatt_dm_attr_chrc_val(bt_gatt_dm_attr *attr)

{
  int iVar1;
  ushort in_r1;
  bt_gatt_chrc *pbVar2;
  ushort local_14;
  undefined2 local_12;
  
  pbVar2 = (bt_gatt_chrc *)0x0;
  _local_14 = CONCAT22(0x2803,in_r1 & 0xff00);
  iVar1 = bt_uuid_cmp((bt_uuid *)&local_14,(bt_uuid *)*attr);
  if (iVar1 == 0) {
    pbVar2 = (bt_gatt_chrc *)(*attr + -8);
  }
  return pbVar2;
}


