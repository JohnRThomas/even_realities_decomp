/*
 * Function: bt_rand
 * Entry:    00058f60
 * Prototype: int __stdcall bt_rand(void * buf, size_t len)
 */


/* exclude_from_export_ai */

int bt_rand(void *buf,size_t len)

{
  int iVar1;
  
  if ((buf == (void *)0x0) || (len == 0)) {
    iVar1 = -0x16;
  }
  else {
    iVar1 = tc_hmac_prng_generate(buf,len,&DAT_200061e0);
    if (iVar1 == -1) {
      iVar1 = prng_reseed((tc_hmac_prng_struct *)0xffffffff);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = tc_hmac_prng_generate(buf,len,&DAT_200061e0);
    }
    if (iVar1 == 1) {
      iVar1 = 0;
    }
    else {
      iVar1 = -5;
    }
  }
  return iVar1;
}


