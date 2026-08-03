/*
 * Function: __aeabi_dadd
 * Entry:    0000d58c
 * Prototype: ulonglong __stdcall __aeabi_dadd(uint param_1, uint param_2, uint param_3, uint param_4)
 */


/* exclude_from_export */

ulonglong __aeabi_dadd(uint param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  bool bVar14;
  bool bVar15;
  
  uVar8 = param_2 << 1;
  bVar14 = ((param_2 ^ param_4) & 0x7fffffff) == 0;
  bVar15 = bVar14 && param_1 == param_3;
  if (!bVar14 || param_1 != param_3) {
    bVar15 = uVar8 == 0 && param_1 == 0;
  }
  if (!bVar15) {
    bVar15 = param_4 << 1 == 0 && param_3 == 0;
  }
  iVar7 = (int)uVar8 >> 0x15;
  if (!bVar15) {
    bVar15 = iVar7 == -1;
  }
  iVar1 = (int)(param_4 << 1) >> 0x15;
  if (!bVar15) {
    bVar15 = iVar1 == -1;
  }
  if (bVar15) {
    if (iVar7 == -1 || iVar1 == -1) {
      uVar8 = param_3;
      uVar11 = param_4;
      if (iVar7 == -1) {
        uVar8 = param_1;
        uVar11 = param_2;
      }
      if (iVar7 != -1 || iVar1 != -1) {
        param_3 = uVar8;
        param_4 = uVar11;
      }
      bVar15 = (uVar11 & 0xfffff) == 0;
      bVar14 = uVar8 == 0 && bVar15;
      if (uVar8 == 0 && bVar15) {
        bVar14 = param_3 == 0 && (param_4 & 0xfffff) == 0;
      }
      if (!bVar14 || uVar11 != param_4) {
        uVar11 = uVar11 | 0x80000;
      }
      return CONCAT44(uVar11,uVar8);
    }
    if (((param_2 ^ param_4) & 0x7fffffff) != 0 || param_1 != param_3) {
      if (uVar8 == 0 && param_1 == 0) {
        param_1 = param_3;
        param_2 = param_4;
      }
      return CONCAT44(param_2,param_1);
    }
    if (param_2 != param_4) {
      return 0;
    }
    if ((param_2 & 0x7fffffff) >> 0x14 == 0) {
      bVar15 = (param_1 & 0x80000000) != 0;
      uVar8 = param_2 * 2 + (uint)bVar15;
      if (CARRY4(param_2,param_2) || CARRY4(param_2 * 2,(uint)bVar15)) {
        uVar8 = uVar8 | 0x80000000;
      }
      return CONCAT44(uVar8,param_1 << 1);
    }
    if (uVar8 < 0xffc00000) {
      return CONCAT44(param_2 + 0x100000,param_1);
    }
    uVar8 = param_2 & 0x80000000;
LAB_0000d7cc:
    return (ulonglong)(uVar8 | 0x7ff00000) << 0x20;
  }
  uVar9 = (param_2 & 0x7fffffff) >> 0x14;
  uVar8 = (param_4 & 0x7fffffff) >> 0x14;
  uVar11 = uVar8 - uVar9;
  bVar15 = uVar11 != 0;
  if (uVar8 < uVar9) {
    uVar11 = -uVar11;
  }
  uVar10 = param_1;
  uVar13 = param_2;
  if (bVar15 && uVar9 <= uVar8) {
    uVar9 = uVar9 + uVar11;
    uVar10 = param_3;
    uVar13 = param_4;
    param_3 = param_1;
    param_4 = param_2;
  }
  if (0x36 < uVar11) {
    return CONCAT44(uVar13,uVar10);
  }
  uVar4 = uVar13 & 0xfffff | 0x100000;
  if ((uVar13 & 0x80000000) != 0) {
    bVar15 = uVar10 != 0;
    uVar10 = -uVar10;
    uVar4 = -uVar4 - (uint)bVar15;
  }
  uVar8 = param_4 & 0xfffff | 0x100000;
  if ((param_4 & 0x80000000) != 0) {
    bVar15 = param_3 != 0;
    param_3 = -param_3;
    uVar8 = -uVar8 - (uint)bVar15;
  }
  if (uVar9 == uVar11) {
    uVar8 = uVar8 ^ 0x100000;
    if (uVar9 == 0) {
      uVar4 = uVar4 ^ 0x100000;
      uVar9 = 1;
    }
    else {
      uVar11 = uVar11 - 1;
    }
  }
  uVar13 = -uVar11 + 0x20;
  if ((int)uVar11 < 0x21) {
    uVar12 = param_3 << (uVar13 & 0xff);
    uVar5 = param_3 >> (uVar11 & 0xff);
    uVar3 = uVar10 + uVar5;
    uVar6 = uVar8 << (uVar13 & 0xff);
    uVar13 = uVar3 + uVar6;
    uVar4 = uVar4 + CARRY4(uVar10,uVar5) + ((int)uVar8 >> (uVar11 & 0xff)) +
            (uint)CARRY4(uVar3,uVar6);
  }
  else {
    uVar12 = uVar8 << (-uVar11 + 0x40 & 0xff);
    if (param_3 != 0) {
      uVar12 = uVar12 | 2;
    }
    uVar8 = (int)uVar8 >> (uVar11 - 0x20 & 0xff);
    uVar13 = uVar10 + uVar8;
    uVar4 = uVar4 + ((int)uVar8 >> 0x1f) + (uint)CARRY4(uVar10,uVar8);
  }
  uVar8 = uVar4 & 0x80000000;
  uVar11 = uVar4;
  if ((int)uVar4 < 0) {
    bVar15 = uVar12 == 0;
    uVar12 = -uVar12;
    uVar11 = -uVar13;
    uVar13 = -(uint)!bVar15 - uVar13;
    uVar11 = -(uint)(bVar15 <= uVar11) - uVar4;
  }
  if (0xfffff < uVar11) {
    uVar10 = uVar9 - 1;
    if (0x1fffff < uVar11) {
      uVar10 = uVar11 & 1;
      uVar11 = uVar11 >> 1;
      bVar2 = (byte)uVar13;
      uVar13 = (uint)(uVar10 != 0) << 0x1f | uVar13 >> 1;
      uVar12 = (uint)(bVar2 & 1) << 0x1f | uVar12 >> 1;
      uVar10 = uVar9;
      if (0xffbfffff < uVar9 * 0x200000) goto LAB_0000d7cc;
    }
LAB_0000d698:
    bVar15 = 0x7fffffff < uVar12;
    if (uVar12 == 0x80000000) {
      bVar15 = (uVar13 & 1) != 0;
    }
    return CONCAT44(uVar11 + uVar10 * 0x100000 + (uint)CARRY4(uVar13,(uint)bVar15) | uVar8,
                    uVar13 + bVar15);
  }
  bVar14 = (uVar12 & 0x80000000) != 0;
  uVar12 = uVar12 << 1;
  uVar10 = uVar13 * 2;
  bVar15 = CARRY4(uVar13,uVar13);
  uVar13 = uVar13 * 2 + (uint)bVar14;
  uVar11 = uVar11 * 2 + (uint)(bVar15 || CARRY4(uVar10,(uint)bVar14));
  uVar10 = uVar9 - 2;
  if (uVar9 - 1 != 0 && 0xfffff < uVar11) goto LAB_0000d698;
  uVar3 = uVar13;
  uVar9 = uVar11;
  if (uVar11 == 0) {
    uVar3 = 0;
    uVar9 = uVar13;
  }
  iVar7 = LZCOUNT(uVar9);
  if (uVar11 == 0) {
    iVar7 = iVar7 + 0x20;
  }
  uVar6 = iVar7 - 0xb;
  bVar14 = SBORROW4(uVar6,0x20);
  uVar5 = iVar7 - 0x2b;
  bVar15 = uVar5 == 0;
  uVar11 = uVar5;
  uVar13 = uVar5;
  if ((int)uVar6 < 0x20) {
    bVar14 = SCARRY4(uVar5,0xc);
    uVar13 = iVar7 - 0x1f;
    bVar15 = uVar13 == 0;
    uVar11 = uVar6;
    if (!bVar15 && -0xd < (int)uVar5) {
      uVar3 = uVar9 << (uVar6 & 0xff);
      uVar9 = uVar9 >> (0xc - uVar13 & 0xff);
      goto LAB_0000d710;
    }
  }
  if (bVar15 || (int)uVar13 < 0 != bVar14) {
    uVar12 = 0x20 - uVar11;
  }
  uVar9 = uVar9 << (uVar11 & 0xff);
  if (bVar15 || (int)uVar13 < 0 != bVar14) {
    uVar9 = uVar9 | uVar3 >> (uVar12 & 0xff);
    uVar3 = uVar3 << (uVar11 & 0xff);
  }
LAB_0000d710:
  if ((int)uVar6 <= (int)uVar10) {
    return CONCAT44(uVar9 + (uVar10 - uVar6) * 0x100000 | uVar8,uVar3);
  }
  uVar11 = ~(uVar10 - uVar6);
  if ((int)uVar11 < 0x1f) {
    if (uVar11 - 0x13 != 0 && -0xd < (int)(uVar11 - 0x1f)) {
      uVar8 = 0xc - (uVar11 - 0x13);
      return CONCAT44(uVar4,uVar3 >> (0x20 - uVar8 & 0xff) | uVar9 << (uVar8 & 0xff)) &
             0x80000000ffffffff;
    }
    uVar11 = uVar11 + 1;
    return CONCAT44(uVar8 | uVar9 >> (uVar11 & 0xff),
                    uVar3 >> (uVar11 & 0xff) | uVar9 << (0x20 - uVar11 & 0xff));
  }
  return CONCAT44(uVar4,uVar9 >> (uVar11 - 0x1f & 0xff)) & 0x80000000ffffffff;
}


