/*
 * Function: internal_encrypt_le
 * Entry:    00084ade
 * Prototype: int __stdcall internal_encrypt_le(uint8_t * key, uint8_t * plaintext, uint8_t * enc_data)
 */


/* exclude_from_export */

int internal_encrypt_le(uint8_t *key,uint8_t *plaintext,uint8_t *enc_data)

{
  uint8_t uVar1;
  int iVar2;
  size_t length;
  uint8_t *puVar3;
  uint8_t *puVar4;
  uint8_t auStack_d0 [16];
  undefined auStack_c0 [180];
  
  if (((key != (uint8_t *)0x0) && (plaintext != (uint8_t *)0x0)) && (enc_data != (uint8_t *)0x0)) {
    sys_memcpy_swap(auStack_d0,key,(size_t)enc_data);
    iVar2 = tc_aes128_set_encrypt_key(auStack_c0,auStack_d0);
    if (iVar2 != 0) {
      sys_memcpy_swap(auStack_d0,plaintext,length);
      iVar2 = tc_aes_encrypt(enc_data,auStack_d0,auStack_c0);
      if (iVar2 != 0) {
        puVar4 = enc_data + -1;
        puVar3 = enc_data + 0x10;
        do {
          puVar4 = puVar4 + 1;
          uVar1 = *puVar4;
          puVar3 = puVar3 + -1;
          *puVar4 = *puVar3;
          *puVar3 = uVar1;
        } while (puVar4 != enc_data + 7);
        return 0;
      }
    }
  }
  return -0x16;
}


