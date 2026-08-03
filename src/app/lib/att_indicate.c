/*
 * Function: att_indicate
 * Entry:    00085978
 * Prototype: uint8_t __stdcall att_indicate(bt_att_chan * chan, net_buf * buf)
 */


/* exclude_from_export_ai */

uint8_t att_indicate(bt_att_chan *chan,net_buf *buf)

{
  uint16_t handle;
  net_buf *buf_00;
  
  handle = net_buf_pull_le16((net_buf *)&(buf->field6_0xc).field0);
  bt_gatt_notification
            (*(bt_conn **)chan->att,handle,(buf->field6_0xc).field0.data,
             (buf->field6_0xc).field0.len);
  buf_00 = bt_att_chan_create_pdu(chan,'\x1e',0);
  if (buf_00 != (net_buf *)0x0) {
    bt_att_chan_send_rsp(chan,buf_00);
  }
  return '\0';
}


