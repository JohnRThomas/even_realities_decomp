/*
 * Function: _isatty_r
 * Entry:    0007b818
 * Prototype: undefined __stdcall _isatty_r(int * param_1, int param_2)
 */


/* exclude_from_export */

void _isatty_r(int *param_1,int param_2)

{
  int iVar1;
  
  errno = 0;
  iVar1 = _isatty(param_2);
  if ((iVar1 == -1) && (errno != 0)) {
    *param_1 = errno;
  }
  return;
}


