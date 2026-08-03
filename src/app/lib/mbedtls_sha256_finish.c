/*
 * Function: mbedtls_sha256_finish
 * Entry:    0007df18
 * Prototype: void __stdcall mbedtls_sha256_finish(mbedtls_sha256_context * ctx, uchar * output)
 */


/* exclude_from_export */

void mbedtls_sha256_finish(mbedtls_sha256_context *ctx,uchar *output)

{
  int iVar1;
  
  if (((ctx != (mbedtls_sha256_context *)0x0) && (output != (uchar *)0x0)) &&
     (iVar1 = mbedtls_sha_finish_internal(ctx), iVar1 == 0)) {
    if (*ctx == 1) {
      memmove(output,ctx + 2,0x20);
      return;
    }
    if (*ctx == 2) {
      memmove(output,ctx + 2,0x1c);
      return;
    }
  }
  return;
}


