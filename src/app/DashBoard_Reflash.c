/*
 * Function: DashBoard_Reflash
 * Entry:    00038dc4
 * Prototype: undefined __stdcall DashBoard_Reflash(int param_1, int param_2, int param_3, int param_4)
 */


void DashBoard_Reflash(int param_1,int param_2,int param_3,int param_4)

{
  bool bVar1;
  char cVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  GlassesState *pGVar6;
  dashboard_ts_context *pdVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  size_t sVar11;
  size_t n;
  char *pcVar12;
  int iVar13;
  undefined *puVar14;
  byte bVar15;
  uint uVar16;
  char *pcVar17;
  uint uVar18;
  uint32_t uVar19;
  uint32_t uVar20;
  uint uVar21;
  uint local_a8;
  uint local_a4;
  uint local_a0;
  uint local_9c;
  undefined4 local_98;
  uint local_94;
  uint local_90 [4];
  undefined4 local_80;
  uint local_7c [22];
  
  if (2 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): display_mode = %d\n","DashBoard_Reflash",param_4);
    }
    else {
      ble_printk("%s(): display_mode = %d\n");
    }
  }
  bVar1 = FUN_00028d2c();
  uVar18 = (uint)bVar1;
  if (2 < LOG_LEVEL) {
    pcVar12 = "connect";
    if (BLE_DEBUG == 0) {
      if (uVar18 != 1) {
        pcVar12 = "disconnect";
      }
      printk("%s(): BLE Connect status : %s\n","DashBoard_Reflash",pcVar12);
    }
    else {
      if (uVar18 != 1) {
        pcVar12 = "disconnect";
      }
      ble_printk("%s(): BLE Connect status : %s\n","DashBoard_Reflash",pcVar12);
    }
  }
  pGVar6 = __get_dashboard_state();
  if (pGVar6->is_master == true) {
    if ((((uVar18 == 1) && (pGVar6 = __get_dashboard_state(), pGVar6[1].is_master == false)) &&
        (pGVar6 = __get_dashboard_state(), pGVar6->dashboard_ts->field_0x73 == '\x01')) &&
       (pGVar6 = __get_dashboard_state(), pGVar6->dashboard_ts->field_0x74 == '\0')) {
      cVar2 = FUN_00030440();
      if (cVar2 == '\x01') {
        FUN_0008040c();
      }
    }
    else {
      cVar2 = FUN_00030440();
      if (cVar2 != '\x01') {
        FUN_00030458();
      }
    }
  }
  if (param_4 == 1) {
    if (((DAT_20004b14 != uVar18) || (DAT_20004b11 != '\x01')) ||
       (PANE_MODE != *(byte *)(param_1 + 0x66))) {
      gui_screen_clear();
      PANE_MODE = *(byte *)(param_1 + 0x66);
      DAT_20004b11 = *(char *)(param_1 + 0x65);
      DAT_20004b14 = uVar18;
      if (2 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): display_mode = %d ,exec screen clear\n","DashBoard_Reflash");
        }
        else {
          ble_printk("%s(): display_mode = %d ,exec screen clear\n");
        }
      }
    }
    local_a0 = 0;
    local_9c = 0;
    local_98 = 0;
    if (uVar18 == 1) {
      pdVar7 = (dashboard_ts_context *)FUN_00080732();
      __init_burial_point_date(pdVar7,(undefined2 *)&local_a0);
      iVar8 = FUN_000807aa(local_a0 & 0xffff,local_a0 >> 0x10,local_9c & 0xffff);
      pcVar12 = get_string(iVar8 + 0x28U & 0xff);
      local_94 = 0;
      memset(local_90,0,0x10);
      uVar16 = local_9c & 0xffff;
      uVar18 = local_a0 >> 0x10;
      if (*(char *)(param_1 + 0x5f) == '\0') {
        pcVar17 = "%s, %02d/%02d";
        uVar21 = uVar18;
        uVar18 = uVar16;
      }
      else {
        uVar21 = uVar16;
        if (*(char *)(param_1 + 0x5f) == '\x01') {
          pcVar17 = "%s, %02d-%02d";
        }
        else {
          pcVar17 = "%s, %02d/%02d";
        }
      }
      __sprintf_chk((char *)&local_94,0,0x14,pcVar17,pcVar12,uVar21,uVar18);
      iVar8 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      iVar9 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      gui_utf_draw(0,(char *)&local_94,3,iVar8,uVar3 + 2,iVar9 + 0x8c,uVar4 + 0x1d,1,0,0,
                   (undefined *)0x0,0);
      pGVar6 = __get_dashboard_state();
      iVar8 = pGVar6->dashboard_ts->time_disp_mode;
      pdVar7 = (dashboard_ts_context *)FUN_00080732();
      iVar9 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      iVar10 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      gui_clock_draw(pdVar7,iVar9,uVar3 + 0x34,iVar10 + 0x96,uVar4 + 0x55,1,(char)iVar8 != '\x01');
      if (param_3 == 1) {
        iVar8 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        gui_bmp_bitmap_draw(0x5a,iVar8 + 0x23e,uVar3 + 4,0,0,0);
        iVar8 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        gui_bmp_bitmap_draw(0x59,iVar8 + 0xac,uVar3 + 4,0,0,0);
        if (2 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): weather icon num = %d\n","DashBoard_Reflash",(uint)*(byte *)(param_1 + 4))
            ;
          }
          else {
            ble_printk("%s(): weather icon num = %d\n");
          }
        }
        local_80 = 0;
        local_7c[0] = 0;
        if ((*(byte *)(param_1 + 4) - 1 & 0xff) < 0xfe) {
          uVar18 = FUN_0004916c((uint)*(byte *)(param_1 + 4));
          iVar8 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          gui_bmp_bitmap_draw(uVar18,iVar8,uVar3 + 0x6d,0,0,0);
          pGVar6 = __get_dashboard_state();
          iVar8 = (int)*(char *)(param_1 + 5);
          local_80 = (uint)(byte)pGVar6->dashboard_ts->field_0x5d;
          if (local_80 == 0) {
            local_7c[0] = local_80;
            if (2 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): temperature = %d\n","DashBoard_Reflash",iVar8);
              }
              else {
                ble_printk("%s(): temperature = %d\n");
              }
            }
            snprintf((char *)&local_80,8,"%d",iVar8);
            local_a8 = 0;
            iVar8 = FUN_000809e2();
            uVar3 = FUN_00080a3a();
            iVar9 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            gui_string_draw(3,(byte *)&local_80,iVar8 + 0x1c,uVar3 + 0x6d,iVar9 + 0x58,uVar4 + 0x88,
                            (int *)&local_a8);
            bVar15 = 0x2a;
          }
          else {
            local_80 = 0;
            local_7c[0] = 0;
            iVar8 = (iVar8 * 9) / 5 + 0x20;
            if (2 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): fahrenheit_temperature = %d\n","DashBoard_Reflash",iVar8);
              }
              else {
                ble_printk("%s(): fahrenheit_temperature = %d\n");
              }
            }
            snprintf((char *)&local_80,8,"%d",iVar8);
            local_a8 = 0;
            iVar8 = FUN_000809e2();
            uVar3 = FUN_00080a3a();
            iVar9 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            gui_string_draw(3,(byte *)&local_80,iVar8 + 0x1c,uVar3 + 0x6d,iVar9 + 0x58,uVar4 + 0x88,
                            (int *)&local_a8);
            bVar15 = 0x23;
          }
          local_7c[0] = 0;
          local_80 = (uint)bVar15;
          iVar8 = FUN_000809e2();
          iVar9 = iVar8 + 0x1c + local_a8;
          uVar3 = FUN_00080a3a();
          iVar8 = FUN_000809e2();
          iVar8 = local_a8 + iVar8;
          uVar4 = FUN_00080a3a();
          gui_string_draw(3,(byte *)&local_80,iVar9,uVar3 + 0x6d,iVar8 + 0x67,uVar4 + 0x88,
                          (int *)0x0);
        }
        iVar8 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        gui_bmp_bitmap_draw(0x3c,iVar8 + 0x60,uVar3 + 0x6d,0,0,0);
        uVar18 = FUN_00035310();
        if ((int)uVar18 < 0xb) {
          pcVar12 = "%d";
        }
        else {
          pcVar12 = "%d+";
          uVar18 = 10;
        }
        local_80 = 0;
        local_7c[0] = 0;
        snprintf((char *)&local_80,8,pcVar12,uVar18);
        iVar8 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        gui_string_draw(3,(byte *)&local_80,iVar8 + 0x7c,uVar3 + 0x6d,iVar9 + 0x9a,uVar4 + 0x88,
                        (int *)0x0);
        if (*(char *)(param_1 + 0x60) == '\x01') {
          iVar8 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          gui_bmp_bitmap_draw(0x42,iVar8 + 0x8c,uVar3 + 1,0,0,0);
        }
        else {
          pGVar6 = __get_dashboard_state();
          iVar8 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          _clean_fb_data((byte *)&(pGVar6->jdb_panel_context).__panel_buffer,0,iVar8 + 0x8c,
                         uVar3 + 1,iVar9 + 0xa4,uVar4 + 0x1c);
          pGVar6 = __get_dashboard_state();
          uVar20 = (pGVar6->jdb_panel_context).current_row;
          pGVar6 = __get_dashboard_state();
          uVar19 = (pGVar6->jdb_panel_context).current_column;
          iVar8 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          _reflash_fb_data_to_lcd(uVar20,uVar19,iVar8 + 0x8c,uVar3 + 1,iVar9 + 0xa4,uVar4 + 0x1c);
        }
      }
      else if (param_3 != 4) {
        return;
      }
      uVar18 = (uint)PANE_MODE;
      if (uVar18 == 0) {
        local_80 = uVar18;
        memset(local_7c,0,0x1c);
        iVar9 = 0;
        iVar8 = 0;
        do {
          if (*(char *)(iVar9 * 0x143 + *(int *)(param_2 + 0x1030) + 3) == '\x01') {
            if (2 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): quick note num.%d is vaild\n","DashBoard_Reflash",iVar9);
              }
              else {
                ble_printk("%s(): quick note num.%d is vaild\n");
              }
            }
            iVar8 = iVar8 + 1;
          }
          iVar9 = iVar9 + 1;
        } while (iVar9 != 4);
LAB_0003aba8:
        if (2 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): total quick note num = %d\n","DashBoard_Reflash",iVar8);
          }
          else {
            ble_printk("%s(): total quick note num = %d\n");
          }
        }
        DAT_20004afa = (char)iVar8;
        iVar9 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        gui_bmp_bitmap_draw(0x3b,iVar9 + 0xba,uVar3 + 1,0,0,0);
        if (iVar8 == 0) {
          iVar9 = FUN_000806de(&DAT_2000aa10);
          if ((iVar9 << 0x1e < 0) && (DAT_20004b02 == '\x01')) {
            DAT_20004b02 = (char)iVar8;
            pGVar6 = __get_dashboard_state();
            iVar8 = FUN_000809e2();
            uVar3 = FUN_00080a3a();
            iVar9 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            _clean_fb_data((byte *)&(pGVar6->jdb_panel_context).__panel_buffer,0,iVar8 + 0xd6,
                           uVar3 + 1,iVar9 + 0x22e,uVar4 + 0x1c);
            pGVar6 = __get_dashboard_state();
            uVar19 = (pGVar6->jdb_panel_context).current_row;
            pGVar6 = __get_dashboard_state();
            uVar20 = (pGVar6->jdb_panel_context).current_column;
            iVar8 = FUN_000809e2();
            uVar3 = FUN_00080a3a();
            iVar9 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            _reflash_fb_data_to_lcd(uVar19,uVar20,iVar8 + 0xd6,uVar3 + 1,iVar9 + 0x22e,uVar4 + 0x1c)
            ;
            pGVar6 = __get_dashboard_state();
            iVar8 = FUN_000809e2();
            uVar3 = FUN_00080a3a();
            iVar9 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            _clean_fb_data((byte *)&(pGVar6->jdb_panel_context).__panel_buffer,0,iVar8 + 0xba,
                           uVar3 + 0x1c,iVar9 + 0x238,uVar4 + 0x88);
            pGVar6 = __get_dashboard_state();
            uVar19 = (pGVar6->jdb_panel_context).current_row;
            pGVar6 = __get_dashboard_state();
            uVar20 = (pGVar6->jdb_panel_context).current_column;
            iVar8 = FUN_000809e2();
            uVar3 = FUN_00080a3a();
            iVar9 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            _reflash_fb_data_to_lcd
                      (uVar19,uVar20,iVar8 + 0xba,uVar3 + 0x1c,iVar9 + 0x238,uVar4 + 0x88);
          }
          FUN_00038b00();
          FUN_00038864();
          return;
        }
        DAT_20004b02 = '\x01';
        memset(&local_80,0,0x20);
        snprintf((char *)&local_80,0x20,"%d/%d",DAT_20004af9 + 1,iVar8);
        uVar18 = (uint)DAT_20004af9;
        iVar13 = *(int *)(param_2 + 0x1030);
        iVar9 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        iVar10 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        gui_utf_draw(0,(char *)(iVar13 + uVar18 * 0x143 + 4),0,iVar9 + 0xd6,uVar3 + 1,iVar10 + 0x22e
                     ,uVar4 + 0x1c,1,0,0,(undefined *)0x0,0);
        if (iVar8 == 1) {
          iVar8 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          pcVar12 = " ";
        }
        else {
          iVar8 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          pcVar12 = (char *)&local_80;
        }
        gui_utf_draw(0,pcVar12,0,iVar8 + 0x20e,uVar3 + 1,iVar9 + 0x23a,uVar4 + 0x1c,1,0,0,
                     (undefined *)0x0,0);
        pcVar12 = (char *)(uVar18 * 0x143 + 0x2d + *(int *)(param_2 + 0x1030));
        iVar8 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        iVar10 = uVar4 + 0x88;
        iVar9 = iVar9 + 0x238;
        iVar13 = uVar3 + 0x1c;
        iVar8 = iVar8 + 0xba;
