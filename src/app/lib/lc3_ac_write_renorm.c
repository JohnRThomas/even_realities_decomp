/*
 * Function: lc3_ac_write_renorm
 * Entry:    0006bc24
 * Prototype: void __stdcall lc3_ac_write_renorm(lc3_bits_t * bits)
 */


/* exclude_from_export */

void lc3_ac_write_renorm(lc3_bits_t *bits)

{
  lc3_bits_t lVar1;
  char *pcVar2;
  uint uVar3;
  
  lVar1 = bits[2];
  if (0xffff < lVar1) {
    return;
  }
  uVar3 = bits[1];
  do {
    if ((uVar3 < 0xff0000) || (bits[4] != 0)) {
      if ((-1 < (int)bits[3]) && (pcVar2 = (char *)bits[0xc], pcVar2 < (char *)bits[0xb])) {
        bits[0xc] = (lc3_bits_t)(pcVar2 + 1);
        *pcVar2 = (char)bits[3] + (char)bits[4];
      }
      lVar1 = bits[5];
      while (0 < (int)lVar1) {
        pcVar2 = (char *)bits[0xc];
        if ((char *)bits[0xb] <= pcVar2) {
          bits[5] = lVar1 - 1;
          if (0 < (int)(lVar1 - 1)) {
            bits[5] = 0;
          }
          break;
        }
        bits[0xc] = (lc3_bits_t)(pcVar2 + 1);
        *pcVar2 = -(bits[4] == 0);
        lVar1 = bits[5] - 1;
        bits[5] = lVar1;
      }
      uVar3 = bits[1];
      lVar1 = bits[2];
      bits[3] = uVar3 >> 0x10;
      bits[4] = 0;
    }
    else {
      bits[5] = bits[5] + 1;
    }
    lVar1 = lVar1 << 8;
    uVar3 = (uVar3 & 0xffff) << 8;
    bits[1] = uVar3;
    bits[2] = lVar1;
    if (0xffff < lVar1) {
      return;
    }
  } while( true );
}


