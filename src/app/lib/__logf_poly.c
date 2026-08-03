/*
 * Function: __logf_poly
 * Entry:    000797e0
 * Prototype: float __stdcall __logf_poly(float param_1)
 */


/* exclude_from_export_ai */

float __logf_poly(float param_1)

{
  int iVar1;
  uint uVar2;
  uint in_fpscr;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  
  if (ABS(param_1) == 0.0) {
    fVar4 = -33554432.0;
  }
  else {
    if (-1 < (int)param_1) {
      if (0x7f7fffff < (int)param_1) {
        return param_1 + param_1;
      }
      if ((int)param_1 < 0x800000) {
        iVar1 = -0x19;
        param_1 = param_1 * 33554432.0;
      }
      else {
        iVar1 = 0;
      }
      uVar2 = (uint)param_1 & 0x7fffff;
      iVar1 = ((int)param_1 >> 0x17) + -0x7f + iVar1 + (uVar2 + 0x4afb20 >> 0x17);
      fVar4 = (float)(uVar2 + 0x4afb20 & 0x800000 ^ 0x3f800000 | uVar2) - 1.0;
      if ((uVar2 + 0xf & 0x7ffff0) != 0) {
        fVar7 = fVar4 / (fVar4 + 2.0);
        fVar3 = (float)VectorSignedToFloat(iVar1,(byte)(in_fpscr >> 0x16) & 3);
        fVar5 = fVar7 * fVar7;
        fVar6 = fVar5 * fVar5;
        fVar6 = (((fVar6 * 0.14798199 + 0.18183573) * fVar6 + 0.2857143) * fVar6 + 0.6666667) *
                fVar5 + ((fVar6 * 0.15313838 + 0.22222199) * fVar6 + 0.4) * fVar6;
        if ((int)(0x35c288 - uVar2 | uVar2 - 0x30a3d0) < 1) {
          fVar7 = (fVar4 - fVar6) * fVar7;
          if (iVar1 == 0) {
            return fVar4 - fVar7;
          }
          fVar5 = fVar7 + -fVar3 * 9.058001e-06;
        }
        else {
          fVar5 = fVar4 * 0.5 * fVar4;
          fVar7 = (fVar6 + fVar5) * fVar7;
          if (iVar1 == 0) {
            fVar5 = fVar5 - fVar7;
            goto LAB_0007989c;
          }
          fVar5 = fVar5 - (fVar7 + fVar3 * 9.058001e-06);
        }
        return -(fVar5 - fVar4) + fVar3 * 0.6931381;
      }
      if (fVar4 == 0.0) {
        if (iVar1 == 0) {
          return 0.0;
        }
        fVar4 = (float)VectorSignedToFloat(iVar1,(byte)((in_fpscr & 0xfffffff) >> 0x16) & 3);
        return fVar4 * 9.058001e-06 + fVar4 * 0.6931381;
      }
      fVar5 = fVar4 * fVar4 * (-fVar4 * 0.33333334 + 0.5);
      if (iVar1 != 0) {
        fVar7 = (float)VectorSignedToFloat(iVar1,(byte)((in_fpscr & 0xfffffff) >> 0x16) & 3);
        return -((fVar5 + -fVar7 * 9.058001e-06) - fVar4) + fVar7 * 0.6931381;
      }
LAB_0007989c:
      return fVar4 - fVar5;
    }
    fVar4 = param_1 - param_1;
  }
  return fVar4 / 0.0;
}


