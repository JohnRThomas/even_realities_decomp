/*
 * Function: net_buf_simple_pull_mem
 * Entry:    00062840
 * Prototype: void * __stdcall net_buf_simple_pull_mem(net_buf_simple * buf, size_t len)
 */


/* exclude_from_export */

void * net_buf_simple_pull_mem(net_buf_simple *buf,size_t len)

{
  undefined *puVar1;
  
  puVar1 = buf->data;
  if (buf->len < len) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","buf->len >= len",
            "WEST_TOPDIR/zephyr/subsys/net/buf_simple.c",409);
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  buf->len = buf->len - (short)len;
  buf->data = puVar1 + len;
  return puVar1;
}


