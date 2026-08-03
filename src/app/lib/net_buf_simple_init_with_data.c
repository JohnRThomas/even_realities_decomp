/*
 * Function: net_buf_simple_init_with_data
 * Entry:    00086ea4
 * Prototype: void __stdcall net_buf_simple_init_with_data(net_buf_simple * buf, void * data, size_t size)
 */


/* exclude_from_export */

void net_buf_simple_init_with_data(net_buf_simple *buf,void *data,size_t size)

{
  buf->__buf = data;
  buf->data = data;
  buf->size = (word)size;
  buf->len = (word)size;
  return;
}


