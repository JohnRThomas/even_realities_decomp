/*
 * Function: cc_mbedtls_sha256_update
 * Entry:    0007dec4
 * Prototype: undefined4 __stdcall cc_mbedtls_sha256_update(void * param_1, uchar * param_2, size_t param_3)
 */


/* exclude_from_export */

undefined4 cc_mbedtls_sha256_update(void *param_1,uchar *param_2,size_t param_3)

{
  int iVar1;
  uchar auStack_90 [132];
  
  if ((&DAT_00100000 < param_2 + param_3) || (0x80 < param_3)) {
    if (param_2 <= &DAT_00100000) {
      return 0xffffffc9;
    }
    iVar1 = mbedtls_sha_update_internal(param_1,param_2,param_3);
  }
  else {
    memmove(auStack_90,param_2,param_3);
    iVar1 = mbedtls_sha_update_internal(param_1,auStack_90,param_3);
    CC_HalWriteRegister(auStack_90,0x80);
  }
  if (iVar1 != 0) {
    return 0xffffffc9;
  }
  return 0;
}


