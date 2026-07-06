/*
 * Function: process_for_new_message_come_on
 * Entry:    0002e048
 * Prototype: undefined4 __stdcall process_for_new_message_come_on(byte * param_1, byte * param_2)
 */


undefined4 process_for_new_message_come_on(byte *param_1,byte *param_2)

{
  longlong lVar1;
  bool bVar2;
  char cVar3;
  byte bVar4;
  bool bVar5;
  int *piVar6;
  char *fmt;
  GlassesState *pGVar7;
  char *pcVar8;
  uint uVar9;
  int extraout_r1;
  int extraout_r1_00;
  int extraout_r1_01;
  int extraout_r1_02;
  undefined4 extraout_r1_03;
  undefined4 extraout_r1_04;
  undefined4 extraout_r1_05;
  uint extraout_r1_06;
  undefined4 extraout_r1_07;
  undefined4 extraout_r1_08;
  undefined4 extraout_r1_09;
  undefined4 extraout_r1_10;
  undefined4 extraout_r1_11;
  undefined4 extraout_r1_12;
  undefined4 extraout_r1_13;
  undefined4 extraout_r1_14;
  undefined4 extraout_r1_15;
  int extraout_r1_16;
  undefined4 extraout_r1_17;
  undefined4 extraout_r1_18;
  int extraout_r1_19;
  undefined4 extraout_r1_20;
  int extraout_r1_21;
  int extraout_r1_22;
  int extraout_r1_23;
  undefined4 extraout_r1_24;
  int extraout_r1_25;
  undefined4 extraout_r1_26;
  undefined4 extraout_r1_27;
  int extraout_r1_28;
  int extraout_r1_29;
  undefined4 extraout_r1_30;
  undefined4 extraout_r1_31;
  int extraout_r1_32;
  int extraout_r1_33;
  undefined4 extraout_r1_34;
  undefined4 extraout_r1_35;
  int extraout_r1_36;
  int extraout_r1_37;
  undefined4 extraout_r1_38;
  undefined4 extraout_r1_39;
  int extraout_r1_40;
  undefined4 extraout_r1_41;
  int iVar10;
  int extraout_r1_42;
  int extraout_r1_43;
  int extraout_r1_44;
  undefined4 extraout_r1_45;
  int extraout_r1_46;
  int extraout_r1_47;
  undefined4 extraout_r1_48;
  int extraout_r1_49;
  int extraout_r1_50;
  int extraout_r1_51;
  undefined4 extraout_r1_52;
  undefined4 extraout_r1_53;
  undefined4 extraout_r1_54;
  undefined4 extraout_r1_55;
  undefined4 uVar11;
  int extraout_r1_56;
  undefined4 extraout_r1_57;
  int extraout_r1_58;
  undefined4 extraout_r1_59;
  undefined4 extraout_r1_60;
  undefined4 extraout_r1_61;
  int extraout_r1_62;
  undefined4 extraout_r1_63;
  int extraout_r1_64;
  int extraout_r1_65;
  undefined4 extraout_r1_66;
  int extraout_r1_67;
  int extraout_r1_68;
  undefined4 extraout_r1_69;
  int extraout_r1_70;
  undefined4 extraout_r1_71;
  undefined4 extraout_r1_72;
  undefined4 extraout_r1_73;
  uint extraout_r1_74;
  uint extraout_r1_75;
  uint extraout_r1_76;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 extraout_r2_02;
  undefined4 extraout_r2_03;
  undefined4 extraout_r2_04;
  undefined4 extraout_r2_05;
  undefined4 extraout_r2_06;
  undefined4 uVar12;
  undefined4 extraout_r2_07;
  undefined1 *puVar13;
  undefined4 extraout_r2_08;
  undefined4 extraout_r2_09;
  undefined4 extraout_r2_10;
  undefined4 extraout_r3;
  uint extraout_r3_00;
  uint extraout_r3_01;
  uint extraout_r3_02;
  uint extraout_r3_03;
  uint extraout_r3_04;
  uint extraout_r3_05;
  uint extraout_r3_06;
  uint extraout_r3_07;
  undefined4 extraout_r3_08;
  uint extraout_r3_09;
  uint extraout_r3_10;
  uint extraout_r3_11;
  uint extraout_r3_12;
  undefined4 extraout_r3_13;
  uint extraout_r3_14;
  uint extraout_r3_15;
  uint extraout_r3_16;
  uint extraout_r3_17;
  uint extraout_r3_18;
  undefined4 extraout_r3_19;
  uint extraout_r3_20;
  undefined4 extraout_r3_21;
  uint extraout_r3_22;
  undefined4 extraout_r3_23;
  uint extraout_r3_24;
  uint extraout_r3_25;
  uint extraout_r3_26;
  uint extraout_r3_27;
  uint extraout_r3_28;
  uint extraout_r3_29;
  uint extraout_r3_30;
  uint extraout_r3_31;
  uint extraout_r3_32;
  uint extraout_r3_33;
  uint extraout_r3_34;
  uint extraout_r3_35;
  uint extraout_r3_36;
  uint extraout_r3_37;
  byte *pbVar14;
  undefined4 extraout_r3_38;
  undefined4 extraout_r3_39;
  undefined4 extraout_r3_40;
  byte *extraout_r3_41;
  undefined4 extraout_r3_42;
  byte *extraout_r3_43;
  short sVar15;
  int iVar16;
  uint uVar17;
  int iVar18;
  undefined8 uVar19;
  int64_t iVar20;
  undefined2 local_2c;
  byte local_2a;
  
  iVar16 = 0;
LAB_0002e05a:
  memset(param_1 + 0xef,0,0x5dc);
  clear_timeout_message(0);
  iVar10 = extraout_r1;
  if (*param_1 == 1) {
    __check_showing_message();
    iVar10 = extraout_r1_00;
  }
  if (param_1[0xd5] != 4) {
    DAT_20019a6d = 0;
  }
  if ((param_1[0xfec] == 0) && (bVar2 = FUN_0002da10((int)param_1), iVar10 = extraout_r1_01, bVar2))
  {
    trigger_screen_state_change("BLE:wakeup:running_task",(int)param_1,1,extraout_r3);
    iVar10 = extraout_r1_02;
  }
  switch((uint)param_1[0xd5]) {
  case 0:
    piVar6 = *(int **)(param_1 + 0x1068);
    if ((int)(DAT_20008518 << 0x1e) < 0) {
      DAT_20008518 = DAT_20008518 & 0xfffffffd;
    }
    FUN_00080338(1);
    bVar2 = FUN_0002d9e8((int)param_1);
    if (!bVar2) {
      if (*param_2 != 2) {
        trigger_screen_state_change("goto idle1",(int)param_1,0,(uint)*param_2);
        pGVar7 = __get_dashboard_state();
        if ((pGVar7->is_master == true) &&
           (pGVar7 = __get_dashboard_state(), (pGVar7->sem_2).count == 0)) {
          pGVar7 = __get_dashboard_state();
          k_sem_give(&pGVar7->sem_2);
        }
      }
      param_1[0xd5] = 0;
      puVar13 = *(undefined1 **)(param_1 + 0x1068);
      *puVar13 = 0;
      puVar13[1] = 0;
      puVar13[2] = 0;
      puVar13[3] = 0;
      *(undefined1 *)(*(int *)(param_1 + 0x1068) + 4) = 1;
      bVar4 = FUN_00035acc();
      if (bVar4 == 1) {
        iVar16 = 5;
      }
      else {
        pGVar7 = __get_dashboard_state();
        iVar16 = 0;
        if (pGVar7->field20_0xc8[0x15] != '\0') {
          iVar16 = 6;
        }
      }
      FUN_00035abc(iVar16);
      FUN_0002ddb0();
      if (*param_2 != 2) {
        iVar16 = 100;
        do {
          if (param_1[0xfea] == 1) break;
          sleep(10);
          iVar16 = iVar16 + -1;
        } while (iVar16 != 0);
      }
      if (1 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): Now, I will goto run IDLE ^v^ g->persist_task->screen_id %d, persist->status %d pkg->screen_id %d\n"
                 ,"process_for_IDLE",**(undefined4 **)(param_1 + 0x1068),(uint)*(byte *)(piVar6 + 1)
                 ,(uint)param_1[0xd5]);
        }
        else {
          ble_printk("%s(): Now, I will goto run IDLE ^v^ g->persist_task->screen_id %d, persist->status %d pkg->screen_id %d\n"
                     ,"process_for_IDLE",**(undefined4 **)(param_1 + 0x1068),
                     (uint)*(byte *)(piVar6 + 1),(uint)param_1[0xd5]);
        }
      }
    }
    DAT_20019a6d = 0;
    uVar9 = 0;
