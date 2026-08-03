/*
 * Function: fmaxf
 * Entry:    0008a0b2
 * Prototype: float __stdcall fmaxf(float param_1, float param_2)
 */


/* exclude_from_export_ai */

float fmaxf(float param_1,float param_2)

{
  bool bVar1;
  
  bVar1 = __isnormalf((uint)param_1);
  if ((!bVar1) || ((bVar1 = __isnormalf((uint)param_2), bVar1 && (param_1 <= param_2)))) {
    param_1 = param_2;
  }
  return param_1;
}


