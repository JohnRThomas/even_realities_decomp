/*
 * Function: k_heap_init
 * Entry:    00089b5a
 * Prototype: void __stdcall k_heap_init(k_heap * h, void * mem, size_t bytes)
 */


/* exclude_from_export */

void k_heap_init(k_heap *h,void *mem,size_t bytes)

{
  h[3] = (k_heap)(h + 3);
  h[4] = (k_heap)(h + 3);
  sys_heap_init((sys_heap *)h,mem,bytes);
  return;
}