LAB_0003a208:
        gui_utf_draw_dark_light_split
                  (0,pcVar12,0,iVar8,iVar13,iVar9,iVar10,4,0x200b,0,(undefined *)0x0,0);
        return;
      }
      switch(uVar18) {
      case 1:
        iVar8 = 0;
        iVar9 = 0;
        do {
          iVar10 = iVar8 * 0x7f2;
          iVar8 = iVar8 + 1;
          if ((&DAT_2000e104)[iVar10] == '\x01') {
            iVar9 = iVar9 + 1;
          }
        } while (iVar8 != 4);
        cVar2 = *(char *)(param_1 + 0x69);
        if (cVar2 == '\0') {
          if (DAT_20004b19 != '\0') {
            DAT_20004b19 = cVar2;
            iVar8 = FUN_000809e2();
            uVar3 = FUN_00080a3a();
            iVar10 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            gui_area_clear(iVar8 + 0xae,uVar3 + 4,iVar10 + 0x23c,uVar4 + 0x88);
          }
          if (iVar9 == 0) {
            cleanStocksIndex();
          }
          if (2 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): db_info->stocks_disp_mode = %d\n","DashBoard_Reflash",
                     (uint)*(byte *)(param_1 + 0x69));
            }
            else {
              ble_printk("%s(): db_info->stocks_disp_mode = %d\n");
            }
          }
          iVar8 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          gui_bmp_bitmap_draw(0x43,iVar8 + 0xba,uVar3 + 2,0,0,0);
          pcVar12 = get_string(0x4d);
          iVar9 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          iVar8 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          iVar10 = uVar4 + 0x51;
          iVar13 = uVar3 + 0x36;
          uVar18 = 1;
          iVar9 = iVar9 + 0xb8;
          goto LAB_000399e0;
        }
        if (cVar2 != '\x01') {
          if (cVar2 != '\x02') {
            return;
          }
          if (DAT_20004b19 != '\x02') {
            DAT_20004b19 = cVar2;
            iVar8 = FUN_000809e2();
            uVar3 = FUN_00080a3a();
            iVar9 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            gui_area_clear(iVar8 + 0xae,uVar3 + 4,iVar9 + 0x23c,uVar4 + 0x88);
          }
          iVar8 = 0;
          iVar9 = 0;
          do {
            iVar10 = iVar8 * 0x7f2;
            iVar8 = iVar8 + 1;
            if ((&DAT_2000e104)[iVar10] == '\x01') {
              iVar9 = iVar9 + 1;
            }
          } while (iVar8 != 4);
          uVar18 = (uint)DAT_20004afb;
          DAT_20004afc = (undefined1)iVar9;
          cVar2 = (&DAT_2000e105)[uVar18 * 0x7f2];
          if (cVar2 == '\0') {
            iVar8 = FUN_000809e2();
            uVar3 = FUN_00080a3a();
            iVar10 = uVar3 + 2;
            uVar16 = 0x46;
            iVar8 = iVar8 + 0xba;
LAB_0003b2b4:
            gui_bmp_bitmap_draw(uVar16,iVar8,iVar10,0,0,0);
          }
          else {
            if (cVar2 == '\x01') {
              iVar8 = FUN_000809e2();
              uVar3 = FUN_00080a3a();
              iVar10 = uVar3 + 2;
              uVar16 = 0x44;
              iVar8 = iVar8 + 0xba;
              goto LAB_0003b2b4;
            }
            if (cVar2 == '\x02') {
              iVar8 = FUN_000809e2();
              uVar3 = FUN_00080a3a();
              iVar10 = uVar3 + 2;
              uVar16 = 0x45;
              iVar8 = iVar8 + 0xba;
              goto LAB_0003b2b4;
            }
          }
          if (iVar9 == 0) {
            iVar8 = FUN_000809e2();
            uVar3 = FUN_00080a3a();
            iVar9 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            gui_area_clear(iVar8 + 0x20e,uVar3 + 1,iVar9 + 0x23a,uVar4 + 0x1c);
          }
          else {
            local_80 = 0;
            memset(local_7c,0,0x1c);
            snprintf((char *)&local_80,0x20,"%d/%d",uVar18 + 1,iVar9);
            iVar8 = FUN_000809e2();
            uVar3 = FUN_00080a3a();
            iVar9 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            gui_utf_draw(0,(char *)&local_80,0,iVar8 + 0x20e,uVar3 + 1,iVar9 + 0x23a,uVar4 + 0x1c,1,
                         0,0,(undefined *)0x0,0);
          }
          iVar10 = uVar18 * 0x7f2;
          iVar8 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          gui_utf_draw(0,(char *)(iVar10 + 0x2000e108),0,iVar8 + 0xd6,(uint)uVar3,iVar9 + 0x202,
                       uVar4 + 0x1b,1,0,0,(undefined *)0x0,0);
          iVar8 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          gui_utf_draw(0,(char *)(iVar10 + 0x2000e128),0,iVar8 + 0xba,uVar3 + 0x1b,iVar9 + 0x234,
                       uVar4 + 0x36,1,0,0,(undefined *)0x0,0);
          iVar8 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          gui_utf_draw_align_right
                    (0,(char *)(iVar10 + 0x2000e168),0,iVar8 + 0x182,uVar3 + 0x36,iVar9 + 0x234,
                     uVar4 + 0x51,1,0,0,(undefined *)0x0,0);
          iVar8 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          gui_utf_draw_align_right
                    (0,(char *)(iVar10 + 0x2000e178),0,iVar8 + 0x182,uVar3 + 0x51,iVar9 + 0x234,
                     uVar4 + 0x6c,1,0,0,(undefined *)0x0,0);
          iVar8 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          gui_utf_draw_align_right
                    (0,(char *)(iVar10 + 0x2000e188),0,iVar8 + 0x182,uVar3 + 0x6c,iVar9 + 0x234,
                     uVar4 + 0x87,1,0,0,(undefined *)0x0,0);
          iVar8 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          iVar9 = iVar9 + 0x172;
          uVar18 = iVar8 + 0xba;
LAB_00039d7e:
          gui_bitmap_draw(uVar18,uVar3 + 0x36,iVar9,uVar4 + 0x88,iVar10 + 0x2000e198,0xf);
          return;
        }
        if (DAT_20004b19 != '\x01') {
          DAT_20004b19 = cVar2;
          iVar8 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          iVar10 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          gui_area_clear(iVar8 + 0xae,uVar3 + 4,iVar10 + 0x23c,uVar4 + 0x88);
        }
        if (iVar9 == 0) {
          cleanStocksIndex();
        }
        if (2 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): db_info->stocks_disp_mode = %d\n","DashBoard_Reflash",
                   (uint)*(byte *)(param_1 + 0x69));
          }
          else {
            ble_printk("%s(): db_info->stocks_disp_mode = %d\n");
          }
        }
        iVar8 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        uVar18 = 0x43;
LAB_0003b190:
        gui_bmp_bitmap_draw(uVar18,iVar8 + 0xba,uVar3 + 2,0,0,0);
        pcVar12 = get_string(0x4b);
        iVar8 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        gui_utf_draw_middle(0,pcVar12,0,iVar8 + 0xb8,uVar3 + 0x2a,iVar9 + 0x234,uVar4 + 0x45,1,0,0,
                            (undefined *)0x0,0);
        pcVar12 = get_string(0x4c);
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        iVar8 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        iVar9 = iVar9 + 0xb8;
LAB_00039af2:
        iVar10 = uVar3 + 0x60;
        iVar8 = iVar8 + 0x234;
        iVar13 = uVar4 + 0x45;
        uVar18 = 1;
        goto LAB_000399e2;
      case 2:
        iVar8 = 0;
        local_80 = 0;
        iVar9 = 0;
        memset(local_7c,0,0x1c);
        do {
          if ((&DAT_20011281)[iVar9 * 0x159] == '\x01') {
            if (2 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): news num.%d is vaild\n","DashBoard_Reflash",iVar9);
              }
              else {
                ble_printk("%s(): news num.%d is vaild\n");
              }
            }
            iVar8 = iVar8 + 1;
          }
          iVar9 = iVar9 + 1;
        } while (iVar9 != 4);
        cVar2 = *(char *)(param_1 + 0x6a);
        if (cVar2 == '\0') {
          if (DAT_20004b1a != '\0') {
            DAT_20004b1a = cVar2;
            iVar9 = FUN_000809e2();
            uVar3 = FUN_00080a3a();
            iVar10 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            gui_area_clear(iVar9 + 0xae,uVar3 + 4,iVar10 + 0x23c,uVar4 + 0x88);
          }
          if (iVar8 == 0) {
            cleanNewsIndex();
          }
          iVar8 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          uVar18 = 0x47;
          iVar8 = iVar8 + 0xba;
LAB_0003b5b4:
          gui_bmp_bitmap_draw(uVar18,iVar8,uVar3 + 2,0,0,0);
          pcVar12 = get_string(0x4d);
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          iVar8 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          uVar18 = 1;
          iVar10 = uVar3 + 0x51;
        }
        else {
          if (cVar2 == '\x01') {
            if (DAT_20004b1a != '\x01') {
              DAT_20004b1a = cVar2;
              iVar9 = FUN_000809e2();
              uVar3 = FUN_00080a3a();
              iVar10 = FUN_000809e2();
              uVar4 = FUN_00080a3a();
              gui_area_clear(iVar9 + 0xae,uVar3 + 4,iVar10 + 0x23c,uVar4 + 0x88);
            }
            if (iVar8 == 0) {
              cleanNewsIndex();
            }
            iVar8 = FUN_000809e2();
            uVar3 = FUN_00080a3a();
            uVar18 = 0x47;
            goto LAB_0003b190;
          }
          if (cVar2 != '\x04') {
            if (cVar2 != '\x02') {
              return;
            }
            if (DAT_20004b1a != '\x02') {
              DAT_20004b1a = cVar2;
              iVar9 = FUN_000809e2();
              uVar3 = FUN_00080a3a();
              iVar10 = FUN_000809e2();
              uVar4 = FUN_00080a3a();
              gui_area_clear(iVar9 + 0xae,uVar3 + 4,iVar10 + 0x23c,uVar4 + 0x88);
            }
            if (2 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): total news num = %d\n","DashBoard_Reflash",iVar8);
              }
              else {
                ble_printk("%s(): total news num = %d\n");
              }
            }
            DAT_20004afe = (char)iVar8;
            iVar9 = FUN_000809e2();
            uVar3 = FUN_00080a3a();
            gui_bmp_bitmap_draw(0x47,iVar9 + 0xba,uVar3 + 2,0,0,0);
            if (iVar8 != 0) {
              DAT_20004b03 = '\x01';
              memset(&local_80,0,0x20);
              snprintf((char *)&local_80,0x20,"%d/%d",DAT_20004afd + 1,iVar8);
              uVar18 = (uint)DAT_20004afd;
              iVar9 = FUN_000809e2();
              uVar3 = FUN_00080a3a();
              iVar10 = FUN_000809e2();
              uVar4 = FUN_00080a3a();
              gui_utf_draw(0,(char *)(uVar18 * 0x159 + 0x20011282),0,iVar9 + 0xd6,uVar3 + 1,
                           iVar10 + 0x200,uVar4 + 0x1c,1,0,0,(undefined *)0x0,0);
              if (iVar8 == 1) {
                iVar8 = FUN_000809e2();
                uVar4 = FUN_00080a3a();
                iVar9 = FUN_000809e2();
                uVar3 = FUN_00080a3a();
                pcVar12 = " ";
              }
              else {
                iVar8 = FUN_000809e2();
                uVar4 = FUN_00080a3a();
                iVar9 = FUN_000809e2();
                uVar3 = FUN_00080a3a();
                pcVar12 = (char *)&local_80;
              }
              gui_utf_draw(0,pcVar12,0,iVar8 + 0x216,uVar4 + 1,iVar9 + 0x23a,uVar3 + 0x1c,1,0,0,
                           (undefined *)0x0,0);
              iVar8 = FUN_000809e2();
              uVar3 = FUN_00080a3a();
              iVar9 = FUN_000809e2();
              uVar4 = FUN_00080a3a();
              iVar9 = iVar9 + 0x236;
              iVar10 = uVar4 + 0x88;
              iVar13 = uVar3 + 0x1c;
              iVar8 = iVar8 + 0xba;
              pcVar12 = (char *)(uVar18 * 0x159 + 0x200112c2);
              goto LAB_0003a208;
            }
            iVar9 = FUN_000806de(&DAT_2000aa10);
            if ((-1 < iVar9 << 0x1e) || (DAT_20004b03 != '\x01')) goto LAB_0003a10c;
            DAT_20004b03 = (char)iVar8;
            pGVar6 = __get_dashboard_state();
            iVar8 = FUN_000809e2();
            uVar3 = FUN_00080a3a();
            iVar9 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            _clean_fb_data((byte *)&(pGVar6->jdb_panel_context).__panel_buffer,0,iVar8 + 0xd4,
                           uVar3 + 1,iVar9 + 0x23c,uVar4 + 0x1c);
            pGVar6 = __get_dashboard_state();
            uVar19 = (pGVar6->jdb_panel_context).current_row;
            pGVar6 = __get_dashboard_state();
            uVar20 = (pGVar6->jdb_panel_context).current_column;
            iVar8 = FUN_000809e2();
            uVar3 = FUN_00080a3a();
            iVar9 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            _reflash_fb_data_to_lcd(uVar19,uVar20,iVar8 + 0xd4,uVar3 + 1,iVar9 + 0x23c,uVar4 + 0x1c)
            ;
            pGVar6 = __get_dashboard_state();
            iVar8 = FUN_000809e2();
            uVar3 = FUN_00080a3a();
            iVar9 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            _clean_fb_data((byte *)&(pGVar6->jdb_panel_context).__panel_buffer,0,iVar8 + 0xba,
                           uVar3 + 0x1c,iVar9 + 0x234,uVar4 + 0x88);
            pGVar6 = __get_dashboard_state();
            uVar19 = (pGVar6->jdb_panel_context).current_row;
            pGVar6 = __get_dashboard_state();
            uVar20 = (pGVar6->jdb_panel_context).current_column;
            iVar8 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            iVar9 = FUN_000809e2();
            uVar3 = FUN_00080a3a();
            iVar9 = iVar9 + 0x234;
            iVar8 = iVar8 + 0xba;
