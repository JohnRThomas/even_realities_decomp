/*
 * Function: bt_crypto_aes_cmac
 * Entry:    00086d66
 * Prototype: int __stdcall bt_crypto_aes_cmac(uint8_t * key, uint8_t * in, size_t len, uint8_t * out)
 */


/* exclude_from_export_ai */

int bt_crypto_aes_cmac(uint8_t *key,uint8_t *in,size_t len,uint8_t *out)

{
  int iVar1;
  undefined auStack_118 [88];
  undefined auStack_c0 [176];
  
  iVar1 = tc_cmac_setup(auStack_118,key,auStack_c0);
  if (((iVar1 == 0) || (iVar1 = tc_cmac_update(auStack_118,in,len), iVar1 == 0)) ||
     (iVar1 = tc_cmac_final(out,auStack_118), iVar1 == 0)) {
    iVar1 = -5;
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}


