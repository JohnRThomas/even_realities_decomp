/*
 * Function: process_queue
 * Entry:    000858cc
 * Prototype: int __stdcall process_queue(bt_att_chan * chan, k_fifo * queue)
 */


/* exclude_from_export_ai */

int process_queue(bt_att_chan *chan,k_fifo *queue)

{
  net_buf *buf;
  int iVar1;
  k_timeout_t timeout;
  
  timeout.ticks._4_4_ = 0;
  timeout.ticks._0_4_ = queue;
  buf = net_buf_get(queue,timeout);
  if (buf == (net_buf *)0x0) {
    iVar1 = -2;
  }
  else {
    iVar1 = chan_send(chan,buf);
    if (iVar1 != 0) {
      k_queue_prepend(&queue->_queue,buf);
    }
  }
  return iVar1;
}


