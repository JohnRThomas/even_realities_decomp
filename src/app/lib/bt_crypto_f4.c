/*
 * Function: bt_crypto_f4
 * Entry:    00086da2
 * Prototype: int __stdcall bt_crypto_f4(uint8_t * u, uint8_t * v, uint8_t * x, uint8_t z, uint8_t * res)
 */


/* exclude_from_export_ai */

int bt_crypto_f4(uint8_t *u,uint8_t *v,uint8_t *x,uint8_t z,uint8_t *res)

{
  int iVar1;
  size_t length;
  uint8_t auStack_6c [16];
  uint8_t auStack_5c [32];
  undefined1 auStack_3c [32];
  uint8_t local_1c;
  
  sys_memcpy_swap(auStack_5c,u,0x20);
  sys_memcpy_swap(auStack_3c,v,0x20);
  local_1c = z;
  sys_memcpy_swap(auStack_6c,x,0x10);
  iVar1 = bt_crypto_aes_cmac(auStack_6c,auStack_5c,0x41,res);
  if (iVar1 == 0) {
    sys_mem_swap(res,length);
  }
  return iVar1;
}


