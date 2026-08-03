/*
 * Function: fmod
 * Entry:    00078d74
 * Prototype: double __stdcall fmod(double param_1, double param_2)
 */


/* exclude_from_export_ai */

double fmod(double param_1,double param_2)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  float fVar9;
  double dVar10;
  longlong lVar11;
  uint extraout_s1;
  uint uVar12;
  uint uVar13;
  
  uVar12 = SUB84(param_2,0);
  uVar13 = (uint)((ulonglong)param_2 >> 0x20);
  uVar6 = (uint)((ulonglong)param_1 >> 0x20);
  uVar7 = SUB84(param_1,0);
  dVar10 = fmod(param_1,param_2);
  uVar5 = (uint)((ulonglong)dVar10 >> 0x20);
  uVar8 = SUB84(dVar10,0);
  if (DAT_20003751 == -1) {
    return dVar10;
  }
  iVar2 = __unorddf2(uVar12,uVar13,uVar12,uVar13);
  if (iVar2 != 0) {
    return dVar10;
  }
  iVar2 = __unorddf2(uVar7,uVar6,uVar7,uVar6);
  if (iVar2 == 0) {
    bVar1 = __aeabi_dcmpeq(uVar7,uVar6,0,0);
    if (!bVar1) {
      uVar4 = __isfinite();
      if (((uVar4 == 0) && (uVar4 = __isfinite(), uVar4 != 0)) && (uVar4 = __isfinite(), uVar4 != 0)
         ) {
        iVar2 = __unorddf2(uVar8,uVar5,uVar8,uVar5);
        if (iVar2 != 0) {
          piVar3 = __errno();
          *piVar3 = 0x21;
          dVar10 = (double)__divdf3(0,0,0,0);
          return dVar10;
        }
        piVar3 = __errno();
        *piVar3 = 0x22;
        bVar1 = __gedf2(uVar7,uVar6,0,0);
        if (bVar1) {
          lVar11 = ((ulonglong)uVar13 << 0x20) + ((ulonglong)param_2 & 0xffffffff);
          fVar9 = fmodf((float)lVar11,(float)((ulonglong)lVar11 >> 0x20));
          bVar1 = __aeabi_dcmpeq((uint)fVar9,extraout_s1,uVar12,uVar13);
          if (!bVar1) {
            return -INFINITY;
          }
        }
        return INFINITY;
      }
      bVar1 = __aeabi_dcmpeq(uVar8,uVar5,0,0);
      if (!bVar1) {
        return dVar10;
      }
      uVar5 = __isfinite();
      if (uVar5 != 0) {
        uVar5 = __isfinite();
        if (uVar5 != 0) {
          piVar3 = __errno();
          *piVar3 = 0x22;
          return 0.0;
        }
        return dVar10;
      }
      return dVar10;
    }
    bVar1 = __aeabi_dcmpeq(uVar12,uVar13,0,0);
    if (!bVar1) {
      uVar5 = __isfinite();
      if (uVar5 == 0) {
        return dVar10;
      }
      bVar1 = __gedf2(uVar12,uVar13,0,0);
      if (bVar1) {
        piVar3 = __errno();
        *piVar3 = 0x21;
        return -INFINITY;
      }
      return dVar10;
    }
  }
  else {
    bVar1 = __aeabi_dcmpeq(uVar12,uVar13,0,0);
    if (!bVar1) {
      return dVar10;
    }
  }
  return 1.0;
}


