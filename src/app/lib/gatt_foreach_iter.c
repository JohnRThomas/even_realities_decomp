/*
 * Function: gatt_foreach_iter
 * Entry:    00085eca
 * Prototype: uint8_t __stdcall gatt_foreach_iter(bt_gatt_attr * attr, uint16_t handle, uint16_t start_handle, uint16_t end_handle, bt_uuid * uuid, void * attr_data, uint16_t * num_matches, bt_gatt_attr_func_t func, void * user_data)
 */


/* exclude_from_export_ai */

uint8_t gatt_foreach_iter(bt_gatt_attr *attr,uint16_t handle,uint16_t start_handle,
                         uint16_t end_handle,bt_uuid *uuid,void *attr_data,uint16_t *num_matches,
                         bt_gatt_attr_func_t func,void *user_data)

{
  uint8_t uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = (uint)end_handle;
  uVar3 = (uint)handle;
  if (uVar3 <= uVar4) {
    if (((uVar3 < start_handle) ||
        ((uuid != (bt_uuid *)0x0 && (iVar2 = bt_uuid_cmp(uuid,(bt_uuid *)attr->uuid), iVar2 != 0))))
       || ((attr_data != (void *)0x0 && (attr->user_data != attr_data)))) {
      return '\x01';
    }
    *num_matches = *num_matches - 1;
    uVar1 = (*(code *)func)(attr,uVar3,user_data,func,uVar4);
    if (*num_matches != 0) {
      return uVar1;
    }
  }
  return '\0';
}


