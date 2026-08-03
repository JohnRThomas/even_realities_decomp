/*
 * Function: l2cap_chan_send_req
 * Entry:    0008511a
 * Prototype: void __stdcall l2cap_chan_send_req(bt_l2cap_chan * chan, net_buf * buf, k_timeout_t timeout)
 */


/* exclude_from_export */

void l2cap_chan_send_req(bt_l2cap_chan *chan,net_buf *buf,k_timeout_t timeout)

{
  int iVar1;
  undefined4 extraout_r1;
  k_timeout_t delay;
  
  delay.ticks._4_4_ = (undefined4)timeout.ticks;
  iVar1 = bt_l2cap_send_cb(chan->conn,5,buf,(bt_conn_tx_cb_t)0x0,(void *)0x0);
  if (iVar1 != 0) {
    net_buf_unref(buf);
    return;
  }
  delay.ticks._0_4_ = extraout_r1;
  k_work_reschedule((k_work_delayable *)&chan[9].destroy,delay);
  return;
}


