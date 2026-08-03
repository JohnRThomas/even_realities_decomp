/*
 * Function: tc_hmac_prng_generate
 * Entry:    00083e7c
 * Prototype: int __stdcall tc_hmac_prng_generate(uint8_t * out, uint outlen, TCHmacPrng_t prng)
 */


/* exclude_from_export_ai */

int tc_hmac_prng_generate(uint8_t *out,uint outlen,TCHmacPrng_t prng)

{
  int iVar1;
  uint to_len;
  uint8_t *tag;
  
  if (((out == (uint8_t *)0x0) || (prng == (TCHmacPrng_t)0x0)) || (0x7ffff < outlen - 1)) {
    iVar1 = 0;
  }
  else if (*(int *)(prng + 0x130) == 0) {
    iVar1 = -1;
  }
  else {
    *(int *)(prng + 0x130) = *(int *)(prng + 0x130) + -1;
    tag = prng + 0x110;
    do {
      tc_hmac_set_key(prng,prng + 0xf0,0x20);
      tc_hmac_init(prng);
      tc_hmac_update(prng,tag,0x20);
      tc_hmac_final(tag,0x20,prng);
      to_len = outlen;
      if (0x1f < outlen) {
        to_len = 0x20;
      }
      _copy(out,to_len,tag,to_len);
      if (outlen < 0x20) {
        outlen = 0x20;
      }
      outlen = outlen - 0x20;
      out = out + to_len;
    } while (outlen != 0);
    fp_crypto_hmac_sha256(prng,(uint8_t *)0x0,0,(uint8_t *)0x0,0);
    iVar1 = 1;
  }
  return iVar1;
}


