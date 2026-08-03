/*
 * Function: fminf
 * Entry:    0008a0ec
 * Prototype: float __stdcall fminf(float param_1, float param_2)
 */


/* exclude_from_export_ai */

float fminf(float param_1,float param_2)

{
  bool bVar1;
  
  bVar1 = __isnormalf((uint)param_1);
  if ((!bVar1) ||
     ((bVar1 = __isnormalf((uint)param_2), bVar1 && (-1 < (int)((uint)(param_1 < param_2) << 0x1f)))
     )) {
    param_1 = param_2;
  }
  return param_1;
}


