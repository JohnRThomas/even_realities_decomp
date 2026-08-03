/*
 * Function: sub_bytes
 * Entry:    00052cc8
 * Prototype: void __stdcall sub_bytes(uint8_t * s)
 */


/* exclude_from_export_ai */

void sub_bytes(uint8_t *s)

{
  byte *pbVar1;
  
  pbVar1 = s + -1;
  do {
    pbVar1 = pbVar1 + 1;
    *pbVar1 = (&DAT_000ef97e)[*pbVar1];
  } while (pbVar1 != s + 0xf);
  return;
}


