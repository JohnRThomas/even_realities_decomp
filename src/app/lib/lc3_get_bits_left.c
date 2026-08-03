/*
 * Function: lc3_get_bits_left
 * Entry:    0006b838
 * Prototype: int __stdcall lc3_get_bits_left(lc3_bits_t * bits)
 */


/* exclude_from_export */

int lc3_get_bits_left(lc3_bits_t *bits)

{
  lc3_bits_t lVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  lc3_bits_t lVar5;
  int iVar6;
  
  lVar1 = bits[0xc];
  uVar3 = bits[0xd];
  if ((char)*bits == '\0') {
    iVar6 = 3;
    uVar3 = uVar3 + 4;
    uVar2 = lVar1 - 3;
  }
  else {
    iVar6 = 0;
    uVar2 = lVar1;
  }
  if (uVar2 < uVar3) {
    iVar6 = iVar6 + uVar3;
  }
  else {
    lVar1 = uVar3 - uVar2;
  }
  uVar4 = bits[2];
  if (uVar2 < uVar3) {
    lVar1 = iVar6 - lVar1;
  }
  if (uVar4 == 0) {
    iVar6 = 0x1a;
  }
  else {
    iVar6 = 0;
    do {
      uVar4 = uVar4 >> 1;
      iVar6 = iVar6 + 1;
    } while (uVar4 != 0);
    iVar6 = 0x1a - iVar6;
  }
  lVar5 = bits[5];
  if (-1 < (int)bits[3]) {
    lVar5 = lVar5 + 1;
  }
  uVar3 = lVar1 * 8 - (iVar6 + lVar5 * 8 + bits[8] + bits[9]);
  return uVar3 & ~((int)uVar3 >> 0x1f);
}


