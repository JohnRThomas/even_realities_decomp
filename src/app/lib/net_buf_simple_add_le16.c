/*
 * Function: net_buf_simple_add_le16
 * Entry:    00086f1e
 * Prototype: void __stdcall net_buf_simple_add_le16(net_buf_simple * buf, uint16_t val)
 */


/* exclude_from_export */

void net_buf_simple_add_le16(net_buf_simple *buf,uint16_t val)

{
  uint16_t *puVar1;
  
  puVar1 = net_buf_add((net_buf *)buf,2);
  *puVar1 = val;
  return;
}


