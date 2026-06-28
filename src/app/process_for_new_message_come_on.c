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
  char *pcVar7;
  GlassesState *pGVar8;
  char *pcVar9;
  uint uVar10;
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
  char *extraout_r1_21;
  char *extraout_r1_22;
  int extraout_r1_23;
  int extraout_r1_24;
  int extraout_r1_25;
  undefined4 extraout_r1_26;
  int extraout_r1_27;
  undefined4 extraout_r1_28;
  undefined4 extraout_r1_29;
  int extraout_r1_30;
  int extraout_r1_31;
  undefined4 extraout_r1_32;
  undefined4 extraout_r1_33;
  int extraout_r1_34;
  int extraout_r1_35;
  undefined4 extraout_r1_36;
  undefined4 extraout_r1_37;
  int extraout_r1_38;
  int extraout_r1_39;
  undefined4 extraout_r1_40;
  undefined4 extraout_r1_41;
  int extraout_r1_42;
  undefined4 extraout_r1_43;
  int iVar11;
  int extraout_r1_44;
  int extraout_r1_45;
  int extraout_r1_46;
  undefined4 extraout_r1_47;
  int extraout_r1_48;
  int extraout_r1_49;
  undefined4 extraout_r1_50;
  int extraout_r1_51;
  int extraout_r1_52;
  int extraout_r1_53;
  undefined4 extraout_r1_54;
  undefined4 extraout_r1_55;
  undefined4 extraout_r1_56;
  undefined4 extraout_r1_57;
  undefined4 uVar12;
  int extraout_r1_58;
  undefined4 extraout_r1_59;
  int extraout_r1_60;
  undefined4 extraout_r1_61;
  undefined4 extraout_r1_62;
  undefined4 extraout_r1_63;
  int extraout_r1_64;
  undefined4 extraout_r1_65;
  int extraout_r1_66;
  int extraout_r1_67;
  undefined4 extraout_r1_68;
  int extraout_r1_69;
  int extraout_r1_70;
  undefined4 extraout_r1_71;
  int extraout_r1_72;
  undefined4 extraout_r1_73;
  undefined4 extraout_r1_74;
  undefined4 extraout_r1_75;
  uint extraout_r1_76;
  uint extraout_r1_77;
  char *extraout_r1_78;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 extraout_r2_02;
  undefined4 extraout_r2_03;
  undefined4 extraout_r2_04;
  undefined4 extraout_r2_05;
  undefined4 extraout_r2_06;
  undefined4 uVar13;
  undefined4 extraout_r2_07;
  undefined4 extraout_r2_08;
  undefined1 *puVar14;
  undefined4 extraout_r2_09;
  undefined4 extraout_r2_10;
  undefined4 extraout_r2_11;
  undefined4 extraout_r2_12;
  undefined4 extraout_r2_13;
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
  byte *pbVar15;
  undefined4 extraout_r3_38;
  undefined4 extraout_r3_39;
  undefined4 extraout_r3_40;
  byte *extraout_r3_41;
  undefined4 extraout_r3_42;
  byte *extraout_r3_43;
  short sVar16;
  int iVar17;
  uint uVar18;
  int iVar19;
  int64_t iVar20;
  undefined2 local_2c;
  byte local_2a;
  
  iVar17 = 0;
LAB_0002e05a:
  memset(param_1 + 0xef,0,0x5dc);
  clear_timeout_message(0);
  iVar11 = extraout_r1;
  if (*param_1 == 1) {
    __check_showing_message();
    iVar11 = extraout_r1_00;
  }
  if (param_1[0xd5] != 4) {
    DAT_20019a6d = 0;
  }
  if ((param_1[0xfec] == 0) && (bVar2 = FUN_0002da10((int)param_1), iVar11 = extraout_r1_01, bVar2))
  {
    trigger_screen_state_change("BLE:wakeup:running_task",(int)param_1,1,extraout_r3);
    iVar11 = extraout_r1_02;
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
        pGVar8 = __get_dashboard_state();
        if ((*(char *)pGVar8 == '\x02') &&
           (pGVar8 = __get_dashboard_state(), (pGVar8->sem_2).count == 0)) {
          pGVar8 = __get_dashboard_state();
          k_sem_give(&pGVar8->sem_2);
        }
      }
      param_1[0xd5] = 0;
      puVar14 = *(undefined1 **)(param_1 + 0x1068);
      *puVar14 = 0;
      puVar14[1] = 0;
      puVar14[2] = 0;
      puVar14[3] = 0;
      *(undefined1 *)(*(int *)(param_1 + 0x1068) + 4) = 1;
      bVar4 = FUN_00035acc();
      if (bVar4 == 1) {
        iVar17 = 5;
      }
      else {
        pGVar8 = __get_dashboard_state();
        iVar17 = 0;
        if (pGVar8->field_0xdd != '\0') {
          iVar17 = 6;
        }
      }
      FUN_00035abc(iVar17);
      FUN_0002ddb0();
      if (*param_2 != 2) {
        iVar17 = 100;
        do {
          if (param_1[0xfea] == 1) break;
          sleep(10);
          iVar17 = iVar17 + -1;
        } while (iVar17 != 0);
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
                     (uint)*(byte *)(piVar6 + 1));
        }
      }
    }
    DAT_20019a6d = 0;
    uVar10 = 0;
