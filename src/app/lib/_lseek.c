/*
 * Function: _lseek
 * Entry:    0004e41c
 * Prototype: __off_t __stdcall _lseek(int __fd, __off_t __offset, int __whence)
 */


/* exclude_from_export_ai */

__off_t _lseek(int __fd,__off_t __offset,int __whence)

{
  int iVar1;
  __off_t _Var2;
  
  iVar1 = console_write(__fd);
  if (iVar1 < 0) {
    _Var2 = -1;
  }
  else {
    _Var2 = __FUN_00081450(*(int *)(&DAT_2000256c + __fd * 0x28),
                           *(undefined4 *)(&DAT_20002568 + __fd * 0x28),0x101,__offset);
  }
  return _Var2;
}


