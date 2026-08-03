/*
 * Function: _write
 * Entry:    0007c7d0
 * Prototype: ssize_t __stdcall _write(int __fd, void * __buf, size_t __n)
 */


/* exclude_from_export_ai */

ssize_t _write(int __fd,void *__buf,size_t __n)

{
  int iVar1;
  undefined4 in_r3;
  
  errno = 0;
  iVar1 = console_putchar((uint)__buf,__n,in_r3);
  if ((iVar1 == -1) && (errno != 0)) {
    *(int *)__fd = errno;
  }
  return iVar1;
}