LAB_0002f1fc:
    do {
      while( true ) {
        uVar17 = uVar9;
        if ((param_1[1] == 1) || (pGVar7 = __get_dashboard_state(), pGVar7->field_0x1 == '\b'))
        goto LAB_0002f26c;
        bVar2 = is_in_box();
        if ((!bVar2) && ((param_1[0xfee] != 0xc || ((*piVar6 == 7 && (param_1[0xd5] == 7))))))
        break;
LAB_0002f2e0:
        if (*param_1 == 1) {
          (**(code **)(param_2 + 0x98))(param_2,0x50);
        }
        z_impl_k_sleep(0x667,0);
        uVar9 = uVar17 + 1;
      }
      bVar2 = FUN_0002d9e8((int)param_1);
      if (bVar2) {
        param_1[0xd5] = (byte)*piVar6;
        if (*(char *)(*(int *)(param_1 + 0xff0) + 0x74) != '\0') {
          *(undefined1 *)(*(int *)(param_1 + 0xff0) + 0x74) = 0;
        }
        pbVar14 = *(byte **)(param_1 + 0x1014);
        pcVar8 = "BLE:wakeup:persist_task";
        if (1 < *pbVar14) {
          *pbVar14 = 0;
        }
LAB_0002f268:
        trigger_screen_state_change(pcVar8,(int)param_1,1,pbVar14);
LAB_0002f26c:
        if (*param_1 != 1) {
          return 0;
        }
        (**(code **)(param_2 + 0x98))(param_2,0x26);
        return 0;
      }
      bVar4 = FUN_00033d5c();
      puVar13 = (undefined1 *)(uint)bVar4;
      if (puVar13 == &DAT_00000001) goto LAB_0002f2e0;
      uVar12 = extraout_r1_71;
      if (*(char *)(*(int *)(param_1 + 0x101c) + 1) != '\0') {
LAB_0002f2da:
        uVar17 = uVar17 + 1;
        if (((uVar17 & 0x1f) == 0) && (0 < LOG_LEVEL)) {
          bVar4 = *(byte *)(*(int *)(param_1 + 0x101c) + 1);
          if (BLE_DEBUG == 0) {
            uVar12 = FUN_0007f3da(puVar13,uVar12);
            pGVar7 = __get_dashboard_state();
            printk("%s(): There is an unfinished task,skip the local tasks:%d,%d,%d\n",
                   "process_for_IDLE",(uint)bVar4,uVar12,
                   (uint)*(byte *)(*(int *)&pGVar7->field_0x1018 + 1));
          }
          else {
            uVar12 = FUN_0007f3da(puVar13,uVar12);
            pGVar7 = __get_dashboard_state();
            ble_printk("%s(): There is an unfinished task,skip the local tasks:%d,%d,%d\n",
                       "process_for_IDLE",(uint)bVar4,uVar12,
                       (uint)*(byte *)(*(int *)&pGVar7->field_0x1018 + 1));
          }
        }
        goto LAB_0002f2e0;
      }
      iVar16 = FUN_0007f3da(puVar13,extraout_r1_71);
      puVar13 = (undefined1 *)0x0;
      uVar12 = extraout_r1_72;
      if (iVar16 == 0) goto LAB_0002f2da;
      pGVar7 = __get_dashboard_state();
      puVar13 = &pGVar7->field_0x1000;
      uVar12 = extraout_r1_73;
      if (*(char *)(*(int *)&pGVar7->field_0x1018 + 1) != '\0') goto LAB_0002f2da;
      if (*(char *)(*(int *)(param_1 + 0xff0) + 0x74) != '\0') {
        uVar9 = uVar17 + 1;
        sleep(0x32);
        if ((int)uVar9 < 0x50) {
          if (((uVar9 * -0x33333333 >> 3 | uVar9 * -0x60000000) < 0x6666667) && (1 < LOG_LEVEL)) {
            pcVar8 = "%s(): dashboard wait for starting other task\n";
LAB_0002f3b6:
            uVar9 = uVar17 + 1;
            if (BLE_DEBUG == 0) {
              printk(pcVar8,"process_for_IDLE");
            }
            else {
              ble_printk(pcVar8);
            }
          }
        }
        else {
          *(undefined1 *)(*(int *)(param_1 + 0xff0) + 0x74) = 0;
        }
        goto LAB_0002f1fc;
      }
      if (**(byte **)(param_1 + 0x1014) < 2) {
        if (*param_2 != 2) {
LAB_0002f4c2:
          if ((param_1[0x1245] != 0) || (*(char *)(*(int *)(param_1 + 0xff0) + 0x72) != '\0'))
          goto LAB_0002f534;
LAB_0002f4d2:
          if (param_1[0x10d6] != 0) {
            if ((((*param_2 != 1) || (cVar3 = FUN_000260dc(), cVar3 != '\0')) &&
                (cVar3 = FUN_000260dc(), cVar3 == '\0')) ||
               ((bVar4 = FUN_00035acc(), bVar4 != 1 && (cVar3 = FUN_00035a78(), cVar3 != '\x01'))))
            {
              if (param_1[0x10d6] == 0) goto LAB_0002f4dc;
              goto LAB_0002f61e;
            }
            FUN_00037830();
            if (*param_1 != 1) {
              if (param_1[0xd5] != 4) goto LAB_0002f6ce;
              pcVar8 = "goto message show task !";
LAB_0002e84e:
              if (BLE_DEBUG == 0) {
                printk(pcVar8);
              }
              else {
                ble_printk(pcVar8);
              }
              break;
            }
            sync_message_signal_to_slave(1,extraout_r1_76,extraout_r2_10);
            clear_timeout_message(0);
            uVar19 = FUN_0002dd98();
            FUN_000359fc((uint)uVar19,(int)((ulonglong)uVar19 >> 0x20));
            update_temp_task_status((int)param_1,4,2);
            pcVar8 = "IMU:wakeup:uncomplete msg";
            uVar12 = extraout_r3_42;
            goto LAB_0002e8a4;
          }
LAB_0002f4dc:
          cVar3 = FUN_00035a78();
          if (cVar3 == '\x01') {
            if (*param_1 == 1) {
              sync_message_signal_to_slave(0,extraout_r1_75,extraout_r2_09);
              update_temp_task_status((int)param_1,5,2);
              trigger_screen_state_change("BLE:wakeup:new-unread_msg",(int)param_1,1,extraout_r3_39)
              ;
              if (LOG_LEVEL < 1) break;
              pcVar8 = "process_for_IDLE";
              goto LAB_0002e2e0;
            }
            if (param_1[0xd5] == 5) {
              if (LOG_LEVEL < 1) break;
              pcVar8 = "process_for_IDLE";
              fmt = "%s(): goto new message come on task slave!\r\n\n";
              goto LAB_0002f498;
            }
          }
LAB_0002f6ce:
          if (param_1[0x10d6] == 0) goto LAB_0002f2e0;
LAB_0002f61e:
          if ((param_1[0xd5] != 4) ||
             (((*param_2 != 1 || (cVar3 = FUN_000260dc(), pbVar14 = extraout_r3_43, cVar3 != '\0'))
              && (cVar3 = FUN_000260dc(), pbVar14 = extraout_r3_41, cVar3 == '\0'))))
          goto LAB_0002f2e0;
          pcVar8 = "BLE:wakeup:next-unread_msg";
          goto LAB_0002f268;
        }
        pGVar7 = __get_dashboard_state();
        if ((pGVar7->field_0xfea != '\x05') && (bVar2 = FUN_00035ea4(), bVar2)) {
          FUN_00037830();
          if (*param_1 == 1) {
            sync_message_signal_to_slave(1,extraout_r1_74,extraout_r2_08);
            clear_timeout_message(0);
            uVar19 = FUN_0002dd98();
            FUN_000359fc((uint)uVar19,(int)((ulonglong)uVar19 >> 0x20));
            update_temp_task_status((int)param_1,4,2);
            trigger_screen_state_change("IMU:wakeup:uncomplete msg",(int)param_1,1,extraout_r3_38);
          }
          else if (param_1[0xd5] != 4) goto LAB_0002f2e0;
          if (LOG_LEVEL < 1) break;
          pcVar8 = "process_for_IDLE";
          fmt = "%s(): goto message show task !\n";
          goto LAB_0002f498;
        }
        if (*(char *)(*(int *)(param_1 + 0xff0) + 0x74) != '\0') goto LAB_0002f4d2;
        if (((*param_2 != 2) || (pGVar7 = __get_dashboard_state(), pGVar7->field_0xfea == '\x05'))
           || (cVar3 = FUN_000260dc(), cVar3 != '\0')) goto LAB_0002f4c2;
LAB_0002f534:
        if ((int)(DAT_20008518 << 0x1e) < 0) {
          DAT_20008518 = DAT_20008518 & 0xfffffffd;
        }
        if (*param_1 == 1) goto code_r0x0002f552;
        goto LAB_0002f5b0;
      }
      uVar9 = uVar17 + 1;
      sleep(0x32);
      if ((int)uVar9 < 100) {
        if (((uVar9 * -0x33333333 >> 3 | uVar9 * -0x60000000) < 0x6666667) && (1 < LOG_LEVEL)) {
          pcVar8 = "%s(): evenai v2 wait for starting other task\n";
          goto LAB_0002f3b6;
        }
      }
      else {
        **(undefined1 **)(param_1 + 0x1014) = 0;
      }
    } while( true );
  case 1:
    trigger_screen_state_change("WAIT_BLOW_HEAD",(int)param_1,0,(uint)param_1[0xd5]);
    while ((*param_2 != 1 && (pGVar7 = __get_dashboard_state(), pGVar7->field_0x1244 != '\x04'))) {
      if (((char)(*(int **)(param_1 + 0x1068))[1] == '\x02') &&
         (**(int **)(param_1 + 0x1068) == 0x10)) {
        param_1[0xd5] = 0x10;
        trigger_screen_state_change("BLE:wakeup:persist_task",(int)param_1,1,0x10);
        return 0;
      }
      z_impl_k_sleep(0x667,0);
    }
    uVar9 = 0;
