/*
 * Function: bt_gatt_attr_value_handle
 * Entry:    000863c6
 * Prototype: uint16_t __stdcall bt_gatt_attr_value_handle(bt_gatt_attr * attr)
 */


/* exclude_from_export_ai */

uint16_t bt_gatt_attr_value_handle(bt_gatt_attr *attr)

{
  uint16_t uVar1;
  int iVar2;
  ushort in_r1;
  ushort local_c;
  undefined2 local_a;
  
  if (attr != (bt_gatt_attr *)0x0) {
    _local_c = CONCAT22(0x2803,in_r1 & 0xff00);
    iVar2 = bt_uuid_cmp((bt_uuid *)attr->uuid,(bt_uuid *)&local_c);
    if (iVar2 == 0) {
      if (*(uint16_t *)(attr->user_data + 4) != 0) {
        return *(uint16_t *)(attr->user_data + 4);
      }
      uVar1 = bt_gatt_attr_get_handle(attr);
      return uVar1 + 1;
    }
  }
  return 0;
}