LAB_0002f1fc:
    do {
      while( true ) {
        uVar18 = uVar10;
        if ((param_1[1] == 1) || (pGVar8 = __get_dashboard_state(), pGVar8->field_0x1 == '\b'))
        goto LAB_0002f26c;
        bVar2 = is_in_box();
        if ((!bVar2) && ((param_1[0xfee] != 0xc || ((*piVar6 == 7 && (param_1[0xd5] == 7))))))
        break;
LAB_0002f2e0:
        if (*param_1 == 1) {
          (**(code **)(param_2 + 0x98))(param_2,0x50);
        }
        z_impl_k_sleep(0x667,0);
        uVar10 = uVar18 + 1;
      }
      bVar2 = FUN_0002d9e8((int)param_1);
      if (bVar2) {
        param_1[0xd5] = (byte)*piVar6;
        if (*(char *)(*(int *)(param_1 + 0xff0) + 0x74) != '\0') {
          *(undefined1 *)(*(int *)(param_1 + 0xff0) + 0x74) = 0;
        }
        pbVar15 = *(byte **)(param_1 + 0x1014);
        pcVar9 = "BLE:wakeup:persist_task";
        if (1 < *pbVar15) {
          *pbVar15 = 0;
        }
LAB_0002f268:
        trigger_screen_state_change(pcVar9,(int)param_1,1,pbVar15);
LAB_0002f26c:
        if (*param_1 != 1) {
          return 0;
        }
        (**(code **)(param_2 + 0x98))(param_2,0x26);
        return 0;
      }
      bVar4 = FUN_00033d5c();
      puVar14 = (undefined1 *)(uint)bVar4;
      if (puVar14 == &DAT_00000001) goto LAB_0002f2e0;
      uVar13 = extraout_r1_73;
      if (*(char *)(*(int *)(param_1 + 0x101c) + 1) != '\0') {
LAB_0002f2da:
        uVar18 = uVar18 + 1;
        if (((uVar18 & 0x1f) == 0) && (0 < LOG_LEVEL)) {
          bVar4 = *(byte *)(*(int *)(param_1 + 0x101c) + 1);
          if (BLE_DEBUG == 0) {
            uVar13 = FUN_0007f3da(puVar14,uVar13);
            pGVar8 = __get_dashboard_state();
            printk("%s(): There is an unfinished task,skip the local tasks:%d,%d,%d\n",
                   "process_for_IDLE",(uint)bVar4,uVar13,
                   (uint)*(byte *)(*(int *)&pGVar8->field_0x1018 + 1));
          }
          else {
            uVar13 = FUN_0007f3da(puVar14,uVar13);
            __get_dashboard_state();
            ble_printk("%s(): There is an unfinished task,skip the local tasks:%d,%d,%d\n",
                       "process_for_IDLE",(uint)bVar4,uVar13);
          }
        }
        goto LAB_0002f2e0;
      }
      iVar17 = FUN_0007f3da(puVar14,extraout_r1_73);
      puVar14 = (undefined1 *)0x0;
      uVar13 = extraout_r1_74;
      if (iVar17 == 0) goto LAB_0002f2da;
      pGVar8 = __get_dashboard_state();
      puVar14 = &pGVar8->field_0x1000;
      uVar13 = extraout_r1_75;
      if (*(char *)(*(int *)&pGVar8->field_0x1018 + 1) != '\0') goto LAB_0002f2da;
      if (*(char *)(*(int *)(param_1 + 0xff0) + 0x74) != '\0') {
        uVar10 = uVar18 + 1;
        sleep(0x32);
        if ((int)uVar10 < 0x50) {
          if (((uVar10 * -0x33333333 >> 3 | uVar10 * -0x60000000) < 0x6666667) && (1 < LOG_LEVEL)) {
            pcVar9 = "%s(): dashboard wait for starting other task\n";
LAB_0002f3b6:
            uVar10 = uVar18 + 1;
            if (BLE_DEBUG == 0) {
              printk(pcVar9);
            }
            else {
              ble_printk(pcVar9,"process_for_IDLE",0x6666666,BLE_DEBUG);
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
              pcVar7 = "goto message show task !";
              pcVar9 = extraout_r1_78;
              uVar13 = extraout_r2_13;
LAB_0002e84e:
              if (BLE_DEBUG == 0) {
                printk(pcVar7);
              }
              else {
                ble_printk(pcVar7,pcVar9,uVar13,BLE_DEBUG);
              }
              break;
            }
            sync_message_signal_to_slave(1,(uint)extraout_r1_78,extraout_r2_13);
            clear_timeout_message(0);
            FUN_0002dd98();
            FUN_000359fc();
            update_temp_task_status((int)param_1,4,2);
            pcVar9 = "IMU:wakeup:uncomplete msg";
            uVar13 = extraout_r3_42;
            goto LAB_0002e8a4;
          }
LAB_0002f4dc:
          cVar3 = FUN_00035a78();
          if (cVar3 == '\x01') {
            if (*param_1 == 1) {
              sync_message_signal_to_slave(0,extraout_r1_77,extraout_r2_11);
              update_temp_task_status((int)param_1,5,2);
              trigger_screen_state_change("BLE:wakeup:new-unread_msg",(int)param_1,1,extraout_r3_39)
              ;
              if (LOG_LEVEL < 1) break;
              pcVar9 = "process_for_IDLE";
              uVar13 = extraout_r2_12;
              goto LAB_0002e2e0;
            }
            if (param_1[0xd5] == 5) {
              if (LOG_LEVEL < 1) break;
              pcVar9 = "process_for_IDLE";
              pcVar7 = "%s(): goto new message come on task slave!\r\n\n";
              uVar13 = extraout_r2_11;
              goto LAB_0002f498;
            }
          }
LAB_0002f6ce:
          if (param_1[0x10d6] == 0) goto LAB_0002f2e0;
LAB_0002f61e:
          if ((param_1[0xd5] != 4) ||
             (((*param_2 != 1 || (cVar3 = FUN_000260dc(), pbVar15 = extraout_r3_43, cVar3 != '\0'))
              && (cVar3 = FUN_000260dc(), pbVar15 = extraout_r3_41, cVar3 == '\0'))))
          goto LAB_0002f2e0;
          pcVar9 = "BLE:wakeup:next-unread_msg";
          goto LAB_0002f268;
        }
        pGVar8 = __get_dashboard_state();
        if ((pGVar8->field_0xfea != '\x05') && (bVar2 = FUN_00035ea4(), bVar2)) {
          FUN_00037830();
          if (*param_1 == 1) {
            sync_message_signal_to_slave(1,extraout_r1_76,extraout_r2_09);
            clear_timeout_message(0);
            FUN_0002dd98();
            FUN_000359fc();
            update_temp_task_status((int)param_1,4,2);
            trigger_screen_state_change("IMU:wakeup:uncomplete msg",(int)param_1,1,extraout_r3_38);
            uVar13 = extraout_r2_10;
          }
          else {
            uVar13 = extraout_r2_09;
            if (param_1[0xd5] != 4) goto LAB_0002f2e0;
          }
          if (LOG_LEVEL < 1) break;
          pcVar9 = "process_for_IDLE";
          pcVar7 = "%s(): goto message show task !\n";
          goto LAB_0002f498;
        }
        if (*(char *)(*(int *)(param_1 + 0xff0) + 0x74) != '\0') goto LAB_0002f4d2;
        if (((*param_2 != 2) || (pGVar8 = __get_dashboard_state(), pGVar8->field_0xfea == '\x05'))
           || (cVar3 = FUN_000260dc(), cVar3 != '\0')) goto LAB_0002f4c2;
LAB_0002f534:
        if ((int)(DAT_20008518 << 0x1e) < 0) {
          DAT_20008518 = DAT_20008518 & 0xfffffffd;
        }
        if (*param_1 == 1) goto code_r0x0002f552;
        goto LAB_0002f5b0;
      }
      uVar10 = uVar18 + 1;
      sleep(0x32);
      if ((int)uVar10 < 100) {
        if (((uVar10 * -0x33333333 >> 3 | uVar10 * -0x60000000) < 0x6666667) && (1 < LOG_LEVEL)) {
          pcVar9 = "%s(): evenai v2 wait for starting other task\n";
          goto LAB_0002f3b6;
        }
      }
      else {
        **(undefined1 **)(param_1 + 0x1014) = 0;
      }
    } while( true );
  case 1:
    trigger_screen_state_change("WAIT_BLOW_HEAD",(int)param_1,0,(uint)param_1[0xd5]);
    while ((*param_2 != 1 && (pGVar8 = __get_dashboard_state(), pGVar8->field_0x1244 != '\x04'))) {
      if (((char)(*(int **)(param_1 + 0x1068))[1] == '\x02') &&
         (**(int **)(param_1 + 0x1068) == 0x10)) {
        param_1[0xd5] = 0x10;
        trigger_screen_state_change("BLE:wakeup:persist_task",(int)param_1,1,0x10);
        return 0;
      }
      z_impl_k_sleep(0x667,0);
    }
    uVar10 = 0;
