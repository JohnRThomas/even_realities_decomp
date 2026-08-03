/*
 * Function: net_buf_simple_headroom
 * Entry:    00086ee0
 * Prototype: size_t __stdcall net_buf_simple_headroom(net_buf_simple * buf)
 */


/* exclude_from_export */

size_t net_buf_simple_headroom(net_buf_simple *buf)

{
  return (int)buf->data - (int)buf->__buf;
}


