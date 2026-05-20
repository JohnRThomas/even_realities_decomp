/*
 * Function: slave_display_thread
 * Entry:    00029fbc
 * Prototype: undefined __stdcall slave_display_thread(int param_1, uint param_2, undefined4 param_3)
 */


void slave_display_thread(int param_1,uint param_2,undefined4 param_3)

{
  byte bVar1;
  char cVar2;
  bool bVar3;
  GlassesState *pGVar4;
  char *pcVar5;
  GlassesState *pGVar6;
  undefined4 uVar7;
  uint extraout_r1;
  uint extraout_r1_00;
  undefined4 extraout_r1_01;
  uint extraout_r1_02;
  uint extraout_r1_03;
  uint extraout_r1_04;
  uint extraout_r1_05;
  uint extraout_r1_06;
  uint extraout_r1_07;
  uint extraout_r1_08;
  uint extraout_r1_09;
  uint extraout_r1_10;
  uint extraout_r1_11;
  uint extraout_r1_12;
  uint extraout_r1_13;
  uint extraout_r1_14;
  uint extraout_r1_15;
  uint extraout_r1_16;
  uint extraout_r1_17;
  uint extraout_r1_18;
  uint extraout_r1_19;
  uint extraout_r1_20;
  uint extraout_r1_21;
  uint extraout_r1_22;
  uint extraout_r1_23;
  uint extraout_r1_24;
  uint extraout_r1_25;
  undefined4 extraout_r1_26;
  uint extraout_r1_27;
  uint extraout_r1_28;
  uint extraout_r1_29;
  uint extraout_r1_30;
  uint extraout_r1_31;
  uint uVar8;
  uint extraout_r2;
  uint extraout_r2_00;
  uint *extraout_r2_01;
  uint *puVar9;
  uint *extraout_r2_02;
  uint *extraout_r2_03;
  undefined4 extraout_r2_04;
  undefined4 extraout_r2_05;
  undefined1 uVar10;
  undefined1 *puVar11;
  int iVar12;
  undefined1 *extraout_r3;
  undefined1 *extraout_r3_00;
  undefined1 *extraout_r3_01;
  undefined1 *extraout_r3_02;
  undefined1 *extraout_r3_03;
  undefined1 *extraout_r3_04;
  undefined4 extraout_r3_05;
  byte bVar13;
  k_timeout_t timeout;
  undefined8 uVar14;
  k_timeout_t timeout_00;
  
  *(undefined1 *)(param_1 + 0xfeb) = 1;
  *(undefined1 *)(param_1 + 0xd5) = 0;
  if (1 < (int)LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): enter\n");
      param_2 = extraout_r1_03;
    }
    else {
      ble_printk("%s(): enter\n","slave_display_thread",param_3,BLE_DEBUG);
      param_2 = extraout_r1;
    }
  }
  if (*(char *)(param_1 + 0xfee) == '\v') {
    change_work_mode(2);
    param_2 = extraout_r1_00;
  }
