/*
 * Function: nrf_fuel_gauge_internal_2
 * Entry:    0000e3a0
 * Prototype: int __stdcall nrf_fuel_gauge_internal_2(float param_1, float param_2, float * param_3, float * param_4, float * param_5, int param_6)
 */


/* exclude_from_export */

int nrf_fuel_gauge_internal_2
              (float param_1,float param_2,float *param_3,float *param_4,float *param_5,int param_6)

{
  int iVar1;
  int iVar2;
  char cVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  
  fVar4 = *param_3;
  fVar5 = param_3[200];
  fVar6 = param_3[1] - fVar4;
  if (fVar4 < param_1) {
    iVar1 = (uint)(fVar4 < param_1) << 0x1f;
    cVar3 = (char)((uint)iVar1 >> 0x18);
    if (param_1 >= fVar5) goto LAB_0000e3de;
    if ((-1 < iVar1) || (-1 < (int)((uint)(param_1 < fVar5) << 0x1f))) {
      fVar5 = 0.0;
      goto LAB_0000e49c;
    }
  }
  else {
    iVar1 = (uint)(fVar4 < param_1) << 0x1f;
    cVar3 = (char)((uint)iVar1 >> 0x18);
    if (param_1 < fVar5) {
      if (iVar1 < 0) {
        iVar1 = (uint)(param_1 < fVar5) << 0x1f;
        if (iVar1 < 0) {
          param_6 = 1;
        }
        if (-1 < iVar1) {
          param_6 = 0;
        }
      }
      else {
        param_6 = 0;
      }
      fVar5 = ((param_1 - fVar4) *
              ((param_4[1] + param_5[1] * param_2) - (*param_4 + *param_5 * param_2))) / fVar6 +
              *param_4 + *param_5 * param_2;
    }
    else {
LAB_0000e3de:
      if (cVar3 < '\0') {
        iVar1 = (uint)(param_1 < fVar5) << 0x1f;
        if (iVar1 < 0) {
          param_6 = 1;
        }
        if (-1 < iVar1) {
          param_6 = 0;
        }
      }
      else {
        param_6 = 0;
      }
      fVar5 = (((param_4[200] + param_5[200] * param_2) - (param_4[199] + param_5[199] * param_2)) *
              (param_1 - fVar5)) / fVar6 + param_4[200] + param_5[200] * param_2;
    }
    if (param_6 == 0) goto LAB_0000e49c;
  }
  fVar4 = ceilf((param_1 - fVar4) / fVar6);
  iVar2 = (int)(fVar4 + 2.0) + 0x3fffffff;
  iVar1 = (int)(fVar4 + 1.0) + 0x3fffffff;
  fVar4 = (param_1 - *param_3) / fVar6 - fVar4;
  fVar5 = fVar4 * param_4[iVar2] + param_4[iVar1] * (1.0 - fVar4) +
          param_2 * (fVar4 * param_5[iVar2] + param_5[iVar1] * (1.0 - fVar4));
LAB_0000e49c:
  iVar1 = isnanf(param_1);
  return (uint)(iVar1 == 0) * (int)fVar5;
}


