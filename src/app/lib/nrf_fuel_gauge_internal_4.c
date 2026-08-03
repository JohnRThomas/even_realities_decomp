/*
 * Function: nrf_fuel_gauge_internal_4
 * Entry:    0000eb7c
 * Prototype: float __stdcall nrf_fuel_gauge_internal_4(float param_1, float * param_2, float * param_3)
 */


/* exclude_from_export */

float nrf_fuel_gauge_internal_4(float param_1,float *param_2,float *param_3)

{
  int iVar1;
  float *pfVar2;
  float fVar3;
  float fVar4;
  float unaff_s16;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  
  fVar7 = *param_2;
  fVar8 = *param_3;
  fVar6 = param_3[2];
  fVar5 = param_2[2];
  pfVar2 = param_2;
  do {
    fVar3 = *pfVar2;
    pfVar2 = pfVar2 + 1;
    iVar1 = isnanf(fVar3);
    if (iVar1 != 0) {
      return unaff_s16;
    }
  } while (param_2 + 3 != pfVar2);
  fVar3 = param_2[1];
  if ((int)((uint)(fVar3 < *param_2) << 0x1f) < 0) {
    fVar7 = param_2[2];
    fVar8 = param_3[2];
    fVar6 = *param_3;
    fVar5 = *param_2;
  }
  fVar9 = param_3[1];
  iVar1 = isnanf(param_1);
  if (iVar1 != 0) {
    return DAT_20002d3c;
  }
  fVar4 = (fVar9 - fVar8) / (fVar3 - fVar7);
  fVar5 = ((fVar6 - fVar9) / (fVar5 - fVar3) - fVar4) / (fVar5 - fVar7);
  return fVar8 + (fVar4 + -(fVar3 - fVar7) * fVar5 + fVar5 * (param_1 - fVar7)) * (param_1 - fVar7);
}


