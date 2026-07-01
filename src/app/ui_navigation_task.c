/*
 * Function: ui_navigation_task
 * Entry:    00041438
 * Prototype: undefined4 __stdcall ui_navigation_task(int param_1, undefined4 param_2, uint param_3)
 */


undefined4 ui_navigation_task(int param_1,undefined4 param_2,uint param_3)

{
  char cVar1;
  short sVar2;
  byte bVar3;
  ushort uVar4;
  ushort uVar5;
  GlassesState *pGVar6;
  undefined4 uVar7;
  undefined4 extraout_r0;
  undefined4 extraout_r0_00;
  undefined4 extraout_r0_01;
  undefined4 extraout_r0_02;
  undefined4 extraout_r0_03;
  undefined4 extraout_r0_04;
  GlassesState *pGVar8;
  int iVar9;
  int extraout_r0_05;
  int extraout_r0_06;
  int iVar10;
  int extraout_r0_07;
  int extraout_r0_08;
  int extraout_r0_09;
  char *fmt;
  int extraout_r0_10;
  int extraout_r0_11;
  int extraout_r0_12;
  dashboard_ts_context *dashboard_ts_ctx;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  undefined4 uVar11;
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
  undefined4 extraout_r1_13;
  undefined4 extraout_r1_14;
  undefined4 extraout_r1_15;
  undefined4 extraout_r1_16;
  undefined4 extraout_r1_17;
  undefined4 extraout_r1_18;
  undefined4 extraout_r1_19;
  undefined4 extraout_r1_20;
  undefined4 extraout_r1_21;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 uVar12;
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
  undefined4 extraout_r2_19;
  undefined4 extraout_r2_20;
  undefined4 extraout_r2_21;
  undefined4 extraout_r2_22;
  uint extraout_r2_23;
  uint extraout_r2_24;
  undefined4 extraout_r2_25;
  uint extraout_r2_26;
  uint extraout_r2_27;
  undefined4 extraout_r2_28;
  undefined4 extraout_r2_29;
  undefined4 extraout_r2_30;
  undefined4 extraout_r2_31;
  undefined4 extraout_r2_32;
  undefined4 extraout_r2_33;
  uint uVar13;
  undefined4 extraout_r2_34;
  undefined4 extraout_r2_35;
  undefined4 extraout_r2_36;
  undefined4 extraout_r2_37;
  int iVar14;
  undefined *puVar15;
  bool bVar16;
  k_timeout_t timeout;
  undefined8 uVar17;
  undefined8 uVar18;
  uint local_34;
  undefined4 uStack_30;
  uint local_2c;
  
  pGVar6 = __get_dashboard_state();
  puVar15 = pGVar6->field20_0xc8 + 0x27;
  FUN_000452f0(param_1 + 0x24);
  uVar7 = FUN_0004540c();
  uVar18 = CONCAT44(DAT_20004da4,DAT_20004da0);
  switch(DAT_20004d70) {
  case 0:
    if (LOG_LEVEL < 3) {
      uVar11 = extraout_r1;
      uVar12 = extraout_r2;
      if (param_3 != 2) goto LAB_00041c16;
    }
    else {
      if (BLE_DEBUG == 0) {
        printk("%s(): ENTER NAVIGATION INIT status ....\n");
        uVar7 = extraout_r0_01;
        uVar11 = extraout_r1_02;
        uVar12 = extraout_r2_02;
      }
      else {
        ble_printk("%s(): ENTER NAVIGATION INIT status ....\n","ui_navigation_task",extraout_r2,
                   BLE_DEBUG);
        uVar7 = extraout_r0;
        uVar11 = extraout_r1_00;
        uVar12 = extraout_r2_00;
      }
      if (param_3 != 2) {
LAB_00041c16:
        if (param_3 == 0) {
          if (DAT_20004d76 == '\x01') {
            if (2 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): dynamic image reflash\n");
              }
              else {
                ble_printk("%s(): dynamic image reflash\n","ui_navigation_task",uVar12,BLE_DEBUG);
              }
            }
            iVar9 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            gui_bmp_dynamic_bitmap_draw(8,iVar9,uVar4 + 0x3a);
            goto LAB_00041c5a;
          }
          pGVar6 = __get_dashboard_state();
          uVar18 = CONCAT44(DAT_20004da4,DAT_20004da0);
          uVar7 = extraout_r2_10;
          if (*(char *)pGVar6 != '\x01') goto switchD_00041460_default;
LAB_000415ae:
          if (DAT_20004d76 != '\x01') goto LAB_000415b6;
LAB_00041c6e:
          if ((0 < DAT_20007f48) && (DAT_20007f48 = 0, DAT_20004d9d < 0x14)) {
            DAT_20004d9d = 0x13;
          }
          uVar18 = FUN_000808b4();
          uVar17 = FUN_000809b6((uint)uVar18,(int)((ulonglong)uVar18 >> 0x20),DAT_20004da0,
                                DAT_20004da4);
          uVar18 = CONCAT44(DAT_20004da4,DAT_20004da0);
          if ((int)((ulonglong)uVar17 >> 0x20) < (int)(uint)((uint)uVar17 < 0x3e9))
          goto switchD_00041460_default;
          uVar18 = FUN_000808b4();
          DAT_20004da4 = (int)((ulonglong)uVar18 >> 0x20);
          DAT_20004da0 = (uint)uVar18;
          DAT_20004d9d = DAT_20004d9d - 1;
          uVar7 = extraout_r2_34;
          if (2 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): DECETED TIMEOUT ...... _tpm_thread_prv_data.sync_cnt = %d\n");
              uVar18 = CONCAT44(DAT_20004da4,DAT_20004da0);
              uVar7 = extraout_r2_13;
            }
            else {
              ble_printk("%s(): DECETED TIMEOUT ...... _tpm_thread_prv_data.sync_cnt = %d\n",
                         "ui_navigation_task",(uint)DAT_20004d9d,BLE_DEBUG);
              uVar18 = CONCAT44(DAT_20004da4,DAT_20004da0);
              uVar7 = extraout_r2_35;
            }
          }
          DAT_20004da4 = (int)((ulonglong)uVar18 >> 0x20);
          DAT_20004da0 = (uint)uVar18;
          if (DAT_20004d9d != 0) goto switchD_00041460_default;
          if (1 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk(
                    "%s(): There is a disconnection between the AR Glasses and the Bluetooth application!\n"
                    );
              uVar18 = CONCAT44(DAT_20004da4,DAT_20004da0);
              uVar7 = extraout_r2_14;
            }
            else {
              ble_printk("%s(): There is a disconnection between the AR Glasses and the Bluetooth application!\n"
                         ,"ui_navigation_task",uVar7,BLE_DEBUG);
              uVar18 = CONCAT44(DAT_20004da4,DAT_20004da0);
              uVar7 = extraout_r2_36;
            }
          }
          DAT_20004da4 = (int)((ulonglong)uVar18 >> 0x20);
          DAT_20004da0 = (uint)uVar18;
          if (2 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): bluetooth connect is break,Send Stop Navigation command to slave.\n");
              uVar18 = CONCAT44(DAT_20004da4,DAT_20004da0);
            }
            else {
              ble_printk("%s(): bluetooth connect is break,Send Stop Navigation command to slave.\n"
                         ,"ui_navigation_task",uVar7,BLE_DEBUG);
              uVar18 = CONCAT44(DAT_20004da4,DAT_20004da0);
            }
          }
          DAT_20004da4 = (int)((ulonglong)uVar18 >> 0x20);
          DAT_20004da0 = (uint)uVar18;
          local_34 = CONCAT22(local_34._2_2_,0x106);
          pGVar6 = __get_dashboard_state();
          uVar13 = sync_to_slave((char *)pGVar6,6,&local_34,2);
          uVar7 = extraout_r2_37;
          goto joined_r0x00041874;
        }
        if (param_3 == 1) {
          pGVar8 = __get_dashboard_state();
          uVar7 = extraout_r1_04;
          if (*(char *)pGVar8 == '\x01') {
            pGVar8 = (GlassesState *)
                     send_response_data_to_ble(pGVar8,extraout_r1_04,extraout_r2_04,1);
            uVar7 = extraout_r1_05;
          }
          uVar18 = CONCAT44(uVar7,pGVar8);
          if (DAT_20004d76 == '\0') {
            pGVar8 = __get_dashboard_state();
            uVar18 = CONCAT44(extraout_r1_06,&pGVar8->field_0x1000);
            if (**(char **)&pGVar8->field_0x1004 == '\x01') {
              if (2 < LOG_LEVEL) {
                if (BLE_DEBUG == 0) {
                  printk("%s(): INIT STATUS  SYNC ACTION ENTER\n");
                }
                else {
                  ble_printk("%s(): INIT STATUS  SYNC ACTION ENTER\n","ui_navigation_task",
                             extraout_r2_05,BLE_DEBUG);
                }
              }
              FUN_000402f4();
              DAT_20004d76 = '\x01';
              uVar18 = FUN_000808b4();
              DAT_20004da4 = (int)((ulonglong)uVar18 >> 0x20);
              DAT_20004da0 = (uint)uVar18;
              DAT_20004d9d = 10;
              gui_screen_clear(DAT_20004da0,DAT_20004da4,extraout_r2_06);
              FUN_00045444();
              uVar18 = FUN_00080928();
            }
          }
          if (((DAT_20004d76 == '\x01') && (DAT_20010dc1 == '\x01')) &&
             (uVar13 = (uint)DAT_20010dc0, DAT_20010dc0 == 1)) {
            uVar7 = 0;
            DAT_2001c74d = 0;
            DAT_20004d70 = uVar13;
            if (2 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): switch NAVIGATION_RUNNING_STATUS .....\n");
                uVar18 = CONCAT44(extraout_r1_08,extraout_r0_04);
                uVar7 = extraout_r2_09;
              }
              else {
                ble_printk("%s(): switch NAVIGATION_RUNNING_STATUS .....\n","ui_navigation_task",0,
                           BLE_DEBUG);
                uVar18 = CONCAT44(extraout_r1_07,extraout_r0_03);
                uVar7 = extraout_r2_07;
              }
            }
            gui_screen_clear((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),uVar7);
            DAT_2001c74e = 0;
            DAT_20004d9d = 10;
            uVar18 = FUN_000808b4();
            DAT_20004da4 = (int)((ulonglong)uVar18 >> 0x20);
            DAT_20004da0 = (uint)uVar18;
            navigation_overview_map_display(pGVar6,(int)puVar15,extraout_r2_08);
          }
