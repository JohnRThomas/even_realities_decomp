/*
 * Function: ui_navigation_task
 * Entry:    00041438
 * Prototype: undefined4 __stdcall ui_navigation_task(int param_1, undefined4 param_2, uint param_3)
 */


undefined4 ui_navigation_task(int param_1,undefined4 param_2,uint param_3)

{
  short sVar1;
  byte bVar2;
  ushort uVar3;
  ushort uVar4;
  GlassesState *pGVar5;
  GlassesState *pGVar6;
  int iVar7;
  dashboard_ts_context *pdVar8;
  uint uVar9;
  char *fmt;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  undefined4 extraout_r1_02;
  undefined4 uVar10;
  undefined4 extraout_r1_03;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  int iVar11;
  undefined *puVar12;
  int iVar13;
  bool bVar14;
  k_timeout_t timeout;
  undefined8 uVar15;
  undefined8 uVar16;
  uint local_34;
  undefined4 uStack_30;
  uint local_2c;
  
  pGVar5 = __get_dashboard_state();
  puVar12 = pGVar5->field20_0xc8 + 0x27;
  __set_frame_buffer(param_1 + 0x24);
  __set_showing_notification_on_gui();
  uVar16 = CONCAT44(DAT_20004da4,DAT_20004da0);
  switch(DAT_20004d70) {
  case 0:
    if (LOG_LEVEL < 3) {
      if (param_3 != 2) goto LAB_00041c16;
    }
    else {
      if (BLE_DEBUG == 0) {
        printk("%s(): ENTER NAVIGATION INIT status ....\n","ui_navigation_task");
      }
      else {
        ble_printk("%s(): ENTER NAVIGATION INIT status ....\n");
      }
      if (param_3 != 2) {
LAB_00041c16:
        if (param_3 == 0) {
          if (DAT_20004d76 == '\x01') {
            if (2 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): dynamic image reflash\n","ui_navigation_task");
              }
              else {
                ble_printk("%s(): dynamic image reflash\n");
              }
            }
            iVar13 = FUN_000809e2();
            uVar3 = FUN_00080a3a();
            gui_bmp_dynamic_bitmap_draw(8,iVar13,uVar3 + 0x3a);
            goto LAB_00041c5a;
          }
          pGVar5 = __get_dashboard_state();
          uVar16 = CONCAT44(DAT_20004da4,DAT_20004da0);
          if (pGVar5->is_master != true) goto switchD_00041460_default;
LAB_000415ae:
          if (DAT_20004d76 != '\x01') goto LAB_000415b6;
LAB_00041c6e:
          if ((0 < DAT_20007f48) && (DAT_20007f48 = 0, DAT_20004d9d < 0x14)) {
            DAT_20004d9d = 0x13;
          }
          uVar16 = FUN_000808b4();
          uVar15 = FUN_000809b6((uint)uVar16,(int)((ulonglong)uVar16 >> 0x20),DAT_20004da0,
                                DAT_20004da4);
          uVar16 = CONCAT44(DAT_20004da4,DAT_20004da0);
          if ((int)((ulonglong)uVar15 >> 0x20) < (int)(uint)((uint)uVar15 < 0x3e9))
          goto switchD_00041460_default;
          uVar16 = FUN_000808b4();
          DAT_20004da4 = (int)((ulonglong)uVar16 >> 0x20);
          DAT_20004da0 = (uint)uVar16;
          DAT_20004d9d = DAT_20004d9d - 1;
          if (2 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): DECETED TIMEOUT ...... _tpm_thread_prv_data.sync_cnt = %d\n",
                     "ui_navigation_task",(uint)DAT_20004d9d);
              uVar16 = CONCAT44(DAT_20004da4,DAT_20004da0);
            }
            else {
              ble_printk("%s(): DECETED TIMEOUT ...... _tpm_thread_prv_data.sync_cnt = %d\n");
              uVar16 = CONCAT44(DAT_20004da4,DAT_20004da0);
            }
          }
          DAT_20004da4 = (int)((ulonglong)uVar16 >> 0x20);
          DAT_20004da0 = (uint)uVar16;
          if (DAT_20004d9d != 0) goto switchD_00041460_default;
          if (1 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): There is a disconnection between the AR Glasses and the Bluetooth application!\n"
                     ,"ui_navigation_task");
              uVar16 = CONCAT44(DAT_20004da4,DAT_20004da0);
            }
            else {
              ble_printk(
                        "%s(): There is a disconnection between the AR Glasses and the Bluetooth application!\n"
                        );
              uVar16 = CONCAT44(DAT_20004da4,DAT_20004da0);
            }
          }
          DAT_20004da4 = (int)((ulonglong)uVar16 >> 0x20);
          DAT_20004da0 = (uint)uVar16;
          if (2 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): bluetooth connect is break,Send Stop Navigation command to slave.\n",
                     "ui_navigation_task");
              uVar16 = CONCAT44(DAT_20004da4,DAT_20004da0);
            }
            else {
              ble_printk("%s(): bluetooth connect is break,Send Stop Navigation command to slave.\n"
                        );
              uVar16 = CONCAT44(DAT_20004da4,DAT_20004da0);
            }
          }
          DAT_20004da4 = (int)((ulonglong)uVar16 >> 0x20);
          DAT_20004da0 = (uint)uVar16;
          local_34 = CONCAT22(local_34._2_2_,0x106);
          pGVar5 = __get_dashboard_state();
          uVar9 = sync_to_slave(&pGVar5->is_master,6,&local_34,2);
          goto joined_r0x00041874;
        }
        if (param_3 == 1) {
          pGVar6 = __get_dashboard_state();
          if (pGVar6->is_master == true) {
            send_response_data_to_ble(pGVar6,extraout_r1,extraout_r2,1);
          }
          if ((DAT_20004d76 == '\0') &&
             (pGVar6 = __get_dashboard_state(), **(char **)&pGVar6->field_0x1004 == '\x01')) {
            if (2 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): INIT STATUS  SYNC ACTION ENTER\n","ui_navigation_task");
              }
              else {
                ble_printk("%s(): INIT STATUS  SYNC ACTION ENTER\n");
              }
            }
            FUN_000402f4();
            DAT_20004d76 = '\x01';
            uVar16 = FUN_000808b4();
            DAT_20004da4 = (int)((ulonglong)uVar16 >> 0x20);
            DAT_20004da0 = (uint)uVar16;
            DAT_20004d9d = 10;
            gui_screen_clear();
            FUN_00045444();
            FUN_00080928();
          }
          if (((DAT_20004d76 == '\x01') && (DAT_20010dc1 == '\x01')) &&
             (uVar9 = (uint)DAT_20010dc0, DAT_20010dc0 == 1)) {
            DAT_2001c74d = 0;
            DAT_20004d70 = uVar9;
            if (2 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): switch NAVIGATION_RUNNING_STATUS .....\n","ui_navigation_task");
              }
              else {
                ble_printk("%s(): switch NAVIGATION_RUNNING_STATUS .....\n");
              }
            }
            gui_screen_clear();
            DAT_2001c74e = 0;
            DAT_20004d9d = 10;
            uVar16 = FUN_000808b4();
            DAT_20004da4 = (int)((ulonglong)uVar16 >> 0x20);
            DAT_20004da0 = (uint)uVar16;
            navigation_overview_map_display(pGVar5,(int)puVar12);
          }
