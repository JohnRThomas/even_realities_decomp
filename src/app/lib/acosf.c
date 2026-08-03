/*
 * Function: acosf
 * Entry:    00078ed4
 * Prototype: float __stdcall acosf(float param_1)
 */


/* exclude_from_export_ai */

float acosf(float param_1)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  
  fVar2 = asinf(param_1);
  if ((DAT_20003751 != -1) && (!NAN(param_1))) {
    fVar3 = fabsf(param_1);
    if (1.0 < fVar3) {
      piVar1 = __errno();
      *piVar1 = 0x21;
      return NAN;
    }
  }
  return fVar2;
}


