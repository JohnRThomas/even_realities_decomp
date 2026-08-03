/*
 * Function: bt_l2cap_chan_disconnect
 * Entry:    000852e8
 * Prototype: int __stdcall bt_l2cap_chan_disconnect(bt_l2cap_chan * chan)
 */


/* exclude_from_export */

int bt_l2cap_chan_disconnect(bt_l2cap_chan *chan)

{
  uint8_t code;
  net_buf *buf;
  undefined2 *puVar1;
  int iVar2;
  uint16_t len;
  
  if (chan->conn == (bt_conn *)0x0) {
    iVar2 = -0x80;
  }
  else {
    code = get_ident();
    *(uint8_t *)&chan[9].ops = code;
    buf = l2cap_create_le_sig_pdu((net_buf *)&DAT_00000006,code,'\x04',len);
    if (buf == (net_buf *)0x0) {
      iVar2 = -0xc;
    }
    else {
      puVar1 = net_buf_add((net_buf *)&(buf->field6_0xc).field0,4);
      *puVar1 = (short)chan[1].BT_L2CAP_NUM_STATUS_;
      puVar1[1] = *(undefined2 *)&chan[1].conn;
      l2cap_chan_send_req(chan,buf,(k_timeout_t)0x10000);
      iVar2 = 0;
      *(undefined1 *)&chan[9].conn = 4;
    }
  }
  return iVar2;
}


