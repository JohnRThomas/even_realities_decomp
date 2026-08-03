/*
 * Function: net_buf_frag_last
 * Entry:    000625b0
 * Prototype: net_buf * __stdcall net_buf_frag_last(net_buf * frags)
 */


/* exclude_from_export */

net_buf * net_buf_frag_last(net_buf *frags)

{
  net_buf *pnVar1;
  
  if (frags == (net_buf *)0x0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","buf","WEST_TOPDIR/zephyr/subsys/net/buf.c",566);
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  do {
    pnVar1 = frags;
    frags = pnVar1->frags;
  } while (frags != (net_buf *)0x0);
  return pnVar1;
}


