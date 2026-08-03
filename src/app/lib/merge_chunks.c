/*
 * Function: merge_chunks
 * Entry:    0008177e
 * Prototype: void __stdcall merge_chunks(z_heap * h, chunkid_t lc, chunkid_t rc)
 */


/* exclude_from_export */

void merge_chunks(z_heap *h,chunkid_t lc,chunkid_t rc)

{
  chunksz_t cVar1;
  chunksz_t cVar2;
  chunksz_t cVar3;
  
  cVar1 = chunk_size(h,lc);
  cVar2 = chunk_size(h,rc);
  set_chunk_size(h,lc,cVar1 + cVar2);
  cVar3 = chunk_size(h,rc);
  chunk_set(h,rc + cVar3,LEFT_SIZE,cVar1 + cVar2);
  return;
}


