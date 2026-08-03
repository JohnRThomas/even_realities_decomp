/*
 * Function: ui_teleprompter_task
 * Entry:    0003f24c
 * Prototype: undefined4 __stdcall ui_teleprompter_task(int param_1, undefined4 param_2, int param_3)
 */


undefined4 ui_teleprompter_task(int param_1,undefined4 param_2,int param_3)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  GlassesState *pGVar7;
  GlassesState *extraout_r0;
  GlassesState *pGVar8;
  dashboard_ts_context *pdVar9;
  int iVar10;
  int iVar11;
  GlassesState *extraout_r0_00;
  int iVar12;
  char *pcVar13;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  undefined4 extraout_r1_02;
  undefined4 extraout_r1_03;
  undefined4 extraout_r1_04;
  undefined4 uVar14;
  undefined4 extraout_r1_05;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 extraout_r2_02;
  undefined4 extraout_r2_03;
  undefined4 uVar15;
  byte *buffer;
  int extraout_r3;
  int extraout_r3_00;
  uint32_t uVar16;
  uint uVar17;
  int iVar18;
  uint32_t uVar19;
  bool bVar20;
  longlong lVar21;
  undefined8 uVar22;
  undefined8 uVar23;
  k_timeout_t timeout;
  k_timeout_t timeout_00;
  uint uVar24;
  undefined2 local_6c [2];
  undefined4 local_68;
  undefined4 auStack_64 [16];
  
  pGVar7 = __get_dashboard_state();
  buffer = (byte *)(param_1 + 0x24);
  __set_frame_buffer(buffer);
  __set_showing_notification_on_gui();
  uVar23 = CONCAT44(DAT_20004b4c,DAT_20004b48);
  switch(DAT_20004b40) {
  case 0:
    if (LOG_LEVEL < 3) {
      if (param_3 != 2) goto LAB_0003f2f8;
    }
    else {
      if (BLE_DEBUG == 0) {
        printk("%s(): running  TELEPROMPTER_DISPLAY_IDLE STATUS.\n","ui_teleprompter_task");
      }
      else {
        ble_printk("%s(): running  TELEPROMPTER_DISPLAY_IDLE STATUS.\n");
      }
      if (param_3 != 2) {
        if (2 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            pGVar8 = __get_dashboard_state();
            printk("%s(): GLOBAL->temeprompter_info->enable = %d\n","ui_teleprompter_task",
                   (uint)*(byte *)(*(int *)&pGVar8->field_0x1000 + 1));
          }
          else {
            pGVar8 = __get_dashboard_state();
            ble_printk("%s(): GLOBAL->temeprompter_info->enable = %d\n","ui_teleprompter_task",
                       (uint)*(byte *)(*(int *)&pGVar8->field_0x1000 + 1));
          }
        }
LAB_0003f2f8:
        uVar23 = CONCAT44(DAT_20004b4c,DAT_20004b48);
        if (param_3 == 1) {
          pGVar8 = __get_dashboard_state();
          uVar23 = CONCAT44(DAT_20004b4c,DAT_20004b48);
          if ((*(char *)(*(int *)&pGVar8->field_0x1000 + 1) == '\x01') &&
             (uVar23 = CONCAT44(DAT_20004b4c,DAT_20004b48), pGVar7->field20_0xc8[0x28] == '\x01')) {
            if (2 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): setp1: received teleprompter command.\n","ui_teleprompter_task");
              }
              else {
                ble_printk("%s(): setp1: received teleprompter command.\n");
              }
            }
            pGVar8 = __get_dashboard_state();
            if (pGVar8->is_master == true) {
              send_response_data_to_ble(pGVar8,extraout_r1,extraout_r2,1);
            }
            if (2 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): received teleprompter counter down timer start event..\n",
                       "ui_teleprompter_task");
              }
              else {
                ble_printk("%s(): received teleprompter counter down timer start event..\n");
              }
            }
            gui_screen_clear();
            memset(&DAT_20004b40,0,0x230);
            DAT_20004b40 = 1;
            uVar23 = FUN_00080894();
            DAT_20004b4c = (int)((ulonglong)uVar23 >> 0x20);
            DAT_20004b48 = (uint)uVar23;
            uVar23 = FUN_00080894();
            DAT_20004b54 = (undefined4)((ulonglong)uVar23 >> 0x20);
            DAT_20004b50 = (int)uVar23;
            DAT_20004b58 = 0;
            DAT_20004b41 = '\n';
            DAT_20004b65 = pGVar7->field20_0xc8[0x33];
            DAT_2000a9d0 = 0;
            DAT_2000a9cc = 0;
            DAT_2000a9c8 = 0;
            DAT_2000a9c4 = 0;
            DAT_2000a9c0 = 0;
            DAT_2000a9bc = 0;
            memset(&DAT_20004b70,0,0x200);
            timeout.ticks._4_4_ = 0xffffffff;
            timeout.ticks._0_4_ = extraout_r1_00;
            z_impl_k_mutex_lock(&k_mutex_2000851c,timeout);
            memcpy(&DAT_20004b70,pGVar7->field20_0xc8 + 0x3e,0x200);
            bVar3 = pGVar7->field20_0xc8[0x34];
            uVar4 = *(ushort *)(pGVar7->field20_0xc8 + 0x35);
            DAT_20004b64 = pGVar7->field20_0xc8[0x27];
            DAT_20004b65 = pGVar7->field20_0xc8[0x33];
            z_impl_k_mutex_unlock(&k_mutex_2000851c);
            uVar23 = FUN_00080894();
            uVar17 = (char)pGVar7->field20_0xc8[0x33] * 1000;
            uVar24 = uVar17 + (uint)uVar23;
            DAT_20004b68 = uVar24 - 0x15e;
            DAT_20004b6c = (int)((ulonglong)uVar23 >> 0x20) +
                           ((int)uVar17 >> 0x1f) + (uint)CARRY4(uVar17,(uint)uVar23) + -1 +
                           (uint)(0x15d < uVar24);
            if (2 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): teleprompter work mode = %d\n","ui_teleprompter_task",
                       (uint)DAT_20004b64);
              }
              else {
                ble_printk("%s(): teleprompter work mode = %d\n");
              }
            }
            __clear_showing_notification_on_gui();
            iVar10 = 0;
            do {
              iVar11 = FUN_000809e2();
              uVar5 = FUN_00080a3a();
              iVar12 = FUN_000809e2();
              uVar6 = FUN_00080a3a();
              uVar24 = 0;
              gui_utf_draw(0,&DAT_20004b70,0,iVar11 + 0x58,uVar5 + 1,iVar12 + 0x230,uVar6 + 0x88,5,
                           (uint)uVar4,0,(undefined *)0x0,0);
              pGVar7 = __get_dashboard_state();
              iVar11 = pGVar7->dashboard_ts->time_disp_mode;
              pdVar9 = (dashboard_ts_context *)FUN_00080732();
              iVar12 = FUN_000809e2();
              uVar5 = FUN_00080a3a();
              iVar18 = FUN_000809e2();
              uVar6 = FUN_00080a3a();
              gui_clock_draw(pdVar9,iVar12,uVar5 + 2,iVar18 + 0x3f,uVar6 + 0x1d,3,
                             (char)iVar11 != '\x01');
              iVar11 = FUN_000809e2();
              uVar5 = FUN_00080a3a();
              iVar12 = FUN_000809e2();
              uVar6 = FUN_00080a3a();
              gui_verticalLine_process_bar
                        (iVar11 + 0x23c,(uint)uVar5,iVar12 + 0x23c,uVar6 + 0x88,1,bVar3);
              iVar11 = FUN_000809e2();
              uVar5 = FUN_00080a3a();
              gui_bmp_bitmap_draw(0x18,iVar11,uVar5 + 0x36,0,0,0);
              do {
                iVar11 = 0;
                do {
                  local_68 = 0x7050301;
                  auStack_64[0] = 0x7070707;
                  bVar2 = *(byte *)(*(int *)(buffer + uVar24 * 4) + iVar11);
                  if (bVar2 != 0) {
                    *(byte *)(*(int *)(buffer + uVar24 * 4) + iVar11) =
                         bVar2 & (&DAT_000accab)
                                 [iVar11 + (uint)*(byte *)((int)auStack_64 + iVar10 + -4) * 0x140 +
                                           (uVar24 % 0x1a) * 0xa00];
                  }
                  iVar11 = iVar11 + 1;
                } while (iVar11 != 0x140);
                uVar24 = uVar24 + 1;
              } while (uVar24 != 199);
              pGVar7 = __get_dashboard_state();
              uVar16 = (pGVar7->jdb_panel_context).current_row;
              pGVar7 = __get_dashboard_state();
              iVar10 = iVar10 + 1;
              _reflash_fb_data_to_lcd
                        (uVar16,(pGVar7->jdb_panel_context).current_column,0,0,0x280,199);
            } while (iVar10 != 4);
            __set_showing_notification_on_gui();
            z_impl_k_sleep((k_timeout_t)0x1334);
            FUN_00045444();
            uVar23 = CONCAT44(DAT_20004b4c,DAT_20004b48);
          }
        }
        goto switchD_0003f274_default;
      }
    }
