/*
 * Function: snprintf
 * Entry:    0007abbc
 * Prototype: int __stdcall snprintf(char * buf, ulong len, char * f, ...)
 */


/* exclude_from_export */

int snprintf(char *buf,ulong len,char *f,...)

{
  undefined4 *puVar1;
  int iVar2;
  char *local_80;
  char *local_78;
  undefined2 local_74;
  undefined2 local_72;
  char *local_70;
  char *local_6c;
  
  puVar1 = _REENT;
  if ((int)len < 0) {
    iVar2 = -1;
    *_REENT = 0x8b;
  }
  else {
    local_74 = 0x208;
    if (len == 0) {
      local_78 = (char *)0x0;
    }
    else {
      local_78 = (char *)(len - 1);
    }
    local_72 = 0xffff;
    local_80 = buf;
    local_70 = buf;
    local_6c = local_78;
    iVar2 = fprintf(_REENT,(FILE *)&local_80,f);
    if (iVar2 < -1) {
      *puVar1 = 0x8b;
    }
    if (len != 0) {
      *local_80 = '\0';
    }
  }
  return iVar2;
}


