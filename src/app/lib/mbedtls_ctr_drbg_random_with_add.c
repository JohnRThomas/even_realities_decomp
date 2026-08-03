/*
 * Function: mbedtls_ctr_drbg_random_with_add
 * Entry:    0007cf98
 * Prototype: int __stdcall mbedtls_ctr_drbg_random_with_add(void * p_rng, uchar * output, size_t output_len, uchar * additional, size_t add_len)
 */


/* exclude_from_export */

int mbedtls_ctr_drbg_random_with_add
              (void *p_rng,uchar *output,size_t output_len,uchar *additional,size_t add_len)

{
  int iVar1;
  char cVar2;
  int iVar3;
  uint n;
  uint8_t auStack_68 [16];
  uint auStack_58 [13];
  
  if (0x400 < output_len) {
    return -0x36;
  }
  if (0x100 < add_len) {
    return -0x38;
  }
  memset(auStack_58,0,0x30);
  iVar3 = (int)p_rng + 0x9c;
  iVar1 = (*DAT_20002f78)(iVar3);
  if (iVar1 != 0) {
    return iVar1;
  }
  if ((*(int *)((int)p_rng + 0x1c) < *(int *)((int)p_rng + 0x10)) ||
     (*(int *)((int)p_rng + 0x14) != 0)) {
    iVar1 = block_cipher_df(p_rng,additional,add_len,0);
    if ((iVar1 != 0) && (iVar1 = (*DAT_20002f74)(iVar3), iVar1 != 0)) {
      return iVar1;
    }
  }
  else if ((add_len != 0) &&
          ((iVar1 = block_cipher_df((uchar *)auStack_58,additional,add_len), iVar1 != 0 ||
           (iVar1 = mbedtls_ctr_drbg_update(p_rng,auStack_58), iVar1 != 0)))) goto LAB_0007d0da;
  if (output_len != 0) {
    do {
      cVar2 = *(char *)((int)p_rng + 0xf) + '\x01';
      *(char *)((int)p_rng + 0xf) = cVar2;
      if (((((cVar2 == '\0') &&
            (cVar2 = *(char *)((int)p_rng + 0xe) + '\x01', *(char *)((int)p_rng + 0xe) = cVar2,
            cVar2 == '\0')) &&
           (cVar2 = *(char *)((int)p_rng + 0xd) + '\x01', *(char *)((int)p_rng + 0xd) = cVar2,
           cVar2 == '\0')) &&
          ((((cVar2 = *(char *)((int)p_rng + 0xc) + '\x01', *(char *)((int)p_rng + 0xc) = cVar2,
             cVar2 == '\0' &&
             (cVar2 = *(char *)((int)p_rng + 0xb) + '\x01', *(char *)((int)p_rng + 0xb) = cVar2,
             cVar2 == '\0')) &&
            ((cVar2 = *(char *)((int)p_rng + 10) + '\x01', *(char *)((int)p_rng + 10) = cVar2,
             cVar2 == '\0' &&
             ((cVar2 = *(char *)((int)p_rng + 9) + '\x01', *(char *)((int)p_rng + 9) = cVar2,
              cVar2 == '\0' &&
              (cVar2 = *(char *)((int)p_rng + 8) + '\x01', *(char *)((int)p_rng + 8) = cVar2,
              cVar2 == '\0')))))) &&
           (cVar2 = *(char *)((int)p_rng + 7) + '\x01', *(char *)((int)p_rng + 7) = cVar2,
           cVar2 == '\0')))) &&
         (((((cVar2 = *(char *)((int)p_rng + 6) + '\x01', *(char *)((int)p_rng + 6) = cVar2,
             cVar2 == '\0' &&
             (cVar2 = *(char *)((int)p_rng + 5) + '\x01', *(char *)((int)p_rng + 5) = cVar2,
             cVar2 == '\0')) &&
            (cVar2 = *(char *)((int)p_rng + 4) + '\x01', *(char *)((int)p_rng + 4) = cVar2,
            cVar2 == '\0')) &&
           ((cVar2 = *(char *)((int)p_rng + 3) + '\x01', *(char *)((int)p_rng + 3) = cVar2,
            cVar2 == '\0' &&
            (cVar2 = *(char *)((int)p_rng + 2) + '\x01', *(char *)((int)p_rng + 2) = cVar2,
            cVar2 == '\0')))) &&
          (cVar2 = *(char *)((int)p_rng + 1) + '\x01', *(char *)((int)p_rng + 1) = cVar2,
          cVar2 == '\0')))) {
        *(char *)p_rng = *(char *)p_rng + '\x01';
      }
      iVar1 = cc_mbedtls_aes_crypt_ecb((AesContext_t *)((int)p_rng + 0x20),1,p_rng,auStack_68);
      if (iVar1 != 0) goto LAB_0007d0da;
      n = output_len;
      if (0xf < output_len) {
        n = 0x10;
      }
      memcpy(output,auStack_68,n);
      output_len = output_len - n;
      output = output + n;
    } while (output_len != 0);
  }
  iVar1 = mbedtls_ctr_drbg_update(p_rng,auStack_58);
  if (iVar1 == 0) {
    *(int *)((int)p_rng + 0x10) = *(int *)((int)p_rng + 0x10) + 1;
  }
LAB_0007d0da:
  iVar3 = (*DAT_20002f74)(iVar3);
  if (iVar3 != 0) {
    iVar1 = iVar3;
  }
  mbedtls_platform_zeroize(auStack_58,0x30);
  mbedtls_platform_zeroize(auStack_68,0x10);
  return iVar1;
}


