/*
 * Function: mbedtls_platform_zeroize
 * Entry:    0007de90
 * Prototype: void __stdcall mbedtls_platform_zeroize(void * buf, size_t len)
 */


/* exclude_from_export_ai */

void mbedtls_platform_zeroize(void *buf,size_t len)

{
  if (buf != (void *)0x0) {
    mbedtls_zeroize_internal(buf,0xf4);
    return;
  }
  return;
}


