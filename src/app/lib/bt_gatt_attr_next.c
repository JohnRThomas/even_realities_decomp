/*
 * Function: bt_gatt_attr_next
 * Entry:    0005e364
 * Prototype: bt_gatt_attr * __stdcall bt_gatt_attr_next(bt_gatt_attr * attr)
 */


/* exclude_from_export */

bt_gatt_attr * bt_gatt_attr_next(bt_gatt_attr *attr)

{
  uint16_t uVar1;
  bt_gatt_attr *local_c [2];
  
  local_c[0] = (bt_gatt_attr *)0x0;
  uVar1 = bt_gatt_attr_get_handle(attr);
  bt_gatt_foreach_attr(uVar1 + 1,uVar1 + 1,&LAB_0008626a_1,local_c);
  return local_c[0];
}


