/*
 * Function: buffer_write
 * Entry:    0008263e
 * Prototype: void __stdcall buffer_write(log_output_func_t outf, uint8_t * buf, size_t len, void * ctx)
 */


/* exclude_from_export */

void buffer_write(log_output_func_t outf,uint8_t *buf,size_t len,void *ctx)

{
  int iVar1;
  
  do {
    iVar1 = (*(code *)outf)(buf,len,ctx);
    len = len - iVar1;
    buf = buf + iVar1;
  } while (len != 0);
  return;
}


