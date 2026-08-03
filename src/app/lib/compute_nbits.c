/*
 * Function: compute_nbits
 * Entry:    00072534
 * Prototype: int __stdcall compute_nbits(lc3_dt dt, lc3_srate sr, int nbytes, uint16_t * x, int * n, int nbits_budget, bool * p_lsb_mode)
 */


/* exclude_from_export */

int compute_nbits(lc3_dt dt,lc3_srate sr,int nbytes,uint16_t *x,int *n,int nbits_budget,
                 bool *p_lsb_mode)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  byte *pbVar15;
  ushort *puVar16;
  undefined *local_50;
  int local_4c;
  int local_48;
  int local_3c;
  
  iVar4 = (sr + LC3_SRATE_32K) * 0x14;
  if (nbits_budget == 0) {
    iVar13 = 0x7fffffff;
  }
  else {
    iVar13 = nbits_budget << 0xb;
  }
  iVar12 = 0;
  uVar2 = 1;
  local_50 = &DAT_000928e0 + (uint)(iVar4 + -0x28 < nbytes) * 0x800;
  uVar1 = 0;
  iVar8 = 0;
  local_4c = 0;
  local_48 = 0;
  local_3c = 0;
  do {
    iVar14 = (int)((sr * (dt + 3) + dt + 3) * 0x14 + 2) >> (uVar2 & 0xff);
    if (*n <= iVar14) {
      iVar14 = *n;
    }
    if ((iVar12 < iVar14) && (iVar8 <= iVar13)) {
      puVar16 = x + iVar12 + 1;
      do {
        uVar9 = (uint)(puVar16[-1] >> 1);
        uVar10 = (uint)(*puVar16 >> 1);
        iVar11 = (uint)(uVar9 != 0) + (uint)(uVar10 != 0);
        pbVar15 = local_50 + uVar1 * 4;
        uVar5 = (uint)(ushort)((puVar16[-1] | *puVar16) >> 3);
        iVar8 = iVar8 + iVar11 * 0x800;
        uVar6 = 0;
        if (uVar5 != 0) {
          if (nbytes < iVar4) {
            uVar7 = 0;
LAB_000726de:
            do {
              uVar6 = uVar7;
              if (2 < (int)uVar7) {
                uVar6 = 3;
              }
              uVar5 = (int)uVar5 >> 1;
              uVar7 = uVar7 + 1;
              iVar8 = iVar8 + (uint)*(ushort *)(&DAT_00090f80 + (uint)pbVar15[uVar6] * 0x22);
            } while (uVar5 != 0);
            uVar6 = uVar7;
            if (2 < (int)uVar7) {
              uVar6 = 3;
            }
            iVar3 = uVar7 * 0x1000;
          }
          else {
            if (uVar9 == 1) {
              iVar3 = 3;
            }
            else {
              iVar3 = 2;
            }
            if (uVar10 == 1) {
              iVar3 = iVar3 + 1;
            }
            uVar5 = (int)uVar5 >> 1;
            iVar8 = iVar8 + (*(ushort *)(&DAT_00090f80 + (uint)*pbVar15 * 0x22) - 0x1000);
            local_3c = local_3c + iVar3;
            if (uVar5 != 0) {
              uVar7 = 1;
              goto LAB_000726de;
            }
            uVar6 = 1;
            iVar3 = 0x1000;
            uVar7 = uVar6;
          }
          pbVar15 = pbVar15 + uVar6;
          iVar8 = iVar8 + iVar3;
          uVar9 = (int)uVar9 >> (uVar7 & 0xff);
          uVar10 = (int)uVar10 >> (uVar7 & 0xff);
        }
        iVar12 = iVar12 + 2;
        iVar8 = iVar8 + (uint)*(ushort *)
                               (&DAT_00090f60 + ((uint)*pbVar15 * 0x11 + uVar9 + uVar10 * 4) * 2);
        if ((iVar11 != 0) && (iVar8 <= iVar13)) {
          local_4c = iVar8;
          local_48 = iVar12;
        }
        if ((int)uVar6 < 2) {
          uVar6 = (int)(short)((short)uVar10 + (short)uVar9) * (int)(short)((short)uVar6 + 1) + 1;
        }
        else {
          uVar6 = uVar6 + 0xc;
        }
        uVar1 = (uVar1 & 0xf) * 0x10 + (uVar6 & 0xff) & 0xff;
      } while ((iVar12 < iVar14) && (puVar16 = puVar16 + 2, iVar8 <= iVar13));
    }
    uVar2 = uVar2 - 1;
    local_50 = local_50 + 0x400;
  } while (uVar2 != 0xffffffff);
  *n = local_48;
  if (p_lsb_mode != (bool *)0x0) {
    if ((iVar4 <= nbytes) && (iVar13 < local_4c + local_3c * 0x800)) {
      *p_lsb_mode = true;
      goto LAB_00072692;
    }
    *p_lsb_mode = false;
  }
  if (iVar13 == 0x7fffffff) {
    local_4c = local_4c + local_3c * 0x800;
  }
LAB_00072692:
  iVar4 = local_4c + 0x7ff;
  if (iVar4 < 0) {
    iVar4 = local_4c + 0xffe;
  }
  return iVar4 >> 0xb;
}


