/*
 * Function: free_list_add
 * Entry:    000817ba
 * Prototype: void __stdcall free_list_add(z_heap * h, chunkid_t c)
 */


/* exclude_from_export */

void free_list_add(z_heap *h,chunkid_t c)

{
  chunksz_t sz;
  uint uVar1;
  chunkid_t cVar2;
  chunk_fields f;
  chunk_fields f_00;
  chunk_fields f_01;
  chunkid_t extraout_r3;
  chunkid_t extraout_r3_00;
  z_heap zVar3;
  
  zVar3 = h[2];
  sz = chunk_size(h,c);
  if ((0x7fff < (uint)zVar3) && (sz == 1)) {
    return;
  }
  uVar1 = bucket_idx((z_heap *)zVar3,sz);
  zVar3 = h[uVar1 + 4];
  if (zVar3 == (z_heap)0x0) {
    h[3] = (z_heap)((uint)h[3] | 1 << (uVar1 & 0xff));
    h[uVar1 + 4] = (z_heap)c;
    chunk_set(h,c,FREE_PREV,c);
    f = FREE_NEXT;
    zVar3 = (z_heap)c;
    cVar2 = extraout_r3;
  }
  else {
    cVar2 = chunk_field(h,(chunkid_t)zVar3,FREE_PREV);
    chunk_set(h,c,f_00,cVar2);
    chunk_set(h,c,FREE_NEXT,(chunkid_t)zVar3);
    chunk_set(h,cVar2,f_01,c);
    f = FREE_PREV;
    cVar2 = extraout_r3_00;
  }
  chunk_set(h,(chunkid_t)zVar3,f,cVar2);
  return;
}


