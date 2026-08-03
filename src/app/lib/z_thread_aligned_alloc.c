/*
 * Function: z_thread_aligned_alloc
 * Entry:    00078bec
 * Prototype: void * __stdcall z_thread_aligned_alloc(size_t align, size_t size)
 */


/* exclude_from_export */

void * z_thread_aligned_alloc(size_t align,size_t size)

{
  bool bVar1;
  void *pvVar2;
  k_heap *heap;
  
  bVar1 = k_is_in_isr();
  if (bVar1) {
    heap = (k_heap *)&DAT_20003978;
  }
  else {
    heap = *(k_heap **)(_current.base + 0x88);
    if (heap == (k_heap *)0x0) {
      return (void *)0x0;
    }
  }
  pvVar2 = z_heap_aligned_alloc(heap,align,size);
  return pvVar2;
}


