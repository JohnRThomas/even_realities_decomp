/*
 * Function: att_notify_mult
 * Entry:    000853a8
 * Prototype: uint8_t __stdcall att_notify_mult(bt_att_chan * chan, net_buf * buf)
 */


/* exclude_from_export */

uint8_t att_notify_mult(bt_att_chan *chan,net_buf *buf)

{
  bt_gatt_mult_notification
            (*(bt_conn **)chan->att,(buf->field6_0xc).field0.data,(buf->field6_0xc).field0.len);
  return '\0';
}


