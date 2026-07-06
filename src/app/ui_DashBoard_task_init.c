/*
 * Function: ?_ui_DashBoard_task_init
 * Entry:    0003ce6c
 * Prototype: undefined4 __stdcall ?_ui_DashBoard_task_init(int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 */


/* WARNING: Removing unreachable block (ram,0x0003d104) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
__ui_DashBoard_task_init(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  longlong lVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  char cVar6;
  bool bVar7;
  GlassesState *pGVar8;
  int iVar9;
  char *fmt;
  undefined4 uVar10;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  uint uVar11;
  undefined4 extraout_r1_01;
  undefined4 extraout_r1_02;
  undefined4 extraout_r1_03;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 uVar12;
  uint uVar13;
  undefined4 extraout_r2_01;
  undefined4 extraout_r2_02;
  undefined4 extraout_r2_03;
  uint uVar14;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined1 *unaff_r4;
  int unaff_r5;
  int *unaff_r6;
  int unaff_r7;
  int unaff_r8;
  int unaff_r9;
  uint32_t uVar15;
  int iVar16;
  uint uVar17;
  ulonglong uVar18;
  undefined4 local_228;
  undefined4 local_224;
  int iStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  
  *(short *)(param_1 + 0x24) = (short)param_1;
  iStack_18 = param_1;
  uStack_14 = param_3;
  uStack_10 = param_4;
  if (((unaff_r9 != 1) ||
      (pGVar8 = __get_dashboard_state(), pGVar8->dashboard_ts->field_0x73 != '\x01')) ||
     (*(char *)(unaff_r5 + 0x162) != '\x01')) goto LAB_0003d09a;
  if (unaff_r4[0xc] == '\0') {
    uVar10 = extraout_r1;
    uVar12 = extraout_r2;
    if (2 < *unaff_r6) {
      if (BLE_DEBUG == 0) {
        printk("%s(): DASHBOARD INIT .......\n","ui_DashBoard_task");
        uVar10 = extraout_r1_03;
        uVar12 = extraout_r2_03;
      }
      else {
        ble_printk("%s(): DASHBOARD INIT .......\n");
        uVar10 = extraout_r1_00;
        uVar12 = extraout_r2_00;
      }
    }
    FUN_00029774(0x1e,uVar10,uVar12);
    memset(&DAT_20004af8,0,0x28);
    gui_screen_clear();
    bVar1 = DAT_2001c4e3;
    uVar17 = (uint)DAT_2001c4e3;
    unaff_r4[0xc] = 1;
    bVar5 = DAT_2001c4e6;
    uVar13 = (uint)DAT_2001c4e6;
    unaff_r4[0x20] = *(undefined1 *)(unaff_r5 + 0x156);
    bVar4 = DAT_2001c4e5;
    bVar3 = DAT_2001c4e4;
    iVar9 = *unaff_r6;
    uVar14 = (uint)DAT_2001c4e5;
    uVar11 = (uint)DAT_2001c4e4;
    unaff_r4[1] = bVar5;
    unaff_r4[3] = bVar4;
    unaff_r4[5] = bVar3;
    unaff_r4[8] = bVar1;
    if (2 < iVar9) {
      if (BLE_DEBUG == 0) {
        printk("%s(): quicknote index = %d,stocks index = %d,news index = %d,calendar = %d\n",
               "ui_DashBoard_task",uVar13,uVar14,uVar11,uVar17);
      }
      else {
        ble_printk("%s(): quicknote index = %d,stocks index = %d,news index = %d,calendar = %d\n");
      }
      if (2 < *unaff_r6) {
        if (BLE_DEBUG == 0) {
          printk("%s(): db_info->schedule_disp_status = %d\n","ui_DashBoard_task",
                 (uint)*(byte *)(unaff_r5 + 0x156),0,uVar11,uVar17);
        }
        else {
          ble_printk("%s(): db_info->schedule_disp_status = %d\n");
        }
        if (2 < *unaff_r6) {
          if (BLE_DEBUG == 0) {
            printk("%s(): db_info->stocks_disp_mode = %d\n","ui_DashBoard_task",
                   (uint)*(byte *)(unaff_r5 + 0x158),0,uVar11,uVar17);
          }
          else {
            ble_printk("%s(): db_info->stocks_disp_mode = %d\n");
          }
          if (2 < *unaff_r6) {
            if (BLE_DEBUG == 0) {
              printk("%s(): db_info->news_disp_mode = %d\n","ui_DashBoard_task",
                     (uint)*(byte *)(unaff_r5 + 0x159));
            }
            else {
              ble_printk("%s(): db_info->news_disp_mode = %d\n");
            }
            if (2 < *unaff_r6) {
              if (BLE_DEBUG == 0) {
                printk("%s(): db_info->schedule_disp_status = %d\n","ui_DashBoard_task",
                       (uint)*(byte *)(unaff_r5 + 0x156));
              }
              else {
                ble_printk("%s(): db_info->schedule_disp_status = %d\n");
              }
              if (2 < *unaff_r6) {
                if (BLE_DEBUG == 0) {
                  printk("%s(): db_info->citywalk_disp_mode = %d\n","ui_DashBoard_task",
                         (uint)*(byte *)(unaff_r5 + 0x15a));
                }
                else {
                  ble_printk("%s(): db_info->citywalk_disp_mode = %d\n");
                }
              }
            }
          }
        }
      }
    }
    __clear_showing_notification_on_gui();
    DAT_2000a9b0 = 0;
    while (DAT_2000a9b0 < 4) {
      pGVar8 = __get_dashboard_state();
      DashBoard_Reflash(unaff_r8,(int)pGVar8,1,(uint)*(byte *)(unaff_r5 + 0x154));
      uVar11 = 0;
      do {
        iVar9 = 0;
        do {
          local_228 = 0x7050301;
          local_224 = 0x7070707;
          iVar16 = *(int *)(unaff_r7 + uVar11 * 4);
          bVar1 = *(byte *)(iVar16 + iVar9);
          if (bVar1 != 0) {
            *(byte *)(iVar16 + iVar9) =
                 bVar1 & (&DAT_000accab)
                         [iVar9 + (uint)*(byte *)((int)&local_228 + DAT_2000a9b0) * 0x140 +
                                  (uVar11 % 0x1a) * 0xa00];
          }
          iVar9 = iVar9 + 1;
        } while (iVar9 != 0x140);
        uVar11 = uVar11 + 1;
      } while (uVar11 != 199);
      DAT_2000a9b0 = DAT_2000a9b0 + 1;
      pGVar8 = __get_dashboard_state();
      uVar15 = (pGVar8->jdb_panel_context).current_row;
      pGVar8 = __get_dashboard_state();
      _reflash_fb_data_to_lcd(uVar15,(pGVar8->jdb_panel_context).current_column,0,0,0x280,199);
    }
    __set_showing_notification_on_gui();
    pGVar8 = __get_dashboard_state();
    if (pGVar8->is_master == true) {
      local_228 = CONCAT22(local_228._2_2_,0x202);
      cVar6 = unaff_r4[0x1a];
      if (cVar6 == '\0') {
        cVar6 = __getNotesIndex();
        local_228._0_2_ = CONCAT11(cVar6 << 4 | local_228._1_1_,(undefined1)local_228);
        if (2 < LOG_LEVEL) {
          fmt = "%s(): master sync quicknote index to slave ,index = %d\n";
          goto LAB_0003d002;
        }
      }
      else if (cVar6 == '\x01') {
        local_228 = CONCAT22(local_228._2_2_,0x402);
        cVar6 = getStocksIndex();
        local_228._0_2_ = CONCAT11(cVar6 << 4 | local_228._1_1_,(undefined1)local_228);
        if (2 < LOG_LEVEL) {
          fmt = "%s(): master sync stocks index to slave,index = %d\n";
LAB_0003d002:
          if (BLE_DEBUG == 0) {
            printk(fmt,"ui_DashBoard_task");
          }
          else {
            ble_printk(fmt);
          }
        }
      }
      else {
        if (cVar6 == '\x02') {
          local_228 = CONCAT22(local_228._2_2_,0x602);
          cVar6 = getNewsIndex();
        }
        else {
          if (cVar6 != '\x03') goto LAB_0003d00c;
          local_228 = CONCAT22(local_228._2_2_,0x802);
          cVar6 = getCalenadrIndex();
        }
        local_228._0_2_ = CONCAT11(cVar6 << 4 | local_228._1_1_,(undefined1)local_228);
        if (2 < LOG_LEVEL) {
          fmt = "%s(): master sync news index to slave,index = %d\n";
          goto LAB_0003d002;
        }
      }
LAB_0003d00c:
      pGVar8 = __get_dashboard_state();
      uVar11 = sync_to_slave(&pGVar8->is_master,6,&local_228,2);
      if ((int)uVar11 < 5000) {
        if (2 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            uVar10 = FUN_00080732();
            printk("%s(): sync to slave return value = %d,exec key function. ts = %d\n",
                   "ui_DashBoard_task",uVar11,uVar10);
          }
          else {
            uVar10 = FUN_00080732();
            ble_printk("%s(): sync to slave return value = %d,exec key function. ts = %d\n",
                       _ui_DashBoard_task,uVar11,uVar10);
          }
        }
      }
      else if (1 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): SYNC TO Slave failed...,don\'t exec key function.\n","ui_DashBoard_task");
        }
        else {
          ble_printk("%s(): SYNC TO Slave failed...,don\'t exec key function.\n");
        }
      }
    }
    uVar18 = sys_clock_tick_get();
    lVar2 = (uVar18 & 0xffffffff) * 1000;
    uVar11 = (int)(uVar18 >> 0x20) * 1000 + (int)((ulonglong)lVar2 >> 0x20);
    *(uint *)(unaff_r4 + 0x10) = (uint)lVar2 >> 0xf | uVar11 * 0x20000;
    *(uint *)(unaff_r4 + 0x14) = uVar11 >> 0xf;
    *unaff_r4 = 1;
    unaff_r4[0x24] = 1;
    uVar10 = FUN_0004c124(0x42);
    __send_message_count_to_app(uVar10,extraout_r1_01,extraout_r2_01,extraout_r3);
  }
  pGVar8 = __get_dashboard_state();
  if (pGVar8->is_master == true) {
    bVar7 = FUN_00028d2c();
    if (bVar7) {
      cVar6 = FUN_00030440();
      if ((cVar6 == '\x01') && (pGVar8 = __get_dashboard_state(), pGVar8[1].is_master == false)) {
        FUN_0008040c();
      }
    }
    else {
      cVar6 = FUN_00030440();
      if (cVar6 != '\x01') {
        FUN_00030458();
      }
    }
  }
LAB_0003d09a:
  iVar9 = FUN_000806de(&DAT_20007f50);
  if ((iVar9 << 0x1e < 0) && (iVar9 = FUN_000806de(&DAT_20007f4c), -1 < iVar9 << 0x1e)) {
    local_228 = 0x650;
    local_224 = CONCAT22(local_224._2_2_,0x201);
    if (2 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): send dashboard lock info to app ,status = %d \n","ui_DashBoard_task",2);
      }
      else {
        ble_printk("%s(): send dashboard lock info to app ,status = %d \n");
      }
    }
    uVar10 = send_response_data_to_msgqueue(&local_228,6);
    send_response_data_to_ble(uVar10,extraout_r1_02,extraout_r2_02,extraout_r3_00);
    DAT_20007f4c = DAT_20007f4c | 2;
  }
  return 0;
}


