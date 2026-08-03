/*
 * Function: tc_hmac_prng_init
 * Entry:    00083e0a
 * Prototype: int __stdcall tc_hmac_prng_init(TCHmacPrng_t prng, uint8_t * personalization, uint plen)
 */


/* exclude_from_export */

int tc_hmac_prng_init(TCHmacPrng_t prng,uint8_t *personalization,uint plen)

{
  int iVar1;
  
  iVar1 = 0;
  if (prng != (TCHmacPrng_t)0x0) {
    if (personalization == (uint8_t *)0x0) {
      iVar1 = 0;
    }
    else {
      memset(prng + 0xf0,0,0x20);
      memset(prng + 0x110,1,0x20);
      fp_crypto_hmac_sha256(prng,personalization,plen,(uint8_t *)0x0,0);
      iVar1 = 1;
      *(undefined4 *)(prng + 0x130) = 0;
    }
  }
  return iVar1;
}


