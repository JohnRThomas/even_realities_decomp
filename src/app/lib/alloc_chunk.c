/*
 * Function: alloc_chunk
 * Entry:    000816bc
 * Prototype: chunkid_t __stdcall alloc_chunk(z_heap * h, chunksz_t sz)
 */


/* exclude_from_export */

chunkid_t alloc_chunk(z_heap *h,chunksz_t sz)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  int bidx;
  chunksz_t cVar5;
  z_heap zVar6;
  uint uVar7;
  int iVar8;
  z_heap zVar9;
  
  bidx = bucket_idx((z_heap *)h[2],sz);
  zVar9 = h[bidx + 4];
  if (zVar9 != (z_heap)0x0) {
    iVar8 = 3;
    do {
      zVar6 = h[bidx + 4];
      cVar5 = chunk_size(h,(chunkid_t)zVar6);
      if (sz <= cVar5) goto LAB_000816ee;
      zVar6 = (z_heap)chunk_field(h,(chunkid_t)zVar6,FREE_NEXT);
      iVar8 = iVar8 + -1;
      h[bidx + 4] = zVar6;
    } while ((iVar8 != 0) && (zVar9 != zVar6));
  }
  uVar7 = -1 << (bidx + 1U & 0xff) & (uint)h[3];
  zVar6 = (z_heap)0x0;
  if (uVar7 != 0) {
    bVar2 = (byte)uVar7;
    bVar3 = (byte)(uVar7 >> 8);
    bVar4 = (byte)(uVar7 >> 0x10);
    bVar1 = (byte)(uVar7 >> 0x18);
    bidx = LZCOUNT((uint)(byte)((((((((bVar2 & 1) << 1 | bVar2 >> 1 & 1) << 1 | bVar2 >> 2 & 1) << 1
                                   | bVar2 >> 3 & 1) << 1 | bVar2 >> 4 & 1) << 1 | bVar2 >> 5 & 1)
                                 << 1 | bVar2 >> 6 & 1) << 1 | bVar2 >> 7) << 0x18 |
                   (uint)(byte)((((((((bVar3 & 1) << 1 | bVar3 >> 1 & 1) << 1 | bVar3 >> 2 & 1) << 1
                                   | bVar3 >> 3 & 1) << 1 | bVar3 >> 4 & 1) << 1 | bVar3 >> 5 & 1)
                                 << 1 | bVar3 >> 6 & 1) << 1 | bVar3 >> 7) << 0x10 |
                   (uint)(byte)((((((((bVar4 & 1) << 1 | bVar4 >> 1 & 1) << 1 | bVar4 >> 2 & 1) << 1
                                   | bVar4 >> 3 & 1) << 1 | bVar4 >> 4 & 1) << 1 | bVar4 >> 5 & 1)
                                 << 1 | bVar4 >> 6 & 1) << 1 | bVar4 >> 7) << 8 |
                   (uint)(byte)((((((((bVar1 & 1) << 1 | bVar1 >> 1 & 1) << 1 | bVar1 >> 2 & 1) << 1
                                   | bVar1 >> 3 & 1) << 1 | bVar1 >> 4 & 1) << 1 | bVar1 >> 5 & 1)
                                 << 1 | bVar1 >> 6 & 1) << 1 | bVar1 >> 7));
    zVar6 = h[bidx + 4];
LAB_000816ee:
    free_list_remove_bidx(h,(chunkid_t)zVar6,bidx);
  }
  return (chunkid_t)zVar6;
}


