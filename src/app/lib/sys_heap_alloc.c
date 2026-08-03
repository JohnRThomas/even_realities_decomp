/*
 * Function: sys_heap_alloc
 * Entry:    000818c2
 * Prototype: void * __stdcall sys_heap_alloc(sys_heap * heap, size_t bytes)
 */


/* exclude_from_export */

void * sys_heap_alloc(sys_heap *heap,size_t bytes)

{
  chunksz_t sz;
  chunkid_t c;
  chunksz_t cVar1;
  int extraout_r0;
  int iVar2;
  z_heap *h;
  
  h = heap->heap;
  if ((bytes != 0) && (bytes >> 3 < (uint)h[2])) {
    sz = bytes_to_chunksz((z_heap *)h[2],bytes);
    c = alloc_chunk(h,sz);
    if (c != 0) {
      cVar1 = chunk_size(h,c);
      if (sz < cVar1) {
        split_chunks(h,c,sz + c);
        free_list_add(h,sz + c);
      }
      set_chunk_used(h,c,true);
      if ((uint)h[2] < 0x8000) {
        iVar2 = 4;
      }
      else {
        iVar2 = 8;
      }
      return (void *)(extraout_r0 + iVar2 + c * 8);
    }
  }
  return (void *)0x0;
}


