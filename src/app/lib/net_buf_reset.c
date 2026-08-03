/*
 * Function: net_buf_reset
 * Entry:    00062118
 * Prototype: void __stdcall net_buf_reset(net_buf * buf)
 */


/* exclude_from_export */

void net_buf_reset(net_buf *buf)

{
  if (buf->flags == '\0') {
    if (buf->frags == (net_buf *)0x0) {
      (buf->field6_0xc).field0.len = 0;
      (buf->field6_0xc).field0.data = (buf->field6_0xc).field0.__buf;
      return;
    }
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","buf->frags == ((void *)0)",
            "WEST_TOPDIR/zephyr/subsys/net/buf.c",0x5b);
  }
  else {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","buf->flags == 0U","WEST_TOPDIR/zephyr/subsys/net/buf.c"
            ,90);
  }
                    /* WARNING: Subroutine does not return */
  k_panic();
}


