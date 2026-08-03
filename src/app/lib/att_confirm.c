/*
 * Function: att_confirm
 * Entry:    00085c02
 * Prototype: uint8_t __stdcall att_confirm(bt_att_chan * chan, net_buf * buf)
 */


/* exclude_from_export_ai */

uint8_t att_confirm(bt_att_chan *chan,net_buf *buf)

{
  uint8_t uVar1;
  
  uVar1 = att_handle_rsp(chan,(buf->field6_0xc).field0.data,(buf->field6_0xc).field0.len,'\0');
  return uVar1;
}