LAB_00041c5a:
          pGVar6 = __get_dashboard_state();
          uVar18 = CONCAT44(DAT_20004da4,DAT_20004da0);
          if ((*(char *)pGVar6 != '\x01') ||
             (uVar18 = CONCAT44(DAT_20004da4,DAT_20004da0), DAT_20004d76 != '\x01'))
          goto switchD_00041460_default;
          goto LAB_00041c6e;
        }
        pGVar6 = __get_dashboard_state();
        uVar7 = extraout_r2_12;
        if (*(char *)pGVar6 == '\x01') goto LAB_000415ae;
LAB_000415b6:
        uVar18 = CONCAT44(DAT_20004da4,DAT_20004da0);
joined_r0x00041a90:
        if (param_3 != 5) goto switchD_00041460_default;
        if (2 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): Received exit command from master, exit teleprompter mode\n");
          }
          else {
            ble_printk("%s(): Received exit command from master, exit teleprompter mode\n",
                       "ui_navigation_task",uVar7,BLE_DEBUG);
          }
        }
        goto LAB_000415d2;
      }
      if (2 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): running exit command..\n");
          uVar7 = extraout_r0_02;
          uVar11 = extraout_r1_03;
          uVar12 = extraout_r2_03;
        }
        else {
          ble_printk("%s(): running exit command..\n","ui_navigation_task",uVar12,BLE_DEBUG);
          uVar7 = extraout_r0_00;
          uVar11 = extraout_r1_01;
          uVar12 = extraout_r2_01;
        }
      }
    }
    gui_screen_clear(uVar7,uVar11,uVar12);
    goto LAB_000414a6;
  case 1:
    if (param_3 != 2) {
      if (param_3 == 1) {
        pGVar8 = __get_dashboard_state();
        uVar7 = extraout_r1_09;
        if (*(char *)pGVar8 == '\x01') {
          send_response_data_to_ble(pGVar8,extraout_r1_09,extraout_r2_15,1);
          pGVar8 = __get_dashboard_state();
          uVar7 = extraout_r1_10;
          if (*(char *)(*(int *)&pGVar8->field_0x1004 + 6) == '\x01') {
            if (DAT_20004d9d < 0x14) {
              DAT_20004d9d = 0x13;
            }
            pGVar8 = __get_dashboard_state();
            *(undefined1 *)(*(int *)&pGVar8->field_0x1004 + 6) = 0;
            uVar7 = extraout_r1_11;
          }
        }
        timeout.ticks._4_4_ = 0xffffffff;
        timeout.ticks._0_4_ = uVar7;
        z_impl_k_mutex_lock(&k_mutex_2000851c,timeout);
        DAT_20004d84 = pGVar6->field20_0xc8[0xd5];
        DAT_20004d98 = pGVar6->field20_0xc8[0x2e];
        iVar9 = z_impl_k_mutex_unlock(&k_mutex_2000851c);
        uVar7 = extraout_r1_12;
        if (2 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): arrived status = %d,  nav->imu_action_status = %d\n","ui_navigation_task",
                   (uint)DAT_20004d84);
            iVar9 = extraout_r0_07;
            uVar7 = extraout_r1_15;
          }
          else {
            ble_printk("%s(): arrived status = %d,  nav->imu_action_status = %d\n",
                       "ui_navigation_task",(uint)DAT_20004d84,
                       (uint)(byte)pGVar6->field20_0xc8[0x2e]);
            iVar9 = extraout_r0_05;
            uVar7 = extraout_r1_13;
          }
        }
        if (DAT_20004d84 == 2) {
          uVar11 = 2;
          if (2 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): received arrived complte command\n");
              iVar9 = extraout_r0_08;
              uVar7 = extraout_r1_16;
              uVar11 = extraout_r2_21;
            }
            else {
              ble_printk("%s(): received arrived complte command\n","ui_navigation_task",2,BLE_DEBUG
                        );
              iVar9 = extraout_r0_06;
              uVar7 = extraout_r1_14;
              uVar11 = extraout_r2_16;
            }
          }
          DAT_20004d70 = 3;
          gui_screen_clear(iVar9,uVar7,uVar11);
          bVar3 = get_current_language();
          if (bVar3 == 6) {
            iVar9 = 0xaa;
          }
          else {
            iVar9 = 0xc4;
          }
          iVar14 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          iVar10 = FUN_000809e2();
          uVar5 = FUN_00080a3a();
          gui_utf_draw(0,pGVar6->field20_0xc8 + 0xdc,0,iVar14 + iVar9,uVar4 + 0x3c,iVar10 + 0x23f,
                       uVar5 + 0x57,2,0,0,(undefined *)0x0,0);
          pGVar6 = __get_dashboard_state();
          cVar1 = pGVar6->dashboard_ts->field_0x5e;
          uVar13 = FUN_00080732();
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          iVar14 = FUN_000809e2();
          uVar5 = FUN_00080a3a();
          gui_clock_draw(uVar13,iVar9,uVar4 + 2,iVar14 + 0x4c,uVar5 + 0x1d,3,cVar1 != '\x01');
          uVar18 = FUN_000808b4();
          DAT_20004d88 = 5000;
          DAT_20004d8c = 0;
        }
        else {
          if (DAT_20004d84 == 1) {
            if (2 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): received arrived command,draw arrived page\n");
                iVar9 = extraout_r0_10;
                uVar7 = extraout_r1_18;
              }
              else {
                ble_printk("%s(): received arrived command,draw arrived page\n","ui_navigation_task"
                           ,1,BLE_DEBUG);
                iVar9 = extraout_r0_09;
                uVar7 = extraout_r1_17;
              }
            }
            uVar13 = (uint)DAT_20004d98;
            if (uVar13 != 2) {
              if (2 < LOG_LEVEL) {
                if (BLE_DEBUG == 0) {
                  printk("%s(): navigation arrived 1 rst reflash\n");
                  iVar9 = extraout_r0_12;
                  uVar7 = extraout_r1_20;
                  uVar13 = extraout_r2_24;
                }
                else {
                  ble_printk("%s(): navigation arrived 1 rst reflash\n","ui_navigation_task",uVar13,
                             BLE_DEBUG);
                  iVar9 = extraout_r0_11;
                  uVar7 = extraout_r1_19;
                  uVar13 = extraout_r2_23;
                }
              }
              if (DAT_20004d85 == '\0') {
                gui_screen_clear(iVar9,uVar7,uVar13);
                DAT_20004d85 = '\x01';
              }
              iVar9 = FUN_000809e2();
              uVar4 = FUN_00080a3a();
              iVar14 = FUN_000809e2();
              uVar5 = FUN_00080a3a();
              gui_bitmps_merge_draw
                        (iVar9 + 0x1b6,(uint)uVar4,iVar14 + 0x240,uVar5 + 0x88,0x2001c74f,
                         (int)&DAT_2001d057,2,0xf);
              bVar3 = get_current_language();
              if (bVar3 == 6) {
                iVar9 = 0xe8;
              }
              else {
                iVar9 = 0xc4;
              }
              iVar14 = FUN_000809e2();
              uVar4 = FUN_00080a3a();
              iVar10 = FUN_000809e2();
              uVar5 = FUN_00080a3a();
              gui_utf_draw(0,pGVar6->field20_0xc8 + 0xdc,0,iVar14 + iVar9,uVar4 + 0x3c,
                           iVar10 + 0x1e4,uVar5 + 0x57,2,0,0,(undefined *)0x0,0);
              DAT_20004d74 = 0;
              DAT_20004d75 = 1;
              sVar2 = DAT_20004d7e;
              uVar4 = DAT_20004d80;
              goto LAB_000419bc;
            }
            uVar7 = 2;
            if (2 < LOG_LEVEL) {
              fmt = 
              "%s(): navigation arrived 2 rst reflash, navigation_panoramic_map_display reflash\n";
LAB_000418be:
              if (BLE_DEBUG == 0) {
                printk(fmt);
                uVar7 = extraout_r2_25;
              }
              else {
                ble_printk(fmt,"ui_navigation_task",2,BLE_DEBUG);
                uVar7 = extraout_r2_22;
              }
            }
          }
          else {
            uVar13 = (uint)DAT_20004d98;
            if (uVar13 != 2) {
              if (2 < LOG_LEVEL) {
                if (BLE_DEBUG == 0) {
                  printk("%s(): navigation_overview_map_display reflash\n");
                  uVar13 = extraout_r2_27;
                }
                else {
                  ble_printk("%s(): navigation_overview_map_display reflash\n","ui_navigation_task",
                             uVar13,BLE_DEBUG);
                  uVar13 = extraout_r2_26;
                }
              }
              navigation_overview_map_display(pGVar6,(int)puVar15,uVar13);
              uVar18 = CONCAT44(DAT_20004d94,DAT_20004d90);
              goto LAB_000417bc;
            }
            uVar7 = 2;
            if (2 < LOG_LEVEL) {
              fmt = "%s(): navigation_panoramic_map_display reflash\n";
              goto LAB_000418be;
            }
          }
          navigation_panoramic_map_display(pGVar6,(int)puVar15,uVar7);
          uVar18 = CONCAT44(DAT_20004d94,DAT_20004d90);
        }
