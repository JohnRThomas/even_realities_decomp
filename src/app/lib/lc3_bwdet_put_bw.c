/*
 * Function: lc3_bwdet_put_bw
 * Entry:    0006bdd4
 * Prototype: void __stdcall lc3_bwdet_put_bw(lc3_bits_t * bits, lc3_srate sr, lc3_bandwidth bw)
 */


/* exclude_from_export_ai */

void lc3_bwdet_put_bw(lc3_bits_t *bits,lc3_srate sr,lc3_bandwidth bw)

{
  uint n;
  lc3_bits_t lVar1;
  
  n = (uint)(LC3_SRATE_16K < sr);
  if (sr != LC3_SRATE_8K) {
    n = n + 1;
  }
  if (LC3_SRATE_32K < sr) {
    n = n + 1;
  }
  if (n != 0) {
    lVar1 = n + bits[8];
    if (0x20 < (int)lVar1) {
      lc3_put_bits_generic(bits,bw,n);
      return;
    }
    bits[7] = bits[7] | bw << (bits[8] & 0xff);
    bits[8] = lVar1;
    return;
  }
  return;
}


