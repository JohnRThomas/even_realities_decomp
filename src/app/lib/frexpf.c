/*
 * Function: frexpf
 * Entry:    00078c60
 * Prototype: float __stdcall frexpf(float x, int * exp)
 */


/* exclude_from_export_ai */

float frexpf(float x,int *exp)

{
  float fVar1;
  
  fVar1 = ABS(x);
  *exp = 0;
  if ((int)fVar1 - 1U < 0x7f7fffff) {
    if (((uint)x & 0x7f800000) == 0) {
      x = x * 33554432.0;
      *exp = -0x19;
      fVar1 = ABS(x);
    }
    x = (float)((uint)x & 0x807fffff | 0x3f000000);
    *exp = *exp + ((int)fVar1 >> 0x17) + -0x7e;
  }
  return x;
}