LAB_0003a104:
            _reflash_fb_data_to_lcd(uVar19,uVar20,iVar8,uVar4 + 0x1c,iVar9,uVar3 + 0x88);
LAB_0003a10c:
            cleanNewsIndex();
            return;
          }
          if (DAT_20004b1a != '\x04') {
            DAT_20004b1a = '\x04';
            iVar9 = FUN_000809e2();
            uVar3 = FUN_00080a3a();
            iVar10 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            gui_area_clear(iVar9 + 0xae,uVar3 + 4,iVar10 + 0x23c,uVar4 + 0x88);
          }
          if (iVar8 == 0) {
            cleanNewsIndex();
          }
          iVar8 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          gui_bmp_bitmap_draw(0x47,iVar8 + 0xba,uVar3 + 2,0,0,0);
          pcVar12 = get_string(0x51);
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          iVar8 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          uVar18 = 2;
          iVar10 = uVar3 + 0x6c;
        }
        iVar13 = uVar4 + 0x36;
        break;
      case 3:
        if ((DAT_20004b18 != *(char *)(param_1 + 0x67)) || (DAT_20004aff != DAT_20004b00)) {
          DAT_20004aff = DAT_20004b00;
          DAT_20004b18 = *(char *)(param_1 + 0x67);
          iVar8 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          gui_area_clear(iVar8 + 0x20e,uVar3 + 2,iVar9 + 0x234,uVar4 + 0x1d);
          iVar8 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          gui_area_clear(iVar8 + 0xb8,uVar3 + 0x3b,iVar9 + 0x23e,uVar4 + 0x88);
        }
        iVar8 = 0;
        iVar9 = 0;
        do {
          if ((&DAT_2001252f)[iVar8 * 0xa4] == '\x01') {
            if (2 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): news num.%d is vaild\n","DashBoard_Reflash",iVar8);
              }
              else {
                ble_printk("%s(): news num.%d is vaild\n");
              }
            }
            iVar9 = iVar9 + 1;
          }
          iVar8 = iVar8 + 1;
        } while (iVar8 != 8);
        if (2 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): total calendar num = %d\n","DashBoard_Reflash",iVar9);
          }
          else {
            ble_printk("%s(): total calendar num = %d\n");
          }
        }
        DAT_20004b01 = ((byte)iVar9 & 1) + (char)(iVar9 >> 1);
        if (DAT_20004b18 == '\0') {
          pcVar12 = get_string(0x4d);
          iVar9 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          iVar10 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          iVar8 = uVar4 + 0x51;
          iVar13 = uVar3 + 0x36;
        }
        else if (DAT_20004b18 == '\x01') {
          pcVar12 = get_string(0x4b);
          iVar8 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          gui_utf_draw_middle(0,pcVar12,0,iVar8 + 0xb8,uVar3 + 0x2a,iVar9 + 0x234,uVar4 + 0x45,1,0,0
                              ,(undefined *)0x0,0);
          pcVar12 = get_string(0x4c);
          iVar9 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          iVar10 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          iVar8 = uVar4 + 0x60;
          iVar13 = uVar3 + 0x45;
        }
        else {
          if (DAT_20004b18 != '\x02') {
            if (DAT_20004b18 != '\x03') {
              return;
            }
            iVar8 = FUN_000809e2();
            uVar3 = FUN_00080a3a();
            gui_bmp_bitmap_draw(0x39,iVar8 + 0xba,uVar3 + 1,0,0,0);
            pcVar12 = get_string(0x4e);
            iVar8 = FUN_000809e2();
            uVar3 = FUN_00080a3a();
            iVar9 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            gui_utf_draw(0,pcVar12,0,iVar8 + 0xd6,(uint)uVar3,iVar9 + 0x13a,uVar4 + 0x1b,1,0,0,
                         (undefined *)0x0,0);
            uVar18 = (uint)DAT_20004b01;
            if (uVar18 == 0) {
              return;
            }
            local_80 = 0;
            memset(local_7c,0,0x1c);
            snprintf((char *)&local_80,0x20,"%d/%d",DAT_20004b00 + 1,uVar18);
            iVar8 = FUN_000809e2();
            uVar3 = FUN_00080a3a();
            iVar9 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            gui_utf_draw(0,(char *)&local_80,0,iVar8 + 0x216,uVar3 + 1,iVar9 + 0x23a,uVar4 + 0x1c,1,
                         0,0,(undefined *)0x0,0);
            uVar18 = (uint)DAT_20004b00;
            iVar8 = FUN_000809e2();
            uVar3 = FUN_00080a3a();
            iVar9 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            gui_utf_draw(0,&DAT_20012530 + uVar18 * 0x148,0,iVar8 + 0xba,uVar3 + 0x1b,iVar9 + 0x236,
                         uVar4 + 0x36,1,0,0,(undefined *)0x0,0);
            uVar18 = (uint)DAT_20004b00;
            iVar8 = FUN_000809e2();
            uVar3 = FUN_00080a3a();
            iVar9 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            gui_utf_draw(0,&DAT_20012571 + uVar18 * 0x148,0,iVar8 + 0xba,uVar3 + 0x36,iVar9 + 0x15e,
                         uVar4 + 0x51,1,0,0,(undefined *)0x0,0);
            uVar18 = (uint)DAT_20004b00;
            iVar8 = FUN_000809e2();
            uVar3 = FUN_00080a3a();
            iVar9 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            gui_utf_draw_align_right
                      (0,&DAT_20012592 + uVar18 * 0x148,0,iVar8 + 0x162,uVar3 + 0x36,iVar9 + 0x234,
                       uVar4 + 0x51,1,0,0,(undefined *)0x0,0);
            iVar8 = ((short)(ushort)DAT_20004b00 * 2 + 1) * 0xa4;
            if ((&DAT_2001252f)[iVar8] != '\x01') {
              return;
            }
            iVar9 = FUN_000809e2();
            uVar3 = FUN_00080a3a();
            iVar10 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            gui_utf_draw(0,&DAT_20012530 + iVar8,0,iVar9 + 0xba,uVar3 + 0x51,iVar10 + 0x236,
                         uVar4 + 0x6c,1,0,0,(undefined *)0x0,0);
            uVar3 = (ushort)DAT_20004b00;
            iVar8 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            iVar9 = FUN_000809e2();
            uVar5 = FUN_00080a3a();
            gui_utf_draw(0,&DAT_20012571 + ((short)uVar3 * 2 + 1) * 0xa4,0,iVar8 + 0xba,uVar4 + 0x6c
                         ,iVar9 + 0x15e,uVar5 + 0x87,1,0,0,(undefined *)0x0,0);
            uVar3 = (ushort)DAT_20004b00;
            iVar8 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            iVar9 = FUN_000809e2();
            uVar5 = FUN_00080a3a();
            gui_utf_draw_align_right
                      (0,&DAT_20012592 + ((short)uVar3 * 2 + 1) * 0xa4,0,iVar8 + 0x162,uVar4 + 0x6c,
                       iVar9 + 0x234,uVar5 + 0x87,1,0,0,(undefined *)0x0,0);
            return;
          }
          iVar8 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          gui_bmp_bitmap_draw(0x39,iVar8 + 0xba,uVar3 + 1,0,0,0);
          pcVar12 = get_string(0x4e);
          iVar8 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          gui_utf_draw(0,pcVar12,0,iVar8 + 0xd6,(uint)uVar3,iVar9 + 0x13a,uVar4 + 0x1b,1,0,0,
                       (undefined *)0x0,0);
          pcVar12 = get_string(0x4a);
          iVar9 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          iVar10 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          iVar8 = uVar4 + 0x51;
          iVar13 = uVar3 + 0x36;
        }
        gui_utf_draw_middle(0,pcVar12,0,iVar9 + 0xb8,iVar13,iVar10 + 0x234,iVar8,1,0,0,
                            (undefined *)0x0,0);
        cleanCalenadrIndex();
        return;
      case 4:
        cVar2 = *(char *)(param_1 + 0x6b);
        if (cVar2 == '\0') {
LAB_0003bf02:
          if (DAT_20004b1b != cVar2) {
            DAT_20004b1b = cVar2;
            iVar8 = FUN_000809e2();
            uVar3 = FUN_00080a3a();
            iVar9 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            gui_area_clear(iVar8 + 0xae,(uint)uVar3,iVar9 + 0x23c,uVar4 + 0x88);
          }
          iVar8 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          uVar18 = 0x48;
          iVar8 = iVar8 + 0xb8;
          goto LAB_0003b5b4;
        }
        if (DAT_20004b1c == '\0') {
          if (DAT_2001111d == '\0') goto LAB_0003bf02;
          if (cVar2 != '\x01') {
            if (cVar2 != '\x03') {
              return;
            }
            if (DAT_2001111d != '\x01') {
              return;
            }
            if (0x158 < *(ushort *)(param_1 + 0x6d)) {
              return;
            }
            if (0x68 < *(ushort *)(param_1 + 0x6f)) {
              return;
            }
            goto LAB_0003bf7e;
          }
        }
        else if (cVar2 != '\x01') {
          if (cVar2 != '\x03') {
            return;
          }
          if (DAT_2001111d != '\x01') {
            return;
          }
          if (*(char *)(param_1 + 0x71) != '\x03') {
            return;
          }
          if (0x158 < *(ushort *)(param_1 + 0x6d)) {
            return;
          }
          if (0x68 < *(ushort *)(param_1 + 0x6f)) {
            return;
          }
          if (DAT_20004b1c == '\x01') {
            *(undefined1 *)(param_1 + 0x71) = 0;
            pGVar6 = __get_dashboard_state();
            pGVar6->dashboard_ts->field_0x71 = 0;
          }
LAB_0003bf7e:
          if (DAT_20004b1b != *(char *)(param_1 + 0x6b)) {
            DAT_20004b1b = *(char *)(param_1 + 0x6b);
            iVar8 = FUN_000809e2();
            uVar3 = FUN_00080a3a();
            iVar9 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            gui_area_clear(iVar8 + 0xae,(uint)uVar3,iVar9 + 0x23c,uVar4 + 0x88);
          }
          iVar8 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          gui_bitmap_draw(iVar8 + 0xb8,(uint)uVar3,iVar9 + 0x230,uVar4 + 0x88,0x200143cf,2);
          iVar8 = FUN_000809e2();
          uVar18 = iVar8 + 0xb8 + (uint)*(ushort *)(param_1 + 0x6d);
          uVar3 = FUN_00080a3a();
          iVar10 = (uint)*(ushort *)(param_1 + 0x6f) + (uint)uVar3;
          iVar8 = FUN_000809e2();
          uVar3 = *(ushort *)(param_1 + 0x6d);
          uVar4 = FUN_00080a3a();
          iVar9 = (uint)uVar3 + iVar8 + 0xd8;
          iVar8 = (uint)*(ushort *)(param_1 + 0x6f) + (uint)uVar4;
          puVar14 = &DAT_20015cc7;
LAB_0003a3c2:
          gui_1bit_bitmap_override(uVar18,iVar10,iVar9,iVar8 + 0x20,(int)puVar14,0xf);
          return;
        }
        if (DAT_20004b1b != '\x01') {
          DAT_20004b1b = '\x01';
          iVar8 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          gui_area_clear(iVar8 + 0xae,(uint)uVar3,iVar9 + 0x23c,uVar4 + 0x88);
        }
        iVar8 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        gui_bmp_bitmap_draw(0x48,iVar8 + 0xb8,uVar3 + 2,0,0,0);
        pcVar12 = get_string(0x50);
        iVar9 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        iVar8 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        iVar10 = uVar4 + 0x60;
        uVar18 = 2;
        iVar13 = uVar3 + 0x2a;
        break;
      default:
        goto switchD_0003b01c_default;
      }
      iVar9 = iVar9 + 0xb8;
      goto LAB_000399e0;
    }
    pdVar7 = (dashboard_ts_context *)FUN_00080732();
    __init_burial_point_date(pdVar7,(undefined2 *)&local_a0);
    iVar8 = FUN_000807aa(local_a0 & 0xffff,local_a0 >> 0x10,local_9c & 0xffff);
    pcVar12 = get_string(iVar8 + 0x28U & 0xff);
    local_94 = 0;
    memset(local_90,0,0x10);
    uVar16 = local_9c & 0xffff;
    uVar18 = local_a0 >> 0x10;
    if (*(char *)(param_1 + 0x5f) == '\0') {
      pcVar17 = "%s, %02d/%02d";
      uVar21 = uVar18;
      uVar18 = uVar16;
    }
    else {
      uVar21 = uVar16;
      if (*(char *)(param_1 + 0x5f) == '\x01') {
        pcVar17 = "%s, %02d-%02d";
      }
      else {
        pcVar17 = "%s, %02d/%02d";
      }
    }
    __sprintf_chk((char *)&local_94,0,0x14,pcVar17,pcVar12,uVar21,uVar18);
    iVar8 = FUN_000809e2();
    uVar3 = FUN_00080a3a();
    iVar9 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    gui_utf_draw(0,(char *)&local_94,3,iVar8,(uint)uVar3,iVar9 + 0x8c,uVar4 + 0x1b,1,0,0,
                 (undefined *)0x0,0);
    pGVar6 = __get_dashboard_state();
    iVar8 = pGVar6->dashboard_ts->time_disp_mode;
    pdVar7 = (dashboard_ts_context *)FUN_00080732();
    iVar9 = FUN_000809e2();
    uVar3 = FUN_00080a3a();
    iVar10 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    gui_clock_draw(pdVar7,iVar9,uVar3 + 0x34,iVar10 + 0x96,uVar4 + 0x55,1,(char)iVar8 != '\x01');
    if (param_3 == 1) {
      iVar8 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      gui_bmp_bitmap_draw(0x3e,iVar8,uVar3 + 0x6d,0,0,0);
      if (*(char *)(param_1 + 0x60) == '\x01') {
        iVar8 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        gui_bmp_bitmap_draw(0x42,iVar8 + 0x60,uVar3 + 0x6d,0,0,0);
      }
      else {
        pGVar6 = __get_dashboard_state();
        iVar8 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        _clean_fb_data((byte *)&(pGVar6->jdb_panel_context).__panel_buffer,0,iVar8 + 0x60,
                       uVar3 + 0x6d,iVar9 + 0x78,uVar4 + 0x88);
        pGVar6 = __get_dashboard_state();
        uVar19 = (pGVar6->jdb_panel_context).current_row;
        pGVar6 = __get_dashboard_state();
        uVar20 = (pGVar6->jdb_panel_context).current_column;
        iVar8 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        _reflash_fb_data_to_lcd(uVar19,uVar20,iVar8 + 0x60,uVar3 + 0x6d,iVar9 + 0x78,uVar4 + 0x88);
      }
      iVar8 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      gui_bmp_bitmap_draw(0x5a,iVar8 + 0x23e,uVar3 + 4,0,0,0);
      iVar8 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      gui_bmp_bitmap_draw(0x59,iVar8 + 0xac,uVar3 + 4,0,0,0);
    }
    else if (param_3 != 4) {
      return;
    }
    uVar18 = (uint)PANE_MODE;
    if (uVar18 == 0) {
      local_80 = uVar18;
      memset(local_7c,0,0x1c);
      iVar9 = 0;
      iVar8 = 0;
      do {
        if (*(char *)(iVar9 * 0x143 + *(int *)(param_2 + 0x1030) + 3) == '\x01') {
          if (2 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): quick note num.%d is vaild\n","DashBoard_Reflash",iVar9);
            }
            else {
              ble_printk("%s(): quick note num.%d is vaild\n");
            }
          }
          iVar8 = iVar8 + 1;
        }
        iVar9 = iVar9 + 1;
      } while (iVar9 != 4);
      goto LAB_0003aba8;
    }
    switch(uVar18) {
    case 1:
      iVar8 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      iVar9 = uVar3 + 2;
      uVar18 = 0x43;
      iVar8 = iVar8 + 0xba;
      break;
    case 2:
      iVar8 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      iVar9 = uVar3 + 2;
      uVar18 = 0x47;
      iVar8 = iVar8 + 0xba;
      break;
    case 3:
      iVar8 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      iVar9 = uVar3 + 2;
      uVar18 = 0x39;
      iVar8 = iVar8 + 0xba;
      break;
    case 4:
      iVar8 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      iVar9 = uVar3 + 2;
      uVar18 = 0x48;
      iVar8 = iVar8 + 0xba;
      break;
    default:
      goto switchD_0003c4b2_default;
    }
    gui_bmp_bitmap_draw(uVar18,iVar8,iVar9,0,0,0);
