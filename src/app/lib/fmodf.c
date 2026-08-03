/*
 * Function: fmodf
 * Entry:    00079a70
 * Prototype: float __stdcall fmodf(float param_1, float param_2)
 */


/* exclude_from_export_ai */

float fmodf(float param_1,float param_2)

{
  int iVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  ulonglong uVar6;
  uint local_20;
  uint uStack_1c;
  
  iVar1 = (int)param_2 >> 0x1f;
  uVar3 = ((uint)ABS(param_2) >> 0x14) - 0x3ff;
  if ((int)uVar3 < 0x14) {
    if ((int)uVar3 < 0) {
      if (ABS(param_2) == 0.0 && param_1 == 0.0) {
        return param_1;
      }
      uVar3 = (uint)param_2 & 0xfffff | (uint)param_1;
      iVar1 = iVar1 * -8;
      uVar4 = *(uint *)(&DAT_0008c058 + iVar1);
      uVar5 = *(uint *)(&DAT_0008c05c + iVar1);
      uVar6 = __aeabi_dadd(uVar4,uVar5,(uint)param_1,
                           (-uVar3 | uVar3) >> 0xc & 0x80000 | (uint)param_2 & 0xfffe0000);
      local_20 = (uint)uVar6;
      uStack_1c = (uint)(uVar6 >> 0x20);
      uVar6 = __subdf(local_20,uStack_1c,uVar4,uVar5);
      return (float)uVar6;
    }
    uVar4 = 0xfffff >> (uVar3 & 0xff);
    if ((uVar4 & (uint)param_2) == 0 && param_1 == 0.0) {
      return param_1;
    }
    bVar2 = param_1 != 0.0;
    param_1 = 0.0;
    if (bVar2 || ((uint)param_2 & uVar4 >> 1) != 0) {
      param_2 = (float)(0x40000 >> (uVar3 & 0xff) | (uint)param_2 & ~(uVar4 >> 1));
      param_1 = (float)((uint)(uVar3 == 0x13) * -0x80000000);
    }
  }
  else {
    if (0x33 < (int)uVar3) {
      if (uVar3 != 0x400) {
        return param_1;
      }
      uVar6 = __aeabi_dadd((uint)param_1,(uint)param_2,(uint)param_1,(uint)param_2);
      return (float)uVar6;
    }
    uVar4 = ((uint)ABS(param_2) >> 0x14) - 0x413;
    uVar3 = 0xffffffff >> (uVar4 & 0xff);
    if (((uint)param_1 & uVar3) == 0) {
      return param_1;
    }
    if (((uint)param_1 & uVar3 >> 1) != 0) {
      param_1 = (float)(0x40000000 >> (uVar4 & 0xff) | (uint)param_1 & ~(uVar3 >> 1));
    }
  }
  iVar1 = iVar1 * -8;
  uVar3 = *(uint *)(&DAT_0008c058 + iVar1);
  uVar4 = *(uint *)(&DAT_0008c05c + iVar1);
  uVar6 = __aeabi_dadd(uVar3,uVar4,(uint)param_1,(uint)param_2);
  local_20 = (uint)uVar6;
  uStack_1c = (uint)(uVar6 >> 0x20);
  uVar6 = __subdf(local_20,uStack_1c,uVar3,uVar4);
  return (float)uVar6;
}


