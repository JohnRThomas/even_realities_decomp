/*
 * Function: _fstat_r
 * Entry:    0007b0f4
 * Prototype: undefined __stdcall _fstat_r(int * param_1, int param_2, stat * param_3)
 */


/* exclude_from_export */

void _fstat_r(int *param_1,int param_2,stat *param_3)

{
  int iVar1;
  
  errno = 0;
  iVar1 = _fstat(param_2,param_3);
  if ((iVar1 == -1) && (errno != 0)) {
    *param_1 = errno;
  }
  return;
}


