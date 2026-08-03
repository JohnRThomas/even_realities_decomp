/*
 * Function: vsprintf
 * Entry:    0007af20
 * Prototype: int __stdcall vsprintf(char * param_1, char * param_2, va_list param_3)
 */


/* exclude_from_export_ai */

int vsprintf(char *param_1,char *param_2,va_list param_3)

{
  int iVar1;
  char *local_70;
  char *local_68;
  char *local_64;
  char *local_60;
  char *local_5c;
  
  local_5c = &DAT_7fffffff;
  local_68 = &DAT_7fffffff;
  local_64 = (char *)0xffff0208;
  local_70 = param_1;
  local_60 = param_1;
  iVar1 = fprintf(_REENT,(FILE *)&local_70,param_2,param_3);
  *local_70 = '\0';
  return iVar1;
}


