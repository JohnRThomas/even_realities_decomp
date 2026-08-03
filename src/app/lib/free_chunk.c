/*
 * Function: free_chunk
 * Entry:    0008183e
 * Prototype: void __stdcall free_chunk(z_heap * h, chunkid_t c)
 */


/* exclude_from_export */

void free_chunk(z_heap *h,chunkid_t c)

{
  chunksz_t cVar1;
  chunkid_t cVar2;
  chunkid_t cVar3;
  uint extraout_r2;
  
  cVar1 = chunk_size(h,c);
  cVar2 = chunk_field(h,c + cVar1,SIZE_AND_USED);
  if (-1 < (int)(cVar2 << 0x1f)) {
    free_list_remove(h,c + cVar1);
    cVar1 = chunk_size(h,c);
    merge_chunks(h,c,c + cVar1);
  }
  cVar2 = chunk_field(h,c,LEFT_SIZE);
  cVar3 = chunk_field(h,c - cVar2,SIZE_AND_USED);
  if ((cVar3 & extraout_r2) == 0) {
    free_list_remove(h,c - cVar2);
    cVar2 = chunk_field(h,c,LEFT_SIZE);
    merge_chunks(h,c - cVar2,c);
    cVar2 = chunk_field(h,c,LEFT_SIZE);
    c = c - cVar2;
  }
  free_list_add(h,c);
  return;
}


