/*
 * Function: atan2f
 * Entry:    000793fc
 * Prototype: float __stdcall atan2f(float param_1, float param_2)
 */


/* exclude_from_export_ai */

float atan2f(float param_1,float param_2)

{
  float fVar1;
  float fVar2;
  undefined *puVar3;
  uint uVar4;
  
  fVar1 = ABS(param_2);
  if (((uint)fVar1 < 0x7f800001) && (fVar2 = ABS(param_1), (uint)fVar2 < 0x7f800001)) {
    if (param_2 == 1.0) {
      fVar1 = atanf(param_1);
      return fVar1;
    }
    uVar4 = (int)param_2 >> 0x1e & 2U | (uint)param_1 >> 0x1f;
    if (fVar2 == 0.0) {
      if (uVar4 == 2) {
        fVar1 = 3.1415927;
      }
      else {
        fVar1 = (float)((uint)(uVar4 == 3) * -0x3fb6f025 + (uint)(uVar4 != 3) * (int)param_1);
      }
    }
    else {
      if (fVar1 != 0.0) {
        if (fVar1 == INFINITY) {
          uVar4 = uVar4 - 1;
          if (fVar2 == INFINITY) {
            if (2 < uVar4) {
              return 0.7853982;
            }
            puVar3 = &DAT_0009c220;
          }
          else {
            if (2 < uVar4) {
              return 0.0;
            }
            puVar3 = &DAT_0009c214;
          }
          return *(float *)(puVar3 + uVar4 * 4);
        }
        if (fVar2 != INFINITY) {
          if ((int)fVar2 - (int)fVar1 < 0x1e800000) {
            if (((int)param_2 < 0) && ((int)fVar2 - (int)fVar1 >> 0x17 < -0x3c)) {
              fVar1 = 0.0;
            }
            else {
              fVar1 = fabsf(param_1 / param_2);
              fVar1 = atanf(fVar1);
            }
          }
          else {
            fVar1 = 1.5707964;
          }
          if (uVar4 == 1) {
            return (float)((int)fVar1 + -0x80000000);
          }
          if (uVar4 == 2) {
            return 3.1415927 - (fVar1 + 8.742278e-08);
          }
          if (uVar4 == 0) {
            return fVar1;
          }
          return (fVar1 + 8.742278e-08) - 3.1415927;
        }
      }
      fVar1 = (float)((uint)(-1 < (int)param_1) * 0x3fc90fdb +
                     (uint)(-1 >= (int)param_1) * -0x4036f025);
    }
  }
  else {
    fVar1 = param_1 + param_2;
  }
  return fVar1;
}


