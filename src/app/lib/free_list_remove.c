/*
 * Function: free_list_remove
 * Entry:    0008168e
 * Prototype: void __stdcall free_list_remove(z_heap * h, chunkid_t c)
 */


/* exclude_from_export */

void free_list_remove(z_heap *h,chunkid_t c)

{
  chunksz_t sz;
  int bidx;
  z_heap h_00;
  
  h_00 = h[2];
  sz = chunk_size(h,c);
  if ((0x7fff < (uint)h_00) && (sz == 1)) {
    return;
  }
  bidx = bucket_idx((z_heap *)h_00,sz);
  free_list_remove_bidx(h,c,bidx);
  return;
}


