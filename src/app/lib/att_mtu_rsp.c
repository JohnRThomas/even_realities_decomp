/*
 * Function: att_mtu_rsp
 * Entry:    00085c38
 * Prototype: uint8_t __stdcall att_mtu_rsp(bt_att_chan * chan, net_buf * buf)
 */


/* exclude_from_export */

uint8_t att_mtu_rsp(bt_att_chan *chan,net_buf *buf)

{
  uint8_t uVar1;
  uint16_t len;
  ushort *pdu;
  
  pdu = (ushort *)(buf->field6_0xc).field0.data;
  if (*pdu < 0x17) {
    len = 0;
    uVar1 = '\x04';
    pdu = (ushort *)0x0;
  }
  else {
    *(ushort *)((int)&chan[1].ATT_NUM_FLAGS_ + 2) = *pdu;
    *(undefined2 *)((int)&chan->timeout_work + 2) = 0x1f2;
    att_chan_mtu_updated(chan);
    uVar1 = '\0';
    len = (buf->field6_0xc).field0.len;
  }
  uVar1 = att_handle_rsp(chan,pdu,len,uVar1);
  return uVar1;
}


