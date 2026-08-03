/*
 * Function: read_group_cb
 * Entry:    0005b9fc
 * Prototype: uint8_t __stdcall read_group_cb(bt_gatt_attr * attr, uint16_t handle, void * user_data)
 */


/* exclude_from_export_ai */

uint8_t read_group_cb(bt_gatt_attr *attr,uint16_t handle,void *user_data)

{
  ushort uVar1;
  int iVar2;
  uint16_t *puVar3;
  ssize_t sVar4;
  uint uVar5;
  undefined4 in_r3;
  uint uVar6;
  bt_att_chan *chan;
  uint uVar7;
  ushort local_20;
  undefined2 local_1e;
  undefined4 local_1c;
  
  chan = *(bt_att_chan **)user_data;
  _local_20 = CONCAT22(0x2800,(ushort)user_data & 0xff00);
  local_1c = in_r3;
  iVar2 = bt_uuid_cmp((bt_uuid *)attr->uuid,(bt_uuid *)&local_20);
  if (iVar2 != 0) {
    uVar1 = (ushort)local_1c;
    local_1c = CONCAT22(0x2801,uVar1 & 0xff00);
    iVar2 = bt_uuid_cmp((bt_uuid *)attr->uuid,(bt_uuid *)&local_1c);
    if (iVar2 != 0) {
      iVar2 = *(int *)((int)user_data + 0x10);
      if (iVar2 == 0) {
        return '\x01';
      }
      if (handle <= *(ushort *)(iVar2 + 2)) {
        return '\x01';
      }
      *(uint16_t *)(iVar2 + 2) = handle;
      return '\x01';
    }
  }
  iVar2 = bt_uuid_cmp((bt_uuid *)attr->uuid,*(bt_uuid **)((int)user_data + 4));
  if (iVar2 != 0) {
    *(undefined4 *)((int)user_data + 0x10) = 0;
    return '\x01';
  }
  if (**(byte **)((int)user_data + 0xc) != 0) {
    uVar7 = (uint)*(ushort *)((int)&chan->timeout_work + 2);
    uVar5 = (uint)*(ushort *)((int)&chan[1].ATT_NUM_FLAGS_ + 2);
    uVar6 = (uint)*(ushort *)(*(int *)((int)user_data + 8) + 0x10);
    if (uVar5 < uVar7) {
      iVar2 = uVar5 - uVar6;
    }
    else {
      iVar2 = uVar7 - uVar6;
    }
    if (iVar2 < (int)(uint)**(byte **)((int)user_data + 0xc)) {
      return '\0';
    }
  }
  puVar3 = net_buf_add((net_buf *)(*(int *)((int)user_data + 8) + 0xc),4);
  *(uint16_t **)((int)user_data + 0x10) = puVar3;
  *puVar3 = handle;
  *(uint16_t *)(*(int *)((int)user_data + 0x10) + 2) = handle;
  sVar4 = att_chan_read(chan,attr,*(net_buf **)((int)user_data + 8),0,(attr_read_cb)0x854bd,
                        user_data);
  if (sVar4 < 0) {
    return '\0';
  }
  return *(int *)((int)user_data + 0x10) != 0;
}