LAB_0003f2a0:
    gui_screen_clear();
    memset(&DAT_20004b40,0,0x230);
    uVar23 = CONCAT44(DAT_20004b4c,DAT_20004b48);
    goto switchD_0003f274_default;
  case 1:
    if (param_3 == 2) goto LAB_0003f2a0;
    if (param_3 == 1) {
      if (2 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): counter down break,received sync message...\n","ui_teleprompter_task");
        }
        else {
          ble_printk("%s(): counter down break,received sync message...\n");
        }
      }
      if ((byte)pGVar7->field20_0xc8[0x31] - 2 < 2) {
        uVar23 = FUN_00080894();
        DAT_20004b4c = (int)((ulonglong)uVar23 >> 0x20);
        DAT_20004b48 = (uint)uVar23;
        DAT_20004b40 = 2;
        uVar23 = FUN_00080894();
        DAT_20004b54 = (undefined4)((ulonglong)uVar23 >> 0x20);
        DAT_20004b50 = (int)uVar23;
        iVar10 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        iVar11 = FUN_000809e2();
        uVar5 = FUN_00080a3a();
        _clean_fb_data(buffer,0,iVar10,uVar4 + 0x36,iVar11 + 0x24,uVar5 + 0x52);
        if (DAT_20004b64 == 1) {
          iVar10 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          uVar24 = 0x1a;
        }
        else {
          if (DAT_20004b64 != 0) goto LAB_0003f6a0;
          iVar10 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          uVar24 = 0x19;
        }
        gui_bmp_bitmap_draw(uVar24,iVar10,uVar4 + 0x36,0,0,0);
      }
