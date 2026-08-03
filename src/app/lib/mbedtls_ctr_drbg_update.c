/*
 * Function: mbedtls_ctr_drbg_update
 * Entry:    0007cc94
 * Prototype: int __stdcall mbedtls_ctr_drbg_update(uint8_t * param_1, uint * param_2)
 */


/* exclude_from_export_ai */

int mbedtls_ctr_drbg_update(uint8_t *param_1,uint *param_2)

{
  uint8_t uVar1;
  int iVar2;
  uint *puVar3;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  uint local_20;
  uint local_1c;
  
  puVar3 = &local_48;
  memset(&local_48,0,0x30);
  do {
    uVar1 = param_1[0xf];
    param_1[0xf] = uVar1 + '\x01';
    if ((((((uint8_t)(uVar1 + '\x01') == '\0') &&
          (uVar1 = param_1[0xe], param_1[0xe] = uVar1 + '\x01', (uint8_t)(uVar1 + '\x01') == '\0'))
         && (uVar1 = param_1[0xd], param_1[0xd] = uVar1 + '\x01', (uint8_t)(uVar1 + '\x01') == '\0')
         ) && (((uVar1 = param_1[0xc], param_1[0xc] = uVar1 + '\x01',
                (uint8_t)(uVar1 + '\x01') == '\0' &&
                (uVar1 = param_1[0xb], param_1[0xb] = uVar1 + '\x01',
                (uint8_t)(uVar1 + '\x01') == '\0')) &&
               ((uVar1 = param_1[10], param_1[10] = uVar1 + '\x01',
                (uint8_t)(uVar1 + '\x01') == '\0' &&
                ((uVar1 = param_1[9], param_1[9] = uVar1 + '\x01', (uint8_t)(uVar1 + '\x01') == '\0'
                 && (uVar1 = param_1[8], param_1[8] = uVar1 + '\x01',
                    (uint8_t)(uVar1 + '\x01') == '\0')))))))) &&
       ((uVar1 = param_1[7], param_1[7] = uVar1 + '\x01', (uint8_t)(uVar1 + '\x01') == '\0' &&
        (((((uVar1 = param_1[6], param_1[6] = uVar1 + '\x01', (uint8_t)(uVar1 + '\x01') == '\0' &&
            (uVar1 = param_1[5], param_1[5] = uVar1 + '\x01', (uint8_t)(uVar1 + '\x01') == '\0')) &&
           (uVar1 = param_1[4], param_1[4] = uVar1 + '\x01', (uint8_t)(uVar1 + '\x01') == '\0')) &&
          ((uVar1 = param_1[3], param_1[3] = uVar1 + '\x01', (uint8_t)(uVar1 + '\x01') == '\0' &&
           (uVar1 = param_1[2], param_1[2] = uVar1 + '\x01', (uint8_t)(uVar1 + '\x01') == '\0'))))
         && (uVar1 = param_1[1], param_1[1] = uVar1 + '\x01', (uint8_t)(uVar1 + '\x01') == '\0')))))
       ) {
      *param_1 = *param_1 + '\x01';
    }
    iVar2 = cc_mbedtls_aes_crypt_ecb((AesContext_t *)(param_1 + 0x20),1,param_1,(uint8_t *)puVar3);
    if (iVar2 != 0) goto LAB_0007cdec;
    puVar3 = (uint *)((int)puVar3 + 0x10);
  } while (puVar3 != (uint *)&stack0xffffffe8);
  local_40 = param_2[2] ^ local_40;
  local_3c = param_2[3] ^ local_3c;
  local_38 = param_2[4] ^ local_38;
  local_34 = param_2[5] ^ local_34;
  local_30 = param_2[6] ^ local_30;
  local_2c = param_2[7] ^ local_2c;
  local_28 = param_2[8] ^ local_28;
  local_24 = param_2[9] ^ local_24;
  local_20 = param_2[10] ^ local_20;
  local_1c = param_2[0xb] ^ local_1c;
  local_48 = local_48 ^ *param_2;
  local_44 = param_2[1] ^ local_44;
  iVar2 = cc_mbedtls_aes_setkey_enc((int)(param_1 + 0x20),&local_48,0x100);
  if (iVar2 == 0) {
    memcpy(param_1,&local_28,0x10);
  }
LAB_0007cdec:
  mbedtls_platform_zeroize(&local_48,0x30);
  return iVar2;
}


