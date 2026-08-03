/*
 * Function: tc_sha256_init
 * Entry:    00052f4c
 * Prototype: int __stdcall tc_sha256_init(TCSha256State_t s)
 */


/* exclude_from_export_ai */

int tc_sha256_init(TCSha256State_t s)

{
  if (s != (TCSha256State_t)0x0) {
    memset(s,0,0x70);
    *(undefined4 *)s = 0x6a09e667;
    *(undefined4 *)(s + 4) = 0xbb67ae85;
    *(undefined **)(s + 8) = &DAT_3c6ef372;
    *(undefined4 *)(s + 0xc) = 0xa54ff53a;
    *(undefined4 *)(s + 0x10) = 0x510e527f;
    *(undefined4 *)(s + 0x14) = 0x9b05688c;
    *(undefined4 *)(s + 0x18) = 0x1f83d9ab;
    *(undefined4 *)(s + 0x1c) = 0x5be0cd19;
  }
  return (uint)(s != (TCSha256State_t)0x0);
}


