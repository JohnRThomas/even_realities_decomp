/*
 * Function: ldexpf
 * Entry:    00078cb4
 * Prototype: float __stdcall ldexpf(float param_1, int param_2)
 */


/* exclude_from_export_ai */

float ldexpf(float param_1,int param_2)

{
  int iVar1;
  float fVar2;
  uint uVar3;
  
  fVar2 = ABS(param_1);
  if (fVar2 == 0.0) {
    return param_1;
  }
  if (0x7f7fffff < (uint)fVar2) {
    return param_1 + param_1;
  }
  if (((uint)param_1 & 0x7f800000) == 0) {
    param_1 = param_1 * 33554432.0;
    if (param_2 < -50000) {
      fVar2 = 1e-30;
      goto LAB_00078d0e;
    }
    uVar3 = ((uint)ABS(param_1) >> 0x17) - 0x19;
  }
  else {
    uVar3 = (uint)fVar2 >> 0x17;
  }
  iVar1 = param_2 + uVar3;
  if (iVar1 < 0xff) {
    if (0 < iVar1) {
      return (float)((uint)param_1 & 0x807fffff | iVar1 * 0x800000);
    }
    if (-0x17 < iVar1) {
      uVar3 = (uint)param_1 & 0x807fffff;
      param_1 = 2.9802322e-08;
      fVar2 = (float)(uVar3 | (iVar1 + 0x19) * 0x800000);
LAB_00078d0e:
      return fVar2 * param_1;
    }
    fVar2 = 1e-30;
    iVar1 = -0x725dbda0;
  }
  else {
    fVar2 = 1e+30;
    iVar1 = -0xeb60d36;
  }
  return (float)((uint)(-1 < (int)param_1) * (int)fVar2 + (uint)(-1 >= (int)param_1) * iVar1) *
         fVar2;
}