LAB_0002e7a8:
    param_1[0xd5] = (byte)uVar9;
    break;
  case 2:
    while( true ) {
      if ((*(char *)(*(int *)(param_1 + 0xff4) + 5) == '\0') || (param_1[0xfee] != 10)) {
        sync_to_slave((char *)param_1,8,(undefined4 *)0x0,0);
        if (*param_2 == 2) {
          update_persist_task_status_to_wait_blow_head((int)param_1,extraout_r1_24,extraout_r2_01,2)
          ;
        }
        else {
          update_persist_task_status_to_idle((int)param_1,extraout_r1_24);
        }
        uVar9 = (uint)*param_1;
        if (uVar9 == 1) {
          z_impl_k_sleep(0x4000,0);
          uVar9 = extraout_r3_16;
        }
        pcVar8 = "countdown:trigger-off-imm";
        goto LAB_0002e1bc;
      }
      if ((param_1[1] == 1) ||
         (pGVar7 = __get_dashboard_state(), iVar10 = extraout_r1_22, pGVar7->field_0x1 == '\b')) {
        update_persist_task_status_to_idle((int)param_1,iVar10);
        pcVar8 = "countdown:imu-trigger-off-imm";
        uVar9 = extraout_r3_14;
        goto LAB_0002e1bc;
      }
      if (**(int **)(param_1 + 0xff4) == 0) {
        *(undefined1 *)((int)*(int **)(param_1 + 0xff4) + 5) = 0;
        update_persist_task_status((int)param_1,**(uint **)(param_1 + 0x1068),1);
        pcVar8 = "countdown:ts is over";
        uVar9 = extraout_r3_15;
        goto LAB_0002e1bc;
      }
      if (*param_2 == 2) break;
      uVar9 = 1;
      if (param_1[0xd5] == 1) goto LAB_0002e606;
      z_impl_k_sleep(0x667,0);
      iVar10 = extraout_r1_23;
    }
    if (param_1[0xdd] == 0) {
      pGVar7 = __get_dashboard_state();
      pGVar7->dashboard_ts->field_0x73 = 1;
      update_temp_task_status((int)param_1,6,2);
    }
    else {
      update_temp_task_status((int)param_1,4,2);
      FUN_0002dd98();
    }
    update_persist_task_status((int)param_1,**(uint **)(param_1 + 0x1068),3);
    break;
  default:
    z_impl_k_sleep(0x8000,0);
    if (iVar16 != 0xb) {
      return 0;
    }
    break;
  case 4:
    sVar15 = 1000;
    do {
      pGVar7 = __get_dashboard_state();
      if (pGVar7->field20_0xc8[0x15] == '\0') break;
      pGVar7 = __get_dashboard_state();
      cVar3 = FUN_00035218((byte)pGVar7->field20_0xc8[0x15] - 1);
      if (cVar3 == '\x04') break;
      sVar15 = sVar15 + -1;
      z_impl_k_sleep(0x21,0);
    } while (sVar15 != 0);
    iVar10 = 0;
    param_1[0xdc] = 0;
    FUN_00035abc(4);
    bVar4 = param_1[0xfee];
    pGVar7 = __get_dashboard_state();
    iVar16 = FUN_0002df54((uint)bVar4,(uint)(byte)pGVar7->field_0x10d7);
    param_1[0xdb] = (byte)iVar16;
    uVar12 = extraout_r1_09;
    while( true ) {
      while( true ) {
        if (param_1[0x10d6] == 0) {
          bVar2 = *param_2 == 1;
        }
        else {
          bVar4 = FUN_00035acc();
          bVar2 = bVar4 == 2;
          uVar12 = extraout_r1_10;
        }
        if (((!bVar2) && (param_1[0xdb] != 0)) || (param_1[0xfee] != 10)) break;
        if ((param_1[0xd5] == 6) ||
           ((param_1[0xd5] != 6 &&
            (((cVar3 = FUN_000260dc(), cVar3 == '\0' && (*param_2 == 2)) ||
             (*(short *)(param_1 + 0x1244) == 0x104)))))) {
          pGVar7 = __get_dashboard_state();
          if ((pGVar7->field_0x10d6 != '\0') &&
             (pGVar7 = __get_dashboard_state(), pGVar7->is_master == true)) {
            pGVar7 = __get_dashboard_state();
            uVar9 = *(uint *)&pGVar7->field_0x1078;
            *(uint *)&pGVar7->field_0x1078 = uVar9 - 1000;
            *(uint *)&pGVar7->field_0x107c =
                 *(int *)&pGVar7->field_0x107c + -1 + (uint)(999 < uVar9);
          }
          if (*param_1 == 1) {
            if (1 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): master sync canvas_distance_gear:%d,raster_height_gear:%d\n",
                       "process_for_message_show",(uint)param_1[0xec1],(uint)param_1[0xec0]);
              }
              else {
                ble_printk("%s(): master sync canvas_distance_gear:%d,raster_height_gear:%d\n",
                           "process_for_message_show");
              }
            }
            local_2c = CONCAT11(param_1[0xec1],0xb);
            local_2a = param_1[0xec0];
            sync_to_slave((char *)param_1,0xc,(undefined4 *)&local_2c,3);
            cal_panel_canvas_coord((int *)(param_1 + 0xec4),(int *)(param_1 + 0xeb8));
            if (*(char *)(*(int *)(param_1 + 0xff0) + 0x74) != '\0') {
              *(undefined1 *)(*(int *)(param_1 + 0xff0) + 0x74) = 0;
            }
          }
          z_impl_k_sleep(0x4000,0);
          pGVar7 = __get_dashboard_state();
          pGVar7->dashboard_ts->field_0x73 = 1;
          pGVar7 = __get_dashboard_state();
          update_temp_task_status((int)pGVar7,6,2);
          goto LAB_0002e246;
        }
        sync_to_slave((char *)param_1,8,(undefined4 *)0x0,0);
        if (*param_1 == 1) {
          update_persist_task_status_to_idle((int)param_1,extraout_r1_11);
        }
        else if (param_1[0xd5] == 4) goto LAB_0002e55a;
        FUN_00035abc(5);
        if (*param_1 == 1) {
          z_impl_k_sleep(0x4000,0);
        }
        cVar3 = FUN_00035a78();
        uVar12 = extraout_r1_12;
        uVar9 = extraout_r3_11;
        if (cVar3 != '\x04') goto LAB_0002e544;
      }
      if (((param_1[1] == 1) ||
          (pGVar7 = __get_dashboard_state(), uVar12 = extraout_r1_14, pGVar7->field_0x1 == '\b')) ||
         (pGVar7 = __get_dashboard_state(), uVar12 = extraout_r1_15, pGVar7->display_mode == '\f'))
      {
        update_persist_task_status_to_idle((int)param_1,uVar12);
        FUN_00035abc(5);
        uVar9 = extraout_r3_10;
        goto LAB_0002e544;
      }
      if (param_1[0xd5] != 4) break;
      iVar10 = iVar10 + 1;
      if (((param_1[0x10d6] != 0) && (*param_1 == 1)) &&
         ((((*param_2 == 1 && (cVar3 = FUN_000260dc(), cVar3 == '\0')) ||
           (cVar3 = FUN_000260dc(), cVar3 != '\0')) &&
          ((((uint)(iVar10 * -0x33333333) >> 2 | iVar10 * 0x40000000) < 0xccccccd &&
           (param_1[0xdb] < 0x1e)))))) {
        param_1[0xdb] = param_1[0xdb] - 1;
      }
