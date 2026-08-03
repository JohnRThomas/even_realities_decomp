/*
 * Function: l2cap_rx_process
 * Entry:    0008533a
 * Prototype: void __stdcall l2cap_rx_process(k_work * work)
 */


/* exclude_from_export */

void l2cap_rx_process(k_work *work)

{
  net_buf *buf;
  uint in_r1;
  uint extraout_r1;
  k_timeout_t timeout;
  
  while (timeout.ticks._4_4_ = 0, timeout.ticks._0_4_ = in_r1,
        buf = net_buf_get((k_fifo *)(work + 1),timeout), buf != (net_buf *)0x0) {
    l2cap_chan_le_recv((bt_l2cap_le_chan *)&work[-9].queue,buf);
    net_buf_unref(buf);
    in_r1 = extraout_r1;
  }
  return;
}


