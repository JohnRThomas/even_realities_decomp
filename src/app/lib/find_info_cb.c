/*
 * Function: find_info_cb
 * Entry:    000854dc
 * Prototype: uint8_t __stdcall find_info_cb(bt_gatt_attr * attr, uint16_t handle, void * user_data)
 */


/* exclude_from_export */

uint8_t find_info_cb(bt_gatt_attr *attr,uint16_t handle,void *user_data)

{
  undefined1 *puVar1;
  uint16_t *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar6;
  undefined1 uVar7;
  undefined *puVar8;
  int iVar9;
  bool bVar10;
  bool bVar11;
  undefined4 *puVar5;
  
  iVar9 = *(int *)user_data;
  if (*(int *)((int)user_data + 8) == 0) {
    puVar1 = net_buf_add((net_buf *)(*(int *)((int)user_data + 4) + 0xc),1);
    *(undefined1 **)((int)user_data + 8) = puVar1;
    if (*attr->uuid == '\0') {
      uVar7 = 1;
    }
    else {
      uVar7 = 2;
    }
    *puVar1 = uVar7;
  }
  if (**(char **)((int)user_data + 8) == '\x01') {
    if (*attr->uuid == '\0') {
      puVar2 = net_buf_add((net_buf *)(*(int *)((int)user_data + 4) + 0xc),4);
      *(uint16_t **)((int)user_data + 0xc) = puVar2;
      *puVar2 = handle;
      *(undefined2 *)(*(int *)((int)user_data + 0xc) + 2) = *(undefined2 *)(attr->uuid + 2);
      uVar3 = (uint)*(ushort *)(*(int *)((int)user_data + 4) + 0x10);
      if ((uint)*(ushort *)(iVar9 + 0x1e) < (uint)*(ushort *)(iVar9 + 0x2e)) {
        uVar3 = *(ushort *)(iVar9 + 0x1e) - uVar3;
      }
      else {
        uVar3 = *(ushort *)(iVar9 + 0x2e) - uVar3;
      }
      bVar11 = 3 < uVar3;
      bVar10 = uVar3 == 4;
      goto LAB_00085548;
    }
  }
  else if ((**(char **)((int)user_data + 8) == '\x02') && (*attr->uuid == '\x02')) {
    puVar2 = net_buf_add((net_buf *)(*(int *)((int)user_data + 4) + 0xc),0x12);
    *(uint16_t **)((int)user_data + 0xc) = puVar2;
    *puVar2 = handle;
    puVar8 = attr->uuid;
    puVar4 = (undefined4 *)(puVar8 + 1);
    puVar6 = (undefined4 *)(*(int *)((int)user_data + 0xc) + 2);
    do {
      puVar5 = puVar4 + 1;
      *puVar6 = *puVar4;
      puVar4 = puVar5;
      puVar6 = puVar6 + 1;
    } while (puVar5 != (undefined4 *)(puVar8 + 0x11));
    uVar3 = (uint)*(ushort *)(*(int *)((int)user_data + 4) + 0x10);
    if ((uint)*(ushort *)(iVar9 + 0x1e) < (uint)*(ushort *)(iVar9 + 0x2e)) {
      uVar3 = *(ushort *)(iVar9 + 0x1e) - uVar3;
    }
    else {
      uVar3 = *(ushort *)(iVar9 + 0x2e) - uVar3;
    }
    bVar11 = 0x11 < uVar3;
    bVar10 = uVar3 == 0x12;
LAB_00085548:
    if (bVar11 && !bVar10) {
      return '\x01';
    }
    return '\0';
  }
  return '\0';
}


