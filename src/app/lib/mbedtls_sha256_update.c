/*
 * Function: mbedtls_sha256_update
 * Entry:    0007d17c
 * Prototype: int __stdcall mbedtls_sha256_update(int * param_1, uchar param_2, uchar * param_3, uint param_4)
 */


/* exclude_from_export_ai */

int mbedtls_sha256_update(int *param_1,uchar param_2,uchar *param_3,uint param_4)

{
  int extraout_r0;
  int iVar1;
  mbedtls_sha256_context *ctx;
  uchar *output;
  uchar local_44;
  undefined1 local_43;
  uchar auStack_40 [36];
  
  if (param_4 < 0x21) {
    local_43 = (undefined1)param_4;
    output = param_3;
  }
  else {
    output = auStack_40;
    iVar1 = mbedtls_sha256(param_3,param_4,output,0);
    if (iVar1 != 0) goto LAB_0007d1be;
    local_43 = 0x20;
    param_4 = 0x20;
  }
  ctx = (mbedtls_sha256_context *)(param_1 + 1);
  local_44 = param_2;
  if ((*param_1 != 0) || (mbedtls_sha256_starts(ctx,0), iVar1 = extraout_r0, extraout_r0 == 0)) {
    *param_1 = 1;
    iVar1 = cc_mbedtls_sha256_update(ctx,&local_44,2);
    if (iVar1 == 0) {
      iVar1 = cc_mbedtls_sha256_update(ctx,output,param_4);
    }
  }
LAB_0007d1be:
  mbedtls_platform_zeroize(auStack_40,0x20);
  return iVar1;
}


