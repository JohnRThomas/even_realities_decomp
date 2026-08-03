/*
 * Function: logf
 * Entry:    00079004
 * Prototype: float __stdcall logf(float param_1)
 */


/* exclude_from_export_ai */

float logf(float param_1)

{
  int *piVar1;
  float fVar2;
  
  fVar2 = __ieee754_logf(param_1);
  if ((DAT_20003751 != -1) && (param_1 <= 0.0)) {
    if (param_1 != 0.0) {
      piVar1 = __errno();
      *piVar1 = 0x21;
      return NAN;
    }
    piVar1 = __errno();
    fVar2 = -INFINITY;
    *piVar1 = 0x22;
  }
  return fVar2;
}


