/*
 * Function: net_buf_unref
 * Entry:    000624f8
 * Prototype: void __stdcall net_buf_unref(net_buf * buf)
 */


/* exclude_from_export */

void net_buf_unref(net_buf *buf)

{
  byte bVar1;
  uint8_t uVar2;
  net_buf *pnVar3;
  
  if (buf == (net_buf *)0x0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","buf","WEST_TOPDIR/zephyr/subsys/net/buf.c",467);
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  do {
    pnVar3 = buf->frags;
    uVar2 = buf->ref + 0xff;
    buf->ref = uVar2;
    if (uVar2 != '\0') {
      return;
    }
    if ((buf->field6_0xc).field0.__buf != (uint8_t *)0x0) {
      if (-1 < (int)((uint)buf->flags << 0x1f)) {
        (**(code **)(**(int **)(&DAT_20003c48 + (uint)buf->pool_id * 0x34) + 8))(buf);
      }
      (buf->field6_0xc).field0.__buf = (uint8_t *)0x0;
    }
    bVar1 = buf->pool_id;
    (buf->field6_0xc).field0.data = (uint8_t *)0x0;
    buf->frags = (net_buf *)0x0;
    if (*(code **)(&DAT_20003c44 + (uint)bVar1 * 0x34) == (code *)0x0) {
      k_queue_prepend((k_queue *)(&DAT_20003c1c + (uint)bVar1 * 0x34),buf);
    }
    else {
      (**(code **)(&DAT_20003c44 + (uint)bVar1 * 0x34))(buf);
    }
    buf = pnVar3;
  } while (pnVar3 != (net_buf *)0x0);
  return;
}


