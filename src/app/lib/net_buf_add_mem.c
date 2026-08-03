/*
 * Function: net_buf_add_mem
 * Entry:    00086ef8
 * Prototype: void * __stdcall net_buf_add_mem(net_buf * buf, void * mem, size_t len)
 */


/* exclude_from_export */

void * net_buf_add_mem(net_buf *buf,void *mem,size_t len)

{
  void *pvVar1;
  
  pvVar1 = net_buf_add(buf,len);
  pvVar1 = memcpy(pvVar1,mem,len);
  return pvVar1;
}


