/*
 * Function: lc3_put_bits_generic
 * Entry:    0006bbb0
 * Prototype: void __stdcall lc3_put_bits_generic(lc3_bits_t * bits, uint v, int n)
 */


/* exclude_from_export_ai */

void lc3_put_bits_generic(lc3_bits_t *bits,uint v,int n)

{
  uint uVar1;
  lc3_bits_t lVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar1 = bits[8];
  uVar3 = 0x20 - uVar1;
  if (n <= (int)(0x20 - uVar1)) {
    uVar3 = n;
  }
  if (uVar3 == 0) {
    uVar5 = (int)uVar1 >> 3;
  }
  else {
    uVar4 = uVar1 & 0xff;
    uVar5 = 4;
    uVar1 = 0x20;
    bits[7] = bits[7] | v << uVar4;
  }
  lVar2 = bits[0xd];
  uVar4 = lVar2 - bits[0xc] & ~((int)(lVar2 - bits[0xc]) >> 0x1f);
  if ((int)uVar5 <= (int)uVar4) {
    uVar4 = uVar5;
  }
  bits[8] = uVar1 + uVar4 * -8;
  if (uVar4 != 0) {
    bits[0xd] = lVar2 - 1;
    *(char *)(lVar2 - 1) = (char)bits[7];
    while( true ) {
      uVar1 = bits[7];
      uVar4 = uVar4 - 1;
      bits[7] = uVar1 >> 8;
      if (uVar4 == 0) break;
      lVar2 = bits[0xd];
      bits[0xd] = lVar2 - 1;
      *(char *)(lVar2 - 1) = (char)(uVar1 >> 8);
    }
  }
  bits[7] = v >> (uVar3 & 0xff);
  bits[8] = n - uVar3;
  return;
}


