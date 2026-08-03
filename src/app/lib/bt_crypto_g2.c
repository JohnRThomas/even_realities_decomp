/*
 * Function: bt_crypto_g2
 * Entry:    00062058
 * Prototype: int __stdcall bt_crypto_g2(uint8_t * u, uint8_t * v, uint8_t * x, uint8_t * y, uint32_t * passkey)
 */


/* exclude_from_export_ai */

int bt_crypto_g2(uint8_t *u,uint8_t *v,uint8_t *x,uint8_t *y,uint32_t *passkey)

{
  int iVar1;
  uint8_t auStack_70 [12];
  uint local_64;
  uint8_t auStack_60 [32];
  undefined1 auStack_40 [32];
  undefined1 auStack_20 [16];
  
  sys_memcpy_swap(auStack_60,u,0x20);
  sys_memcpy_swap(auStack_40,v,0x20);
  sys_memcpy_swap(auStack_20,y,0x10);
  sys_memcpy_swap(auStack_70,x,0x10);
  iVar1 = bt_crypto_aes_cmac(auStack_70,auStack_60,0x50,auStack_70);
  if (iVar1 == 0) {
    *passkey = (local_64 << 0x18 | (local_64 >> 8 & 0xff) << 0x10 | (local_64 >> 0x10 & 0xff) << 8 |
               local_64 >> 0x18) % 1000000;
  }
  return iVar1;
}


