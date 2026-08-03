/*
 * Function: net_buf_frag_insert
 * Entry:    000625e4
 * Prototype: void __stdcall net_buf_frag_insert(net_buf * parent, net_buf * frag)
 */


/* exclude_from_export */

void net_buf_frag_insert(net_buf *parent,net_buf *frag)

{
  net_buf *pnVar1;
  net_buf *pnVar2;
  
  if (parent == (net_buf *)0x0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","parent","WEST_TOPDIR/zephyr/subsys/net/buf.c",577);
  }
  else {
    if (frag != (net_buf *)0x0) {
      pnVar2 = parent->frags;
      if (pnVar2 != (net_buf *)0x0) {
        pnVar1 = net_buf_frag_last(frag);
        pnVar1->frags = pnVar2;
      }
      parent->frags = frag;
      return;
    }
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","frag","WEST_TOPDIR/zephyr/subsys/net/buf.c",0x242);
  }
                    /* WARNING: Subroutine does not return */
  k_panic();
}


