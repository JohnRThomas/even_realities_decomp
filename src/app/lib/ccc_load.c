/*
 * Function: ccc_load
 * Entry:    0005d098
 * Prototype: uint8_t __stdcall ccc_load(bt_gatt_attr * attr, uint16_t handle, void * user_data)
 */


/* exclude_from_export_ai */

uint8_t ccc_load(bt_gatt_attr *attr,uint16_t handle,void *user_data)

{
  ushort uVar1;
  bt_gatt_ccc_cfg *pbVar2;
  int iVar3;
  undefined1 *extraout_r2;
  bt_gatt_ccc_cfg *extraout_r2_00;
  bt_addr_le_t *addr;
  _bt_gatt_ccc *ccc;
  
  if (attr->write == (undefined *)0x5d711) {
    ccc = (_bt_gatt_ccc *)attr->user_data;
    if (*(ushort **)((int)user_data + 8) != (ushort *)0x0) {
      if (*(int *)((int)user_data + 0xc) == 0) {
        return '\0';
      }
      uVar1 = **(ushort **)((int)user_data + 8);
      if (uVar1 == handle) {
        addr = *(bt_addr_le_t **)user_data;
        pbVar2 = ccc_find_cfg(ccc,addr,*(uint8_t *)((int)user_data + 4));
        if (pbVar2 == (bt_gatt_ccc_cfg *)0x0) {
          pbVar2 = ccc_find_cfg(ccc,(bt_addr_le_t *)&DAT_000f0b50,'\0');
          if (pbVar2 == (bt_gatt_ccc_cfg *)0x0) goto LAB_0005d0d6;
          bt_addr_le_copy((bt_addr_le_t *)((int)pbVar2 + 1),addr);
          *(undefined1 *)extraout_r2_00 = *(undefined1 *)((int)user_data + 4);
          pbVar2 = extraout_r2_00;
        }
        *(undefined2 *)(pbVar2 + 2) = *(undefined2 *)(*(int *)((int)user_data + 8) + 2);
      }
      else if (handle <= uVar1) {
        return '\x01';
      }
LAB_0005d0d6:
      iVar3 = *(int *)((int)user_data + 0xc) + -1;
      *(int *)((int)user_data + 0xc) = iVar3;
      *(int *)((int)user_data + 8) = *(int *)((int)user_data + 8) + 4;
      return iVar3 != 0;
    }
    pbVar2 = ccc_find_cfg(ccc,*(bt_addr_le_t **)user_data,*(uint8_t *)((int)user_data + 4));
    if (pbVar2 != (bt_gatt_ccc_cfg *)0x0) {
      bt_addr_le_copy((bt_addr_le_t *)((int)pbVar2 + 1),(bt_addr_le_t *)&DAT_000f0b50);
      *extraout_r2 = 0;
      *(undefined2 *)(extraout_r2 + 8) = 0;
    }
  }
  return '\x01';
}


