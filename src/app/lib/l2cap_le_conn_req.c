/*
 * Function: l2cap_le_conn_req
 * Entry:    00085152
 * Prototype: int __stdcall l2cap_le_conn_req(bt_l2cap_le_chan * ch)
 */


/* exclude_from_export */

int l2cap_le_conn_req(bt_l2cap_le_chan *ch)

{
  uint8_t code;
  net_buf *buf;
  undefined2 *puVar1;
  int iVar2;
  uint16_t len;
  
  code = get_ident();
  *(uint8_t *)((int)&ch[3].chan + 1) = code;
  buf = l2cap_create_le_sig_pdu((net_buf *)&BusFault,code,'\n',len);
  if (buf == (net_buf *)0x0) {
    iVar2 = -0xc;
  }
  else {
    puVar1 = net_buf_add((net_buf *)&(buf->field6_0xc).field0,10);
    *puVar1 = *(undefined2 *)((int)&ch[2].rtx_sync + 3);
    puVar1[1] = *(undefined2 *)((int)&ch->tx_buf + 2);
    puVar1[2] = (short)ch->tx_work;
    puVar1[3] = *(undefined2 *)((int)&ch->tx_work + 2);
    puVar1[4] = (short)*(undefined4 *)((int)&ch->_sdu + 2);
    l2cap_chan_send_req((bt_l2cap_chan *)ch,buf,(k_timeout_t)0x140000);
    iVar2 = 0;
  }
  return iVar2;
}


