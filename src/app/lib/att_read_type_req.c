/*
 * Function: att_read_type_req
 * Entry:    0005c734
 * Prototype: uint8_t __stdcall att_read_type_req(bt_att_chan * chan, net_buf * buf)
 */


/* exclude_from_export_ai */

uint8_t att_read_type_req(bt_att_chan *chan,net_buf *buf)

{
  uint16_t end_handle;
  bool bVar1;
  uint16_t *puVar2;
  ushort uVar3;
  ushort uVar4;
  uint16_t start_handle;
  bt_uuid abStack_44 [20];
  bt_att_chan *local_30;
  bt_uuid *pbStack_2c;
  net_buf *local_28;
  undefined1 *local_24;
  char local_1c;
  
  uVar3 = (buf->field6_0xc).field0.len - 4;
  uVar4 = uVar3 & 0xff;
  if ((uVar4 != 2) && (uVar4 != 0x10)) {
    return '\x04';
  }
  puVar2 = net_buf_simple_pull_mem(&(buf->field6_0xc).b,4);
  start_handle = *puVar2;
  end_handle = puVar2[1];
  bVar1 = bt_uuid_create(abStack_44,(uint8_t *)(puVar2 + 2),(uint8_t)uVar3);
  if (!bVar1) {
    return '\x0e';
  }
  if (start_handle != 0) {
    if (end_handle == 0) {
      start_handle = 0;
    }
    else if (start_handle <= end_handle) {
      memset(&local_30,0,0x18);
      local_28 = bt_att_create_rsp_pdu(chan,'\t',1);
      if (local_28 == (net_buf *)0x0) {
        return '\x11';
      }
      local_30 = chan;
      pbStack_2c = abStack_44;
      local_24 = net_buf_add((net_buf *)&(local_28->field6_0xc).field0,1);
      *local_24 = 0;
      local_1c = '\n';
      bt_gatt_foreach_attr(start_handle,end_handle,(bt_gatt_attr_func_t)0x5bab5,&local_30);
      if (local_1c == '\0') {
        bt_att_chan_send_rsp(chan,local_28);
        return '\0';
      }
      tx_meta_data_free((bt_att_tx_meta_data *)local_28->user_data);
      net_buf_unref(local_28);
    }
  }
  send_err_rsp((bt_l2cap_chan *)chan,8,start_handle);
  return '\0';
}