switchD_0003c4b2_default:
    get_current_language();
    pcVar12 = get_string(0x4f);
    iVar9 = FUN_000809e2();
    uVar3 = FUN_00080a3a();
    iVar8 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    iVar8 = iVar8 + 0x234;
    iVar9 = iVar9 + 0xb8;
LAB_0003a9be:
    iVar10 = uVar4 + 0x6c;
    iVar13 = uVar3 + 0x36;
    uVar18 = 2;
  }
  else {
    if (param_4 == 2) {
      if (((DAT_20004b14 != uVar18) || (DAT_20004b11 != '\x02')) ||
         (PANE_MODE != *(byte *)(param_1 + 0x66))) {
        gui_screen_clear();
        PANE_MODE = *(byte *)(param_1 + 0x66);
        DAT_20004b11 = *(char *)(param_1 + 0x65);
        DAT_20004b14 = uVar18;
        if (2 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): display_mode = %d ,exec screen clear\n","DashBoard_Reflash");
          }
          else {
            ble_printk("%s(): display_mode = %d ,exec screen clear\n");
          }
        }
      }
      if (uVar18 == 1) {
        if (param_3 == 1) {
          if (*(char *)(param_1 + 0x60) == '\x01') {
            if (DAT_20002f88 != 0) {
              DAT_20002f88 = 0;
              pGVar6 = __get_dashboard_state();
              iVar8 = FUN_000809e2();
              uVar3 = FUN_00080a3a();
              iVar9 = FUN_000809e2();
              uVar4 = FUN_00080a3a();
              _clean_fb_data((byte *)&(pGVar6->jdb_panel_context).__panel_buffer,0,iVar8,
                             uVar3 + 0x1c,iVar9 + 0x240,uVar4 + 0x37);
              pGVar6 = __get_dashboard_state();
              uVar19 = (pGVar6->jdb_panel_context).current_row;
              pGVar6 = __get_dashboard_state();
              uVar20 = (pGVar6->jdb_panel_context).current_column;
              iVar8 = FUN_000809e2();
              uVar3 = FUN_00080a3a();
              iVar9 = FUN_000809e2();
              uVar4 = FUN_00080a3a();
              _reflash_fb_data_to_lcd(uVar19,uVar20,iVar8,uVar3 + 0x1c,iVar9 + 0x240,uVar4 + 0x37);
            }
            iVar8 = FUN_000809e2();
            uVar3 = FUN_00080a3a();
            gui_bmp_bitmap_draw(0x42,iVar8 + 0x1b8,uVar3 + 0x1c,0,0,0);
          }
          else if (DAT_20002f88 != 0x16) {
            DAT_20002f88 = 0x16;
            pGVar6 = __get_dashboard_state();
            iVar8 = FUN_000809e2();
            uVar3 = FUN_00080a3a();
            iVar9 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            _clean_fb_data((byte *)&(pGVar6->jdb_panel_context).__panel_buffer,0,iVar8,uVar3 + 0x1c,
                           iVar9 + 0x240,uVar4 + 0x37);
            pGVar6 = __get_dashboard_state();
            uVar19 = (pGVar6->jdb_panel_context).current_row;
            pGVar6 = __get_dashboard_state();
            uVar20 = (pGVar6->jdb_panel_context).current_column;
            iVar8 = FUN_000809e2();
            uVar3 = FUN_00080a3a();
            iVar9 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            _reflash_fb_data_to_lcd(uVar19,uVar20,iVar8,uVar3 + 0x1c,iVar9 + 0x240,uVar4 + 0x37);
          }
          if (2 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): weather icon num = %d\n","DashBoard_Reflash",
                     (uint)*(byte *)(param_1 + 4));
            }
            else {
              ble_printk("%s(): weather icon num = %d\n");
            }
          }
          local_80 = 0;
          local_7c[0] = 0;
          if ((*(byte *)(param_1 + 4) - 1 & 0xff) < 0xfe) {
            uVar18 = FUN_0004916c((uint)*(byte *)(param_1 + 4));
            iVar8 = FUN_000809e2();
            uVar16 = (uint)DAT_20002f88;
            uVar3 = FUN_00080a3a();
            gui_bmp_bitmap_draw(uVar18,uVar16 + iVar8 + 0x100,uVar3 + 0x1c,0,0,0);
            pGVar6 = __get_dashboard_state();
            iVar8 = (int)*(char *)(param_1 + 5);
            local_80 = (uint)(byte)pGVar6->dashboard_ts->field_0x5d;
            if (local_80 == 0) {
              local_7c[0] = local_80;
              if (2 < LOG_LEVEL) {
                if (BLE_DEBUG == 0) {
                  printk("%s(): temperature = %d\n","DashBoard_Reflash",iVar8);
                }
                else {
                  ble_printk("%s(): temperature = %d\n");
                }
              }
              snprintf((char *)&local_80,8,"%d",iVar8);
              local_94 = 0;
              iVar8 = FUN_000809e2();
              uVar16 = (uint)DAT_20002f88;
              uVar3 = FUN_00080a3a();
              iVar9 = FUN_000809e2();
              uVar18 = (uint)DAT_20002f88;
              uVar4 = FUN_00080a3a();
              gui_string_draw(3,(byte *)&local_80,uVar16 + iVar8 + 0x11c,uVar3 + 0x1c,
                              uVar18 + iVar9 + 0x144,uVar4 + 0x37,(int *)&local_94);
              bVar15 = 0x2a;
            }
            else {
              local_80 = 0;
              local_7c[0] = 0;
              iVar8 = (iVar8 * 9) / 5 + 0x20;
              if (2 < LOG_LEVEL) {
                if (BLE_DEBUG == 0) {
                  printk("%s(): fahrenheit_temperature = %d\n","DashBoard_Reflash",iVar8);
                }
                else {
                  ble_printk("%s(): fahrenheit_temperature = %d\n");
                }
              }
              snprintf((char *)&local_80,8,"%d",iVar8);
              local_94 = 0;
              iVar8 = FUN_000809e2();
              uVar16 = (uint)DAT_20002f88;
              uVar3 = FUN_00080a3a();
              iVar9 = FUN_000809e2();
              uVar18 = (uint)DAT_20002f88;
              uVar4 = FUN_00080a3a();
              gui_string_draw(3,(byte *)&local_80,uVar16 + iVar8 + 0x11c,uVar3 + 0x1c,
                              uVar18 + iVar9 + 0x144,uVar4 + 0x37,(int *)&local_94);
              bVar15 = 0x23;
            }
            local_7c[0] = 0;
            local_80 = (uint)bVar15;
            iVar8 = FUN_000809e2();
            iVar9 = (uint)DAT_20002f88 + iVar8 + 0x11c + local_94;
            uVar3 = FUN_00080a3a();
            iVar8 = FUN_000809e2();
            iVar8 = (uint)DAT_20002f88 + iVar8 + local_94;
            uVar4 = FUN_00080a3a();
            gui_string_draw(3,(byte *)&local_80,iVar9,uVar3 + 0x1c,iVar8 + 299,uVar4 + 0x37,
                            (int *)0x0);
          }
          iVar8 = FUN_000809e2();
          uVar18 = (uint)DAT_20002f88;
          uVar3 = FUN_00080a3a();
          gui_bmp_bitmap_draw(0x3c,iVar8 + 0x16e + uVar18,uVar3 + 0x1c,0,0,0);
          uVar18 = FUN_00035310();
          if ((int)uVar18 < 0xb) {
            pcVar12 = "%d";
          }
          else {
            uVar18 = 10;
            pcVar12 = "%d+";
          }
          local_80 = 0;
          local_7c[0] = 0;
          snprintf((char *)&local_80,8,pcVar12,uVar18);
          iVar8 = FUN_000809e2();
          uVar16 = (uint)DAT_20002f88;
          uVar3 = FUN_00080a3a();
          iVar9 = FUN_000809e2();
          uVar18 = (uint)DAT_20002f88;
          uVar4 = FUN_00080a3a();
          gui_string_draw(3,(byte *)&local_80,uVar16 + iVar8 + 0x18a,uVar3 + 0x1c,
                          uVar18 + iVar9 + 0x1a4,uVar4 + 0x37,(int *)0x0);
        }
        local_94 = 0;
        local_90[0] = 0;
        local_90[1] = 0;
        pdVar7 = (dashboard_ts_context *)FUN_00080732();
        __init_burial_point_date(pdVar7,(undefined2 *)&local_94);
        iVar8 = FUN_000807aa(local_94 & 0xffff,local_94 >> 0x10,local_90[0] & 0xffff);
        pcVar12 = get_string(iVar8 + 0x28U & 0xff);
        local_80 = 0;
        memset(local_7c,0,0x10);
        uVar16 = local_90[0] & 0xffff;
        uVar18 = local_94 >> 0x10;
        if (*(char *)(param_1 + 0x5f) == '\0') {
          pcVar17 = "%s, %02d/%02d";
          uVar21 = uVar18;
          uVar18 = uVar16;
        }
        else {
          uVar21 = uVar16;
          if (*(char *)(param_1 + 0x5f) == '\x01') {
            pcVar17 = "%s, %02d-%02d";
          }
          else {
            pcVar17 = "%s, %02d/%02d";
          }
        }
        __sprintf_chk((char *)&local_80,0,0x14,pcVar17,pcVar12,uVar21,uVar18);
        iVar8 = FUN_000809e2();
        uVar18 = (uint)DAT_20002f88;
        uVar3 = FUN_00080a3a();
        iVar9 = FUN_000809e2();
        uVar18 = uVar18 + iVar8 + 0x54;
        iVar8 = (uint)DAT_20002f88 + iVar9 + 0xe0;
      }
      else {
        if (param_3 == 1) {
          if (*(char *)(param_1 + 0x60) == '\x01') {
            if (DAT_20002f88 != 0) {
              DAT_20002f88 = 0;
              pGVar6 = __get_dashboard_state();
              iVar8 = FUN_000809e2();
              uVar3 = FUN_00080a3a();
              iVar9 = FUN_000809e2();
              uVar4 = FUN_00080a3a();
              _clean_fb_data((byte *)&(pGVar6->jdb_panel_context).__panel_buffer,0,iVar8,
                             uVar3 + 0x1c,iVar9 + 0x240,uVar4 + 0x37);
              pGVar6 = __get_dashboard_state();
              uVar19 = (pGVar6->jdb_panel_context).current_row;
              pGVar6 = __get_dashboard_state();
              uVar20 = (pGVar6->jdb_panel_context).current_column;
              iVar8 = FUN_000809e2();
              uVar3 = FUN_00080a3a();
              iVar9 = FUN_000809e2();
              uVar4 = FUN_00080a3a();
              _reflash_fb_data_to_lcd(uVar19,uVar20,iVar8,uVar3 + 0x1c,iVar9 + 0x240,uVar4 + 0x37);
            }
            iVar8 = FUN_000809e2();
            uVar3 = FUN_00080a3a();
            gui_bmp_bitmap_draw(0x42,iVar8 + 0x178,uVar3 + 0x1c,0,0,0);
          }
          else if (DAT_20002f88 != 0x16) {
            DAT_20002f88 = 0x16;
            pGVar6 = __get_dashboard_state();
            iVar8 = FUN_000809e2();
            uVar3 = FUN_00080a3a();
            iVar9 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            _clean_fb_data((byte *)&(pGVar6->jdb_panel_context).__panel_buffer,0,iVar8,uVar3 + 0x1c,
                           iVar9 + 0x240,uVar4 + 0x37);
            pGVar6 = __get_dashboard_state();
            uVar19 = (pGVar6->jdb_panel_context).current_row;
            pGVar6 = __get_dashboard_state();
            uVar20 = (pGVar6->jdb_panel_context).current_column;
            iVar8 = FUN_000809e2();
            uVar3 = FUN_00080a3a();
            iVar9 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            _reflash_fb_data_to_lcd(uVar19,uVar20,iVar8,uVar3 + 0x1c,iVar9 + 0x240,uVar4 + 0x37);
          }
          iVar8 = FUN_000809e2();
          uVar18 = (uint)DAT_20002f88;
          uVar3 = FUN_00080a3a();
          gui_bmp_bitmap_draw(0x3e,uVar18 + iVar8 + 0x144,uVar3 + 0x1c,0,0,0);
        }
        local_94 = 0;
        local_90[0] = 0;
        local_90[1] = 0;
        pdVar7 = (dashboard_ts_context *)FUN_00080732();
        __init_burial_point_date(pdVar7,(undefined2 *)&local_94);
        iVar8 = FUN_000807aa(local_94 & 0xffff,local_94 >> 0x10,local_90[0] & 0xffff);
        pcVar12 = get_string(iVar8 + 0x28U & 0xff);
        local_80 = 0;
        memset(local_7c,0,0x10);
        uVar16 = local_90[0] & 0xffff;
        uVar18 = local_94 >> 0x10;
        if (*(char *)(param_1 + 0x5f) == '\0') {
          pcVar17 = "%s, %02d/%02d";
          uVar21 = uVar18;
          uVar18 = uVar16;
        }
        else {
          uVar21 = uVar16;
          if (*(char *)(param_1 + 0x5f) == '\x01') {
            pcVar17 = "%s, %02d-%02d";
          }
          else {
            pcVar17 = "%s, %02d/%02d";
          }
        }
        __sprintf_chk((char *)&local_80,0,0x14,pcVar17,pcVar12,uVar21,uVar18);
        iVar8 = FUN_000809e2();
        uVar18 = (uint)DAT_20002f88;
        uVar3 = FUN_00080a3a();
        iVar9 = FUN_000809e2();
        uVar18 = uVar18 + iVar8 + 0x98;
        iVar8 = (uint)DAT_20002f88 + iVar9 + 0x124;
      }
      uVar4 = FUN_00080a3a();
      gui_utf_draw_align_right
                (0,(char *)&local_80,3,uVar18,uVar3 + 0x1c,iVar8,uVar4 + 0x37,1,0,0,(undefined *)0x0
                 ,0);
      pGVar6 = __get_dashboard_state();
      iVar8 = pGVar6->dashboard_ts->time_disp_mode;
      pdVar7 = (dashboard_ts_context *)FUN_00080732();
      iVar9 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      iVar10 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      gui_clock_draw(pdVar7,iVar9 + 0xea,uVar3 + 0x4c,iVar10 + 0x180,uVar4 + 0x6d,1,
                     (char)iVar8 != '\x01');
      return;
    }
    if (param_4 != 0) {
      return;
    }
    if (((DAT_20004b14 != uVar18) || (DAT_20004b11 != '\0')) ||
       (PANE_MODE != *(byte *)(param_1 + 0x66))) {
      gui_screen_clear();
      PANE_MODE = *(byte *)(param_1 + 0x66);
      DAT_20004b11 = *(char *)(param_1 + 0x65);
      DAT_20004b14 = uVar18;
      if (2 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): display_mode = %d ,exec screen clear\n","DashBoard_Reflash");
        }
        else {
          ble_printk("%s(): display_mode = %d ,exec screen clear\n");
        }
      }
    }
    local_a0 = 0;
    local_9c = 0;
    local_98 = 0;
    if (uVar18 != 1) {
      pdVar7 = (dashboard_ts_context *)FUN_00080732();
      __init_burial_point_date(pdVar7,(undefined2 *)&local_a0);
      iVar8 = FUN_000807aa(local_a0 & 0xffff,local_a0 >> 0x10,local_9c & 0xffff);
      pcVar12 = get_string(iVar8 + 0x28U & 0xff);
      local_94 = 0;
      memset(local_90,0,0x10);
      uVar16 = local_9c & 0xffff;
      uVar18 = local_a0 >> 0x10;
      if (*(char *)(param_1 + 0x5f) == '\0') {
        pcVar17 = "%s, %02d/%02d";
        uVar21 = uVar18;
        uVar18 = uVar16;
      }
      else {
        uVar21 = uVar16;
        if (*(char *)(param_1 + 0x5f) == '\x01') {
          pcVar17 = "%s, %02d-%02d";
        }
        else {
          pcVar17 = "%s, %02d/%02d";
        }
      }
      __sprintf_chk((char *)&local_94,0,0x14,pcVar17,pcVar12,uVar21,uVar18);
      iVar8 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      iVar9 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      gui_utf_draw(0,(char *)&local_94,3,iVar8 + 0x2e,(uint)uVar3,iVar9 + 0xb9,uVar4 + 0x1b,1,0,0,
                   (undefined *)0x0,0);
      pGVar6 = __get_dashboard_state();
      iVar8 = pGVar6->dashboard_ts->time_disp_mode;
      pdVar7 = (dashboard_ts_context *)FUN_00080732();
      iVar9 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      iVar10 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      gui_clock_draw(pdVar7,iVar9 + 0x2e,uVar3 + 0x34,iVar10 + 0xc3,uVar4 + 0x55,1,
                     (char)iVar8 != '\x01');
      if (param_3 == 1) {
        iVar8 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        gui_bmp_bitmap_draw(0x3e,iVar8 + 0x2e,uVar3 + 0x6d,0,0,0);
        if (*(char *)(param_1 + 0x60) == '\x01') {
          iVar8 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          gui_bmp_bitmap_draw(0x42,iVar8 + 0x8e,uVar3 + 0x6d,0,0,0);
        }
        else {
          pGVar6 = __get_dashboard_state();
          iVar8 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          _clean_fb_data((byte *)&(pGVar6->jdb_panel_context).__panel_buffer,0,iVar8 + 0x8e,
                         uVar3 + 0x6d,iVar9 + 0xa6,uVar4 + 0x88);
          pGVar6 = __get_dashboard_state();
          uVar19 = (pGVar6->jdb_panel_context).current_row;
          pGVar6 = __get_dashboard_state();
          uVar20 = (pGVar6->jdb_panel_context).current_column;
          iVar8 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          _reflash_fb_data_to_lcd(uVar19,uVar20,iVar8 + 0x8e,uVar3 + 0x6d,iVar9 + 0xa6,uVar4 + 0x88)
          ;
        }
        iVar8 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        gui_bmp_bitmap_draw(0x5a,iVar8 + 0x214,uVar3 + 4,0,0,0);
        iVar8 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        gui_bmp_bitmap_draw(0x59,iVar8 + 0xd4,uVar3 + 4,0,0,0);
      }
      else if (param_3 != 4) {
        return;
      }
      uVar18 = (uint)PANE_MODE;
      if (uVar18 == 0) {
        local_80 = uVar18;
        memset(local_7c,0,0x1c);
        iVar8 = 0;
        iVar9 = 0;
        do {
          if (*(char *)(iVar8 * 0x143 + *(int *)(param_2 + 0x1030) + 3) == '\x01') {
            if (2 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): quick note num.%d is vaild\n","DashBoard_Reflash",iVar8);
              }
              else {
                ble_printk("%s(): quick note num.%d is vaild\n");
              }
            }
            iVar9 = iVar9 + 1;
          }
          iVar8 = iVar8 + 1;
        } while (iVar8 != 4);
        if (2 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): total quick note num = %d\n","DashBoard_Reflash",iVar9);
          }
          else {
            ble_printk("%s(): total quick note num = %d\n");
          }
        }
        DAT_20004afa = (char)iVar9;
        iVar8 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        gui_bmp_bitmap_draw(0x3b,iVar8 + 0xe0,uVar3 + 2,0,0,0);
        if (iVar9 == 0) {
          iVar8 = FUN_000806de(&DAT_2000aa10);
          if ((-1 < iVar8 << 0x1e) || (DAT_20004b02 != '\x01')) goto LAB_00039194;
          DAT_20004b02 = (char)iVar9;
          pGVar6 = __get_dashboard_state();
          iVar8 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          _clean_fb_data((byte *)&(pGVar6->jdb_panel_context).__panel_buffer,0,iVar8 + 0x128,
                         uVar3 + 1,iVar9 + 0x208,uVar4 + 0x1c);
          pGVar6 = __get_dashboard_state();
          uVar19 = (pGVar6->jdb_panel_context).current_row;
          pGVar6 = __get_dashboard_state();
          uVar20 = (pGVar6->jdb_panel_context).current_column;
          iVar8 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          _reflash_fb_data_to_lcd(uVar19,uVar20,iVar8 + 0x128,uVar3 + 1,iVar9 + 0x23a,uVar4 + 0x1c);
          pGVar6 = __get_dashboard_state();
          iVar8 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          _clean_fb_data((byte *)&(pGVar6->jdb_panel_context).__panel_buffer,0,iVar8 + 0x10a,
                         uVar3 + 0x1c,iVar9 + 0x208,uVar4 + 0x88);
          pGVar6 = __get_dashboard_state();
          uVar19 = (pGVar6->jdb_panel_context).current_row;
          pGVar6 = __get_dashboard_state();
          uVar20 = (pGVar6->jdb_panel_context).current_column;
          iVar8 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          iVar9 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          iVar9 = iVar9 + 0x208;
          goto LAB_00039182;
        }
        DAT_20004b02 = '\x01';
        memset(&local_80,0,0x20);
        snprintf((char *)&local_80,0x20,"%d/%d",DAT_20004af9 + 1,iVar9);
        uVar18 = (uint)DAT_20004af9;
        iVar13 = *(int *)(param_2 + 0x1030);
        iVar8 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        iVar10 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        gui_utf_draw(0,(char *)(iVar13 + uVar18 * 0x143 + 4),0,iVar8 + 0xfc,uVar3 + 1,iVar10 + 0x1d6
                     ,uVar4 + 0x1c,1,0,0,(undefined *)0x0,0);
        if (iVar9 == 1) {
          iVar9 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          iVar8 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          pcVar12 = " ";
        }
        else {
          iVar9 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          iVar8 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          pcVar12 = (char *)&local_80;
        }
        gui_utf_draw(0,pcVar12,0,iVar9 + 0x1e4,uVar3 + 1,iVar8 + 0x212,uVar4 + 0x1c,1,0,0,
                     (undefined *)0x0,0);
        pcVar12 = (char *)(uVar18 * 0x143 + 0x2d + *(int *)(param_2 + 0x1030));
        iVar8 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        iVar9 = iVar9 + 0x208;
        iVar8 = iVar8 + 0xe0;
        goto LAB_000398be;
      }
      if (uVar18 == 1) {
        iVar8 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        iVar9 = uVar3 + 2;
        uVar18 = 0x43;
        iVar8 = iVar8 + 0xe0;
LAB_0003a97c:
        gui_bmp_bitmap_draw(uVar18,iVar8,iVar9,0,0,0);
      }
      else {
        if (uVar18 == 2) {
          iVar8 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          iVar9 = uVar3 + 2;
          uVar18 = 0x47;
          iVar8 = iVar8 + 0xe0;
          goto LAB_0003a97c;
        }
        if (uVar18 == 4) {
          iVar8 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          iVar9 = uVar3 + 2;
          uVar18 = 0x48;
          iVar8 = iVar8 + 0xe0;
          goto LAB_0003a97c;
        }
      }
      pcVar12 = get_string(0x4f);
      iVar9 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      iVar8 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      iVar8 = iVar8 + 0x20a;
      iVar9 = iVar9 + 0xe0;
      goto LAB_0003a9be;
    }
    pdVar7 = (dashboard_ts_context *)FUN_00080732();
    __init_burial_point_date(pdVar7,(undefined2 *)&local_a0);
    iVar8 = FUN_000807aa(local_a0 & 0xffff,local_a0 >> 0x10,local_9c & 0xffff);
    pcVar12 = get_string(iVar8 + 0x28U & 0xff);
    local_94 = 0;
    memset(local_90,0,0x10);
    uVar16 = local_9c & 0xffff;
    uVar18 = local_a0 >> 0x10;
    if (*(char *)(param_1 + 0x5f) == '\0') {
      pcVar17 = "%s, %02d/%02d";
      uVar21 = uVar18;
      uVar18 = uVar16;
    }
    else {
      uVar21 = uVar16;
      if (*(char *)(param_1 + 0x5f) == '\x01') {
        pcVar17 = "%s, %02d-%02d";
      }
      else {
        pcVar17 = "%s, %02d/%02d";
      }
    }
    __sprintf_chk((char *)&local_94,0,0x14,pcVar17,pcVar12,uVar21,uVar18);
    iVar8 = FUN_000809e2();
    uVar3 = FUN_00080a3a();
    iVar9 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    gui_utf_draw(0,(char *)&local_94,3,iVar8,uVar3 + 2,iVar9 + 0x8c,uVar4 + 0x1d,1,0,0,
                 (undefined *)0x0,0);
    pGVar6 = __get_dashboard_state();
    iVar8 = pGVar6->dashboard_ts->time_disp_mode;
    pdVar7 = (dashboard_ts_context *)FUN_00080732();
    iVar9 = FUN_000809e2();
    uVar3 = FUN_00080a3a();
    iVar10 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    gui_clock_draw(pdVar7,iVar9,uVar3 + 0x22,iVar10 + 0x96,uVar4 + 0x43,1,(char)iVar8 != '\x01');
    if (param_3 == 1) {
      iVar8 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      gui_bmp_bitmap_draw(0x5a,iVar8 + 0x23e,uVar3 + 4,0,0,0);
      iVar8 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      gui_bmp_bitmap_draw(0x59,iVar8 + 0xfe,uVar3 + 4,0,0,0);
      if (2 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): weather icon num = %d\n","DashBoard_Reflash",(uint)*(byte *)(param_1 + 4));
        }
        else {
          ble_printk("%s(): weather icon num = %d\n");
        }
      }
      local_a8 = 0;
      local_a4 = 0;
      if ((*(byte *)(param_1 + 4) - 1 & 0xff) < 0xfe) {
        uVar18 = FUN_0004916c((uint)*(byte *)(param_1 + 4));
        iVar8 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        gui_bmp_bitmap_draw(uVar18,iVar8 + 0xa0,uVar3 + 1,0,0,0);
        pGVar6 = __get_dashboard_state();
        iVar8 = (int)*(char *)(param_1 + 5);
        local_a8 = (uint)(byte)pGVar6->dashboard_ts->field_0x5d;
        if (local_a8 == 0) {
          local_a4 = local_a8;
          if (2 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): temperature = %d\n","DashBoard_Reflash",iVar8);
            }
            else {
              ble_printk("%s(): temperature = %d\n");
            }
          }
          snprintf((char *)&local_a8,8,"%d",iVar8);
          local_80 = 0;
          iVar8 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          gui_string_draw(3,(byte *)&local_a8,iVar8 + 0xbc,uVar3 + 1,iVar9 + 0xf8,uVar4 + 0x1c,
                          &local_80);
          bVar15 = 0x2a;
        }
        else {
          local_a8 = 0;
          local_a4 = 0;
          iVar8 = (iVar8 * 9) / 5 + 0x20;
          if (2 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): fahrenheit_temperature = %d\n","DashBoard_Reflash",iVar8);
            }
            else {
              ble_printk("%s(): fahrenheit_temperature = %d\n");
            }
          }
          snprintf((char *)&local_a8,8,"%d",iVar8);
          local_80 = 0;
          iVar8 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          gui_string_draw(3,(byte *)&local_a8,iVar8 + 0xbc,uVar3 + 1,iVar9 + 0xf8,uVar4 + 0x1c,
                          &local_80);
          bVar15 = 0x23;
        }
        local_a4 = 0;
        local_a8 = (uint)bVar15;
        iVar8 = FUN_000809e2();
        iVar9 = iVar8 + 0xbc + local_80;
        uVar3 = FUN_00080a3a();
        iVar8 = FUN_000809e2();
        iVar8 = local_80 + iVar8;
        uVar4 = FUN_00080a3a();
        gui_string_draw(3,(byte *)&local_a8,iVar9,uVar3 + 1,iVar8 + 0xcb,uVar4 + 0x1c,(int *)0x0);
      }
      iVar8 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      gui_bmp_bitmap_draw(0x3c,iVar8 + 0xa0,uVar3 + 0x25,0,0,0);
      uVar18 = FUN_00035310();
      if ((int)uVar18 < 0xb) {
        pcVar12 = "%d";
      }
      else {
        pcVar12 = "%d+";
        uVar18 = 10;
      }
      local_a8 = 0;
      local_a4 = 0;
      snprintf((char *)&local_a8,8,pcVar12,uVar18);
      iVar8 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      iVar9 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      gui_string_draw(3,(byte *)&local_a8,iVar8 + 0xbc,uVar3 + 0x25,iVar9 + 0xe8,uVar4 + 0x40,
                      (int *)0x0);
      if (*(char *)(param_1 + 0x60) == '\x01') {
        iVar8 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        gui_bmp_bitmap_draw(0x42,iVar8 + 0xdc,uVar3 + 0x25,0,0,0);
      }
      else {
        pGVar6 = __get_dashboard_state();
        iVar8 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        _clean_fb_data((byte *)&(pGVar6->jdb_panel_context).__panel_buffer,0,iVar8 + 0xdc,
                       uVar3 + 0x25,iVar9 + 0xf4,uVar4 + 0x40);
        pGVar6 = __get_dashboard_state();
        uVar19 = (pGVar6->jdb_panel_context).current_row;
        pGVar6 = __get_dashboard_state();
        uVar20 = (pGVar6->jdb_panel_context).current_column;
        iVar8 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        _reflash_fb_data_to_lcd(uVar19,uVar20,iVar8 + 0xdc,uVar3 + 0x25,iVar9 + 0xf4,uVar4 + 0x40);
      }
      iVar8 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      gui_bmp_bitmap_draw(0x39,iVar8,uVar3 + 0x56,0,0,0);
      if (DAT_20004b18 != *(char *)(param_1 + 0x67)) {
        DAT_20004b18 = *(char *)(param_1 + 0x67);
        iVar8 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        gui_area_clear(iVar8 + 0x1c,uVar3 + 0x51,iVar9 + 0xf2,uVar4 + 0x6c);
        iVar8 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        gui_area_clear(iVar8,uVar3 + 0x6c,iVar9 + 0xf2,uVar4 + 0x87);
      }
      if (DAT_20004b18 == '\0') {
        iVar8 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        gui_area_clear(iVar8 + 0x1c,uVar3 + 0x51,iVar9 + 0xf2,uVar4 + 0x6c);
        pcVar12 = get_string(0x4d);
        iVar8 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        iVar13 = uVar3 + 0x6c;
        iVar10 = uVar4 + 0x89;
        iVar9 = iVar9 + 0xf2;
      }
      else if (DAT_20004b18 == '\x01') {
        iVar8 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        gui_area_clear(iVar8 + 0x1c,uVar3 + 0x51,iVar9 + 0xf2,uVar4 + 0x6c);
        pcVar12 = get_string(0x4b);
        iVar8 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        iVar9 = iVar9 + 0xf2;
        iVar10 = uVar4 + 0x89;
        iVar13 = uVar3 + 0x6e;
      }
      else if (DAT_20004b18 == '\x02') {
        iVar8 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        gui_area_clear(iVar8 + 0x1c,uVar3 + 0x51,iVar9 + 0xf2,uVar4 + 0x6c);
        pcVar12 = get_string(0x4a);
        iVar8 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        iVar10 = uVar4 + 0x89;
        iVar13 = uVar3 + 0x6e;
        iVar9 = iVar9 + 0xf2;
      }
      else {
        if (DAT_20004b18 != '\x03') goto LAB_00038fc6;
        iVar8 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        gui_utf_draw(0,&DAT_20012530,0,iVar8 + 0x1c,uVar3 + 0x51,iVar9 + 0xf2,uVar4 + 0x6c,1,0,0,
                     (undefined *)0x0,0);
        local_80 = 0;
        memset(local_7c,0,0x54);
        sVar11 = strlen(&DAT_20012571);
        memcpy(&local_80,&DAT_20012571,sVar11);
        sVar11 = strlen(&DAT_20012571);
        *(undefined1 *)((int)local_7c + (sVar11 - 4)) = 0x20;
        n = strlen(&DAT_20012592);
        memcpy((void *)((int)local_7c + (sVar11 - 3)),&DAT_20012592,n);
        iVar8 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        iVar9 = iVar9 + 0xf2;
        iVar13 = uVar3 + 0x6c;
        iVar10 = uVar4 + 0x87;
        pcVar12 = (char *)&local_80;
      }
      gui_utf_draw(0,pcVar12,0,iVar8,iVar13,iVar9,iVar10,1,0,0,(undefined *)0x0,0);
    }
    else if (param_3 != 4) {
      return;
    }
