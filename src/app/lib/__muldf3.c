/*
 * Function: __muldf3
 * Entry:    0000d8f8
 * Prototype: ulonglong __stdcall __muldf3(uint param_1, uint param_2, uint param_3, uint param_4)
 */


/* exclude_from_export */

ulonglong __muldf3(uint param_1,uint param_2,uint param_3,uint param_4)

{
  ulonglong uVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  uint extraout_r2;
  uint extraout_r3;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint unaff_r5;
  uint uVar8;
  uint uVar9;
  uint extraout_r12;
  uint uVar10;
  bool bVar11;
  bool bVar12;
  bool bVar13;
  ulonglong uVar14;
  
  uVar14 = CONCAT44(param_2,param_1);
  uVar9 = 0x7ff;
  uVar5 = param_2 >> 0x14 & 0x7ff;
  bVar11 = uVar5 == 0;
  if (!bVar11) {
    unaff_r5 = param_4 >> 0x14 & 0x7ff;
    bVar11 = unaff_r5 == 0;
  }
  if (!bVar11) {
    bVar11 = uVar5 == 0x7ff;
  }
  if (!bVar11) {
    bVar11 = unaff_r5 == 0x7ff;
  }
  if (bVar11) {
    uVar14 = __muldf3_outline(param_1,param_2,param_3,param_4);
    param_3 = extraout_r2;
    param_4 = extraout_r3;
    uVar9 = extraout_r12;
  }
  uVar4 = (uint)(uVar14 >> 0x20);
  uVar3 = (uint)uVar14;
  iVar6 = uVar5 + unaff_r5;
  uVar8 = uVar4 ^ param_4;
  uVar4 = uVar4 & ~(uVar9 << 0x15);
  uVar5 = param_4 & ~(uVar9 << 0x15);
  bVar11 = (uVar4 & 0xfffff) == 0;
  bVar12 = uVar3 == 0 && bVar11;
  if (uVar3 != 0 || !bVar11) {
    bVar12 = param_3 == 0 && (uVar5 & 0xfffff) == 0;
  }
  uVar4 = uVar4 | 0x100000;
  uVar5 = uVar5 | 0x100000;
  if (bVar12) {
    uVar3 = uVar3 | param_3;
    uVar5 = (uVar8 & 0x80000000 | uVar4) ^ uVar5;
    uVar4 = uVar9 >> 1;
    bVar12 = SBORROW4(iVar6,uVar4);
    uVar7 = iVar6 - uVar4;
    bVar11 = uVar7 == 0;
    uVar8 = uVar7;
    if (!bVar11 && (int)uVar4 <= iVar6) {
      bVar12 = SBORROW4(uVar9,uVar7);
      uVar8 = uVar9 - uVar7;
      bVar11 = uVar9 == uVar7;
    }
    if (!bVar11 && (int)uVar8 < 0 == bVar12) {
      return CONCAT44(uVar5 | uVar7 * 0x100000,uVar3);
    }
    uVar5 = uVar5 | 0x100000;
    uVar4 = 0;
    bVar12 = SBORROW4(uVar7,1);
    uVar7 = uVar7 - 1;
    bVar11 = uVar7 == 0;
    uVar9 = uVar7;
  }
  else {
    uVar1 = (uVar14 & 0xffffffff) * (ulonglong)param_3;
    uVar14 = (uVar14 & 0xffffffff) * (ulonglong)uVar5 +
             (ulonglong)uVar4 * (ulonglong)param_3 + (uVar1 >> 0x20);
    uVar10 = (uint)uVar14;
    lVar2 = (ulonglong)uVar4 * (ulonglong)uVar5 + (uVar14 >> 0x20);
    uVar9 = (uint)lVar2;
    uVar5 = (uint)((ulonglong)lVar2 >> 0x20);
    if ((int)uVar1 != 0) {
      uVar10 = uVar10 | 1;
    }
    uVar7 = (iVar6 + -0x3ff) - (uint)(uVar5 < 0x200);
    if (uVar5 < 0x200) {
      bVar11 = (uVar10 & 0x80000000) != 0;
      uVar10 = uVar10 << 1;
      lVar2 = CONCAT44(uVar5 * 2 + (uint)(CARRY4(uVar9,uVar9) || CARRY4(uVar9 * 2,(uint)bVar11)),
                       uVar9 * 2 + (uint)bVar11);
    }
    uVar5 = uVar8 & 0x80000000 | (int)((ulonglong)lVar2 >> 0x20) << 0xb | (uint)lVar2 >> 0x15;
    uVar3 = (uint)lVar2 << 0xb | uVar10 >> 0x15;
    uVar4 = uVar10 * 0x800;
    bVar13 = 0xfc < uVar7;
    bVar12 = SBORROW4(uVar7,0xfd);
    uVar8 = uVar7 - 0xfd;
    bVar11 = uVar8 == 0;
    uVar9 = uVar8;
    if (bVar13 && !bVar11) {
      bVar13 = 0x6ff < uVar8;
      bVar12 = SBORROW4(uVar8,0x700);
      uVar9 = uVar7 - 0x7fd;
      bVar11 = uVar8 == 0x700;
    }
    if (!bVar13 || bVar11) {
      bVar11 = 0x7fffffff < uVar4;
      if (uVar4 == 0x80000000) {
        bVar11 = (uVar10 >> 0x15 & 1) != 0;
      }
      return CONCAT44(uVar5 + uVar7 * 0x100000 + (uint)CARRY4(uVar3,(uint)bVar11),uVar3 + bVar11);
    }
  }
  if (!bVar11 && (int)uVar9 < 0 == bVar12) {
    return (ulonglong)(uVar5 & 0x80000000 | 0x7ff00000) << 0x20;
  }
  if (-0x36 < (int)uVar7) {
    uVar9 = -uVar7;
    uVar8 = uVar9 - 0x20;
    if (0x1f < (int)uVar9) {
      uVar7 = uVar3 >> (uVar8 & 0xff) | uVar5 << (0x20 - uVar8 & 0xff);
      uVar9 = (uVar5 >> (uVar8 & 0xff) & ~((uVar5 & 0x80000000) >> (uVar8 & 0xff))) -
              ((int)uVar7 >> 0x1f);
      if ((uVar4 == 0 && uVar3 << (0x20 - uVar8 & 0xff) == 0) && (uVar7 & 0x7fffffff) == 0) {
        uVar9 = uVar9 & ~(uVar7 >> 0x1f);
      }
      return CONCAT44(uVar5,uVar9) & 0x80000000ffffffff;
    }
    if (uVar9 - 0x14 != 0 && -0xd < (int)uVar8) {
      uVar9 = 0xc - (uVar9 - 0x14);
      uVar8 = uVar3 << (uVar9 & 0xff);
      uVar9 = uVar3 >> (0x20 - uVar9 & 0xff) | uVar5 << (uVar9 & 0xff);
      uVar3 = uVar9 + -((int)uVar8 >> 0x1f);
      if (uVar4 == 0 && (uVar8 & 0x7fffffff) == 0) {
        uVar3 = uVar3 & ~(uVar8 >> 0x1f);
      }
      return CONCAT44((uVar5 & 0x80000000) + (uint)CARRY4(uVar9,-((int)uVar8 >> 0x1f)),uVar3);
    }
    uVar10 = uVar3 << (uVar7 + 0x20 & 0xff);
    uVar3 = uVar3 >> (uVar9 & 0xff) | uVar5 << (uVar7 + 0x20 & 0xff);
    uVar8 = uVar3 + -((int)uVar10 >> 0x1f);
    if (uVar4 == 0 && (uVar10 & 0x7fffffff) == 0) {
      uVar8 = uVar8 & ~(uVar10 >> 0x1f);
    }
    return CONCAT44((uVar5 & 0x80000000) +
                    ((uVar5 & 0x7fffffff) >> (uVar9 & 0xff)) +
                    (uint)CARRY4(uVar3,-((int)uVar10 >> 0x1f)),uVar8);
  }
  return (ulonglong)(uVar5 & 0x80000000) << 0x20;
}


