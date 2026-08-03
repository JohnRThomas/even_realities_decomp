/*
 * Function: chunk_size
 * Entry:    000815b0
 * Prototype: chunksz_t __stdcall chunk_size(z_heap * h, chunkid_t c)
 */


/* exclude_from_export */

chunksz_t chunk_size(z_heap *h,chunkid_t c)

{
  chunkid_t cVar1;
  uint extraout_r2;
  
  cVar1 = chunk_field(h,c,SIZE_AND_USED);
  return cVar1 >> (extraout_r2 & 0xff);
}


