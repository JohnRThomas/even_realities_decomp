/*
 * Function: free_list_remove_bidx
 * Entry:    00081632
 * Prototype: void __stdcall free_list_remove_bidx(z_heap * h, chunkid_t c, int bidx)
 */


/* exclude_from_export */

void free_list_remove_bidx(z_heap *h,chunkid_t c,int bidx)

{
  z_heap val;
  chunkid_t c_00;
  
  val = (z_heap)chunk_field(h,c,FREE_NEXT);
  if ((z_heap)c == val) {
    h[3] = (z_heap)((uint)h[3] & ~(1 << (bidx & 0xffU)));
    h[bidx + 4] = (z_heap)0x0;
    return;
  }
  c_00 = chunk_field(h,c,FREE_PREV);
  h[bidx + 4] = val;
  chunk_set(h,c_00,FREE_NEXT,(chunkid_t)val);
  chunk_set(h,(chunkid_t)val,FREE_PREV,c_00);
  return;
}


