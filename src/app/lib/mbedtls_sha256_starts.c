/*
 * Function: mbedtls_sha256_starts
 * Entry:    0007de9c
 * Prototype: void __stdcall mbedtls_sha256_starts(mbedtls_sha256_context * ctx, int is224)
 */


/* exclude_from_export_ai */

void mbedtls_sha256_starts(mbedtls_sha256_context *ctx,int is224)

{
  bool bVar1;
  
  if (is224 == 0) {
    bVar1 = CC_HashInit(ctx,1);
  }
  else {
    if (is224 != 1) {
      return;
    }
    bVar1 = CC_HashInit(ctx,2);
  }
  if (bVar1) {
    return;
  }
  return;
}


