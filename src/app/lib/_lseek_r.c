/*
 * Function: _lseek_r
 * Entry:    0007b840
 * Prototype: __off_t __stdcall _lseek_r(void * ptr, int fd, __off_t pos, int whence)
 */


/* exclude_from_export_ai */

__off_t _lseek_r(void *ptr,int fd,__off_t pos,int whence)

{
  __off_t _Var1;
  
  errno = 0;
  _Var1 = _lseek(fd,pos,whence);
  if ((_Var1 == -1) && (errno != 0)) {
    *(int *)ptr = errno;
  }
  return _Var1;
}