LAB_0002e55a:
      z_impl_k_sleep(0x667,0);
      uVar12 = extraout_r1_13;
    }
    uVar9 = 0;
    if (param_1[0xd5] == 0) goto LAB_0002e544;
    break;
  case 5:
    bVar4 = param_1[0xfee];
    pGVar7 = __get_dashboard_state();
    iVar16 = FUN_0002df54((uint)bVar4,(uint)(byte)pGVar7->field_0x10d7);
    param_1[0xdb] = (byte)iVar16;
    FUN_00035abc(2);
    pGVar7 = __get_dashboard_state();
    iVar10 = 0;
    piVar6 = FUN_00035260((byte)pGVar7->field20_0xc8[0x15] - 1);
    uVar12 = extraout_r1_03;
    iVar16 = *piVar6;
LAB_0002e1ae:
    if (((param_1[1] == 1) ||
        (pGVar7 = __get_dashboard_state(), uVar12 = extraout_r1_04, pGVar7->field_0x1 == '\b')) ||
       (pGVar7 = __get_dashboard_state(), uVar12 = extraout_r1_05, pGVar7->display_mode == '\f')) {
      update_persist_task_status_to_idle((int)param_1,uVar12);
      pcVar8 = "message:imu-trigger-off-imm";
      uVar9 = extraout_r3_07;
      goto LAB_0002e1bc;
    }
    iVar18 = iVar16;
    if (*param_1 == 1) {
      pGVar7 = __get_dashboard_state();
      piVar6 = FUN_00035260((byte)pGVar7->field20_0xc8[0x15] - 1);
      iVar18 = *piVar6;
      if (iVar18 != iVar16) {
        bVar4 = param_1[0xfee];
        pGVar7 = __get_dashboard_state();
        iVar16 = FUN_0002df54((uint)bVar4,(uint)(byte)pGVar7->field_0x10d7);
        param_1[0xdb] = (byte)iVar16;
      }
    }
    if (param_1[0xd5] != 5) {
      if (0 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): goto next screen, new screen %d !\r\n\n","process_for_new_message_come_on",
                 (uint)param_1[0xd5]);
        }
        else {
          ble_printk("%s(): goto next screen, new screen %d !\r\n\n");
        }
      }
      break;
    }
    if ((*param_2 == 2) || (param_1[0xfee] == 0xb)) {
      FUN_00037830();
      if (param_1[0xb0d] == 1) {
        update_temp_task_status((int)param_1,8,2);
        FUN_00035abc(4);
        break;
      }
      if ((param_1[0xd5] == 5) && (*param_1 == 1)) goto code_r0x0002e2aa;
    }
    if (param_1[0xdb] != 0) goto LAB_0002e30c;
    goto LAB_0002e2ec;
  case 6:
    param_1[0xdc] = 0;
    if ((int)(DAT_20008518 << 0x1e) < 0) {
      DAT_20008518 = DAT_20008518 & 0xfffffffd;
    }
    bVar2 = false;
LAB_0002e5fa:
    if ((param_1[1] == 1) ||
       (pGVar7 = __get_dashboard_state(), iVar10 = extraout_r1_16, pGVar7->field_0x1 == '\b')) {
LAB_0002e600:
      update_persist_task_status_to_idle((int)param_1,iVar10);
      uVar9 = extraout_r3_12;
      goto LAB_0002e606;
    }
    if (!bVar2 && *(char *)(*(int *)(param_1 + 0xff0) + 0x72) == '\0') {
      if ((*param_2 != 1) || (cVar3 = FUN_000260dc(), cVar3 != '\0')) {
        pGVar7 = __get_dashboard_state();
        bVar2 = false;
        if ((pGVar7->field_0x1245 != '\0') ||
           (pGVar7 = __get_dashboard_state(), pGVar7->field_0x1244 != '\x04')) goto LAB_0002e646;
      }
LAB_0002e71c:
      if ((int)(DAT_20008518 << 0x1e) < 0) {
        DAT_20008518 = DAT_20008518 & 0xfffffffd;
      }
      bVar2 = FUN_0002d9e8((int)param_1);
      if ((!bVar2) || (*(char *)(*(int *)(param_1 + 0xff0) + 0x74) != '\0')) {
        FUN_00030458();
        sync_to_slave((char *)param_1,8,(undefined4 *)0x0,0);
        iVar10 = extraout_r1_19;
        goto LAB_0002e600;
      }
      goto LAB_0002e74c;
    }
    if (*(char *)(*(int *)(param_1 + 0xff0) + 0x72) == '\0') goto LAB_0002e71c;
    bVar2 = true;
