/*
 * Function: cbvprintf
 * Entry:    00082658
 * Prototype: int __stdcall cbvprintf(cbprintf_cb out, void * ctx, char * format, va_list ap)
 */


/* exclude_from_export */

int cbvprintf(cbprintf_cb out,void *ctx,char *format,va_list ap)

{
  int iVar1;
  
  iVar1 = z_cbvprintf_impl(out,ctx,format,ap,0);
  return iVar1;
}


