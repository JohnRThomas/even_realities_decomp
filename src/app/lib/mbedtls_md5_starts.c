/*
 * Function: mbedtls_md5_starts
 * Entry:    0004cac8
 * Prototype: void __stdcall mbedtls_md5_starts(mbedtls_md5_context * ctx)
 */


/* exclude_from_export_ai */

void mbedtls_md5_starts(mbedtls_md5_context *ctx)

{
  *ctx = 0;
  ctx[1] = 0;
  ctx[2] = 0x67452301;
  ctx[3] = 0xefcdab89;
  ctx[4] = 0x98badcfe;
  ctx[5] = 0x10325476;
  return;
}


