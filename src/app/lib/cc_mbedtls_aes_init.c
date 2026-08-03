/*
 * Function: cc_mbedtls_aes_init
 * Entry:    0007dda8
 * Prototype: undefined __stdcall cc_mbedtls_aes_init(int param_1)
 */


/* exclude_from_export */

void cc_mbedtls_aes_init(int param_1)

{
  if (param_1 == 0) {
    CC_PalAbort("ctx cannot be NULL");
  }
  *(undefined4 *)(param_1 + 0x54) = 0;
  *(undefined4 *)(param_1 + 0x58) = 0;
  *(undefined4 *)(param_1 + 0x5c) = 1;
  *(undefined4 *)(param_1 + 0x60) = 1;
  return;
}