LAB_00041c5a:
          pGVar5 = __get_dashboard_state();
          uVar16 = CONCAT44(DAT_20004da4,DAT_20004da0);
          if ((pGVar5->is_master != true) ||
             (uVar16 = CONCAT44(DAT_20004da4,DAT_20004da0), DAT_20004d76 != '\x01'))
          goto switchD_00041460_default;
          goto LAB_00041c6e;
        }
        pGVar5 = __get_dashboard_state();
        if (pGVar5->is_master == true) goto LAB_000415ae;
LAB_000415b6:
        uVar16 = CONCAT44(DAT_20004da4,DAT_20004da0);
joined_r0x00041a90:
        if (param_3 != 5) goto switchD_00041460_default;
        if (2 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): Received exit command from master, exit teleprompter mode\n",
                   "ui_navigation_task");
          }
          else {
            ble_printk("%s(): Received exit command from master, exit teleprompter mode\n");
          }
        }
        goto LAB_000415d2;
      }
      if (2 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): running exit command..\n","ui_navigation_task");
        }
        else {
          ble_printk("%s(): running exit command..\n");
        }
      }
    }
    gui_screen_clear();
    goto LAB_000414a6;
  case 1:
    if (param_3 != 2) {
      if (param_3 == 1) {
        pGVar6 = __get_dashboard_state();
        uVar10 = extraout_r1_00;
        if (pGVar6->is_master == true) {
          send_response_data_to_ble(pGVar6,extraout_r1_00,extraout_r2_00,1);
          pGVar6 = __get_dashboard_state();
          uVar10 = extraout_r1_01;
          if (*(char *)(*(int *)&pGVar6->field_0x1004 + 6) == '\x01') {
            if (DAT_20004d9d < 0x14) {
              DAT_20004d9d = 0x13;
            }
            pGVar6 = __get_dashboard_state();
            *(undefined1 *)(*(int *)&pGVar6->field_0x1004 + 6) = 0;
            uVar10 = extraout_r1_02;
          }
        }
        timeout.ticks._4_4_ = 0xffffffff;
        timeout.ticks._0_4_ = uVar10;
        z_impl_k_mutex_lock(&k_mutex_2000851c,timeout);
        DAT_20004d84 = pGVar5->field20_0xc8[0xd5];
        DAT_20004d98 = pGVar5->field20_0xc8[0x2e];
        z_impl_k_mutex_unlock(&k_mutex_2000851c);
        if (2 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): arrived status = %d,  nav->imu_action_status = %d\n","ui_navigation_task",
                   (uint)DAT_20004d84,(uint)(byte)pGVar5->field20_0xc8[0x2e]);
          }
          else {
            ble_printk("%s(): arrived status = %d,  nav->imu_action_status = %d\n",
                       "ui_navigation_task",(uint)DAT_20004d84);
          }
        }
        if (DAT_20004d84 == 2) {
          if (2 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): received arrived complte command\n","ui_navigation_task");
            }
            else {
              ble_printk("%s(): received arrived complte command\n");
            }
          }
          DAT_20004d70 = 3;
          gui_screen_clear();
          bVar2 = get_current_language();
          if (bVar2 == 6) {
            iVar13 = 0xaa;
          }
          else {
            iVar13 = 0xc4;
          }
          iVar11 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          iVar7 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          gui_utf_draw(0,pGVar5->field20_0xc8 + 0xdc,0,iVar11 + iVar13,uVar3 + 0x3c,iVar7 + 0x23f,
                       uVar4 + 0x57,2,0,0,(undefined *)0x0,0);
          pGVar5 = __get_dashboard_state();
          iVar13 = pGVar5->dashboard_ts->time_disp_mode;
          pdVar8 = (dashboard_ts_context *)FUN_00080732();
          iVar11 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          iVar7 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          gui_clock_draw(pdVar8,iVar11,uVar3 + 2,iVar7 + 0x4c,uVar4 + 0x1d,3,(char)iVar13 != '\x01')
          ;
          uVar16 = FUN_000808b4();
          DAT_20004d88 = 5000;
          DAT_20004d8c = 0;
        }
        else {
          if (DAT_20004d84 == 1) {
            if (2 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): received arrived command,draw arrived page\n","ui_navigation_task");
              }
              else {
                ble_printk("%s(): received arrived command,draw arrived page\n");
              }
            }
            if (DAT_20004d98 != '\x02') {
              if (2 < LOG_LEVEL) {
                if (BLE_DEBUG == 0) {
                  printk("%s(): navigation arrived 1 rst reflash\n","ui_navigation_task");
                }
                else {
                  ble_printk("%s(): navigation arrived 1 rst reflash\n");
                }
              }
              if (DAT_20004d85 == '\0') {
                gui_screen_clear();
                DAT_20004d85 = '\x01';
              }
              iVar13 = FUN_000809e2();
              uVar3 = FUN_00080a3a();
              iVar11 = FUN_000809e2();
              uVar4 = FUN_00080a3a();
              gui_bitmps_merge_draw
                        (iVar13 + 0x1b6,(uint)uVar3,iVar11 + 0x240,uVar4 + 0x88,0x2001c74f,
                         (int)&DAT_2001d057,2,0xf);
              bVar2 = get_current_language();
              if (bVar2 == 6) {
                iVar13 = 0xe8;
              }
              else {
                iVar13 = 0xc4;
              }
              iVar11 = FUN_000809e2();
              uVar3 = FUN_00080a3a();
              iVar7 = FUN_000809e2();
              uVar4 = FUN_00080a3a();
              gui_utf_draw(0,pGVar5->field20_0xc8 + 0xdc,0,iVar11 + iVar13,uVar3 + 0x3c,
                           iVar7 + 0x1e4,uVar4 + 0x57,2,0,0,(undefined *)0x0,0);
              DAT_20004d74 = 0;
              DAT_20004d75 = 1;
              sVar1 = DAT_20004d7e;
              uVar3 = DAT_20004d80;
              goto LAB_000419bc;
            }
            if (2 < LOG_LEVEL) {
              fmt = 
              "%s(): navigation arrived 2 rst reflash, navigation_panoramic_map_display reflash\n";
LAB_000418be:
              if (BLE_DEBUG == 0) {
                printk(fmt,"ui_navigation_task");
              }
              else {
                ble_printk(fmt);
              }
            }
          }
          else {
            if (DAT_20004d98 != '\x02') {
              if (2 < LOG_LEVEL) {
                if (BLE_DEBUG == 0) {
                  printk("%s(): navigation_overview_map_display reflash\n","ui_navigation_task");
                }
                else {
                  ble_printk("%s(): navigation_overview_map_display reflash\n");
                }
              }
              navigation_overview_map_display(pGVar5,(int)puVar12);
              uVar16 = CONCAT44(DAT_20004d94,DAT_20004d90);
              goto LAB_000417bc;
            }
            if (2 < LOG_LEVEL) {
              fmt = "%s(): navigation_panoramic_map_display reflash\n";
              goto LAB_000418be;
            }
          }
          navigation_panoramic_map_display(pGVar5,(int)puVar12);
          uVar16 = CONCAT44(DAT_20004d94,DAT_20004d90);
        }