LAB_0002e7a8:
    param_1[0xd5] = (byte)uVar10;
    break;
  case 2:
    while( true ) {
      if ((*(char *)(*(int *)(param_1 + 0xff4) + 5) == '\0') || (param_1[0xfee] != 10)) {
        sync_to_slave((char *)param_1,8,(undefined4 *)0x0,0);
        if (*param_2 == 2) {
          update_persist_task_status_to_wait_blow_head((int)param_1,extraout_r1_26);
        }
        else {
          update_persist_task_status_to_idle((int)param_1,extraout_r1_26);
        }
        uVar10 = (uint)*param_1;
        if (uVar10 == 1) {
          z_impl_k_sleep(0x4000,0);
          uVar10 = extraout_r3_16;
        }
        pcVar9 = "countdown:trigger-off-imm";
        goto LAB_0002e1bc;
      }
      if ((param_1[1] == 1) ||
         (pGVar8 = __get_dashboard_state(), iVar11 = extraout_r1_24, pGVar8->field_0x1 == '\b')) {
        update_persist_task_status_to_idle((int)param_1,iVar11);
        pcVar9 = "countdown:imu-trigger-off-imm";
        uVar10 = extraout_r3_14;
        goto LAB_0002e1bc;
      }
      if (**(int **)(param_1 + 0xff4) == 0) {
        *(undefined1 *)((int)*(int **)(param_1 + 0xff4) + 5) = 0;
        update_persist_task_status((int)param_1,**(uint **)(param_1 + 0x1068),1);
        pcVar9 = "countdown:ts is over";
        uVar10 = extraout_r3_15;
        goto LAB_0002e1bc;
      }
      if (*param_2 == 2) break;
      uVar10 = 1;
      if (param_1[0xd5] == 1) goto LAB_0002e606;
      z_impl_k_sleep(0x667,0);
      iVar11 = extraout_r1_25;
    }
    if (param_1[0xdd] == 0) {
      pGVar8 = __get_dashboard_state();
      pGVar8->dashboard_ts->field_0x73 = 1;
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
    if (iVar17 != 0xb) {
      return 0;
    }
    break;
  case 4:
    sVar16 = 1000;
    do {
      pGVar8 = __get_dashboard_state();
      if (pGVar8->field_0xdd == '\0') break;
      pGVar8 = __get_dashboard_state();
      cVar3 = FUN_00035218((byte)pGVar8->field_0xdd - 1);
      if (cVar3 == '\x04') break;
      sVar16 = sVar16 + -1;
      z_impl_k_sleep(0x21,0);
    } while (sVar16 != 0);
    iVar11 = 0;
    param_1[0xdc] = 0;
    FUN_00035abc(4);
    bVar4 = param_1[0xfee];
    pGVar8 = __get_dashboard_state();
    iVar17 = FUN_0002df54((uint)bVar4,(uint)(byte)pGVar8->field_0x10d7);
    param_1[0xdb] = (byte)iVar17;
    uVar13 = extraout_r1_09;
    while( true ) {
      while( true ) {
        if (param_1[0x10d6] == 0) {
          bVar2 = *param_2 == 1;
        }
        else {
          bVar4 = FUN_00035acc();
          bVar2 = bVar4 == 2;
          uVar13 = extraout_r1_10;
        }
        if (((!bVar2) && (param_1[0xdb] != 0)) || (param_1[0xfee] != 10)) break;
        if ((param_1[0xd5] == 6) ||
           ((param_1[0xd5] != 6 &&
            (((cVar3 = FUN_000260dc(), cVar3 == '\0' && (*param_2 == 2)) ||
             (*(short *)(param_1 + 0x1244) == 0x104)))))) {
          pGVar8 = __get_dashboard_state();
          if ((pGVar8->field_0x10d6 != '\0') &&
             (pGVar8 = __get_dashboard_state(), *(char *)pGVar8 == '\x01')) {
            pGVar8 = __get_dashboard_state();
            uVar10 = *(uint *)&pGVar8->field_0x1078;
            *(uint *)&pGVar8->field_0x1078 = uVar10 - 1000;
            *(uint *)&pGVar8->field_0x107c =
                 *(int *)&pGVar8->field_0x107c + -1 + (uint)(999 < uVar10);
          }
          if (*param_1 == 1) {
            if (1 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): master sync canvas_distance_gear:%d,raster_height_gear:%d\n",
                       "process_for_message_show");
              }
              else {
                ble_printk("%s(): master sync canvas_distance_gear:%d,raster_height_gear:%d\n",
                           "process_for_message_show",(uint)param_1[0xec1],(uint)param_1[0xec0]);
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
          pGVar8 = __get_dashboard_state();
          pGVar8->dashboard_ts->field_0x73 = 1;
          pGVar8 = __get_dashboard_state();
          update_temp_task_status((int)pGVar8,6,2);
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
        uVar13 = extraout_r1_12;
        uVar10 = extraout_r3_11;
        if (cVar3 != '\x04') goto LAB_0002e544;
      }
      if (((param_1[1] == 1) ||
          (pGVar8 = __get_dashboard_state(), uVar13 = extraout_r1_14, pGVar8->field_0x1 == '\b')) ||
         (pGVar8 = __get_dashboard_state(), uVar13 = extraout_r1_15, pGVar8->display_mode == '\f'))
      {
        update_persist_task_status_to_idle((int)param_1,uVar13);
        FUN_00035abc(5);
        uVar10 = extraout_r3_10;
        goto LAB_0002e544;
      }
      if (param_1[0xd5] != 4) break;
      iVar11 = iVar11 + 1;
      if (((param_1[0x10d6] != 0) && (*param_1 == 1)) &&
         ((((*param_2 == 1 && (cVar3 = FUN_000260dc(), cVar3 == '\0')) ||
           (cVar3 = FUN_000260dc(), cVar3 != '\0')) &&
          ((((uint)(iVar11 * -0x33333333) >> 2 | iVar11 * 0x40000000) < 0xccccccd &&
           (param_1[0xdb] < 0x1e)))))) {
        param_1[0xdb] = param_1[0xdb] - 1;
      }
LAB_0002e55a:
      z_impl_k_sleep(0x667,0);
      uVar13 = extraout_r1_13;
    }
    uVar10 = 0;
    if (param_1[0xd5] == 0) goto LAB_0002e544;
    break;
  case 5:
    bVar4 = param_1[0xfee];
    pGVar8 = __get_dashboard_state();
    iVar17 = FUN_0002df54((uint)bVar4,(uint)(byte)pGVar8->field_0x10d7);
    param_1[0xdb] = (byte)iVar17;
    FUN_00035abc(2);
    pGVar8 = __get_dashboard_state();
    iVar11 = 0;
    piVar6 = FUN_00035260((byte)pGVar8->field_0xdd - 1);
    uVar13 = extraout_r1_03;
    iVar17 = *piVar6;
LAB_0002e1ae:
    if (((param_1[1] == 1) ||
        (pGVar8 = __get_dashboard_state(), uVar13 = extraout_r1_04, pGVar8->field_0x1 == '\b')) ||
       (pGVar8 = __get_dashboard_state(), uVar13 = extraout_r1_05, pGVar8->display_mode == '\f')) {
      update_persist_task_status_to_idle((int)param_1,uVar13);
      pcVar9 = "message:imu-trigger-off-imm";
      uVar10 = extraout_r3_07;
      goto LAB_0002e1bc;
    }
    iVar19 = iVar17;
    if (*param_1 == 1) {
      pGVar8 = __get_dashboard_state();
      piVar6 = FUN_00035260((byte)pGVar8->field_0xdd - 1);
      iVar19 = *piVar6;
      if (iVar19 != iVar17) {
        bVar4 = param_1[0xfee];
        pGVar8 = __get_dashboard_state();
        iVar17 = FUN_0002df54((uint)bVar4,(uint)(byte)pGVar8->field_0x10d7);
        param_1[0xdb] = (byte)iVar17;
      }
    }
    if (param_1[0xd5] != 5) {
      if (0 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): goto next screen, new screen %d !\r\n\n");
        }
        else {
          ble_printk("%s(): goto next screen, new screen %d !\r\n\n",
                     "process_for_new_message_come_on",(uint)param_1[0xd5],BLE_DEBUG);
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
       (pGVar8 = __get_dashboard_state(), iVar11 = extraout_r1_16, pGVar8->field_0x1 == '\b')) {
LAB_0002e600:
      update_persist_task_status_to_idle((int)param_1,iVar11);
      uVar10 = extraout_r3_12;
      goto LAB_0002e606;
    }
    if (!bVar2 && *(char *)(*(int *)(param_1 + 0xff0) + 0x72) == '\0') {
      if ((*param_2 != 1) || (cVar3 = FUN_000260dc(), cVar3 != '\0')) {
        pGVar8 = __get_dashboard_state();
        bVar2 = false;
        if ((pGVar8->field_0x1245 != '\0') ||
           (pGVar8 = __get_dashboard_state(), pGVar8->field_0x1244 != '\x04')) goto LAB_0002e646;
      }
LAB_0002e71c:
      if ((int)(DAT_20008518 << 0x1e) < 0) {
        DAT_20008518 = DAT_20008518 & 0xfffffffd;
      }
      bVar2 = FUN_0002d9e8((int)param_1);
      if ((!bVar2) || (*(char *)(*(int *)(param_1 + 0xff0) + 0x74) != '\0')) {
        FUN_00030458();
        sync_to_slave((char *)param_1,8,(undefined4 *)0x0,0);
        iVar11 = extraout_r1_19;
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
        uVar10 = FUN_0002dd80(**(uint **)(param_1 + 0x1068));
        if (uVar10 == 0) {
          FUN_00030458();
        }
        uVar10 = *(uint *)(param_1 + 0xdf);
        if (uVar10 == 0xb) goto LAB_0002e7a8;
        switch(uVar10) {
        case 7:
          uVar10 = 7;
          goto LAB_0002e7a8;
        case 8:
          uVar10 = 8;
          goto LAB_0002e7a8;
        case 9:
          uVar10 = 9;
          goto LAB_0002e7a8;
        case 10:
          uVar10 = 10;
          goto LAB_0002e7a8;
        default:
          param_1[0xdc] = param_1[0xdc] + 1;
          break;
        case 0xc:
          uVar10 = 0xc;
          goto LAB_0002e7a8;
        case 0xe:
          uVar10 = 0xe;
          goto LAB_0002e7a8;
        case 0xf:
          uVar10 = 0xf;
          goto LAB_0002e7a8;
        case 0x10:
          uVar10 = 0x10;
          goto LAB_0002e7a8;
        case 0x11:
          uVar10 = 0x11;
          goto LAB_0002e7a8;
        case 0x12:
          uVar10 = 0x12;
          goto LAB_0002e7a8;
        case 0x13:
          uVar10 = 0x13;
          goto LAB_0002e7a8;
        case 0x14:
          uVar10 = 0x14;
          goto LAB_0002e7a8;
        }
      }
      if (param_1[0xd5] == 1) {
        uVar10 = 1;
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
      uVar10 = sync_to_slave((char *)param_1,6,(undefined4 *)&local_2c,2);
      if (2999 < (int)uVar10) {
        if (0 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): sync exit dashboard fail!\n");
          }
          else {
            ble_printk("%s(): sync exit dashboard fail!\n","process_for_DASHBOARD_show",
                       extraout_r2_01,BLE_DEBUG);
          }
        }
        goto LAB_0002e830;
      }
      uVar13 = extraout_r1_17;
      if (1 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): sync close dashboard!\n");
          uVar13 = extraout_r1_20;
        }
        else {
          ble_printk("%s(): sync close dashboard!\n","process_for_DASHBOARD_show",extraout_r2_01,
                     BLE_DEBUG);
          uVar13 = extraout_r1_18;
        }
      }
      display_close_screen(6,uVar13);
      while (*(char *)(*(int *)(param_1 + 0xff0) + 0x73) == '\x01') {
        z_impl_k_sleep(0x667,0);
      }
      *(undefined1 *)(*(int *)(param_1 + 0xff0) + 0x74) = 0;
