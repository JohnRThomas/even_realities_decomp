/*
 * Function: lc3_tns_analyze
 * Entry:    00073280
 * Prototype: void __stdcall lc3_tns_analyze(lc3_dt dt, lc3_bandwidth bw, bool nn_flag, int nbytes, lc3_tns_data_t * data, float * x)
 */


/* exclude_from_export_ai */

void lc3_tns_analyze(lc3_dt dt,lc3_bandwidth bw,bool nn_flag,int nbytes,lc3_tns_data_t *data,
                    float *x)

{
  bool bVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float *pfVar7;
  int *piVar8;
  float *pfVar9;
  float *pfVar10;
  int iVar11;
  float *pfVar12;
  float *pfVar13;
  uint uVar14;
  int *piVar15;
  float *pfVar16;
  float *pfVar18;
  uint uVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  undefined **ppuVar23;
  lc3_tns_data_t *plVar24;
  lc3_tns_data_t *plVar25;
  float *pfVar26;
  lc3_tns_data_t *plVar27;
  float *pfVar28;
  int *piVar29;
  lc3_tns_data_t *plVar30;
  float fVar31;
  float fVar32;
  float fVar33;
  float fVar34;
  float fVar35;
  float fVar36;
  float fVar37;
  float fVar38;
  float fVar39;
  float fVar40;
  float fVar41;
  float fVar42;
  float fVar43;
  float fVar44;
  undefined *puVar45;
  float fVar46;
  float fVar47;
  float fVar48;
  float fVar49;
  float fVar50;
  float local_154 [10];
  float local_12c;
  float local_128;
  float local_124;
  undefined *local_11c [4];
  undefined *local_10c;
  undefined *local_108;
  undefined *puStack_104;
  undefined *local_100;
  undefined *local_fc;
  undefined *local_f8;
  float local_f4;
  float local_f0;
  float local_ec;
  float local_e8;
  float local_e4 [18];
  float local_9c;
  float local_98;
  float local_94;
  float local_90;
  float local_8c;
  float local_88;
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float *pfVar17;
  
  if (2U < (uint)bw) {
    iVar20 = 2;
  }
  else {
    iVar20 = 1;
  }
  if (dt == 0) {
    iVar11 = 0x2d;
  }
  else {
    iVar11 = 0x3c;
  }
  data[1].opaque[0] = nbytes < iVar11;
  *(int *)data->opaque = iVar20;
  local_11c[0] = &DAT_0009c114;
  local_11c[1] = &DAT_0009c124;
  local_11c[2] = &DAT_0009c134;
  local_11c[3] = &DAT_0009c144;
  local_10c = &DAT_0009c160;
  local_108 = &DAT_0009c17c;
  puStack_104 = &DAT_0009c18c;
  local_100 = &DAT_0009c19c;
  pfVar18 = local_e4;
  local_fc = &DAT_0009c1ac;
  local_f8 = &DAT_0009c1c8;
  piVar8 = (int *)local_11c[dt * 5 + bw];
  piVar15 = piVar8 + iVar20 * 3;
  pfVar7 = x + *piVar8;
  pfVar10 = pfVar18;
  do {
    pfVar9 = &local_9c;
    piVar29 = piVar8 + 3;
    pfVar12 = pfVar7;
    do {
      piVar8 = piVar8 + 1;
      pfVar7 = x + *piVar8;
      iVar21 = (int)pfVar7 - (int)pfVar12 >> 2;
      pfVar26 = pfVar7;
      iVar11 = iVar21;
      pfVar13 = pfVar9;
      do {
        fVar47 = 0.0;
        iVar22 = iVar11 + -1;
        pfVar28 = (float *)(((int)pfVar12 + iVar21 * 2) * 2 - (int)pfVar26);
        pfVar16 = pfVar12;
        if (iVar11 != 0) {
          do {
            pfVar17 = pfVar16 + 1;
            fVar41 = *pfVar28;
            pfVar28 = pfVar28 + 1;
            fVar47 = fVar47 + *pfVar16 * fVar41;
            pfVar16 = pfVar17;
          } while (pfVar17 != pfVar26);
        }
        *pfVar13 = fVar47;
        fVar33 = local_94;
        fVar41 = local_98;
        fVar47 = local_9c;
        pfVar13 = pfVar13 + 3;
        pfVar26 = pfVar26 + -1;
        iVar11 = iVar22;
      } while (iVar21 + -9 != iVar22);
      pfVar9 = pfVar9 + 1;
      pfVar12 = pfVar7;
    } while (piVar8 != piVar29);
    bVar1 = local_9c == 0.0;
    *pfVar10 = 3.0;
    if (((bVar1) || (fVar41 == 0.0)) || (fVar33 == 0.0)) {
      fVar47 = 0.0;
      pfVar10[1] = 0.0;
      pfVar10[2] = 0.0;
      pfVar10[3] = 0.0;
      pfVar10[4] = 0.0;
      pfVar10[5] = 0.0;
      pfVar10[6] = 0.0;
      pfVar10[7] = 0.0;
    }
    else {
      fVar41 = 1.0 / fVar41;
      fVar47 = 1.0 / fVar47;
      fVar33 = 1.0 / fVar33;
      fVar39 = fVar41 * local_50;
      fVar43 = fVar41 * local_8c;
      fVar35 = fVar41 * local_74;
      fVar36 = fVar41 * local_68;
      fVar38 = fVar41 * local_5c;
      fVar40 = fVar41 * local_44;
      fVar49 = fVar41 * local_38;
      fVar48 = local_78 * fVar47;
      fVar31 = local_6c * fVar47;
      fVar32 = local_60 * fVar47;
      fVar37 = local_54 * fVar47;
      fVar42 = local_48 * fVar47;
      fVar50 = local_3c * fVar47;
      fVar44 = local_90 * fVar47;
      fVar34 = local_70 * fVar33;
      fVar46 = local_64 * fVar33;
      fVar2 = local_58 * fVar33;
      fVar3 = local_88 * fVar33;
      fVar4 = local_4c * fVar33;
      fVar5 = local_40 * fVar33;
      fVar6 = local_34 * fVar33;
      pfVar10[2] = (fVar41 * local_80 + local_84 * fVar47 + local_7c * fVar33) * 0.9921354;
      pfVar10[3] = (fVar35 + fVar48 + fVar34) * 0.9823916;
      pfVar10[4] = (fVar36 + fVar31 + fVar46) * 0.9689108;
      pfVar10[1] = (fVar43 + fVar44 + fVar3) * 0.99802804;
      pfVar10[5] = (fVar38 + fVar32 + fVar2) * 0.9518498;
      fVar47 = (fVar49 + fVar50 + fVar6) * 0.88132316;
      pfVar10[6] = (fVar39 + fVar37 + fVar4) * 0.93140495;
      pfVar10[7] = (fVar40 + fVar42 + fVar5) * 0.90780824;
    }
    pfVar10[8] = fVar47;
    pfVar10 = pfVar10 + 9;
  } while (piVar8 != piVar15);
  pfVar10 = local_154 + 3;
  pfVar7 = &local_9c;
  pfVar9 = pfVar7;
  pfVar12 = pfVar10;
  do {
    fVar41 = *pfVar18;
    *pfVar9 = 1.0;
    iVar11 = 1;
    pfVar26 = local_154 + 5;
    pfVar13 = pfVar18;
    pfVar16 = pfVar9;
    fVar47 = fVar41;
    while( true ) {
      while( true ) {
        while( true ) {
          fVar33 = pfVar13[1];
          if (iVar11 != 1) break;
          fVar48 = -fVar33 / fVar47;
          pfVar26[1] = fVar48;
          fVar47 = fVar47 * (-fVar48 * fVar48 + 1.0);
          fVar33 = -(pfVar13[2] + fVar33 * local_154[6]) / fVar47;
          pfVar16 = pfVar16 + 2;
          pfVar9[1] = local_154[6] + fVar33 * fVar48;
          pfVar13 = pfVar13 + 2;
          pfVar26 = pfVar26 + 2;
          iVar11 = 3;
          fVar47 = fVar47 * (-fVar33 * fVar33 + 1.0);
          *pfVar16 = fVar33;
        }
        fVar37 = pfVar9[1];
        fVar31 = *pfVar13;
        fVar42 = pfVar9[2];
        fVar32 = pfVar13[-1];
        fVar48 = -fVar33 + -fVar37 * fVar31 + -fVar42 * fVar32;
        if (iVar11 == 3) {
          fVar48 = fVar48 / fVar47;
          fVar47 = (-fVar48 * fVar48 + 1.0) * fVar47;
          local_154[6] = fVar37 + fVar48 * *pfVar16;
          local_154[7] = fVar42 + fVar48 * pfVar16[-1];
        }
        else {
          fVar48 = fVar48 + -pfVar9[3] * pfVar13[-2] + -pfVar13[-3] * pfVar9[4];
          if (iVar11 != 5) {
            fVar48 = fVar48 + -pfVar9[5] * pfVar13[-4] + -pfVar13[-5] * pfVar9[6];
          }
          fVar48 = fVar48 / fVar47;
          fVar47 = fVar47 * (-fVar48 * fVar48 + 1.0);
          local_154[6] = fVar37 + *pfVar16 * fVar48;
          local_154[7] = fVar42 + pfVar16[-1] * fVar48;
          local_154[8] = pfVar9[3] + pfVar16[-2] * fVar48;
          local_154[9] = pfVar9[4] + pfVar16[-3] * fVar48;
          if (iVar11 != 5) {
            local_12c = pfVar9[5] + fVar48 * pfVar16[-4];
            local_128 = pfVar9[6] + pfVar16[-5] * fVar48;
          }
        }
        pfVar26[1] = fVar48;
        fVar42 = local_124;
        fVar37 = local_128;
        fVar33 = -(pfVar13[2] + fVar33 * local_154[6]) + -fVar31 * local_154[7] +
                 -fVar32 * local_154[8];
        if ((iVar11 != 3) &&
           (fVar33 = fVar33 + -pfVar13[-2] * local_154[9] + -pfVar13[-3] * local_12c, iVar11 != 5))
        {
          fVar33 = fVar33 + -pfVar13[-4] * local_128 + -pfVar13[-5] * local_124;
        }
        fVar33 = fVar33 / fVar47;
        fVar31 = *pfVar26;
        fVar32 = pfVar26[-1];
        fVar47 = (-fVar33 * fVar33 + 1.0) * fVar47;
        pfVar9[1] = local_154[6] + fVar33 * fVar48;
        pfVar9[2] = local_154[7] + fVar33 * fVar31;
        pfVar9[3] = local_154[8] + fVar33 * fVar32;
        if (iVar11 != 3) break;
        pfVar16 = pfVar16 + 2;
        iVar11 = 5;
        pfVar13 = pfVar13 + 2;
        pfVar26 = pfVar26 + 2;
        *pfVar16 = fVar33;
      }
      fVar48 = pfVar26[-3];
      pfVar9[4] = local_154[9] + fVar33 * pfVar26[-2];
      pfVar9[5] = local_12c + fVar33 * fVar48;
      if (iVar11 != 5) break;
      pfVar16 = pfVar16 + 2;
      iVar11 = 7;
      pfVar13 = pfVar13 + 2;
      pfVar26 = pfVar26 + 2;
      *pfVar16 = fVar33;
    }
    fVar48 = pfVar26[-4];
    fVar31 = pfVar26[-5];
    *pfVar12 = fVar41 / fVar47;
    pfVar12 = pfVar12 + 1;
    pfVar9[6] = fVar37 + fVar33 * fVar48;
    pfVar9[7] = fVar42 + fVar33 * fVar31;
    pfVar18 = pfVar18 + 9;
    pfVar16[2] = fVar33;
    pfVar9 = pfVar9 + 9;
  } while (pfVar12 != pfVar10 + iVar20);
  plVar25 = data + 1;
  pfVar18 = local_e4;
  plVar30 = data + 3;
  iVar21 = 0;
  iVar11 = iVar20;
  plVar27 = plVar25;
  pfVar9 = pfVar18;
  do {
    plVar27 = plVar27 + 1;
    *(undefined4 *)plVar27->opaque = 0;
    if ((!nn_flag) && (fVar47 = *pfVar10, 1.5 < fVar47)) {
      fVar31 = pfVar7[1];
      fVar48 = pfVar7[2];
      fVar33 = pfVar7[3];
      fVar41 = pfVar7[4];
      fVar32 = pfVar7[5];
      fVar37 = pfVar7[6];
      fVar42 = pfVar7[7];
      fVar50 = pfVar7[8];
      if ((data[1].opaque[0] != 0) && ((int)((uint)(fVar47 < 2.0) << 0x1f) < 0)) {
        fVar34 = (fVar47 - 2.0) * 0.29999995 + 1.0;
        fVar47 = fVar34 * fVar34 * fVar34;
        fVar48 = fVar48 * fVar34 * fVar34;
        fVar44 = fVar34 * fVar47;
        fVar33 = fVar33 * fVar47;
        fVar47 = fVar34 * fVar44;
        fVar41 = fVar41 * fVar44;
        fVar44 = fVar34 * fVar47;
        fVar31 = fVar31 * fVar34;
        fVar46 = fVar34 * fVar44;
        fVar32 = fVar32 * fVar47;
        fVar37 = fVar37 * fVar44;
        fVar42 = fVar42 * fVar46;
        fVar50 = fVar34 * fVar50 * fVar46;
        pfVar7[1] = fVar31;
        pfVar7[2] = fVar48;
        pfVar7[3] = fVar33;
        pfVar7[4] = fVar41;
        pfVar7[5] = fVar32;
        pfVar7[6] = fVar37;
        pfVar7[7] = fVar42;
        pfVar7[8] = fVar50;
      }
      pfVar9[7] = fVar50;
      fVar47 = 1.0 / (-fVar50 * fVar50 + 1.0);
      pfVar12 = pfVar9 + 7;
      iVar11 = 0x18;
      uVar14 = 6;
      local_100 = (undefined *)((fVar31 + -fVar50 * fVar42) * fVar47);
      local_fc = (undefined *)((fVar48 + -fVar50 * fVar37) * fVar47);
      local_f8 = (undefined *)((fVar33 + -fVar50 * fVar32) * fVar47);
      local_f4 = (1.0 - fVar50) * fVar41 * fVar47;
      local_f0 = (fVar32 + -fVar50 * fVar33) * fVar47;
      local_ec = (fVar37 + -fVar50 * fVar48) * fVar47;
      local_e8 = (fVar42 + -fVar50 * fVar31) * fVar47;
      ppuVar23 = local_11c + 7;
      while( true ) {
        pfVar26 = (float *)((int)ppuVar23 + iVar11);
        fVar41 = *pfVar26;
        fVar47 = 1.0 / (-fVar41 * fVar41 + 1.0);
        puVar45 = (undefined *)(fVar47 * ((float)*ppuVar23 + -fVar41 * pfVar26[-1]));
        uVar19 = uVar14 & 1;
        pfVar12 = pfVar12 + -1;
        *pfVar12 = fVar41;
        local_11c[uVar19 * 7] = puVar45;
        fVar41 = -fVar41;
        if (uVar14 == 1) break;
        local_11c[uVar19 * 7 + 1] =
             (undefined *)(fVar47 * ((float)ppuVar23[1] + fVar41 * pfVar26[-2]));
        if (((uVar14 != 2) &&
            (local_11c[uVar19 * 7 + 2] =
                  (undefined *)(fVar47 * ((float)ppuVar23[2] + fVar41 * pfVar26[-3])), uVar14 != 3))
           && (local_11c[uVar19 * 7 + 3] =
                    (undefined *)(fVar47 * ((float)ppuVar23[3] + fVar41 * pfVar26[-4])), uVar14 != 4
              )) {
          local_11c[uVar19 * 7 + 4] =
               (undefined *)(fVar47 * ((float)ppuVar23[4] + fVar41 * pfVar26[-5]));
        }
        uVar14 = uVar14 - 1;
        iVar11 = iVar11 + -4;
        ppuVar23 = local_11c + uVar19 * 7;
      }
      *pfVar9 = (float)puVar45;
      *(undefined4 *)plVar27->opaque = 8;
      plVar24 = plVar30;
      pfVar12 = pfVar9;
      do {
        fVar47 = *pfVar12;
        pfVar12 = pfVar12 + 1;
        fVar41 = ABS(fVar47);
        uVar14 = (uint)(0.7390089 <= fVar41);
        puVar45 = (&PTR_DAT_0009c0f4)[uVar14 * 4];
        iVar11 = uVar14 * 4;
        plVar24 = plVar24 + 1;
        *(int *)plVar24->opaque = iVar11;
        if (fVar41 < (float)puVar45) {
          if ((int)((uint)(fVar47 < 0.0) << 0x1f) < 0) {
            iVar11 = uVar14 * -4;
            *(int *)plVar24->opaque = iVar11;
          }
          if (iVar11 != 0) goto LAB_00073b7c;
          iVar22 = *(int *)plVar27->opaque + -1;
        }
        else {
          iVar22 = iVar11 + 1;
          puVar45 = (&PTR_DAT_0009c0f4)[iVar22];
          *(int *)plVar24->opaque = iVar22;
          if ((float)puVar45 <= fVar41) {
            iVar22 = iVar11 + 2;
            puVar45 = (&PTR_DAT_0009c0f4)[iVar22];
            *(int *)plVar24->opaque = iVar22;
            if ((float)puVar45 <= fVar41) {
              iVar22 = iVar11 + 3;
              puVar45 = (&PTR_DAT_0009c0f4)[iVar22];
              *(int *)plVar24->opaque = iVar22;
              if ((float)puVar45 <= fVar41) {
                iVar22 = iVar11 + 4;
                *(int *)plVar24->opaque = iVar22;
              }
            }
          }
          if ((int)((uint)(fVar47 < 0.0) << 0x1f) < 0) {
            *(int *)plVar24->opaque = -iVar22;
          }
LAB_00073b7c:
          iVar22 = 8;
        }
        *(int *)plVar27->opaque = iVar22;
      } while (pfVar9 + 8 != pfVar12);
      iVar11 = *(int *)data->opaque;
      if (0 < iVar22) {
        plVar24 = plVar30;
        pfVar12 = pfVar9;
        do {
          plVar24 = plVar24 + 1;
          uVar14 = *(uint *)plVar24->opaque;
          fVar47 = *(float *)(&DAT_0009c0d0 +
                             ((uVar14 ^ (int)uVar14 >> 0x1f) - ((int)uVar14 >> 0x1f)) * 4);
          if ((int)uVar14 < 0) {
            fVar47 = -fVar47;
          }
          *pfVar12 = fVar47;
          pfVar12 = pfVar12 + 1;
        } while (plVar24 != plVar30 + iVar22);
      }
    }
    pfVar9 = pfVar9 + 8;
    iVar21 = iVar21 + 1;
    pfVar10 = pfVar10 + 1;
    plVar30 = plVar30 + 8;
    pfVar7 = pfVar7 + 9;
    if (iVar11 <= iVar21) {
      fVar47 = 0.0;
      iVar11 = dt + 3;
      iVar21 = (bw * iVar11 + iVar11) * 0x14 >> (uint)(2U < (uint)bw);
      plVar27 = plVar25 + iVar20;
      iVar20 = iVar21;
      iVar11 = iVar11 * 3;
      fVar41 = fVar47;
      fVar33 = fVar47;
      fVar48 = fVar47;
      fVar31 = fVar47;
      fVar32 = fVar47;
      fVar37 = fVar47;
      fVar42 = fVar47;
      pfVar10 = x;
      do {
        iVar22 = iVar20;
        pfVar10 = pfVar10 + iVar21;
        plVar25 = plVar25 + 1;
        iVar20 = *(int *)plVar25->opaque;
        if ((iVar20 != 0) && (iVar11 < iVar22)) {
          pfVar7 = x + iVar11;
          while( true ) {
            fVar44 = *pfVar7;
            fVar50 = fVar44;
            if (0 < iVar20) {
              fVar34 = fVar42 + *pfVar18 * fVar44;
              fVar50 = fVar44 + *pfVar18 * fVar42;
              fVar42 = fVar44;
              if (iVar20 != 1) {
                fVar44 = fVar37 + fVar50 * pfVar18[1];
                fVar50 = fVar50 + pfVar18[1] * fVar37;
                fVar37 = fVar34;
                if (iVar20 != 2) {
                  fVar34 = fVar32 + fVar50 * pfVar18[2];
                  fVar50 = fVar50 + fVar32 * pfVar18[2];
                  fVar32 = fVar44;
                  if (iVar20 != 3) {
                    fVar44 = fVar48 + fVar50 * pfVar18[3];
                    fVar50 = fVar50 + fVar48 * pfVar18[3];
                    fVar48 = fVar34;
                    if (iVar20 != 4) {
                      fVar34 = fVar33 + fVar50 * pfVar18[4];
                      fVar50 = fVar50 + fVar33 * pfVar18[4];
                      fVar33 = fVar44;
                      if (iVar20 != 5) {
                        fVar44 = fVar41 + pfVar18[5] * fVar50;
                        fVar50 = fVar50 + fVar41 * pfVar18[5];
                        fVar41 = fVar34;
                        if (iVar20 != 6) {
                          fVar34 = fVar31 + pfVar18[6] * fVar50;
                          fVar50 = fVar50 + fVar31 * pfVar18[6];
                          fVar31 = fVar44;
                          if (iVar20 != 7) {
                            fVar44 = pfVar18[7] * fVar47;
                            fVar47 = fVar34;
                            fVar50 = fVar50 + fVar44;
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
            *pfVar7 = fVar50;
            if (pfVar7 + 1 == pfVar10) break;
            iVar20 = *(int *)plVar25->opaque;
            pfVar7 = pfVar7 + 1;
          }
        }
        pfVar18 = pfVar18 + 8;
        iVar20 = iVar22 + iVar21;
        iVar11 = iVar22;
      } while (plVar27 != plVar25);
      return;
    }
  } while( true );
}


