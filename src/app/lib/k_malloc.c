/*
 * Function: k_malloc
 * Entry:    0008a072
 * Prototype: void * __stdcall k_malloc(size_t size)
 */


/* exclude_from_export */

void * k_malloc(size_t size)

{
  void *pvVar1;
  
  pvVar1 = k_aligned_alloc(4,size);
  return pvVar1;
}


