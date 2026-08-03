/*
 * Function: net_buf_push
 * Entry:    000627c4
 * Prototype: void * __stdcall net_buf_push(net_buf * buf, size_t len)
 */


/* exclude_from_export */

void * net_buf_push(net_buf *buf,size_t len)

{
  short sVar1;
  sys_snode_t *psVar2;
  
  psVar2 = (buf->node).next;
  if ((uint)((int)psVar2 - *(int *)&buf->ref) < len) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","net_buf_simple_headroom(buf) >= len",
            "WEST_TOPDIR/zephyr/subsys/net/buf_simple.c",301);
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  sVar1 = *(short *)&buf->frags;
  psVar2 = (sys_snode_t *)((int)psVar2 - len);
  (buf->node).next = psVar2;
  *(short *)&buf->frags = (short)len + sVar1;
  return psVar2;
}


