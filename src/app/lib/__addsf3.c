/*
 * Function: __addsf3
 * Entry:    0000df94
 * Prototype: uint __stdcall __addsf3(uint param_1, uint param_2, undefined4 param_3, uint param_4)
 */


/* exclude_from_export_ai */

uint __addsf3(uint param_1,uint param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  bool bVar8;
  
  uVar3 = param_1 << 1;
  bVar8 = uVar3 == 0;
  if (!bVar8) {
    param_4 = param_2 << 1;
    bVar8 = param_4 == 0;
  }
  if (!bVar8) {
    bVar8 = uVar3 == param_4;
  }
  iVar1 = (int)uVar3 >> 0x18;
  if (!bVar8) {
    bVar8 = iVar1 == -1;
  }
  if (!bVar8) {
    bVar8 = (int)param_4 >> 0x18 == -1;
  }
  if (bVar8) {
    iVar2 = (int)(param_2 << 1) >> 0x18;
    if (iVar1 == -1 || iVar2 == -1) {
      uVar3 = param_2;
      if (iVar1 == -1) {
        uVar3 = param_1;
      }
      if (iVar1 != -1 || iVar2 != -1) {
        param_2 = uVar3;
      }
      if (((uVar3 & 0x7fffff) != 0 || (param_2 & 0x7fffff) != 0) || uVar3 != param_2) {
        uVar3 = uVar3 | 0x400000;
      }
      return uVar3;
    }
    if (((param_1 ^ param_2) & 0x7fffffff) != 0) {
      if (uVar3 == 0) {
        param_1 = param_2;
      }
      return param_1;
    }
    if (param_1 != param_2) {
      return 0;
    }
    if ((uVar3 & 0xff000000) == 0) {
      uVar3 = param_1 << 1;
      if ((param_1 & 0x80000000) != 0) {
        uVar3 = uVar3 | 0x80000000;
      }
      return uVar3;
    }
    if (uVar3 < 0xfe000000) {
      return param_1 + 0x800000;
    }
    uVar7 = param_1 & 0x80000000;
LAB_0000e0ca:
    return uVar7 | 0x7f800000;
  }
  uVar4 = (param_1 & 0x7fffffff) >> 0x17;
  uVar3 = param_4 >> 0x18;
  uVar7 = uVar3 - uVar4;
  uVar6 = param_2;
  uVar5 = uVar4;
  if (uVar7 != 0 && uVar4 <= uVar3) {
    uVar5 = uVar4 + uVar7;
    uVar6 = param_1;
    param_1 = param_2;
  }
  if (uVar3 < uVar4) {
    uVar7 = -uVar7;
  }
  if (0x19 < uVar7) {
    return param_1;
  }
  uVar3 = param_1 & 0xffffff | 0x800000;
  if ((param_1 & 0x80000000) != 0) {
    uVar3 = -uVar3;
  }
  uVar4 = uVar6 & 0xffffff | 0x800000;
  if ((uVar6 & 0x80000000) != 0) {
    uVar4 = -uVar4;
  }
  if (uVar5 == uVar7) {
    uVar4 = uVar4 ^ 0x800000;
    if (uVar5 == 0) {
      uVar3 = uVar3 ^ 0x800000;
      uVar5 = 1;
    }
    else {
      uVar7 = uVar7 - 1;
    }
  }
  uVar3 = uVar3 + ((int)uVar4 >> (uVar7 & 0xff));
  uVar4 = uVar4 << (0x20 - uVar7 & 0xff);
  uVar7 = uVar3 & 0x80000000;
  if ((int)uVar3 < 0) {
    bVar8 = uVar4 != 0;
    uVar4 = -uVar4;
    uVar3 = -uVar3 - (uint)bVar8;
  }
  if (uVar3 < 0x800000) {
    uVar6 = uVar4 & 0x80000000;
    uVar4 = uVar4 << 1;
    uVar3 = uVar3 * 2 + (uint)(uVar6 != 0);
    uVar6 = uVar5 - 2;
    if (uVar5 - 1 == 0 || uVar3 < 0x800000) {
      uVar5 = LZCOUNT(uVar3) - 8;
      uVar3 = uVar3 << (uVar5 & 0xff);
      if ((int)uVar6 < (int)uVar5) {
        uVar3 = uVar3 >> (-(uVar6 - uVar5) & 0xff);
      }
      else {
        uVar3 = uVar3 + (uVar6 - uVar5) * 0x800000;
      }
      return uVar3 | uVar7;
    }
  }
  else {
    uVar6 = uVar5 - 1;
    if (0xffffff < uVar3) {
      uVar6 = uVar3 & 1;
      uVar3 = uVar3 >> 1;
      uVar4 = (uint)(uVar6 != 0) << 0x1f | uVar4 >> 1;
      uVar6 = uVar5;
      if (0xfd < uVar5) goto LAB_0000e0ca;
    }
  }
  uVar3 = uVar3 + uVar6 * 0x800000 + (uint)(0x7fffffff < uVar4);
  if (uVar4 == 0x80000000) {
    uVar3 = uVar3 & 0xfffffffe;
  }
  return uVar3 | uVar7;
}


