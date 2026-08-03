/*
 * Function: virtqueue_allocate
 * Entry:    00082520
 * Prototype: virtqueue * __stdcall virtqueue_allocate(uint num_desc_extra)
 */


/* exclude_from_export_ai */

virtqueue * virtqueue_allocate(uint num_desc_extra)

{
  virtqueue *buf;
  size_t size;
  
  size = num_desc_extra * 8 + 0x34;
  buf = k_malloc(size);
  if (buf != (virtqueue *)0x0) {
    memset(buf,0,size);
  }
  return buf;
}


