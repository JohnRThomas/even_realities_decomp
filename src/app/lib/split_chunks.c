/*
 * Function: split_chunks
 * Entry:    00081730
 * Prototype: void __stdcall split_chunks(z_heap * h, chunkid_t lc, chunkid_t rc)
 */


/* exclude_from_export */

void split_chunks(z_heap *h,chunkid_t lc,chunkid_t rc)

{
  chunksz_t cVar1;
  chunkid_t size;
  
  cVar1 = chunk_size(h,lc);
  size = (lc - rc) + cVar1;
  set_chunk_size(h,lc,rc - lc);
  set_chunk_size(h,rc,size);
  chunk_set(h,rc,LEFT_SIZE,rc - lc);
  cVar1 = chunk_size(h,rc);
  chunk_set(h,rc + cVar1,LEFT_SIZE,size);
  return;
}


