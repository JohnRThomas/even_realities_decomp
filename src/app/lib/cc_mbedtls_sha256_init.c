/*
 * Function: cc_mbedtls_sha256_init
 * Entry:    0007de68
 * Prototype: undefined __stdcall cc_mbedtls_sha256_init(void * param_1)
 */


/* exclude_from_export */

void cc_mbedtls_sha256_init(void *param_1)

{
  if (param_1 != (void *)0x0) {
    CC_HalWriteRegister(param_1,0xf4);
    return;
  }
  CC_PalAbort("\nctx is NULL\n");
  CC_HalWriteRegister((void *)0x0,0xf4);
  return;
}


