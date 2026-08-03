/*
 * Function: net_buf_push_u8
 * Entry:    00086ec2
 * Prototype: void __stdcall net_buf_push_u8(net_buf * buf, uint8_t val)
 */


/* exclude_from_export_ai */

void net_buf_push_u8(net_buf *buf,uint8_t val)

{
  uint8_t *puVar1;
  
  puVar1 = net_buf_push(buf,1);
  *puVar1 = val;
  return;
}


