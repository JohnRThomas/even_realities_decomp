/*
 * Function: ceilf
 * Entry:    0008a0ac
 * Prototype: float __stdcall ceilf(float param_1)
 */


/* exclude_from_export_ai */

float ceilf(float param_1)

{
  float fVar1;
  
  fVar1 = (float)FPRoundInt(param_1,0x20,2,0);
  return fVar1;
}


