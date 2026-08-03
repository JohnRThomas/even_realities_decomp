/*
 * Function: vprintk
 * Entry:    0004e46c
 * Prototype: void __stdcall vprintk(char * fmt, va_list ap)
 */


/* exclude_from_export */

void vprintk(char *fmt,va_list ap)

{
  z_cbvprintf_impl((cbprintf_cb)0x4e455,(void *)0x0,fmt,ap,0);
  return;
}


