/*
 * Function: expf
 * Entry:    00078f38
 * Prototype: float __stdcall expf(float param_1)
 */


/* exclude_from_export_ai */

float expf(float param_1)

{
  bool bVar1;
  int *piVar2;
  float fVar3;
  
  fVar3 = __ieee754_expf(param_1);
  if ((DAT_20003751 != -1) && (bVar1 = __isfinitef((uint)param_1), bVar1)) {
    if (param_1 <= 88.72168) {
      if ((int)((uint)(param_1 < -103.972084) << 0x1f) < 0) {
        piVar2 = __errno();
        fVar3 = 0.0;
        *piVar2 = 0x22;
      }
    }
    else {
      piVar2 = __errno();
      fVar3 = INFINITY;
      *piVar2 = 0x22;
    }
  }
  return fVar3;
}


