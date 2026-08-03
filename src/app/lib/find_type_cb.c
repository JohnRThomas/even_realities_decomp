/*
 * Function: find_type_cb
 * Entry:    0005b67c
 * Prototype: uint8_t __stdcall find_type_cb(bt_gatt_attr * attr, uint16_t handle, void * user_data)
 */


/* exclude_from_export */

uint8_t find_type_cb(bt_gatt_attr *attr,uint16_t handle,void *user_data)

{
  byte data_len;
  bool bVar1;
  int iVar2;
  size_t sVar3;
  uint uVar4;
  net_buf *frag;
  net_buf_pool *pool;
  uint16_t *puVar5;
  net_buf *frags;
  uint extraout_r1;
  int iVar6;
  k_timeout_t timeout;
  byte local_78 [4];
  char *local_74;
  uint local_70;
  undefined4 local_64;
  uint8_t auStack_60 [16];
  bt_uuid abStack_50 [20];
  bt_uuid local_3c [2];
  undefined2 local_3a;
  
  iVar6 = *(int *)user_data;
  local_64 = *(undefined4 *)(iVar6 + 8);
  local_3c[0].type = '\0';
  local_3a = 0x2801;
  iVar2 = bt_uuid_cmp((bt_uuid *)attr->uuid,local_3c);
  if (iVar2 == 0) goto LAB_0005b7a8;
  local_3c[0].type = '\0';
  local_3a = 0x2800;
  iVar2 = bt_uuid_cmp((bt_uuid *)attr->uuid,local_3c);
  if (iVar2 != 0) {
    iVar2 = *(int *)((int)user_data + 8);
    if (iVar2 == 0) {
      return '\x01';
    }
    if (handle <= *(ushort *)(iVar2 + 2)) {
      return '\x01';
    }
    goto LAB_0005b6cc;
  }
  sVar3 = net_buf_frags_len(*(net_buf **)((int)user_data + 4));
  if ((uint)*(ushort *)(iVar6 + 0x1e) < (uint)*(ushort *)(iVar6 + 0x2e)) {
    uVar4 = *(ushort *)(iVar6 + 0x1e) - sVar3;
  }
  else {
    uVar4 = *(ushort *)(iVar6 + 0x2e) - sVar3;
  }
  if (uVar4 < 4) {
    return '\0';
  }
  frag = net_buf_frag_last(frags);
  sVar3 = net_buf_frags_len(*(net_buf **)((int)user_data + 4));
  if ((uint)*(ushort *)(iVar6 + 0x1e) < (uint)*(ushort *)(iVar6 + 0x2e)) {
    uVar4 = *(ushort *)(iVar6 + 0x1e) - sVar3;
  }
  else {
    uVar4 = *(ushort *)(iVar6 + 0x2e) - sVar3;
  }
  sVar3 = net_buf_simple_tailroom(&(frag->field6_0xc).b);
  if (uVar4 < sVar3) {
    sVar3 = net_buf_frags_len(*(net_buf **)((int)user_data + 4));
    if ((uint)*(ushort *)(iVar6 + 0x1e) < (uint)*(ushort *)(iVar6 + 0x2e)) {
      sVar3 = *(ushort *)(iVar6 + 0x1e) - sVar3;
    }
    else {
      sVar3 = *(ushort *)(iVar6 + 0x2e) - sVar3;
    }
  }
  else {
    sVar3 = net_buf_simple_tailroom(&(frag->field6_0xc).b);
  }
  if (sVar3 == 0) {
    pool = net_buf_pool_get((uint)*(byte *)(*(int *)((int)user_data + 4) + 10));
    timeout.ticks._4_4_ = 0;
    timeout.ticks._0_4_ = extraout_r1;
    frag = net_buf_alloc(pool,timeout);
    if (frag == (net_buf *)0x0) {
      return '\0';
    }
    net_buf_frag_add(*(net_buf **)((int)user_data + 4),frag);
  }
  local_70 = 0;
  uVar4 = (*(code *)attr->read)(local_64,attr,auStack_60,0x10);
  if ((int)uVar4 < 0) goto LAB_0005b7a8;
  data_len = *(byte *)((int)user_data + 0x10);
  if (data_len == uVar4) {
    iVar2 = memcmp(*(uint8_t **)((int)user_data + 0xc),auStack_60,(uint)data_len);
LAB_0005b7e0:
    if (iVar2 == 0) {
      *(undefined1 *)((int)user_data + 0x11) = 0;
      puVar5 = net_buf_add((net_buf *)&(frag->field6_0xc).field0,4);
      *(uint16_t **)((int)user_data + 8) = puVar5;
      *puVar5 = handle;
      iVar2 = *(int *)((int)user_data + 8);
LAB_0005b6cc:
      *(uint16_t *)(iVar2 + 2) = handle;
      return '\x01';
    }
  }
  else {
    bVar1 = bt_uuid_create(local_3c,*(uint8_t **)((int)user_data + 0xc),data_len);
    if (bVar1) {
      bVar1 = bt_uuid_create(abStack_50,auStack_60,(uint8_t)uVar4);
      if (bVar1) {
        iVar2 = bt_uuid_cmp(local_3c,abStack_50);
        goto LAB_0005b7e0;
      }
      local_74 = "Unable to create UUID: size %d";
      local_70 = uVar4;
    }
    else {
      local_74 = "Unable to create UUID: size %u";
      local_70 = (uint)*(byte *)((int)user_data + 0x10);
    }
    local_78[0] = 3;
    local_78[1] = 0;
    local_78[2] = 0;
    local_78[3] = 0;
    LOG_WRN(&PTR_s_bt_att_0008b8b0,0x1880,local_78);
  }
LAB_0005b7a8:
  *(undefined4 *)((int)user_data + 8) = 0;
  return '\x01';
}


