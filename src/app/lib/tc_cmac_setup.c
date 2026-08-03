/*
 * Function: tc_cmac_setup
 * Entry:    00083922
 * Prototype: int __stdcall tc_cmac_setup(TCCmacState_t s, uint8_t * key, TCAesKeySched_t sched)
 */


/* exclude_from_export_ai */

int tc_cmac_setup(TCCmacState_t s,uint8_t *key,TCAesKeySched_t sched)

{
  int iVar1;
  
  iVar1 = 0;
  if (s != (TCCmacState_t)0x0) {
    if (key == (uint8_t *)0x0) {
      iVar1 = 0;
    }
    else {
      memset(s,0,0x58);
      *(TCAesKeySched_t *)(s + 0x48) = sched;
      tc_aes128_set_encrypt_key(sched,key);
      memset(s,0,0x10);
      tc_aes_encrypt(s,s,*(TCAesKeySched_t *)(s + 0x48));
      gf_double(s + 0x10,s);
      gf_double(s + 0x20,s + 0x10);
      tc_cmac_init(s);
      iVar1 = 1;
    }
  }
  return iVar1;
}


