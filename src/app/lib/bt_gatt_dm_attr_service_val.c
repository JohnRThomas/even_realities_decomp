/*
 * Function: bt_gatt_dm_attr_service_val
 * Entry:    00082bf8
 * Prototype: bt_gatt_service_val * __stdcall bt_gatt_dm_attr_service_val(bt_gatt_dm_attr * attr)
 */


/* exclude_from_export */

bt_gatt_service_val * bt_gatt_dm_attr_service_val(bt_gatt_dm_attr *attr)

{
  int iVar1;
  ushort in_r1;
  ushort local_18;
  undefined2 local_16;
  ushort local_14;
  undefined2 local_12;
  
  _local_18 = CONCAT22(0x2800,(ushort)attr & 0xff00);
  local_14 = in_r1;
  iVar1 = bt_uuid_cmp((bt_uuid *)&local_18,(bt_uuid *)*attr);
  if (iVar1 != 0) {
    local_14 = local_14 & 0xff00;
    _local_14 = CONCAT22(0x2801,local_14);
    iVar1 = bt_uuid_cmp((bt_uuid *)&local_14,(bt_uuid *)*attr);
    if (iVar1 != 0) {
      return (bt_gatt_service_val *)0x0;
    }
  }
  return (bt_gatt_service_val *)(*attr + -8);
}


