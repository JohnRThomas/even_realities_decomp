/*
 * Function: FUN_0003cdac
 * Entry:    0003cdac
 * Prototype: undefined4 __stdcall FUN_0003cdac(int param_1, int param_2)
 */


/* WARNING: Removing unreachable block (ram,0x0003d3f2) */
/* WARNING: Removing unreachable block (ram,0x0003d104) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0003cdac(int param_1,int param_2)

{
  longlong lVar1;
  byte bVar2;
  bool bVar3;
  char cVar4;
  undefined1 uVar5;
  GlassesState *pGVar6;
  void *pvVar7;
  uint uVar8;
  int iVar9;
  undefined4 uVar10;
  uint extraout_r0;
  uint extraout_r0_00;
  char *pcVar11;
  GlassesState *pGVar12;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  undefined4 extraout_r1_02;
  undefined4 extraout_r1_03;
  undefined4 extraout_r1_04;
  undefined4 extraout_r1_05;
  undefined4 extraout_r1_06;
  undefined4 extraout_r1_07;
  undefined4 extraout_r1_08;
  undefined4 extraout_r1_09;
  undefined4 extraout_r1_10;
  undefined4 extraout_r1_11;
  undefined4 extraout_r1_12;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 extraout_r2_02;
  undefined4 extraout_r2_03;
  undefined4 extraout_r2_04;
  undefined4 extraout_r2_05;
  undefined4 extraout_r2_06;
  undefined4 extraout_r2_07;
  undefined4 extraout_r2_08;
  undefined4 extraout_r2_09;
  undefined4 extraout_r2_10;
  undefined4 extraout_r2_11;
  undefined4 extraout_r2_12;
  undefined4 extraout_r2_13;
  undefined4 extraout_r2_14;
  undefined4 extraout_r2_15;
  undefined4 extraout_r2_16;
  undefined4 extraout_r2_17;
  undefined4 extraout_r2_18;
  undefined4 uVar13;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 extraout_r3_01;
  int extraout_r3_02;
  int extraout_r3_03;
  undefined4 extraout_r3_04;
  global_state_struct_0FF0 *pgVar14;
  uint uVar15;
  undefined1 *puVar16;
  int iVar17;
  ulonglong uVar18;
  undefined8 uVar19;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  
  pGVar6 = __get_dashboard_state();
  puVar16 = &pGVar6->field_0xef;
  FUN_000452f0(param_1 + 0x24);
  if (DAT_20004af8 == '\0') {
    if (2 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk(pcRam0003ce70);
      }
      else {
        ble_printk(pcRam0003ce70,___ui_DashBoard_task_init,extraout_r2,BLE_DEBUG);
      }
    }
    enter_dashboard_burial_point();
    if (param_2 == 2) {
      if (2 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): dashboard function exit ...\n");
        }
        else {
          ble_printk("%s(): dashboard function exit ...\n",___ui_DashBoard_task_init,extraout_r2_00,
                     BLE_DEBUG);
        }
      }
      pGVar6 = __get_dashboard_state();
      pGVar6->glasses_state_struct_0FF0->field_0x73 = 0;
      uVar19 = FUN_00029774(0x1f,extraout_r1,extraout_r2_01);
      gui_screen_clear((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),extraout_r2_02);
      goto LAB_0003ce42;
    }
    if (((param_2 != 1) ||
        (pGVar12 = __get_dashboard_state(), pGVar12->glasses_state_struct_0FF0->field_0x73 != '\x01'
        )) || (pGVar6->field_0x162 != '\x01')) goto LAB_0003d09a;
    if (cRam20004b04 == '\0') {
      uVar10 = extraout_r1_00;
      uVar13 = extraout_r2_03;
      if (2 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): DASHBOARD INIT .......\n");
          uVar10 = extraout_r1_05;
          uVar13 = extraout_r2_09;
        }
        else {
          ble_printk("%s(): DASHBOARD INIT .......\n","ui_DashBoard_task",extraout_r2_03,BLE_DEBUG);
          uVar10 = extraout_r1_01;
          uVar13 = extraout_r2_04;
        }
      }
      FUN_00029774(0x1e,uVar10,uVar13);
      pvVar7 = memset(&DAT_20004af8,0,0x28);
      gui_screen_clear(pvVar7,extraout_r1_02,extraout_r2_05);
      cRam20004b04 = '\x01';
      DAT_20004b18 = pGVar6->field_0x156;
      DAT_20004af9 = DAT_2001c4e6;
      DAT_20004afb = DAT_2001c4e5;
      DAT_20004afd = DAT_2001c4e4;
      DAT_20004b00 = DAT_2001c4e3;
      if (2 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): quicknote index = %d,stocks index = %d,news index = %d,calendar = %d\n");
        }
        else {
          ble_printk("%s(): quicknote index = %d,stocks index = %d,news index = %d,calendar = %d\n",
                     "ui_DashBoard_task",(uint)DAT_2001c4e6,(uint)DAT_2001c4e5);
        }
        if (2 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): db_info->schedule_disp_status = %d\n");
          }
          else {
            ble_printk("%s(): db_info->schedule_disp_status = %d\n","ui_DashBoard_task",
                       (uint)(byte)pGVar6->field_0x156,BLE_DEBUG);
          }
          if (2 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): db_info->stocks_disp_mode = %d\n");
            }
            else {
              ble_printk("%s(): db_info->stocks_disp_mode = %d\n","ui_DashBoard_task",
                         (uint)(byte)pGVar6->field_0x158,BLE_DEBUG);
            }
            if (2 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): db_info->news_disp_mode = %d\n");
              }
              else {
                ble_printk("%s(): db_info->news_disp_mode = %d\n","ui_DashBoard_task",
                           (uint)(byte)pGVar6->field_0x159,BLE_DEBUG);
              }
              if (2 < LOG_LEVEL) {
                if (BLE_DEBUG == 0) {
                  printk("%s(): db_info->schedule_disp_status = %d\n");
                }
                else {
                  ble_printk("%s(): db_info->schedule_disp_status = %d\n","ui_DashBoard_task",
                             (uint)(byte)pGVar6->field_0x156,BLE_DEBUG);
                }
                if (2 < LOG_LEVEL) {
                  if (BLE_DEBUG == 0) {
                    printk("%s(): db_info->citywalk_disp_mode = %d\n");
                  }
                  else {
                    ble_printk("%s(): db_info->citywalk_disp_mode = %d\n","ui_DashBoard_task",
                               (uint)(byte)pGVar6->field_0x15a,BLE_DEBUG);
                  }
                }
              }
            }
          }
        }
      }
      FUN_00045428();
      DAT_2000a9b0 = 0;
      while (DAT_2000a9b0 < 4) {
        pGVar12 = __get_dashboard_state();
        DashBoard_Reflash((int)puVar16,(int)pGVar12,1,(uint)(byte)pGVar6->field_0x154);
        uVar8 = 0;
        do {
          iVar9 = 0;
          do {
            uStack_a0 = 0x7050301;
            uStack_9c = 0x7070707;
            iVar17 = *(int *)(param_1 + 0x24 + uVar8 * 4);
            bVar2 = *(byte *)(iVar17 + iVar9);
            if (bVar2 != 0) {
              *(byte *)(iVar17 + iVar9) =
                   bVar2 & (&DAT_000accab)
                           [iVar9 + (uint)*(byte *)((int)&uStack_a0 + DAT_2000a9b0) * 0x140 +
                                    (uVar8 % 0x1a) * 0xa00];
            }
            iVar9 = iVar9 + 1;
          } while (iVar9 != 0x140);
          uVar8 = uVar8 + 1;
        } while (uVar8 != 199);
        DAT_2000a9b0 = DAT_2000a9b0 + 1;
        pGVar12 = __get_dashboard_state();
        iVar9 = *(int *)&pGVar12->field_0xeb4;
        pGVar12 = __get_dashboard_state();
        _reflash_fb_data_to_lcd(iVar9,*(int *)&pGVar12->field_0xeb8,0,0,0x280,199);
      }
      FUN_0004540c();
      pGVar6 = __get_dashboard_state();
      if (*(char *)pGVar6 == '\x01') {
        uStack_a0 = CONCAT22(uStack_a0._2_2_,0x202);
        if (PANE_MODE == 0) {
          bVar2 = FUN_00038ac8();
          uVar8 = (bVar2 & 0xf) << 4 | uStack_a0 >> 8 & 0xff;
          uStack_a0._0_2_ = CONCAT11((char)uVar8,(undefined1)uStack_a0);
          if (2 < LOG_LEVEL) {
            pcVar11 = "%s(): master sync quicknote index to slave ,index = %d\n";
            goto LAB_0003d002;
          }
        }
        else if (PANE_MODE == 1) {
          uStack_a0 = CONCAT22(uStack_a0._2_2_,0x402);
          bVar2 = getStocksIndex();
          uVar8 = (bVar2 & 0xf) << 4 | uStack_a0 >> 8 & 0xff;
          uStack_a0._0_2_ = CONCAT11((char)uVar8,(undefined1)uStack_a0);
          if (2 < LOG_LEVEL) {
            pcVar11 = "%s(): master sync stocks index to slave,index = %d\n";
LAB_0003d002:
            if (BLE_DEBUG == 0) {
              printk(pcVar11);
            }
            else {
              ble_printk(pcVar11,"ui_DashBoard_task",uVar8,BLE_DEBUG);
            }
          }
        }
        else {
          if (PANE_MODE == 2) {
            uStack_a0 = CONCAT22(uStack_a0._2_2_,0x602);
            bVar2 = getNewsIndex();
          }
          else {
            if (PANE_MODE != 3) goto LAB_0003d00c;
            uStack_a0 = CONCAT22(uStack_a0._2_2_,0x802);
            bVar2 = getCalenadrIndex();
          }
          uVar8 = (bVar2 & 0xf) << 4 | uStack_a0 >> 8 & 0xff;
          uStack_a0._0_2_ = CONCAT11((char)uVar8,(undefined1)uStack_a0);
          if (2 < LOG_LEVEL) {
            pcVar11 = "%s(): master sync news index to slave,index = %d\n";
            goto LAB_0003d002;
          }
        }
LAB_0003d00c:
        pGVar6 = __get_dashboard_state();
        uVar8 = sync_to_slave((char *)pGVar6,6,&uStack_a0,2);
        if ((int)uVar8 < 5000) {
          if (2 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              uVar10 = FUN_00080732();
              printk("%s(): sync to slave return value = %d,exec key function. ts = %d\n",
                     "ui_DashBoard_task",uVar8,uVar10);
            }
            else {
              uVar10 = FUN_00080732();
              ble_printk("%s(): sync to slave return value = %d,exec key function. ts = %d\n",
                         "ui_DashBoard_task",uVar8,uVar10);
            }
          }
        }
        else if (1 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): SYNC TO Slave failed...,don\'t exec key function.\n");
          }
          else {
            ble_printk("%s(): SYNC TO Slave failed...,don\'t exec key function.\n",
                       "ui_DashBoard_task",extraout_r2_06,BLE_DEBUG);
          }
        }
      }
      uVar18 = sys_clock_tick_get();
      lVar1 = (uVar18 & 0xffffffff) * 1000;
      uVar8 = (int)(uVar18 >> 0x20) * 1000 + (int)((ulonglong)lVar1 >> 0x20);
      DAT_20004b08 = (uint)lVar1 >> 0xf | uVar8 * 0x20000;
      DAT_20004b0c = uVar8 >> 0xf;
      DAT_20004af8 = '\x01';
      DAT_20004b1c = 1;
      uVar10 = FUN_0004c124(0x42);
      __send_message_count_to_app(uVar10,extraout_r1_03,extraout_r2_07,extraout_r3);
    }
    pGVar6 = __get_dashboard_state();
    if (*(char *)pGVar6 == '\x01') {
      bVar3 = FUN_00028d2c();
      if (bVar3) {
        cVar4 = FUN_00030440();
        if ((cVar4 == '\x01') && (pGVar6 = __get_dashboard_state(), *(char *)(pGVar6 + 1) == '\0'))
        {
          FUN_0008040c();
        }
      }
      else {
        cVar4 = FUN_00030440();
        if (cVar4 != '\x01') {
          FUN_00030458();
        }
      }
    }
LAB_0003d09a:
    iVar9 = FUN_000806de(&DAT_20007f50);
    if (-1 < iVar9 << 0x1e) {
      return 0;
    }
    iVar9 = FUN_000806de(&DAT_20007f4c);
    if (iVar9 << 0x1e < 0) {
      return 0;
    }
    uStack_a0 = 0x650;
    uStack_9c = CONCAT22(uStack_9c._2_2_,0x201);
    if (2 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): send dashboard lock info to app ,status = %d \n");
      }
      else {
        ble_printk("%s(): send dashboard lock info to app ,status = %d \n","ui_DashBoard_task",2,
                   BLE_DEBUG);
      }
    }
    uVar10 = send_response_data_to_msgqueue(&uStack_a0,6);
    send_response_data_to_ble(uVar10,extraout_r1_04,extraout_r2_08,extraout_r3_00);
    DAT_20007f4c = DAT_20007f4c | 2;
    return 0;
  }
  if (DAT_20004af8 != '\x01') {
    return 0;
  }
  uVar8 = FUN_000806de(&DAT_20007f50);
  if (((uVar8 & 2) != 0) && (iVar9 = FUN_000806de(&DAT_20007f4c), -1 < iVar9 << 0x1e)) {
    uStack_a0 = 0x650;
    uStack_9c = CONCAT22(uStack_9c._2_2_,0x201);
    if (2 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): send dashboard lock info to app ,status = %d \n");
      }
      else {
        ble_printk("%s(): send dashboard lock info to app ,status = %d \n","ui_DashBoard_task",2,
                   BLE_DEBUG);
      }
    }
    uVar10 = send_response_data_to_msgqueue(&uStack_a0,6);
    send_response_data_to_ble(uVar10,extraout_r1_06,extraout_r2_10,extraout_r3_01);
    DAT_20007f4c = DAT_20007f4c | 2;
  }
  uVar8 = FUN_00035310();
  if (uVar8 != DAT_20004b1d) {
    uVar8 = FUN_00035310();
    DAT_20004b1d = (byte)uVar8;
    uVar10 = extraout_r1_07;
    uVar13 = extraout_r2_11;
    iVar9 = LOG_LEVEL;
    if (2 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk(
              "%s(): notify message count has changed,send message count to app. unread messgae count = %d\n"
              );
        uVar8 = extraout_r0_00;
        uVar10 = extraout_r1_10;
        uVar13 = extraout_r2_16;
        iVar9 = extraout_r3_03;
      }
      else {
        ble_printk("%s(): notify message count has changed,send message count to app. unread messgae count = %d\n"
                   ,"ui_DashBoard_task",uVar8 & 0xff,BLE_DEBUG);
        uVar8 = extraout_r0;
        uVar10 = extraout_r1_08;
        uVar13 = extraout_r2_12;
        iVar9 = extraout_r3_02;
      }
    }
    __send_message_count_to_app(uVar8,uVar10,uVar13,iVar9);
  }
  FUN_0004540c();
  if (LOG_LEVEL < 3) {
    uVar10 = extraout_r2_13;
    if (param_2 != 2) goto LAB_0003d6c6;
  }
  else {
    if (BLE_DEBUG == 0) {
      printk("%s(): Enter DASHBOARD_RUNING_STATUS task....\n");
      uVar10 = extraout_r2_17;
    }
    else {
      ble_printk("%s(): Enter DASHBOARD_RUNING_STATUS task....\n","ui_DashBoard_task",extraout_r2_13
                 ,BLE_DEBUG);
      uVar10 = extraout_r2_14;
    }
    if (param_2 != 2) {
LAB_0003d6c6:
      if (param_2 == 1) {
        pGVar12 = __get_dashboard_state();
        DashBoard_Reflash((int)puVar16,(int)pGVar12,1,(uint)(byte)pGVar6->field_0x154);
        return 0;
      }
      if (param_2 == 0) {
        if (2 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): current index = %d\n");
          }
          else {
            ble_printk("%s(): current index = %d\n","ui_DashBoard_task",
                       (uint)(byte)pGVar6->field_0x154,BLE_DEBUG);
          }
        }
        pGVar12 = __get_dashboard_state();
        DashBoard_Reflash((int)puVar16,(int)pGVar12,0,(uint)(byte)pGVar6->field_0x154);
        goto LAB_0003d43e;
      }
      if (param_2 != 4) {
        if (param_2 == 6) {
          if (2 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): received system low power event.\n");
            }
            else {
              ble_printk("%s(): received system low power event.\n","ui_DashBoard_task",uVar10,
                         BLE_DEBUG);
            }
          }
          pGVar6 = __get_dashboard_state();
          uVar13 = 1;
          pgVar14 = pGVar6->glasses_state_struct_0FF0;
          uVar10 = extraout_r1_11;
        }
        else {
          if (param_2 != 7) goto LAB_0003d43e;
          if (2 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): received system  power resume event.\n");
            }
            else {
              ble_printk("%s(): received system  power resume event.\n","ui_DashBoard_task",uVar10,
                         BLE_DEBUG);
            }
          }
          pGVar6 = __get_dashboard_state();
          uVar13 = 0;
          pgVar14 = pGVar6->glasses_state_struct_0FF0;
          uVar10 = extraout_r1_12;
        }
        pgVar14->field_0x60 = (char)uVar13;
        __send_message_count_to_app(pGVar6,uVar10,uVar13,pgVar14);
        goto LAB_0003d43e;
      }
      if (0 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): received key press event,_dashboard_prv_data.display_mode = %d\n");
        }
        else {
          ble_printk("%s(): received key press event,_dashboard_prv_data.display_mode = %d\n",
                     "ui_DashBoard_task",(uint)DAT_20004b11,BLE_DEBUG);
        }
      }
      uVar8 = (uint)PANE_MODE;
      if (0 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): _CurrentCustomAreaType = %d\n");
        }
        else {
          ble_printk("%s(): _CurrentCustomAreaType = %d\n","ui_DashBoard_task",uVar8,BLE_DEBUG);
        }
      }
      if (uVar8 == 0) {
        if (1 < DAT_20004afa) {
          DAT_20004af9 = (DAT_20004af9 + 1) -
                         DAT_20004afa * ((byte)(DAT_20004af9 + 1) / DAT_20004afa);
          DAT_2001c4e6 = DAT_20004af9;
          FUN_000167cc(DAT_20004af9);
          if (2 < LOG_LEVEL) {
            uVar8 = (uint)DAT_20004af9;
            pcVar11 = "%s(): current quicknote index = %d\n";
LAB_0003d55a:
            if (BLE_DEBUG == 0) {
              printk(pcVar11);
            }
            else {
              ble_printk(pcVar11,"ui_DashBoard_task",uVar8,BLE_DEBUG);
            }
          }
        }
      }
      else if (uVar8 == 1) {
        uVar8 = (uint)DAT_20004afc;
        if (1 < uVar8) {
          uVar15 = (uint)(byte)(DAT_20004afb + 1) - uVar8 * ((byte)(DAT_20004afb + 1) / uVar8);
          uVar8 = uVar15 & 0xff;
          DAT_20004afb = (byte)uVar15;
          DAT_2001c4e5 = DAT_20004afb;
          if (2 < LOG_LEVEL) {
            pcVar11 = "%s(): current stocks index = %d\n";
            goto LAB_0003d55a;
          }
        }
      }
      else if (uVar8 == 2) {
        uVar8 = (uint)DAT_20004afe;
        if ((1 < uVar8) && (DAT_20004afd != '\x03')) {
          uVar15 = (uint)(byte)(DAT_20004afd + 1) - uVar8 * ((byte)(DAT_20004afd + 1) / uVar8);
          uVar8 = uVar15 & 0xff;
          DAT_20004afd = (char)uVar15;
          DAT_2001c4e4 = DAT_20004afd;
          if (2 < LOG_LEVEL) {
            pcVar11 = "%s(): current news index = %d\n";
            goto LAB_0003d55a;
          }
        }
      }
      else if (uVar8 == 3) {
        uVar8 = (uint)DAT_20004b01;
        if (uVar8 != 0) {
          uVar15 = (uint)(byte)(DAT_20004b00 + 1) - uVar8 * ((byte)(DAT_20004b00 + 1) / uVar8);
          uVar8 = uVar15 & 0xff;
          DAT_20004b00 = (char)uVar15;
          DAT_2001c4e3 = DAT_20004b00;
          if (0 < LOG_LEVEL) {
            pcVar11 = "%s(): current calendar index = %d\n";
            goto LAB_0003d55a;
          }
        }
      }
      else if (uVar8 == 4) goto LAB_0003d43e;
      pGVar12 = __get_dashboard_state();
      uVar19 = DashBoard_Reflash((int)puVar16,(int)pGVar12,4,(uint)(byte)pGVar6->field_0x154);
      sync_dashboard_key_event_to_app
                ((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),extraout_r2_18,extraout_r3_04);
LAB_0003d43e:
      pGVar6 = __get_dashboard_state();
      if (*(char *)pGVar6 != '\x01') {
        return 0;
      }
      iVar9 = FUN_00080756();
      uVar18 = sys_clock_tick_get();
      lVar1 = (uVar18 & 0xffffffff) * 1000;
      uVar15 = (int)(uVar18 >> 0x20) * 1000 + (int)((ulonglong)lVar1 >> 0x20);
      uVar8 = (uint)lVar1 >> 0xf | uVar15 * 0x20000;
      uVar15 = uVar15 >> 0xf;
      if (iVar9 == 0) {
        pGVar6 = __get_dashboard_state();
        if (pGVar6->glasses_state_struct_0FF0->field_0x60 != '\0') {
          if (DAT_20004b06 != '\0') {
            return 0;
          }
          if ((int)((uVar15 - DAT_20004b0c) - (uint)(uVar8 < DAT_20004b08)) <
              (int)(uint)(uVar8 - DAT_20004b08 < 0x5dd)) {
            return 0;
          }
        }
        uVar5 = 1;
      }
      else {
        pGVar6 = __get_dashboard_state();
        if (pGVar6->glasses_state_struct_0FF0->field_0x60 != '\x01') {
          if (DAT_20004b06 != '\0') {
            return 0;
          }
          if ((int)((uVar15 - DAT_20004b0c) - (uint)(uVar8 < DAT_20004b08)) <
              (int)(uint)(uVar8 - DAT_20004b08 < 0x5dd)) {
            return 0;
          }
        }
        uVar5 = 0;
      }
      SendPowerInfoToSlave(uVar5);
      DAT_20004b06 = 1;
      return 0;
    }
    if (2 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): dashboard function exit ...\n");
      }
      else {
        ble_printk("%s(): dashboard function exit ...\n","ui_DashBoard_task",uVar10,BLE_DEBUG);
      }
    }
  }
  pGVar6 = __get_dashboard_state();
  pGVar6->glasses_state_struct_0FF0->field_0x73 = 0;
  FUN_00029774(0x1f,extraout_r1_09,extraout_r2_15);
  FUN_00045968();
LAB_0003ce42:
  DAT_20008480 = DAT_20008480 & 0xfffffffd;
  exit_dashboard_burial_point();
  memset(&DAT_20004af8,0,0x28);
                    /* WARNING: Read-only address (ram,0x0003ce6c) is written */
                    /* WARNING: Read-only address (ram,0x0003ce70) is written */
  return 0;
}