LAB_0002e646:
    if (*(char *)(*(int *)(param_1 + 0xff0) + 0x74) == '\0') {
      bVar5 = FUN_0002d9e8((int)param_1);
      if (bVar5) {
        uVar9 = FUN_0002dd80(**(uint **)(param_1 + 0x1068));
        if (uVar9 == 0) {
          FUN_00030458();
        }
        uVar9 = *(uint *)(param_1 + 0xdf);
        if (uVar9 == 0xb) goto LAB_0002e7a8;
        switch(uVar9) {
        case 7:
          uVar9 = 7;
          goto LAB_0002e7a8;
        case 8:
          uVar9 = 8;
          goto LAB_0002e7a8;
        case 9:
          uVar9 = 9;
          goto LAB_0002e7a8;
        case 10:
          uVar9 = 10;
          goto LAB_0002e7a8;
        default:
          param_1[0xdc] = param_1[0xdc] + 1;
          break;
        case 0xc:
          uVar9 = 0xc;
          goto LAB_0002e7a8;
        case 0xe:
          uVar9 = 0xe;
          goto LAB_0002e7a8;
        case 0xf:
          uVar9 = 0xf;
          goto LAB_0002e7a8;
        case 0x10:
          uVar9 = 0x10;
          goto LAB_0002e7a8;
        case 0x11:
          uVar9 = 0x11;
          goto LAB_0002e7a8;
        case 0x12:
          uVar9 = 0x12;
          goto LAB_0002e7a8;
        case 0x13:
          uVar9 = 0x13;
          goto LAB_0002e7a8;
        case 0x14:
          uVar9 = 0x14;
          goto LAB_0002e7a8;
        }
      }
      if (param_1[0xd5] == 1) {
        uVar9 = 1;
        goto LAB_0002e606;
      }
    }
    bVar5 = __is_master();
    if ((bVar5) && (*(char *)(*(int *)(param_1 + 0xff0) + 0x74) == '\x01')) {
      *(undefined1 *)(*(int *)(param_1 + 0xff0) + 0x74) = 2;
    }
    if ((*(char *)(*(int *)(param_1 + 0xff0) + 0x74) == '\x02') &&
       (bVar5 = FUN_0002d9e8((int)param_1), bVar5)) {
      local_2c = 0x902;
      uVar9 = sync_to_slave((char *)param_1,6,(undefined4 *)&local_2c,2);
      if (2999 < (int)uVar9) {
        if (0 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): sync exit dashboard fail!\n","process_for_DASHBOARD_show");
          }
          else {
            ble_printk("%s(): sync exit dashboard fail!\n");
          }
        }
        goto LAB_0002e830;
      }
      uVar12 = extraout_r1_17;
      if (1 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): sync close dashboard!\n","process_for_DASHBOARD_show");
          uVar12 = extraout_r1_20;
        }
        else {
          ble_printk("%s(): sync close dashboard!\n");
          uVar12 = extraout_r1_18;
        }
      }
      display_close_screen(6,uVar12);
      while (*(char *)(*(int *)(param_1 + 0xff0) + 0x73) == '\x01') {
        z_impl_k_sleep(0x667,0);
      }
      *(undefined1 *)(*(int *)(param_1 + 0xff0) + 0x74) = 0;
LAB_0002e74c:
      uVar9 = FUN_0002dd80(**(uint **)(param_1 + 0x1068));
      if (uVar9 == 0) {
        FUN_00030458();
      }
      uVar9 = **(uint **)(param_1 + 0x1068) & 0xff;
      goto LAB_0002e7a8;
    }
LAB_0002e830:
    if (param_1[0xd5] == 4) {
      FUN_00030458();
      if (*param_1 == 2) {
        sleep(0x96);
      }
      pcVar8 = "goto message show task becasse screen id is E_ID_SCREEN_ANCS_NOTIFICATION!";
      goto LAB_0002e84e;
    }
    if (param_1[0xfea] == 1) {
      z_impl_k_sleep(0x667,0);
      return 0;
    }
    if ((DAT_20019a6c == '\0') || (uVar9 = FUN_000352f4(), uVar9 == 0)) goto LAB_0002e8aa;
    FUN_00030458();
    FUN_00037830();
    FUN_00035abc(6);
    update_temp_task_status((int)param_1,4,2);
    pcVar8 = "display msg by touch";
    uVar12 = extraout_r3_13;
    goto LAB_0002e8a4;
  case 7:
    *(undefined1 *)(*(int *)(param_1 + 0x1018) + 1) = 0;
    goto LAB_0002ec50;
  case 8:
    param_1[0xb0d] = 0;
    pGVar7 = __get_dashboard_state();
    uVar9 = FUN_00035310();
    pGVar7->field20_0xc8[0x15] = (char)uVar9;
    while ((*param_2 != 1 || (param_1[0xfee] != 10))) {
      z_impl_k_sleep(0x667,0);
    }
    sync_to_slave((char *)param_1,8,(undefined4 *)0x0,0);
    update_persist_task_status_to_idle((int)param_1,extraout_r1_41);
    uVar9 = (uint)*param_1;
    if (uVar9 == 1) {
      z_impl_k_sleep(0x4000,0);
      uVar9 = extraout_r3_26;
    }
LAB_0002e544:
    pcVar8 = "imu-trigger-off-imm";
    goto LAB_0002e1bc;
  case 9:
    iVar16 = *(int *)(param_1 + 0x1000);
    goto LAB_0002e994;
  case 10:
    pcVar8 = *(char **)(param_1 + 0x1004);
    goto LAB_0002eab2;
  case 0xb:
    goto LAB_0002e162;
  case 0xc:
    goto LAB_0002e14c;
  case 0xe:
    goto LAB_0002e136;
  case 0xf:
    goto LAB_0002e120;
  case 0x10:
    iVar16 = 0;
    goto LAB_0002ed72;
  case 0x11:
    goto LAB_0002e10a;
  case 0x12:
    goto LAB_0002e0f4;
  case 0x13:
    goto LAB_0002e0da;
  case 0x14:
    pGVar7 = __get_dashboard_state();
    if ((pGVar7->is_master == true) &&
       (pGVar7 = __get_dashboard_state(), (pGVar7->sem_2).count == 0)) {
      pGVar7 = __get_dashboard_state();
      k_sem_give(&pGVar7->sem_2);
    }
    iVar20 = k_uptime_get();
    uVar12 = (undefined4)((ulonglong)iVar20 >> 0x20);
    *(int64_t *)(*(int *)(param_1 + 0x1014) + 6) = iVar20;
    *(undefined1 *)(*(int *)(param_1 + 0xff0) + 0x74) = 0;
    goto LAB_0002eeea;
  }
LAB_0002e246:
  iVar16 = 0xb;
  goto LAB_0002e05a;
LAB_0002eeea:
  if ((param_1[1] == 1) ||
     (pGVar7 = __get_dashboard_state(), uVar12 = extraout_r1_59, pGVar7->field_0x1 == '\b'))
  goto LAB_0002eef0;
  if ((*param_1 == 1) && (**(char **)(param_1 + 0x1014) == '\x01')) {
    iVar20 = k_uptime_get();
    iVar16 = *(int *)(param_1 + 0x1014);
    lVar1 = iVar20 - *(longlong *)(iVar16 + 6);
    if ((int)((ulonglong)lVar1 >> 0x20) < (int)(uint)((uint)lVar1 < 0x1389)) {
LAB_0002ef8e:
      iVar20 = k_uptime_get();
      lVar1 = iVar20 - *(longlong *)(*(int *)(param_1 + 0x1014) + 6);
      if (((int)((ulonglong)lVar1 >> 0x20) < (int)(uint)((uint)lVar1 < 0x2711)) ||
         (*(char *)(*(int *)(param_1 + 0x1014) + 1) != '\x02')) goto LAB_0002ef46;
    }
    else {
      if (*(char *)(iVar16 + 1) == '\a') {
        bVar2 = *(char *)(iVar16 + 3) == '\x01';
      }
      else {
        if (*(char *)(iVar16 + 1) != '\x04') goto LAB_0002ef8e;
        bVar2 = *(char *)(iVar16 + 3) == '\x13';
      }
      if (!bVar2) goto LAB_0002ef8e;
    }
    **(undefined1 **)(param_1 + 0x1014) = 0;
  }
LAB_0002ef46:
  bVar2 = __is_master();
  if ((bVar2) && (**(char **)(param_1 + 0x1014) == '\x02')) {
    **(char **)(param_1 + 0x1014) = '\x03';
  }
  if ((**(char **)(param_1 + 0x1014) == '\0') || (**(char **)(param_1 + 0x1014) == '\x03')) {
    uVar9 = sync_to_slave((char *)param_1,8,(undefined4 *)0x0,0);
    if ((int)uVar9 < 3000) {
      update_persist_task_status_to_idle((int)param_1,extraout_r1_60);
      pcVar8 = "evenai_v2:self exit";
      uVar9 = extraout_r3_34;
      goto LAB_0002e1bc;
    }
    if (0 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): sync exit evenai_v2 fail!\n","process_for_even_ai_v2_show");
      }
      else {
        ble_printk("%s(): sync exit evenai_v2 fail!\n");
      }
    }
  }
  if (param_1[0xd5] == 1) {
    pcVar8 = "evenai_v2:imu-trigger-off-imm";
    uVar9 = 1;
    goto LAB_0002e1bc;
  }
  z_impl_k_sleep(0x667,0);
  uVar12 = extraout_r1_61;
  goto LAB_0002eeea;
