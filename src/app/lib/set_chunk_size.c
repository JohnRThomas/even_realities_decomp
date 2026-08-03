/*
 * Function: set_chunk_size
 * Entry:    000815ec
 * Prototype: void __stdcall set_chunk_size(z_heap * h, chunkid_t c, chunksz_t size)
 */


/* exclude_from_export */

void set_chunk_size(z_heap *h,chunkid_t c,chunksz_t size)

{
  chunk_set(h,c,SIZE_AND_USED,size << 1);
  return;
}


