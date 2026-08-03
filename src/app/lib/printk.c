/*
 * Function: printk
 * Entry:    0008153c
 * Prototype: void __stdcall printk(char * fmt, ...)
 */


/* exclude_from_export */

void printk(char *fmt,...)

{
  undefined4 in_r1;
  undefined4 in_r2;
  undefined4 in_r3;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_c = in_r1;
  uStack_8 = in_r2;
  uStack_4 = in_r3;
  vprintk(fmt,(va_list)&uStack_c);
  return;
}