LAB_00038fc6:
    uVar18 = (uint)PANE_MODE;
    if (uVar18 == 0) {
      local_80 = uVar18;
      memset(local_7c,0,0x1c);
      iVar8 = 0;
      iVar9 = 0;
      do {
        if (*(char *)(iVar8 * 0x143 + *(int *)(param_2 + 0x1030) + 3) == '\x01') {
          if (2 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): quick note num.%d is vaild\n","DashBoard_Reflash",iVar8);
            }
            else {
              ble_printk("%s(): quick note num.%d is vaild\n");
            }
          }
          iVar9 = iVar9 + 1;
        }
        iVar8 = iVar8 + 1;
      } while (iVar8 != 4);
      if (2 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): total quick note num = %d\n","DashBoard_Reflash",iVar9);
        }
        else {
          ble_printk("%s(): total quick note num = %d\n");
        }
      }
      DAT_20004afa = (char)iVar9;
      iVar8 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      gui_bmp_bitmap_draw(0x3b,iVar8 + 0x10a,uVar3 + 2,0,0,0);
      if (iVar9 == 0) {
        iVar8 = FUN_000806de(&DAT_2000aa10);
        if ((-1 < iVar8 << 0x1e) || (DAT_20004b02 != '\x01')) goto LAB_00039194;
        DAT_20004b02 = (char)iVar9;
        pGVar6 = __get_dashboard_state();
        iVar8 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        _clean_fb_data((byte *)&(pGVar6->jdb_panel_context).__panel_buffer,0,iVar8 + 0x128,uVar3 + 1
                       ,iVar9 + 0x23a,uVar4 + 0x1c);
        pGVar6 = __get_dashboard_state();
        uVar19 = (pGVar6->jdb_panel_context).current_row;
        pGVar6 = __get_dashboard_state();
        uVar20 = (pGVar6->jdb_panel_context).current_column;
        iVar8 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        _reflash_fb_data_to_lcd(uVar19,uVar20,iVar8 + 0x128,uVar3 + 1,iVar9 + 0x23a,uVar4 + 0x1c);
        pGVar6 = __get_dashboard_state();
        iVar8 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        _clean_fb_data((byte *)&(pGVar6->jdb_panel_context).__panel_buffer,0,iVar8 + 0x10a,
                       uVar3 + 0x1c,iVar9 + 0x232,uVar4 + 0x88);
        pGVar6 = __get_dashboard_state();
        uVar19 = (pGVar6->jdb_panel_context).current_row;
        pGVar6 = __get_dashboard_state();
        uVar20 = (pGVar6->jdb_panel_context).current_column;
        iVar8 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        iVar9 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        iVar9 = iVar9 + 0x232;
LAB_00039182:
        _reflash_fb_data_to_lcd(uVar19,uVar20,iVar8 + 0x10a,uVar4 + 0x1c,iVar9,uVar3 + 0x88);
LAB_00039194:
        FUN_00038b00();
        FUN_000386c0();
        return;
      }
      DAT_20004b02 = '\x01';
      memset(&local_80,0,0x20);
      snprintf((char *)&local_80,0x20,"%d/%d",DAT_20004af9 + 1,iVar9);
      uVar18 = (uint)DAT_20004af9;
      iVar13 = *(int *)(param_2 + 0x1030);
      iVar8 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      iVar10 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      gui_utf_draw(0,(char *)(iVar13 + uVar18 * 0x143 + 4),0,iVar8 + 0x128,uVar3 + 1,iVar10 + 0x212,
                   uVar4 + 0x1c,1,0,0,(undefined *)0x0,0);
      if (iVar9 == 1) {
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        iVar8 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        pcVar12 = " ";
      }
      else {
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        iVar8 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        pcVar12 = (char *)&local_80;
      }
      gui_utf_draw(0,pcVar12,0,iVar9 + 0x218,uVar4 + 1,iVar8 + 0x23a,uVar3 + 0x1c,1,0,0,
                   (undefined *)0x0,0);
      pcVar12 = (char *)(uVar18 * 0x143 + 0x2d + *(int *)(param_2 + 0x1030));
      iVar8 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      iVar9 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      iVar9 = iVar9 + 0x238;
      iVar8 = iVar8 + 0x10a;
