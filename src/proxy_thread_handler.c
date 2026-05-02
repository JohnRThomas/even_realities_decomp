/*
 * Function: proxy_thread_handler
 * Entry:    0004b4d0
 * Prototype: undefined __stdcall proxy_thread_handler(int param_1)
 */


/* WARNING: Restarted to delay deadcode elimination for space: ram */

void proxy_thread_handler(int param_1)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  char *fmt;
  GlassesState *pGVar5;
  uint uVar6;
  char *pcVar7;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  undefined4 extraout_r1_02;
  int extraout_r2;
  int extraout_r2_00;
  int extraout_r2_01;
  int extraout_r2_02;
  int extraout_r2_03;
  undefined1 *puVar8;
  undefined1 *puVar9;
  undefined4 extraout_r2_04;
  undefined4 extraout_r2_05;
  undefined4 extraout_r2_06;
  undefined4 extraout_r2_07;
  global_state_struct_0FF0 *pgVar10;
  int iVar11;
  code *pcVar12;
  size_t sVar13;
  k_timeout_t timeout;
  undefined8 local_48;
  undefined1 local_40 [2];
  ushort local_3e;
  byte local_3c;
  char local_3b;
  
  memset(local_40,0,0x18);
LAB_0004b4e6:
  do {
    if ((*(char *)(param_1 + 1) == '\x01') || (*(char *)(param_1 + 1) == '\b')) {
      uVar2 = 0x28000;
LAB_0004b4f4:
      timeout.ticks._4_4_ = 0;
      timeout.ticks._0_4_ = uVar2;
      z_impl_k_sleep(timeout);
      goto LAB_0004b4e6;
    }
    if (-1 < (int)((uint)*(ushort *)(param_1 + 0x1070) << 0x18)) {
      uVar2 = 0x8000;
      goto LAB_0004b4f4;
    }
    memset(local_40,0,0x18);
    iVar3 = z_impl_k_msgq_get((k_msgq *)&DAT_20003acc,local_40,(k_timeout_t)0xffffffffffffffff);
  } while (iVar3 != 0);
  switch(local_40[0]) {
  case 0:
    memset(&DAT_2001e1a6,0,0x14);
    sVar13 = (size_t)local_3e;
    if (0x13 < sVar13) {
      sVar13 = 0x14;
    }
    memcpy(&DAT_2001e1a6,&local_3c,sVar13);
    DAT_200108f2 = (undefined2)sVar13;
    DAT_2001e1a5 = '\x01';
    goto LAB_0004b4e6;
  case 1:
    if (DAT_2001e1a5 != '\0') {
      iVar3 = (**(code **)(param_1 + 0x788))(&DAT_2001e1a6,DAT_200108f2);
      if ((iVar3 < 0) && (1 < LOG_LEVEL)) {
        if (BLE_DEBUG == 0) {
          printk("%s(): Failed to send data over BLE connection: ret = %d \n");
        }
        else {
          ble_printk("%s(): Failed to send data over BLE connection: ret = %d \n",
                     "proxy_thread_handler",iVar3,BLE_DEBUG);
        }
      }
      local_48._0_4_ = 0;
      local_48._4_4_ = 0;
      FUN_0004d4f8(&local_48);
      DAT_2001e1a5 = '\0';
      DAT_200108f2 = 0;
    }
    goto LAB_0004b4e6;
  case 2:
    if (local_3c == 0) {
      DAT_2001e0be = local_3b - 1;
      bVar1 = z_device_is_ready((device *)&DAT_0008b3a0);
      if (!bVar1) goto LAB_0004b5e6;
      memset(&DAT_2001e0bf,0,0xe6);
      pGVar5 = __get_dashboard_state();
      pcVar12 = *(code **)&pGVar5->field_0x1044;
      pGVar5 = __get_dashboard_state();
      iVar3 = (*pcVar12)(pGVar5,0x400000,&DAT_2001e0bf,0xe6);
      if (iVar3 == 0) {
        if ((DAT_2001e0bf == 0x5aa5aa5a) && ((&DAT_2001e0c7)[(uint)DAT_2001e0be * 5] == 2)) {
          DAT_2000aa6c = *(int *)(&DAT_2001e0cb + (uint)DAT_2001e0be * 0x14);
          DAT_2000aa68 = *(int *)(&DAT_2001e0cf + (uint)DAT_2001e0be * 0x14);
        }
        memset(&DAT_2001e0bf,0,0xe6);
        pGVar5 = __get_dashboard_state();
        pcVar12 = *(code **)&pGVar5->field_0x1044;
        pGVar5 = __get_dashboard_state();
        iVar3 = (*pcVar12)(pGVar5,DAT_2000aa6c,&DAT_2001e0bf,0xbe);
        if (iVar3 == 0) {
          DAT_2000aa64 = (DAT_2000aa68 - DAT_2000aa6c) / 0xbe;
          if (DAT_2000aa68 - DAT_2000aa6c != ((DAT_2000aa68 - DAT_2000aa6c) / 0xbe) * 0xbe) {
            DAT_2000aa64 = DAT_2000aa64 + 1;
          }
          DAT_2000aa60 = DAT_2000aa68 - DAT_2000aa6c;
          DAT_2001dfd7 = '\0';
          DAT_2000aa5c = 0;
          DAT_2000aa58 = 0;
          memset(&DAT_2001dfd8,0,0xe6);
          DAT_2001dfd8 = 0x1e;
          DAT_2001dfda = 0;
          DAT_2001dfdb = DAT_2001dfd7;
          DAT_2001dfd7 = DAT_2001dfd7 + '\x01';
          DAT_2001dfdc = 2;
          DAT_2001dfdd = (char)DAT_2000aa64;
          DAT_2001dfde = (undefined1)((uint)DAT_2000aa64 >> 8);
          DAT_2000aa5c = DAT_2000aa5c + 1;
          DAT_2001dfdf = (undefined1)DAT_2000aa5c;
          iVar11 = 3;
          DAT_2001dfe0 = (undefined1)((uint)DAT_2000aa5c >> 8);
          DAT_2001dfe1 = DAT_2001e0be + 1;
          if (DAT_2000aa60 - DAT_2000aa58 < 0xbe) {
            sVar13 = DAT_2000aa60 - DAT_2000aa58;
          }
          else {
            sVar13 = 0xbe;
          }
          memcpy(&DAT_2001dfe2,&DAT_2001e0bf,sVar13);
          DAT_2001dfd9 = (char)sVar13 + 10;
          while (iVar3 = (**(code **)(param_1 + 0x788))(&DAT_2001dfd8,DAT_2001dfd9), iVar3 < 0) {
            if (1 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): Failed to send data over BLE connection: ret = %d \n");
                iVar3 = extraout_r2_01;
              }
              else {
                ble_printk("%s(): Failed to send data over BLE connection: ret = %d \n",
                           "proxy_thread_handler",iVar3,BLE_DEBUG);
                iVar3 = extraout_r2_00;
              }
            }
            iVar11 = iVar11 + -1;
            if (iVar11 == 0) {
              if (LOG_LEVEL < 2) goto LAB_0004b4e6;
              pcVar7 = 
              "%s(): send audio stream more than retry count,break audio send process....\n";
              goto LAB_0004b832;
            }
            if (1 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): retry send audio data first packet\n");
              }
              else {
                ble_printk("%s(): retry send audio data first packet\n","proxy_thread_handler",iVar3
                           ,BLE_DEBUG);
              }
            }
          }
          DAT_2001dfd6 = '\x01';
          DAT_2000aa58 = DAT_2000aa58 + sVar13;
          FUN_00030db0((uint)DAT_2001e0be);
          goto LAB_0004b854;
        }
      }
