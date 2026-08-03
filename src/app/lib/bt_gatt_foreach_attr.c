/*
 * Function: bt_gatt_foreach_attr
 * Entry:    00086454
 * Prototype: void __stdcall bt_gatt_foreach_attr(uint16_t start_handle, uint16_t end_handle, bt_gatt_attr_func_t func, void * user_data)
 */


/* exclude_from_export */

void bt_gatt_foreach_attr
               (uint16_t start_handle,uint16_t end_handle,bt_gatt_attr_func_t func,void *user_data)

{
  bt_gatt_foreach_attr_type(start_handle,end_handle,(bt_uuid *)0x0,(void *)0x0,0,func,user_data);
  return;
}


