/*
 * Function: cc_mbedtls_aes_crypt_ecb
 * Entry:    0007de18
 * Prototype: undefined4 __stdcall cc_mbedtls_aes_crypt_ecb(AesContext_t * param_1, uint param_2, uint8_t * param_3, uint8_t * param_4)
 */


/* exclude_from_export */

undefined4
cc_mbedtls_aes_crypt_ecb(AesContext_t *param_1,uint param_2,uint8_t *param_3,uint8_t *param_4)

{
  drvError_t dVar1;
  CCBuffInfo_t apuStack_20 [2];
  CCBuffInfo_t apuStack_18 [2];
  
  if ((((param_1 != (AesContext_t *)0x0) && (param_3 != (uint8_t *)0x0)) &&
      (param_4 != (uint8_t *)0x0)) && (param_2 < 2)) {
    if (param_2 == 1) {
      if (param_1[0xe] != 0) {
        return 0xffffffde;
      }
    }
    else if (param_1[0xe] != 1) {
      return 0xffffffde;
    }
    param_1[0xd] = 0;
    dVar1 = SetDataBuffersInfo(param_3,0x10,apuStack_20,param_4,0x10,apuStack_18);
    if ((dVar1 == 0) && (dVar1 = ProcessAesDrv(param_1,apuStack_20,apuStack_18,0x10), dVar1 == 0)) {
      return 0;
    }
  }
  return 0xffffffde;
}