LAB_0002eef0:
  update_persist_task_status_to_idle((int)param_1,uVar12);
  pcVar8 = "evenai_v2:dfu";
  uVar9 = extraout_r3_33;
  goto LAB_0002e1bc;
LAB_0002e0da:
  if ((param_1[1] == 1) ||
     (pGVar7 = __get_dashboard_state(), iVar10 = extraout_r1_68, pGVar7->field_0x1 == '\b'))
  goto LAB_0002e0e2;
  if (**(char **)(param_1 + 0x102c) == '\0') {
    sync_to_slave((char *)param_1,8,(undefined4 *)0x0,0);
    update_persist_task_status_to_idle((int)param_1,extraout_r1_69);
    uVar9 = (uint)*param_1;
    if (uVar9 == 1) {
      z_impl_k_sleep(0x4000,0);
      uVar9 = extraout_r3_37;
    }
    pcVar8 = "transcribe:self exit";
    goto LAB_0002e1bc;
  }
  if (param_1[0xd5] == 1) {
    pcVar8 = "transcribe:imu-trigger-off-imm";
    uVar9 = 1;
    goto LAB_0002e1bc;
  }
  z_impl_k_sleep(0x667,0);
  iVar10 = extraout_r1_70;
  goto LAB_0002e0da;
LAB_0002e0e2:
  update_persist_task_status_to_idle((int)param_1,iVar10);
  pcVar8 = "transcribe:dfu";
  uVar9 = extraout_r3_00;
  goto LAB_0002e1bc;
LAB_0002e0f4:
  if ((param_1[1] == 1) ||
     (pGVar7 = __get_dashboard_state(), iVar10 = extraout_r1_65, pGVar7->field_0x1 == '\b'))
  goto LAB_0002e0fc;
  if (*param_1 == 1) {
    if (**(char **)(param_1 + 0x1028) != '\0') {
      iVar20 = k_uptime_get();
      lVar1 = iVar20 - *(longlong *)(*(undefined1 **)(param_1 + 0x1028) + 2);
      if ((int)(uint)((uint)lVar1 < 0xfa1) <= (int)((ulonglong)lVar1 >> 0x20)) {
        **(undefined1 **)(param_1 + 0x1028) = 0;
      }
      goto LAB_0002f09e;
    }
LAB_0002f056:
    sync_to_slave((char *)param_1,8,(undefined4 *)0x0,0);
    update_persist_task_status_to_idle((int)param_1,extraout_r1_66);
    uVar9 = (uint)*param_1;
    if (uVar9 == 1) {
      z_impl_k_sleep(0x4000,0);
      uVar9 = extraout_r3_36;
    }
    pcVar8 = "prompt:self exit";
    goto LAB_0002e1bc;
  }
LAB_0002f09e:
  if (**(char **)(param_1 + 0x1028) == '\0') goto LAB_0002f056;
  if (param_1[0xd5] == 1) {
    pcVar8 = "prompt:imu-trigger-off-imm";
    uVar9 = 1;
    goto LAB_0002e1bc;
  }
  z_impl_k_sleep(0x667,0);
  iVar10 = extraout_r1_67;
  goto LAB_0002e0f4;
LAB_0002e0fc:
  update_persist_task_status_to_idle((int)param_1,iVar10);
  pcVar8 = "prompt:dfu";
  uVar9 = extraout_r3_01;
  goto LAB_0002e1bc;
LAB_0002e10a:
  if ((param_1[1] == 1) ||
     (pGVar7 = __get_dashboard_state(), iVar10 = extraout_r1_62, pGVar7->field_0x1 == '\b'))
  goto LAB_0002e112;
  if (**(char **)(param_1 + 0x1024) == '\0') {
    sync_to_slave((char *)param_1,8,(undefined4 *)0x0,0);
    update_persist_task_status_to_idle((int)param_1,extraout_r1_63);
    uVar9 = (uint)*param_1;
    if (uVar9 == 1) {
      z_impl_k_sleep(0x4000,0);
      uVar9 = extraout_r3_35;
    }
    pcVar8 = "set_imu_pitch:self exit";
    goto LAB_0002e1bc;
  }
  if (param_1[0xd5] == 1) {
    pcVar8 = "set_imu_pitch:imu-trigger-off-imm";
    uVar9 = 1;
    goto LAB_0002e1bc;
  }
  z_impl_k_sleep(0x667,0);
  iVar10 = extraout_r1_64;
  goto LAB_0002e10a;
LAB_0002e112:
  update_persist_task_status_to_idle((int)param_1,iVar10);
  pcVar8 = "set_imu_pitch:dfu";
  uVar9 = extraout_r3_02;
  goto LAB_0002e1bc;
LAB_0002ed72:
  if (param_1[0xfee] == 0xc) goto code_r0x0002ed7a;
  if ((param_1[1] == 1) ||
     (pGVar7 = __get_dashboard_state(), iVar10 = extraout_r1_51, pGVar7->field_0x1 == '\b'))
  goto LAB_0002eda6;
  bVar2 = FUN_00028d2c();
  uVar11 = extraout_r1_52;
  uVar12 = extraout_r2_04;
  if ((!bVar2) &&
     ((pGVar7 = __get_dashboard_state(), uVar11 = extraout_r1_53, uVar12 = extraout_r2_05,
      1 < **(byte **)&pGVar7->field_0x1010 &&
      (pGVar7 = __get_dashboard_state(), uVar11 = extraout_r1_54, uVar12 = extraout_r2_06,
      **(byte **)&pGVar7->field_0x1010 < 10)))) {
    pGVar7 = __get_dashboard_state();
    uVar12 = 10;
    **(undefined1 **)&pGVar7->field_0x1010 = 10;
    uVar11 = extraout_r1_55;
  }
  if (((*(char *)(*(int *)(param_1 + 0x1010) + 7) == '\0') ||
      (pGVar7 = __get_dashboard_state(), uVar11 = extraout_r1_57, uVar12 = extraout_r2_07,
      **(char **)&pGVar7->field_0x1010 == '\0')) ||
     (((uVar9 = (uint)**(byte **)(param_1 + 0x1010), uVar9 == 8 || (uVar9 == 0xb)) &&
      (uVar12 = 0, param_1[0xdb] == 0)))) {
    if (*param_1 == 1) {
      FUN_00029774(0,uVar11,uVar12);
    }
    sync_to_slave((char *)param_1,8,(undefined4 *)0x0,0);
    iVar10 = extraout_r1_56;
    goto LAB_0002eda6;
  }
  if (param_1[0xd5] == 1) {
    FUN_00080338(1);
    pcVar8 = "evenai:imu-trigger-off-imm";
    uVar9 = extraout_r3_32;
    goto LAB_0002e1bc;
  }
  iVar16 = iVar16 + 1;
  if ((*param_1 == 1) &&
     (((uVar9 - 7 < 2 || (uVar9 == 0xb)) &&
      (((uint)(iVar16 * -0x33333333) >> 2 | iVar16 * 0x40000000) < 0xccccccd)))) {
    param_1[0xdb] = param_1[0xdb] - 1;
  }
  z_impl_k_sleep(0x667,0);
  iVar10 = extraout_r1_58;
  goto LAB_0002ed72;
