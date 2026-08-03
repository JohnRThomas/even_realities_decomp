/*
 * Function: net_buf_add_u8
 * Entry:    00086f10
 * Prototype: uint8_t * __stdcall net_buf_add_u8(net_buf * buf, uint8_t val)
 */


/* exclude_from_export */

uint8_t * net_buf_add_u8(net_buf *buf,uint8_t val)

{
  uint8_t *puVar1;
  
  puVar1 = net_buf_add(buf,1);
  *puVar1 = val;
  return puVar1;
}


