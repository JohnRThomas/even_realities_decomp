/*
 * Function: gen_hash_m
 * Entry:    00085dc4
 * Prototype: uint8_t __stdcall gen_hash_m(bt_gatt_attr * attr, uint16_t handle, void * user_data)
 */


/* exclude_from_export_ai */

uint8_t gen_hash_m(bt_gatt_attr *attr,uint16_t handle,void *user_data)

{
  int iVar1;
  uint16_t *data;
  size_t dlen;
  uint uVar2;
  char *pcVar3;
  uint16_t local_2e;
  uint16_t auStack_2c [12];
  
  pcVar3 = attr->uuid;
  if (*pcVar3 != '\0') {
    return '\x01';
  }
  uVar2 = (uint)*(ushort *)(pcVar3 + 2);
  local_2e = handle;
  if (uVar2 == 0x2900) {
LAB_00085de4:
    iVar1 = tc_cmac_update(user_data,(uint8_t *)&local_2e,2);
    if (iVar1 != 0) {
      local_2e = *(uint16_t *)(pcVar3 + 2);
      iVar1 = tc_cmac_update(user_data,(uint8_t *)&local_2e,2);
      if (iVar1 != 0) {
        dlen = (*(code *)attr->read)(0,attr,auStack_2c,0x13,0);
        if ((int)dlen < 0) goto LAB_00085dfa;
        data = auStack_2c;
LAB_00085e3c:
        iVar1 = tc_cmac_update(user_data,(uint8_t *)data,dlen);
        if (iVar1 != 0) {
          return '\x01';
        }
      }
    }
  }
  else {
    if (uVar2 < 0x2901) {
      if (3 < uVar2 - 0x2800) {
        return '\x01';
      }
      goto LAB_00085de4;
    }
    if (4 < (uVar2 + 0xd6ff & 0xffff)) {
      return '\x01';
    }
    iVar1 = tc_cmac_update(user_data,(uint8_t *)&local_2e,2);
    if (iVar1 != 0) {
      local_2e = *(uint16_t *)(pcVar3 + 2);
      dlen = 2;
      data = &local_2e;
      goto LAB_00085e3c;
    }
  }
  dlen = 0xffffffea;
LAB_00085dfa:
  *(size_t *)((int)user_data + 0x58) = dlen;
  return '\0';
}


