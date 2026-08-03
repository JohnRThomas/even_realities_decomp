/*
 * Function: remove_peer_from_attr
 * Entry:    0005d580
 * Prototype: uint8_t __stdcall remove_peer_from_attr(bt_gatt_attr * attr, uint16_t handle, void * user_data)
 */


/* exclude_from_export */

uint8_t remove_peer_from_attr(bt_gatt_attr *attr,uint16_t handle,void *user_data)

{
  bt_gatt_ccc_cfg *pbVar1;
  
  if ((attr->write == (undefined *)0x5d711) &&
     (pbVar1 = ccc_find_cfg((_bt_gatt_ccc *)attr->user_data,*(bt_addr_le_t **)user_data,
                            *(uint8_t *)((int)user_data + 4)), pbVar1 != (bt_gatt_ccc_cfg *)0x0)) {
    *pbVar1 = 0;
    pbVar1[1] = 0;
    *(undefined2 *)(pbVar1 + 2) = 0;
  }
  return '\x01';
}