LAB_0002e74c:
      uVar10 = FUN_0002dd80(**(uint **)(param_1 + 0x1068));
      if (uVar10 == 0) {
        FUN_00030458();
      }
      uVar10 = **(uint **)(param_1 + 0x1068) & 0xff;
      goto LAB_0002e7a8;
    }
LAB_0002e830:
    if (param_1[0xd5] == 4) {
      FUN_00030458();
      pcVar9 = extraout_r1_21;
      uVar13 = extraout_r2_02;
      if (*param_1 == 2) {
        sleep(0x96);
        pcVar9 = extraout_r1_22;
        uVar13 = extraout_r2_03;
      }
      pcVar7 = "goto message show task becasse screen id is E_ID_SCREEN_ANCS_NOTIFICATION!";
      goto LAB_0002e84e;
    }
    if (param_1[0xfea] == 1) {
      z_impl_k_sleep(0x667,0);
      return 0;
    }
    if ((DAT_20019a6c == '\0') || (uVar10 = FUN_000352f4(), uVar10 == 0)) goto LAB_0002e8aa;
    FUN_00030458();
    FUN_00037830();
    FUN_00035abc(6);
    update_temp_task_status((int)param_1,4,2);
    pcVar9 = "display msg by touch";
    uVar13 = extraout_r3_13;
    goto LAB_0002e8a4;
  case 7:
    *(undefined1 *)(*(int *)(param_1 + 0x1018) + 1) = 0;
    goto LAB_0002ec50;
  case 8:
    param_1[0xb0d] = 0;
    pGVar8 = __get_dashboard_state();
    uVar10 = FUN_00035310();
    pGVar8->field_0xdd = (char)uVar10;
    while ((*param_2 != 1 || (param_1[0xfee] != 10))) {
      z_impl_k_sleep(0x667,0);
    }
    sync_to_slave((char *)param_1,8,(undefined4 *)0x0,0);
    update_persist_task_status_to_idle((int)param_1,extraout_r1_43);
    uVar10 = (uint)*param_1;
    if (uVar10 == 1) {
      z_impl_k_sleep(0x4000,0);
      uVar10 = extraout_r3_26;
    }
