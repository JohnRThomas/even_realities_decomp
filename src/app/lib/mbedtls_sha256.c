/*
 * Function: mbedtls_sha256
 * Entry:    0007e1d0
 * Prototype: int __stdcall mbedtls_sha256(uchar * input, size_t ilen, uchar * output, int is224)
 */


/* exclude_from_export_ai */

int mbedtls_sha256(uchar *input,size_t ilen,uchar *output,int is224)

{
  int extraout_r0;
  int iVar1;
  int extraout_r0_00;
  size_t extraout_r1;
  size_t len;
  size_t extraout_r1_00;
  size_t len_00;
  
  cc_mbedtls_sha256_init(&DAT_2000dfe4);
  mbedtls_sha256_starts((mbedtls_sha256_context *)&DAT_2000dfe4,is224);
  len = extraout_r1;
  iVar1 = extraout_r0;
  if ((extraout_r0 == 0) &&
     (iVar1 = cc_mbedtls_sha256_update(&DAT_2000dfe4,input,ilen), len = extraout_r1_00, iVar1 == 0))
  {
    mbedtls_sha256_finish((mbedtls_sha256_context *)&DAT_2000dfe4,output);
    mbedtls_platform_zeroize(&DAT_2000dfe4,len_00);
    return extraout_r0_00;
  }
  mbedtls_platform_zeroize(&DAT_2000dfe4,len);
  return iVar1;
}


