/*
 * Function: lc3_spec_encode
 * Entry:    00072c68
 * Prototype: void __stdcall lc3_spec_encode(lc3_bits_t * bits, lc3_dt dt, lc3_srate sr, lc3_bandwidth bw, int nbytes, uint16_t * xq, lc3_spec_side_t * side, float * x)
 */


/* exclude_from_export_ai */

void lc3_spec_encode(lc3_bits_t *bits,lc3_dt dt,lc3_srate sr,lc3_bandwidth bw,int nbytes,
                    uint16_t *xq,lc3_spec_side_t *side,float *x)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  ushort uVar4;
  uint16_t *puVar5;
  uint uVar6;
  uint uVar7;
  float *pfVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  lc3_bits_t lVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  uint uVar20;
  ushort *puVar21;
  int iVar22;
  int iVar23;
  uint uVar24;
  ushort *puVar25;
  byte *pbVar26;
  int iVar27;
  int iVar28;
  uint in_fpscr;
  float fVar29;
  float fVar30;
  uint local_50;
  undefined *local_4c;
  uint local_40;
  int local_3c;
  
  bVar1 = side[2].opaque[0];
  iVar18 = *(int *)side[1].opaque;
  iVar17 = iVar18;
  if (dt == 0) {
    iVar11 = (bw + 1) * 0x3c;
    if (iVar11 <= iVar18) {
      iVar17 = iVar11;
    }
    iVar11 = iVar11 + 2;
    if (0x10 < iVar17) {
      iVar16 = 0x10;
      iVar23 = 3;
      iVar28 = 2;
      goto LAB_00072ca8;
    }
    fVar30 = 0.0;
    iVar23 = 3;
    iVar27 = 0x10;
    iVar28 = 4;
    iVar19 = -2;
    iVar17 = 0;
    iVar22 = 0;
LAB_00072d14:
    pfVar8 = x + iVar19 + iVar27;
    iVar27 = iVar27 - iVar17;
    do {
      iVar17 = iVar17 + 1;
      if (iVar28 < iVar17) {
        fVar30 = fVar30 + ABS(*pfVar8);
        iVar22 = iVar22 + 1;
      }
      pfVar8 = pfVar8 + 1;
    } while (iVar27 + iVar17 < iVar11);
LAB_00072d40:
    if (iVar22 != 0) {
      fVar29 = (float)VectorSignedToFloat(iVar22,(byte)(in_fpscr >> 0x16) & 3);
      uVar12 = bits[8];
      uVar9 = 8 - (int)((fVar30 * 16.0) / fVar29 + 0.5);
      if ((int)uVar9 < 7) {
        uVar9 = uVar9 & ~((int)uVar9 >> 0x1f);
      }
      else {
        uVar9 = 7;
      }
      goto joined_r0x00072d80;
    }
  }
  else {
    iVar11 = (bw + 1) * 0x50;
    if (iVar11 <= iVar18) {
      iVar17 = iVar11;
    }
    iVar23 = dt + 3;
    iVar28 = dt + 2;
    iVar27 = iVar23 * 6 - iVar28;
    iVar11 = iVar11 + iVar28;
    iVar16 = iVar27;
    if (iVar27 < iVar17) {
LAB_00072ca8:
      iVar27 = iVar17;
      iVar22 = 0;
      iVar19 = -2 - dt;
      puVar5 = xq + iVar16 + 0x7fffffff;
      pfVar8 = x + iVar16 + iVar19;
      fVar30 = 0.0;
      iVar16 = 0;
      iVar28 = iVar28 * 2;
      do {
        while( true ) {
          puVar5 = puVar5 + 1;
          iVar16 = iVar16 + 1;
          if (*puVar5 == 0) break;
          iVar16 = 0;
          pfVar8 = pfVar8 + 1;
          iVar17 = 0;
          if (puVar5 == xq + iVar27 + -1) goto LAB_00072d0e;
        }
        if (iVar28 < iVar16) {
          fVar30 = fVar30 + ABS(*pfVar8);
          iVar22 = iVar22 + 1;
        }
        pfVar8 = pfVar8 + 1;
        iVar17 = iVar16;
      } while (puVar5 != xq + iVar27 + -1);
LAB_00072d0e:
      if (iVar27 < iVar11) goto LAB_00072d14;
      goto LAB_00072d40;
    }
    if (iVar27 < iVar11) {
      iVar17 = 0;
      fVar30 = 0.0;
      iVar28 = iVar28 * 2;
      iVar19 = -2 - dt;
      iVar22 = iVar17;
      goto LAB_00072d14;
    }
  }
  uVar12 = bits[8];
  uVar9 = 0;
