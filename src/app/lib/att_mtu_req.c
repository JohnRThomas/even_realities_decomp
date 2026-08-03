/*
 * Function: att_mtu_req
 * Entry:    00085b4e
 * Prototype: uint8_t __stdcall att_mtu_req(bt_att_chan * chan, net_buf * buf)
 */


/* exclude_from_export_ai */

uint8_t att_mtu_req(bt_att_chan *chan,net_buf *buf)

{
  ushort uVar1;
  uint8_t uVar2;
  net_buf *buf_00;
  undefined1 *puVar3;
  int *piVar4;
  uint *puVar5;
  
  uVar1 = *(ushort *)(buf->field6_0xc).field0.data;
  if (uVar1 < 0x17) {
    uVar2 = '\x04';
  }
  else {
    buf_00 = bt_att_create_rsp_pdu(chan,'\x03',2);
    if (buf_00 == (net_buf *)0x0) {
      uVar2 = '\x0e';
    }
    else {
      puVar3 = net_buf_add((net_buf *)&(buf_00->field6_0xc).field0,2);
      *puVar3 = 0xf2;
      puVar3[1] = 1;
      bt_att_chan_send_rsp(chan,buf_00);
      *(undefined2 *)((int)&chan->timeout_work + 2) = 0x1f2;
      piVar4 = (int *)chan->att;
      *(ushort *)((int)&chan[1].ATT_NUM_FLAGS_ + 2) = uVar1;
      puVar5 = (uint *)(*piVar4 + 4);
      *puVar5 = *puVar5 | 0x1000;
      att_chan_mtu_updated(chan);
      uVar2 = '\0';
    }
  }
  return uVar2;
}


