/*
 * Function: att_read_req
 * Entry:    00085b36
 * Prototype: uint8_t __stdcall att_read_req(bt_att_chan * chan, net_buf * buf)
 */


/* exclude_from_export_ai */

uint8_t att_read_req(bt_att_chan *chan,net_buf *buf)

{
  uint8_t uVar1;
  
  uVar1 = att_read_rsp(chan,'\n','\v',*(uint16_t *)(buf->field6_0xc).field0.data,0);
  return uVar1;
}