code_r0x0002ed7a:
  sync_to_slave((char *)param_1,8,(undefined4 *)0x0,0);
  iVar10 = extraout_r1_50;
  if (*param_2 == 2) {
    update_persist_task_status_to_wait_blow_head((int)param_1,extraout_r1_50,extraout_r2_03,2);
  }
  else {
LAB_0002eda6:
    update_persist_task_status_to_idle((int)param_1,iVar10);
  }
  FUN_00080338(1);
  pcVar8 = "evenai:self exit";
  uVar9 = extraout_r3_31;
  goto LAB_0002e1bc;
LAB_0002e120:
  if ((param_1[1] == 1) ||
     (pGVar7 = __get_dashboard_state(), iVar10 = extraout_r1_47, pGVar7->field_0x1 == '\b'))
  goto LAB_0002e128;
  if (**(char **)(param_1 + 0x1020) == '\0') {
    sync_to_slave((char *)param_1,8,(undefined4 *)0x0,0);
    update_persist_task_status_to_idle((int)param_1,extraout_r1_48);
    uVar9 = (uint)*param_1;
    if (uVar9 == 1) {
      z_impl_k_sleep(0x4000,0);
      uVar9 = extraout_r3_30;
    }
    pcVar8 = "raster_height:self exit";
    goto LAB_0002e1bc;
  }
  if (param_1[0xd5] == 1) {
    pcVar8 = "raster_height:imu-trigger-off-imm";
    uVar9 = 1;
    goto LAB_0002e1bc;
  }
  z_impl_k_sleep(0x667,0);
  iVar10 = extraout_r1_49;
  goto LAB_0002e120;
LAB_0002e128:
  update_persist_task_status_to_idle((int)param_1,iVar10);
  pcVar8 = "raster_height:dfu";
  uVar9 = extraout_r3_03;
  goto LAB_0002e1bc;
LAB_0002e136:
  if ((param_1[1] == 1) ||
     (pGVar7 = __get_dashboard_state(), iVar10 = extraout_r1_44, pGVar7->field_0x1 == '\b'))
  goto LAB_0002e13e;
  if (**(char **)(param_1 + 0x101c) == '\0') {
    sync_to_slave((char *)param_1,8,(undefined4 *)0x0,0);
    update_persist_task_status_to_idle((int)param_1,extraout_r1_45);
    uVar9 = (uint)*param_1;
    if (uVar9 == 1) {
      z_impl_k_sleep(0xccd,0);
      uVar9 = extraout_r3_29;
    }
    pcVar8 = "onboarding:self exit";
    goto LAB_0002e1bc;
  }
  if (param_1[0xd5] == 1) {
    pcVar8 = "onboarding:imu-trigger-off-imm";
    uVar9 = 1;
    goto LAB_0002e1bc;
  }
  z_impl_k_sleep(0x667,0);
  iVar10 = extraout_r1_46;
  goto LAB_0002e136;
LAB_0002e13e:
  update_persist_task_status_to_idle((int)param_1,iVar10);
  pcVar8 = "onboarding:dfu";
  uVar9 = extraout_r3_04;
  goto LAB_0002e1bc;
LAB_0002e14c:
  if ((param_1[1] == 1) ||
     (pGVar7 = __get_dashboard_state(), iVar10 = extraout_r1_29, pGVar7->field_0x1 == '\b'))
  goto LAB_0002e154;
  if (*(char *)(*(int *)(param_1 + 0x1034) + 1) == '\0') {
    if (*param_2 == 2) {
      sync_to_slave((char *)param_1,8,(undefined4 *)0x0,0);
      if (*param_2 == 2) {
        update_persist_task_status_to_wait_blow_head((int)param_1,extraout_r1_30,extraout_r2_02,2);
        uVar12 = extraout_r3_19;
      }
      else {
        update_persist_task_status_to_idle((int)param_1,extraout_r1_30);
        uVar12 = extraout_r3_21;
      }
      trigger_screen_state_change("IMU:wakeup:dashboard",(int)param_1,1,uVar12);
    }
    else {
      sync_to_slave((char *)param_1,8,(undefined4 *)0x0,0);
      update_persist_task_status_to_idle((int)param_1,extraout_r1_31);
    }
    uVar9 = (uint)*param_1;
    if (uVar9 == 1) {
      z_impl_k_sleep(0x4000,0);
      uVar9 = extraout_r3_20;
    }
    pcVar8 = "quicknote:self exit";
    goto LAB_0002e1bc;
  }
  uVar9 = 1;
  if (param_1[0xd5] == 1) goto LAB_0002e606;
  z_impl_k_sleep(0x667,0);
  iVar10 = extraout_r1_32;
  goto LAB_0002e14c;
LAB_0002e154:
  update_persist_task_status_to_idle((int)param_1,iVar10);
  pcVar8 = "quicknote:imu-trigger-off-imm";
  uVar9 = extraout_r3_05;
  goto LAB_0002e1bc;
LAB_0002e162:
  if ((param_1[1] == 1) ||
     (pGVar7 = __get_dashboard_state(), iVar10 = extraout_r1_37, pGVar7->field_0x1 == '\b'))
  goto LAB_0002e16a;
  if ((*(char *)(*(int *)(param_1 + 0x1008) + 6) == '\0') &&
     (*(char *)(*(int *)(param_1 + 0x100c) + 6) == '\0')) {
    if (*param_2 == 2) {
      sync_to_slave((char *)param_1,8,(undefined4 *)0x0,0);
      update_persist_task_status_to_idle((int)param_1,extraout_r1_38);
      if (*param_1 == 1) {
        z_impl_k_sleep(0x4000,0);
      }
      iVar16 = 0x2667;
    }
    else {
      sync_to_slave((char *)param_1,8,(undefined4 *)0x0,0);
      update_persist_task_status_to_idle((int)param_1,extraout_r1_39);
      uVar9 = (uint)*param_1;
      if (uVar9 != 1) goto LAB_0002e170;
      iVar16 = 0x4000;
    }
    z_impl_k_sleep(iVar16,0);
    uVar9 = extraout_r3_25;
    goto LAB_0002e170;
  }
  uVar9 = 1;
  if (param_1[0xd5] == 1) goto LAB_0002e606;
  z_impl_k_sleep(0x667,0);
  iVar10 = extraout_r1_40;
  goto LAB_0002e162;
LAB_0002eab2:
  if ((param_1[1] == 1) ||
     (pGVar7 = __get_dashboard_state(), iVar10 = extraout_r1_33, pGVar7->field_0x1 == '\b'))
  goto LAB_0002eab8;
  if (*pcVar8 == '\0') {
    if (*param_2 == 2) {
      sync_to_slave((char *)param_1,8,(undefined4 *)0x0,0);
      update_persist_task_status_to_idle((int)param_1,extraout_r1_34);
      trigger_screen_state_change("IMU:wakeup:dashboard",(int)param_1,1,extraout_r3_23);
      if (*param_1 == 1) {
        z_impl_k_sleep(0x4000,0);
      }
      iVar16 = 0x2667;
LAB_0002eb3a:
      z_impl_k_sleep(iVar16,0);
      uVar9 = extraout_r3_24;
    }
    else {
      sync_to_slave((char *)param_1,8,(undefined4 *)0x0,0);
      update_persist_task_status_to_idle((int)param_1,extraout_r1_35);
      uVar9 = (uint)*param_1;
      if (uVar9 == 1) {
        iVar16 = 0x4000;
        goto LAB_0002eb3a;
      }
    }
    pcVar8 = "navigation:self exit";
    goto LAB_0002e1bc;
  }
  uVar9 = 1;
  if (param_1[0xd5] == 1) goto LAB_0002e606;
  z_impl_k_sleep(0x667,0);
  iVar10 = extraout_r1_36;
  goto LAB_0002eab2;
LAB_0002eab8:
  update_persist_task_status_to_idle((int)param_1,iVar10);
  pcVar8 = "navigation:imu-trigger-off-imm";
  uVar9 = extraout_r3_22;
  goto LAB_0002e1bc;
