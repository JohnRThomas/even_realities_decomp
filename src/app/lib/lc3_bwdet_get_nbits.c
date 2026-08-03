/*
 * Function: lc3_bwdet_get_nbits
 * Entry:    0006bdbc
 * Prototype: int __stdcall lc3_bwdet_get_nbits(lc3_srate sr)
 */


/* exclude_from_export_ai */

int lc3_bwdet_get_nbits(lc3_srate sr)

{
  uint uVar1;
  
  uVar1 = (uint)(LC3_SRATE_16K < sr);
  if (sr != LC3_SRATE_8K) {
    uVar1 = uVar1 + 1;
  }
  if (LC3_SRATE_32K < sr) {
    uVar1 = uVar1 + 1;
  }
  return uVar1;
}


