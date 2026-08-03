/*
 * Function: mutex_free_platform
 * Entry:    00052fb0
 * Prototype: void __stdcall mutex_free_platform(net_buf * buf)
 */


/* exclude_from_export_ai */

void mutex_free_platform(net_buf *buf)

{
  sys_snode_t *buf_00;
  net_buf *pnVar1;
  
  if (buf == (net_buf *)0x0) {
    (*nrf_cc3xx_platform_abort_apis_t_20002f10.abort_fn)("mutex_init called with NULL parameter");
  }
  pnVar1 = buf->frags;
  if (((pnVar1 != (net_buf *)0x3a000) && (pnVar1 != (net_buf *)0xe80000)) &&
     (pnVar1 != (net_buf *)0xa95c5f2c)) {
    buf_00 = (buf->node).next;
    if (((uint)pnVar1 & 0xe80) == 0) {
      memset(buf_00,0,0x14);
    }
    else {
      k_mem_slab_free((k_mem_slab *)&DAT_2000b1b4,buf_00);
      (buf->node).next = (sys_snode_t *)0x0;
    }
    buf->frags = (net_buf *)0xa95c5f2c;
  }
  return;
}