LAB_000417bc:
        DAT_20004d94 = (int)((ulonglong)uVar16 >> 0x20);
        DAT_20004d90 = (uint)uVar16;
        pGVar5 = __get_dashboard_state();
        uVar16 = CONCAT44(DAT_20004da4,DAT_20004da0);
        if (pGVar5->is_master != true) goto switchD_00041460_default;
      }
      else {
        if (param_3 == 0) {
          local_34 = param_3;
          uStack_30 = param_3;
          local_2c = param_3;
          pdVar8 = (dashboard_ts_context *)FUN_00080732();
          __init_burial_point_date(pdVar8,(undefined2 *)&local_34);
          uVar16 = CONCAT44(DAT_20004d94,DAT_20004d90);
          sVar1 = uStack_30._2_2_;
          uVar3 = (ushort)local_2c;
          if (((uint)DAT_20004d80 != (local_2c & 0xffff)) || (uStack_30._2_2_ != DAT_20004d7e)) {
LAB_000419bc:
            DAT_20004d80 = uVar3;
            DAT_20004d7e = sVar1;
            pGVar5 = __get_dashboard_state();
            iVar13 = pGVar5->dashboard_ts->time_disp_mode;
            pdVar8 = (dashboard_ts_context *)FUN_00080732();
            iVar11 = FUN_000809e2();
            uVar3 = FUN_00080a3a();
            iVar7 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            gui_clock_draw(pdVar8,iVar11,uVar3 + 2,iVar7 + 0x4c,uVar4 + 0x1d,3,
                           (char)iVar13 != '\x01');
            uVar16 = CONCAT44(DAT_20004d94,DAT_20004d90);
          }
          goto LAB_000417bc;
        }
        pGVar5 = __get_dashboard_state();
        uVar16 = CONCAT44(DAT_20004da4,DAT_20004da0);
        if (pGVar5->is_master != true) goto joined_r0x00041a90;
      }
      if ((0 < DAT_20007f48) && (DAT_20007f48 = 0, DAT_20004d9d < 0x14)) {
        DAT_20004d9d = 0x13;
      }
      uVar16 = FUN_000808b4();
      uVar15 = FUN_000809b6((uint)uVar16,(int)((ulonglong)uVar16 >> 0x20),DAT_20004da0,DAT_20004da4)
      ;
      uVar16 = CONCAT44(DAT_20004da4,DAT_20004da0);
      if ((int)((ulonglong)uVar15 >> 0x20) < (int)(uint)((uint)uVar15 < 0x3e9))
      goto switchD_00041460_default;
      uVar16 = FUN_000808b4();
      DAT_20004da4 = (int)((ulonglong)uVar16 >> 0x20);
      DAT_20004da0 = (uint)uVar16;
      DAT_20004d9d = DAT_20004d9d - 1;
      if (2 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): DECETED TIMEOUT ...... _tpm_thread_prv_data.sync_cnt = %d\n",
                 "ui_navigation_task",(uint)DAT_20004d9d);
          uVar16 = CONCAT44(DAT_20004da4,DAT_20004da0);
        }
        else {
          ble_printk("%s(): DECETED TIMEOUT ...... _tpm_thread_prv_data.sync_cnt = %d\n");
          uVar16 = CONCAT44(DAT_20004da4,DAT_20004da0);
        }
      }
      DAT_20004da4 = (int)((ulonglong)uVar16 >> 0x20);
      DAT_20004da0 = (uint)uVar16;
      if (DAT_20004d9d != 0) goto switchD_00041460_default;
      if (1 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): There is a disconnection between the AR Glasses and the Bluetooth application!\n"
                 ,"ui_navigation_task");
          uVar16 = CONCAT44(DAT_20004da4,DAT_20004da0);
        }
        else {
          ble_printk(
                    "%s(): There is a disconnection between the AR Glasses and the Bluetooth application!\n"
                    );
          uVar16 = CONCAT44(DAT_20004da4,DAT_20004da0);
        }
      }
      DAT_20004da4 = (int)((ulonglong)uVar16 >> 0x20);
      DAT_20004da0 = (uint)uVar16;
      if (2 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): bluetooth connect is break,Send Stop Navigation command to slave.\n",
                 "ui_navigation_task");
          uVar16 = CONCAT44(DAT_20004da4,DAT_20004da0);
        }
        else {
          ble_printk("%s(): bluetooth connect is break,Send Stop Navigation command to slave.\n");
          uVar16 = CONCAT44(DAT_20004da4,DAT_20004da0);
        }
      }
      DAT_20004da4 = (int)((ulonglong)uVar16 >> 0x20);
      DAT_20004da0 = (uint)uVar16;
      local_34 = CONCAT22(local_34._2_2_,0x106);
      pGVar5 = __get_dashboard_state();
      uVar9 = sync_to_slave(&pGVar5->is_master,6,&local_34,2);
