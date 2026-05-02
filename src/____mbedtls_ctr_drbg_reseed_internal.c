/*
 * Function: $_?_mbedtls_ctr_drbg_reseed_internal
 * Entry:    0007cf98
 * Prototype: int __stdcall $_?_mbedtls_ctr_drbg_reseed_internal(mbedtls_ctr_drbg_context * ctx, uchar * additional, size_t len, size_t nonce_len)
 */


int ____mbedtls_ctr_drbg_reseed_internal
              (mbedtls_ctr_drbg_context *ctx,uchar *additional,size_t len,size_t nonce_len)

{
  int iVar1;
  int iVar2;
  char cVar3;
  mbedtls_ctr_drbg_context *pmVar4;
  uint n;
  uint in_stack_00000000;
  uint8_t auStack_68 [16];
  uint auStack_58 [13];
  
  if (0x400 < len) {
    return -0x36;
  }
  if (0x100 < in_stack_00000000) {
    return -0x38;
  }
  memset(auStack_58,0,0x30);
  pmVar4 = ctx + 0x27;
  iVar1 = (*DAT_20002f78)(pmVar4);
  if (iVar1 != 0) {
    return iVar1;
  }
  if ((ctx[7] < ctx[4]) || (ctx[5] != 0)) {
    iVar1 = block_cipher_df((uint8_t *)ctx,(void *)nonce_len,in_stack_00000000,0);
    if ((iVar1 != 0) && (iVar1 = (*DAT_20002f74)(pmVar4), iVar1 != 0)) {
      return iVar1;
    }
  }
  else if ((in_stack_00000000 != 0) &&
          ((iVar1 = block_cipher_df((uchar *)auStack_58,(uchar *)nonce_len,in_stack_00000000),
           iVar1 != 0 || (iVar1 = mbedtls_ctr_drbg_update((uint8_t *)ctx,auStack_58), iVar1 != 0))))
  goto LAB_0007d0da;
  if (len != 0) {
    do {
      cVar3 = *(char *)((int)ctx + 0xf) + '\x01';
      *(char *)((int)ctx + 0xf) = cVar3;
      if (((((cVar3 == '\0') &&
            (cVar3 = *(char *)((int)ctx + 0xe) + '\x01', *(char *)((int)ctx + 0xe) = cVar3,
            cVar3 == '\0')) &&
           (cVar3 = *(char *)((int)ctx + 0xd) + '\x01', *(char *)((int)ctx + 0xd) = cVar3,
           cVar3 == '\0')) &&
          ((((cVar3 = (char)ctx[3] + '\x01', *(char *)(ctx + 3) = cVar3, cVar3 == '\0' &&
             (cVar3 = *(char *)((int)ctx + 0xb) + '\x01', *(char *)((int)ctx + 0xb) = cVar3,
             cVar3 == '\0')) &&
            ((cVar3 = *(char *)((int)ctx + 10) + '\x01', *(char *)((int)ctx + 10) = cVar3,
             cVar3 == '\0' &&
             ((cVar3 = *(char *)((int)ctx + 9) + '\x01', *(char *)((int)ctx + 9) = cVar3,
              cVar3 == '\0' &&
              (cVar3 = (char)ctx[2] + '\x01', *(char *)(ctx + 2) = cVar3, cVar3 == '\0')))))) &&
           (cVar3 = *(char *)((int)ctx + 7) + '\x01', *(char *)((int)ctx + 7) = cVar3, cVar3 == '\0'
           )))) && (((((cVar3 = *(char *)((int)ctx + 6) + '\x01', *(char *)((int)ctx + 6) = cVar3,
                       cVar3 == '\0' &&
                       (cVar3 = *(char *)((int)ctx + 5) + '\x01', *(char *)((int)ctx + 5) = cVar3,
                       cVar3 == '\0')) &&
                      (cVar3 = (char)ctx[1] + '\x01', *(char *)(ctx + 1) = cVar3, cVar3 == '\0')) &&
                     ((cVar3 = *(char *)((int)ctx + 3) + '\x01', *(char *)((int)ctx + 3) = cVar3,
                      cVar3 == '\0' &&
                      (cVar3 = *(char *)((int)ctx + 2) + '\x01', *(char *)((int)ctx + 2) = cVar3,
                      cVar3 == '\0')))) &&
                    (cVar3 = *(char *)((int)ctx + 1) + '\x01', *(char *)((int)ctx + 1) = cVar3,
                    cVar3 == '\0')))) {
        *(char *)ctx = (char)*ctx + '\x01';
      }
      iVar1 = cc_mbedtls_aes_crypt_ecb((AesContext_t *)(ctx + 8),1,(uint8_t *)ctx,auStack_68);
      if (iVar1 != 0) goto LAB_0007d0da;
      n = len;
      if (0xf < len) {
        n = 0x10;
      }
      memcpy(additional,auStack_68,n);
      len = len - n;
      additional = additional + n;
    } while (len != 0);
  }
  iVar1 = mbedtls_ctr_drbg_update((uint8_t *)ctx,auStack_58);
  if (iVar1 == 0) {
    ctx[4] = ctx[4] + 1;
  }
LAB_0007d0da:
  iVar2 = (*DAT_20002f74)(pmVar4);
  if (iVar2 != 0) {
    iVar1 = iVar2;
  }
  mbedtls_platform_zeroize(auStack_58,0x30);
  mbedtls_platform_zeroize(auStack_68,0x10);
  return iVar1;
}