LAB_0003f6a0:
      pGVar7 = __get_dashboard_state();
      uVar23 = CONCAT44(DAT_20004b4c,DAT_20004b48);
      if (pGVar7->is_master == true) {
        send_response_data_to_ble(pGVar7,extraout_r1_01,extraout_r2_00,1);
        uVar23 = CONCAT44(DAT_20004b4c,DAT_20004b48);
      }
      goto switchD_0003f274_default;
    }
    uVar23 = CONCAT44(DAT_20004b4c,DAT_20004b48);
    if (param_3 != 0) goto switchD_0003f274_default;
    if (2 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): na sync arar reflash,update counter down timer\n","ui_teleprompter_task");
      }
      else {
        ble_printk("%s(): na sync arar reflash,update counter down timer\n");
      }
    }
    uVar23 = FUN_00080894();
    iVar10 = (int)((ulonglong)uVar23 >> 0x20);
    uVar24 = (uint)uVar23;
    if ((int)((iVar10 - DAT_20004b6c) - (uint)(uVar24 < DAT_20004b68)) < 0 ==
        (SBORROW4(iVar10,DAT_20004b6c) !=
        SBORROW4(iVar10 - DAT_20004b6c,(uint)(uVar24 < DAT_20004b68)))) {
      if (2 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): counter down timeout . exit counter down status ,switch TEXT DISPLAY \n",
                 "ui_teleprompter_task");
        }
        else {
          ble_printk("%s(): counter down timeout . exit counter down status ,switch TEXT DISPLAY \n"
                    );
        }
      }
      uVar23 = FUN_00080894();
      DAT_20004b54 = (undefined4)((ulonglong)uVar23 >> 0x20);
      DAT_20004b50 = (int)uVar23;
      DAT_20004b40 = 2;
      uVar23 = FUN_00080894();
      DAT_20004b4c = (int)((ulonglong)uVar23 >> 0x20);
      DAT_20004b48 = (uint)uVar23;
      iVar10 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      iVar11 = FUN_000809e2();
      uVar5 = FUN_00080a3a();
      _clean_fb_data(buffer,0,iVar10,uVar4 + 0x36,iVar11 + 0x1e,uVar5 + 0x50);
      pGVar7 = __get_dashboard_state();
      uVar16 = (pGVar7->jdb_panel_context).current_row;
      pGVar7 = __get_dashboard_state();
      uVar19 = (pGVar7->jdb_panel_context).current_column;
      iVar10 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      iVar11 = FUN_000809e2();
      uVar5 = FUN_00080a3a();
      iVar12 = uVar5 + 0x50;
      iVar11 = iVar11 + 0x1e;
