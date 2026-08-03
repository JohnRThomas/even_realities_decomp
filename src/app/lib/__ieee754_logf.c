/*
 * Function: __ieee754_logf
 * Entry:    000799c0
 * Prototype: float __stdcall __ieee754_logf(float param_1)
 */


/* exclude_from_export_ai */

float __ieee754_logf(float param_1)

{
  int iVar1;
  int iVar2;
  uint in_fpscr;
  float fVar3;
  float fVar4;
  
  if (ABS(param_1) == 0.0) {
    fVar3 = -33554432.0;
  }
  else {
    if (-1 < (int)param_1) {
      if (0x7f7fffff < (int)param_1) {
        return param_1 + param_1;
      }
      if ((int)param_1 < 0x800000) {
        iVar2 = -0x19;
        param_1 = param_1 * 33554432.0;
      }
      else {
        iVar2 = 0;
      }
      iVar2 = ((int)param_1 >> 0x17) + -0x7f + iVar2;
      iVar1 = iVar2 >> 0x1f;
      fVar4 = (float)VectorSignedToFloat(iVar2 - iVar1,(byte)(in_fpscr >> 0x16) & 3);
      fVar3 = __logf_poly((float)((uint)param_1 & 0x7fffff | (iVar1 + 0x7f) * 0x800000));
      return fVar3 * 0.4342945 + fVar4 * 7.903415e-07 + fVar4 * 0.3010292;
    }
    fVar3 = param_1 - param_1;
  }
  return fVar3 / 0.0;
}