LAB_000398be:
      iVar10 = uVar4 + 0x88;
      iVar13 = uVar3 + 0x1c;
      goto LAB_0003a208;
    }
    if (uVar18 == 1) {
      iVar8 = 0;
      iVar9 = 0;
      do {
        iVar10 = iVar8 * 0x7f2;
        iVar8 = iVar8 + 1;
        if ((&DAT_2000e104)[iVar10] == '\x01') {
          iVar9 = iVar9 + 1;
        }
      } while (iVar8 != 4);
      cVar2 = *(char *)(param_1 + 0x69);
      if (cVar2 != '\0') {
        if (cVar2 == '\x01') {
          if (DAT_20004b19 != '\x01') {
            DAT_20004b19 = cVar2;
            iVar8 = FUN_000809e2();
            uVar3 = FUN_00080a3a();
            iVar10 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            gui_area_clear(iVar8 + 0x100,(uint)uVar3,iVar10 + 0x23c,uVar4 + 0x88);
          }
          if (2 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): db_info->stocks_disp_mode = %d\n","DashBoard_Reflash",
                     (uint)*(byte *)(param_1 + 0x69));
            }
            else {
              ble_printk("%s(): db_info->stocks_disp_mode = %d\n");
            }
          }
          if (iVar9 == 0) {
            cleanStocksIndex();
          }
          iVar8 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          uVar18 = 0x43;
