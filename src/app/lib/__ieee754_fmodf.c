/*
 * Function: __ieee754_fmodf
 * Entry:    000796d8
 * Prototype: float __stdcall __ieee754_fmodf(float param_1, float param_2)
 */


/* exclude_from_export_ai */

float __ieee754_fmodf(float param_1,float param_2)

{
  float fVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  float fVar9;
  int iVar10;
  
  fVar1 = ABS(param_2);
  if (((int)fVar1 - 1U < 0x7f800000) && (fVar9 = ABS(param_1), (uint)fVar9 < 0x7f800000)) {
    if ((uint)fVar1 <= (uint)fVar9) {
      uVar7 = (uint)param_1 & 0x80000000;
      if (fVar9 != fVar1) {
        if (((uint)param_1 & 0x7f800000) == 0) {
          iVar3 = -0x7e;
          for (iVar4 = (int)param_1 << 8; 0 < iVar4; iVar4 = iVar4 << 1) {
            iVar3 = iVar3 + -1;
          }
        }
        else {
          iVar3 = ((int)fVar9 >> 0x17) + -0x7f;
        }
        if (((uint)param_2 & 0x7f800000) == 0) {
          iVar4 = -0x7e;
          for (iVar10 = (int)param_2 << 8; -1 < iVar10; iVar10 = iVar10 << 1) {
            iVar4 = iVar4 + -1;
          }
        }
        else {
          iVar4 = ((int)fVar1 >> 0x17) + -0x7f;
        }
        if (iVar3 < -0x7e) {
          uVar5 = -iVar3 - 0x7e;
        }
        else {
          uVar5 = (uint)param_1 & 0x7fffff | 0x800000;
        }
        iVar10 = iVar3 - iVar4;
        if (iVar3 < -0x7e) {
          uVar5 = (int)fVar9 << (uVar5 & 0xff);
        }
        if (iVar4 < -0x7e) {
          uVar2 = (int)fVar1 << (-iVar4 - 0x7eU & 0xff);
        }
        else {
          uVar2 = (uint)param_2 & 0x7fffff | 0x800000;
        }
        while( true ) {
          uVar8 = uVar5 - uVar2;
          if (iVar10 == 0) break;
          if ((-1 < (int)uVar8) && (uVar5 = uVar8, uVar8 == 0)) goto LAB_0007970c;
          uVar5 = uVar5 << 1;
          iVar10 = iVar10 + -1;
        }
        uVar6 = uVar5 & (int)uVar8 >> 0x20;
        if (uVar5 < uVar2) {
          uVar6 = uVar8;
        }
        if (uVar6 != 0) {
          for (; (int)uVar6 < 0x800000; uVar6 = uVar6 << 1) {
            iVar4 = iVar4 + -1;
          }
          if (-0x7f < iVar4) {
            return (float)(uVar6 - 0x800000 | uVar7 | (iVar4 + 0x7f) * 0x800000);
          }
          return (float)((int)uVar6 >> (0xffffff82U - iVar4 & 0xff) | uVar7);
        }
      }
LAB_0007970c:
      param_1 = *(float *)(&DAT_0009c244 + (uVar7 >> 0x1d));
    }
  }
  else {
    param_1 = (param_1 * param_2) / (param_1 * param_2);
  }
  return param_1;
}


