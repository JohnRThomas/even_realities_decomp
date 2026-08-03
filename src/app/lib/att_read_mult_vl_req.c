/*
 * Function: att_read_mult_vl_req
 * Entry:    0005c548
 * Prototype: uint8_t __stdcall att_read_mult_vl_req(bt_att_chan * chan, net_buf * buf)
 */


/* exclude_from_export_ai */

uint8_t att_read_mult_vl_req(bt_att_chan *chan,net_buf *buf)

{
  bool bVar1;
  uint16_t start_handle;
  bt_att_chan *local_30 [2];
  net_buf *local_28;
  char local_24;
  
  bVar1 = bt_gatt_change_aware(*(bt_conn **)chan->att,true);
  if (bVar1) {
    memset(local_30,0,0x10);
    local_28 = bt_att_create_rsp_pdu(chan,'!',0);
    if (local_28 == (net_buf *)0x0) {
      return '\x11';
    }
    local_30[0] = chan;
    do {
      if ((buf->field6_0xc).field0.len < 2) {
        bt_att_chan_send_rsp(chan,local_28);
        return '\0';
      }
      start_handle = net_buf_pull_le16((net_buf *)&(buf->field6_0xc).field0);
      local_24 = '\x01';
      bt_gatt_foreach_attr(start_handle,start_handle,(bt_gatt_attr_func_t)0x85777,local_30);
    } while (local_24 == '\0');
    tx_meta_data_free((bt_att_tx_meta_data *)local_28->user_data);
    net_buf_unref(local_28);
    send_err_rsp((bt_l2cap_chan *)chan,0x20,start_handle);
  }
  else {
    bVar1 = atomic_test_and_set_bit((atomic_t *)(chan + 8),5);
    if (!bVar1) {
      return '\x12';
    }
  }
  return '\0';
}


