/*
 * Function: nrf_fuel_gauge_internal_1
 * Entry:    0000ea70
 * Prototype: undefined __stdcall nrf_fuel_gauge_internal_1(float param_1, float * param_2, undefined4 * param_3, float * param_4)
 */


/* exclude_from_export */

void nrf_fuel_gauge_internal_1(float param_1,float *param_2,undefined4 *param_3,float *param_4)

{
  int iVar1;
  undefined4 *puVar2;
  float *pfVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float local_58 [4];
  float local_48;
  float local_44;
  undefined4 *puVar3;
  
  puVar2 = param_3;
  pfVar4 = local_58;
  do {
    puVar3 = puVar2 + 1;
    *pfVar4 = (float)*puVar2;
    puVar2 = puVar3;
    pfVar4 = pfVar4 + 1;
  } while (param_3 + 6 != puVar3);
  fVar14 = *param_2;
  fVar13 = param_2[2];
  pfVar4 = param_2;
  do {
    fVar5 = *pfVar4;
    pfVar4 = pfVar4 + 1;
    iVar1 = isnanf(fVar5);
    if (iVar1 != 0) {
      return;
    }
  } while (param_2 + 3 != pfVar4);
  fVar11 = param_2[1];
  fVar5 = local_58[0];
  fVar10 = local_58[3];
  fVar12 = local_44;
  fVar6 = local_58[2];
  if ((int)((uint)(fVar11 < *param_2) << 0x1f) < 0) {
    fVar14 = param_2[2];
    fVar13 = *param_2;
    fVar5 = local_58[2];
    fVar10 = local_44;
    fVar12 = local_58[3];
    fVar6 = local_58[0];
  }
  iVar1 = isnanf(param_1);
  fVar8 = DAT_20002d3c;
  fVar7 = DAT_20002d3c;
  if (iVar1 == 0) {
    fVar7 = fVar11 - fVar14;
    fVar8 = (local_58[1] - fVar5) / fVar7;
    fVar9 = (local_48 - fVar10) / fVar7;
    fVar6 = ((fVar6 - local_58[1]) / (fVar13 - fVar11) - fVar8) / (fVar13 - fVar14);
    fVar13 = ((fVar12 - local_48) / (fVar13 - fVar11) - fVar9) / (fVar13 - fVar14);
    fVar14 = param_1 - fVar14;
    fVar8 = fVar5 + (fVar8 + -fVar7 * fVar6 + fVar6 * fVar14) * fVar14;
    fVar7 = fVar10 + (fVar9 + -fVar7 * fVar13 + fVar13 * fVar14) * fVar14;
  }
  param_4[1] = fVar7;
  *param_4 = fVar8;
  return;
}


