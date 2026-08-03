/*
 * Function: tc_hmac_prng_reseed
 * Entry:    00083e4a
 * Prototype: int __stdcall tc_hmac_prng_reseed(TCHmacPrng_t prng, uint8_t * seed, uint seedlen, uint8_t * additional_input, uint additionallen)
 */


/* exclude_from_export */

int tc_hmac_prng_reseed(TCHmacPrng_t prng,uint8_t *seed,uint seedlen,uint8_t *additional_input,
                       uint additionallen)

{
  int iVar1;
  
  if (((prng == (TCHmacPrng_t)0x0) || (seed == (uint8_t *)0x0)) || (seedlen < 0x20)) {
    iVar1 = 0;
  }
  else {
    if (additional_input == (uint8_t *)0x0) {
      additionallen = 0;
    }
    else if (additionallen == 0) {
      return 0;
    }
    fp_crypto_hmac_sha256(prng,seed,seedlen,additional_input,additionallen);
    iVar1 = 1;
    *(undefined4 *)(prng + 0x130) = 0xffffffff;
  }
  return iVar1;
}