LAB_0002e544:
    pcVar9 = "imu-trigger-off-imm";
    goto LAB_0002e1bc;
  case 9:
    iVar17 = *(int *)(param_1 + 0x1000);
    goto LAB_0002e994;
  case 10:
    pcVar9 = *(char **)(param_1 + 0x1004);
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
    iVar17 = 0;
    goto LAB_0002ed72;
  case 0x11:
    goto LAB_0002e10a;
  case 0x12:
    goto LAB_0002e0f4;
  case 0x13:
    goto LAB_0002e0da;
  case 0x14:
    pGVar8 = __get_dashboard_state();
    if ((*(char *)pGVar8 == '\x02') &&
       (pGVar8 = __get_dashboard_state(), (pGVar8->sem_2).count == 0)) {
      pGVar8 = __get_dashboard_state();
      k_sem_give(&pGVar8->sem_2);
    }
    iVar20 = k_uptime_get();
    uVar13 = (undefined4)((ulonglong)iVar20 >> 0x20);
    *(int64_t *)(*(int *)(param_1 + 0x1014) + 6) = iVar20;
    *(undefined1 *)(*(int *)(param_1 + 0xff0) + 0x74) = 0;
    goto LAB_0002eeea;
  }
LAB_0002e246:
  iVar17 = 0xb;
  goto LAB_0002e05a;
LAB_0002eeea:
  if ((param_1[1] == 1) ||
     (pGVar8 = __get_dashboard_state(), uVar13 = extraout_r1_61, pGVar8->field_0x1 == '\b'))
  goto LAB_0002eef0;
  if ((*param_1 == 1) && (**(char **)(param_1 + 0x1014) == '\x01')) {
    iVar20 = k_uptime_get();
    iVar17 = *(int *)(param_1 + 0x1014);
    lVar1 = iVar20 - *(longlong *)(iVar17 + 6);
    if ((int)((ulonglong)lVar1 >> 0x20) < (int)(uint)((uint)lVar1 < 0x1389)) {
LAB_0002ef8e:
      iVar20 = k_uptime_get();
      lVar1 = iVar20 - *(longlong *)(*(int *)(param_1 + 0x1014) + 6);
      if (((int)((ulonglong)lVar1 >> 0x20) < (int)(uint)((uint)lVar1 < 0x2711)) ||
         (*(char *)(*(int *)(param_1 + 0x1014) + 1) != '\x02')) goto LAB_0002ef46;
    }
    else {
      if (*(char *)(iVar17 + 1) == '\a') {
        bVar2 = *(char *)(iVar17 + 3) == '\x01';
      }
      else {
        if (*(char *)(iVar17 + 1) != '\x04') goto LAB_0002ef8e;
        bVar2 = *(char *)(iVar17 + 3) == '\x13';
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
    uVar10 = sync_to_slave((char *)param_1,8,(undefined4 *)0x0,0);
    if ((int)uVar10 < 3000) {
      update_persist_task_status_to_idle((int)param_1,extraout_r1_62);
      pcVar9 = "evenai_v2:self exit";
      uVar10 = extraout_r3_34;
      goto LAB_0002e1bc;
    }
    if (0 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): sync exit evenai_v2 fail!\n");
      }
      else {
        ble_printk("%s(): sync exit evenai_v2 fail!\n","process_for_even_ai_v2_show",extraout_r2_08,
                   BLE_DEBUG);
      }
    }
  }
  if (param_1[0xd5] == 1) {
    pcVar9 = "evenai_v2:imu-trigger-off-imm";
    uVar10 = 1;
    goto LAB_0002e1bc;
  }
  z_impl_k_sleep(0x667,0);
  uVar13 = extraout_r1_63;
  goto LAB_0002eeea;
LAB_0002eef0:
  update_persist_task_status_to_idle((int)param_1,uVar13);
  pcVar9 = "evenai_v2:dfu";
  uVar10 = extraout_r3_33;
  goto LAB_0002e1bc;
LAB_0002e0da:
  if ((param_1[1] == 1) ||
     (pGVar8 = __get_dashboard_state(), iVar11 = extraout_r1_70, pGVar8->field_0x1 == '\b'))
  goto LAB_0002e0e2;
  if (**(char **)(param_1 + 0x102c) == '\0') {
    sync_to_slave((char *)param_1,8,(undefined4 *)0x0,0);
    update_persist_task_status_to_idle((int)param_1,extraout_r1_71);
    uVar10 = (uint)*param_1;
    if (uVar10 == 1) {
      z_impl_k_sleep(0x4000,0);
      uVar10 = extraout_r3_37;
    }
    pcVar9 = "transcribe:self exit";
    goto LAB_0002e1bc;
  }
  if (param_1[0xd5] == 1) {
    pcVar9 = "transcribe:imu-trigger-off-imm";
    uVar10 = 1;
    goto LAB_0002e1bc;
  }
  z_impl_k_sleep(0x667,0);
  iVar11 = extraout_r1_72;
  goto LAB_0002e0da;
LAB_0002e0e2:
  update_persist_task_status_to_idle((int)param_1,iVar11);
  pcVar9 = "transcribe:dfu";
  uVar10 = extraout_r3_00;
  goto LAB_0002e1bc;
LAB_0002e0f4:
  if ((param_1[1] == 1) ||
     (pGVar8 = __get_dashboard_state(), iVar11 = extraout_r1_67, pGVar8->field_0x1 == '\b'))
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
    update_persist_task_status_to_idle((int)param_1,extraout_r1_68);
    uVar10 = (uint)*param_1;
    if (uVar10 == 1) {
      z_impl_k_sleep(0x4000,0);
      uVar10 = extraout_r3_36;
    }
    pcVar9 = "prompt:self exit";
    goto LAB_0002e1bc;
  }
