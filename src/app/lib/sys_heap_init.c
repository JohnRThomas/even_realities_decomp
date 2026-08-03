/*
 * Function: sys_heap_init
 * Entry:    0004e668
 * Prototype: void __stdcall sys_heap_init(sys_heap * heap, void * mem, size_t bytes)
 */


/* exclude_from_export */

void sys_heap_init(sys_heap *heap,void *mem,size_t bytes)

{
  chunksz_t cVar1;
  z_heap *h;
  z_heap *h_00;
  char *test;
  uint uVar2;
  char *test_00;
  char *test_01;
  char *file;
  char *file_00;
  int extraout_r2;
  size_t n;
  chunksz_t size;
  char *file_01;
  int line;
  int line_00;
  int iVar3;
  int line_01;
  z_heap *h_01;
  z_heap h_02;
  
  if (bytes < 0x40000) {
    if (bytes < 5) {
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","bytes > heap_footer_bytes(bytes)",
              "WEST_TOPDIR/zephyr/lib/os/heap.c",498);
      _ASSERT("\theap size is too small\n",test,file,line);
      goto LAB_0004e68e;
    }
    iVar3 = 4;
  }
  else {
    iVar3 = 8;
  }
  h_01 = (z_heap *)((int)mem + 7U & 0xfffffff8);
  uVar2 = ((int)mem + (bytes - iVar3) & 0xfffffff8) - (int)h_01;
  h_02 = (z_heap)(uVar2 >> 3);
  if (uVar2 < 0x18) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","heap_sz > chunksz(sizeof(struct z_heap))",
            "WEST_TOPDIR/zephyr/lib/os/heap.c",0x1fb);
    _ASSERT("\theap size is too small\n",test_00,file_00,line_00);
  }
  else {
    heap->heap = h_01;
    h_01[2] = h_02;
    h_01[3] = (z_heap)0x0;
    iVar3 = bucket_idx((z_heap *)h_02,(chunksz_t)h_02);
    cVar1 = bytes_to_chunksz((z_heap *)h_02,1);
    uVar2 = extraout_r2 * 4 + 7U >> 3;
    if (cVar1 + uVar2 <= (uint)h_02) {
      n = extraout_r2 * 4 - 0x10;
      if (iVar3 < -1) {
        n = 0;
      }
      memset(h_01 + 4,0,n);
      set_chunk_size(h_01,0,uVar2);
      chunk_set(h_01,0,LEFT_SIZE,0);
      set_chunk_used(h_01,0,true);
      set_chunk_size(h,uVar2,(int)h_02 - uVar2);
      chunk_set(h_01,uVar2,LEFT_SIZE,uVar2);
      set_chunk_size(h_01,(chunkid_t)h_02,size);
      chunk_set(h_01,(chunkid_t)h_02,LEFT_SIZE,(int)h_02 - uVar2);
      set_chunk_used(h_01,(chunkid_t)h_02,true);
      free_list_add(h_00,uVar2);
      return;
    }
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","chunk0_size + min_chunk_size(h) <= heap_sz",
            "WEST_TOPDIR/zephyr/lib/os/heap.c",524);
    _ASSERT("\theap size is too small\n",test_01,file_01,line_01);
  }
LAB_0004e68e:
                    /* WARNING: Subroutine does not return */
  k_panic();
}