LAB_0002e994:
  if ((param_1[1] == 1) ||
     (pGVar7 = __get_dashboard_state(), iVar10 = extraout_r1_25, pGVar7->field_0x1 == '\b'))
  goto LAB_0002e99a;
  if (*(char *)(iVar16 + 1) == '\0') {
    FUN_00030458();
    if (*param_2 == 2) {
      trigger_screen_state_change("IMU:wakeup:dashboard",(int)param_1,1,2);
      FUN_0003f23c();
      sync_to_slave((char *)param_1,8,(undefined4 *)0x0,0);
      update_persist_task_status_to_idle((int)param_1,extraout_r1_26);
      if (*param_1 == 1) {
        z_impl_k_sleep(0x4000,0);
      }
      iVar16 = 0x2667;
LAB_0002e9f0:
      z_impl_k_sleep(iVar16,0);
      uVar9 = extraout_r3_18;
    }
    else {
      sync_to_slave((char *)param_1,8,(undefined4 *)0x0,0);
      update_persist_task_status_to_idle((int)param_1,extraout_r1_27);
      FUN_0003f23c();
      uVar9 = (uint)*param_1;
      if (uVar9 == 1) {
        iVar16 = 0x4000;
        goto LAB_0002e9f0;
      }
    }
    pcVar8 = "temeprompter:self exit";
    goto LAB_0002e1bc;
  }
  uVar9 = 1;
  if (param_1[0xd5] == 1) goto LAB_0002e606;
  z_impl_k_sleep(0x667,0);
  iVar10 = extraout_r1_28;
  goto LAB_0002e994;
LAB_0002e99a:
  update_persist_task_status_to_idle((int)param_1,iVar10);
  pcVar8 = "teleprompter:imu-trigger-off-imm";
  uVar9 = extraout_r3_17;
  goto LAB_0002e1bc;
LAB_0002ec50:
  if (**(char **)(param_1 + 0x1018) != '\0') {
    iVar20 = k_uptime_get();
    lVar1 = iVar20 - *(longlong *)(*(undefined1 **)(param_1 + 0x1018) + 3);
    iVar16 = (int)((ulonglong)lVar1 >> 0x20);
    bVar2 = (uint)lVar1 < 0x5dd;
    iVar10 = iVar16 - (uint)bVar2;
    if ((int)(uint)bVar2 <= iVar16) {
      **(undefined1 **)(param_1 + 0x1018) = 0;
    }
  }
  if ((param_1[1] == 1) ||
     (pGVar7 = __get_dashboard_state(), iVar10 = extraout_r1_42, pGVar7->field_0x1 == '\b')) {
    update_persist_task_status_to_idle((int)param_1,iVar10);
    pcVar8 = "not_disturb:dfu";
    uVar9 = extraout_r3_27;
    goto LAB_0002e1bc;
  }
  if (**(char **)(param_1 + 0x1018) == '\0') {
    update_persist_task_status_to_idle((int)param_1,extraout_r1_42);
    pcVar8 = "not_disturb:self exit";
    uVar9 = extraout_r3_28;
    goto LAB_0002e1bc;
  }
  if (param_1[0xd5] == 1) goto LAB_0002ecb6;
  z_impl_k_sleep(0x667,0);
  iVar10 = extraout_r1_43;
  goto LAB_0002ec50;
LAB_0002ecb6:
  pcVar8 = "not_disturb:imu-trigger-off-imm";
  uVar9 = 1;
  goto LAB_0002e1bc;
LAB_0002e8aa:
  __get_dashboard_state();
  z_impl_k_sleep(0x667,0);
  iVar10 = extraout_r1_21;
  goto LAB_0002e5fa;
code_r0x0002e2aa:
  sync_message_signal_to_slave(1,extraout_r1_06,extraout_r2);
  clear_timeout_message(0);
  uVar19 = FUN_0002dd98();
  FUN_000359fc((uint)uVar19,(int)((ulonglong)uVar19 >> 0x20));
  update_temp_task_status((int)param_1,4,2);
  trigger_screen_state_change("IMU:wakeup:new-notification",(int)param_1,1,extraout_r3_08);
  if (0 < LOG_LEVEL) {
    pcVar8 = "process_for_new_message_come_on";
LAB_0002e2e0:
    fmt = "%s(): goto new message come on task master!\r\n\n";
LAB_0002f498:
    if (BLE_DEBUG == 0) {
      printk(fmt,pcVar8);
    }
    else {
      ble_printk(fmt);
    }
  }
  goto LAB_0002e246;
LAB_0002e30c:
  z_impl_k_sleep(0x667,0);
  iVar10 = iVar10 + 1;
  if (((*param_1 == 1) && (((uint)(iVar10 * -0x33333333) >> 2 | iVar10 * 0x40000000) < 0xccccccd))
     && (param_1[0xdb] != 0)) {
    param_1[0xdb] = param_1[0xdb] - 1;
  }
  uVar12 = extraout_r1_08;
  iVar16 = iVar18;
  if (param_1[0xdb] == 0) {
    param_1[0xb0d] = 0;
LAB_0002e2ec:
    sync_to_slave((char *)param_1,8,(undefined4 *)0x0,0);
    if (*param_2 == 2) {
      update_persist_task_status_to_wait_blow_head((int)param_1,extraout_r1_07,extraout_r2_00,2);
    }
    else {
      update_persist_task_status_to_idle((int)param_1,extraout_r1_07);
    }
    FUN_00035abc(6);
    pcVar8 = "new-msg-timeout-goto-idle";
    uVar9 = extraout_r3_09;
    goto LAB_0002e1bc;
  }
  goto LAB_0002e1ae;
LAB_0002e606:
  pcVar8 = "dashboard:imu-trigger-off-imm";
  goto LAB_0002e1bc;
code_r0x0002f552:
  if (1 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): master sync canvas_distance_gear:%d,raster_height_gear:%d\n","process_for_IDLE",
             (uint)param_1[0xec1],(uint)param_1[0xec0]);
    }
    else {
      ble_printk("%s(): master sync canvas_distance_gear:%d,raster_height_gear:%d\n",
                 "process_for_IDLE");
    }
  }
  local_2c = CONCAT11(param_1[0xec1],0xb);
  local_2a = param_1[0xec0];
  sync_to_slave((char *)param_1,0xc,(undefined4 *)&local_2c,3);
  cal_panel_canvas_coord((int *)(param_1 + 0xec4),(int *)(param_1 + 0xeb8));
  bVar2 = FUN_0002d9e8((int)param_1);
  uVar9 = uVar17;
  if (!bVar2) goto LAB_0002f5b0;
  goto LAB_0002f1fc;
LAB_0002f5b0:
  pGVar7 = __get_dashboard_state();
  if (((pGVar7->is_master == true) && (bVar2 = FUN_00028d2c(), bVar2)) &&
     ((pGVar7 = __get_dashboard_state(), pGVar7[1].is_master == false &&
      (cVar3 = FUN_00030440(), cVar3 == '\x01')))) {
    FUN_0008040c();
  }
  pGVar7 = __get_dashboard_state();
  pGVar7->dashboard_ts->field_0x73 = 1;
  update_temp_task_status((int)param_1,6,2);
  pcVar8 = "IMU:wakeup:dashboard";
  uVar12 = extraout_r3_40;
LAB_0002e8a4:
  trigger_screen_state_change(pcVar8,(int)param_1,1,uVar12);
  goto LAB_0002e246;
LAB_0002e16a:
  update_persist_task_status_to_idle((int)param_1,iVar10);
  uVar9 = extraout_r3_06;
LAB_0002e170:
  pcVar8 = "translate:self exit";
LAB_0002e1bc:
  trigger_screen_state_change(pcVar8,(int)param_1,0,uVar9);
  sleep(0x96);
  cVar3 = FUN_00035a78();
  if (cVar3 == '\x01') {
    bVar4 = FUN_00035acc();
    if (bVar4 == 1) {
      iVar16 = 5;
    }
    else {
      pGVar7 = __get_dashboard_state();
      iVar16 = 0;
      if (pGVar7->field20_0xc8[0x15] != '\0') {
        iVar16 = 6;
      }
    }
    FUN_00035abc(iVar16);
  }
  return 0;
}


