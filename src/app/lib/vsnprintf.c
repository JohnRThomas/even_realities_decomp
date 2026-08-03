/*
 * Function: vsnprintf
 * Entry:    0007aed8
 * Prototype: int __stdcall vsnprintf(char * __s, size_t __maxlen, char * __format, __gnuc_va_list __arg)
 */


/* exclude_from_export' */

int vsnprintf(char *__s,size_t __maxlen,char *__format,__gnuc_va_list __arg)

{
  int iVar1;
  
  iVar1 = _vsnprintf_r(_REENT,__s,__maxlen,__format,(va_list)__arg);
  return iVar1;
}


