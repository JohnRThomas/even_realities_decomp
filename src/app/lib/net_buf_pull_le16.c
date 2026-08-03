/*
 * Function: net_buf_pull_le16
 * Entry:    00086ed0
 * Prototype: uint16_t __stdcall net_buf_pull_le16(net_buf * buf)
 */


/* exclude_from_export */

uint16_t net_buf_pull_le16(net_buf *buf)

{
  uint16_t uVar1;
  
  uVar1 = *(uint16_t *)&((buf->node).next)->next;
  net_buf_simple_pull((net_buf_simple *)buf);
  return uVar1;
}


