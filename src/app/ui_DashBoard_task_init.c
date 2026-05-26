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
  longlong lVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  byte bVar4;
  byte bVar5;
  bool bVar6;
  char cVar7;
  GlassesState *pGVar8;
  void *pvVar9;
  int iVar10;
  char *fmt;
  undefined4 uVar11;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  undefined4 extraout_r1_02;
  undefined4 extraout_r1_03;
  undefined4 extraout_r1_04;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 uVar12;
  undefined4 extraout_r2_01;
  uint uVar13;
  undefined4 extraout_r2_02;
  undefined4 extraout_r2_03;
  undefined4 extraout_r2_04;
  undefined4 extraout_r2_05;
  uint uVar14;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined1 *unaff_r4;
  int unaff_r5;
  int *unaff_r6;
  int unaff_r7;
  int unaff_r8;
  int unaff_r9;
  int iVar15;
  ulonglong uVar16;
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
      (pGVar8 = __get_dashboard_state(), pGVar8->glasses_state_struct_0FF0->field_0x73 != '\x01'))
     || (*(char *)(unaff_r5 + 0x162) != '\x01')) goto LAB_0003d09a;
  if (unaff_r4[0xc] == '\0') {
    uVar11 = extraout_r1;
    uVar12 = extraout_r2;
    if (2 < *unaff_r6) {
      if (BLE_DEBUG == 0) {
        printk("%s(): DASHBOARD INIT .......\n");
        uVar11 = extraout_r1_04;
        uVar12 = extraout_r2_05;
      }
      else {
        ble_printk("%s(): DASHBOARD INIT .......\n","ui_DashBoard_task",extraout_r2,BLE_DEBUG);
        uVar11 = extraout_r1_00;
        uVar12 = extraout_r2_00;
      }
    }
    FUN_00029774(0x1e,uVar11,uVar12);
    pvVar9 = memset(&DAT_20004af8,0,0x28);
    gui_screen_clear(pvVar9,extraout_r1_01,extraout_r2_01);
    uVar2 = DAT_2001c4e3;
    unaff_r4[0xc] = 1;
    bVar4 = DAT_2001c4e6;
    uVar13 = (uint)DAT_2001c4e6;
    unaff_r4[0x20] = *(undefined1 *)(unaff_r5 + 0x156);
    bVar5 = DAT_2001c4e5;
    uVar3 = DAT_2001c4e4;
    iVar10 = *unaff_r6;
    uVar14 = (uint)DAT_2001c4e5;
    unaff_r4[1] = bVar4;
    unaff_r4[3] = bVar5;
    unaff_r4[5] = uVar3;
    unaff_r4[8] = uVar2;
    if (2 < iVar10) {
      if (BLE_DEBUG == 0) {
        printk("%s(): quicknote index = %d,stocks index = %d,news index = %d,calendar = %d\n");
      }
      else {
        ble_printk("%s(): quicknote index = %d,stocks index = %d,news index = %d,calendar = %d\n",
                   "ui_DashBoard_task",uVar13,uVar14);
      }
      if (2 < *unaff_r6) {
        if (BLE_DEBUG == 0) {
          printk("%s(): db_info->schedule_disp_status = %d\n");
        }
        else {
          ble_printk("%s(): db_info->schedule_disp_status = %d\n","ui_DashBoard_task",
                     (uint)*(byte *)(unaff_r5 + 0x156),BLE_DEBUG);
        }
        if (2 < *unaff_r6) {
          if (BLE_DEBUG == 0) {
            printk("%s(): db_info->stocks_disp_mode = %d\n");
          }
          else {
            ble_printk("%s(): db_info->stocks_disp_mode = %d\n","ui_DashBoard_task",
                       (uint)*(byte *)(unaff_r5 + 0x158),BLE_DEBUG);
          }
          if (2 < *unaff_r6) {
            if (BLE_DEBUG == 0) {
              printk("%s(): db_info->news_disp_mode = %d\n");
            }
            else {
              ble_printk("%s(): db_info->news_disp_mode = %d\n","ui_DashBoard_task",
                         (uint)*(byte *)(unaff_r5 + 0x159),BLE_DEBUG);
            }
            if (2 < *unaff_r6) {
              if (BLE_DEBUG == 0) {
                printk("%s(): db_info->schedule_disp_status = %d\n");
              }
              else {
                ble_printk("%s(): db_info->schedule_disp_status = %d\n","ui_DashBoard_task",
                           (uint)*(byte *)(unaff_r5 + 0x156),BLE_DEBUG);
              }
              if (2 < *unaff_r6) {
                if (BLE_DEBUG == 0) {
                  printk("%s(): db_info->citywalk_disp_mode = %d\n");
                }
                else {
                  ble_printk("%s(): db_info->citywalk_disp_mode = %d\n","ui_DashBoard_task",
                             (uint)*(byte *)(unaff_r5 + 0x15a),BLE_DEBUG);
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
      pGVar8 = __get_dashboard_state();
      DashBoard_Reflash(unaff_r8,(int)pGVar8,1,(uint)*(byte *)(unaff_r5 + 0x154));
      uVar13 = 0;
      do {
        iVar10 = 0;
        do {
          local_228 = 0x7050301;
          local_224 = 0x7070707;
          iVar15 = *(int *)(unaff_r7 + uVar13 * 4);
          bVar5 = *(byte *)(iVar15 + iVar10);
          if (bVar5 != 0) {
            *(byte *)(iVar15 + iVar10) =
                 bVar5 & (&DAT_000accab)
                         [iVar10 + (uint)*(byte *)((int)&local_228 + DAT_2000a9b0) * 0x140 +
                                   (uVar13 % 0x1a) * 0xa00];
          }
          iVar10 = iVar10 + 1;
        } while (iVar10 != 0x140);
        uVar13 = uVar13 + 1;
      } while (uVar13 != 199);
      DAT_2000a9b0 = DAT_2000a9b0 + 1;
      pGVar8 = __get_dashboard_state();
      iVar10 = *(int *)&pGVar8->field_0xeb4;
      pGVar8 = __get_dashboard_state();
      _reflash_fb_data_to_lcd(iVar10,*(int *)&pGVar8->field_0xeb8,0,0,0x280,199);
    }
    FUN_0004540c();
    pGVar8 = __get_dashboard_state();
    if (*(char *)pGVar8 == '\x01') {
      local_228 = CONCAT22(local_228._2_2_,0x202);
      cVar7 = unaff_r4[0x1a];
      if (cVar7 == '\0') {
        bVar5 = FUN_00038ac8();
        uVar13 = (bVar5 & 0xf) << 4 | local_228 >> 8 & 0xff;
        local_228._0_2_ = CONCAT11((char)uVar13,(undefined1)local_228);
        if (2 < LOG_LEVEL) {
          fmt = "%s(): master sync quicknote index to slave ,index = %d\n";
          goto LAB_0003d002;
        }
      }
      else if (cVar7 == '\x01') {
        local_228 = CONCAT22(local_228._2_2_,0x402);
        bVar5 = getStocksIndex();
        uVar13 = (bVar5 & 0xf) << 4 | local_228 >> 8 & 0xff;
        local_228._0_2_ = CONCAT11((char)uVar13,(undefined1)local_228);
        if (2 < LOG_LEVEL) {
          fmt = "%s(): master sync stocks index to slave,index = %d\n";
LAB_0003d002:
          if (BLE_DEBUG == 0) {
            printk(fmt);
          }
          else {
            ble_printk(fmt,"ui_DashBoard_task",uVar13,BLE_DEBUG);
          }
        }
      }
      else {
        if (cVar7 == '\x02') {
          local_228 = CONCAT22(local_228._2_2_,0x602);
          bVar5 = getNewsIndex();
        }
        else {
          if (cVar7 != '\x03') goto LAB_0003d00c;
          local_228 = CONCAT22(local_228._2_2_,0x802);
          bVar5 = getCalenadrIndex();
        }
        uVar13 = (bVar5 & 0xf) << 4 | local_228 >> 8 & 0xff;
        local_228._0_2_ = CONCAT11((char)uVar13,(undefined1)local_228);
        if (2 < LOG_LEVEL) {
          fmt = "%s(): master sync news index to slave,index = %d\n";
          goto LAB_0003d002;
        }
      }
LAB_0003d00c:
      pGVar8 = __get_dashboard_state();
      uVar13 = sync_to_slave((char *)pGVar8,6,&local_228,2);
      if ((int)uVar13 < 5000) {
        if (2 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            uVar11 = FUN_00080732();
            printk("%s(): sync to slave return value = %d,exec key function. ts = %d\n",
                   "ui_DashBoard_task",uVar13,uVar11);
          }
          else {
            uVar11 = FUN_00080732();
            ble_printk("%s(): sync to slave return value = %d,exec key function. ts = %d\n",
                       _ui_DashBoard_task,uVar13,uVar11);
          }
        }
      }
      else if (1 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): SYNC TO Slave failed...,don\'t exec key function.\n");
        }
        else {
          ble_printk("%s(): SYNC TO Slave failed...,don\'t exec key function.\n","ui_DashBoard_task"
                     ,extraout_r2_02,BLE_DEBUG);
        }
      }
    }
    uVar16 = sys_clock_tick_get();
    lVar1 = (uVar16 & 0xffffffff) * 1000;
    uVar13 = (int)(uVar16 >> 0x20) * 1000 + (int)((ulonglong)lVar1 >> 0x20);
    *(uint *)(unaff_r4 + 0x10) = (uint)lVar1 >> 0xf | uVar13 * 0x20000;
    *(uint *)(unaff_r4 + 0x14) = uVar13 >> 0xf;
    *unaff_r4 = 1;
    unaff_r4[0x24] = 1;
    uVar11 = FUN_0004c124(0x42);
    __send_message_count_to_app(uVar11,extraout_r1_02,extraout_r2_03,extraout_r3);
  }
  pGVar8 = __get_dashboard_state();
  if (*(char *)pGVar8 == '\x01') {
    bVar6 = FUN_00028d2c();
    if (bVar6) {
      cVar7 = FUN_00030440();
      if ((cVar7 == '\x01') && (pGVar8 = __get_dashboard_state(), *(char *)(pGVar8 + 1) == '\0')) {
        FUN_0008040c();
      }
    }
    else {
      cVar7 = FUN_00030440();
      if (cVar7 != '\x01') {
        FUN_00030458();
      }
    }
  }
LAB_0003d09a:
  iVar10 = FUN_000806de(&DAT_20007f50);
  if ((iVar10 << 0x1e < 0) && (iVar10 = FUN_000806de(&DAT_20007f4c), -1 < iVar10 << 0x1e)) {
    local_228 = 0x650;
    local_224 = CONCAT22(local_224._2_2_,0x201);
    if (2 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): send dashboard lock info to app ,status = %d \n");
      }
      else {
        ble_printk("%s(): send dashboard lock info to app ,status = %d \n","ui_DashBoard_task",2,
                   BLE_DEBUG);
      }
    }
    uVar11 = send_response_data_to_msgqueue(&local_228,6);
    send_response_data_to_ble(uVar11,extraout_r1_03,extraout_r2_04,extraout_r3_00);
    DAT_20007f4c = DAT_20007f4c | 2;
  }
  return 0;
}