LAB_0002f09e:
  if (**(char **)(param_1 + 0x1028) == '\0') goto LAB_0002f056;
  if (param_1[0xd5] == 1) {
    pcVar9 = "prompt:imu-trigger-off-imm";
    uVar10 = 1;
    goto LAB_0002e1bc;
  }
  z_impl_k_sleep(0x667,0);
  iVar11 = extraout_r1_69;
  goto LAB_0002e0f4;
LAB_0002e0fc:
  update_persist_task_status_to_idle((int)param_1,iVar11);
  pcVar9 = "prompt:dfu";
  uVar10 = extraout_r3_01;
  goto LAB_0002e1bc;
LAB_0002e10a:
  if ((param_1[1] == 1) ||
     (pGVar8 = __get_dashboard_state(), iVar11 = extraout_r1_64, pGVar8->field_0x1 == '\b'))
  goto LAB_0002e112;
  if (**(char **)(param_1 + 0x1024) == '\0') {
    sync_to_slave((char *)param_1,8,(undefined4 *)0x0,0);
    update_persist_task_status_to_idle((int)param_1,extraout_r1_65);
    uVar10 = (uint)*param_1;
    if (uVar10 == 1) {
      z_impl_k_sleep(0x4000,0);
      uVar10 = extraout_r3_35;
    }
    pcVar9 = "set_imu_pitch:self exit";
    goto LAB_0002e1bc;
  }
  if (param_1[0xd5] == 1) {
    pcVar9 = "set_imu_pitch:imu-trigger-off-imm";
    uVar10 = 1;
    goto LAB_0002e1bc;
  }
  z_impl_k_sleep(0x667,0);
  iVar11 = extraout_r1_66;
  goto LAB_0002e10a;
LAB_0002e112:
  update_persist_task_status_to_idle((int)param_1,iVar11);
  pcVar9 = "set_imu_pitch:dfu";
  uVar10 = extraout_r3_02;
  goto LAB_0002e1bc;
LAB_0002ed72:
  if (param_1[0xfee] == 0xc) goto code_r0x0002ed7a;
  if ((param_1[1] == 1) ||
     (pGVar8 = __get_dashboard_state(), iVar11 = extraout_r1_53, pGVar8->field_0x1 == '\b'))
  goto LAB_0002eda6;
  bVar2 = FUN_00028d2c();
  uVar12 = extraout_r1_54;
  uVar13 = extraout_r2_04;
  if ((!bVar2) &&
     ((pGVar8 = __get_dashboard_state(), uVar12 = extraout_r1_55, uVar13 = extraout_r2_05,
      1 < **(byte **)&pGVar8->field_0x1010 &&
      (pGVar8 = __get_dashboard_state(), uVar12 = extraout_r1_56, uVar13 = extraout_r2_06,
      **(byte **)&pGVar8->field_0x1010 < 10)))) {
    pGVar8 = __get_dashboard_state();
    uVar13 = 10;
    **(undefined1 **)&pGVar8->field_0x1010 = 10;
    uVar12 = extraout_r1_57;
  }
  if (((*(char *)(*(int *)(param_1 + 0x1010) + 7) == '\0') ||
      (pGVar8 = __get_dashboard_state(), uVar12 = extraout_r1_59, uVar13 = extraout_r2_07,
      **(char **)&pGVar8->field_0x1010 == '\0')) ||
     (((uVar10 = (uint)**(byte **)(param_1 + 0x1010), uVar10 == 8 || (uVar10 == 0xb)) &&
      (uVar13 = 0, param_1[0xdb] == 0)))) {
    if (*param_1 == 1) {
      FUN_00029774(0,uVar12,uVar13);
    }
    sync_to_slave((char *)param_1,8,(undefined4 *)0x0,0);
    iVar11 = extraout_r1_58;
    goto LAB_0002eda6;
  }
  if (param_1[0xd5] == 1) {
    FUN_00080338(1);
    pcVar9 = "evenai:imu-trigger-off-imm";
    uVar10 = extraout_r3_32;
    goto LAB_0002e1bc;
  }
  iVar17 = iVar17 + 1;
  if ((*param_1 == 1) &&
     (((uVar10 - 7 < 2 || (uVar10 == 0xb)) &&
      (((uint)(iVar17 * -0x33333333) >> 2 | iVar17 * 0x40000000) < 0xccccccd)))) {
    param_1[0xdb] = param_1[0xdb] - 1;
  }
  z_impl_k_sleep(0x667,0);
  iVar11 = extraout_r1_60;
  goto LAB_0002ed72;
code_r0x0002ed7a:
  sync_to_slave((char *)param_1,8,(undefined4 *)0x0,0);
  iVar11 = extraout_r1_52;
  if (*param_2 == 2) {
    update_persist_task_status_to_wait_blow_head((int)param_1,extraout_r1_52);
  }
  else {
LAB_0002eda6:
    update_persist_task_status_to_idle((int)param_1,iVar11);
  }
  FUN_00080338(1);
  pcVar9 = "evenai:self exit";
  uVar10 = extraout_r3_31;
  goto LAB_0002e1bc;
LAB_0002e120:
  if ((param_1[1] == 1) ||
     (pGVar8 = __get_dashboard_state(), iVar11 = extraout_r1_49, pGVar8->field_0x1 == '\b'))
  goto LAB_0002e128;
  if (**(char **)(param_1 + 0x1020) == '\0') {
    sync_to_slave((char *)param_1,8,(undefined4 *)0x0,0);
    update_persist_task_status_to_idle((int)param_1,extraout_r1_50);
    uVar10 = (uint)*param_1;
    if (uVar10 == 1) {
      z_impl_k_sleep(0x4000,0);
      uVar10 = extraout_r3_30;
    }
    pcVar9 = "raster_height:self exit";
    goto LAB_0002e1bc;
  }
  if (param_1[0xd5] == 1) {
    pcVar9 = "raster_height:imu-trigger-off-imm";
    uVar10 = 1;
    goto LAB_0002e1bc;
  }
  z_impl_k_sleep(0x667,0);
  iVar11 = extraout_r1_51;
  goto LAB_0002e120;
LAB_0002e128:
  update_persist_task_status_to_idle((int)param_1,iVar11);
  pcVar9 = "raster_height:dfu";
  uVar10 = extraout_r3_03;
  goto LAB_0002e1bc;
LAB_0002e136:
  if ((param_1[1] == 1) ||
     (pGVar8 = __get_dashboard_state(), iVar11 = extraout_r1_46, pGVar8->field_0x1 == '\b'))
  goto LAB_0002e13e;
  if (**(char **)(param_1 + 0x101c) == '\0') {
    sync_to_slave((char *)param_1,8,(undefined4 *)0x0,0);
    update_persist_task_status_to_idle((int)param_1,extraout_r1_47);
    uVar10 = (uint)*param_1;
    if (uVar10 == 1) {
      z_impl_k_sleep(0xccd,0);
      uVar10 = extraout_r3_29;
    }
    pcVar9 = "onboarding:self exit";
    goto LAB_0002e1bc;
  }
  if (param_1[0xd5] == 1) {
    pcVar9 = "onboarding:imu-trigger-off-imm";
    uVar10 = 1;
    goto LAB_0002e1bc;
  }
  z_impl_k_sleep(0x667,0);
  iVar11 = extraout_r1_48;
  goto LAB_0002e136;