LAB_00039a6e:
          gui_bmp_bitmap_draw(uVar18,iVar8 + 0x10a,uVar3 + 2,0,0,0);
          pcVar12 = get_string(0x4b);
          iVar8 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          gui_utf_draw_middle(0,pcVar12,0,iVar8 + 0x10a,uVar3 + 0x2a,iVar9 + 0x234,uVar4 + 0x45,1,0,
                              0,(undefined *)0x0,0);
          pcVar12 = get_string(0x4c);
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          iVar8 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          iVar9 = iVar9 + 0x10a;
          goto LAB_00039af2;
        }
        if (cVar2 != '\x02') {
          return;
        }
        if (DAT_20004b19 != '\x02') {
          DAT_20004b19 = cVar2;
          iVar8 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          gui_area_clear(iVar8 + 0x100,uVar3 + 4,iVar9 + 0x23c,uVar4 + 0x88);
        }
        iVar8 = 0;
        iVar9 = 0;
        do {
          iVar10 = iVar8 * 0x7f2;
          iVar8 = iVar8 + 1;
          if ((&DAT_2000e104)[iVar10] == '\x01') {
            iVar9 = iVar9 + 1;
          }
        } while (iVar8 != 4);
        DAT_20004afc = (undefined1)iVar9;
        uVar18 = (uint)DAT_20004afb;
        cVar2 = (&DAT_2000e105)[uVar18 * 0x7f2];
        if (cVar2 == '\0') {
          iVar8 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          iVar10 = uVar3 + 2;
          uVar16 = 0x46;
          iVar8 = iVar8 + 0x10a;
LAB_00039b98:
          gui_bmp_bitmap_draw(uVar16,iVar8,iVar10,0,0,0);
        }
        else {
          if (cVar2 == '\x01') {
            iVar8 = FUN_000809e2();
            uVar3 = FUN_00080a3a();
            iVar10 = uVar3 + 2;
            uVar16 = 0x44;
            iVar8 = iVar8 + 0x10a;
            goto LAB_00039b98;
          }
          if (cVar2 == '\x02') {
            iVar8 = FUN_000809e2();
            uVar3 = FUN_00080a3a();
            iVar10 = uVar3 + 2;
            uVar16 = 0x45;
            iVar8 = iVar8 + 0x10a;
            goto LAB_00039b98;
          }
        }
        if (iVar9 == 0) {
          iVar8 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          gui_area_clear(iVar8 + 0x218,uVar3 + 1,iVar9 + 0x23a,uVar4 + 0x1c);
        }
        else {
          local_80 = 0;
          memset(local_7c,0,0x1c);
          snprintf((char *)&local_80,0x20,"%d/%d",uVar18 + 1,iVar9);
          iVar8 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          gui_utf_draw(0,(char *)&local_80,0,iVar8 + 0x218,uVar3 + 1,iVar9 + 0x23a,uVar4 + 0x1c,1,0,
                       0,(undefined *)0x0,0);
        }
        iVar10 = uVar18 * 0x7f2;
        iVar8 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        gui_utf_draw(0,(char *)(iVar10 + 0x2000e108),0,iVar8 + 0x126,(uint)uVar3,iVar9 + 0x200,
                     uVar4 + 0x1b,1,0,0,(undefined *)0x0,0);
        iVar8 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        gui_utf_draw(0,(char *)(iVar10 + 0x2000e128),0,iVar8 + 0x10a,uVar3 + 0x1b,iVar9 + 0x232,
                     uVar4 + 0x36,1,0,0,(undefined *)0x0,0);
        iVar8 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        gui_utf_draw_align_right
                  (0,(char *)(iVar10 + 0x2000e168),0,iVar8 + 0x1d2,uVar3 + 0x36,iVar9 + 0x232,
                   uVar4 + 0x51,1,0,0,(undefined *)0x0,0);
        iVar8 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        gui_utf_draw_align_right
                  (0,(char *)(iVar10 + 0x2000e178),0,iVar8 + 0x1d2,uVar3 + 0x51,iVar9 + 0x232,
                   uVar4 + 0x6c,1,0,0,(undefined *)0x0,0);
        iVar8 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        gui_utf_draw_align_right
                  (0,(char *)(iVar10 + 0x2000e188),0,iVar8 + 0x1d2,uVar3 + 0x6c,iVar9 + 0x232,
                   uVar4 + 0x87,1,0,0,(undefined *)0x0,0);
        iVar8 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        iVar9 = iVar9 + 0x1c2;
        uVar18 = iVar8 + 0x10a;
        goto LAB_00039d7e;
      }
      if (2 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): db_info->stocks_disp_mode = %d\n","DashBoard_Reflash");
        }
        else {
          ble_printk("%s(): db_info->stocks_disp_mode = %d\n","DashBoard_Reflash",0);
        }
      }
      if (DAT_20004b19 != *(char *)(param_1 + 0x69)) {
        DAT_20004b19 = *(char *)(param_1 + 0x69);
        iVar8 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        iVar10 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        gui_area_clear(iVar8 + 0x100,uVar3 + 4,iVar10 + 0x23c,uVar4 + 0x88);
      }
      if (iVar9 == 0) {
        cleanStocksIndex();
      }
      iVar8 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      iVar9 = uVar3 + 2;
      uVar18 = 0x43;
      iVar8 = iVar8 + 0x10a;