LAB_0004b622:
      if (0 < LOG_LEVEL) {
        pcVar7 = (char *)0x400000;
        fmt = "%s():  form address [%d] read data failed.\n\n";
        goto LAB_0004b638;
      }
      goto LAB_0004b4e6;
    }
    if (local_3c != 1) goto LAB_0004b4e6;
    if (DAT_2001dfd6 == '\0') {
LAB_0004b86e:
      FUN_00030dc8();
      goto LAB_0004b4e6;
    }
    if (DAT_2000aa58 < DAT_2000aa60) {
      memset(&DAT_2001dfd8,0,0xe6);
      if (DAT_2000aa60 - DAT_2000aa58 < 0xbe) {
        sVar13 = 0;
        if (DAT_2000aa60 - DAT_2000aa58 < 0xbe) {
          sVar13 = DAT_2000aa60 - DAT_2000aa58;
        }
      }
      else {
        sVar13 = 0xbe;
      }
      DAT_2001dfd8 = 0x1e;
      DAT_2001dfd9 = (char)sVar13 + 10;
      DAT_2001dfda = 0;
      DAT_2001dfdb = DAT_2001dfd7;
      DAT_2001dfd7 = DAT_2001dfd7 + '\x01';
      DAT_2001dfdc = 2;
      DAT_2001dfdd = (char)DAT_2000aa64;
      DAT_2001dfde = (undefined1)((uint)DAT_2000aa64 >> 8);
      DAT_2000aa5c = DAT_2000aa5c + 1;
      DAT_2001dfdf = (undefined1)DAT_2000aa5c;
      DAT_2001dfe0 = (undefined1)((uint)DAT_2000aa5c >> 8);
      DAT_2001dfe1 = DAT_2001e0be + 1;
      memset(&DAT_2001e0bf,0,0xe6);
      pGVar5 = __get_dashboard_state();
      pcVar12 = *(code **)&pGVar5->field_0x1044;
      pGVar5 = __get_dashboard_state();
      iVar3 = (*pcVar12)(pGVar5,DAT_2000aa58 + DAT_2000aa6c,&DAT_2001e0bf,sVar13);
      if (iVar3 != 0) {
        if (0 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s():  form address [%d] read data failed.\n\n");
          }
          else {
            ble_printk("%s():  form address [%d] read data failed.\n\n","proxy_thread_handler",
                       0x400000,BLE_DEBUG);
          }
        }
LAB_0004b9a6:
        DAT_2001dfd6 = '\0';
        goto LAB_0004b86e;
      }
      memcpy(&DAT_2001dfe2,&DAT_2001e0bf,sVar13);
      iVar3 = 3;
      while (iVar11 = (**(code **)(param_1 + 0x788))(&DAT_2001dfd8,DAT_2001dfd9), iVar11 < 0) {
        if (1 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): Failed to send data over BLE connection: ret = %d \n");
            iVar11 = extraout_r2_03;
          }
          else {
            ble_printk("%s(): Failed to send data over BLE connection: ret = %d \n",
                       "proxy_thread_handler",iVar11,BLE_DEBUG);
            iVar11 = extraout_r2_02;
          }
        }
        iVar3 = iVar3 + -1;
        if (iVar3 == 0) {
          if (1 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): send audio stream more than retry count,break audio send process....\n")
              ;
            }
            else {
              ble_printk("%s(): send audio stream more than retry count,break audio send process....\n"
                         ,"proxy_thread_handler",iVar11,BLE_DEBUG);
            }
          }
          goto LAB_0004b9a6;
        }
        if (1 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): retry send audio data\n");
          }
          else {
            ble_printk("%s(): retry send audio data\n","proxy_thread_handler",iVar11,BLE_DEBUG);
          }
        }
      }
      DAT_2000aa58 = sVar13 + DAT_2000aa58;