LAB_00029ff6:
  if (*(char *)(param_1 + 0xfee) == '\v') {
    *(byte *)(param_1 + 0xd4) = *(byte *)(param_1 + 0xd4) & 0xc0;
    cVar2 = FUN_00033d5c();
    if (cVar2 == '\0') {
      uVar10 = 6;
    }
    else {
      uVar10 = 3;
    }
    uVar8 = 0x8000;
    *(undefined1 *)(param_1 + 0xd5) = uVar10;
    goto LAB_0002a090;
  }
  timeout.ticks._4_4_ = 0xffffffff;
  timeout.ticks._0_4_ = param_2;
  z_impl_k_sem_take((k_sem *)(param_1 + 0x20),timeout);
  do {
    if (*(char *)(param_1 + 1) != '\x01') {
      pGVar4 = __get_dashboard_state();
      uVar14 = CONCAT44(extraout_r1_01,pGVar4);
      if (pGVar4->field_0x1 != '\b') break;
    }
    uVar8 = 0x28000;
LAB_0002a090:
    timeout_00.ticks._4_4_ = 0;
    timeout_00.ticks._0_4_ = uVar8;
    z_impl_k_sleep(timeout_00);
  } while( true );
  if (((uint)*(byte *)(param_1 + 0xed7) != (uint)*(byte *)(param_1 + 0xcb)) ||
     (uVar8 = (uint)*(byte *)(param_1 + 0xed5), uVar8 != *(byte *)(param_1 + 0xed7))) {
    cVar2 = FUN_00033d5c();
    if (cVar2 == '\x01') {
      uVar14 = set_brightness_to_panel_reg_in_running
                         ((uint)*(byte *)(param_1 + 0xed5),extraout_r1_02);
      *(undefined1 *)(param_1 + 0xcb) = *(undefined1 *)(param_1 + 0xed5);
      *(undefined1 *)(param_1 + 0xed7) = *(undefined1 *)(param_1 + 0xed5);
      uVar8 = extraout_r2;
    }
    else {
      bVar1 = *(byte *)(param_1 + 0xcb);
      *(byte *)(param_1 + 0xed7) = bVar1;
      *(byte *)(param_1 + 0xed5) = bVar1;
      uVar14 = set_brightness_to_panel_reg_in_running((uint)bVar1,extraout_r1_02);
      uVar8 = extraout_r2_00;
    }
  }
  param_2 = (uint)((ulonglong)uVar14 >> 0x20);
  switch(*(byte *)(param_1 + 0xd4) & 0x3f) {
  case 0:
    if (*(char *)(param_1 + 0xfea) == '\x01') {
      if ((*(char *)(param_1 + 0xd5) != '\x06') && (bVar3 = FUN_0002da10(param_1), !bVar3)) {
        param_2 = extraout_r1_04;
        if ((int)LOG_LEVEL < 1) break;
        pcVar5 = "%s(): Ignore data...\n";
        puVar9 = extraout_r2_01;
        goto LAB_0002a0da;
      }
      change_work_mode(2);
      if ((*(char *)(param_1 + 0xd5) == '\x06') && (*(char *)(param_1 + 0xee8) != '\x02')) {
        *(undefined1 *)(param_1 + 0xee8) = 2;
      }
    }
    goto switchD_0002a7f2_default;
  case 1:
    DAT_20019a65 = 1;
    DAT_20019a64 = 1;
    if (*(char *)(param_1 + 0xfea) != '\0') {
      z_impl_k_sleep((k_timeout_t)0xa3e);
      param_2 = extraout_r1_06;
      break;
    }
    FUN_0007ff66(param_1,0);
    *(undefined1 *)(param_1 + 0xee8) = 1;
    puVar11 = *(undefined1 **)(param_1 + 0x1068);
    pcVar5 = "goto idle2";
    *puVar11 = 0;
    puVar11[1] = 0;
    puVar11[2] = 0;
    puVar11[3] = 0;
    uVar8 = 0;
    goto LAB_0002a13c;
  case 2:
    if (*(char *)(param_1 + 0xe5) == '\v') {
      if (1 < (int)LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): slave rcv canvas_distance_gear:%d,raster_height_gear:%d\n",
                 "slave_display_thread");
        }
        else {
          ble_printk("%s(): slave rcv canvas_distance_gear:%d,raster_height_gear:%d\n",
                     "slave_display_thread",(uint)*(byte *)(param_1 + 0xe6),
                     (uint)*(byte *)(param_1 + 0xe7));
        }
      }
      if ((*(byte *)(param_1 + 0xe6) < 10) && (*(byte *)(param_1 + 0xe7) < 9)) {
        pGVar4 = __get_dashboard_state();
        pGVar4->field_0xec1 = *(undefined1 *)(param_1 + 0xe6);
        pGVar4 = __get_dashboard_state();
        pGVar4->field_0xec0 = *(undefined1 *)(param_1 + 0xe7);
        pGVar4 = __get_dashboard_state();
        pGVar6 = __get_dashboard_state();
        cal_panel_canvas_coord((int *)&pGVar4->field_0xec4,(int *)&pGVar6->field_0xeb8);
      }
    }
    DAT_20019a64 = 1;
    if (((((*(char *)(param_1 + 0xd5) == '\t') || (*(char *)(param_1 + 0xd5) == '\f')) ||
         (*(char *)(param_1 + 0xd5) == '\n')) ||
        ((*(char *)(param_1 + 0xd5) == '\v' || (*(char *)(param_1 + 0xd5) == '\x06')))) ||
       ((((*(char *)(param_1 + 0xd5) == '\a' ||
          ((*(char *)(param_1 + 0xd5) == '\x0e' || (*(char *)(param_1 + 0xd5) == '\x0f')))) ||
         (*(char *)(param_1 + 0xd5) == '\x10')) ||
        ((((*(char *)(param_1 + 0xd5) == '\x14' || (*(char *)(param_1 + 0xd5) == '\x11')) ||
          (*(char *)(param_1 + 0xd5) == '\x12')) ||
         ((*(char *)(param_1 + 0xd5) == '\x13' || (*(char *)(param_1 + 0xd5) == '\0')))))))) {
      *(undefined1 *)(param_1 + 0xee8) = 2;
    }
    change_work_mode(2);
    if (((*(char *)(param_1 + 0xd5) != '\t') || (*(char *)(param_1 + 0xd5) != '\n')) ||
       ((*(char *)(param_1 + 0xd5) != '\v' ||
        ((*(char *)(param_1 + 0xd5) != '\x10' ||
         (param_2 = extraout_r1_07, *(char *)(param_1 + 0xd5) != '\x14')))))) {
      k_sem_give((k_sem *)(param_1 + 0x38));
      param_2 = extraout_r1_08;
    }
    DAT_20019a64 = 0;
    break;
  case 3:
    FUN_0007ff66(param_1,1);
    change_work_mode(7);
    param_2 = extraout_r1_09;
    break;
  case 4:
    FUN_0007ff66(param_1,1);
    *(undefined1 *)(param_1 + 0xfee) = 0xc;
    *(undefined4 *)(param_1 + 0x1060) = 3;
    iVar12 = 0x80;
    goto LAB_0002a7c4;
  case 5:
    *(undefined1 *)(param_1 + 0xfee) = 10;
    *(undefined4 *)(param_1 + 0x1060) = 3;
    k_sem_give((k_sem *)(param_1 + 0x80));
    FUN_0003f1bc();
    param_2 = extraout_r1_31;
    break;
  case 6:
    if (*(byte *)(param_1 + 0xe5) == 9) {
      upgradeDashboardStartupModeInfoToFlash((uint)*(byte *)(param_1 + 0xe6),param_2,uVar8);
      param_2 = extraout_r1_10;
      break;
    }
    iVar12 = *(byte *)(param_1 + 0xe5) - 1;
    puVar9 = &switchD_0002a2c6::switchdataD_0002a2cc;
    switch(iVar12) {
    case 0:
      if (*(char *)(param_1 + 0xd5) == '\f') {
        if (*(char *)(param_1 + 0xe6) != '\0') break;
        display_DelayClose(10000);
        goto LAB_0002a36e;
      }
      if (*(char *)(param_1 + 0xe6) != '\x01') break;
      FUN_00080224(param_1,0);
      *(undefined1 *)(param_1 + 0xec) = 0xc;
      *(undefined1 *)(*(int *)(param_1 + 0x1034) + 1) = 1;
      *(undefined1 *)(*(int *)(param_1 + 0x1034) + 2) = 0;
      *(undefined1 *)(*(int *)(param_1 + 0x1034) + 3) = 7;
      pGVar4 = __get_dashboard_state();
      memset((void *)(*(int *)&pGVar4->field_0x1034 + 8),0,0x14a);
      update_persist_task_status(param_1,0xc,2);
      goto switchD_0002a7f2_default;
    case 1:
      bVar1 = *(byte *)(param_1 + 0xe6);
      bVar13 = bVar1 & 0xf;
      if (bVar13 == 1) {
        if (*(char *)(param_1 + 0xd5) != '\x06') goto LAB_0002a4b8;
        FUN_00038ae4(bVar1 >> 4);
      }
      else {
        if (bVar13 == 2) {
          FUN_00038ae4(bVar1 >> 4);
          param_2 = extraout_r1_13;
          break;
        }
        if (bVar13 == 3) {
          if (*(char *)(param_1 + 0xd5) != '\x06') goto LAB_0002a4b8;
          setStocksIndex(bVar1 >> 4,param_2,&switchD_0002a2c6::switchdataD_0002a2cc,6);
        }
        else {
          if (bVar13 == 4) {
            setStocksIndex(bVar1 >> 4,param_2,&switchD_0002a2c6::switchdataD_0002a2cc,iVar12);
            param_2 = extraout_r1_14;
            break;
          }
          if (bVar13 != 5) {
            if (bVar13 == 6) {
              setNewsIndex(bVar1 >> 4,param_2,&switchD_0002a2c6::switchdataD_0002a2cc,iVar12);
              param_2 = extraout_r1_15;
              break;
            }
            if (bVar13 == 7) {
              if (*(char *)(param_1 + 0xd5) == '\x06') {
                uVar8 = (uint)(bVar1 >> 4);
                setCalenadrIndex(bVar1 >> 4,param_2,&switchD_0002a2c6::switchdataD_0002a2cc,6);
                display_inputEvent(0,1);
                z_impl_k_yield();
                param_2 = extraout_r1_16;
                if ((int)LOG_LEVEL < 1) break;
                if (BLE_DEBUG == 0) {
                  uVar7 = FUN_00080732();
                  pcVar5 = 
                  "%s(): received master send touch si gle click command,timestamp = %d,exec key function %d\n"
                  ;
LAB_0002a47c:
                  printk(pcVar5,"slave_display_thread",uVar7,uVar8);
                  param_2 = extraout_r1_18;
                  break;
                }
                uVar7 = FUN_00080732();
                pcVar5 = 
                "%s(): received master send touch si gle click command,timestamp = %d,exec key function %d\n"
                ;
LAB_0002a46a:
                ble_printk(pcVar5,"slave_display_thread",uVar7,uVar8);
                param_2 = extraout_r1_17;
                break;
              }
            }
            else if (bVar13 == 8) {
              uVar8 = (uint)(bVar1 >> 4);
              setCalenadrIndex(bVar1 >> 4,param_2,&switchD_0002a2c6::switchdataD_0002a2cc,iVar12);
              param_2 = extraout_r1_19;
              if ((int)LOG_LEVEL < 1) break;
              if (BLE_DEBUG == 0) {
                uVar7 = FUN_00080732();
                pcVar5 = 
                "%s(): received master send calendar index sync commmand ,timestamp = %d,exec index update %d\n"
                ;
                goto LAB_0002a47c;
              }
              uVar7 = FUN_00080732();
              pcVar5 = 
              "%s(): received master send calendar index sync commmand ,timestamp = %d,exec index update %d\n"
              ;
              goto LAB_0002a46a;
            }
LAB_0002a4b8:
            if (bVar1 == 9) {
              *(undefined1 *)(*(int *)(param_1 + 0xff0) + 0x74) = 2;
            }
            else if (1 < (int)LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): received key press event ,slave screen id = %d,drop it ...\n");
                param_2 = extraout_r1_21;
              }
              else {
                ble_printk("%s(): received key press event ,slave screen id = %d,drop it ...\n",
                           "slave_display_thread",(uint)*(byte *)(param_1 + 0xd5),BLE_DEBUG);
                param_2 = extraout_r1_20;
              }
            }
            break;
          }
          if (*(char *)(param_1 + 0xd5) != '\x06') goto LAB_0002a4b8;
          setNewsIndex(bVar1 >> 4,param_2,&switchD_0002a2c6::switchdataD_0002a2cc,6);
        }
      }
      display_inputEvent(0,1);
