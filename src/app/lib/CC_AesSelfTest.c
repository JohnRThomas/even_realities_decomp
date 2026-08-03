/*
 * Function: CC_AesSelfTest
 * Entry:    0007cef8
 * Prototype: int __stdcall CC_AesSelfTest(uint8_t * param_1, undefined4 param_2, undefined4 param_3, void * param_4, uint param_5)
 */


/* exclude_from_export_ai */

int CC_AesSelfTest(uint8_t *param_1,undefined4 param_2,undefined4 param_3,void *param_4,uint param_5
                  )

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined1 auStack_40 [32];
  
  memset(auStack_40,0,0x20);
  iVar1 = (*DAT_20002f78)(param_1 + 0x9c);
  if (iVar1 != 0) {
    return iVar1;
  }
  cc_mbedtls_aes_init((int)(param_1 + 0x20));
  uVar3 = *(uint *)(param_1 + 0x18);
  *(undefined4 *)(param_1 + 0x94) = param_2;
  *(undefined4 *)(param_1 + 0x98) = param_3;
  if (uVar3 == 0) {
    uVar4 = *(uint *)(param_1 + 0x10);
    param_1[0x18] = ' ';
    param_1[0x19] = '\0';
    param_1[0x1a] = '\0';
    param_1[0x1b] = '\0';
    if ((int)uVar4 < 0) {
      uVar4 = 0x10;
    }
  }
  else {
    uVar4 = *(uint *)(param_1 + 0x10);
    if ((int)uVar4 < 0) {
      if (uVar3 < 0x30) {
        uVar4 = uVar3 + 1 >> 1;
      }
      else {
        uVar4 = 0;
      }
    }
  }
  iVar1 = cc_mbedtls_aes_setkey_enc((int)(param_1 + 0x20),auStack_40,0x100);
  if (iVar1 == 0) {
    iVar1 = block_cipher_df(param_1,param_4,param_5,uVar4);
  }
  iVar2 = (*DAT_20002f74)(param_1 + 0x9c);
  if (iVar2 != 0) {
    iVar1 = iVar2;
  }
  return iVar1;
}