LAB_000417bc:
        DAT_20004d94 = (int)((ulonglong)uVar18 >> 0x20);
        DAT_20004d90 = (uint)uVar18;
        pGVar6 = __get_dashboard_state();
        uVar18 = CONCAT44(DAT_20004da4,DAT_20004da0);
        if (*(char *)pGVar6 != '\x01') goto switchD_00041460_default;
      }
      else {
        if (param_3 == 0) {
          local_34 = param_3;
          uStack_30 = param_3;
          local_2c = param_3;
          dashboard_ts_ctx = (dashboard_ts_context *)FUN_00080732();
          __init_burial_point_date(dashboard_ts_ctx,(undefined2 *)&local_34);
          uVar18 = CONCAT44(DAT_20004d94,DAT_20004d90);
          sVar2 = uStack_30._2_2_;
          uVar4 = (ushort)local_2c;
          if (((uint)DAT_20004d80 != (local_2c & 0xffff)) || (uStack_30._2_2_ != DAT_20004d7e)) {
LAB_000419bc:
            DAT_20004d80 = uVar4;
            DAT_20004d7e = sVar2;
            pGVar6 = __get_dashboard_state();
            cVar1 = pGVar6->dashboard_ts->field_0x5e;
            uVar13 = FUN_00080732();
            iVar9 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            iVar14 = FUN_000809e2();
            uVar5 = FUN_00080a3a();
            gui_clock_draw(uVar13,iVar9,uVar4 + 2,iVar14 + 0x4c,uVar5 + 0x1d,3,cVar1 != '\x01');
            uVar18 = CONCAT44(DAT_20004d94,DAT_20004d90);
          }
          goto LAB_000417bc;
        }
        pGVar6 = __get_dashboard_state();
        uVar18 = CONCAT44(DAT_20004da4,DAT_20004da0);
        uVar7 = extraout_r2_28;
        if (*(char *)pGVar6 != '\x01') goto joined_r0x00041a90;
      }
      if ((0 < DAT_20007f48) && (DAT_20007f48 = 0, DAT_20004d9d < 0x14)) {
        DAT_20004d9d = 0x13;
      }
      uVar18 = FUN_000808b4();
      uVar17 = FUN_000809b6((uint)uVar18,(int)((ulonglong)uVar18 >> 0x20),DAT_20004da0,DAT_20004da4)
      ;
      uVar18 = CONCAT44(DAT_20004da4,DAT_20004da0);
      if ((int)((ulonglong)uVar17 >> 0x20) < (int)(uint)((uint)uVar17 < 0x3e9))
      goto switchD_00041460_default;
      uVar18 = FUN_000808b4();
      DAT_20004da4 = (int)((ulonglong)uVar18 >> 0x20);
      DAT_20004da0 = (uint)uVar18;
      DAT_20004d9d = DAT_20004d9d - 1;
      uVar7 = extraout_r2_17;
      if (2 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): DECETED TIMEOUT ...... _tpm_thread_prv_data.sync_cnt = %d\n");
          uVar18 = CONCAT44(DAT_20004da4,DAT_20004da0);
          uVar7 = extraout_r2_29;
        }
        else {
          ble_printk("%s(): DECETED TIMEOUT ...... _tpm_thread_prv_data.sync_cnt = %d\n",
                     "ui_navigation_task",(uint)DAT_20004d9d,BLE_DEBUG);
          uVar18 = CONCAT44(DAT_20004da4,DAT_20004da0);
          uVar7 = extraout_r2_18;
        }
      }
      DAT_20004da4 = (int)((ulonglong)uVar18 >> 0x20);
      DAT_20004da0 = (uint)uVar18;
      if (DAT_20004d9d != 0) goto switchD_00041460_default;
      if (1 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk(
                "%s(): There is a disconnection between the AR Glasses and the Bluetooth application!\n"
                );
          uVar18 = CONCAT44(DAT_20004da4,DAT_20004da0);
          uVar7 = extraout_r2_30;
        }
        else {
          ble_printk("%s(): There is a disconnection between the AR Glasses and the Bluetooth application!\n"
                     ,"ui_navigation_task",uVar7,BLE_DEBUG);
          uVar18 = CONCAT44(DAT_20004da4,DAT_20004da0);
          uVar7 = extraout_r2_19;
        }
      }
      DAT_20004da4 = (int)((ulonglong)uVar18 >> 0x20);
      DAT_20004da0 = (uint)uVar18;
      if (2 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): bluetooth connect is break,Send Stop Navigation command to slave.\n");
          uVar18 = CONCAT44(DAT_20004da4,DAT_20004da0);
        }
        else {
          ble_printk("%s(): bluetooth connect is break,Send Stop Navigation command to slave.\n",
                     "ui_navigation_task",uVar7,BLE_DEBUG);
          uVar18 = CONCAT44(DAT_20004da4,DAT_20004da0);
        }
      }
      DAT_20004da4 = (int)((ulonglong)uVar18 >> 0x20);
      DAT_20004da0 = (uint)uVar18;
      local_34 = CONCAT22(local_34._2_2_,0x106);
      pGVar6 = __get_dashboard_state();
      uVar13 = sync_to_slave((char *)pGVar6,6,&local_34,2);
      uVar7 = extraout_r2_20;
