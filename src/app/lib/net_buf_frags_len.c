/*
 * Function: net_buf_frags_len
 * Entry:    00085378
 * Prototype: size_t __stdcall net_buf_frags_len(net_buf * buf)
 */


/* exclude_from_export */

size_t net_buf_frags_len(net_buf *buf)

{
  size_t sVar1;
  
  sVar1 = 0;
  for (; buf != (net_buf *)0x0; buf = buf->frags) {
    sVar1 = sVar1 + (buf->field6_0xc).field0.len;
  }
  return sVar1;
}