LAB_0002a36e:
      z_impl_k_yield();
      param_2 = extraout_r1_12;
      break;
    case 2:
      if (*(char *)(param_1 + 0xd5) == '\t') {
LAB_0002a4f2:
        if (*(char *)(param_1 + 0xe6) == '\x01') {
          display_MasterSendClose((int)uVar14,param_2,&switchD_0002a2c6::switchdataD_0002a2cc,1);
          goto LAB_0002a36e;
        }
        if ((int)LOG_LEVEL < 1) break;
        pcVar5 = "%s(): slave received unknown command,drop it\n";
      }
      else {
        if ((int)LOG_LEVEL < 1) break;
        pcVar5 = 
        "%s(): The master Send the teleprompter command, but the slave\'s current ScreenID is not teleprompter.drop this command..\n"
        ;
      }
      goto LAB_0002a0da;
    case 3:
      *(undefined1 *)(param_1 + 0xcd) = *(undefined1 *)(*(int *)(param_1 + 0x101c) + 3);
      *(undefined1 *)(*(int *)(param_1 + 0x101c) + 2) = *(undefined1 *)(param_1 + 0xe6);
      *(undefined1 *)(*(int *)(param_1 + 0x101c) + 3) = *(undefined1 *)(param_1 + 0xe7);
      FUN_00044b24();
      DAT_2001db40 = *(char *)(param_1 + 0xe7);
      cVar2 = *(char *)(param_1 + 0xe8);
      thunk_FUN_00045444();
      FUN_00042830();
      uVar14 = FUN_0007fea6();
      *(undefined8 *)(*(int *)(param_1 + 0x101c) + 4) = uVar14;
      if ((**(int **)(param_1 + 0x1068) == 0xe) ||
         ((iVar12 = FUN_0007f3da((int)uVar14,(int)((ulonglong)uVar14 >> 0x20)), iVar12 != 0 &&
          (*(char *)(*(int *)(param_1 + 0x101c) + 1) == '\0')))) {
        bVar1 = *(byte *)(*(int *)(param_1 + 0x101c) + 2);
        puVar11 = (undefined1 *)(uint)bVar1;
        if (puVar11 == &DAT_00000003) {
          if (DAT_2001db40 == '\x12') {
            *(char *)(*(int *)(param_1 + 0x101c) + 0xc) = cVar2;
            *(byte *)(*(int *)(param_1 + 0x101c) + 0xd) = bVar1;
            *(byte *)(*(int *)(param_1 + 0x101c) + 0xe) = bVar1;
          }
        }
        else if (puVar11 == &DAT_0000000b) {
          pGVar4 = __get_dashboard_state();
          **(undefined1 **)&pGVar4->field_0x101c = 0;
          pGVar4 = __get_dashboard_state();
          puVar11 = *(undefined1 **)&pGVar4->field_0x101c;
          puVar11[1] = 0;
        }
      }
      else {
        iVar12 = FUN_0007f3da(iVar12,extraout_r1_26);
        puVar11 = extraout_r3;
        if ((iVar12 == 0) && (puVar11 = LOG_LEVEL, 1 < (int)LOG_LEVEL)) {
          if (BLE_DEBUG == 0) {
            printk("%s(): ble device unbound,prepare to show binding tip\n");
            puVar11 = extraout_r3_01;
          }
          else {
            ble_printk("%s(): ble device unbound,prepare to show binding tip\n",
                       "slave_display_thread",extraout_r2_04,BLE_DEBUG);
            puVar11 = extraout_r3_00;
          }
        }
        if (cVar2 == '\x01') {
          **(undefined1 **)(param_1 + 0x101c) = 1;
          update_persist_task_status(param_1,0xe,2);
          *(undefined1 *)(*(int *)(param_1 + 0x101c) + 0x20) = *(undefined1 *)(param_1 + 0xed5);
          puVar11 = &DAT_0000002a;
          *(undefined1 *)(param_1 + 0xed5) = 0x2a;
        }
      }
      uVar8 = 1;
      pcVar5 = "IMU:wakeup:onboarding";
      goto LAB_0002a13c;
    case 4:
      FUN_0003f1bc();
      uVar8 = 1;
      pcVar5 = "TOUCH:wakeup:not_disturb";
      puVar11 = extraout_r3_02;
      goto LAB_0002a13c;
    case 5:
      if (*(char *)(param_1 + 0xd5) == '\n') goto LAB_0002a4f2;
      if ((int)LOG_LEVEL < 1) break;
      pcVar5 = 
      "%s(): The master Send the navigation command, but the slave\'s current ScreenID is not navigation.drop this command..\n"
      ;
      goto LAB_0002a0da;
    case 6:
      if (*(char *)(param_1 + 0xd5) == '\x06') {
        display_powerEvent((uint)*(byte *)(param_1 + 0xe6));
        goto LAB_0002a36e;
      }
      if ((int)LOG_LEVEL < 1) break;
      pcVar5 = 
      "%s(): The master Send the power notify command, but the slave\'s current ScreenID is not dashboard.drop this command..\n"
      ;
