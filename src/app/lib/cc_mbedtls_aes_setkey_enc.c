/*
 * Function: cc_mbedtls_aes_setkey_enc
 * Entry:    0007ddd4
 * Prototype: undefined4 __stdcall cc_mbedtls_aes_setkey_enc(int param_1, void * param_2, uint param_3)
 */


/* exclude_from_export */

undefined4 cc_mbedtls_aes_setkey_enc(int param_1,void *param_2,uint param_3)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    return 0xffffffde;
  }
  if (param_2 != (void *)0x0) {
    uVar1 = 0;
    *(undefined4 *)(param_1 + 0x38) = 0;
    *(undefined1 *)(param_1 + 0x3c) = 0;
    if (param_3 == 0xc0) {
      uVar1 = 1;
    }
    else if (param_3 == 0x100) {
      uVar1 = 2;
    }
    else if (param_3 != 0x80) {
      return 0xffffffe0;
    }
    *(undefined4 *)(param_1 + 0x30) = uVar1;
    memmove((void *)(param_1 + 0x10),param_2,param_3 >> 3);
    return 0;
  }
  return 0xffffffe0;
}


