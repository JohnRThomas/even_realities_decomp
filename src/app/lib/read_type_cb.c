/*
 * Function: read_type_cb
 * Entry:    0005bab4
 * Prototype: uint8_t __stdcall read_type_cb(bt_gatt_attr * attr, uint16_t handle, void * user_data)
 */


/* exclude_from_export_ai */

uint8_t read_type_cb(bt_gatt_attr *attr,uint16_t handle,void *user_data)

{
  uint8_t uVar1;
  char cVar2;
  int iVar3;
  net_buf *pnVar4;
  uint16_t *puVar5;
  uint uVar6;
  size_t sVar7;
  uint uVar8;
  bt_conn *conn;
  bt_att_chan *chan;
  
  chan = *(bt_att_chan **)user_data;
  conn = (bt_conn *)chan->ATT_NUM_FLAGS_;
  iVar3 = bt_uuid_cmp((bt_uuid *)attr->uuid,*(bt_uuid **)((int)user_data + 4));
  if (iVar3 == 0) {
    uVar1 = bt_gatt_check_perm(conn,attr,0x95);
    *(uint8_t *)((int)user_data + 0x14) = uVar1;
    if (uVar1 == '\0') {
      pnVar4 = net_buf_frag_last(*(net_buf **)((int)user_data + 8));
      puVar5 = net_buf_add((net_buf *)&(pnVar4->field6_0xc).field0,2);
      *(uint16_t **)((int)user_data + 0x10) = puVar5;
      *puVar5 = handle;
      uVar6 = att_chan_read(chan,attr,*(net_buf **)((int)user_data + 8),0,(attr_read_cb)0x85389,
                            user_data);
      if ((int)uVar6 < 0) {
        if (uVar6 < 0xffffff01) {
          cVar2 = '\x0e';
        }
        else {
          cVar2 = -(char)uVar6;
        }
        *(char *)((int)user_data + 0x14) = cVar2;
      }
      else if (*(int *)((int)user_data + 0x10) != 0) {
        sVar7 = net_buf_frags_len(*(net_buf **)((int)user_data + 8));
        uVar8 = (uint)*(ushort *)((int)&chan[1].ATT_NUM_FLAGS_ + 2);
        uVar6 = (uint)*(ushort *)((int)&chan->timeout_work + 2);
        if (uVar8 < uVar6) {
          uVar6 = uVar8 - sVar7;
        }
        else {
          uVar6 = uVar6 - sVar7;
        }
        return **(byte **)((int)user_data + 0xc) < uVar6;
      }
    }
    else if (**(char **)((int)user_data + 0xc) != '\0') {
      *(undefined1 *)((int)user_data + 0x14) = 0;
    }
    uVar1 = '\0';
  }
  else {
    uVar1 = '\x01';
  }
  return uVar1;
}


