/*
 * Function: _fstat
 * Entry:    00083fa0
 * Prototype: int __stdcall _fstat(int __fd, stat * __buf)
 */


/* exclude_from_export */

int _fstat(int __fd,stat *__buf)

{
  *(undefined4 *)((int)&__buf->st_dev + 4) = 0x2000;
  return 0;
}


