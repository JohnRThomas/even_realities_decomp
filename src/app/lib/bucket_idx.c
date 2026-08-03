/*
 * Function: bucket_idx
 * Entry:    0008161a
 * Prototype: int __stdcall bucket_idx(z_heap * h, chunksz_t sz)
 */


/* exclude_from_export */

int bucket_idx(z_heap *h,chunksz_t sz)

{
  chunksz_t cVar1;
  int extraout_r2;
  
  cVar1 = bytes_to_chunksz(h,1);
  return 0x1f - LZCOUNT((extraout_r2 + 1) - cVar1);
}


