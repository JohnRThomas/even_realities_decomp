/*
 * Function: read_vl_cb
 * Entry:    00085776
 * Prototype: uint8_t __stdcall read_vl_cb(bt_gatt_attr * attr, uint16_t handle, void * user_data)
 */


/* exclude_from_export_ai */

uint8_t read_vl_cb(bt_gatt_attr *attr,uint16_t handle,void *user_data)

{
  uint8_t uVar1;
  bt_conn *conn;
  undefined2 *puVar2;
  uint uVar3;
  uint uVar4;
  char cVar5;
  uint uVar6;
  int iVar7;
  bt_att_chan *chan;
  
  chan = *(bt_att_chan **)user_data;
  conn = (bt_conn *)chan->ATT_NUM_FLAGS_;
  *(undefined1 *)((int)user_data + 0xc) = 0;
  uVar1 = bt_gatt_check_perm(conn,attr,0x95);
  *(uint8_t *)((int)user_data + 0xc) = uVar1;
  if (uVar1 == '\0') {
    uVar3 = (uint)*(ushort *)((int)&chan[1].ATT_NUM_FLAGS_ + 2);
    uVar4 = (uint)*(ushort *)((int)&chan->timeout_work + 2);
    uVar6 = (uint)*(ushort *)(*(int *)((int)user_data + 8) + 0x10);
    if (uVar4 < uVar3) {
      iVar7 = uVar4 - uVar6;
    }
    else {
      iVar7 = uVar3 - uVar6;
    }
    if (1 < iVar7) {
      puVar2 = net_buf_add((net_buf *)(*(int *)((int)user_data + 8) + 0xc),2);
      uVar3 = att_chan_read(chan,attr,*(net_buf **)((int)user_data + 8),
                            *(uint16_t *)((int)user_data + 4),(attr_read_cb)0x0,(void *)0x0);
      if (-1 < (int)uVar3) {
        *puVar2 = (short)uVar3;
        return '\x01';
      }
      if (uVar3 < 0xffffff01) {
        cVar5 = '\x0e';
      }
      else {
        cVar5 = -(char)uVar3;
      }
      *(char *)((int)user_data + 0xc) = cVar5;
    }
  }
  return '\0';
}


