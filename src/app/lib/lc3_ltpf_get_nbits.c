/*
 * Function: lc3_ltpf_get_nbits
 * Entry:    0006e614
 * Prototype: int __stdcall lc3_ltpf_get_nbits(bool pitch)
 */


/* exclude_from_export_ai */

int lc3_ltpf_get_nbits(bool pitch)

{
  return (uint)pitch * 10 + 1;
}