LAB_0003f7c6:
      _reflash_fb_data_to_lcd(uVar16,uVar19,iVar10,uVar4 + 0x36,iVar11,iVar12);
      if (DAT_20004b64 == 1) {
        iVar10 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        uVar24 = 0x1a;
      }
      else {
        uVar23 = CONCAT44(DAT_20004b4c,DAT_20004b48);
        if (DAT_20004b64 != 0) goto switchD_0003f274_default;
        iVar10 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        uVar24 = 0x19;
      }
      gui_bmp_bitmap_draw(uVar24,iVar10,uVar4 + 0x36,0,0,0);
      uVar23 = CONCAT44(DAT_20004b4c,DAT_20004b48);
      goto switchD_0003f274_default;
    }
    lVar21 = __aeabi_ldivmod(DAT_20004b68 - uVar24,
                             (DAT_20004b6c - iVar10) - (uint)(DAT_20004b68 < uVar24),1000,0);
    iVar10 = (int)((ulonglong)lVar21 >> 0x20);
    bVar20 = (uint)(int)(char)DAT_20004b65 < (uint)lVar21;
    iVar11 = (int)((uint)DAT_20004b65 << 0x18) >> 0x1f;
    if ((int)((iVar11 - iVar10) - (uint)bVar20) < 0 !=
        (SBORROW4(iVar11,iVar10) != SBORROW4(iVar11 - iVar10,(uint)bVar20))) {
      lVar21 = CONCAT44((int)((uint)DAT_20004b65 << 0x18) >> 0x1f,(int)(char)DAT_20004b65);
    }
    if (lVar21 == 0) {
      if (2 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): remain time end ,switch text display ...\n","ui_teleprompter_task");
        }
        else {
          ble_printk("%s(): remain time end ,switch text display ...\n");
        }
      }
      uVar23 = FUN_00080894();
      DAT_20004b54 = (undefined4)((ulonglong)uVar23 >> 0x20);
      DAT_20004b50 = (int)uVar23;
      uVar23 = FUN_00080894();
      DAT_20004b4c = (int)((ulonglong)uVar23 >> 0x20);
      DAT_20004b48 = (uint)uVar23;
      DAT_20004b40 = 2;
      iVar10 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      iVar11 = FUN_000809e2();
      uVar5 = FUN_00080a3a();
      _clean_fb_data(buffer,0,iVar10,uVar4 + 0x36,iVar11 + 0x24,uVar5 + 0x52);
      pGVar7 = __get_dashboard_state();
      uVar16 = (pGVar7->jdb_panel_context).current_row;
      pGVar7 = __get_dashboard_state();
      uVar19 = (pGVar7->jdb_panel_context).current_column;
      iVar10 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      iVar11 = FUN_000809e2();
      uVar5 = FUN_00080a3a();
      iVar12 = uVar5 + 0x52;
      iVar11 = iVar11 + 0x24;
      goto LAB_0003f7c6;
    }
    local_68 = (uint)local_68._3_1_ << 0x18;
    snprintf((char *)&local_68,3,"%d",(int)lVar21);
    if (2 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): upgrade counterdown timer = %s\n","ui_teleprompter_task",&local_68);
      }
      else {
        ble_printk("%s(): upgrade counterdown timer = %s\n");
      }
    }
    iVar10 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    iVar11 = FUN_000809e2();
    uVar5 = FUN_00080a3a();
    iVar12 = uVar5 + 0x50;
    iVar11 = iVar11 + 0x1e;
    iVar18 = uVar4 + 0x36;
    pcVar13 = (char *)&local_68;
    break;
  case 2:
    if (LOG_LEVEL < 3) {
      if (param_3 == 2) goto LAB_0003f98a;
    }
    else {
      if (BLE_DEBUG == 0) {
        printk("%s(): running TELEPROMPTER_TEXT_DISPLAY STATUS.\n","ui_teleprompter_task");
      }
      else {
        ble_printk("%s(): running TELEPROMPTER_TEXT_DISPLAY STATUS.\n");
      }
      if (param_3 == 2) goto joined_r0x0003ffd8;
    }
    bVar3 = DAT_20004b5d;
    if (DAT_20004b5d == 1) {
      uVar24 = DAT_20004b58;
      if (DAT_20004b5c == 0) {
        uVar23 = FUN_00080894();
        DAT_20004b58 = (DAT_20004b58 - DAT_20004b50) + (int)uVar23;
        DAT_20004b5c = bVar3;
        uVar24 = DAT_20004b58;
      }
    }
    else if (DAT_20004b5c == 0) {
      uVar23 = FUN_00080894();
      uVar24 = ((int)uVar23 - DAT_20004b50) + DAT_20004b58;
    }
    else {
      uVar23 = FUN_00080894();
      DAT_20004b50 = (int)uVar23;
      DAT_20004b54 = 0;
      DAT_20004b60 = DAT_20004b58;
      DAT_20004b5c = 0;
      uVar24 = DAT_20004b60;
    }
    DAT_20004b60 = uVar24;
    pGVar8 = __get_dashboard_state();
    bVar20 = (char)pGVar8->dashboard_ts->time_disp_mode != '\x01';
    uVar24 = (uint)bVar20;
    pdVar9 = (dashboard_ts_context *)FUN_00080732();
    iVar10 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    iVar11 = FUN_000809e2();
    uVar5 = FUN_00080a3a();
    gui_clock_draw(pdVar9,iVar10,uVar4 + 2,iVar11 + 0x3f,uVar5 + 0x1d,3,bVar20);
    if (param_3 == 1) {
      pGVar8 = __get_dashboard_state();
      if (pGVar8->is_master == true) {
        uVar14 = extraout_r1_03;
        uVar15 = extraout_r2_02;
        iVar10 = LOG_LEVEL;
        if (2 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): received sync area command ,send store cache data to app\n",
                   "ui_teleprompter_task");
            pGVar8 = extraout_r0;
            uVar14 = extraout_r1_02;
            uVar15 = extraout_r2_01;
            iVar10 = extraout_r3;
          }
          else {
            ble_printk("%s(): received sync area command ,send store cache data to app\n");
            pGVar8 = extraout_r0_00;
            uVar14 = extraout_r1_04;
            uVar15 = extraout_r2_03;
            iVar10 = extraout_r3_00;
          }
        }
        send_response_data_to_ble(pGVar8,uVar14,uVar15,iVar10);
        if (DAT_20004b41 < '\x14') {
          DAT_20004b41 = '\x13';
        }
      }
      memset(&DAT_20004b70,0,0x200);
      timeout_00.ticks._4_4_ = 0xffffffff;
      timeout_00.ticks._0_4_ = extraout_r1_05;
      z_impl_k_mutex_lock(&k_mutex_2000851c,timeout_00);
      memcpy(&DAT_20004b70,pGVar7->field20_0xc8 + 0x3e,0x200);
      bVar3 = pGVar7->field20_0xc8[0x34];
      cVar1 = pGVar7->field20_0xc8[0x37];
      uVar4 = *(ushort *)(pGVar7->field20_0xc8 + 0x35);
      iVar10 = *(int *)(pGVar7->field20_0xc8 + 0x38);
      z_impl_k_mutex_unlock(&k_mutex_2000851c);
      if (DAT_20010f05 == '\x01') {
        DAT_20010f05 = '\0';
        iVar11 = FUN_000809e2();
        uVar5 = FUN_00080a3a();
        iVar12 = FUN_000809e2();
        uVar6 = FUN_00080a3a();
        FUN_00046544(0,&DAT_20004b70,0,iVar11 + 0x58,uVar5 + 1,iVar12 + 0x230,uVar6 + 0x88,5,
                     (uint)uVar4);
      }
      else {
        iVar11 = FUN_000809e2();
        uVar5 = FUN_00080a3a();
        iVar12 = FUN_000809e2();
        uVar6 = FUN_00080a3a();
        gui_utf_draw(0,&DAT_20004b70,0,iVar11 + 0x58,uVar5 + 1,iVar12 + 0x230,uVar6 + 0x88,5,
                     (uint)uVar4,0,(undefined *)0x0,0);
      }
      iVar11 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      iVar12 = FUN_000809e2();
      uVar5 = FUN_00080a3a();
      uVar24 = 0;
      gui_verticalLine_process_bar(iVar11 + 0x23c,(uint)uVar4,iVar12 + 0x23c,uVar5 + 0x88,1,bVar3);
      if (cVar1 == '\x01') {
        if (DAT_2000aa10 << 0x1e < 0) {
          iVar11 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          iVar12 = FUN_000809e2();
          uVar5 = FUN_00080a3a();
          _clean_fb_data(buffer,0,iVar11,uVar4 + 0x36,iVar12 + 0x24,uVar5 + 0x52);
        }
        if (DAT_2000aa10 << 0x1e < 0) {
          pGVar7 = __get_dashboard_state();
          uVar16 = (pGVar7->jdb_panel_context).current_row;
          pGVar7 = __get_dashboard_state();
          uVar19 = (pGVar7->jdb_panel_context).current_column;
          iVar11 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          iVar12 = FUN_000809e2();
          uVar5 = FUN_00080a3a();
          _reflash_fb_data_to_lcd(uVar16,uVar19,iVar11,uVar4 + 0x36,iVar12 + 0x24,uVar5 + 0x52);
        }
        iVar11 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        gui_bmp_bitmap_draw(0x1b,iVar11,uVar4 + 0x36,0,0,0);
        DAT_20004b5d = 1;
        DAT_20004b58 = iVar10 * 1000;
        uVar23 = FUN_00080894();
        DAT_20004b50 = (int)uVar23;
        DAT_20004b54 = 0;
        if (LOG_LEVEL < 3) goto LAB_0004026c;
        pcVar13 = "%s(): suspend enable...\n";
      }
      else {
        DAT_20004b5d = 0;
        if (DAT_2000aa10 << 0x1e < 0) {
          iVar10 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          iVar11 = FUN_000809e2();
          uVar5 = FUN_00080a3a();
          _clean_fb_data(buffer,0,iVar10,uVar4 + 0x36,iVar11 + 0x24,uVar5 + 0x52);
        }
        if (DAT_2000aa10 << 0x1e < 0) {
          pGVar7 = __get_dashboard_state();
          uVar16 = (pGVar7->jdb_panel_context).current_row;
          pGVar7 = __get_dashboard_state();
          uVar19 = (pGVar7->jdb_panel_context).current_column;
          iVar10 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          iVar11 = FUN_000809e2();
          uVar5 = FUN_00080a3a();
          _reflash_fb_data_to_lcd(uVar16,uVar19,iVar10,uVar4 + 0x36,iVar11 + 0x24,uVar5 + 0x52);
        }
        if (DAT_20004b64 == 1) {
          iVar10 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          uVar17 = 0x1a;
LAB_0003fac8:
          gui_bmp_bitmap_draw(uVar17,iVar10,uVar4 + 0x36,0,0,0);
        }
        else if (DAT_20004b64 == 0) {
          iVar10 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          uVar17 = 0x19;
          goto LAB_0003fac8;
        }
        if (LOG_LEVEL < 3) goto LAB_0004026c;
        pcVar13 = "%s(): suspend cancel...\n";
      }
      if (BLE_DEBUG == 0) {
        printk(pcVar13,"ui_teleprompter_task");
      }
      else {
        ble_printk(pcVar13);
      }
    }
