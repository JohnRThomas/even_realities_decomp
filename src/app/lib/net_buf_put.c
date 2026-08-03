/*
 * Function: net_buf_put
 * Entry:    000624ac
 * Prototype: void __stdcall net_buf_put(k_fifo * fifo, net_buf * buf)
 */


/* exclude_from_export */

void net_buf_put(k_fifo *fifo,net_buf *buf)

{
  if (fifo == (k_fifo *)0x0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","fifo","WEST_TOPDIR/zephyr/subsys/net/buf.c",0x1c7);
  }
  else {
    if (buf != (net_buf *)0x0) {
      k_queue_append(&fifo->_queue,buf);
      return;
    }
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","buf","WEST_TOPDIR/zephyr/subsys/net/buf.c",0x1c8);
  }
                    /* WARNING: Subroutine does not return */
  k_panic();
}


