/*
 * Function: _close_r
 * Entry:    0008a766
 * Prototype: undefined __stdcall _close_r(int * param_1, int param_2)
 */


/* exclude_from_export */

void _close_r(int *param_1,int param_2)

{
  int iVar1;
  
  errno = 0;
  iVar1 = _close((int)*(short *)(param_2 + 0xe));
  if ((iVar1 == -1) && (errno != 0)) {
    *param_1 = errno;
  }
  return;
}