LAB_0004026c:
    if ((DAT_20004b64 == 2) && (uVar17 = (uint)DAT_20004b5d, uVar17 == 0)) {
      iVar10 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      gui_bmp_dynamic_bitmap_draw(1,iVar10,uVar4 + 0x36);
      uVar24 = uVar17;
    }
    DAT_20004b60 = DAT_20004b60 / 1000;
    if (DAT_20004b60 < 0x3c) {
      DAT_2000a9c8 = DAT_20004b60 % 0x3c;
    }
    else if (DAT_20004b60 < 0xe10) {
      DAT_2000a9c8 = DAT_20004b60 % 0x3c;
      DAT_2000a9cc = DAT_20004b60 / 0x3c;
    }
    else if (DAT_20004b60 < 360000) {
      DAT_2000a9d0 = DAT_20004b60 / 0xe10;
      DAT_2000a9cc = (DAT_20004b60 % 0xe10) / 0x3c;
      DAT_2000a9c8 = (DAT_20004b60 % 0xe10) % 0x3c;
    }
    else {
      DAT_2000a9d0 = 99;
      DAT_2000a9c8 = 0x3b;
      DAT_2000a9cc = 0x3b;
    }
    local_68 = 0;
    memset(auStack_64,0,0x3c);
    if ((int)DAT_2000a9d0 < 10) {
      pcVar13 = "%d:%02d:%02d";
    }
    else {
      pcVar13 = "%02d:%02d:%02d";
    }
    snprintf((char *)&local_68,0x40,pcVar13,DAT_2000a9d0,DAT_2000a9cc,DAT_2000a9c8,uVar24);
    if (((DAT_2000a9d0 != DAT_2000a9c4) || (DAT_2000a9cc != DAT_2000a9c0)) ||
       (DAT_2000a9c8 != DAT_2000a9bc)) {
      iVar10 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      iVar11 = FUN_000809e2();
      uVar5 = FUN_00080a3a();
      gui_utf_draw(0,(char *)&local_68,0,iVar10,uVar4 + 0x6e,iVar11 + 0x50,uVar5 + 0x88,1,0,0,
                   (undefined *)0x0,0);
      DAT_2000a9c4 = DAT_2000a9d0;
      DAT_2000a9c0 = DAT_2000a9cc;
      DAT_2000a9bc = DAT_2000a9c8;
    }
    pGVar7 = __get_dashboard_state();
    if (pGVar7->is_master == true) {
      if ((0 < DAT_20007f44) && (DAT_20007f44 = 0, DAT_20004b41 < '\x14')) {
        DAT_20004b41 = '\x13';
      }
      uVar23 = FUN_00080894();
      uVar22 = FUN_000809b6((uint)uVar23,(int)((ulonglong)uVar23 >> 0x20),DAT_20004b48,DAT_20004b4c)
      ;
      uVar23 = CONCAT44(DAT_20004b4c,DAT_20004b48);
      if ((int)((ulonglong)uVar22 >> 0x20) < (int)(uint)((uint)uVar22 < 0x3e9))
      goto switchD_0003f274_default;
      uVar23 = FUN_00080894();
      DAT_20004b4c = (int)((ulonglong)uVar23 >> 0x20);
      DAT_20004b48 = (uint)uVar23;
      DAT_20004b41 = DAT_20004b41 + -1;
      if (2 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): DECETED TIMEOUT ...... _tpm_thread_prv_data.sync_cnt = %d\n",
                 "ui_teleprompter_task",(int)DAT_20004b41);
          uVar23 = CONCAT44(DAT_20004b4c,DAT_20004b48);
        }
        else {
          ble_printk("%s(): DECETED TIMEOUT ...... _tpm_thread_prv_data.sync_cnt = %d\n");
          uVar23 = CONCAT44(DAT_20004b4c,DAT_20004b48);
        }
      }
      DAT_20004b4c = (int)((ulonglong)uVar23 >> 0x20);
      DAT_20004b48 = (uint)uVar23;
      if ('\0' < DAT_20004b41) goto switchD_0003f274_default;
      if (1 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): There is a disconnection between the AR Glasses and the Bluetooth application!\n"
                 ,"ui_teleprompter_task");
          uVar23 = CONCAT44(DAT_20004b4c,DAT_20004b48);
        }
        else {
          ble_printk(
                    "%s(): There is a disconnection between the AR Glasses and the Bluetooth application!\n"
                    );
          uVar23 = CONCAT44(DAT_20004b4c,DAT_20004b48);
        }
      }
      DAT_20004b4c = (int)((ulonglong)uVar23 >> 0x20);
      DAT_20004b48 = (uint)uVar23;
      if (2 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): bluetooth connect is break,Send Stop Teleprompter command to slave.\n",
                 "ui_teleprompter_task");
          uVar23 = CONCAT44(DAT_20004b4c,DAT_20004b48);
        }
        else {
          ble_printk("%s(): bluetooth connect is break,Send Stop Teleprompter command to slave.\n");
          uVar23 = CONCAT44(DAT_20004b4c,DAT_20004b48);
        }
      }
      DAT_20004b4c = (int)((ulonglong)uVar23 >> 0x20);
      DAT_20004b48 = (uint)uVar23;
      local_6c[0] = 0x103;
      pGVar7 = __get_dashboard_state();
      uVar24 = sync_to_slave(&pGVar7->is_master,6,(undefined4 *)local_6c,2);
      if (4999 < (int)uVar24) {
        uVar23 = CONCAT44(DAT_20004b4c,DAT_20004b48);
        if (0 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): SYNC TO Slave failed...,don\'t exec teleprompter exit action,master auto exit...\n"
                   ,"ui_teleprompter_task");
            uVar23 = CONCAT44(DAT_20004b4c,DAT_20004b48);
          }
          else {
            ble_printk(
                      "%s(): SYNC TO Slave failed...,don\'t exec teleprompter exit action,master auto exit...\n"
                      );
            uVar23 = CONCAT44(DAT_20004b4c,DAT_20004b48);
          }
        }
        goto switchD_0003f274_default;
      }
      DAT_20004b40 = 3;
      uVar23 = FUN_00080894();
      DAT_20004b4c = (int)((ulonglong)uVar23 >> 0x20);
      DAT_20004b48 = (uint)uVar23;
      gui_screen_clear();
      iVar10 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      gui_bmp_bitmap_draw(0x3f,iVar10,uVar4 + 0x3a,0,0,0);
      bVar3 = get_current_language();
      if (bVar3 == 6) {
        iVar10 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        iVar11 = FUN_000809e2();
        uVar5 = FUN_00080a3a();
        gui_utf_draw(0,"Teleprompter aufgrund einer",0,iVar10 + 0xa0,uVar4 + 0x37,iVar11 + 0x23a,
                     uVar5 + 0x52,1,0,0,(undefined *)0x0,0);
        iVar10 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        iVar12 = FUN_000809e2();
        uVar5 = FUN_00080a3a();
        iVar11 = uVar5 + 0x6d;
        iVar18 = uVar4 + 0x52;
        pcVar13 = "App-Trennung gestoppt.";
        iVar10 = iVar10 + 0xb4;
      }
      else {
        iVar10 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        iVar12 = FUN_000809e2();
        uVar5 = FUN_00080a3a();
        iVar11 = uVar5 + 0x88;
        iVar18 = uVar4 + 0x37;
        pcVar13 = "Teleprompt stopped due to app disconnection";
        iVar10 = iVar10 + 0x4e;
      }
      gui_utf_draw(0,pcVar13,0,iVar10,iVar18,iVar12 + 0x23a,iVar11,1,0,0,(undefined *)0x0,0);
      goto LAB_0003f99a;
    }
    uVar23 = CONCAT44(DAT_20004b4c,DAT_20004b48);
    if (param_3 != 5) goto switchD_0003f274_default;
    if (2 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): Received exit command from master, exit teleprompter mode\n",
               "ui_teleprompter_task");
      }
      else {
        ble_printk("%s(): Received exit command from master, exit teleprompter mode\n");
      }
    }
    DAT_20004b40 = 3;
    uVar23 = FUN_00080894();
    DAT_20004b4c = (int)((ulonglong)uVar23 >> 0x20);
    DAT_20004b48 = (uint)uVar23;
    gui_screen_clear();
    iVar10 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    gui_bmp_bitmap_draw(0x3f,iVar10,uVar4 + 0x3a,0,0,0);
    bVar3 = get_current_language();
    if (bVar3 == 6) {
      iVar10 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      iVar11 = FUN_000809e2();
      uVar5 = FUN_00080a3a();
      gui_utf_draw(0,"Teleprompter aufgrund einer",0,iVar10 + 0xa0,uVar4 + 0x37,iVar11 + 0x23a,
                   uVar5 + 0x52,1,0,0,(undefined *)0x0,0);
      iVar10 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      iVar11 = FUN_000809e2();
      uVar5 = FUN_00080a3a();
      iVar11 = iVar11 + 0x23a;
      iVar12 = uVar5 + 0x6d;
      iVar18 = uVar4 + 0x52;
      pcVar13 = "App-Trennung gestoppt.";
      iVar10 = iVar10 + 0xb4;
    }
    else {
      iVar10 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      iVar11 = FUN_000809e2();
      uVar5 = FUN_00080a3a();
      iVar12 = uVar5 + 0x88;
      iVar11 = iVar11 + 0x23a;
      iVar18 = uVar4 + 0x37;
      pcVar13 = "Teleprompt stopped due to app disconnection";
      iVar10 = iVar10 + 0x4e;
    }
    break;
  case 3:
    if (1 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): running TELEPROMPTER_DISPLAY_ABNORMAL_EXIT STATUS.\n","ui_teleprompter_task");
      }
      else {
        ble_printk("%s(): running TELEPROMPTER_DISPLAY_ABNORMAL_EXIT STATUS.\n");
      }
    }
    uVar23 = FUN_00080894();
    uVar23 = FUN_000809b6((uint)uVar23,(int)((ulonglong)uVar23 >> 0x20),DAT_20004b48,DAT_20004b4c);
    if ((int)(uint)((uint)uVar23 < 0x1f41) <= (int)((ulonglong)uVar23 >> 0x20)) {
      if (1 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): The teleprompter automatically shuts down due to disconnection.\n",
                 "ui_teleprompter_task");
        }
        else {
          ble_printk("%s(): The teleprompter automatically shuts down due to disconnection.\n");
        }
      }
      pGVar7 = __get_dashboard_state();
      memset(*(void **)&pGVar7->field_0x1000,0,0x217);
      FUN_00045968();
      pGVar7 = __get_dashboard_state();
      *(undefined1 *)(*(int *)&pGVar7->field_0x1000 + 1) = 0;
      memset(&DAT_20004b40,0,0x230);
    }
    uVar23 = CONCAT44(DAT_20004b4c,DAT_20004b48);
    if (param_3 != 2) goto switchD_0003f274_default;
joined_r0x0003ffd8:
    if (2 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): received exit command,clear screen...\n","ui_teleprompter_task");
      }
      else {
        ble_printk("%s(): received exit command,clear screen...\n");
      }
    }
LAB_0003f98a:
    FUN_00045968();
    memset(&DAT_20004b40,0,0x230);
LAB_0003f99a:
    pGVar7 = __get_dashboard_state();
    uVar23 = CONCAT44(DAT_20004b4c,DAT_20004b48);
    if ((pGVar7->is_master == true) &&
       (uVar23 = CONCAT44(DAT_20004b4c,DAT_20004b48), DAT_20004b64 == 2)) {
      FUN_00030458();
      uVar23 = CONCAT44(DAT_20004b4c,DAT_20004b48);
    }
  default:
    goto switchD_0003f274_default;
  }
  gui_utf_draw(0,pcVar13,0,iVar10,iVar18,iVar11,iVar12,1,0,0,(undefined *)0x0,0);
  uVar23 = CONCAT44(DAT_20004b4c,DAT_20004b48);
switchD_0003f274_default:
  DAT_20004b4c = (int)((ulonglong)uVar23 >> 0x20);
  DAT_20004b48 = (uint)uVar23;
  return 0;
}


