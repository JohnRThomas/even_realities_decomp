/*
 * Function: net_buf_frag_del
 * Entry:    00062684
 * Prototype: net_buf * __stdcall net_buf_frag_del(net_buf * parent, net_buf * frag)
 */


/* exclude_from_export */

net_buf * net_buf_frag_del(net_buf *parent,net_buf *frag)

{
  net_buf *pnVar1;
  
  if (frag == (net_buf *)0x0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","frag","WEST_TOPDIR/zephyr/subsys/net/buf.c",0x262);
  }
  else {
    if (parent == (net_buf *)0x0) {
LAB_000626da:
      pnVar1 = frag->frags;
      frag->frags = (net_buf *)0x0;
      net_buf_unref(frag);
      return pnVar1;
    }
    if (parent->frags == (net_buf *)0x0) {
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","parent->frags","WEST_TOPDIR/zephyr/subsys/net/buf.c",
              0x265);
    }
    else {
      if (parent->frags == frag) {
        parent->frags = frag->frags;
        goto LAB_000626da;
      }
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","parent->frags == frag",
              "WEST_TOPDIR/zephyr/subsys/net/buf.c",0x266);
    }
  }
                    /* WARNING: Subroutine does not return */
  k_panic();
}


