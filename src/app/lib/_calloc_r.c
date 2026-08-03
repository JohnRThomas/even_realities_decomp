/*
 * Function: _calloc_r
 * Entry:    0008ae80
 * Prototype: void * __stdcall _calloc_r(size_t param_1, int param_2, int param_3)
 */


/* exclude_from_export_ai */

void * _calloc_r(size_t param_1,int param_2,int param_3)

{
  void *buf;
  
  buf = _malloc_r(param_1,param_3 * param_2);
  if (buf != (void *)0x0) {
    memset(buf,0,param_3 * param_2);
  }
  return buf;
}


