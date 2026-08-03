/*
 * Function: k_aligned_alloc
 * Entry:    00078b74
 * Prototype: void * __stdcall k_aligned_alloc(size_t align, size_t size)
 */


/* exclude_from_export */

void * k_aligned_alloc(size_t align,size_t size)

{
  void *pvVar1;
  char *test;
  char *test_00;
  char *file;
  char *file_00;
  int line;
  int line_00;
  
  if ((align < 4) || ((align & 3) != 0)) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n",
            "align / sizeof(void *) >= 1 && (align % sizeof(void *)) == 0",
            "WEST_TOPDIR/zephyr/kernel/mempool.c",66);
    _ASSERT("\talign must be a multiple of sizeof(void *)\n",test,file,line);
  }
  else {
    if ((align - 1 & align) == 0) {
      pvVar1 = z_heap_aligned_alloc((k_heap *)&DAT_20003978,align,size);
      return pvVar1;
    }
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","(align & (align - 1)) == 0",
            "WEST_TOPDIR/zephyr/kernel/mempool.c",70);
    _ASSERT("\talign must be a power of 2\n",test_00,file_00,line_00);
  }
                    /* WARNING: Subroutine does not return */
  k_panic();
}


