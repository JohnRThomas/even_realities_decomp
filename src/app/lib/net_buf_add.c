/*
 * Function: net_buf_add
 * Entry:    0006287c
 * Prototype: void * __stdcall net_buf_add(net_buf * buf, size_t len)
 */


/* exclude_from_export */

void * net_buf_add(net_buf *buf,size_t len)

{
  ushort uVar1;
  size_t sVar2;
  sys_snode_t *psVar3;
  
  uVar1 = *(ushort *)&buf->frags;
  psVar3 = (buf->node).next;
  sVar2 = net_buf_simple_tailroom((net_buf_simple *)buf);
  if (sVar2 < len) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","net_buf_simple_tailroom(buf) >= len",
            "WEST_TOPDIR/zephyr/subsys/net/buf_simple.c",62);
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  *(ushort *)&buf->frags = uVar1 + (short)len;
  return (void *)((int)&psVar3->next + (uint)uVar1);
}