LAB_0002a0da:
      if (BLE_DEBUG == 0) {
        printk(pcVar5);
        param_2 = extraout_r1_22;
      }
      else {
        ble_printk(pcVar5,"slave_display_thread",puVar9,BLE_DEBUG);
        param_2 = extraout_r1_05;
      }
      break;
    case 7:
      bVar1 = *(byte *)(param_1 + 0xe6);
      if (((uint)CURRENT_LANGUAGE != (uint)bVar1) && (1 < (int)LOG_LEVEL)) {
        if (BLE_DEBUG == 0) {
          printk("%s(): The information sent by the host is different from that of the APP\n");
          param_2 = extraout_r1_25;
          puVar9 = extraout_r2_03;
        }
        else {
          ble_printk("%s(): The information sent by the host is different from that of the APP\n",
                     "slave_display_thread",&switchD_0002a2c6::switchdataD_0002a2cc,BLE_DEBUG);
          param_2 = extraout_r1_23;
          puVar9 = extraout_r2_02;
        }
      }
      upgradeAppLanguageInfoToFlash((uint)bVar1,param_2,puVar9);
      param_2 = extraout_r1_24;
      break;
    case 9:
      param_2 = DAT_20008518 | 2;
      DAT_20008518 = param_2;
      if (*(char *)(param_1 + 0xe6) == '\x01') {
        pGVar4 = __get_dashboard_state();
        param_2 = extraout_r1_11;
        if (pGVar4->field_0x1244 == '\x04') {
          *(undefined1 *)(param_1 + 0x1245) = 1;
        }
      }
      else if (*(char *)(param_1 + 0xe6) == '\x02') {
        *(undefined1 *)(param_1 + 0x1245) = 0;
        *(undefined1 *)(*(int *)(param_1 + 0xff0) + 0x72) = 0;
      }
      break;
    case 0xb:
      upgradeDoubleTapCustomizeToFlash
                ((uint)*(byte *)(param_1 + 0xe6),param_2,&switchD_0002a2c6::switchdataD_0002a2cc);
      param_2 = extraout_r1_27;
      break;
    case 0xc:
      upgradeLongpressTapCustomizeToFlash
                ((uint)*(byte *)(param_1 + 0xe6),param_2,&switchD_0002a2c6::switchdataD_0002a2cc);
      param_2 = extraout_r1_28;
      break;
    case 0xd:
      if (*(char *)(param_1 + 0xe6) == '\x06') {
        pGVar4 = __get_dashboard_state();
        FUN_00080224((int)pGVar4,0);
        pGVar4 = __get_dashboard_state();
        if (((*(int *)pGVar4->___glasses_state == 0x14) &&
            (pGVar4 = __get_dashboard_state(), **(char **)&pGVar4->field_0x1014 == '\x01')) &&
           ((pGVar4 = __get_dashboard_state(),
            *(char *)(*(int *)&pGVar4->field_0x1014 + 1) == '\x04' &&
            (pGVar4 = __get_dashboard_state(),
            *(char *)(*(int *)&pGVar4->field_0x1014 + 3) == '\x13')))) {
          if (1 < (int)LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): evenai_v2 need to show network_err tip\n");
            }
            else {
              ble_printk("%s(): evenai_v2 need to show network_err tip\n","slave_display_thread",
                         extraout_r2_05,BLE_DEBUG);
            }
          }
          pGVar4 = __get_dashboard_state();
          *(undefined1 *)(pGVar4->___glasses_state + 4) = 2;
          param_2 = extraout_r1_29;
          break;
        }
        pGVar4 = __get_dashboard_state();
        if (*(int *)pGVar4->___glasses_state != 0x14) {
          pGVar4 = __get_dashboard_state();
          **(undefined1 **)&pGVar4->field_0x1014 = 1;
          pGVar4 = __get_dashboard_state();
          memset((void *)(*(int *)&pGVar4->field_0x1014 + 0x10),0,0x200);
          pGVar4 = __get_dashboard_state();
          update_persist_task_status((int)pGVar4,0x14,2);
        }
        pGVar4 = __get_dashboard_state();
        *(undefined1 *)(*(int *)&pGVar4->field_0x1014 + 1) = 7;
        pGVar4 = __get_dashboard_state();
        *(undefined1 *)(*(int *)&pGVar4->field_0x1014 + 3) = *(undefined1 *)(param_1 + 0xe7);
      }
      goto switchD_0002a7f2_default;
    }
    break;
  case 7:
    switch(*(undefined1 *)(param_1 + 0xe5)) {
    case 0:
      update_temp_task_status(param_1,5,2);
      uVar8 = 1;
      pcVar5 = "BLE:wakeup:new-unread_msg";
      puVar11 = extraout_r3_03;
      goto LAB_0002a13c;
    case 1:
      DAT_20019a6d = 1;
      clear_timeout_message(0);
      FUN_0002dd98();
      FUN_000359fc();
      update_temp_task_status(param_1,4,2);
      uVar8 = 1;
      pcVar5 = "IMU:wakeup:uncomplete msg";
      puVar11 = extraout_r3_04;
LAB_0002a13c:
      trigger_screen_state_change(pcVar5,param_1,uVar8,puVar11);
      break;
    case 2:
      __g_arrMsgContent_count();
      pGVar4 = __get_dashboard_state();
      iVar12 = 0;
      if (pGVar4->field_0xdd != '\0') {
        iVar12 = 6;
      }
      FUN_00035abc(iVar12);
      break;
    case 3:
      DAT_20019a5b = 1;
      pGVar4 = __get_dashboard_state();
      if (((pGVar4->field_0x10d6 != '\0') && (uVar8 = FUN_00035310(), uVar8 != 0)) &&
         (pGVar4 = __get_dashboard_state(), pGVar4->field_0xd5 != '\x04')) {
        pGVar4 = __get_dashboard_state();
        update_temp_task_status((int)pGVar4,4,2);
        pGVar4 = __get_dashboard_state();
        trigger_screen_state_change("IMU:wakeup:new-notification",(int)pGVar4,1,extraout_r3_05);
        FUN_0002dd98();
      }
      __get_msg_show_state();
      pGVar4 = __get_dashboard_state();
      k_sem_give(&pGVar4->sem_2);
      FUN_000359d8();
    }
switchD_0002a7f2_default:
    iVar12 = 0x38;
LAB_0002a7c4:
    k_sem_give((k_sem *)(param_1 + iVar12));
    param_2 = extraout_r1_30;
  }
  goto LAB_00029ff6;
}