LAB_0003999e:
      gui_bmp_bitmap_draw(uVar18,iVar8,iVar9,0,0,0);
      pcVar12 = get_string(0x4d);
      iVar9 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      iVar8 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      uVar18 = 1;
      iVar10 = uVar4 + 0x51;
LAB_000399ce:
      iVar13 = uVar3 + 0x36;
    }
    else {
      if (uVar18 == 2) {
        iVar8 = 0;
        local_80 = 0;
        iVar9 = 0;
        memset(local_7c,0,0x1c);
        do {
          if ((&DAT_20011281)[iVar9 * 0x159] == '\x01') {
            if (2 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): news num.%d is vaild\n","DashBoard_Reflash",iVar9);
              }
              else {
                ble_printk("%s(): news num.%d is vaild\n");
              }
            }
            iVar8 = iVar8 + 1;
          }
          iVar9 = iVar9 + 1;
        } while (iVar9 != 4);
        cVar2 = *(char *)(param_1 + 0x6a);
        if (cVar2 == '\0') {
          if (DAT_20004b1a != '\0') {
            DAT_20004b1a = cVar2;
            iVar9 = FUN_000809e2();
            uVar3 = FUN_00080a3a();
            iVar10 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            gui_area_clear(iVar9 + 0x100,uVar3 + 4,iVar10 + 0x23c,uVar4 + 0x88);
          }
          if (iVar8 == 0) {
            cleanNewsIndex();
          }
          iVar8 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          iVar9 = uVar3 + 2;
          uVar18 = 0x47;
          iVar8 = iVar8 + 0x10a;
          goto LAB_0003999e;
        }
        if (cVar2 == '\x01') {
          if (DAT_20004b1a != '\x01') {
            DAT_20004b1a = cVar2;
            iVar9 = FUN_000809e2();
            uVar3 = FUN_00080a3a();
            iVar10 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            gui_area_clear(iVar9 + 0x100,(uint)uVar3,iVar10 + 0x23c,uVar4 + 0x88);
          }
          if (iVar8 == 0) {
            cleanNewsIndex();
          }
          iVar8 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          uVar18 = 0x47;
          goto LAB_00039a6e;
        }
        if (cVar2 != '\x04') {
          if (cVar2 != '\x02') {
            return;
          }
          if (DAT_20004b1a != '\x02') {
            DAT_20004b1a = cVar2;
            iVar9 = FUN_000809e2();
            uVar3 = FUN_00080a3a();
            iVar10 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            gui_area_clear(iVar9 + 0x100,(uint)uVar3,iVar10 + 0x23c,uVar4 + 0x88);
          }
          if (2 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): total news num = %d\n","DashBoard_Reflash",iVar8);
            }
            else {
              ble_printk("%s(): total news num = %d\n");
            }
          }
          DAT_20004afe = (char)iVar8;
          iVar9 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          gui_bmp_bitmap_draw(0x47,iVar9 + 0x10a,uVar3 + 2,0,0,0);
          if (iVar8 != 0) {
            DAT_20004b03 = '\x01';
            memset(&local_80,0,0x20);
            snprintf((char *)&local_80,0x20,"%d/%d",DAT_20004afd + 1,iVar8);
            uVar18 = (uint)DAT_20004afd;
            iVar9 = FUN_000809e2();
            uVar3 = FUN_00080a3a();
            iVar10 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            gui_utf_draw(0,(char *)(uVar18 * 0x159 + 0x20011282),0,iVar9 + 0x128,uVar3 + 1,
                         iVar10 + 0x212,uVar4 + 0x1c,1,0,0,(undefined *)0x0,0);
            if (iVar8 == 1) {
              iVar8 = FUN_000809e2();
              uVar4 = FUN_00080a3a();
              iVar9 = FUN_000809e2();
              uVar3 = FUN_00080a3a();
              pcVar12 = " ";
            }
            else {
              iVar8 = FUN_000809e2();
              uVar4 = FUN_00080a3a();
              iVar9 = FUN_000809e2();
              uVar3 = FUN_00080a3a();
              pcVar12 = (char *)&local_80;
            }
            gui_utf_draw(0,pcVar12,0,iVar8 + 0x218,uVar4 + 1,iVar9 + 0x23a,uVar3 + 0x1c,1,0,0,
                         (undefined *)0x0,0);
            iVar8 = FUN_000809e2();
            uVar3 = FUN_00080a3a();
            iVar9 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            iVar10 = uVar4 + 0x88;
            iVar9 = iVar9 + 0x238;
            iVar13 = uVar3 + 0x1c;
            iVar8 = iVar8 + 0x10a;
            pcVar12 = (char *)(uVar18 * 0x159 + 0x200112c2);
            goto LAB_0003a208;
          }
          iVar9 = FUN_000806de(&DAT_2000aa10);
          if ((-1 < iVar9 << 0x1e) || (DAT_20004b03 != '\x01')) goto LAB_0003a10c;
          DAT_20004b03 = (char)iVar8;
          pGVar6 = __get_dashboard_state();
          iVar8 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          _clean_fb_data((byte *)&(pGVar6->jdb_panel_context).__panel_buffer,0,iVar8 + 0x128,
                         uVar3 + 1,iVar9 + 0x23a,uVar4 + 0x1c);
          pGVar6 = __get_dashboard_state();
          uVar19 = (pGVar6->jdb_panel_context).current_row;
          pGVar6 = __get_dashboard_state();
          uVar20 = (pGVar6->jdb_panel_context).current_column;
          iVar8 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          _reflash_fb_data_to_lcd(uVar19,uVar20,iVar8 + 0x128,uVar3 + 1,iVar9 + 0x23a,uVar4 + 0x1c);
          pGVar6 = __get_dashboard_state();
          iVar8 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          _clean_fb_data((byte *)&(pGVar6->jdb_panel_context).__panel_buffer,0,iVar8 + 0x10a,
                         uVar3 + 0x1c,iVar9 + 0x232,uVar4 + 0x88);
          pGVar6 = __get_dashboard_state();
          uVar19 = (pGVar6->jdb_panel_context).current_row;
          pGVar6 = __get_dashboard_state();
          uVar20 = (pGVar6->jdb_panel_context).current_column;
          iVar8 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          iVar9 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          iVar9 = iVar9 + 0x232;
          iVar8 = iVar8 + 0x10a;
          goto LAB_0003a104;
        }
        if (DAT_20004b1a != '\x04') {
          DAT_20004b1a = '\x04';
          iVar9 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          iVar10 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          gui_area_clear(iVar9 + 0x100,(uint)uVar3,iVar10 + 0x23c,uVar4 + 0x88);
        }
        if (iVar8 == 0) {
          cleanNewsIndex();
        }
        iVar8 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        gui_bmp_bitmap_draw(0x47,iVar8 + 0x10a,uVar3 + 2,0,0,0);
        pcVar12 = get_string(0x51);
        iVar9 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        iVar8 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        uVar18 = 2;
        iVar10 = uVar4 + 0x6c;
        goto LAB_000399ce;
      }
      if (uVar18 != 4) {
        return;
      }
      cVar2 = *(char *)(param_1 + 0x6b);
      if (cVar2 == 0) {
LAB_0003a260:
        if (DAT_20004b1b != cVar2) {
          DAT_20004b1b = cVar2;
          iVar8 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          gui_area_clear(iVar8 + 0x100,(uint)uVar3,iVar9 + 572,uVar4 + 136);
        }
        iVar8 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        iVar9 = uVar3 + 2;
        uVar18 = 0x48;
        iVar8 = iVar8 + 0x10a;
        goto LAB_0003999e;
      }
      if (DAT_20004b1c == '\0') {
        if (DAT_2001111d == '\0') goto LAB_0003a260;
        if (cVar2 != '\x01') {
          if (cVar2 != '\x03') {
            return;
          }
          if (DAT_2001111d != '\x01') {
            return;
          }
          if (0x108 < *(ushort *)(param_1 + 0x6d)) {
            return;
          }
          if (0x68 < *(ushort *)(param_1 + 0x6f)) {
            return;
          }
          goto LAB_0003a324;
        }
      }
      else if (cVar2 != '\x01') {
        if (cVar2 != '\x03') {
          return;
        }
        if (DAT_2001111d != '\x01') {
          return;
        }
        if (*(char *)(param_1 + 0x71) != '\x03') {
          return;
        }
        if (0x108 < *(ushort *)(param_1 + 0x6d)) {
          return;
        }
        if (0x68 < *(ushort *)(param_1 + 0x6f)) {
          return;
        }
        *(undefined1 *)(param_1 + 0x71) = 0;
        pGVar6 = __get_dashboard_state();
        pGVar6->dashboard_ts->field_0x71 = 0;
LAB_0003a324:
        if (DAT_20004b1b != *(char *)(param_1 + 0x6b)) {
          DAT_20004b1b = *(char *)(param_1 + 0x6b);
          iVar8 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          gui_area_clear(iVar8 + 0x100,(uint)uVar3,iVar9 + 0x23c,uVar4 + 0x88);
        }
        iVar8 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        gui_bitmap_draw(iVar8 + 0x10a,(uint)uVar3,iVar9 + 0x232,uVar4 + 0x88,0x200143cf,2);
        iVar8 = FUN_000809e2();
        uVar18 = iVar8 + 0x10a + (uint)*(ushort *)(param_1 + 0x6d);
        uVar3 = FUN_00080a3a();
        iVar10 = (uint)*(ushort *)(param_1 + 0x6f) + (uint)uVar3;
        iVar8 = FUN_000809e2();
        uVar3 = *(ushort *)(param_1 + 0x6d);
        uVar4 = FUN_00080a3a();
        puVar14 = &DAT_20015777;
        iVar9 = (uint)uVar3 + iVar8 + 0x12a;
        iVar8 = (uint)*(ushort *)(param_1 + 0x6f) + (uint)uVar4;
        goto LAB_0003a3c2;
      }
      if (DAT_20004b1b != '\x01') {
        DAT_20004b1b = '\x01';
        iVar8 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        gui_area_clear(iVar8 + 0x100,(uint)uVar3,iVar9 + 0x23c,uVar4 + 0x88);
      }
      iVar8 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      gui_bmp_bitmap_draw(0x48,iVar8 + 0x10a,uVar3 + 2,0,0,0);
      pcVar12 = get_string(0x50);
      iVar9 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      iVar8 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      iVar10 = uVar4 + 0x60;
      uVar18 = 2;
      iVar13 = uVar3 + 0x2a;
    }
    iVar9 = iVar9 + 0x10a;
LAB_000399e0:
    iVar8 = iVar8 + 0x234;
  }
LAB_000399e2:
  gui_utf_draw_middle(0,pcVar12,0,iVar9,iVar13,iVar8,iVar10,uVar18,0,0,(undefined *)0x0,0);
switchD_0003b01c_default:
  return;
}


