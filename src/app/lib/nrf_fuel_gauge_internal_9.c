/*
 * Function: nrf_fuel_gauge_internal_9
 * Entry:    0000e53c
 * Prototype: int __stdcall nrf_fuel_gauge_internal_9(lc3_dt dt, lc3_srate sr, float * x, int nbits_budget, float nbits_off, int g_off, bool * reset_off)
 */


/* exclude_from_export */

int nrf_fuel_gauge_internal_9
              (lc3_dt dt,lc3_srate sr,float *x,int nbits_budget,float nbits_off,int g_off,
              bool *reset_off)

{
  bool bVar1;
  byte bVar2;
  float *pfVar3;
  undefined1 uVar4;
  int *piVar5;
  int iVar7;
  int iVar8;
  float *pfVar9;
  char cVar10;
  float fVar11;
  float in_s1;
  float in_s2;
  float in_s3;
  float in_s4;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  undefined1 local_54;
  undefined1 local_53;
  undefined1 local_52;
  undefined4 uStack_50;
  int local_4c;
  float local_48 [3];
  int aiStack_3c [3];
  int *piVar6;
  
  x[1] = 2.0;
  *x = 1.0;
  memcpy(x + 2,(void *)dt,0x40);
  x[0x12] = in_s3;
  x[0x13] = in_s4;
  fVar13 = DAT_20002d3c;
  x[0x15] = 0.0;
  x[0x14] = 5.0;
  x[0x16] = 0.0;
  x[0x17] = 0.0;
  pfVar9 = x + 0x18;
  do {
    pfVar3 = pfVar9 + 1;
    *pfVar9 = fVar13;
    pfVar9[0x19] = fVar13;
    pfVar9 = pfVar3;
  } while (x + 0x31 != pfVar3);
  x[0x4b] = fVar13;
  x[0x4c] = fVar13;
  x[0x4d] = fVar13;
  x[0x50] = fVar13;
  x[0x4a] = 1.0;
  x[0x4e] = 0.0;
  x[0x4f] = 0.0;
  memcpy(x + 0x51,(void *)sr,0x1600);
  fVar13 = *(float *)(sr + 0x324);
  fVar12 = *(float *)(sr + 0x328);
  bVar2 = (byte)(((uint)(fVar13 == fVar12) << 0x1e) >> 0x18);
  cVar10 = -((char)((byte)(((uint)(fVar13 < fVar12) << 0x1f) >> 0x18) | bVar2) >> 7);
  if ((bool)cVar10 == (NAN(fVar13) || NAN(fVar12))) {
    uVar4 = 1;
    fVar11 = fVar13;
    fVar12 = fVar13;
  }
  else {
    fVar11 = fVar12;
    if ((cVar10 == '\0') && (fVar11 = fVar13, !(bool)(bVar2 >> 6) && (!NAN(fVar13) && !NAN(fVar12)))
       ) {
      fVar13 = fVar12;
    }
    fVar14 = *(float *)(sr + 0x32c);
    if (fVar14 <= fVar12) {
      uVar4 = 2;
    }
    else {
      fVar12 = fVar14;
      if (((int)((uint)(fVar11 < fVar14) << 0x1f) < 0) || (fVar12 = fVar11, fVar13 <= fVar14)) {
        uVar4 = 3;
        fVar11 = fVar12;
      }
      else {
        uVar4 = 3;
        fVar13 = fVar14;
      }
    }
    fVar12 = fVar13;
    if (-1 < (int)((uint)(in_s2 < fVar13) << 0x1f)) {
      fVar12 = (float)((uint)(fVar11 < in_s2) * (int)fVar11 + (uint)(in_s2 <= fVar11) * (int)in_s2);
    }
  }
  x[0x5d1] = fVar11;
  pfVar9 = (float *)(sr + 0x324);
  x[0x5d2] = fVar13;
  *(undefined1 *)(x + 0x5d3) = uVar4;
  fVar13 = nrf_fuel_gauge_internal_7(pfVar9);
  fVar13 = fminf(fVar12,fVar13);
  fVar11 = nrf_fuel_gauge_internal_6(pfVar9);
  fVar13 = fmaxf(fVar13,fVar11);
  local_54 = *(float *)(sr + 0x324) == fVar13;
  local_53 = *(float *)(sr + 0x328) == fVar13;
  local_52 = *(float *)(sr + 0x32c) == fVar13;
  nrf_fuel_gauge_internal_5((int)&local_54,(int)aiStack_3c,&uStack_50);
  if (local_4c == 0) {
    fVar13 = nrf_fuel_gauge_internal_4(fVar13,pfVar9,(float *)(sr + 0x1578));
  }
  else {
    fVar13 = local_48[0];
    if (0 < local_4c) {
      pfVar9 = local_48;
      piVar5 = aiStack_3c;
      do {
        piVar6 = piVar5 + 1;
        *pfVar9 = *(float *)(sr + (*piVar5 + 0x55d) * 4);
        pfVar9 = pfVar9 + 1;
        piVar5 = piVar6;
        fVar13 = local_48[0];
      } while (aiStack_3c + local_4c != piVar6);
    }
  }
  x[0x5d4] = 3.0;
  fVar15 = nbits_off + in_s1 * fVar13;
  fVar11 = *(float *)(sr + 0x330);
  fVar14 = *(float *)(sr + 0x514);
  fVar16 = *(float *)(sr + 0x334) - fVar11;
  if ((-1 < (int)((uint)(fVar11 < fVar15) << 0x1f)) || (fVar14 <= fVar15)) {
    if (fVar15 <= fVar11) {
      bVar1 = false;
      goto LAB_0000e8ae;
    }
    if (fVar15 < fVar14) {
      fVar14 = 0.0;
      goto LAB_0000e80a;
    }
    bVar1 = false;
LAB_0000e754:
    fVar14 = (((*(float *)(sr + 0x1574) + *(float *)(sr + 0x138c) * fVar12) -
              (*(float *)(sr + 0x1570) + *(float *)(sr + 5000) * fVar12)) * (fVar15 - fVar14)) /
             fVar16 + *(float *)(sr + 0x1574) + *(float *)(sr + 0x138c) * fVar12;
LAB_0000e794:
    if (!bVar1) goto LAB_0000e80a;
  }
  else {
    if (fVar11 == fVar15) {
      bVar1 = true;
LAB_0000e8ae:
      if (fVar14 <= fVar15) goto LAB_0000e754;
      fVar14 = ((fVar15 - fVar11) *
               ((*(float *)(sr + 0x1394) + *(float *)(sr + 0x11ac) * fVar12) -
               (*(float *)(sr + 0x1390) + *(float *)(sr + 0x11a8) * fVar12))) / fVar16 +
               *(float *)(sr + 0x1390) + *(float *)(sr + 0x11a8) * fVar12;
      goto LAB_0000e794;
    }
    if (fVar14 == fVar15) {
      bVar1 = true;
      goto LAB_0000e754;
    }
  }
  fVar11 = ceilf((fVar15 - fVar11) / fVar16);
  iVar7 = sr + (int)(fVar11 + 1.0) * 4;
  iVar8 = sr + (int)(fVar11 + 2.0) * 4;
  fVar11 = (fVar15 - *(float *)(sr + 0x330)) / fVar16 - fVar11;
  fVar14 = fVar11 * *(float *)(iVar8 + 0x138c) + *(float *)(iVar7 + 0x138c) * (1.0 - fVar11) +
           fVar12 * (fVar11 * *(float *)(iVar8 + 0x11a4) +
                    *(float *)(iVar7 + 0x11a4) * (1.0 - fVar11));
LAB_0000e80a:
  iVar7 = isnanf(fVar15);
  x[0x5d5] = 4.0;
  x[0x5d6] = 0.0;
  x[0x5d7] = 0.0;
  x[0x5d8] = 0.0;
  x[0x5d9] = (float)((uint)(iVar7 == 0) * (int)fVar14);
  x[0x5da] = fVar13;
  x[0x5db] = fVar13;
  x[0x5dc] = fVar13;
  x[0x5dd] = fVar13;
  *(float *)nbits_budget = fVar15;
  return iVar7;
}


