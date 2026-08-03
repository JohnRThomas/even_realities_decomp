/*
 * Function: free
 * Entry:    0007a024
 * Prototype: void __stdcall free(void * ptr)
 */


/* exclude_from_export_ai */

void free(void *ptr)

{
  _free_r(_REENT,(int)ptr);
  return;
}


