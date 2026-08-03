/*
 * Function: sys_heap_aligned_alloc
 * Entry:    0004e550
 * Prototype: void * __stdcall sys_heap_aligned_alloc(sys_heap * heap, size_t align, size_t bytes)
 */


/* exclude_from_export */

void * sys_heap_aligned_alloc(sys_heap *heap,size_t align,size_t bytes)

{
  chunksz_t cVar1;
  chunkid_t lc;
  chunkid_t rc;
  uint uVar2;
  char *test;
  z_heap h;
  char *file;
  size_t sVar3;
  int line;
  int iVar4;
  void *pvVar5;
  z_heap *h_00;
  uint uVar6;
  
  h_00 = heap->heap;
  h = h_00[2];
  if ((uint)h < 0x8000) {
    uVar2 = 4;
  }
  else {
    uVar2 = 8;
  }
  sVar3 = align - 1 & align;
  if (sVar3 == 0) {
    if (align <= uVar2) {
      pvVar5 = sys_heap_alloc(heap,bytes);
      return pvVar5;
    }
    uVar6 = 0;
    sVar3 = align;
  }
  else {
    uVar6 = -align & align;
    if (uVar6 <= uVar2) {
      uVar2 = uVar6;
    }
    if ((sVar3 - 1 & sVar3) != 0) {
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","(align & (align - 1)) == 0",
              "WEST_TOPDIR/zephyr/lib/os/heap.c",324);
      _ASSERT("\talign must be a power of 2\n",test,file,line);
                    /* WARNING: Subroutine does not return */
      k_panic();
    }
  }
  if ((bytes != 0) && (bytes >> 3 < (uint)h)) {
    cVar1 = bytes_to_chunksz((z_heap *)h,(bytes + sVar3) - uVar2);
    lc = alloc_chunk(h_00,cVar1);
    if (lc != 0) {
      if ((uint)h_00[2] < 0x8000) {
        iVar4 = 4;
      }
      else {
        iVar4 = 8;
      }
      pvVar5 = (void *)(sVar3 * (((int)h_00 + (sVar3 - 1) + uVar6 + lc * 8 + iVar4) / sVar3) - uVar6
                       );
      rc = mem_to_chunkid(h_00,pvVar5);
      uVar2 = (int)(((int)pvVar5 + bytes + 7 & 0xfffffff8) - (int)h_00) >> 3;
      if (lc < rc) {
        split_chunks(h_00,lc,rc);
        free_list_add(h_00,lc);
      }
      cVar1 = chunk_size(h_00,rc);
      if (uVar2 < cVar1 + rc) {
        split_chunks(h_00,rc,uVar2);
        free_list_add(h_00,uVar2);
      }
      set_chunk_used(h_00,rc,true);
      return pvVar5;
    }
  }
  return (void *)0x0;
}


