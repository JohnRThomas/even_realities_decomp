/*
 * Function: bt_att_chan_send_rsp
 * Entry:    0008595c
 * Prototype: void __stdcall bt_att_chan_send_rsp(bt_att_chan * chan, net_buf * buf)
 */


/* exclude_from_export_ai */

void bt_att_chan_send_rsp(bt_att_chan *chan,net_buf *buf)

{
  int iVar1;
  
  iVar1 = chan_send(chan,buf);
  if (iVar1 != 0) {
    net_buf_put((k_fifo *)&chan[8].ATT_NUM_FLAGS_,buf);
    return;
  }
  return;
}