joined_r0x00041874:
      if (4999 < (int)uVar13) {
        uVar18 = CONCAT44(DAT_20004da4,DAT_20004da0);
        if (0 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk(
                  "%s(): SYNC TO Slave failed...,don\'t exec Navigation exit action,master auto exit...\n"
                  );
            uVar18 = CONCAT44(DAT_20004da4,DAT_20004da0);
          }
          else {
            ble_printk("%s(): SYNC TO Slave failed...,don\'t exec Navigation exit action,master auto exit...\n"
                       ,"ui_navigation_task",uVar7,BLE_DEBUG);
            uVar18 = CONCAT44(DAT_20004da4,DAT_20004da0);
          }
        }
        goto switchD_00041460_default;
      }
LAB_000415d2:
      DAT_20004d70 = 2;
      uVar18 = FUN_000808b4();
      DAT_20004da4 = (int)((ulonglong)uVar18 >> 0x20);
      DAT_20004da0 = (uint)uVar18;
      gui_screen_clear(DAT_20004da0,DAT_20004da4,extraout_r2_11);
      iVar9 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      gui_bmp_bitmap_draw(0x3f,iVar9,uVar4 + 0x3a,0,0,0);
      FUN_000808dc();
      uVar18 = CONCAT44(DAT_20004da4,DAT_20004da0);
      goto switchD_00041460_default;
    }
    break;
  case 2:
    if (1 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): running navigation DISPLAY ABNORMAL EXIT STATUS.\n");
      }
      else {
        ble_printk("%s(): running navigation DISPLAY ABNORMAL EXIT STATUS.\n","ui_navigation_task",
                   extraout_r2,BLE_DEBUG);
      }
    }
    uVar18 = FUN_000808b4();
    uVar18 = FUN_000809b6((uint)uVar18,(int)((ulonglong)uVar18 >> 0x20),DAT_20004da0,DAT_20004da4);
    uVar7 = extraout_r2_31;
    if ((int)(uint)((uint)uVar18 < 0x1f41) <= (int)((ulonglong)uVar18 >> 0x20)) {
      if (1 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): The navigation automatically shuts down due to disconnection.\n");
        }
        else {
          ble_printk("%s(): The navigation automatically shuts down due to disconnection.\n",
                     "ui_navigation_task",extraout_r2_31,BLE_DEBUG);
        }
      }
      FUN_00045968();
      memset(&DAT_20004d70,0,0x38);
      memset(&DAT_2001c74f,0,0x1210);
      DAT_2001c74e = 0;
      pGVar6 = __get_dashboard_state();
      **(undefined1 **)&pGVar6->field_0x1004 = 0;
      uVar7 = extraout_r2_32;
    }
    uVar18 = CONCAT44(DAT_20004da4,DAT_20004da0);
    if (param_3 != 2) goto switchD_00041460_default;
    if (2 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): received exit command,clear screen...\n");
      }
      else {
        ble_printk("%s(): received exit command,clear screen...\n","ui_navigation_task",uVar7,
                   BLE_DEBUG);
      }
    }
    break;
  case 3:
    if (param_3 != 2) {
      if ((param_3 == 1) && (pGVar6 = __get_dashboard_state(), *(char *)pGVar6 == '\x01')) {
        send_response_data_to_ble(pGVar6,extraout_r1_21,extraout_r2_33,1);
      }
      uVar18 = FUN_000808b4();
      iVar9 = (int)((ulonglong)uVar18 >> 0x20);
      uVar13 = DAT_20004d88 + DAT_20004d90;
      iVar14 = DAT_20004d8c + DAT_20004d94 + (uint)CARRY4(DAT_20004d88,DAT_20004d90);
      bVar16 = uVar13 < (uint)uVar18;
      uVar18 = CONCAT44(DAT_20004da4,DAT_20004da0);
      if ((int)((iVar14 - iVar9) - (uint)bVar16) < 0 !=
          (SBORROW4(iVar14,iVar9) != SBORROW4(iVar14 - iVar9,(uint)bVar16))) {
        if (2 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): exec navigation auto exit ...\n");
          }
          else {
            ble_printk("%s(): exec navigation auto exit ...\n","ui_navigation_task",uVar13,BLE_DEBUG
                      );
          }
        }
        pGVar6 = __get_dashboard_state();
        **(undefined1 **)&pGVar6->field_0x1004 = 0;
        FUN_00045968();
        memset(&DAT_20004d70,0,0x38);
        uVar18 = CONCAT44(DAT_20004da4,DAT_20004da0);
      }
      goto switchD_00041460_default;
    }
    break;
  default:
    goto switchD_00041460_default;
  }
  FUN_00045968();
LAB_000414a6:
  memset(&DAT_20004d70,0,0x38);
  memset(&DAT_2001c74f,0,0x1210);
  DAT_2001c74e = 0;
  uVar18 = CONCAT44(DAT_20004da4,DAT_20004da0);
switchD_00041460_default:
  DAT_20004da4 = (int)((ulonglong)uVar18 >> 0x20);
  DAT_20004da0 = (uint)uVar18;
  return 0;
}


