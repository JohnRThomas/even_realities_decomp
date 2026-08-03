/*
 * Function: nrf_fuel_gauge_internal_6
 * Entry:    0000e9b4
 * Prototype: float __stdcall nrf_fuel_gauge_internal_6(float * param_1)
 */


/* exclude_from_export */

float nrf_fuel_gauge_internal_6(float *param_1)

{
  int iVar1;
  float *pfVar2;
  float fVar3;
  float fVar4;
  
  iVar1 = isnanf(*param_1);
  if (iVar1 == 0) {
    fVar3 = *param_1;
    iVar1 = 2;
  }
  else {
    iVar1 = isnanf(param_1[1]);
    if (iVar1 != 0) {
      iVar1 = isnanf(param_1[2]);
      if (iVar1 == 0) {
        return param_1[2];
      }
      return *param_1;
    }
    fVar3 = param_1[1];
    iVar1 = 3;
  }
  pfVar2 = param_1 + iVar1 + 0x3fffffff;
  while( true ) {
    fVar4 = *pfVar2;
    pfVar2 = pfVar2 + 1;
    if ((int)((uint)(fVar4 < fVar3) << 0x1f) < 0) {
      fVar3 = fVar4;
    }
    if (iVar1 != 2) break;
    iVar1 = 3;
  }
  return fVar3;
}