LAB_0004b854:
      sendAudioStreamFileToApp(1,0);
      goto LAB_0004b4e6;
    }
    DAT_2001dfd6 = '\0';
    DAT_2000aa64 = 0;
    DAT_2000aa60 = 0;
    DAT_2000aa58 = 0;
    DAT_2001dfd7 = '\0';
    DAT_2000aa5c = 0;
    DAT_2000aa68 = 0;
    DAT_2000aa6c = 0;
    FUN_00030dc8();
    if (LOG_LEVEL < 1) goto LAB_0004b4e6;
    if (BLE_DEBUG == 0) {
      pGVar5 = __get_dashboard_state();
      pcVar7 = *(char **)pGVar5->glasses_state_struct_0FF0;
      fmt = "%s(): app request over size data ,break,last packet timestamp = %d\n";
      goto LAB_0004b8d8;
    }
    pGVar5 = __get_dashboard_state();
    pgVar10 = pGVar5->glasses_state_struct_0FF0;
    pcVar7 = *(char **)pgVar10;
    fmt = "%s(): app request over size data ,break,last packet timestamp = %d\n";
    break;
  case 3:
    bVar1 = z_device_is_ready((device *)&DAT_0008b3a0);
    if (bVar1) {
      memset(&DAT_2001e0bf,0,0xe6);
      pGVar5 = __get_dashboard_state();
      pcVar12 = *(code **)&pGVar5->field_0x1044;
      pGVar5 = __get_dashboard_state();
      iVar3 = (*pcVar12)(pGVar5,0x400000,&DAT_2001e0bf,0xe6);
      if (iVar3 != 0) goto LAB_0004b622;
      memset(&DAT_2001dfd8,0,0xe6);
      if (local_3c == 0) {
        DAT_2001dfd8 = 0x1e;
      }
      else {
        DAT_2001dfd8 = 0x21;
      }
      DAT_2001dfda = 0;
      DAT_2001dfdb = DAT_2001dfd7;
      DAT_2001dfd7 = DAT_2001dfd7 + '\x01';
      DAT_2001dfdd = '\0';
      DAT_2001dfdc = 1;
      puVar8 = &DAT_2001dfde;
      iVar3 = 0;
      do {
        iVar11 = iVar3 + 1;
        puVar9 = puVar8;
        if ((&DAT_2001e0c7)[iVar3 * 5] == 2) {
          *puVar8 = (char)iVar11;
          uVar4 = (&DAT_2001e0d3)[iVar3 * 5];
          DAT_2001dfdd = DAT_2001dfdd + '\x01';
          puVar8[1] = (char)uVar4;
          puVar8[2] = (char)((uint)uVar4 >> 8);
          puVar8[3] = (char)((uint)uVar4 >> 0x10);
          puVar8[4] = (char)((uint)uVar4 >> 0x18);
          uVar4 = (&DAT_2001e0d7)[iVar3 * 5];
          puVar9 = puVar8 + 9;
          puVar8[5] = (char)uVar4;
          puVar8[6] = (char)((uint)uVar4 >> 8);
          puVar8[7] = (char)((uint)uVar4 >> 0x10);
          puVar8[8] = (char)((uint)uVar4 >> 0x18);
        }
        puVar8 = puVar9;
        iVar3 = iVar11;
      } while (iVar11 != 4);
      DAT_2001dfd9 = DAT_2001dfdd * '\t' + 6;
      for (iVar3 = 0; iVar3 < (int)(uint)DAT_2001dfd9; iVar3 = iVar3 + 1) {
        if (3 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): audio_response_packet_buf[%d] = %d\n\n","proxy_thread_handler",iVar3,
                   (uint)(byte)(&DAT_2001dfd8)[iVar3]);
          }
          else {
            ble_printk("%s(): audio_response_packet_buf[%d] = %d\n\n","proxy_thread_handler",iVar3,
                       (uint)(byte)(&DAT_2001dfd8)[iVar3]);
          }
        }
      }
      pcVar7 = (char *)(**(code **)(param_1 + 0x788))(&DAT_2001dfd8,DAT_2001dfd9);
      if ((-1 < (int)pcVar7) || (LOG_LEVEL < 2)) goto LAB_0004b4e6;
      fmt = "%s(): Failed to send data over BLE connection: ret = %d \n";
    }
    else {
LAB_0004b5e6:
      if (LOG_LEVEL < 1) goto LAB_0004b4e6;
      pcVar7 = "mx25r6435f@0";
      fmt = "%s():  [%s] device not ready.\n\n";
    }
