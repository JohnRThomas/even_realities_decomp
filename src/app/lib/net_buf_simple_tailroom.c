/*
 * Function: net_buf_simple_tailroom
 * Entry:    00086ee8
 * Prototype: size_t __stdcall net_buf_simple_tailroom(net_buf_simple * buf)
 */


/* exclude_from_export */

size_t net_buf_simple_tailroom(net_buf_simple *buf)

{
  return ((uint)buf->size - (uint)buf->len) - ((int)buf->data - (int)buf->__buf);
}


