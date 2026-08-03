/*
 * Function: att_prepare_write_req
 * Entry:    0005c368
 * Prototype: uint8_t __stdcall att_prepare_write_req(bt_att_chan * chan, net_buf * buf)
 */


/* exclude_from_export_ai */

uint8_t att_prepare_write_req(bt_att_chan *chan,net_buf *buf)

{
  ushort uVar1;
  uint16_t start_handle;
  uint16_t uVar2;
  bool bVar3;
  uint16_t *puVar4;
  uint len;
  uint8_t *s;
  undefined4 local_34;
  net_buf *local_30;
  uint8_t *local_2c;
  ushort local_28;
  uint16_t local_26;
  char local_24;
  
  puVar4 = net_buf_simple_pull_mem(&(buf->field6_0xc).b,4);
  start_handle = *puVar4;
  uVar2 = puVar4[1];
  s = (buf->field6_0xc).field0.data;
  uVar1 = (buf->field6_0xc).field0.len;
  bVar3 = bt_gatt_change_aware(*(bt_conn **)chan->att,true);
  if (bVar3) {
    if (start_handle == 0) {
      return '\x01';
    }
    memset(&local_34,0,0x14);
    local_34 = *(undefined4 *)chan->att;
    local_24 = '\x01';
    len = (uint)(byte)uVar1;
    local_28 = uVar1 & 0xff;
    local_2c = s;
    local_26 = uVar2;
    bt_gatt_foreach_attr(start_handle,start_handle,(bt_gatt_attr_func_t)0x5bb61,&local_34);
    if (local_24 == '\0') {
      net_buf_slist_put((sys_slist_t *)(chan->att + 0x28),local_30);
      local_30 = bt_att_create_rsp_pdu(chan,'\x17',0);
      if (local_30 == (net_buf *)0x0) {
        return '\x11';
      }
      puVar4 = net_buf_add((net_buf *)&(local_30->field6_0xc).field0,4);
      *puVar4 = start_handle;
      puVar4[1] = uVar2;
      net_buf_add((net_buf *)&(local_30->field6_0xc).field0,len);
      memcpy(puVar4 + 2,s,len);
      bt_att_chan_send_rsp(chan,local_30);
    }
    else {
      send_err_rsp((bt_l2cap_chan *)chan,0x16,start_handle);
    }
  }
  else {
    bVar3 = atomic_test_and_set_bit((atomic_t *)(chan + 8),5);
    if (!bVar3) {
      return '\x12';
    }
  }
  return '\0';
}


