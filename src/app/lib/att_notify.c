/*
 * Function: att_notify
 * Entry:    000853ba
 * Prototype: uint8_t __stdcall att_notify(bt_att_chan * chan, net_buf * buf)
 */


/* exclude_from_export */

uint8_t att_notify(bt_att_chan *chan,net_buf *buf)

{
  uint16_t handle;
  
  handle = net_buf_pull_le16((net_buf *)&(buf->field6_0xc).field0);
  bt_gatt_notification
            (*(bt_conn **)chan->att,handle,(buf->field6_0xc).field0.data,
             (buf->field6_0xc).field0.len);
  return '\0';
}


