/*
 * Function: _realloc_r
 * Entry:    0008ae9c
 * Prototype: void * __stdcall _realloc_r(undefined4 * param_1, void * param_2, size_t param_3)
 */


/* exclude_from_export_ai */

void * _realloc_r(undefined4 *param_1,void *param_2,size_t param_3)

{
  void *pvVar1;
  uint uVar2;
  
  if (param_2 == (void *)0x0) {
    pvVar1 = _malloc_r((size_t)param_1,param_3);
    return pvVar1;
  }
  if (param_3 == 0) {
    _free_r(param_1,(int)param_2);
  }
  else {
    uVar2 = _malloc_usable_size_r(param_1,(int)param_2);
    if (param_3 <= uVar2) {
      return param_2;
    }
    pvVar1 = _malloc_r((size_t)param_1,param_3);
    if (pvVar1 != (void *)0x0) {
      memcpy(pvVar1,param_2,param_3);
      _free_r(param_1,(int)param_2);
      return pvVar1;
    }
  }
  return (void *)0x0;
}


