/*
 * Function: gf_double
 * Entry:    000838bc
 * Prototype: void __stdcall gf_double(uint8_t * out, uint8_t * in)
 */


/* exclude_from_export_ai */

void gf_double(uint8_t *out,uint8_t *in)

{
  byte *pbVar1;
  byte *pbVar2;
  byte bVar3;
  
  pbVar2 = in + 0x10;
  pbVar1 = out + 0xf;
  if ((char)*in < '\0') {
    bVar3 = 0x87;
  }
  else {
    bVar3 = 0;
  }
  while( true ) {
    pbVar2 = pbVar2 + -1;
    *pbVar1 = bVar3 ^ *pbVar2 << 1;
    if (pbVar2 == in) break;
    bVar3 = *pbVar2 >> 7;
    pbVar1 = pbVar1 + -1;
  }
  return;
}


