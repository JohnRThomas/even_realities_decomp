/*
 * Function: realloc
 * Entry:    0007ab8c
 * Prototype: void * __stdcall realloc(void * __ptr, size_t __size)
 */


/* exclude_from_export */

void * realloc(void *__ptr,size_t __size)

{
  void *pvVar1;
  
  pvVar1 = _realloc_r(_REENT,__ptr,__size);
  return pvVar1;
}


