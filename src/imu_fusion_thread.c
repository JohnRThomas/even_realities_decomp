/*
 * Function: imu_fusion_thread
 * Entry:    0000fec0
 * Prototype: undefined __stdcall imu_fusion_thread(char * param_1)
 */


/* WARNING: Removing unreachable block (ram,0x000105d6) */

void imu_fusion_thread(char *param_1)

{
  longlong lVar1;
  char cVar2;
  bool bVar3;
  byte bVar4;
  uint uVar5;
  int iVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  uint uVar10;
  uint uVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  GlassesState *pGVar15;
  undefined4 uVar16;
  float *pfVar17;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  undefined4 extraout_r1_02;
  int *piVar18;
  undefined4 extraout_r1_03;
  undefined4 extraout_r1_04;
  undefined4 extraout_r1_05;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 extraout_r2_02;
  undefined4 extraout_r2_03;
  undefined4 extraout_r2_04;
  undefined4 extraout_r2_05;
  undefined4 extraout_r2_06;
  undefined4 uVar19;
  undefined4 extraout_r2_07;
  uint extraout_r3;
  uint extraout_r3_00;
  uint extraout_r3_01;
  int iVar20;
  undefined2 extraout_var;
  undefined4 extraout_r3_02;
  uint *extraout_r3_03;
  char *pcVar21;
  float *pfVar22;
  float *pfVar23;
  char *pcVar24;
  float *pfVar25;
  float fVar26;
  char *pcVar27;
  int iVar28;
  int iVar29;
  k_timeout_t timeout;
  ulonglong uVar30;
  ulonglong uVar31;
  uint local_a4;
  float local_a0;
  char *local_9c;
  float local_98;
  float local_94 [6];
  undefined4 local_7c;
  undefined2 local_78;
  uint local_70;
  uint local_6c;
  uint local_68;
  uint local_64;
  uint local_60;
  uint local_5c;
  uint local_58;
  uint local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  
  local_9c = (char *)0x0;
  local_98 = 0.0;
  local_a0 = 0.0;
  memset(&local_70,0,0x18);
  memset(&local_58,0,0x18);
  if ((byte)param_1[0x14] == 0) {
    if (1 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): start imu looper\n\n");
      }
      else {
        ble_printk("%s(): start imu looper\n\n","imu_fusion_thread",0,BLE_DEBUG);
      }
    }
    *param_1 = '\x01';
    pcVar24 = param_1 + -0xee8;
    local_a4 = 0;
    while (param_1[0x15] != '\0') {
      while ((param_1[-0xee7] == '\x01' || (param_1[-0xee7] == '\b'))) {
        z_impl_k_sleep((k_timeout_t)0x28000);
      }
      cVar2 = FUN_00033d5c();
      if (cVar2 == '\0') {
        if (param_1[0x106] == '\v') {
          *param_1 = '\x02';
        }
        else {
          if (param_1[0x106] != '\f') {
            if ((int)((uint)*(ushort *)(param_1 + 0x188) << 0x1a) < 0) {
              uVar30 = sys_clock_tick_get();
              lVar1 = (uVar30 & 0xffffffff) * 1000;
              local_a4 = (uint)lVar1 >> 0xf |
                         ((int)(uVar30 >> 0x20) * 1000 + (int)((ulonglong)lVar1 >> 0x20)) * 0x20000;
              if (1000 < local_a4 - DAT_20008474) {
                FUN_00028694((undefined4 *)(param_1 + 0x28));
              }
              goto LAB_0000ffe8;
            }
            uVar5 = 0xccd;
            *param_1 = '\x01';
            goto LAB_0000ff70;
          }
          *param_1 = '\x01';
          if (param_1[-0xe13] != '\a') {
            sync_to_slave(pcVar24,1,(undefined4 *)0x0,0);
            cVar2 = FUN_000169b4();
            if (cVar2 == '\x02') {
              change_work_mode(3);
            }
            FUN_0007ff66((int)pcVar24,1);
          }
        }
        uVar5 = 0x8000;
      }
      else {
LAB_0000ffe8:
        iVar6 = (**(code **)(*(int *)(*(int *)(param_1 + 0x1c) + 8) + 0xc))
                          (*(int *)(param_1 + 0x1c),0x3a);
        if (iVar6 < 0) {
          uVar5 = 0x290;
        }
        else {
          (**(code **)(*(int *)(*(int *)(param_1 + 0x1c) + 8) + 0x10))
                    (*(int *)(param_1 + 0x1c),3,&local_70);
          (**(code **)(*(int *)(*(int *)(param_1 + 0x1c) + 8) + 0x10))
                    (*(int *)(param_1 + 0x1c),7,&local_58);
          uVar30 = __floatsidf(local_6c);
          uVar30 = __divdf3((uint)uVar30,(uint)(uVar30 >> 0x20),0,0x412e8480);
          uVar31 = __floatsidf(local_70);
          uVar30 = __aeabi_dadd((uint)uVar30,(uint)(uVar30 >> 0x20),(uint)uVar31,
                                (uint)(uVar31 >> 0x20));
          uVar30 = __muldf3((uint)uVar30,(uint)(uVar30 >> 0x20),0,0x40240000);
          fVar7 = (float)__truncdfsf2((uint)uVar30,(uint)(uVar30 >> 0x20));
          uVar30 = __floatsidf(local_64);
          uVar30 = __divdf3((uint)uVar30,(uint)(uVar30 >> 0x20),0,0x412e8480);
          uVar31 = __floatsidf(local_68);
          uVar30 = __aeabi_dadd((uint)uVar30,(uint)(uVar30 >> 0x20),(uint)uVar31,
                                (uint)(uVar31 >> 0x20));
          uVar30 = __muldf3((uint)uVar30,(uint)(uVar30 >> 0x20),0,0x40240000);
          fVar8 = (float)__truncdfsf2((uint)uVar30,(uint)(uVar30 >> 0x20));
          uVar30 = __floatsidf(local_5c);
          uVar30 = __divdf3((uint)uVar30,(uint)(uVar30 >> 0x20),0,0x412e8480);
          uVar31 = __floatsidf(local_60);
          uVar30 = __aeabi_dadd((uint)uVar30,(uint)(uVar30 >> 0x20),(uint)uVar31,
                                (uint)(uVar31 >> 0x20));
          uVar30 = __muldf3((uint)uVar30,(uint)(uVar30 >> 0x20),0,0x40240000);
          fVar9 = (float)__truncdfsf2((uint)uVar30,(uint)(uVar30 >> 0x20));
          uVar30 = __floatsidf(local_54);
          uVar30 = __divdf3((uint)uVar30,(uint)(uVar30 >> 0x20),0,0x412e8480);
          uVar31 = __floatsidf(local_58);
          uVar30 = __aeabi_dadd((uint)uVar30,(uint)(uVar30 >> 0x20),(uint)uVar31,
                                (uint)(uVar31 >> 0x20));
          uVar5 = __truncdfsf2((uint)uVar30,(uint)(uVar30 >> 0x20));
          uVar30 = __floatsidf(local_4c);
          uVar30 = __divdf3((uint)uVar30,(uint)(uVar30 >> 0x20),0,0x412e8480);
          uVar31 = __floatsidf(local_50);
          uVar30 = __aeabi_dadd((uint)uVar30,(uint)(uVar30 >> 0x20),(uint)uVar31,
                                (uint)(uVar31 >> 0x20));
          uVar10 = __truncdfsf2((uint)uVar30,(uint)(uVar30 >> 0x20));
          uVar30 = __floatsidf(local_44);
          uVar30 = __divdf3((uint)uVar30,(uint)(uVar30 >> 0x20),0,0x412e8480);
          uVar31 = __floatsidf(local_48);
          uVar30 = __aeabi_dadd((uint)uVar30,(uint)(uVar30 >> 0x20),(uint)uVar31,
                                (uint)(uVar31 >> 0x20));
          uVar11 = __truncdfsf2((uint)uVar30,(uint)(uVar30 >> 0x20));
          *(int *)(param_1 + 0x1ac) = (int)fVar7;
          *(int *)(param_1 + 0x1b0) = (int)fVar8;
          *(int *)(param_1 + 0x1b4) = (int)fVar9;
          uVar30 = __aeabi_f2d(uVar5,extraout_r1,extraout_r2,extraout_r3);
          uVar30 = __subdf((uint)uVar30,(uint)(uVar30 >> 0x20),0x45a1cac1,0x3fadf3b6);
          fVar12 = (float)__truncdfsf2((uint)uVar30,(uint)(uVar30 >> 0x20));
          uVar30 = __aeabi_f2d(uVar10,extraout_r1_00,extraout_r2_00,extraout_r3_00);
          uVar30 = __aeabi_dadd((uint)uVar30,(uint)(uVar30 >> 0x20),0xa3d70a4,0x3fa0a3d7);
          fVar13 = (float)__truncdfsf2((uint)uVar30,(uint)(uVar30 >> 0x20));
          uVar30 = __aeabi_f2d(uVar11,extraout_r1_01,extraout_r2_01,extraout_r3_01);
          uVar30 = __subdf((uint)uVar30,(uint)(uVar30 >> 0x20),0x47ae147b,0x3f847ae1);
          fVar14 = (float)__truncdfsf2((uint)uVar30,(uint)(uVar30 >> 0x20));
          pcVar21 = param_1 + 0x28;
          fVar26 = (float)FUN_00028888((int)pcVar21);
          FUN_00028700(fVar12,fVar13,fVar14,fVar7,fVar8,fVar9,fVar26,(int)pcVar21);
          fVar7 = FUN_00028904((int)pcVar21);
          local_a0 = fVar7;
          pcVar27 = (char *)FUN_000288e4((int)pcVar21);
          local_9c = pcVar27;
          local_98 = FUN_000288c4((int)pcVar21);
          iVar6 = (int)((float)pcVar27 * 100.0);
          iVar28 = (int)(fVar7 * 100.0);
          iVar29 = (int)(local_98 * 100.0);
          DAT_20008484 = iVar29;
          DAT_20008488 = iVar28;
          DAT_2000848c = iVar6;
          cVar2 = FUN_00033d5c();
          if ((cVar2 == '\x01') && (param_1[0x106] == '\v')) {
            *param_1 = '\x02';
LAB_00010252:
            uVar5 = 0x148;
          }
          else {
            DAT_20008474 = local_a4;
            DAT_20008494 = DAT_20008494 + 1;
            if (DAT_20008490 == '\0') {
              if (DAT_20008494 < 0xc9) goto LAB_00010252;
              DAT_20008490 = '\x01';
              DAT_200084ac = local_a0;
              DAT_200084b0 = local_9c;
              DAT_200084b4 = local_98;
            }
            FUN_00027fa8(param_1);
            if ((char *)(uint)(byte)param_1[-0xe13] == (char *)0x0) {
              if (iVar6 < DAT_20008470) {
                iVar20 = DAT_20008470 - iVar6;
              }
              else {
                iVar20 = iVar6 - DAT_20008470;
              }
              if (0x31 < iVar20) goto LAB_000102c6;
              DAT_2000846c = (char *)(uint)(byte)param_1[-0xe13];
              DAT_20008470 = iVar6;
              FUN_00027f38(0,param_1 + -0xe14);
              goto LAB_000102aa;
            }
LAB_000102c6:
            pcVar21 = param_1 + -0xe14;
            DAT_20008470 = iVar6;
            if (param_1[-0xe13] == '\r') {
              param_1[-0xdfb] = '\f';
              param_1[-0xdfa] = '\0';
              *(float *)(param_1 + -0xdf9) = local_a0;
              *(char **)(param_1 + -0xdf5) = local_9c;
              *(float *)(param_1 + -0xdf1) = local_98;
              pcVar21 = local_9c;
            }
            if (*param_1 == '\x02') {
              if ((iVar6 <= *(int *)(param_1 + 8) + 100) && (*(int *)(param_1 + 0xc) <= iVar6))
              goto LAB_00010752;
              DAT_2000846c = DAT_2000846c + 1;
              DAT_20008484 = iVar29;
              DAT_20008488 = iVar28;
              DAT_2000848c = iVar6;
              if ((int)DAT_2000846c < 2) goto LAB_000102aa;
              DAT_2000846c = (char *)0xfffffffd;
              DAT_20019a64 = 1;
              if (BLE_DEBUG == 0) {
                printk("bow head################################################\n");
                uVar16 = extraout_r1_05;
                uVar19 = extraout_r2_07;
              }
              else {
                ble_printk("bow head################################################\n",pcVar21,
                           &DAT_2000846c,BLE_DEBUG);
                uVar16 = extraout_r1_04;
                uVar19 = extraout_r2_06;
              }
              FUN_00029774(3,uVar16,uVar19);
              *param_1 = '\x01';
              if (((((((param_1[-0xe13] == '\t') || (param_1[-0xe13] == '\f')) ||
                     (param_1[-0xe13] == '\n')) ||
                    ((param_1[-0xe13] == '\v' || (param_1[-0xe13] == '\a')))) ||
                   ((param_1[-0xe13] == '\x0e' ||
                    ((param_1[-0xe13] == '\x0f' || (param_1[-0xe13] == '\x10')))))) ||
                  ((param_1[-0xe13] == '\x14' ||
                   (((param_1[-0xe13] == '\x11' || (param_1[-0xe13] == '\x12')) ||
                    (param_1[-0xe13] == '\x13')))))) ||
                 ((param_1[-0xe13] == '\x04' || (bVar3 = FUN_0002d9e8((int)pcVar24), bVar3)))) {
                DAT_20019a64 = 0;
                goto LAB_0001046e;
              }
              param_1[-0xe1d] = param_1[-0x13];
              if (param_1[-0xe13] == '\x01') {
                uVar5 = 8;
LAB_000106f8:
                sync_to_slave(pcVar24,uVar5,(undefined4 *)0x0,0);
              }
              else if (((param_1[0x1ee] == '\0') || (bVar4 = FUN_00035acc(), bVar4 != 1)) &&
                      ((cVar2 = FUN_000260dc(), cVar2 == '\0' &&
                       (*(char *)(*(int *)(param_1 + 0x108) + 0x72) == '\0')))) {
                uVar5 = 1;
                goto LAB_000106f8;
              }
              if (((param_1[0x1ee] == '\0') && (cVar2 = FUN_000260dc(), cVar2 == '\0')) &&
                 (*(char *)(*(int *)(param_1 + 0x108) + 0x72) == '\0')) {
                FUN_00080224((int)pcVar24,0);
              }
LAB_000105ae:
              DAT_20019a64 = 0;
LAB_000102aa:
              if ((*param_1 == '\x01') && ((int)DAT_2000846c < 1)) {
                sys_clock_tick_get();
                DAT_20008468 = iVar6;
              }
            }
            else {
              if ((iVar6 <= *(int *)(param_1 + 8)) && (*(int *)(param_1 + 0xc) <= iVar6)) {
                DAT_20008484 = iVar29;
                DAT_20008488 = iVar28;
                DAT_2000848c = iVar6;
                sys_clock_tick_get();
                pGVar15 = __get_dashboard_state();
                uVar16 = extraout_r2_02;
                if ((pGVar15->field_0xfea == '\0') ||
                   (pGVar15 = __get_dashboard_state(), uVar16 = extraout_r2_03,
                   pGVar15->field_0xfea == '\x01')) {
                  DAT_2000846c = DAT_2000846c + 1;
                  if (BLE_DEBUG == 0) {
                    printk("trigger_count %d");
                  }
                  else {
                    ble_printk("trigger_count %d",DAT_2000846c,uVar16,BLE_DEBUG);
                  }
                  if (1 < (int)DAT_2000846c) {
                    DAT_2000846c = (char *)0xfffffffd;
                    if ((param_1[-0xe13] != '\0') || (iVar6 < DAT_20008468)) {
                      DAT_20019a64 = 1;
                      if (BLE_DEBUG == 0) {
                        printk("look up################################################,screen_id is %d, pitch_y is %d, pitch_threshold_bow_head is %d, pitch_threshold_level is %d\n"
                               ,(uint)(byte)param_1[-0xe13],iVar6,*(undefined4 *)(param_1 + 8),
                               (uint)(byte)param_1[0x10]);
                      }
                      else {
                        ble_printk("look up################################################,screen_id is %d, pitch_y is %d, pitch_threshold_bow_head is %d, pitch_threshold_level is %d\n"
                                   ,(char *)(uint)(byte)param_1[-0xe13],iVar6,
                                   *(undefined4 *)(param_1 + 8));
                      }
                      iVar28 = 0x65;
                      while (((pGVar15 = __get_dashboard_state(), pGVar15->field_0x10d6 == '\0' &&
                              (DAT_20019a66 != '\0')) && (iVar28 = iVar28 + -1, iVar28 != 0))) {
                        z_impl_k_sleep((k_timeout_t)0x148);
                      }
                      FUN_00029774(2,extraout_r1_02,extraout_r2_04);
                      if ((((((param_1[-0xe13] == '\t') || (param_1[-0xe13] == '\f')) ||
                            ((param_1[-0xe13] == '\n' ||
                             ((param_1[-0xe13] == '\v' || (param_1[-0xe13] == '\x05')))))) ||
                           (param_1[-0xe13] == '\x04')) ||
                          (((((param_1[-0xe13] == '\a' || (param_1[-0xe13] == '\x0e')) ||
                             (param_1[-0xe13] == '\x0f')) ||
                            ((param_1[-0xe13] == '\x10' || (param_1[-0xe13] == '\x14')))) ||
                           (param_1[-0xe13] == '\x11')))) ||
                         ((param_1[-0xe13] == '\x12' || (param_1[-0xe13] == '\x13')))) {
                        *param_1 = '\x02';
                        DAT_20019a64 = 0;
                        goto LAB_0001046e;
                      }
                      cVar2 = FUN_000260dc();
                      if (cVar2 == '\0') {
                        iVar28 = FUN_0007fdc4(&DAT_20007f50);
                        if (iVar28 << 0x1e < 0) {
                          iVar28 = FUN_0007fdc4(&DAT_20008480);
                          if (((-1 < iVar28 << 0x1e) &&
                              (iVar28 = FUN_0007fdc4(&DAT_20007f4c), -1 < iVar28 << 0x1e)) &&
                             (iVar28 = FUN_0007fdc4(&DAT_20007f50), iVar28 << 0x1e < 0)) {
                            local_7c = (float)CONCAT22(extraout_var,0x650);
                            local_78 = 0x101;
                            uVar16 = send_response_data_to_msgqueue(&local_7c,6);
                            send_response_data_to_ble
                                      (uVar16,extraout_r1_03,extraout_r2_05,extraout_r3_02);
                            DAT_20007f4c = DAT_20007f4c | 2;
                          }
                        }
                        else {
                          *param_1 = '\x02';
                          iVar28 = FUN_0007fdc4(&DAT_20008480);
                          if (-1 < iVar28 << 0x1e) {
                            *extraout_r3_03 = *extraout_r3_03 | 2;
                          }
                        }
                      }
                      else {
                        *param_1 = '\x02';
                      }
                      goto LAB_000105ae;
                    }
                  }
                }
                goto LAB_000102aa;
              }
LAB_00010752:
              if ((int)DAT_2000846c < 0) {
                DAT_2000846c = DAT_2000846c + 1;
                DAT_20008484 = iVar29;
                DAT_20008488 = iVar28;
                DAT_2000848c = iVar6;
              }
              else {
                DAT_2000846c = (char *)0x0;
                DAT_20008484 = iVar29;
                DAT_20008488 = iVar28;
                DAT_2000848c = iVar6;
              }
            }
LAB_0001046e:
            iVar6 = 0;
            local_94[0] = local_a0 - DAT_200084ac;
            local_94[1] = (float)local_9c - (float)DAT_200084b0;
            local_94[2] = local_98 - DAT_200084b4;
            local_94[3] = 0.0;
            local_94[4] = 0.0;
            local_94[5] = 0.0;
            if (DAT_20008491 == '\x01') {
              pfVar17 = (float *)&local_7c;
              pfVar25 = local_94 + 3;
              pfVar22 = &DAT_200084b8;
              pfVar23 = &local_a0;
              do {
                fVar7 = *pfVar23;
                pfVar23 = pfVar23 + 1;
                fVar7 = fVar7 - *pfVar22;
                if (180.0 < ABS(fVar7)) {
                  if (0.0 < fVar7) {
                    fVar7 = fVar7 - 360.0;
                  }
                  else {
                    fVar7 = fVar7 + 360.0;
                  }
                }
                *pfVar17 = fVar7;
                fVar7 = *pfVar17;
                pfVar17 = pfVar17 + 1;
                iVar6 = iVar6 + 1;
                *pfVar25 = pfVar22[3] + fVar7;
                pfVar25 = pfVar25 + 1;
                pfVar22 = pfVar22 + 1;
              } while (iVar6 != 3);
              if (((0.1 < ABS(local_a0 - DAT_200084ac)) ||
                  (0.1 < ABS((float)local_9c - (float)DAT_200084b0))) ||
                 (0.1 < ABS(local_98 - DAT_200084b4))) {
                DAT_2000849c = 0;
              }
              else {
                DAT_2000849c = DAT_2000849c + 1;
                if (4 < DAT_2000849c) {
                  DAT_20008491 = '\x02';
                  DAT_200084c4 = local_94[3];
                  DAT_200084c8 = local_94[4];
                  DAT_200084cc = local_94[5];
                }
              }
            }
            else if (DAT_20008491 == '\x02') {
              DAT_20008498 = 0;
              DAT_2000849c = 0;
              DAT_200084a0 = 0;
              DAT_200084a4 = 0;
              DAT_200084a8 = 0;
              DAT_20008491 = '\0';
            }
            else if (DAT_20008491 == '\0') {
              pfVar25 = (float *)&DAT_0008c1f4;
              pfVar17 = local_94;
              piVar18 = &DAT_200084a0;
              iVar6 = 0;
              iVar28 = 0;
              do {
                fVar8 = *pfVar17;
                pfVar17 = pfVar17 + 1;
                fVar7 = *pfVar25;
                pfVar25 = pfVar25 + 1;
                if (fVar7 < ABS(fVar8)) {
                  if (0.0 < fVar8) {
                    iVar29 = 1;
                  }
                  else {
                    iVar29 = -1;
                  }
                  iVar20 = *piVar18;
                  *piVar18 = iVar29;
                  if (iVar20 == iVar29) {
                    iVar6 = iVar6 + 1;
                  }
                }
                iVar28 = iVar28 + 1;
                piVar18 = piVar18 + 1;
              } while (iVar28 != 3);
              if (iVar6 != 0) {
                if (DAT_20008498 == 0) {
                  DAT_200084b8 = local_a0;
                  DAT_200084bc = local_9c;
                  DAT_200084c0 = local_98;
                  DAT_20008498 = 1;
                }
                else {
                  DAT_20008498 = DAT_20008498 + 1;
                  if (4 < DAT_20008498) {
                    DAT_20008491 = '\x01';
                  }
                }
              }
            }
            DAT_200084ac = local_a0;
            DAT_200084b0 = local_9c;
            DAT_200084b4 = local_98;
            if (*param_1 == '\x02') {
              uVar5 = 0x4de;
            }
            else {
              uVar5 = 0xa3e;
            }
          }
        }
      }
LAB_0000ff70:
      timeout.ticks._4_4_ = 0;
      timeout.ticks._0_4_ = uVar5;
      z_impl_k_sleep(timeout);
    }
  }
  else if (1 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): error\n\n");
    }
    else {
      ble_printk("%s(): error\n\n","imu_fusion_thread",(uint)(byte)param_1[0x14],BLE_DEBUG);
    }
  }
  return;
}


