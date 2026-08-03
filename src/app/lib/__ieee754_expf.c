/*
 * Function: __ieee754_expf
 * Entry:    00079538
 * Prototype: float __stdcall __ieee754_expf(float param_1)
 */


/* exclude_from_export_ai */

float __ieee754_expf(float param_1)

{
  int iVar1;
  int iVar2;
  undefined *puVar3;
  uint in_fpscr;
  float fVar4;
  float in_s14;
  float in_s15;
  
  puVar3 = (undefined *)((uint)param_1 & 0x7fffffff);
  if ((undefined *)0x7f800000 < puVar3) {
    return param_1 + param_1;
  }
  if (puVar3 == (undefined *)0x7f800000) {
    return (float)((uint)(-1 < (int)param_1) * (int)param_1);
  }
  if (0x42b17217 < (int)param_1) {
    return INFINITY;
  }
  if (((int)param_1 < 0) && ((undefined *)0x42cff1b5 < puVar3)) {
    return 0.0;
  }
  if (puVar3 < (undefined *)0x3eb17219) {
    if ((puVar3 < &DAT_31800000) && (1.0 < param_1 + 1e+30)) {
      return param_1 + 1.0;
    }
    iVar2 = 0;
  }
  else {
    iVar1 = ((int)param_1 >> 0x1f) * -4;
    if (puVar3 < (undefined *)0x3f851592) {
      in_s14 = param_1 - *(float *)(&DAT_0009c234 + iVar1);
      iVar2 = ((int)param_1 >> 0x1f) * 2 + 1;
      in_s15 = *(float *)(&DAT_0009c22c + iVar1);
    }
    else {
      iVar2 = (int)(*(float *)(&DAT_0009c23c + iVar1) + param_1 * 1.442695);
      fVar4 = (float)VectorSignedToFloat(iVar2,(byte)(in_fpscr >> 0x16) & 3);
      in_s14 = param_1 + -fVar4 * 0.6931381;
      in_s15 = fVar4 * 9.058001e-06;
    }
    param_1 = in_s14 - in_s15;
  }
  fVar4 = param_1 * param_1;
  fVar4 = param_1 + -((((fVar4 * 4.138137e-08 + -1.6533902e-06) * fVar4 + 6.613756e-05) * fVar4 +
                      -0.0027777778) * fVar4 + 0.16666667) * fVar4;
  if (iVar2 != 0) {
    iVar1 = iVar2;
    if (iVar2 < -0x7d) {
      iVar1 = iVar2 + 100;
    }
    fVar4 = 1.0 - ((in_s15 - (param_1 * fVar4) / (2.0 - fVar4)) - in_s14);
    if (iVar2 < -0x7d) {
      fVar4 = (float)((int)fVar4 + iVar1 * 0x800000) * 7.888609e-31;
    }
    else {
      fVar4 = (float)((int)fVar4 + iVar1 * 0x800000);
    }
    return fVar4;
  }
  return 1.0 - ((param_1 * fVar4) / (fVar4 - 2.0) - param_1);
}


