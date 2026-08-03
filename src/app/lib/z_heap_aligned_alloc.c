/*
 * Function: z_heap_aligned_alloc
 * Entry:    00078b0c
 * Prototype: void * __stdcall z_heap_aligned_alloc(k_heap * heap, size_t align, size_t size)
 */


/* exclude_from_export */

void * z_heap_aligned_alloc(k_heap *heap,size_t align,size_t size)

{
  k_timeout_t timeout;
  undefined4 *puVar1;
  uint in_r3;
  int line;
  char *test;
  
  if ((0xfffffffb < size) ||
     (timeout.ticks._4_4_ = 0, timeout.ticks._0_4_ = in_r3,
     puVar1 = k_heap_aligned_alloc(heap,align | 4,size + 4,timeout), puVar1 == (undefined4 *)0x0)) {
    return (void *)0x0;
  }
  test = (char *)(puVar1 + 1);
  *puVar1 = heap;
  if (align == 0) {
    return test;
  }
  if (((uint)test & align - 1) == 0) {
    return test;
  }
  _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","align == 0 || ((uintptr_t)mem & (align - 1)) == 0",
          "WEST_TOPDIR/zephyr/kernel/mempool.c",37);
  _ASSERT("\tmisaligned memory at %p (align = %zu)\n",test,(char *)align,line);
                    /* WARNING: Subroutine does not return */
  k_panic();
}