joined_r0x00072d80:
  if ((int)(uVar12 + 3) < 0x21) {
    bits[8] = uVar12 + 3;
    bits[7] = bits[7] | uVar9 << (uVar12 & 0xff);
  }
  else {
    lc3_put_bits_generic(bits,uVar9,3);
  }
  local_4c = &DAT_000928e0 + (uint)((int)((sr + LC3_SRATE_16K) * 0x14) < nbytes) * 0x800;
  local_50 = 0;
  local_3c = 0;
  local_40 = 1;
  do {
    iVar17 = (int)((sr * iVar23 + iVar23) * 0x14 + 2) >> (local_40 & 0xff);
    if (iVar18 <= iVar17) {
      iVar17 = iVar18;
    }
    if (local_3c < iVar17) {
      uVar12 = (iVar17 - local_3c) - 1;
      puVar21 = xq + local_3c;
LAB_00072dfa:
      do {
        uVar24 = (uint)(puVar21[1] >> 1);
        uVar20 = (uint)(ushort)((puVar21[1] | *puVar21) >> 3);
        uVar9 = (uint)(*puVar21 >> 1);
        pbVar26 = local_4c + local_50 * 4;
        if (uVar20 == 0) {
          uVar20 = 0;
          uVar6 = uVar24;
          uVar13 = uVar9;
        }
        else {
          uVar6 = 0;
          uVar13 = uVar6;
          if (bVar1 == 0) {
LAB_00072ffc:
            do {
              while( true ) {
                uVar7 = bits[8];
                uVar14 = uVar7 + 1;
                uVar10 = (int)uVar9 >> (uVar6 & 0xff) & 1;
                if ((int)uVar14 < 0x21) {
                  bits[8] = uVar14;
                  bits[7] = bits[7] | uVar10 << (uVar7 & 0xff);
                }
                else {
                  lc3_put_bits_generic(bits,uVar10,1);
                  uVar14 = bits[8];
                }
                uVar7 = (int)uVar24 >> (uVar6 & 0xff) & 1;
                if ((int)(uVar14 + 1) < 0x21) {
                  bits[8] = uVar14 + 1;
                  bits[7] = bits[7] | uVar7 << (uVar14 & 0xff);
                }
                else {
                  lc3_put_bits_generic(bits,uVar7,1);
                }
                uVar7 = uVar6;
                if (2 < (int)uVar6) {
                  uVar7 = 3;
                }
                bVar2 = pbVar26[uVar7];
                uVar10 = (bits[2] >> 10) * (uint)*(ushort *)(&DAT_00091820 + (uint)bVar2 * 0x44) +
                         bits[1];
                bits[1] = uVar10;
                uVar7 = (bits[2] >> 10) * (uint)*(ushort *)(&DAT_00091822 + (uint)bVar2 * 0x44);
                bits[1] = uVar10 & 0xffffff;
                bits[2] = uVar7;
                uVar6 = uVar6 + 1;
                bits[4] = bits[4] | uVar10 >> 0x18;
                uVar20 = (int)uVar20 >> 1;
                if (uVar7 < 0x10000) break;
                if (uVar20 == 0) goto LAB_00073026;
              }
              lc3_ac_write_renorm(bits);
            } while (uVar20 != 0);
LAB_00073026:
            uVar20 = uVar6;
            if (2 < (int)uVar6) {
              uVar20 = 3;
            }
          }
          else {
            bVar2 = *pbVar26;
            uVar13 = (bits[2] >> 10) * (uint)*(ushort *)(&DAT_00091820 + (uint)bVar2 * 0x44) +
                     bits[1];
            bits[1] = uVar13;
            uVar6 = (bits[2] >> 10) * (uint)*(ushort *)(&DAT_00091822 + (uint)bVar2 * 0x44);
            bits[2] = uVar6;
            bits[4] = bits[4] | uVar13 >> 0x18;
            bits[1] = uVar13 & 0xffffff;
            if (uVar6 < 0x10000) {
              lc3_ac_write_renorm(bits);
            }
            uVar20 = (int)uVar20 >> 1;
            if (uVar20 != 0) {
              uVar6 = 1;
              uVar13 = uVar6;
              goto LAB_00072ffc;
            }
            uVar13 = 1;
            uVar20 = uVar13;
            uVar6 = uVar13;
          }
          pbVar26 = pbVar26 + uVar20;
          uVar7 = (int)uVar9 >> uVar13;
          uVar10 = (int)uVar24 >> uVar13;
          uVar9 = (int)uVar7 >> (uVar6 - uVar13 & 0xff);
          uVar24 = (int)uVar10 >> (uVar6 - uVar13 & 0xff);
          uVar6 = uVar10 & 0xffff;
          uVar13 = uVar7 & 0xffff;
        }
        if (uVar13 != 0) {
          uVar13 = bits[8];
          uVar4 = *puVar21;
          lVar15 = uVar13 + 1;
          if ((int)lVar15 < 0x21) {
            bits[8] = lVar15;
            bits[7] = bits[7] | (uVar4 & 1) << (uVar13 & 0xff);
          }
          else {
            lc3_put_bits_generic(bits,uVar4 & 1,1);
          }
        }
        if (uVar6 != 0) {
          uVar6 = bits[8];
          uVar4 = puVar21[1];
          lVar15 = uVar6 + 1;
          if ((int)lVar15 < 0x21) {
            bits[8] = lVar15;
            bits[7] = bits[7] | (uVar4 & 1) << (uVar6 & 0xff);
          }
          else {
            lc3_put_bits_generic(bits,uVar4 & 1,1);
          }
        }
        bVar2 = *pbVar26;
        iVar17 = uVar9 + uVar24 * 4;
        uVar13 = (bits[2] >> 10) *
                 (uint)*(ushort *)(&UNK_000917e0 + iVar17 * 4 + (uint)bVar2 * 0x44) + bits[1];
        bits[1] = uVar13;
        uVar6 = (bits[2] >> 10) *
                (uint)*(ushort *)(&UNK_000917e0 + iVar17 * 4 + (uint)bVar2 * 0x44 + 2);
        bits[2] = uVar6;
        bits[4] = bits[4] | uVar13 >> 0x18;
        bits[1] = uVar13 & 0xffffff;
        if (uVar6 < 0x10000) {
          lc3_ac_write_renorm(bits);
        }
        iVar17 = (local_50 & 0xf) * 0x10;
        if (1 < (int)uVar20) {
          local_50 = iVar17 + uVar20 + 0xc & 0xff;
          puVar21 = puVar21 + 2;
          if (xq + (uVar12 & 0xfffffffe) + local_3c + 2 == puVar21) break;
          goto LAB_00072dfa;
        }
        local_50 = (int)(short)((short)uVar9 + (short)uVar24) * (int)(short)((short)uVar20 + 1) +
                   iVar17 + 1U & 0xff;
        puVar21 = puVar21 + 2;
      } while (puVar21 != xq + (uVar12 & 0xfffffffe) + local_3c + 2);
      local_3c = (uVar12 & 0xfffffffe) + local_3c + 2;
    }
    local_40 = local_40 - 1;
    local_4c = local_4c + 0x400;
    if (local_40 == 0xffffffff) {
      iVar17 = lc3_get_bits_left(bits);
      if (bVar1 == 0) {
        if ((0 < iVar18) && (0 < iVar17)) {
          puVar21 = xq + -1;
          puVar25 = puVar21 + iVar18;
          while( true ) {
            while( true ) {
              puVar21 = puVar21 + 1;
              uVar4 = *puVar21;
              if (uVar4 == 0) break;
              uVar12 = (uint)(uVar4 >> 1);
              if ((int)((uint)uVar4 << 0x1f) < 0) {
                uVar12 = -uVar12;
              }
              fVar30 = (float)VectorSignedToFloat(uVar12,(byte)(in_fpscr >> 0x16) & 3);
              uVar12 = in_fpscr & 0xfffffff | (uint)(*x < fVar30) << 0x1f;
              in_fpscr = uVar12 | (uint)(NAN(*x) || NAN(fVar30)) << 0x1c;
              lVar15 = bits[8] + 1;
              uVar12 = (uint)((byte)(uVar12 >> 0x1f) == ((byte)(in_fpscr >> 0x1c) & 1));
              if ((int)lVar15 < 0x21) {
                bits[7] = bits[7] | uVar12 << (bits[8] & 0xff);
                bits[8] = lVar15;
              }
              else {
                lc3_put_bits_generic(bits,uVar12,1);
              }
              iVar17 = iVar17 + -1;
              if (puVar21 == puVar25) {
                return;
              }
              x = x + 1;
              if (iVar17 == 0) {
                return;
              }
            }
            if (puVar21 == puVar25) break;
            x = x + 1;
          }
        }
      }
      else if ((0 < iVar18) && (0 < iVar17)) {
        puVar21 = xq + (iVar18 - 1U & 0xfffffffe);
        while( true ) {
          while( true ) {
            uVar3 = xq[1];
            uVar4 = *xq;
            if ((ushort)((uVar3 | uVar4) >> 3) != 0) break;
            if (xq == puVar21) {
              return;
            }
            xq = xq + 2;
          }
          uVar12 = bits[8];
          iVar18 = iVar17 + -1;
          lVar15 = uVar12 + 1;
          uVar9 = uVar4 >> 1 & 1;
          if ((int)lVar15 < 0x21) {
            bits[8] = lVar15;
            bits[7] = bits[7] | uVar9 << (uVar12 & 0xff);
          }
          else {
            lc3_put_bits_generic(bits,uVar9,1);
          }
          if (uVar4 >> 1 == 1) {
            if (iVar18 == 0) {
              return;
            }
            uVar12 = bits[8];
            lVar15 = uVar12 + 1;
            if ((int)lVar15 < 0x21) {
              bits[8] = lVar15;
              bits[7] = bits[7] | (uVar4 & 1) << (uVar12 & 0xff);
            }
            else {
              lc3_put_bits_generic(bits,uVar4 & 1,1);
            }
            iVar18 = iVar17 + -2;
          }
          iVar17 = iVar18 + -1;
          if (iVar18 != 0) {
            uVar12 = bits[8];
            uVar9 = uVar3 >> 1 & 1;
            lVar15 = uVar12 + 1;
            if ((int)lVar15 < 0x21) {
              bits[8] = lVar15;
              bits[7] = bits[7] | uVar9 << (uVar12 & 0xff);
            }
            else {
              lc3_put_bits_generic(bits,uVar9,1);
            }
          }
          if (uVar3 >> 1 == 1) {
            if (0 < iVar17) {
              uVar12 = bits[8];
              lVar15 = uVar12 + 1;
              if ((int)lVar15 < 0x21) {
                bits[8] = lVar15;
                bits[7] = bits[7] | (uVar3 & 1) << (uVar12 & 0xff);
              }
              else {
                lc3_put_bits_generic(bits,uVar3 & 1,1);
              }
            }
            iVar17 = iVar18 + -2;
          }
          if (xq == puVar21) break;
          xq = xq + 2;
          if (iVar17 < 1) {
            return;
          }
        }
        return;
      }
      return;
    }
  } while( true );
}


