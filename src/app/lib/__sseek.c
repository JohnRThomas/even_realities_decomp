/*
 * Function: __sseek
 * Entry:    0008a742
 * Prototype: undefined __stdcall __sseek(void * param_1, int param_2, __off_t param_3, int param_4)
 */


/* exclude_from_export */

void __sseek(void *param_1,int param_2,__off_t param_3,int param_4)

{
  __off_t _Var1;
  
  _Var1 = _lseek_r(param_1,(int)*(short *)(param_2 + 0xe),param_3,param_4);
  if (_Var1 == -1) {
    *(ushort *)(param_2 + 0xc) = *(ushort *)(param_2 + 0xc) & 0xefff;
  }
  else {
    *(__off_t *)(param_2 + 0x54) = _Var1;
    *(ushort *)(param_2 + 0xc) = *(ushort *)(param_2 + 0xc) | 0x1000;
  }
  return;
}


