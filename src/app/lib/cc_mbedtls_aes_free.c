/*
 * Function: cc_mbedtls_aes_free
 * Entry:    0007ddc8
 * Prototype: undefined __stdcall cc_mbedtls_aes_free(void * param_1)
 */


/* exclude_from_export */

void cc_mbedtls_aes_free(void *param_1)

{
  if (param_1 != (void *)0x0) {
    memset(param_1,0,0x74);
    return;
  }
  return;
}


