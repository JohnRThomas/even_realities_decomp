/*
 * Function: sscanf
 * Entry:    0007ac64
 * Prototype: int __stdcall sscanf(FILE * fp, char * fmt, va_list ap)
 */


/* exclude_from_export */

int sscanf(FILE *fp,char *fmt,va_list ap)

{
  int iVar1;
  FILE *local_80;
  char *local_7c;
  undefined2 local_74;
  undefined2 local_72;
  FILE *local_70;
  char *local_6c;
  char *local_5c;
  _IO_FILE *local_4c;
  _IO_lock_t *local_38;
  va_list avStack_8 [2];
  
  local_74 = 0x204;
  local_80 = fp;
  local_70 = fp;
  avStack_8[0] = ap;
  local_7c = (char *)strlen((char *)fp);
  local_5c = &DAT_0008a707;
  local_4c = (_IO_FILE *)0x0;
  local_38 = (_IO_lock_t *)0x0;
  local_72 = 0xffff;
  local_6c = local_7c;
  iVar1 = __svfscanf_r(_REENT,(FILE *)&local_80,fmt,(va_list)avStack_8);
  return iVar1;
}


