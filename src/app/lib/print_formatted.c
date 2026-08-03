/*
 * Function: print_formatted
 * Entry:    00050d0c
 * Prototype: int __stdcall print_formatted(log_output * output, char * fmt, ...)
 */


/* exclude_from_export */

int print_formatted(log_output *output,char *fmt,...)

{
  int iVar1;
  undefined4 in_r2;
  undefined4 in_r3;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_8 = in_r2;
  uStack_4 = in_r3;
  iVar1 = cbvprintf((cbprintf_cb)0x50d4d,output,fmt,(va_list)&uStack_8);
  return iVar1;
}


