/*
 * Function: malloc
 * Entry:    0007a014
 * Prototype: void * __stdcall malloc(size_t size)
 */


/* exclude_from_export */

void * malloc(size_t size)

{
  void *pvVar1;
  
  pvVar1 = _malloc_r(_REENT,size);
  return pvVar1;
}


