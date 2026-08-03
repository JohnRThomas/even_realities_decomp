/*
 * Function: sbrk_aligned
 * Entry:    0007ab9c
 * Prototype: undefined __stdcall sbrk_aligned(int * param_1, intptr_t param_2)
 */


/* exclude_from_export_ai */

void sbrk_aligned(int *param_1,intptr_t param_2)

{
  void *pvVar1;
  
  errno = 0;
  pvVar1 = _sbrk(param_2);
  if ((pvVar1 == (void *)0xffffffff) && (errno != 0)) {
    *param_1 = errno;
  }
  return;
}


