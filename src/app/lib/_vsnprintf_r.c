/*
 * Function: _vsnprintf_r
 * Entry:    0008a8de
 * Prototype: int __stdcall _vsnprintf_r(undefined4 * ptr, char * str, size_t size, char * fmt, va_list ap)
 */


/* exclude_from_export */

int _vsnprintf_r(undefined4 *ptr,char *str,size_t size,char *fmt,va_list ap)

{
  int iVar1;
  char *local_78;
  char *local_70;
  undefined2 local_6c;
  undefined2 local_6a;
  char *local_68;
  char *local_64;
  
  if ((int)size < 0) {
    *ptr = 0x8b;
    iVar1 = -1;
  }
  else {
    local_6c = 0x208;
    if (size == 0) {
      local_70 = (char *)0x0;
    }
    else {
      local_70 = (char *)(size - 1);
    }
    local_6a = 0xffff;
    local_78 = str;
    local_68 = str;
    local_64 = local_70;
    iVar1 = fprintf(ptr,(FILE *)&local_78,fmt,ap);
    if (iVar1 < -1) {
      *ptr = 0x8b;
    }
    if (size != 0) {
      *local_78 = '\0';
    }
  }
  return iVar1;
}