LAB_0002e13e:
  update_persist_task_status_to_idle((int)param_1,iVar11);
  pcVar9 = "onboarding:dfu";
  uVar10 = extraout_r3_04;
  goto LAB_0002e1bc;
LAB_0002e14c:
  if ((param_1[1] == 1) ||
     (pGVar8 = __get_dashboard_state(), iVar11 = extraout_r1_31, pGVar8->field_0x1 == '\b'))
  goto LAB_0002e154;
  if (*(char *)(*(int *)(param_1 + 0x1034) + 1) == '\0') {
    if (*param_2 == 2) {
      sync_to_slave((char *)param_1,8,(undefined4 *)0x0,0);
      if (*param_2 == 2) {
        update_persist_task_status_to_wait_blow_head((int)param_1,extraout_r1_32);
        uVar13 = extraout_r3_19;
      }
      else {
        update_persist_task_status_to_idle((int)param_1,extraout_r1_32);
        uVar13 = extraout_r3_21;
      }
      trigger_screen_state_change("IMU:wakeup:dashboard",(int)param_1,1,uVar13);
    }
    else {
      sync_to_slave((char *)param_1,8,(undefined4 *)0x0,0);
      update_persist_task_status_to_idle((int)param_1,extraout_r1_33);
    }
    uVar10 = (uint)*param_1;
    if (uVar10 == 1) {
      z_impl_k_sleep(0x4000,0);
      uVar10 = extraout_r3_20;
    }
    pcVar9 = "quicknote:self exit";
    goto LAB_0002e1bc;
  }
  uVar10 = 1;
  if (param_1[0xd5] == 1) goto LAB_0002e606;
  z_impl_k_sleep(0x667,0);
  iVar11 = extraout_r1_34;
  goto LAB_0002e14c;
LAB_0002e154:
  update_persist_task_status_to_idle((int)param_1,iVar11);
  pcVar9 = "quicknote:imu-trigger-off-imm";
  uVar10 = extraout_r3_05;
  goto LAB_0002e1bc;
LAB_0002e162:
  if ((param_1[1] == 1) ||
     (pGVar8 = __get_dashboard_state(), iVar11 = extraout_r1_39, pGVar8->field_0x1 == '\b'))
  goto LAB_0002e16a;
  if ((*(char *)(*(int *)(param_1 + 0x1008) + 6) == '\0') &&
     (*(char *)(*(int *)(param_1 + 0x100c) + 6) == '\0')) {
    if (*param_2 == 2) {
      sync_to_slave((char *)param_1,8,(undefined4 *)0x0,0);
      update_persist_task_status_to_idle((int)param_1,extraout_r1_40);
      if (*param_1 == 1) {
        z_impl_k_sleep(0x4000,0);
      }
      iVar17 = 0x2667;
    }
    else {
      sync_to_slave((char *)param_1,8,(undefined4 *)0x0,0);
      update_persist_task_status_to_idle((int)param_1,extraout_r1_41);
      uVar10 = (uint)*param_1;
      if (uVar10 != 1) goto LAB_0002e170;
      iVar17 = 0x4000;
    }
    z_impl_k_sleep(iVar17,0);
    uVar10 = extraout_r3_25;
    goto LAB_0002e170;
  }
  uVar10 = 1;
  if (param_1[0xd5] == 1) goto LAB_0002e606;
  z_impl_k_sleep(0x667,0);
  iVar11 = extraout_r1_42;
  goto LAB_0002e162;
LAB_0002eab2:
  if ((param_1[1] == 1) ||
     (pGVar8 = __get_dashboard_state(), iVar11 = extraout_r1_35, pGVar8->field_0x1 == '\b'))
  goto LAB_0002eab8;
  if (*pcVar9 == '\0') {
    if (*param_2 == 2) {
      sync_to_slave((char *)param_1,8,(undefined4 *)0x0,0);
      update_persist_task_status_to_idle((int)param_1,extraout_r1_36);
      trigger_screen_state_change("IMU:wakeup:dashboard",(int)param_1,1,extraout_r3_23);
      if (*param_1 == 1) {
        z_impl_k_sleep(0x4000,0);
      }
      iVar17 = 0x2667;
LAB_0002eb3a:
      z_impl_k_sleep(iVar17,0);
      uVar10 = extraout_r3_24;
    }
    else {
      sync_to_slave((char *)param_1,8,(undefined4 *)0x0,0);
      update_persist_task_status_to_idle((int)param_1,extraout_r1_37);
      uVar10 = (uint)*param_1;
      if (uVar10 == 1) {
        iVar17 = 0x4000;
        goto LAB_0002eb3a;
      }
    }
    pcVar9 = "navigation:self exit";
    goto LAB_0002e1bc;
  }
  uVar10 = 1;
  if (param_1[0xd5] == 1) goto LAB_0002e606;
  z_impl_k_sleep(0x667,0);
  iVar11 = extraout_r1_38;
  goto LAB_0002eab2;
LAB_0002eab8:
  update_persist_task_status_to_idle((int)param_1,iVar11);
  pcVar9 = "navigation:imu-trigger-off-imm";
  uVar10 = extraout_r3_22;
  goto LAB_0002e1bc;
LAB_0002e994:
  if ((param_1[1] == 1) ||
     (pGVar8 = __get_dashboard_state(), iVar11 = extraout_r1_27, pGVar8->field_0x1 == '\b'))
  goto LAB_0002e99a;
  if (*(char *)(iVar17 + 1) == '\0') {
    FUN_00030458();
    if (*param_2 == 2) {
      trigger_screen_state_change("IMU:wakeup:dashboard",(int)param_1,1,2);
      FUN_0003f23c();
      sync_to_slave((char *)param_1,8,(undefined4 *)0x0,0);
      update_persist_task_status_to_idle((int)param_1,extraout_r1_28);
      if (*param_1 == 1) {
        z_impl_k_sleep(0x4000,0);
      }
      iVar17 = 0x2667;
LAB_0002e9f0:
      z_impl_k_sleep(iVar17,0);
      uVar10 = extraout_r3_18;
    }
    else {
      sync_to_slave((char *)param_1,8,(undefined4 *)0x0,0);
      update_persist_task_status_to_idle((int)param_1,extraout_r1_29);
      FUN_0003f23c();
      uVar10 = (uint)*param_1;
      if (uVar10 == 1) {
        iVar17 = 0x4000;
        goto LAB_0002e9f0;
      }
    }
    pcVar9 = "temeprompter:self exit";
    goto LAB_0002e1bc;
  }
  uVar10 = 1;
  if (param_1[0xd5] == 1) goto LAB_0002e606;
  z_impl_k_sleep(0x667,0);
  iVar11 = extraout_r1_30;
  goto LAB_0002e994;