LAB_0004b638:
    pgVar10 = (global_state_struct_0FF0 *)BLE_DEBUG;
    if (BLE_DEBUG == 0) {
LAB_0004b8d8:
      printk(fmt,"proxy_thread_handler",pcVar7);
      goto LAB_0004b4e6;
    }
    break;
  case 4:
    iVar3 = 1;
    uVar2 = (uint)local_3c;
    local_48._0_2_ = CONCAT11(local_3c,7);
    do {
      pGVar5 = __get_dashboard_state();
      uVar6 = sync_to_slave((char *)pGVar5,6,(undefined4 *)&local_48,2);
      if ((int)uVar6 < 5000) {
        display_powerEvent(uVar2);
        z_impl_k_yield();
        break;
      }
      if (1 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): SYNC TO Slave failed %d times,don\'t exec quick note start function.\n");
        }
        else {
          ble_printk("%s(): SYNC TO Slave failed %d times,don\'t exec quick note start function.\n",
                     "proxy_thread_handler",iVar3,BLE_DEBUG);
        }
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 != 4);
    goto LAB_0004b4e6;
  case 5:
    iVar3 = 1;
    uVar2 = (uint)local_3c;
    local_48._0_2_ = CONCAT11(local_3c,8);
    do {
      pGVar5 = __get_dashboard_state();
      uVar6 = sync_to_slave((char *)pGVar5,6,(undefined4 *)&local_48,2);
      if ((int)uVar6 < 5000) {
        upgradeAppLanguageInfoToFlash(uVar2,extraout_r1,extraout_r2_04);
        break;
      }
      if (1 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): SYNC TO Slave failed %d times,don\'t exec quick note start function.\n");
        }
        else {
          ble_printk("%s(): SYNC TO Slave failed %d times,don\'t exec quick note start function.\n",
                     "proxy_thread_handler",iVar3,BLE_DEBUG);
        }
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 != 4);
    goto LAB_0004b4e6;
  case 6:
    iVar3 = 1;
    uVar2 = (uint)local_3c;
    local_48._0_2_ = CONCAT11(local_3c,9);
    do {
      pGVar5 = __get_dashboard_state();
      uVar6 = sync_to_slave((char *)pGVar5,6,(undefined4 *)&local_48,2);
      if ((int)uVar6 < 5000) {
        upgradeDashboardStartupModeInfoToFlash(uVar2,extraout_r1_00,extraout_r2_05);
        break;
      }
      if (1 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): SYNC TO Slave failed %d times,don\'t exec quick note start function.\n");
        }
        else {
          ble_printk("%s(): SYNC TO Slave failed %d times,don\'t exec quick note start function.\n",
                     "proxy_thread_handler",iVar3,BLE_DEBUG);
        }
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 != 4);
    goto LAB_0004b4e6;
  case 7:
    pGVar5 = __get_dashboard_state();
    if (((pGVar5->field_0x1244 == '\x04') &&
        (pGVar5 = __get_dashboard_state(), pGVar5->field_0xd5 == '\0')) &&
       (pGVar5 = __get_dashboard_state(), *(char *)pGVar5 == '\x01')) {
      local_48._0_4_ = CONCAT22(local_48._2_2_,0x10a);
      iVar3 = 1;
      do {
        pGVar5 = __get_dashboard_state();
        uVar2 = sync_to_slave((char *)pGVar5,6,(undefined4 *)&local_48,2);
        if ((int)uVar2 < 5000) {
          DAT_20008518 = DAT_20008518 | 2;
          pGVar5 = __get_dashboard_state();
          pGVar5->field_0x1245 = 1;
          break;
        }
        if (1 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk(
                  "%s(): SYNC TO Slave failed %d times,don\'t exec double click startup dashboard function.\n"
                  );
          }
          else {
            ble_printk("%s(): SYNC TO Slave failed %d times,don\'t exec double click startup dashboard function.\n"
                       ,"proxy_thread_handler",iVar3,BLE_DEBUG);
          }
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 != 4);
    }
    pGVar5 = __get_dashboard_state();
    if (((pGVar5->field_0xd5 == '\x06') &&
        ((pGVar5 = __get_dashboard_state(), pGVar5->field_0x1245 != '\0' ||
         (pGVar5 = __get_dashboard_state(), pGVar5->glasses_state_struct_0FF0->field_0x72 != '\0')))
        ) && (pGVar5 = __get_dashboard_state(), *(char *)pGVar5 == '\x01')) {
      local_48._0_4_ = CONCAT22(local_48._2_2_,0x20a);
      iVar3 = 1;
      do {
        pGVar5 = __get_dashboard_state();
        uVar2 = sync_to_slave((char *)pGVar5,6,(undefined4 *)&local_48,2);
        if ((int)uVar2 < 5000) {
          DAT_20008518 = DAT_20008518 | 2;
          pGVar5 = __get_dashboard_state();
          pGVar5->field_0x1245 = 0;
          pGVar5 = __get_dashboard_state();
          pGVar5->glasses_state_struct_0FF0->field_0x72 = 0;
          break;
        }
        if (1 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk(
                  "%s(): SYNC TO Slave failed %d times,don\'t exec double click startup dashboard function.\n"
                  );
          }
          else {
            ble_printk("%s(): SYNC TO Slave failed %d times,don\'t exec double click startup dashboard function.\n"
                       ,"proxy_thread_handler",iVar3,BLE_DEBUG);
          }
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 != 4);
    }
    goto LAB_0004b4e6;
  case 8:
    iVar3 = 1;
    uVar2 = (uint)local_3c;
    local_48._0_2_ = CONCAT11(local_3c,0xc);
    do {
      pGVar5 = __get_dashboard_state();
      uVar6 = sync_to_slave((char *)pGVar5,6,(undefined4 *)&local_48,2);
      if ((int)uVar6 < 5000) {
        upgradeDoubleTapCustomizeToFlash(uVar2,extraout_r1_01,extraout_r2_06);
        break;
      }
      if (1 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): SYNC TO Slave failed %d times,don\'t exec double_tap_customize\n");
        }
        else {
          ble_printk("%s(): SYNC TO Slave failed %d times,don\'t exec double_tap_customize\n",
                     "proxy_thread_handler",iVar3,BLE_DEBUG);
        }
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 != 4);
    goto LAB_0004b4e6;
  case 9:
    iVar3 = 1;
    uVar2 = (uint)local_3c;
    local_48._0_2_ = CONCAT11(local_3c,0xd);
    do {
      pGVar5 = __get_dashboard_state();
      uVar6 = sync_to_slave((char *)pGVar5,6,(undefined4 *)&local_48,2);
      if ((int)uVar6 < 5000) {
        upgradeLongpressTapCustomizeToFlash(uVar2,extraout_r1_02,extraout_r2_07);
        break;
      }
      if (1 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): SYNC TO Slave failed %d times,don\'t exec longpress_tap_customize\n");
        }
        else {
          ble_printk("%s(): SYNC TO Slave failed %d times,don\'t exec longpress_tap_customize\n",
                     "proxy_thread_handler",iVar3,BLE_DEBUG);
        }
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 != 4);
    goto LAB_0004b4e6;
  default:
    if (0 < LOG_LEVEL) {
      pcVar7 = "%s(): received unkonwn command,drop it\n";
      iVar3 = extraout_r2;
LAB_0004b832:
      if (BLE_DEBUG == 0) {
        printk(pcVar7);
      }
      else {
        ble_printk(pcVar7,"proxy_thread_handler",iVar3,BLE_DEBUG);
      }
    }
    goto LAB_0004b4e6;
  }
  ble_printk(fmt,"proxy_thread_handler",pcVar7,pgVar10);
  goto LAB_0004b4e6;
}


