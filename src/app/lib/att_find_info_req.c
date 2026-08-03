/*
 * Function: att_find_info_req
 * Entry:    0005c8c8
 * Prototype: uint8_t __stdcall att_find_info_req(bt_att_chan * chan, net_buf * buf)
 */


/* exclude_from_export_ai */

uint8_t att_find_info_req(bt_att_chan *chan,net_buf *buf)

{
  uint16_t end_handle;
  int in_r2;
  uint16_t *puVar1;
  uint16_t start_handle;
  bt_att_chan *pbStack_20;
  net_buf *pnStack_1c;
  int iStack_18;
  
  puVar1 = (uint16_t *)(buf->field6_0xc).field0.data;
  start_handle = *puVar1;
  end_handle = puVar1[1];
  pbStack_20 = chan;
  pnStack_1c = buf;
  if (start_handle != 0) {
    if (end_handle == 0) {
      start_handle = 0;
    }
    else if (start_handle <= end_handle) {
      iStack_18 = in_r2;
      memset(&pbStack_20,0,0x10);
      pnStack_1c = bt_att_create_rsp_pdu(chan,'\x05',0);
      if (pnStack_1c == (net_buf *)0x0) {
        return '\x11';
      }
      pbStack_20 = chan;
      bt_gatt_foreach_attr(start_handle,end_handle,(bt_gatt_attr_func_t)0x854dd,&pbStack_20);
      if (iStack_18 != 0) {
        bt_att_chan_send_rsp(chan,pnStack_1c);
        return '\0';
      }
      tx_meta_data_free((bt_att_tx_meta_data *)pnStack_1c->user_data);
      net_buf_unref(pnStack_1c);
    }
  }
  send_err_rsp((bt_l2cap_chan *)chan,4,start_handle);
  return '\0';
}