LAB_0002e99a:
  update_persist_task_status_to_idle((int)param_1,iVar11);
  pcVar9 = "teleprompter:imu-trigger-off-imm";
  uVar10 = extraout_r3_17;
  goto LAB_0002e1bc;
LAB_0002ec50:
  if (**(char **)(param_1 + 0x1018) != '\0') {
    iVar20 = k_uptime_get();
    lVar1 = iVar20 - *(longlong *)(*(undefined1 **)(param_1 + 0x1018) + 3);
    iVar17 = (int)((ulonglong)lVar1 >> 0x20);
    bVar2 = (uint)lVar1 < 0x5dd;
    iVar11 = iVar17 - (uint)bVar2;
    if ((int)(uint)bVar2 <= iVar17) {
      **(undefined1 **)(param_1 + 0x1018) = 0;
    }
  }
  if ((param_1[1] == 1) ||
     (pGVar8 = __get_dashboard_state(), iVar11 = extraout_r1_44, pGVar8->field_0x1 == '\b')) {
    update_persist_task_status_to_idle((int)param_1,iVar11);
    pcVar9 = "not_disturb:dfu";
    uVar10 = extraout_r3_27;
    goto LAB_0002e1bc;
  }
  if (**(char **)(param_1 + 0x1018) == '\0') {
    update_persist_task_status_to_idle((int)param_1,extraout_r1_44);
    pcVar9 = "not_disturb:self exit";
    uVar10 = extraout_r3_28;
    goto LAB_0002e1bc;
  }
  if (param_1[0xd5] == 1) goto LAB_0002ecb6;
  z_impl_k_sleep(0x667,0);
  iVar11 = extraout_r1_45;
  goto LAB_0002ec50;
LAB_0002ecb6:
  pcVar9 = "not_disturb:imu-trigger-off-imm";
  uVar10 = 1;
  goto LAB_0002e1bc;
LAB_0002e8aa:
  __get_dashboard_state();
  z_impl_k_sleep(0x667,0);
  iVar11 = extraout_r1_23;
  goto LAB_0002e5fa;
code_r0x0002e2aa:
  sync_message_signal_to_slave(1,extraout_r1_06,extraout_r2);
  clear_timeout_message(0);
  FUN_0002dd98();
  FUN_000359fc();
  update_temp_task_status((int)param_1,4,2);
  trigger_screen_state_change("IMU:wakeup:new-notification",(int)param_1,1,extraout_r3_08);
  if (0 < LOG_LEVEL) {
    pcVar9 = "process_for_new_message_come_on";
    uVar13 = extraout_r2_00;
LAB_0002e2e0:
    pcVar7 = "%s(): goto new message come on task master!\r\n\n";
LAB_0002f498:
    if (BLE_DEBUG == 0) {
      printk(pcVar7);
    }
    else {
      ble_printk(pcVar7,pcVar9,uVar13,BLE_DEBUG);
    }
  }
  goto LAB_0002e246;
LAB_0002e30c:
  z_impl_k_sleep(0x667,0);
  iVar11 = iVar11 + 1;
  if (((*param_1 == 1) && (((uint)(iVar11 * -0x33333333) >> 2 | iVar11 * 0x40000000) < 0xccccccd))
     && (param_1[0xdb] != 0)) {
    param_1[0xdb] = param_1[0xdb] - 1;
  }
  uVar13 = extraout_r1_08;
  iVar17 = iVar19;
  if (param_1[0xdb] == 0) {
    param_1[0xb0d] = 0;
LAB_0002e2ec:
    sync_to_slave((char *)param_1,8,(undefined4 *)0x0,0);
    if (*param_2 == 2) {
      update_persist_task_status_to_wait_blow_head((int)param_1,extraout_r1_07);
    }
    else {
      update_persist_task_status_to_idle((int)param_1,extraout_r1_07);
    }
    FUN_00035abc(6);
    pcVar9 = "new-msg-timeout-goto-idle";
    uVar10 = extraout_r3_09;
    goto LAB_0002e1bc;
  }
  goto LAB_0002e1ae;
LAB_0002e606:
  pcVar9 = "dashboard:imu-trigger-off-imm";
  goto LAB_0002e1bc;
code_r0x0002f552:
  if (1 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): master sync canvas_distance_gear:%d,raster_height_gear:%d\n","process_for_IDLE")
      ;
    }
    else {
      ble_printk("%s(): master sync canvas_distance_gear:%d,raster_height_gear:%d\n",
                 "process_for_IDLE",(uint)param_1[0xec1],(uint)param_1[0xec0]);
    }
  }
  local_2c = CONCAT11(param_1[0xec1],0xb);
  local_2a = param_1[0xec0];
  sync_to_slave((char *)param_1,0xc,(undefined4 *)&local_2c,3);
  cal_panel_canvas_coord((int *)(param_1 + 0xec4),(int *)(param_1 + 0xeb8));
  bVar2 = FUN_0002d9e8((int)param_1);
  uVar10 = uVar18;
  if (!bVar2) goto LAB_0002f5b0;
  goto LAB_0002f1fc;
LAB_0002f5b0:
  pGVar8 = __get_dashboard_state();
  if (((*(char *)pGVar8 == '\x01') && (bVar2 = FUN_00028d2c(), bVar2)) &&
     ((pGVar8 = __get_dashboard_state(), *(char *)(pGVar8 + 1) == '\0' &&
      (cVar3 = FUN_00030440(), cVar3 == '\x01')))) {
    FUN_0008040c();
  }
  pGVar8 = __get_dashboard_state();
  pGVar8->dashboard_ts->field_0x73 = 1;
  update_temp_task_status((int)param_1,6,2);
  pcVar9 = "IMU:wakeup:dashboard";
  uVar13 = extraout_r3_40;
LAB_0002e8a4:
  trigger_screen_state_change(pcVar9,(int)param_1,1,uVar13);
  goto LAB_0002e246;
LAB_0002e16a:
  update_persist_task_status_to_idle((int)param_1,iVar11);
  uVar10 = extraout_r3_06;
LAB_0002e170:
  pcVar9 = "translate:self exit";
LAB_0002e1bc:
  trigger_screen_state_change(pcVar9,(int)param_1,0,uVar10);
  sleep(0x96);
  cVar3 = FUN_00035a78();
  if (cVar3 == '\x01') {
    bVar4 = FUN_00035acc();
    if (bVar4 == 1) {
      iVar17 = 5;
    }
    else {
      pGVar8 = __get_dashboard_state();
      iVar17 = 0;
      if (pGVar8->field_0xdd != '\0') {
        iVar17 = 6;
      }
    }
    FUN_00035abc(iVar17);
  }
  return 0;
}


