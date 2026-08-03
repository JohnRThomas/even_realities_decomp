/*
 * Function: net_buf_ref
 * Entry:    00062580
 * Prototype: net_buf * __stdcall net_buf_ref(net_buf * buf)
 */


/* exclude_from_export */

net_buf * net_buf_ref(net_buf *buf)

{
  if (buf == (net_buf *)0x0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","buf","WEST_TOPDIR/zephyr/subsys/net/buf.c",514);
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  buf->ref = buf->ref + '\x01';
  return buf;
}


