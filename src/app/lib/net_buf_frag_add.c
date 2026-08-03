/*
 * Function: net_buf_frag_add
 * Entry:    0006263c
 * Prototype: net_buf * __stdcall net_buf_frag_add(net_buf * head, net_buf * frag)
 */


/* exclude_from_export */

net_buf * net_buf_frag_add(net_buf *head,net_buf *frag)

{
  net_buf *pnVar1;
  
  if (frag == (net_buf *)0x0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","frag","WEST_TOPDIR/zephyr/subsys/net/buf.c",589);
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  if (head == (net_buf *)0x0) {
    pnVar1 = net_buf_ref(frag);
    return pnVar1;
  }
  pnVar1 = net_buf_frag_last(head);
  net_buf_frag_insert(pnVar1,frag);
  return head;
}


