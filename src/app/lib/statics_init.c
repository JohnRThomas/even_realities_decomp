/*
 * Function: statics_init
 * Entry:    00074c4c
 * Prototype: int __stdcall statics_init(void)
 */


/* exclude_from_export */

int statics_init(void)

{
  char *test;
  char *file;
  int line;
  k_heap *h;
  
  h = (k_heap *)&DAT_20003978;
  while( true ) {
    if ((k_heap *)&DAT_20003990 < h) {
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","h <= _k_heap_list_end",
              "WEST_TOPDIR/zephyr/kernel/kheap.c",24);
      _ASSERT("\tunexpected list end location\n",test,file,line);
                    /* WARNING: Subroutine does not return */
      k_panic();
    }
    if ((k_heap *)0x2000398f < h) break;
    k_heap_init(h,(void *)h[1],(size_t)h[2]);
    h = h + 6;
  }
  return 0;
}


