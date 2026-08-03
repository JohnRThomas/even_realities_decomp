/*
 * Function: lc3_flush_bits
 * Entry:    0006b89c
 * Prototype: void __stdcall lc3_flush_bits(lc3_bits_t * bits)
 */


/* exclude_from_export_ai */

void lc3_flush_bits(lc3_bits_t *bits)

{
  byte *pbVar1;
  uint uVar2;
  lc3_bits_t lVar3;
  lc3_bits_t lVar4;
  byte *pbVar5;
  int iVar6;
  lc3_bits_t lVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  
  lVar4 = bits[8];
  pbVar1 = (byte *)bits[0xc];
  lVar7 = bits[0xd];
  uVar9 = lVar7 - (int)pbVar1;
  iVar10 = uVar9 * 8 - lVar4;
  if (iVar10 < 1) {
    uVar8 = uVar9 & ~((int)uVar9 >> 0x1f);
  }
  else {
    iVar11 = iVar10;
    iVar12 = iVar10 + -0x20;
    while( true ) {
      if (0x1f < iVar11) {
        iVar11 = 0x20;
      }
      uVar8 = uVar9 & ~((int)uVar9 >> 0x1f);
      lVar3 = iVar11 + lVar4;
      if (0x20 < (int)(iVar11 + lVar4)) {
        iVar6 = 0x20 - lVar4;
        if (iVar11 <= (int)(0x20 - lVar4)) {
          iVar6 = iVar11;
        }
        if (iVar6 == 0) {
          uVar2 = (int)lVar4 >> 3;
        }
        else {
          uVar2 = 4;
        }
        if ((int)uVar8 <= (int)uVar2) {
          uVar2 = uVar8;
        }
        if (uVar2 != 0) {
          bits[0xd] = lVar7 - 1;
          *(char *)(lVar7 - 1) = (char)bits[7];
          while( true ) {
            uVar9 = bits[7];
            uVar2 = uVar2 - 1;
            bits[7] = uVar9 >> 8;
            if (uVar2 == 0) break;
            lVar4 = bits[0xd];
            bits[0xd] = lVar4 - 1;
            *(char *)(lVar4 - 1) = (char)(uVar9 >> 8);
          }
          pbVar1 = (byte *)bits[0xc];
          lVar7 = bits[0xd];
          uVar9 = lVar7 - (int)pbVar1;
          uVar8 = uVar9 & ~((int)uVar9 >> 0x1f);
        }
        bits[7] = 0;
        lVar3 = iVar11 - iVar6;
      }
      lVar4 = lVar3;
      if (iVar12 == (iVar10 + -0x20) - (iVar10 - 1U & 0xffffffe0)) break;
      iVar11 = iVar12;
      iVar12 = iVar12 + -0x20;
    }
  }
  uVar9 = (int)lVar4 >> 3;
  if ((int)uVar8 <= (int)lVar4 >> 3) {
    uVar9 = uVar8;
  }
  lVar4 = lVar4 + uVar9 * -8;
  bits[8] = lVar4;
  if (uVar9 != 0) {
    bits[0xd] = lVar7 - 1;
    *(char *)(lVar7 - 1) = (char)bits[7];
    while( true ) {
      uVar8 = bits[7];
      uVar9 = uVar9 - 1;
      bits[7] = uVar8 >> 8;
      if (uVar9 == 0) break;
      lVar4 = bits[0xd];
      bits[0xd] = lVar4 - 1;
      *(char *)(lVar4 - 1) = (char)(uVar8 >> 8);
    }
    lVar4 = bits[8];
    pbVar1 = (byte *)bits[0xc];
  }
  lVar7 = lVar4;
  if (7 < (int)lVar4) {
    lVar7 = 0;
  }
  lVar3 = bits[2];
  if (7 < (int)lVar4) {
    bits[8] = lVar7;
  }
  if (lVar3 == 0) {
    uVar9 = 0xffffffff;
    uVar2 = 0x19;
    iVar10 = 0;
    uVar8 = 0;
  }
  else {
    iVar10 = 0;
    lVar4 = lVar3;
    do {
      lVar4 = lVar4 >> 1;
      iVar10 = iVar10 + 1;
    } while (lVar4 != 0);
    uVar2 = 0x19 - iVar10;
    uVar8 = 0xffffff >> (uVar2 & 0xff);
    uVar9 = ~uVar8;
  }
  uVar13 = bits[1];
  uVar9 = uVar13 + uVar8 & uVar9 & 0xffffff;
  if ((uVar13 + uVar8 >> 0x18 != 0) == (lVar3 + uVar13 >> 0x18 != 0)) {
    if ((lVar3 + uVar13 & 0xffffff) <= uVar9 + uVar8) {
      uVar2 = 0x1a - iVar10;
      uVar9 = uVar13 + (uVar8 >> 1) & ~(uVar8 >> 1) & 0xffffff;
    }
    lVar4 = bits[4];
    if (uVar9 < uVar13) {
      lVar4 = lVar4 | 1;
    }
    bits[4] = lVar4;
  }
  lVar4 = bits[3];
  pbVar5 = (byte *)bits[0xb];
  bits[1] = uVar9;
  uVar8 = uVar2;
  if (8 < (int)uVar2) {
    do {
      if ((uVar9 < 0xff0000) || (bits[4] != 0)) {
        if ((-1 < (int)lVar4) && (pbVar1 < pbVar5)) {
          bits[0xc] = (lc3_bits_t)(pbVar1 + 1);
          *pbVar1 = (char)bits[4] + (char)lVar4;
          pbVar5 = (byte *)bits[0xb];
          pbVar1 = (byte *)bits[0xc];
        }
        lVar4 = bits[5];
        while (0 < (int)lVar4) {
          if (pbVar5 <= pbVar1) {
            bits[5] = lVar4 - 1;
            if (0 < (int)(lVar4 - 1)) {
              bits[5] = 0;
            }
            break;
          }
          bits[0xc] = (lc3_bits_t)(pbVar1 + 1);
          *pbVar1 = -(bits[4] == 0);
          pbVar1 = (byte *)bits[0xc];
          lVar4 = bits[5] - 1;
          pbVar5 = (byte *)bits[0xb];
          bits[5] = lVar4;
        }
        uVar9 = bits[1];
        bits[4] = 0;
        lVar4 = uVar9 >> 0x10;
        bits[3] = lVar4;
      }
      else {
        bits[5] = bits[5] + 1;
      }
      uVar8 = uVar8 - 8;
      uVar9 = (uVar9 & 0xffff) << 8;
      bits[1] = uVar9;
    } while (8 < (int)uVar8);
    uVar2 = (uVar2 - 8) - (uVar2 - 9 & 0xfffffff8);
  }
  if ((uVar9 < 0xff0000) || (bits[4] != 0)) {
    if ((-1 < (int)lVar4) && (pbVar1 < pbVar5)) {
      bits[0xc] = (lc3_bits_t)(pbVar1 + 1);
      *pbVar1 = (char)bits[4] + (char)lVar4;
      pbVar5 = (byte *)bits[0xb];
      pbVar1 = (byte *)bits[0xc];
    }
    lVar7 = bits[5];
    while (0 < (int)lVar7) {
      if (pbVar5 <= pbVar1) {
        lVar7 = lVar7 - 1;
        bits[5] = lVar7;
        if (0 < (int)lVar7) {
          lVar7 = 0;
          bits[5] = 0;
        }
        break;
      }
      bits[0xc] = (lc3_bits_t)(pbVar1 + 1);
      *pbVar1 = -(bits[4] == 0);
      pbVar1 = (byte *)bits[0xc];
      lVar7 = bits[5] - 1;
      pbVar5 = (byte *)bits[0xb];
      bits[5] = lVar7;
    }
    bits[4] = 0;
    uVar9 = bits[1];
    lVar4 = uVar9 >> 0x10;
    bits[3] = lVar4;
  }
  else {
    lVar7 = bits[5] + 1;
    bits[5] = lVar7;
  }
  bits[1] = (uVar9 & 0xffff) << 8;
  if (lVar7 == 0) {
    iVar10 = (int)lVar4 >> (8 - uVar2 & 0xff);
  }
  else {
    if (pbVar1 < pbVar5) {
      bits[0xc] = (lc3_bits_t)(pbVar1 + 1);
      *pbVar1 = (byte)lVar4;
      lVar7 = bits[5];
      pbVar5 = (byte *)bits[0xb];
      pbVar1 = (byte *)bits[0xc];
    }
    if ((int)lVar7 < 2) {
LAB_0006bb46:
      if (uVar2 == 8) {
        iVar10 = 0xff;
      }
      else {
        iVar10 = 0;
      }
    }
    else {
      do {
        if (pbVar5 <= pbVar1) {
          lVar4 = lVar7 - 1;
          if (lVar7 != 2) {
            lVar4 = 1;
          }
          bits[5] = lVar4;
          goto LAB_0006bb46;
        }
        bits[0xc] = (lc3_bits_t)(pbVar1 + 1);
        *pbVar1 = 0xff;
        pbVar1 = (byte *)bits[0xc];
        lVar7 = bits[5] - 1;
        pbVar5 = (byte *)bits[0xb];
        bits[5] = lVar7;
      } while (1 < (int)lVar7);
      if (uVar2 == 8) {
        iVar10 = 0xff;
      }
      else {
        iVar10 = 0;
      }
    }
  }
  if (pbVar1 < pbVar5) {
    *pbVar1 = *pbVar1 & (byte)(0xff >> (uVar2 & 0xff));
    *(byte *)bits[0xc] = (byte)(iVar10 << (8 - uVar2 & 0xff)) | *(byte *)bits[0xc];
  }
  return;
}


