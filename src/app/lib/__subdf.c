/*
 * Function: __subdf
 * Entry:    0000d588
 * Prototype: ulonglong __stdcall __subdf(uint param_1, uint param_2, uint param_3, uint param_4)
 */


/* exclude_from_export */

ulonglong __subdf(uint param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  bool bVar14;
  bool bVar15;
  
  uVar6 = param_4 ^ 0x80000000;
  uVar9 = param_2 << 1;
  bVar14 = ((param_2 ^ uVar6) & 0x7fffffff) == 0;
  bVar15 = bVar14 && param_1 == param_3;
  if (!bVar14 || param_1 != param_3) {
    bVar15 = uVar9 == 0 && param_1 == 0;
  }
  if (!bVar15) {
    bVar15 = param_4 << 1 == 0 && param_3 == 0;
  }
  iVar8 = (int)uVar9 >> 0x15;
  if (!bVar15) {
    bVar15 = iVar8 == -1;
  }
  iVar1 = (int)(param_4 << 1) >> 0x15;
  if (!bVar15) {
    bVar15 = iVar1 == -1;
  }
  if (bVar15) {
    if (iVar8 == -1 || iVar1 == -1) {
      uVar9 = param_3;
      uVar12 = uVar6;
      if (iVar8 == -1) {
        uVar9 = param_1;
        uVar12 = param_2;
      }
      if (iVar8 != -1 || iVar1 != -1) {
        param_3 = uVar9;
        uVar6 = uVar12;
      }
      bVar15 = (uVar12 & 0xfffff) == 0;
      bVar14 = uVar9 == 0 && bVar15;
      if (uVar9 == 0 && bVar15) {
        bVar14 = param_3 == 0 && (uVar6 & 0xfffff) == 0;
      }
      if (!bVar14 || uVar12 != uVar6) {
        uVar12 = uVar12 | 0x80000;
      }
      return CONCAT44(uVar12,uVar9);
    }
    if (((param_2 ^ uVar6) & 0x7fffffff) != 0 || param_1 != param_3) {
      if (uVar9 == 0 && param_1 == 0) {
        param_1 = param_3;
        param_2 = uVar6;
      }
      return CONCAT44(param_2,param_1);
    }
    if (param_2 != uVar6) {
      return 0;
    }
    if ((param_2 & 0x7fffffff) >> 0x14 == 0) {
      bVar15 = (param_1 & 0x80000000) != 0;
      uVar6 = param_2 * 2 + (uint)bVar15;
      if (CARRY4(param_2,param_2) || CARRY4(param_2 * 2,(uint)bVar15)) {
        uVar6 = uVar6 | 0x80000000;
      }
      return CONCAT44(uVar6,param_1 << 1);
    }
    if (uVar9 < 0xffc00000) {
      return CONCAT44(param_2 + 0x100000,param_1);
    }
    uVar6 = param_2 & 0x80000000;
LAB_0000d7cc:
    return (ulonglong)(uVar6 | 0x7ff00000) << 0x20;
  }
  uVar10 = (param_2 & 0x7fffffff) >> 0x14;
  uVar9 = (uVar6 & 0x7fffffff) >> 0x14;
  uVar12 = uVar9 - uVar10;
  bVar15 = uVar12 != 0;
  if (uVar9 < uVar10) {
    uVar12 = -uVar12;
  }
  uVar11 = param_1;
  uVar7 = param_2;
  if (bVar15 && uVar10 <= uVar9) {
    uVar10 = uVar10 + uVar12;
    uVar11 = param_3;
    uVar7 = uVar6;
    param_3 = param_1;
    uVar6 = param_2;
  }
  if (0x36 < uVar12) {
    return CONCAT44(uVar7,uVar11);
  }
  uVar9 = uVar7 & 0xfffff | 0x100000;
  if ((uVar7 & 0x80000000) != 0) {
    bVar15 = uVar11 != 0;
    uVar11 = -uVar11;
    uVar9 = -uVar9 - (uint)bVar15;
  }
  uVar7 = uVar6 & 0xfffff | 0x100000;
  if ((uVar6 & 0x80000000) != 0) {
    bVar15 = param_3 != 0;
    param_3 = -param_3;
    uVar7 = -uVar7 - (uint)bVar15;
  }
  if (uVar10 == uVar12) {
    uVar7 = uVar7 ^ 0x100000;
    if (uVar10 == 0) {
      uVar9 = uVar9 ^ 0x100000;
      uVar10 = 1;
    }
    else {
      uVar12 = uVar12 - 1;
    }
  }
  uVar6 = -uVar12 + 0x20;
  if ((int)uVar12 < 0x21) {
    uVar13 = param_3 << (uVar6 & 0xff);
    uVar5 = param_3 >> (uVar12 & 0xff);
    uVar3 = uVar11 + uVar5;
    uVar6 = uVar7 << (uVar6 & 0xff);
    uVar4 = uVar3 + uVar6;
    uVar9 = uVar9 + CARRY4(uVar11,uVar5) + ((int)uVar7 >> (uVar12 & 0xff)) +
            (uint)CARRY4(uVar3,uVar6);
  }
  else {
    uVar13 = uVar7 << (-uVar12 + 0x40 & 0xff);
    if (param_3 != 0) {
      uVar13 = uVar13 | 2;
    }
    uVar7 = (int)uVar7 >> (uVar12 - 0x20 & 0xff);
    uVar4 = uVar11 + uVar7;
    uVar9 = uVar9 + ((int)uVar7 >> 0x1f) + (uint)CARRY4(uVar11,uVar7);
  }
  uVar6 = uVar9 & 0x80000000;
  uVar12 = uVar9;
  if ((int)uVar9 < 0) {
    bVar15 = uVar13 == 0;
    uVar13 = -uVar13;
    uVar12 = -uVar4;
    uVar4 = -(uint)!bVar15 - uVar4;
    uVar12 = -(uint)(bVar15 <= uVar12) - uVar9;
  }
  if (0xfffff < uVar12) {
    uVar11 = uVar10 - 1;
    if (0x1fffff < uVar12) {
      uVar9 = uVar12 & 1;
      uVar12 = uVar12 >> 1;
      bVar2 = (byte)uVar4;
      uVar4 = (uint)(uVar9 != 0) << 0x1f | uVar4 >> 1;
      uVar13 = (uint)(bVar2 & 1) << 0x1f | uVar13 >> 1;
      uVar11 = uVar10;
      if (0xffbfffff < uVar10 * 0x200000) goto LAB_0000d7cc;
    }
LAB_0000d698:
    bVar15 = 0x7fffffff < uVar13;
    if (uVar13 == 0x80000000) {
      bVar15 = (uVar4 & 1) != 0;
    }
    return CONCAT44(uVar12 + uVar11 * 0x100000 + (uint)CARRY4(uVar4,(uint)bVar15) | uVar6,
                    uVar4 + bVar15);
  }
  bVar14 = (uVar13 & 0x80000000) != 0;
  uVar13 = uVar13 << 1;
  uVar11 = uVar4 * 2;
  bVar15 = CARRY4(uVar4,uVar4);
  uVar4 = uVar4 * 2 + (uint)bVar14;
  uVar12 = uVar12 * 2 + (uint)(bVar15 || CARRY4(uVar11,(uint)bVar14));
  uVar11 = uVar10 - 2;
  if (uVar10 - 1 != 0 && 0xfffff < uVar12) goto LAB_0000d698;
  uVar7 = uVar4;
  uVar10 = uVar12;
  if (uVar12 == 0) {
    uVar7 = 0;
    uVar10 = uVar4;
  }
  iVar8 = LZCOUNT(uVar10);
  if (uVar12 == 0) {
    iVar8 = iVar8 + 0x20;
  }
  uVar5 = iVar8 - 0xb;
  bVar14 = SBORROW4(uVar5,0x20);
  uVar3 = iVar8 - 0x2b;
  bVar15 = uVar3 == 0;
  uVar12 = uVar3;
  uVar4 = uVar3;
  if ((int)uVar5 < 0x20) {
    bVar14 = SCARRY4(uVar3,0xc);
    uVar4 = iVar8 - 0x1f;
    bVar15 = uVar4 == 0;
    uVar12 = uVar5;
    if (!bVar15 && -0xd < (int)uVar3) {
      uVar7 = uVar10 << (uVar5 & 0xff);
      uVar10 = uVar10 >> (0xc - uVar4 & 0xff);
      goto LAB_0000d710;
    }
  }
  if (bVar15 || (int)uVar4 < 0 != bVar14) {
    uVar13 = 0x20 - uVar12;
  }
  uVar10 = uVar10 << (uVar12 & 0xff);
  if (bVar15 || (int)uVar4 < 0 != bVar14) {
    uVar10 = uVar10 | uVar7 >> (uVar13 & 0xff);
    uVar7 = uVar7 << (uVar12 & 0xff);
  }
LAB_0000d710:
  if ((int)uVar5 <= (int)uVar11) {
    return CONCAT44(uVar10 + (uVar11 - uVar5) * 0x100000 | uVar6,uVar7);
  }
  uVar12 = ~(uVar11 - uVar5);
  if ((int)uVar12 < 0x1f) {
    if (uVar12 - 0x13 != 0 && -0xd < (int)(uVar12 - 0x1f)) {
      uVar6 = 0xc - (uVar12 - 0x13);
      return CONCAT44(uVar9,uVar7 >> (0x20 - uVar6 & 0xff) | uVar10 << (uVar6 & 0xff)) &
             0x80000000ffffffff;
    }
    uVar12 = uVar12 + 1;
    return CONCAT44(uVar6 | uVar10 >> (uVar12 & 0xff),
                    uVar7 >> (uVar12 & 0xff) | uVar10 << (0x20 - uVar12 & 0xff));
  }
  return CONCAT44(uVar9,uVar10 >> (uVar12 - 0x1f & 0xff)) & 0x80000000ffffffff;
}


