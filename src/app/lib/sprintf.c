/*
 * Function: sprintf
 * Entry:    0007ac24
 * Prototype: int __stdcall sprintf(char * buf, char * f, ...)
 */


/* exclude_from_export_ai */

int sprintf(char *buf,char *f,...)

{
  int iVar1;
  char *local_78;
  char *local_70;
  char *local_6c;
  char *local_68;
  char *local_64;
  
  local_64 = &DAT_7fffffff;
  local_70 = &DAT_7fffffff;
  local_6c = (char *)0xffff0208;
  local_78 = buf;
  local_68 = buf;
  iVar1 = fprintf(_REENT,(FILE *)&local_78,f);
  *local_78 = '\0';
  return iVar1;
}


