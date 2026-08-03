/*
 * Function: sys_heap_free
 * Entry:    0004e4b4
 * Prototype: void __stdcall sys_heap_free(sys_heap * heap, void * mem)
 */


/* exclude_from_export */

void sys_heap_free(sys_heap *heap,void *mem)

{
  chunkid_t c;
  chunkid_t cVar1;
  chunksz_t cVar2;
  z_heap *h;
  bool used;
  chunk_fields f;
  char *file;
  char *file_00;
  int line;
  int line_00;
  z_heap *h_00;
  
  if (mem == (void *)0x0) {
    return;
  }
  h_00 = heap->heap;
  c = mem_to_chunkid(h_00,mem);
  cVar1 = chunk_field(h_00,c,f);
  if ((int)(cVar1 << 0x1f) < 0) {
    cVar2 = chunk_size(h_00,c);
    cVar1 = chunk_field(h_00,c + cVar2,LEFT_SIZE);
    if (c == (c + cVar2) - cVar1) {
      set_chunk_used(h_00,c,used);
      free_chunk(h,c);
      return;
    }
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","left_chunk(h, right_chunk(h, c)) == c",
            "WEST_TOPDIR/zephyr/lib/os/heap.c",183);
    _ASSERT("\tcorrupted heap bounds (buffer overflow?) for memory at %p\n",mem,file_00,line_00);
  }
  else {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","chunk_used(h, c)","WEST_TOPDIR/zephyr/lib/os/heap.c",
            175);
    _ASSERT("\tunexpected heap state (double-free?) for memory at %p\n",mem,file,line);
  }
                    /* WARNING: Subroutine does not return */
  k_panic();
}


