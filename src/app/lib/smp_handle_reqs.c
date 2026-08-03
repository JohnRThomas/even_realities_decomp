/*
 * Function: smp_handle_reqs
 * Entry:    0008426c
 * Prototype: int __stdcall smp_handle_reqs(bt_l2cap_chan * chan, net_buf * req_buf)
 */


/* exclude_from_export_ai */

int smp_handle_reqs(bt_l2cap_chan *chan,net_buf *req_buf)

{
  net_buf *req;
  net_buf *extraout_r1;
  k_timeout_t timeout;
  smp_streamer local_b8 [4];
  undefined1 auStack_74 [100];
  
  while (timeout.ticks._4_4_ = 0, timeout.ticks._0_4_ = req_buf,
        req = net_buf_get((k_fifo *)&chan->BT_L2CAP_NUM_STATUS_,timeout), req != (net_buf *)0x0) {
    local_b8[0].writer = (undefined *)&local_b8[0].rc_rsn;
    local_b8[0].smpt = (undefined *)chan;
    local_b8[0].reader = auStack_74;
    smp_process_packet(local_b8,req);
    req_buf = extraout_r1;
  }
  return 0;
}