joined_r0x00041874:
      if (4999 < (int)uVar9) {
        uVar16 = CONCAT44(DAT_20004da4,DAT_20004da0);
        if (0 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): SYNC TO Slave failed...,don\'t exec Navigation exit action,master auto exit...\n"
                   ,"ui_navigation_task");
            uVar16 = CONCAT44(DAT_20004da4,DAT_20004da0);
          }
          else {
            ble_printk(
                      "%s(): SYNC TO Slave failed...,don\'t exec Navigation exit action,master auto exit...\n"
                      );
            uVar16 = CONCAT44(DAT_20004da4,DAT_20004da0);
          }
        }
        goto switchD_00041460_default;
      }
LAB_000415d2:
      DAT_20004d70 = 2;
      uVar16 = FUN_000808b4();
      DAT_20004da4 = (int)((ulonglong)uVar16 >> 0x20);
      DAT_20004da0 = (uint)uVar16;
      gui_screen_clear();
      iVar13 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      gui_bmp_bitmap_draw(0x3f,iVar13,uVar3 + 0x3a,0,0,0);
      FUN_000808dc();
      uVar16 = CONCAT44(DAT_20004da4,DAT_20004da0);
      goto switchD_00041460_default;
    }
    break;
  case 2:
    if (1 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): running navigation DISPLAY ABNORMAL EXIT STATUS.\n","ui_navigation_task");
      }
      else {
        ble_printk("%s(): running navigation DISPLAY ABNORMAL EXIT STATUS.\n");
      }
    }
    uVar16 = FUN_000808b4();
    uVar16 = FUN_000809b6((uint)uVar16,(int)((ulonglong)uVar16 >> 0x20),DAT_20004da0,DAT_20004da4);
    if ((int)(uint)((uint)uVar16 < 0x1f41) <= (int)((ulonglong)uVar16 >> 0x20)) {
      if (1 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): The navigation automatically shuts down due to disconnection.\n",
                 "ui_navigation_task");
        }
        else {
          ble_printk("%s(): The navigation automatically shuts down due to disconnection.\n");
        }
      }
      FUN_00045968();
      memset(&DAT_20004d70,0,0x38);
      memset(&DAT_2001c74f,0,0x1210);
      DAT_2001c74e = 0;
      pGVar5 = __get_dashboard_state();
      **(undefined1 **)&pGVar5->field_0x1004 = 0;
    }
    uVar16 = CONCAT44(DAT_20004da4,DAT_20004da0);
    if (param_3 != 2) goto switchD_00041460_default;
    if (2 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): received exit command,clear screen...\n","ui_navigation_task");
      }
      else {
        ble_printk("%s(): received exit command,clear screen...\n");
      }
    }
    break;
  case 3:
    if (param_3 != 2) {
      if ((param_3 == 1) && (pGVar5 = __get_dashboard_state(), pGVar5->is_master == true)) {
        send_response_data_to_ble(pGVar5,extraout_r1_03,extraout_r2_01,1);
      }
      uVar16 = FUN_000808b4();
      iVar13 = (int)((ulonglong)uVar16 >> 0x20);
      iVar11 = DAT_20004d8c + DAT_20004d94 + (uint)CARRY4(DAT_20004d88,DAT_20004d90);
      bVar14 = DAT_20004d88 + DAT_20004d90 < (uint)uVar16;
      uVar16 = CONCAT44(DAT_20004da4,DAT_20004da0);
      if ((int)((iVar11 - iVar13) - (uint)bVar14) < 0 !=
          (SBORROW4(iVar11,iVar13) != SBORROW4(iVar11 - iVar13,(uint)bVar14))) {
        if (2 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): exec navigation auto exit ...\n","ui_navigation_task");
          }
          else {
            ble_printk("%s(): exec navigation auto exit ...\n");
          }
        }
        pGVar5 = __get_dashboard_state();
        **(undefined1 **)&pGVar5->field_0x1004 = 0;
        FUN_00045968();
        memset(&DAT_20004d70,0,0x38);
        uVar16 = CONCAT44(DAT_20004da4,DAT_20004da0);
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
  uVar16 = CONCAT44(DAT_20004da4,DAT_20004da0);
switchD_00041460_default:
  DAT_20004da4 = (int)((ulonglong)uVar16 >> 0x20);
  DAT_20004da0 = (uint)uVar16;
  return 0;
}


