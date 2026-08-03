/*
 * Function: __swrite
 * Entry:    0008a70a
 * Prototype: undefined __stdcall __swrite(int * param_1, int param_2, char * param_3, int param_4)
 */


/* exclude_from_export */

void __swrite(int *param_1,int param_2,char *param_3,int param_4)

{
  int iVar1;
  
  if ((int)((uint)*(ushort *)(param_2 + 0xc) << 0x17) < 0) {
    _lseek_r(param_1,(int)*(short *)(param_2 + 0xe),0,2);
  }
  *(ushort *)(param_2 + 0xc) = *(ushort *)(param_2 + 0xc) & 0xefff;
  errno = 0;
  iVar1 = _write((int)*(short *)(param_2 + 0xe),param_3,param_4);
  if ((iVar1 == -1) && (errno != 0)) {
    *param_1 = errno;
  }
  return;
}


