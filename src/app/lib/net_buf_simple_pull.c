/*
 * Function: net_buf_simple_pull
 * Entry:    00062804
 * Prototype: uint16_t __stdcall net_buf_simple_pull(net_buf_simple * buf)
 */


/* exclude_from_export */

uint16_t net_buf_simple_pull(net_buf_simple *buf)

{
  undefined *puVar1;
  uint in_r1;
  
  if (buf->len < in_r1) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","buf->len >= len",
            "WEST_TOPDIR/zephyr/subsys/net/buf_simple.c",397);
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  buf->len = buf->len - (short)in_r1;
  puVar1 = buf->data;
  buf->data = puVar1 + in_r1;
  return (uint16_t)(puVar1 + in_r1);
}


