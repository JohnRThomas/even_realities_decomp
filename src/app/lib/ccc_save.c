/*
 * Function: ccc_save
 * Entry:    0005d5d4
 * Prototype: uint8_t __stdcall ccc_save(bt_gatt_attr * attr, uint16_t handle, void * user_data)
 */


/* exclude_from_export */

uint8_t ccc_save(bt_gatt_attr *attr,uint16_t handle,void *user_data)

{
  bt_gatt_ccc_cfg *pbVar1;
  int iVar2;
  
  if ((attr->write == (undefined *)0x5d711) &&
     (pbVar1 = ccc_find_cfg((_bt_gatt_ccc *)attr->user_data,*(bt_addr_le_t **)user_data,
                            *(uint8_t *)((int)user_data + 4)), pbVar1 != (bt_gatt_ccc_cfg *)0x0)) {
    iVar2 = *(int *)((int)user_data + 200);
    *(uint16_t *)((int)user_data + iVar2 * 4 + 8) = handle;
    *(short *)((int)user_data + iVar2 * 4 + 10) = (short)pbVar1[2];
    *(int *)((int)user_data + 200) = iVar2 + 1;
  }
  return '\x01';
}


