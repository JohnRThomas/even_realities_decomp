/*
 * Function: snprintk
 * Entry:    00081556
 * Prototype: int __stdcall snprintk(char * str, size_t size, char * fmt, ...)
 */


/* exclude_from_export */

int snprintk(char *str,size_t size,char *fmt,...)

{
  int iVar1;
  undefined4 in_r3;
  undefined4 uStack_4;
  
  uStack_4 = in_r3;
  iVar1 = vsnprintk(str,size,fmt,(va_list)&uStack_4);
  return iVar1;
}


