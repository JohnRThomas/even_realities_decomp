/*
 * Function: FUN_01026538
 * Entry:    01026538
 * Prototype: undefined8 __stdcall FUN_01026538(uint param_1, uint param_2, uint param_3, uint param_4, uint * param_5)
 */


/* WARNING: Removing unreachable block (ram,0x0102679e) */

undefined8 FUN_01026538(uint param_1,uint param_2,uint param_3,uint param_4,uint *param_5)

{
  ulonglong uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  bool bVar13;
  
  if (param_4 == 0) {
    iVar3 = LZCOUNT(param_3);
    if (param_2 < param_3) {
      uVar6 = param_1;
      if (iVar3 != 0) {
        param_3 = param_3 << iVar3;
        uVar6 = param_1 << iVar3;
        param_2 = param_1 >> (0x20U - iVar3 & 0xff) | param_2 << iVar3;
      }
      uVar11 = param_3 >> 0x10;
      uVar7 = param_2 / uVar11;
      uVar8 = uVar7 * (param_3 & 0xffff);
      uVar4 = uVar6 >> 0x10 | (param_2 - uVar11 * uVar7) * 0x10000;
      uVar5 = uVar7;
      if (uVar4 <= uVar8 && uVar8 - uVar4 != 0) {
        bVar13 = CARRY4(param_3,uVar4);
        uVar4 = param_3 + uVar4;
        uVar5 = uVar7 - 1;
        if ((!bVar13) && (uVar4 <= uVar8 && uVar8 - uVar4 != 0)) {
          uVar4 = uVar4 + param_3;
          uVar5 = uVar7 - 2;
        }
      }
      uVar9 = (uVar4 - uVar8) / uVar11;
      uVar2 = uVar9 * (param_3 & 0xffff);
      uVar7 = uVar6 & 0xffff | ((uVar4 - uVar8) - uVar11 * uVar9) * 0x10000;
      uVar4 = uVar9;
      if (uVar7 <= uVar2 && uVar2 - uVar7 != 0) {
        bVar13 = CARRY4(param_3,uVar7);
        uVar7 = param_3 + uVar7;
        uVar4 = uVar9 - 1;
        if ((!bVar13) && (uVar7 <= uVar2 && uVar2 - uVar7 != 0)) {
          uVar7 = uVar7 + param_3;
          uVar4 = uVar9 - 2;
        }
      }
      uVar7 = uVar7 - uVar2;
      uVar4 = uVar4 | uVar5 << 0x10;
      uVar6 = 0;
    }
    else {
      if (iVar3 == 0) {
        uVar5 = param_2 - param_3;
        uVar6 = 1;
        uVar7 = param_1;
      }
      else {
        param_3 = param_3 << iVar3;
        uVar7 = param_1 << iVar3;
        uVar6 = param_2 >> (0x20U - iVar3 & 0xff);
        uVar2 = param_3 >> 0x10;
        uVar5 = param_1 >> (0x20U - iVar3 & 0xff) | param_2 << iVar3;
        uVar11 = uVar6 / uVar2;
        uVar8 = uVar11 * (param_3 & 0xffff);
        uVar6 = uVar5 >> 0x10 | (uVar6 - uVar2 * uVar11) * 0x10000;
        uVar4 = uVar11;
        if (uVar6 <= uVar8 && uVar8 - uVar6 != 0) {
          bVar13 = CARRY4(param_3,uVar6);
          uVar6 = param_3 + uVar6;
          uVar4 = uVar11 - 1;
          if ((!bVar13) && (uVar6 <= uVar8 && uVar8 - uVar6 != 0)) {
            uVar6 = uVar6 + param_3;
            uVar4 = uVar11 - 2;
          }
        }
        uVar9 = (uVar6 - uVar8) / uVar2;
        uVar11 = uVar9 * (param_3 & 0xffff);
        uVar5 = uVar5 & 0xffff | ((uVar6 - uVar8) - uVar2 * uVar9) * 0x10000;
        uVar6 = uVar9;
        if (uVar5 <= uVar11 && uVar11 - uVar5 != 0) {
          bVar13 = CARRY4(param_3,uVar5);
          uVar5 = param_3 + uVar5;
          uVar6 = uVar9 - 1;
          if ((!bVar13) && (uVar5 <= uVar11 && uVar11 - uVar5 != 0)) {
            uVar5 = uVar5 + param_3;
            uVar6 = uVar9 - 2;
          }
        }
        uVar5 = uVar5 - uVar11;
        uVar6 = uVar6 | uVar4 << 0x10;
      }
      uVar2 = param_3 >> 0x10;
      uVar11 = uVar5 / uVar2;
      uVar8 = uVar11 * (param_3 & 0xffff);
      uVar4 = uVar7 >> 0x10 | (uVar5 - uVar2 * uVar11) * 0x10000;
      uVar5 = uVar11;
      if (uVar4 <= uVar8 && uVar8 - uVar4 != 0) {
        bVar13 = CARRY4(param_3,uVar4);
        uVar4 = param_3 + uVar4;
        uVar5 = uVar11 - 1;
        if ((!bVar13) && (uVar4 <= uVar8 && uVar8 - uVar4 != 0)) {
          uVar4 = uVar4 + param_3;
          uVar5 = uVar11 - 2;
        }
      }
      uVar9 = (uVar4 - uVar8) / uVar2;
      uVar11 = uVar9 * (param_3 & 0xffff);
      uVar7 = uVar7 & 0xffff | ((uVar4 - uVar8) - uVar2 * uVar9) * 0x10000;
      uVar4 = uVar9;
      if (uVar7 <= uVar11 && uVar11 - uVar7 != 0) {
        bVar13 = CARRY4(param_3,uVar7);
        uVar7 = param_3 + uVar7;
        uVar4 = uVar9 - 1;
        if ((!bVar13) && (uVar7 <= uVar11 && uVar11 - uVar7 != 0)) {
          uVar7 = uVar7 + param_3;
          uVar4 = uVar9 - 2;
        }
      }
      uVar7 = uVar7 - uVar11;
      uVar4 = uVar4 | uVar5 << 0x10;
    }
    if (param_5 != (uint *)0x0) {
      *param_5 = uVar7 >> iVar3;
      param_5[1] = 0;
    }
  }
  else if (param_2 < param_4) {
    if (param_5 != (uint *)0x0) {
      *param_5 = param_1;
      param_5[1] = param_2;
    }
    uVar4 = 0;
    uVar6 = uVar4;
  }
  else {
    iVar3 = LZCOUNT(param_4);
    if (iVar3 == 0) {
      if ((param_4 < param_2) || (param_3 <= param_1)) {
        bVar13 = param_1 < param_3;
        param_1 = param_1 - param_3;
        param_2 = (param_2 - param_4) - (uint)bVar13;
        uVar4 = 1;
      }
      else {
        uVar4 = 0;
      }
      if (param_5 != (uint *)0x0) {
        *param_5 = param_1;
        param_5[1] = param_2;
      }
    }
    else {
      uVar10 = 0x20 - iVar3;
      uVar8 = param_1 << iVar3;
      uVar5 = param_3 >> (uVar10 & 0xff) | param_4 << iVar3;
      uVar6 = param_2 >> (uVar10 & 0xff);
      uVar2 = uVar5 >> 0x10;
      uVar4 = param_1 >> (uVar10 & 0xff) | param_2 << iVar3;
      uVar11 = uVar6 / uVar2;
      uVar9 = uVar11 * (uVar5 & 0xffff);
      uVar7 = uVar4 >> 0x10 | (uVar6 - uVar2 * uVar11) * 0x10000;
      uVar6 = uVar11;
      if (uVar7 <= uVar9 && uVar9 - uVar7 != 0) {
        bVar13 = CARRY4(uVar5,uVar7);
        uVar7 = uVar5 + uVar7;
        uVar6 = uVar11 - 1;
        if ((!bVar13) && (uVar7 <= uVar9 && uVar9 - uVar7 != 0)) {
          uVar7 = uVar7 + uVar5;
          uVar6 = uVar11 - 2;
        }
      }
      uVar11 = (uVar7 - uVar9) / uVar2;
      uVar12 = uVar11 * (uVar5 & 0xffff);
      uVar7 = uVar4 & 0xffff | ((uVar7 - uVar9) - uVar2 * uVar11) * 0x10000;
      uVar4 = uVar11;
      if (uVar7 <= uVar12 && uVar12 - uVar7 != 0) {
        bVar13 = CARRY4(uVar5,uVar7);
        uVar7 = uVar5 + uVar7;
        uVar4 = uVar11 - 1;
        if ((!bVar13) && (uVar7 <= uVar12 && uVar12 - uVar7 != 0)) {
          uVar7 = uVar7 + uVar5;
          uVar4 = uVar11 - 2;
        }
      }
      uVar4 = uVar4 | uVar6 << 0x10;
      uVar1 = (ulonglong)uVar4 * (ulonglong)(param_3 << iVar3);
      if (CONCAT44(uVar7 - uVar12,uVar8) < uVar1) {
        uVar4 = uVar4 - 1;
        uVar1 = uVar1 - CONCAT44(uVar5,param_3 << iVar3);
      }
      if (param_5 != (uint *)0x0) {
        uVar6 = ((uVar7 - uVar12) - (int)(uVar1 >> 0x20)) - (uint)(uVar8 < (uint)uVar1);
        *param_5 = uVar6 << (uVar10 & 0xff) | uVar8 - (uint)uVar1 >> iVar3;
        param_5[1] = uVar6 >> iVar3;
      }
    }
    uVar6 = 0;
  }
  return CONCAT44(uVar6,uVar4);
}


