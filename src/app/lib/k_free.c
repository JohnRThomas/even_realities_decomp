/*
 * Function: k_free
 * Entry:    0008a064
 * Prototype: void __stdcall k_free(void * ptr)
 */


/* exclude_from_export */

void k_free(void *ptr)

{
  if (ptr != (void *)0x0) {
    k_heap_free(*(sys_heap **)((int)ptr + -4),(void *)((int)ptr + -4));
    return;
  }
  return;
}


