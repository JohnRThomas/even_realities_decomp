/*
 * Function: net_buf_reserve
 * Entry:    00062780
 * Prototype: void __stdcall net_buf_reserve(net_buf * buf, size_t reserve)
 */


/* exclude_from_export */

void net_buf_reserve(net_buf *buf,size_t reserve)

{
  if (buf == (net_buf *)0x0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","buf","WEST_TOPDIR/zephyr/subsys/net/buf_simple.c",43);
  }
  else {
    if (*(short *)&buf->frags == 0) {
      (buf->node).next = (sys_snode_t *)(*(int *)&buf->ref + reserve);
      return;
    }
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","buf->len == 0U",
            "WEST_TOPDIR/zephyr/subsys/net/buf_simple.c",0x2c);
  }
                    /* WARNING: Subroutine does not return */
  k_panic();
}


