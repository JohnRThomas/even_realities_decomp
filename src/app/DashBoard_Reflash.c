/*
 * Function: DashBoard_Reflash
 * Entry:    00038dc4
 * Prototype: undefined __stdcall DashBoard_Reflash(int param_1, int param_2, int param_3, int param_4)
 */


void DashBoard_Reflash(int param_1,int param_2,int param_3,int param_4)

{
  bool bVar1;
  byte bVar2;
  char cVar3;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  GlassesState *pGVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  size_t sVar12;
  size_t n;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 uVar13;
  undefined4 extraout_r1_01;
  undefined4 extraout_r1_02;
  char *pcVar14;
  uint extraout_r2;
  uint extraout_r2_00;
  uint extraout_r2_01;
  uint uVar15;
  uint extraout_r2_02;
  uint extraout_r2_03;
  undefined *puVar16;
  int iVar17;
  int iVar18;
  undefined8 uVar19;
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
      printk("%s(): display_mode = %d\n");
    }
    else {
      ble_printk("%s(): display_mode = %d\n","DashBoard_Reflash",param_4,BLE_DEBUG);
    }
  }
  bVar1 = FUN_00028d2c();
  uVar8 = (uint)bVar1;
  if (2 < LOG_LEVEL) {
    pcVar14 = "connect";
    if (BLE_DEBUG == 0) {
      if (uVar8 != 1) {
        pcVar14 = "disconnect";
      }
      printk("%s(): BLE Connect status : %s\n","DashBoard_Reflash",pcVar14);
    }
    else {
      if (uVar8 != 1) {
        pcVar14 = "disconnect";
      }
      ble_printk("%s(): BLE Connect status : %s\n","DashBoard_Reflash",pcVar14,"disconnect");
    }
  }
  pGVar7 = __get_dashboard_state();
  uVar19 = CONCAT44(extraout_r1,pGVar7);
  uVar15 = extraout_r2;
  if (*(char *)pGVar7 == '\x01') {
    if ((((uVar8 == 1) && (pGVar7 = __get_dashboard_state(), *(char *)(pGVar7 + 1) == '\0')) &&
        (pGVar7 = __get_dashboard_state(), pGVar7->glasses_state_struct_0FF0->field_0x73 == '\x01'))
       && (pGVar7 = __get_dashboard_state(), pGVar7->glasses_state_struct_0FF0->field_0x74 == '\0'))
    {
      bVar2 = FUN_00030440();
      uVar19 = CONCAT44(extraout_r1_00,(uint)bVar2);
      uVar15 = extraout_r2_00;
      if (bVar2 == 1) {
        uVar19 = FUN_0008040c();
        uVar15 = extraout_r2_01;
      }
    }
    else {
      cVar3 = FUN_00030440();
      uVar19 = CONCAT44(extraout_r1_01,1);
      uVar15 = extraout_r2_02;
      if (cVar3 != '\x01') {
        uVar11 = FUN_00030458();
        uVar19 = CONCAT44(extraout_r1_02,uVar11);
        uVar15 = extraout_r2_03;
      }
    }
  }
  uVar13 = (undefined4)((ulonglong)uVar19 >> 0x20);
  uVar11 = (undefined4)uVar19;
  if (param_4 == 1) {
    if (((DAT_20004b14 != uVar8) || (DAT_20004b11 != 1)) ||
       (uVar15 = (uint)PANE_MODE, uVar15 != *(byte *)(param_1 + 0x66))) {
      gui_screen_clear(uVar11,uVar13,uVar15);
      PANE_MODE = *(byte *)(param_1 + 0x66);
      DAT_20004b11 = *(byte *)(param_1 + 0x65);
      DAT_20004b14 = uVar8;
      if (2 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): display_mode = %d ,exec screen clear\n");
        }
        else {
          ble_printk("%s(): display_mode = %d ,exec screen clear\n","DashBoard_Reflash",
                     (uint)DAT_20004b11,BLE_DEBUG);
        }
      }
    }
    local_a0 = 0;
    local_9c = 0;
    local_98 = 0;
    if (uVar8 == 1) {
      uVar8 = FUN_00080732();
      FUN_0004d1e0(uVar8,(undefined2 *)&local_a0);
      iVar9 = FUN_000807aa(local_a0 & 0xffff,local_a0 >> 0x10,local_9c & 0xffff);
      get_string(iVar9 + 0x28U & 0xff);
      local_94 = 0;
      memset(local_90,0,0x10);
      if (*(char *)(param_1 + 0x5f) == '\0') {
        pcVar14 = "%s, %02d/%02d";
      }
      else if (*(char *)(param_1 + 0x5f) == '\x01') {
        pcVar14 = "%s, %02d-%02d";
      }
      else {
        pcVar14 = "%s, %02d/%02d";
      }
      FUN_0008a6b0((char *)&local_94,0,0x14,(byte *)pcVar14);
      iVar9 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      iVar10 = FUN_000809e2();
      uVar5 = FUN_00080a3a();
      gui_utf_draw(0,(char *)&local_94,3,iVar9,uVar4 + 2,iVar10 + 0x8c,uVar5 + 0x1d,1,0,0,
                   (undefined *)0x0,0);
      pGVar7 = __get_dashboard_state();
      cVar3 = pGVar7->glasses_state_struct_0FF0->field_0x5e;
      uVar8 = FUN_00080732();
      iVar9 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      iVar10 = FUN_000809e2();
      uVar5 = FUN_00080a3a();
      gui_clock_draw(uVar8,iVar9,uVar4 + 0x34,iVar10 + 0x96,uVar5 + 0x55,1,cVar3 != '\x01');
      if (param_3 == 1) {
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        gui_bmp_bitmap_draw(0x5a,iVar9 + 0x23e,uVar4 + 4,0,0,0);
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        gui_bmp_bitmap_draw(0x59,iVar9 + 0xac,uVar4 + 4,0,0,0);
        if (2 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): weather icon num = %d\n");
          }
          else {
            ble_printk("%s(): weather icon num = %d\n","DashBoard_Reflash",
                       (uint)*(byte *)(param_1 + 4),BLE_DEBUG);
          }
        }
        local_80 = 0;
        local_7c[0] = 0;
        if ((*(byte *)(param_1 + 4) - 1 & 0xff) < 0xfe) {
          uVar8 = FUN_0004916c((uint)*(byte *)(param_1 + 4));
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          gui_bmp_bitmap_draw(uVar8,iVar9,uVar4 + 0x6d,0,0,0);
          pGVar7 = __get_dashboard_state();
          iVar9 = (int)*(char *)(param_1 + 5);
          local_80 = (uint)(byte)pGVar7->glasses_state_struct_0FF0->field_0x5d;
          if (local_80 == 0) {
            local_7c[0] = local_80;
            if (2 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): temperature = %d\n");
              }
              else {
                ble_printk("%s(): temperature = %d\n","DashBoard_Reflash",iVar9,BLE_DEBUG);
              }
            }
            snprintf((char *)&local_80,8,"%d",iVar9);
            local_a8 = 0;
            iVar9 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            iVar10 = FUN_000809e2();
            uVar5 = FUN_00080a3a();
            gui_string_draw(3,(byte *)&local_80,iVar9 + 0x1c,uVar4 + 0x6d,iVar10 + 0x58,uVar5 + 0x88
                            ,(int *)&local_a8);
            bVar2 = 0x2a;
          }
          else {
            local_80 = 0;
            local_7c[0] = 0;
            iVar9 = (iVar9 * 9) / 5 + 0x20;
            if (2 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): fahrenheit_temperature = %d\n");
              }
              else {
                ble_printk("%s(): fahrenheit_temperature = %d\n","DashBoard_Reflash",iVar9,BLE_DEBUG
                          );
              }
            }
            snprintf((char *)&local_80,8,"%d",iVar9);
            local_a8 = 0;
            iVar9 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            iVar10 = FUN_000809e2();
            uVar5 = FUN_00080a3a();
            gui_string_draw(3,(byte *)&local_80,iVar9 + 0x1c,uVar4 + 0x6d,iVar10 + 0x58,uVar5 + 0x88
                            ,(int *)&local_a8);
            bVar2 = 0x23;
          }
          local_7c[0] = 0;
          local_80 = (uint)bVar2;
          iVar9 = FUN_000809e2();
          iVar10 = iVar9 + 0x1c + local_a8;
          uVar4 = FUN_00080a3a();
          iVar9 = FUN_000809e2();
          iVar9 = local_a8 + iVar9;
          uVar5 = FUN_00080a3a();
          gui_string_draw(3,(byte *)&local_80,iVar10,uVar4 + 0x6d,iVar9 + 0x67,uVar5 + 0x88,
                          (int *)0x0);
        }
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        gui_bmp_bitmap_draw(0x3c,iVar9 + 0x60,uVar4 + 0x6d,0,0,0);
        uVar8 = FUN_00035310();
        if ((int)uVar8 < 0xb) {
          pcVar14 = "%d";
        }
        else {
          pcVar14 = "%d+";
          uVar8 = 10;
        }
        local_80 = 0;
        local_7c[0] = 0;
        snprintf((char *)&local_80,8,pcVar14,uVar8);
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        iVar10 = FUN_000809e2();
        uVar5 = FUN_00080a3a();
        gui_string_draw(3,(byte *)&local_80,iVar9 + 0x7c,uVar4 + 0x6d,iVar10 + 0x9a,uVar5 + 0x88,
                        (int *)0x0);
        if (*(char *)(param_1 + 0x60) == '\x01') {
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          gui_bmp_bitmap_draw(0x42,iVar9 + 0x8c,uVar4 + 1,0,0,0);
        }
        else {
          pGVar7 = __get_dashboard_state();
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          iVar10 = FUN_000809e2();
          uVar5 = FUN_00080a3a();
          _clean_fb_data((int)&pGVar7->field_0xb90,0,iVar9 + 0x8c,uVar4 + 1,iVar10 + 0xa4,
                         uVar5 + 0x1c);
          pGVar7 = __get_dashboard_state();
          iVar18 = *(int *)&pGVar7->field_0xeb4;
          pGVar7 = __get_dashboard_state();
          iVar17 = *(int *)&pGVar7->field_0xeb8;
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          iVar10 = FUN_000809e2();
          uVar5 = FUN_00080a3a();
          _reflash_fb_data_to_lcd(iVar18,iVar17,iVar9 + 0x8c,uVar4 + 1,iVar10 + 0xa4,uVar5 + 0x1c);
        }
      }
      else if (param_3 != 4) {
        return;
      }
      uVar8 = (uint)PANE_MODE;
      if (uVar8 == 0) {
        local_80 = uVar8;
        memset(local_7c,0,0x1c);
        iVar10 = 0;
        iVar9 = 0;
        do {
          if (*(char *)(iVar10 * 0x143 + *(int *)(param_2 + 0x1030) + 3) == '\x01') {
            if (2 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): quick note num.%d is vaild\n");
              }
              else {
                ble_printk("%s(): quick note num.%d is vaild\n","DashBoard_Reflash",iVar10,BLE_DEBUG
                          );
              }
            }
            iVar9 = iVar9 + 1;
          }
          iVar10 = iVar10 + 1;
        } while (iVar10 != 4);
LAB_0003aba8:
        if (2 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): total quick note num = %d\n");
          }
          else {
            ble_printk("%s(): total quick note num = %d\n","DashBoard_Reflash",iVar9,BLE_DEBUG);
          }
        }
        DAT_20004afa = (char)iVar9;
        iVar10 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        gui_bmp_bitmap_draw(0x3b,iVar10 + 0xba,uVar4 + 1,0,0,0);
        if (iVar9 == 0) {
          iVar10 = FUN_000806de(&DAT_2000aa10);
          if ((iVar10 << 0x1e < 0) && (DAT_20004b02 == '\x01')) {
            DAT_20004b02 = (char)iVar9;
            pGVar7 = __get_dashboard_state();
            iVar9 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            iVar10 = FUN_000809e2();
            uVar5 = FUN_00080a3a();
            _clean_fb_data((int)&pGVar7->field_0xb90,0,iVar9 + 0xd6,uVar4 + 1,iVar10 + 0x22e,
                           uVar5 + 0x1c);
            pGVar7 = __get_dashboard_state();
            iVar17 = *(int *)&pGVar7->field_0xeb4;
            pGVar7 = __get_dashboard_state();
            iVar18 = *(int *)&pGVar7->field_0xeb8;
            iVar9 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            iVar10 = FUN_000809e2();
            uVar5 = FUN_00080a3a();
            _reflash_fb_data_to_lcd
                      (iVar17,iVar18,iVar9 + 0xd6,uVar4 + 1,iVar10 + 0x22e,uVar5 + 0x1c);
            pGVar7 = __get_dashboard_state();
            iVar9 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            iVar10 = FUN_000809e2();
            uVar5 = FUN_00080a3a();
            _clean_fb_data((int)&pGVar7->field_0xb90,0,iVar9 + 0xba,uVar4 + 0x1c,iVar10 + 0x238,
                           uVar5 + 0x88);
            pGVar7 = __get_dashboard_state();
            iVar17 = *(int *)&pGVar7->field_0xeb4;
            pGVar7 = __get_dashboard_state();
            iVar18 = *(int *)&pGVar7->field_0xeb8;
            iVar9 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            iVar10 = FUN_000809e2();
            uVar5 = FUN_00080a3a();
            _reflash_fb_data_to_lcd
                      (iVar17,iVar18,iVar9 + 0xba,uVar4 + 0x1c,iVar10 + 0x238,uVar5 + 0x88);
          }
          FUN_00038b00();
          FUN_00038864();
          return;
        }
        DAT_20004b02 = '\x01';
        memset(&local_80,0,0x20);
        snprintf((char *)&local_80,0x20,"%d/%d",DAT_20004af9 + 1,iVar9);
        uVar8 = (uint)DAT_20004af9;
        iVar18 = *(int *)(param_2 + 0x1030);
        iVar10 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        iVar17 = FUN_000809e2();
        uVar5 = FUN_00080a3a();
        gui_utf_draw(0,(char *)(iVar18 + uVar8 * 0x143 + 4),0,iVar10 + 0xd6,uVar4 + 1,iVar17 + 0x22e
                     ,uVar5 + 0x1c,1,0,0,(undefined *)0x0,0);
        if (iVar9 == 1) {
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          iVar10 = FUN_000809e2();
          uVar5 = FUN_00080a3a();
          pcVar14 = " ";
        }
        else {
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          iVar10 = FUN_000809e2();
          uVar5 = FUN_00080a3a();
          pcVar14 = (char *)&local_80;
        }
        gui_utf_draw(0,pcVar14,0,iVar9 + 0x20e,uVar4 + 1,iVar10 + 0x23a,uVar5 + 0x1c,1,0,0,
                     (undefined *)0x0,0);
        pcVar14 = (char *)(uVar8 * 0x143 + 0x2d + *(int *)(param_2 + 0x1030));
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        iVar10 = FUN_000809e2();
        uVar5 = FUN_00080a3a();
        iVar17 = uVar5 + 0x88;
        iVar10 = iVar10 + 0x238;
        iVar18 = uVar4 + 0x1c;
        iVar9 = iVar9 + 0xba;
LAB_0003a208:
        gui_utf_draw_dark_light_split
                  (0,pcVar14,0,iVar9,iVar18,iVar10,iVar17,4,0x200b,0,(undefined *)0x0,0);
        return;
      }
      switch(uVar8) {
      case 1:
        iVar9 = 0;
        iVar10 = 0;
        do {
          iVar17 = iVar9 * 0x7f2;
          iVar9 = iVar9 + 1;
          if ((&DAT_2000e104)[iVar17] == '\x01') {
            iVar10 = iVar10 + 1;
          }
        } while (iVar9 != 4);
        cVar3 = *(char *)(param_1 + 0x69);
        if (cVar3 == '\0') {
          if (DAT_20004b19 != '\0') {
            DAT_20004b19 = cVar3;
            iVar9 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            iVar17 = FUN_000809e2();
            uVar5 = FUN_00080a3a();
            gui_area_clear(iVar9 + 0xae,uVar4 + 4,iVar17 + 0x23c,uVar5 + 0x88);
          }
          if (iVar10 == 0) {
            cleanStocksIndex();
          }
          if (2 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): db_info->stocks_disp_mode = %d\n");
            }
            else {
              ble_printk("%s(): db_info->stocks_disp_mode = %d\n","DashBoard_Reflash",
                         (uint)*(byte *)(param_1 + 0x69),BLE_DEBUG);
            }
          }
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          gui_bmp_bitmap_draw(0x43,iVar9 + 0xba,uVar4 + 2,0,0,0);
          pcVar14 = get_string(0x4d);
          iVar10 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          iVar9 = FUN_000809e2();
          uVar5 = FUN_00080a3a();
          iVar17 = uVar5 + 0x51;
          iVar18 = uVar4 + 0x36;
          uVar8 = 1;
          iVar10 = iVar10 + 0xb8;
          goto LAB_000399e0;
        }
        if (cVar3 != '\x01') {
          if (cVar3 != '\x02') {
            return;
          }
          if (DAT_20004b19 != '\x02') {
            DAT_20004b19 = cVar3;
            iVar9 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            iVar10 = FUN_000809e2();
            uVar5 = FUN_00080a3a();
            gui_area_clear(iVar9 + 0xae,uVar4 + 4,iVar10 + 0x23c,uVar5 + 0x88);
          }
          iVar9 = 0;
          iVar10 = 0;
          do {
            iVar17 = iVar9 * 0x7f2;
            iVar9 = iVar9 + 1;
            if ((&DAT_2000e104)[iVar17] == '\x01') {
              iVar10 = iVar10 + 1;
            }
          } while (iVar9 != 4);
          uVar8 = (uint)DAT_20004afb;
          DAT_20004afc = (undefined1)iVar10;
          cVar3 = (&DAT_2000e105)[uVar8 * 0x7f2];
          if (cVar3 == '\0') {
            iVar9 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            iVar17 = uVar4 + 2;
            uVar15 = 0x46;
            iVar9 = iVar9 + 0xba;
LAB_0003b2b4:
            gui_bmp_bitmap_draw(uVar15,iVar9,iVar17,0,0,0);
          }
          else {
            if (cVar3 == '\x01') {
              iVar9 = FUN_000809e2();
              uVar4 = FUN_00080a3a();
              iVar17 = uVar4 + 2;
              uVar15 = 0x44;
              iVar9 = iVar9 + 0xba;
              goto LAB_0003b2b4;
            }
            if (cVar3 == '\x02') {
              iVar9 = FUN_000809e2();
              uVar4 = FUN_00080a3a();
              iVar17 = uVar4 + 2;
              uVar15 = 0x45;
              iVar9 = iVar9 + 0xba;
              goto LAB_0003b2b4;
            }
          }
          if (iVar10 == 0) {
            iVar9 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            iVar10 = FUN_000809e2();
            uVar5 = FUN_00080a3a();
            gui_area_clear(iVar9 + 0x20e,uVar4 + 1,iVar10 + 0x23a,uVar5 + 0x1c);
          }
          else {
            local_80 = 0;
            memset(local_7c,0,0x1c);
            snprintf((char *)&local_80,0x20,"%d/%d",uVar8 + 1,iVar10);
            iVar9 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            iVar10 = FUN_000809e2();
            uVar5 = FUN_00080a3a();
            gui_utf_draw(0,(char *)&local_80,0,iVar9 + 0x20e,uVar4 + 1,iVar10 + 0x23a,uVar5 + 0x1c,1
                         ,0,0,(undefined *)0x0,0);
          }
          iVar17 = uVar8 * 0x7f2;
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          iVar10 = FUN_000809e2();
          uVar5 = FUN_00080a3a();
          gui_utf_draw(0,(char *)(iVar17 + 0x2000e108),0,iVar9 + 0xd6,(uint)uVar4,iVar10 + 0x202,
                       uVar5 + 0x1b,1,0,0,(undefined *)0x0,0);
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          iVar10 = FUN_000809e2();
          uVar5 = FUN_00080a3a();
          gui_utf_draw(0,(char *)(iVar17 + 0x2000e128),0,iVar9 + 0xba,uVar4 + 0x1b,iVar10 + 0x234,
                       uVar5 + 0x36,1,0,0,(undefined *)0x0,0);
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          iVar10 = FUN_000809e2();
          uVar5 = FUN_00080a3a();
          gui_utf_draw_align_right
                    (0,(char *)(iVar17 + 0x2000e168),0,iVar9 + 0x182,uVar4 + 0x36,iVar10 + 0x234,
                     uVar5 + 0x51,1,0,0,(undefined *)0x0,0);
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          iVar10 = FUN_000809e2();
          uVar5 = FUN_00080a3a();
          gui_utf_draw_align_right
                    (0,(char *)(iVar17 + 0x2000e178),0,iVar9 + 0x182,uVar4 + 0x51,iVar10 + 0x234,
                     uVar5 + 0x6c,1,0,0,(undefined *)0x0,0);
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          iVar10 = FUN_000809e2();
          uVar5 = FUN_00080a3a();
          gui_utf_draw_align_right
                    (0,(char *)(iVar17 + 0x2000e188),0,iVar9 + 0x182,uVar4 + 0x6c,iVar10 + 0x234,
                     uVar5 + 0x87,1,0,0,(undefined *)0x0,0);
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          iVar10 = FUN_000809e2();
          uVar5 = FUN_00080a3a();
          iVar10 = iVar10 + 0x172;
          uVar8 = iVar9 + 0xba;
LAB_00039d7e:
          gui_bitmap_draw(uVar8,uVar4 + 0x36,iVar10,uVar5 + 0x88,iVar17 + 0x2000e198,0xf);
          return;
        }
        if (DAT_20004b19 != '\x01') {
          DAT_20004b19 = cVar3;
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          iVar17 = FUN_000809e2();
          uVar5 = FUN_00080a3a();
          gui_area_clear(iVar9 + 0xae,uVar4 + 4,iVar17 + 0x23c,uVar5 + 0x88);
        }
        if (iVar10 == 0) {
          cleanStocksIndex();
        }
        if (2 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): db_info->stocks_disp_mode = %d\n");
          }
          else {
            ble_printk("%s(): db_info->stocks_disp_mode = %d\n","DashBoard_Reflash",
                       (uint)*(byte *)(param_1 + 0x69),BLE_DEBUG);
          }
        }
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        uVar8 = 0x43;
LAB_0003b190:
        gui_bmp_bitmap_draw(uVar8,iVar9 + 0xba,uVar4 + 2,0,0,0);
        pcVar14 = get_string(0x4b);
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        iVar10 = FUN_000809e2();
        uVar5 = FUN_00080a3a();
        gui_utf_draw_middle(0,pcVar14,0,iVar9 + 0xb8,uVar4 + 0x2a,iVar10 + 0x234,uVar5 + 0x45,1,0,0,
                            (undefined *)0x0,0);
        pcVar14 = get_string(0x4c);
        iVar10 = FUN_000809e2();
        uVar5 = FUN_00080a3a();
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        iVar10 = iVar10 + 0xb8;
LAB_00039af2:
        iVar17 = uVar4 + 0x60;
        iVar9 = iVar9 + 0x234;
        iVar18 = uVar5 + 0x45;
        uVar8 = 1;
        goto LAB_000399e2;
      case 2:
        iVar9 = 0;
        local_80 = 0;
        iVar10 = 0;
        memset(local_7c,0,0x1c);
        do {
          if ((&DAT_20011281)[iVar10 * 0x159] == '\x01') {
            if (2 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): news num.%d is vaild\n");
              }
              else {
                ble_printk("%s(): news num.%d is vaild\n","DashBoard_Reflash",iVar10,BLE_DEBUG);
              }
            }
            iVar9 = iVar9 + 1;
          }
          iVar10 = iVar10 + 1;
        } while (iVar10 != 4);
        cVar3 = *(char *)(param_1 + 0x6a);
        if (cVar3 == '\0') {
          if (DAT_20004b1a != '\0') {
            DAT_20004b1a = cVar3;
            iVar10 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            iVar17 = FUN_000809e2();
            uVar5 = FUN_00080a3a();
            gui_area_clear(iVar10 + 0xae,uVar4 + 4,iVar17 + 0x23c,uVar5 + 0x88);
          }
          if (iVar9 == 0) {
            cleanNewsIndex();
          }
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          uVar8 = 0x47;
          iVar9 = iVar9 + 0xba;
LAB_0003b5b4:
          gui_bmp_bitmap_draw(uVar8,iVar9,uVar4 + 2,0,0,0);
          pcVar14 = get_string(0x4d);
          iVar10 = FUN_000809e2();
          uVar5 = FUN_00080a3a();
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          uVar8 = 1;
          iVar17 = uVar4 + 0x51;
        }
        else {
          if (cVar3 == '\x01') {
            if (DAT_20004b1a != '\x01') {
              DAT_20004b1a = cVar3;
              iVar10 = FUN_000809e2();
              uVar4 = FUN_00080a3a();
              iVar17 = FUN_000809e2();
              uVar5 = FUN_00080a3a();
              gui_area_clear(iVar10 + 0xae,uVar4 + 4,iVar17 + 0x23c,uVar5 + 0x88);
            }
            if (iVar9 == 0) {
              cleanNewsIndex();
            }
            iVar9 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            uVar8 = 0x47;
            goto LAB_0003b190;
          }
          if (cVar3 != '\x04') {
            if (cVar3 != '\x02') {
              return;
            }
            if (DAT_20004b1a != '\x02') {
              DAT_20004b1a = cVar3;
              iVar10 = FUN_000809e2();
              uVar4 = FUN_00080a3a();
              iVar17 = FUN_000809e2();
              uVar5 = FUN_00080a3a();
              gui_area_clear(iVar10 + 0xae,uVar4 + 4,iVar17 + 0x23c,uVar5 + 0x88);
            }
            if (2 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): total news num = %d\n");
              }
              else {
                ble_printk("%s(): total news num = %d\n","DashBoard_Reflash",iVar9,BLE_DEBUG);
              }
            }
            DAT_20004afe = (char)iVar9;
            iVar10 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            gui_bmp_bitmap_draw(0x47,iVar10 + 0xba,uVar4 + 2,0,0,0);
            if (iVar9 != 0) {
              DAT_20004b03 = '\x01';
              memset(&local_80,0,0x20);
              snprintf((char *)&local_80,0x20,"%d/%d",DAT_20004afd + 1,iVar9);
              uVar8 = (uint)DAT_20004afd;
              iVar10 = FUN_000809e2();
              uVar4 = FUN_00080a3a();
              iVar17 = FUN_000809e2();
              uVar5 = FUN_00080a3a();
              gui_utf_draw(0,(char *)(uVar8 * 0x159 + 0x20011282),0,iVar10 + 0xd6,uVar4 + 1,
                           iVar17 + 0x200,uVar5 + 0x1c,1,0,0,(undefined *)0x0,0);
              if (iVar9 == 1) {
                iVar9 = FUN_000809e2();
                uVar5 = FUN_00080a3a();
                iVar10 = FUN_000809e2();
                uVar4 = FUN_00080a3a();
                pcVar14 = " ";
              }
              else {
                iVar9 = FUN_000809e2();
                uVar5 = FUN_00080a3a();
                iVar10 = FUN_000809e2();
                uVar4 = FUN_00080a3a();
                pcVar14 = (char *)&local_80;
              }
              gui_utf_draw(0,pcVar14,0,iVar9 + 0x216,uVar5 + 1,iVar10 + 0x23a,uVar4 + 0x1c,1,0,0,
                           (undefined *)0x0,0);
              iVar9 = FUN_000809e2();
              uVar4 = FUN_00080a3a();
              iVar10 = FUN_000809e2();
              uVar5 = FUN_00080a3a();
              iVar10 = iVar10 + 0x236;
              iVar17 = uVar5 + 0x88;
              iVar18 = uVar4 + 0x1c;
              iVar9 = iVar9 + 0xba;
              pcVar14 = (char *)(uVar8 * 0x159 + 0x200112c2);
              goto LAB_0003a208;
            }
            iVar10 = FUN_000806de(&DAT_2000aa10);
            if ((-1 < iVar10 << 0x1e) || (DAT_20004b03 != '\x01')) goto LAB_0003a10c;
            DAT_20004b03 = (char)iVar9;
            pGVar7 = __get_dashboard_state();
            iVar9 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            iVar10 = FUN_000809e2();
            uVar5 = FUN_00080a3a();
            _clean_fb_data((int)&pGVar7->field_0xb90,0,iVar9 + 0xd4,uVar4 + 1,iVar10 + 0x23c,
                           uVar5 + 0x1c);
            pGVar7 = __get_dashboard_state();
            iVar17 = *(int *)&pGVar7->field_0xeb4;
            pGVar7 = __get_dashboard_state();
            iVar18 = *(int *)&pGVar7->field_0xeb8;
            iVar9 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            iVar10 = FUN_000809e2();
            uVar5 = FUN_00080a3a();
            _reflash_fb_data_to_lcd
                      (iVar17,iVar18,iVar9 + 0xd4,uVar4 + 1,iVar10 + 0x23c,uVar5 + 0x1c);
            pGVar7 = __get_dashboard_state();
            iVar9 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            iVar10 = FUN_000809e2();
            uVar5 = FUN_00080a3a();
            _clean_fb_data((int)&pGVar7->field_0xb90,0,iVar9 + 0xba,uVar4 + 0x1c,iVar10 + 0x234,
                           uVar5 + 0x88);
            pGVar7 = __get_dashboard_state();
            iVar17 = *(int *)&pGVar7->field_0xeb4;
            pGVar7 = __get_dashboard_state();
            iVar18 = *(int *)&pGVar7->field_0xeb8;
            iVar9 = FUN_000809e2();
            uVar5 = FUN_00080a3a();
            iVar10 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            iVar10 = iVar10 + 0x234;
            iVar9 = iVar9 + 0xba;
LAB_0003a104:
            _reflash_fb_data_to_lcd(iVar17,iVar18,iVar9,uVar5 + 0x1c,iVar10,uVar4 + 0x88);
LAB_0003a10c:
            cleanNewsIndex();
            return;
          }
          if (DAT_20004b1a != '\x04') {
            DAT_20004b1a = '\x04';
            iVar10 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            iVar17 = FUN_000809e2();
            uVar5 = FUN_00080a3a();
            gui_area_clear(iVar10 + 0xae,uVar4 + 4,iVar17 + 0x23c,uVar5 + 0x88);
          }
          if (iVar9 == 0) {
            cleanNewsIndex();
          }
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          gui_bmp_bitmap_draw(0x47,iVar9 + 0xba,uVar4 + 2,0,0,0);
          pcVar14 = get_string(0x51);
          iVar10 = FUN_000809e2();
          uVar5 = FUN_00080a3a();
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          uVar8 = 2;
          iVar17 = uVar4 + 0x6c;
        }
        iVar18 = uVar5 + 0x36;
        break;
      case 3:
        if ((DAT_20004b18 != *(char *)(param_1 + 0x67)) || (DAT_20004aff != DAT_20004b00)) {
          DAT_20004aff = DAT_20004b00;
          DAT_20004b18 = *(char *)(param_1 + 0x67);
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          iVar10 = FUN_000809e2();
          uVar5 = FUN_00080a3a();
          gui_area_clear(iVar9 + 0x20e,uVar4 + 2,iVar10 + 0x234,uVar5 + 0x1d);
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          iVar10 = FUN_000809e2();
          uVar5 = FUN_00080a3a();
          gui_area_clear(iVar9 + 0xb8,uVar4 + 0x3b,iVar10 + 0x23e,uVar5 + 0x88);
        }
        iVar9 = 0;
        iVar10 = 0;
        do {
          if ((&DAT_2001252f)[iVar9 * 0xa4] == '\x01') {
            if (2 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): news num.%d is vaild\n");
              }
              else {
                ble_printk("%s(): news num.%d is vaild\n","DashBoard_Reflash",iVar9,BLE_DEBUG);
              }
            }
            iVar10 = iVar10 + 1;
          }
          iVar9 = iVar9 + 1;
        } while (iVar9 != 8);
        if (2 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): total calendar num = %d\n");
          }
          else {
            ble_printk("%s(): total calendar num = %d\n","DashBoard_Reflash",iVar10,BLE_DEBUG);
          }
        }
        DAT_20004b01 = ((byte)iVar10 & 1) + (char)(iVar10 >> 1);
        if (DAT_20004b18 == '\0') {
          pcVar14 = get_string(0x4d);
          iVar17 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          iVar10 = FUN_000809e2();
          uVar5 = FUN_00080a3a();
          iVar9 = uVar5 + 0x51;
          iVar18 = uVar4 + 0x36;
        }
        else if (DAT_20004b18 == '\x01') {
          pcVar14 = get_string(0x4b);
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          iVar10 = FUN_000809e2();
          uVar5 = FUN_00080a3a();
          gui_utf_draw_middle(0,pcVar14,0,iVar9 + 0xb8,uVar4 + 0x2a,iVar10 + 0x234,uVar5 + 0x45,1,0,
                              0,(undefined *)0x0,0);
          pcVar14 = get_string(0x4c);
          iVar17 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          iVar10 = FUN_000809e2();
          uVar5 = FUN_00080a3a();
          iVar9 = uVar5 + 0x60;
          iVar18 = uVar4 + 0x45;
        }
        else {
          if (DAT_20004b18 != '\x02') {
            if (DAT_20004b18 != '\x03') {
              return;
            }
            iVar9 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            gui_bmp_bitmap_draw(0x39,iVar9 + 0xba,uVar4 + 1,0,0,0);
            pcVar14 = get_string(0x4e);
            iVar9 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            iVar10 = FUN_000809e2();
            uVar5 = FUN_00080a3a();
            gui_utf_draw(0,pcVar14,0,iVar9 + 0xd6,(uint)uVar4,iVar10 + 0x13a,uVar5 + 0x1b,1,0,0,
                         (undefined *)0x0,0);
            uVar8 = (uint)DAT_20004b01;
            if (uVar8 == 0) {
              return;
            }
            local_80 = 0;
            memset(local_7c,0,0x1c);
            snprintf((char *)&local_80,0x20,"%d/%d",DAT_20004b00 + 1,uVar8);
            iVar9 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            iVar10 = FUN_000809e2();
            uVar5 = FUN_00080a3a();
            gui_utf_draw(0,(char *)&local_80,0,iVar9 + 0x216,uVar4 + 1,iVar10 + 0x23a,uVar5 + 0x1c,1
                         ,0,0,(undefined *)0x0,0);
            uVar8 = (uint)DAT_20004b00;
            iVar9 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            iVar10 = FUN_000809e2();
            uVar5 = FUN_00080a3a();
            gui_utf_draw(0,&DAT_20012530 + uVar8 * 0x148,0,iVar9 + 0xba,uVar4 + 0x1b,iVar10 + 0x236,
                         uVar5 + 0x36,1,0,0,(undefined *)0x0,0);
            uVar8 = (uint)DAT_20004b00;
            iVar9 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            iVar10 = FUN_000809e2();
            uVar5 = FUN_00080a3a();
            gui_utf_draw(0,&DAT_20012571 + uVar8 * 0x148,0,iVar9 + 0xba,uVar4 + 0x36,iVar10 + 0x15e,
                         uVar5 + 0x51,1,0,0,(undefined *)0x0,0);
            uVar8 = (uint)DAT_20004b00;
            iVar9 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            iVar10 = FUN_000809e2();
            uVar5 = FUN_00080a3a();
            gui_utf_draw_align_right
                      (0,&DAT_20012592 + uVar8 * 0x148,0,iVar9 + 0x162,uVar4 + 0x36,iVar10 + 0x234,
                       uVar5 + 0x51,1,0,0,(undefined *)0x0,0);
            iVar9 = ((short)(ushort)DAT_20004b00 * 2 + 1) * 0xa4;
            if ((&DAT_2001252f)[iVar9] != '\x01') {
              return;
            }
            iVar10 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            iVar17 = FUN_000809e2();
            uVar5 = FUN_00080a3a();
            gui_utf_draw(0,&DAT_20012530 + iVar9,0,iVar10 + 0xba,uVar4 + 0x51,iVar17 + 0x236,
                         uVar5 + 0x6c,1,0,0,(undefined *)0x0,0);
            uVar4 = (ushort)DAT_20004b00;
            iVar9 = FUN_000809e2();
            uVar5 = FUN_00080a3a();
            iVar10 = FUN_000809e2();
            uVar6 = FUN_00080a3a();
            gui_utf_draw(0,&DAT_20012571 + ((short)uVar4 * 2 + 1) * 0xa4,0,iVar9 + 0xba,uVar5 + 0x6c
                         ,iVar10 + 0x15e,uVar6 + 0x87,1,0,0,(undefined *)0x0,0);
            uVar4 = (ushort)DAT_20004b00;
            iVar9 = FUN_000809e2();
            uVar5 = FUN_00080a3a();
            iVar10 = FUN_000809e2();
            uVar6 = FUN_00080a3a();
            gui_utf_draw_align_right
                      (0,&DAT_20012592 + ((short)uVar4 * 2 + 1) * 0xa4,0,iVar9 + 0x162,uVar5 + 0x6c,
                       iVar10 + 0x234,uVar6 + 0x87,1,0,0,(undefined *)0x0,0);
            return;
          }
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          gui_bmp_bitmap_draw(0x39,iVar9 + 0xba,uVar4 + 1,0,0,0);
          pcVar14 = get_string(0x4e);
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          iVar10 = FUN_000809e2();
          uVar5 = FUN_00080a3a();
          gui_utf_draw(0,pcVar14,0,iVar9 + 0xd6,(uint)uVar4,iVar10 + 0x13a,uVar5 + 0x1b,1,0,0,
                       (undefined *)0x0,0);
          pcVar14 = get_string(0x4a);
          iVar17 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          iVar10 = FUN_000809e2();
          uVar5 = FUN_00080a3a();
          iVar9 = uVar5 + 0x51;
          iVar18 = uVar4 + 0x36;
        }
        gui_utf_draw_middle(0,pcVar14,0,iVar17 + 0xb8,iVar18,iVar10 + 0x234,iVar9,1,0,0,
                            (undefined *)0x0,0);
        cleanCalenadrIndex();
        return;
      case 4:
        cVar3 = *(char *)(param_1 + 0x6b);
        if (cVar3 == '\0') {
LAB_0003bf02:
          if (DAT_20004b1b != cVar3) {
            DAT_20004b1b = cVar3;
            iVar9 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            iVar10 = FUN_000809e2();
            uVar5 = FUN_00080a3a();
            gui_area_clear(iVar9 + 0xae,(uint)uVar4,iVar10 + 0x23c,uVar5 + 0x88);
          }
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          uVar8 = 0x48;
          iVar9 = iVar9 + 0xb8;
          goto LAB_0003b5b4;
        }
        if (DAT_20004b1c == '\0') {
          if (DAT_2001111d == '\0') goto LAB_0003bf02;
          if (cVar3 != '\x01') {
            if (cVar3 != '\x03') {
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
        else if (cVar3 != '\x01') {
          if (cVar3 != '\x03') {
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
            pGVar7 = __get_dashboard_state();
            pGVar7->glasses_state_struct_0FF0->field_0x71 = 0;
          }
LAB_0003bf7e:
          if (DAT_20004b1b != *(char *)(param_1 + 0x6b)) {
            DAT_20004b1b = *(char *)(param_1 + 0x6b);
            iVar9 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            iVar10 = FUN_000809e2();
            uVar5 = FUN_00080a3a();
            gui_area_clear(iVar9 + 0xae,(uint)uVar4,iVar10 + 0x23c,uVar5 + 0x88);
          }
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          iVar10 = FUN_000809e2();
          uVar5 = FUN_00080a3a();
          gui_bitmap_draw(iVar9 + 0xb8,(uint)uVar4,iVar10 + 0x230,uVar5 + 0x88,0x200143cf,2);
          iVar9 = FUN_000809e2();
          uVar8 = iVar9 + 0xb8 + (uint)*(ushort *)(param_1 + 0x6d);
          uVar4 = FUN_00080a3a();
          iVar17 = (uint)*(ushort *)(param_1 + 0x6f) + (uint)uVar4;
          iVar9 = FUN_000809e2();
          uVar4 = *(ushort *)(param_1 + 0x6d);
          uVar5 = FUN_00080a3a();
          iVar10 = (uint)uVar4 + iVar9 + 0xd8;
          iVar9 = (uint)*(ushort *)(param_1 + 0x6f) + (uint)uVar5;
          puVar16 = &DAT_20015cc7;
LAB_0003a3c2:
          gui_1bit_bitmap_override(uVar8,iVar17,iVar10,iVar9 + 0x20,(int)puVar16,0xf);
          return;
        }
        if (DAT_20004b1b != '\x01') {
          DAT_20004b1b = '\x01';
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          iVar10 = FUN_000809e2();
          uVar5 = FUN_00080a3a();
          gui_area_clear(iVar9 + 0xae,(uint)uVar4,iVar10 + 0x23c,uVar5 + 0x88);
        }
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        gui_bmp_bitmap_draw(0x48,iVar9 + 0xb8,uVar4 + 2,0,0,0);
        pcVar14 = get_string(0x50);
        iVar10 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        iVar9 = FUN_000809e2();
        uVar5 = FUN_00080a3a();
        iVar17 = uVar5 + 0x60;
        uVar8 = 2;
        iVar18 = uVar4 + 0x2a;
        break;
      default:
        goto switchD_0003b01c_default;
      }
      iVar10 = iVar10 + 0xb8;
      goto LAB_000399e0;
    }
    uVar8 = FUN_00080732();
    FUN_0004d1e0(uVar8,(undefined2 *)&local_a0);
    iVar9 = FUN_000807aa(local_a0 & 0xffff,local_a0 >> 0x10,local_9c & 0xffff);
    get_string(iVar9 + 0x28U & 0xff);
    local_94 = 0;
    memset(local_90,0,0x10);
    if (*(char *)(param_1 + 0x5f) == '\0') {
      pcVar14 = "%s, %02d/%02d";
    }
    else if (*(char *)(param_1 + 0x5f) == '\x01') {
      pcVar14 = "%s, %02d-%02d";
    }
    else {
      pcVar14 = "%s, %02d/%02d";
    }
    FUN_0008a6b0((char *)&local_94,0,0x14,(byte *)pcVar14);
    iVar9 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    iVar10 = FUN_000809e2();
    uVar5 = FUN_00080a3a();
    gui_utf_draw(0,(char *)&local_94,3,iVar9,(uint)uVar4,iVar10 + 0x8c,uVar5 + 0x1b,1,0,0,
                 (undefined *)0x0,0);
    pGVar7 = __get_dashboard_state();
    cVar3 = pGVar7->glasses_state_struct_0FF0->field_0x5e;
    uVar8 = FUN_00080732();
    iVar9 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    iVar10 = FUN_000809e2();
    uVar5 = FUN_00080a3a();
    gui_clock_draw(uVar8,iVar9,uVar4 + 0x34,iVar10 + 0x96,uVar5 + 0x55,1,cVar3 != '\x01');
    if (param_3 == 1) {
      iVar9 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      gui_bmp_bitmap_draw(0x3e,iVar9,uVar4 + 0x6d,0,0,0);
      if (*(char *)(param_1 + 0x60) == '\x01') {
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        gui_bmp_bitmap_draw(0x42,iVar9 + 0x60,uVar4 + 0x6d,0,0,0);
      }
      else {
        pGVar7 = __get_dashboard_state();
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        iVar10 = FUN_000809e2();
        uVar5 = FUN_00080a3a();
        _clean_fb_data((int)&pGVar7->field_0xb90,0,iVar9 + 0x60,uVar4 + 0x6d,iVar10 + 0x78,
                       uVar5 + 0x88);
        pGVar7 = __get_dashboard_state();
        iVar17 = *(int *)&pGVar7->field_0xeb4;
        pGVar7 = __get_dashboard_state();
        iVar18 = *(int *)&pGVar7->field_0xeb8;
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        iVar10 = FUN_000809e2();
        uVar5 = FUN_00080a3a();
        _reflash_fb_data_to_lcd(iVar17,iVar18,iVar9 + 0x60,uVar4 + 0x6d,iVar10 + 0x78,uVar5 + 0x88);
      }
      iVar9 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      gui_bmp_bitmap_draw(0x5a,iVar9 + 0x23e,uVar4 + 4,0,0,0);
      iVar9 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      gui_bmp_bitmap_draw(0x59,iVar9 + 0xac,uVar4 + 4,0,0,0);
    }
    else if (param_3 != 4) {
      return;
    }
    uVar8 = (uint)PANE_MODE;
    if (uVar8 == 0) {
      local_80 = uVar8;
      memset(local_7c,0,0x1c);
      iVar10 = 0;
      iVar9 = 0;
      do {
        if (*(char *)(iVar10 * 0x143 + *(int *)(param_2 + 0x1030) + 3) == '\x01') {
          if (2 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): quick note num.%d is vaild\n");
            }
            else {
              ble_printk("%s(): quick note num.%d is vaild\n","DashBoard_Reflash",iVar10,BLE_DEBUG);
            }
          }
          iVar9 = iVar9 + 1;
        }
        iVar10 = iVar10 + 1;
      } while (iVar10 != 4);
      goto LAB_0003aba8;
    }
    switch(uVar8) {
    case 1:
      iVar9 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      iVar10 = uVar4 + 2;
      uVar8 = 0x43;
      iVar9 = iVar9 + 0xba;
      break;
    case 2:
      iVar9 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      iVar10 = uVar4 + 2;
      uVar8 = 0x47;
      iVar9 = iVar9 + 0xba;
      break;
    case 3:
      iVar9 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      iVar10 = uVar4 + 2;
      uVar8 = 0x39;
      iVar9 = iVar9 + 0xba;
      break;
    case 4:
      iVar9 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      iVar10 = uVar4 + 2;
      uVar8 = 0x48;
      iVar9 = iVar9 + 0xba;
      break;
    default:
      goto switchD_0003c4b2_default;
    }
    gui_bmp_bitmap_draw(uVar8,iVar9,iVar10,0,0,0);
switchD_0003c4b2_default:
    get_current_language();
    pcVar14 = get_string(0x4f);
    iVar10 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    iVar9 = FUN_000809e2();
    uVar5 = FUN_00080a3a();
    iVar9 = iVar9 + 0x234;
    iVar10 = iVar10 + 0xb8;
LAB_0003a9be:
    iVar17 = uVar5 + 0x6c;
    iVar18 = uVar4 + 0x36;
    uVar8 = 2;
  }
  else {
    if (param_4 == 2) {
      if (((DAT_20004b14 != uVar8) || (DAT_20004b11 != 2)) ||
         (uVar15 = (uint)PANE_MODE, uVar15 != *(byte *)(param_1 + 0x66))) {
        gui_screen_clear(uVar11,uVar13,uVar15);
        PANE_MODE = *(byte *)(param_1 + 0x66);
        DAT_20004b11 = *(byte *)(param_1 + 0x65);
        DAT_20004b14 = uVar8;
        if (2 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): display_mode = %d ,exec screen clear\n");
          }
          else {
            ble_printk("%s(): display_mode = %d ,exec screen clear\n","DashBoard_Reflash",
                       (uint)DAT_20004b11,BLE_DEBUG);
          }
        }
      }
      if (uVar8 == 1) {
        if (param_3 == 1) {
          if (*(char *)(param_1 + 0x60) == '\x01') {
            if (DAT_20002f88 != 0) {
              DAT_20002f88 = 0;
              pGVar7 = __get_dashboard_state();
              iVar9 = FUN_000809e2();
              uVar4 = FUN_00080a3a();
              iVar10 = FUN_000809e2();
              uVar5 = FUN_00080a3a();
              _clean_fb_data((int)&pGVar7->field_0xb90,0,iVar9,uVar4 + 0x1c,iVar10 + 0x240,
                             uVar5 + 0x37);
              pGVar7 = __get_dashboard_state();
              iVar17 = *(int *)&pGVar7->field_0xeb4;
              pGVar7 = __get_dashboard_state();
              iVar18 = *(int *)&pGVar7->field_0xeb8;
              iVar9 = FUN_000809e2();
              uVar4 = FUN_00080a3a();
              iVar10 = FUN_000809e2();
              uVar5 = FUN_00080a3a();
              _reflash_fb_data_to_lcd(iVar17,iVar18,iVar9,uVar4 + 0x1c,iVar10 + 0x240,uVar5 + 0x37);
            }
            iVar9 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            gui_bmp_bitmap_draw(0x42,iVar9 + 0x1b8,uVar4 + 0x1c,0,0,0);
          }
          else if (DAT_20002f88 != 0x16) {
            DAT_20002f88 = 0x16;
            pGVar7 = __get_dashboard_state();
            iVar9 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            iVar10 = FUN_000809e2();
            uVar5 = FUN_00080a3a();
            _clean_fb_data((int)&pGVar7->field_0xb90,0,iVar9,uVar4 + 0x1c,iVar10 + 0x240,
                           uVar5 + 0x37);
            pGVar7 = __get_dashboard_state();
            iVar17 = *(int *)&pGVar7->field_0xeb4;
            pGVar7 = __get_dashboard_state();
            iVar18 = *(int *)&pGVar7->field_0xeb8;
            iVar9 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            iVar10 = FUN_000809e2();
            uVar5 = FUN_00080a3a();
            _reflash_fb_data_to_lcd(iVar17,iVar18,iVar9,uVar4 + 0x1c,iVar10 + 0x240,uVar5 + 0x37);
          }
          if (2 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): weather icon num = %d\n");
            }
            else {
              ble_printk("%s(): weather icon num = %d\n","DashBoard_Reflash",
                         (uint)*(byte *)(param_1 + 4),BLE_DEBUG);
            }
          }
          local_80 = 0;
          local_7c[0] = 0;
          if ((*(byte *)(param_1 + 4) - 1 & 0xff) < 0xfe) {
            uVar8 = FUN_0004916c((uint)*(byte *)(param_1 + 4));
            iVar9 = FUN_000809e2();
            uVar15 = (uint)DAT_20002f88;
            uVar4 = FUN_00080a3a();
            gui_bmp_bitmap_draw(uVar8,uVar15 + iVar9 + 0x100,uVar4 + 0x1c,0,0,0);
            pGVar7 = __get_dashboard_state();
            iVar9 = (int)*(char *)(param_1 + 5);
            local_80 = (uint)(byte)pGVar7->glasses_state_struct_0FF0->field_0x5d;
            if (local_80 == 0) {
              local_7c[0] = local_80;
              if (2 < LOG_LEVEL) {
                if (BLE_DEBUG == 0) {
                  printk("%s(): temperature = %d\n");
                }
                else {
                  ble_printk("%s(): temperature = %d\n","DashBoard_Reflash",iVar9,BLE_DEBUG);
                }
              }
              snprintf((char *)&local_80,8,"%d",iVar9);
              local_94 = 0;
              iVar9 = FUN_000809e2();
              uVar15 = (uint)DAT_20002f88;
              uVar4 = FUN_00080a3a();
              iVar10 = FUN_000809e2();
              uVar8 = (uint)DAT_20002f88;
              uVar5 = FUN_00080a3a();
              gui_string_draw(3,(byte *)&local_80,uVar15 + iVar9 + 0x11c,uVar4 + 0x1c,
                              uVar8 + iVar10 + 0x144,uVar5 + 0x37,(int *)&local_94);
              bVar2 = 0x2a;
            }
            else {
              local_80 = 0;
              local_7c[0] = 0;
              iVar9 = (iVar9 * 9) / 5 + 0x20;
              if (2 < LOG_LEVEL) {
                if (BLE_DEBUG == 0) {
                  printk("%s(): fahrenheit_temperature = %d\n");
                }
                else {
                  ble_printk("%s(): fahrenheit_temperature = %d\n","DashBoard_Reflash",iVar9,
                             BLE_DEBUG);
                }
              }
              snprintf((char *)&local_80,8,"%d",iVar9);
              local_94 = 0;
              iVar9 = FUN_000809e2();
              uVar15 = (uint)DAT_20002f88;
              uVar4 = FUN_00080a3a();
              iVar10 = FUN_000809e2();
              uVar8 = (uint)DAT_20002f88;
              uVar5 = FUN_00080a3a();
              gui_string_draw(3,(byte *)&local_80,uVar15 + iVar9 + 0x11c,uVar4 + 0x1c,
                              uVar8 + iVar10 + 0x144,uVar5 + 0x37,(int *)&local_94);
              bVar2 = 0x23;
            }
            local_7c[0] = 0;
            local_80 = (uint)bVar2;
            iVar9 = FUN_000809e2();
            iVar10 = (uint)DAT_20002f88 + iVar9 + 0x11c + local_94;
            uVar4 = FUN_00080a3a();
            iVar9 = FUN_000809e2();
            iVar9 = (uint)DAT_20002f88 + iVar9 + local_94;
            uVar5 = FUN_00080a3a();
            gui_string_draw(3,(byte *)&local_80,iVar10,uVar4 + 0x1c,iVar9 + 299,uVar5 + 0x37,
                            (int *)0x0);
          }
          iVar9 = FUN_000809e2();
          uVar8 = (uint)DAT_20002f88;
          uVar4 = FUN_00080a3a();
          gui_bmp_bitmap_draw(0x3c,iVar9 + 0x16e + uVar8,uVar4 + 0x1c,0,0,0);
          uVar8 = FUN_00035310();
          if ((int)uVar8 < 0xb) {
            pcVar14 = "%d";
          }
          else {
            uVar8 = 10;
            pcVar14 = "%d+";
          }
          local_80 = 0;
          local_7c[0] = 0;
          snprintf((char *)&local_80,8,pcVar14,uVar8);
          iVar9 = FUN_000809e2();
          uVar15 = (uint)DAT_20002f88;
          uVar4 = FUN_00080a3a();
          iVar10 = FUN_000809e2();
          uVar8 = (uint)DAT_20002f88;
          uVar5 = FUN_00080a3a();
          gui_string_draw(3,(byte *)&local_80,uVar15 + iVar9 + 0x18a,uVar4 + 0x1c,
                          uVar8 + iVar10 + 0x1a4,uVar5 + 0x37,(int *)0x0);
        }
        local_94 = 0;
        local_90[0] = 0;
        local_90[1] = 0;
        uVar8 = FUN_00080732();
        FUN_0004d1e0(uVar8,(undefined2 *)&local_94);
        iVar9 = FUN_000807aa(local_94 & 0xffff,local_94 >> 0x10,local_90[0] & 0xffff);
        get_string(iVar9 + 0x28U & 0xff);
        local_80 = 0;
        memset(local_7c,0,0x10);
        if (*(char *)(param_1 + 0x5f) == '\0') {
          pcVar14 = "%s, %02d/%02d";
        }
        else if (*(char *)(param_1 + 0x5f) == '\x01') {
          pcVar14 = "%s, %02d-%02d";
        }
        else {
          pcVar14 = "%s, %02d/%02d";
        }
        FUN_0008a6b0((char *)&local_80,0,0x14,(byte *)pcVar14);
        iVar9 = FUN_000809e2();
        uVar8 = (uint)DAT_20002f88;
        uVar4 = FUN_00080a3a();
        iVar10 = FUN_000809e2();
        uVar8 = uVar8 + iVar9 + 0x54;
        iVar9 = (uint)DAT_20002f88 + iVar10 + 0xe0;
      }
      else {
        if (param_3 == 1) {
          if (*(char *)(param_1 + 0x60) == '\x01') {
            if (DAT_20002f88 != 0) {
              DAT_20002f88 = 0;
              pGVar7 = __get_dashboard_state();
              iVar9 = FUN_000809e2();
              uVar4 = FUN_00080a3a();
              iVar10 = FUN_000809e2();
              uVar5 = FUN_00080a3a();
              _clean_fb_data((int)&pGVar7->field_0xb90,0,iVar9,uVar4 + 0x1c,iVar10 + 0x240,
                             uVar5 + 0x37);
              pGVar7 = __get_dashboard_state();
              iVar17 = *(int *)&pGVar7->field_0xeb4;
              pGVar7 = __get_dashboard_state();
              iVar18 = *(int *)&pGVar7->field_0xeb8;
              iVar9 = FUN_000809e2();
              uVar4 = FUN_00080a3a();
              iVar10 = FUN_000809e2();
              uVar5 = FUN_00080a3a();
              _reflash_fb_data_to_lcd(iVar17,iVar18,iVar9,uVar4 + 0x1c,iVar10 + 0x240,uVar5 + 0x37);
            }
            iVar9 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            gui_bmp_bitmap_draw(0x42,iVar9 + 0x178,uVar4 + 0x1c,0,0,0);
          }
          else if (DAT_20002f88 != 0x16) {
            DAT_20002f88 = 0x16;
            pGVar7 = __get_dashboard_state();
            iVar9 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            iVar10 = FUN_000809e2();
            uVar5 = FUN_00080a3a();
            _clean_fb_data((int)&pGVar7->field_0xb90,0,iVar9,uVar4 + 0x1c,iVar10 + 0x240,
                           uVar5 + 0x37);
            pGVar7 = __get_dashboard_state();
            iVar17 = *(int *)&pGVar7->field_0xeb4;
            pGVar7 = __get_dashboard_state();
            iVar18 = *(int *)&pGVar7->field_0xeb8;
            iVar9 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            iVar10 = FUN_000809e2();
            uVar5 = FUN_00080a3a();
            _reflash_fb_data_to_lcd(iVar17,iVar18,iVar9,uVar4 + 0x1c,iVar10 + 0x240,uVar5 + 0x37);
          }
          iVar9 = FUN_000809e2();
          uVar8 = (uint)DAT_20002f88;
          uVar4 = FUN_00080a3a();
          gui_bmp_bitmap_draw(0x3e,uVar8 + iVar9 + 0x144,uVar4 + 0x1c,0,0,0);
        }
        local_94 = 0;
        local_90[0] = 0;
        local_90[1] = 0;
        uVar8 = FUN_00080732();
        FUN_0004d1e0(uVar8,(undefined2 *)&local_94);
        iVar9 = FUN_000807aa(local_94 & 0xffff,local_94 >> 0x10,local_90[0] & 0xffff);
        get_string(iVar9 + 0x28U & 0xff);
        local_80 = 0;
        memset(local_7c,0,0x10);
        if (*(char *)(param_1 + 0x5f) == '\0') {
          pcVar14 = "%s, %02d/%02d";
        }
        else if (*(char *)(param_1 + 0x5f) == '\x01') {
          pcVar14 = "%s, %02d-%02d";
        }
        else {
          pcVar14 = "%s, %02d/%02d";
        }
        FUN_0008a6b0((char *)&local_80,0,0x14,(byte *)pcVar14);
        iVar9 = FUN_000809e2();
        uVar8 = (uint)DAT_20002f88;
        uVar4 = FUN_00080a3a();
        iVar10 = FUN_000809e2();
        uVar8 = uVar8 + iVar9 + 0x98;
        iVar9 = (uint)DAT_20002f88 + iVar10 + 0x124;
      }
      uVar5 = FUN_00080a3a();
      gui_utf_draw_align_right
                (0,(char *)&local_80,3,uVar8,uVar4 + 0x1c,iVar9,uVar5 + 0x37,1,0,0,(undefined *)0x0,
                 0);
      pGVar7 = __get_dashboard_state();
      cVar3 = pGVar7->glasses_state_struct_0FF0->field_0x5e;
      uVar8 = FUN_00080732();
      iVar9 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      iVar10 = FUN_000809e2();
      uVar5 = FUN_00080a3a();
      gui_clock_draw(uVar8,iVar9 + 0xea,uVar4 + 0x4c,iVar10 + 0x180,uVar5 + 0x6d,1,cVar3 != '\x01');
      return;
    }
    if (param_4 != 0) {
      return;
    }
    if (((DAT_20004b14 != uVar8) || (DAT_20004b11 != 0)) ||
       (uVar15 = (uint)PANE_MODE, uVar15 != *(byte *)(param_1 + 0x66))) {
      gui_screen_clear(uVar11,uVar13,uVar15);
      PANE_MODE = *(byte *)(param_1 + 0x66);
      DAT_20004b11 = *(byte *)(param_1 + 0x65);
      DAT_20004b14 = uVar8;
      if (2 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): display_mode = %d ,exec screen clear\n");
        }
        else {
          ble_printk("%s(): display_mode = %d ,exec screen clear\n","DashBoard_Reflash",
                     (uint)DAT_20004b11,BLE_DEBUG);
        }
      }
    }
    local_a0 = 0;
    local_9c = 0;
    local_98 = 0;
    if (uVar8 != 1) {
      uVar8 = FUN_00080732();
      FUN_0004d1e0(uVar8,(undefined2 *)&local_a0);
      iVar9 = FUN_000807aa(local_a0 & 0xffff,local_a0 >> 0x10,local_9c & 0xffff);
      get_string(iVar9 + 0x28U & 0xff);
      local_94 = 0;
      memset(local_90,0,0x10);
      if (*(char *)(param_1 + 0x5f) == '\0') {
        pcVar14 = "%s, %02d/%02d";
      }
      else if (*(char *)(param_1 + 0x5f) == '\x01') {
        pcVar14 = "%s, %02d-%02d";
      }
      else {
        pcVar14 = "%s, %02d/%02d";
      }
      FUN_0008a6b0((char *)&local_94,0,0x14,(byte *)pcVar14);
      iVar9 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      iVar10 = FUN_000809e2();
      uVar5 = FUN_00080a3a();
      gui_utf_draw(0,(char *)&local_94,3,iVar9 + 0x2e,(uint)uVar4,iVar10 + 0xb9,uVar5 + 0x1b,1,0,0,
                   (undefined *)0x0,0);
      pGVar7 = __get_dashboard_state();
      cVar3 = pGVar7->glasses_state_struct_0FF0->field_0x5e;
      uVar8 = FUN_00080732();
      iVar9 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      iVar10 = FUN_000809e2();
      uVar5 = FUN_00080a3a();
      gui_clock_draw(uVar8,iVar9 + 0x2e,uVar4 + 0x34,iVar10 + 0xc3,uVar5 + 0x55,1,cVar3 != '\x01');
      if (param_3 == 1) {
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        gui_bmp_bitmap_draw(0x3e,iVar9 + 0x2e,uVar4 + 0x6d,0,0,0);
        if (*(char *)(param_1 + 0x60) == '\x01') {
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          gui_bmp_bitmap_draw(0x42,iVar9 + 0x8e,uVar4 + 0x6d,0,0,0);
        }
        else {
          pGVar7 = __get_dashboard_state();
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          iVar10 = FUN_000809e2();
          uVar5 = FUN_00080a3a();
          _clean_fb_data((int)&pGVar7->field_0xb90,0,iVar9 + 0x8e,uVar4 + 0x6d,iVar10 + 0xa6,
                         uVar5 + 0x88);
          pGVar7 = __get_dashboard_state();
          iVar17 = *(int *)&pGVar7->field_0xeb4;
          pGVar7 = __get_dashboard_state();
          iVar18 = *(int *)&pGVar7->field_0xeb8;
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          iVar10 = FUN_000809e2();
          uVar5 = FUN_00080a3a();
          _reflash_fb_data_to_lcd
                    (iVar17,iVar18,iVar9 + 0x8e,uVar4 + 0x6d,iVar10 + 0xa6,uVar5 + 0x88);
        }
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        gui_bmp_bitmap_draw(0x5a,iVar9 + 0x214,uVar4 + 4,0,0,0);
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        gui_bmp_bitmap_draw(0x59,iVar9 + 0xd4,uVar4 + 4,0,0,0);
      }
      else if (param_3 != 4) {
        return;
      }
      uVar8 = (uint)PANE_MODE;
      if (uVar8 == 0) {
        local_80 = uVar8;
        memset(local_7c,0,0x1c);
        iVar9 = 0;
        iVar10 = 0;
        do {
          if (*(char *)(iVar9 * 0x143 + *(int *)(param_2 + 0x1030) + 3) == '\x01') {
            if (2 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): quick note num.%d is vaild\n");
              }
              else {
                ble_printk("%s(): quick note num.%d is vaild\n","DashBoard_Reflash",iVar9,BLE_DEBUG)
                ;
              }
            }
            iVar10 = iVar10 + 1;
          }
          iVar9 = iVar9 + 1;
        } while (iVar9 != 4);
        if (2 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): total quick note num = %d\n");
          }
          else {
            ble_printk("%s(): total quick note num = %d\n","DashBoard_Reflash",iVar10,BLE_DEBUG);
          }
        }
        DAT_20004afa = (char)iVar10;
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        gui_bmp_bitmap_draw(0x3b,iVar9 + 0xe0,uVar4 + 2,0,0,0);
        if (iVar10 == 0) {
          iVar9 = FUN_000806de(&DAT_2000aa10);
          if ((-1 < iVar9 << 0x1e) || (DAT_20004b02 != '\x01')) goto LAB_00039194;
          DAT_20004b02 = (char)iVar10;
          pGVar7 = __get_dashboard_state();
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          iVar10 = FUN_000809e2();
          uVar5 = FUN_00080a3a();
          _clean_fb_data((int)&pGVar7->field_0xb90,0,iVar9 + 0x128,uVar4 + 1,iVar10 + 0x208,
                         uVar5 + 0x1c);
          pGVar7 = __get_dashboard_state();
          iVar17 = *(int *)&pGVar7->field_0xeb4;
          pGVar7 = __get_dashboard_state();
          iVar18 = *(int *)&pGVar7->field_0xeb8;
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          iVar10 = FUN_000809e2();
          uVar5 = FUN_00080a3a();
          _reflash_fb_data_to_lcd(iVar17,iVar18,iVar9 + 0x128,uVar4 + 1,iVar10 + 0x23a,uVar5 + 0x1c)
          ;
          pGVar7 = __get_dashboard_state();
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          iVar10 = FUN_000809e2();
          uVar5 = FUN_00080a3a();
          _clean_fb_data((int)&pGVar7->field_0xb90,0,iVar9 + 0x10a,uVar4 + 0x1c,iVar10 + 0x208,
                         uVar5 + 0x88);
          pGVar7 = __get_dashboard_state();
          iVar17 = *(int *)&pGVar7->field_0xeb4;
          pGVar7 = __get_dashboard_state();
          iVar18 = *(int *)&pGVar7->field_0xeb8;
          iVar9 = FUN_000809e2();
          uVar5 = FUN_00080a3a();
          iVar10 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          iVar10 = iVar10 + 0x208;
          goto LAB_00039182;
        }
        DAT_20004b02 = '\x01';
        memset(&local_80,0,0x20);
        snprintf((char *)&local_80,0x20,"%d/%d",DAT_20004af9 + 1,iVar10);
        uVar8 = (uint)DAT_20004af9;
        iVar18 = *(int *)(param_2 + 0x1030);
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        iVar17 = FUN_000809e2();
        uVar5 = FUN_00080a3a();
        gui_utf_draw(0,(char *)(iVar18 + uVar8 * 0x143 + 4),0,iVar9 + 0xfc,uVar4 + 1,iVar17 + 0x1d6,
                     uVar5 + 0x1c,1,0,0,(undefined *)0x0,0);
        if (iVar10 == 1) {
          iVar10 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          iVar9 = FUN_000809e2();
          uVar5 = FUN_00080a3a();
          pcVar14 = " ";
        }
        else {
          iVar10 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          iVar9 = FUN_000809e2();
          uVar5 = FUN_00080a3a();
          pcVar14 = (char *)&local_80;
        }
        gui_utf_draw(0,pcVar14,0,iVar10 + 0x1e4,uVar4 + 1,iVar9 + 0x212,uVar5 + 0x1c,1,0,0,
                     (undefined *)0x0,0);
        pcVar14 = (char *)(uVar8 * 0x143 + 0x2d + *(int *)(param_2 + 0x1030));
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        iVar10 = FUN_000809e2();
        uVar5 = FUN_00080a3a();
        iVar10 = iVar10 + 0x208;
        iVar9 = iVar9 + 0xe0;
        goto LAB_000398be;
      }
      if (uVar8 == 1) {
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        iVar10 = uVar4 + 2;
        uVar8 = 0x43;
        iVar9 = iVar9 + 0xe0;
LAB_0003a97c:
        gui_bmp_bitmap_draw(uVar8,iVar9,iVar10,0,0,0);
      }
      else {
        if (uVar8 == 2) {
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          iVar10 = uVar4 + 2;
          uVar8 = 0x47;
          iVar9 = iVar9 + 0xe0;
          goto LAB_0003a97c;
        }
        if (uVar8 == 4) {
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          iVar10 = uVar4 + 2;
          uVar8 = 0x48;
          iVar9 = iVar9 + 0xe0;
          goto LAB_0003a97c;
        }
      }
      pcVar14 = get_string(0x4f);
      iVar10 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      iVar9 = FUN_000809e2();
      uVar5 = FUN_00080a3a();
      iVar9 = iVar9 + 0x20a;
      iVar10 = iVar10 + 0xe0;
      goto LAB_0003a9be;
    }
    uVar8 = FUN_00080732();
    FUN_0004d1e0(uVar8,(undefined2 *)&local_a0);
    iVar9 = FUN_000807aa(local_a0 & 0xffff,local_a0 >> 0x10,local_9c & 0xffff);
    get_string(iVar9 + 0x28U & 0xff);
    local_94 = 0;
    memset(local_90,0,0x10);
    if (*(char *)(param_1 + 0x5f) == '\0') {
      pcVar14 = "%s, %02d/%02d";
    }
    else if (*(char *)(param_1 + 0x5f) == '\x01') {
      pcVar14 = "%s, %02d-%02d";
    }
    else {
      pcVar14 = "%s, %02d/%02d";
    }
    FUN_0008a6b0((char *)&local_94,0,0x14,(byte *)pcVar14);
    iVar9 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    iVar10 = FUN_000809e2();
    uVar5 = FUN_00080a3a();
    gui_utf_draw(0,(char *)&local_94,3,iVar9,uVar4 + 2,iVar10 + 0x8c,uVar5 + 0x1d,1,0,0,
                 (undefined *)0x0,0);
    pGVar7 = __get_dashboard_state();
    cVar3 = pGVar7->glasses_state_struct_0FF0->field_0x5e;
    uVar8 = FUN_00080732();
    iVar9 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    iVar10 = FUN_000809e2();
    uVar5 = FUN_00080a3a();
    gui_clock_draw(uVar8,iVar9,uVar4 + 0x22,iVar10 + 0x96,uVar5 + 0x43,1,cVar3 != '\x01');
    if (param_3 == 1) {
      iVar9 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      gui_bmp_bitmap_draw(0x5a,iVar9 + 0x23e,uVar4 + 4,0,0,0);
      iVar9 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      gui_bmp_bitmap_draw(0x59,iVar9 + 0xfe,uVar4 + 4,0,0,0);
      if (2 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): weather icon num = %d\n");
        }
        else {
          ble_printk("%s(): weather icon num = %d\n","DashBoard_Reflash",
                     (uint)*(byte *)(param_1 + 4),BLE_DEBUG);
        }
      }
      local_a8 = 0;
      local_a4 = 0;
      if ((*(byte *)(param_1 + 4) - 1 & 0xff) < 0xfe) {
        uVar8 = FUN_0004916c((uint)*(byte *)(param_1 + 4));
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        gui_bmp_bitmap_draw(uVar8,iVar9 + 0xa0,uVar4 + 1,0,0,0);
        pGVar7 = __get_dashboard_state();
        iVar9 = (int)*(char *)(param_1 + 5);
        local_a8 = (uint)(byte)pGVar7->glasses_state_struct_0FF0->field_0x5d;
        if (local_a8 == 0) {
          local_a4 = local_a8;
          if (2 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): temperature = %d\n");
            }
            else {
              ble_printk("%s(): temperature = %d\n","DashBoard_Reflash",iVar9,BLE_DEBUG);
            }
          }
          snprintf((char *)&local_a8,8,"%d",iVar9);
          local_80 = 0;
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          iVar10 = FUN_000809e2();
          uVar5 = FUN_00080a3a();
          gui_string_draw(3,(byte *)&local_a8,iVar9 + 0xbc,uVar4 + 1,iVar10 + 0xf8,uVar5 + 0x1c,
                          &local_80);
          bVar2 = 0x2a;
        }
        else {
          local_a8 = 0;
          local_a4 = 0;
          iVar9 = (iVar9 * 9) / 5 + 0x20;
          if (2 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): fahrenheit_temperature = %d\n");
            }
            else {
              ble_printk("%s(): fahrenheit_temperature = %d\n","DashBoard_Reflash",iVar9,BLE_DEBUG);
            }
          }
          snprintf((char *)&local_a8,8,"%d",iVar9);
          local_80 = 0;
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          iVar10 = FUN_000809e2();
          uVar5 = FUN_00080a3a();
          gui_string_draw(3,(byte *)&local_a8,iVar9 + 0xbc,uVar4 + 1,iVar10 + 0xf8,uVar5 + 0x1c,
                          &local_80);
          bVar2 = 0x23;
        }
        local_a4 = 0;
        local_a8 = (uint)bVar2;
        iVar9 = FUN_000809e2();
        iVar10 = iVar9 + 0xbc + local_80;
        uVar4 = FUN_00080a3a();
        iVar9 = FUN_000809e2();
        iVar9 = local_80 + iVar9;
        uVar5 = FUN_00080a3a();
        gui_string_draw(3,(byte *)&local_a8,iVar10,uVar4 + 1,iVar9 + 0xcb,uVar5 + 0x1c,(int *)0x0);
      }
      iVar9 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      gui_bmp_bitmap_draw(0x3c,iVar9 + 0xa0,uVar4 + 0x25,0,0,0);
      uVar8 = FUN_00035310();
      if ((int)uVar8 < 0xb) {
        pcVar14 = "%d";
      }
      else {
        pcVar14 = "%d+";
        uVar8 = 10;
      }
      local_a8 = 0;
      local_a4 = 0;
      snprintf((char *)&local_a8,8,pcVar14,uVar8);
      iVar9 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      iVar10 = FUN_000809e2();
      uVar5 = FUN_00080a3a();
      gui_string_draw(3,(byte *)&local_a8,iVar9 + 0xbc,uVar4 + 0x25,iVar10 + 0xe8,uVar5 + 0x40,
                      (int *)0x0);
      if (*(char *)(param_1 + 0x60) == '\x01') {
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        gui_bmp_bitmap_draw(0x42,iVar9 + 0xdc,uVar4 + 0x25,0,0,0);
      }
      else {
        pGVar7 = __get_dashboard_state();
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        iVar10 = FUN_000809e2();
        uVar5 = FUN_00080a3a();
        _clean_fb_data((int)&pGVar7->field_0xb90,0,iVar9 + 0xdc,uVar4 + 0x25,iVar10 + 0xf4,
                       uVar5 + 0x40);
        pGVar7 = __get_dashboard_state();
        iVar17 = *(int *)&pGVar7->field_0xeb4;
        pGVar7 = __get_dashboard_state();
        iVar18 = *(int *)&pGVar7->field_0xeb8;
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        iVar10 = FUN_000809e2();
        uVar5 = FUN_00080a3a();
        _reflash_fb_data_to_lcd(iVar17,iVar18,iVar9 + 0xdc,uVar4 + 0x25,iVar10 + 0xf4,uVar5 + 0x40);
      }
      iVar9 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      gui_bmp_bitmap_draw(0x39,iVar9,uVar4 + 0x56,0,0,0);
      if (DAT_20004b18 != *(char *)(param_1 + 0x67)) {
        DAT_20004b18 = *(char *)(param_1 + 0x67);
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        iVar10 = FUN_000809e2();
        uVar5 = FUN_00080a3a();
        gui_area_clear(iVar9 + 0x1c,uVar4 + 0x51,iVar10 + 0xf2,uVar5 + 0x6c);
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        iVar10 = FUN_000809e2();
        uVar5 = FUN_00080a3a();
        gui_area_clear(iVar9,uVar4 + 0x6c,iVar10 + 0xf2,uVar5 + 0x87);
      }
      if (DAT_20004b18 == '\0') {
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        iVar10 = FUN_000809e2();
        uVar5 = FUN_00080a3a();
        gui_area_clear(iVar9 + 0x1c,uVar4 + 0x51,iVar10 + 0xf2,uVar5 + 0x6c);
        pcVar14 = get_string(0x4d);
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        iVar10 = FUN_000809e2();
        uVar5 = FUN_00080a3a();
        iVar18 = uVar4 + 0x6c;
        iVar17 = uVar5 + 0x89;
        iVar10 = iVar10 + 0xf2;
      }
      else if (DAT_20004b18 == '\x01') {
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        iVar10 = FUN_000809e2();
        uVar5 = FUN_00080a3a();
        gui_area_clear(iVar9 + 0x1c,uVar4 + 0x51,iVar10 + 0xf2,uVar5 + 0x6c);
        pcVar14 = get_string(0x4b);
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        iVar10 = FUN_000809e2();
        uVar5 = FUN_00080a3a();
        iVar10 = iVar10 + 0xf2;
        iVar17 = uVar5 + 0x89;
        iVar18 = uVar4 + 0x6e;
      }
      else if (DAT_20004b18 == '\x02') {
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        iVar10 = FUN_000809e2();
        uVar5 = FUN_00080a3a();
        gui_area_clear(iVar9 + 0x1c,uVar4 + 0x51,iVar10 + 0xf2,uVar5 + 0x6c);
        pcVar14 = get_string(0x4a);
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        iVar10 = FUN_000809e2();
        uVar5 = FUN_00080a3a();
        iVar17 = uVar5 + 0x89;
        iVar18 = uVar4 + 0x6e;
        iVar10 = iVar10 + 0xf2;
      }
      else {
        if (DAT_20004b18 != '\x03') goto LAB_00038fc6;
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        iVar10 = FUN_000809e2();
        uVar5 = FUN_00080a3a();
        gui_utf_draw(0,&DAT_20012530,0,iVar9 + 0x1c,uVar4 + 0x51,iVar10 + 0xf2,uVar5 + 0x6c,1,0,0,
                     (undefined *)0x0,0);
        local_80 = 0;
        memset(local_7c,0,0x54);
        sVar12 = ____strlen(&DAT_20012571);
        memcpy(&local_80,&DAT_20012571,sVar12);
        sVar12 = ____strlen(&DAT_20012571);
        *(undefined1 *)((int)local_7c + (sVar12 - 4)) = 0x20;
        n = ____strlen(&DAT_20012592);
        memcpy((void *)((int)local_7c + (sVar12 - 3)),&DAT_20012592,n);
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        iVar10 = FUN_000809e2();
        uVar5 = FUN_00080a3a();
        iVar10 = iVar10 + 0xf2;
        iVar18 = uVar4 + 0x6c;
        iVar17 = uVar5 + 0x87;
        pcVar14 = (char *)&local_80;
      }
      gui_utf_draw(0,pcVar14,0,iVar9,iVar18,iVar10,iVar17,1,0,0,(undefined *)0x0,0);
    }
    else if (param_3 != 4) {
      return;
    }
LAB_00038fc6:
    uVar8 = (uint)PANE_MODE;
    if (uVar8 == 0) {
      local_80 = uVar8;
      memset(local_7c,0,0x1c);
      iVar9 = 0;
      iVar10 = 0;
      do {
        if (*(char *)(iVar9 * 0x143 + *(int *)(param_2 + 0x1030) + 3) == '\x01') {
          if (2 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): quick note num.%d is vaild\n");
            }
            else {
              ble_printk("%s(): quick note num.%d is vaild\n","DashBoard_Reflash",iVar9,BLE_DEBUG);
            }
          }
          iVar10 = iVar10 + 1;
        }
        iVar9 = iVar9 + 1;
      } while (iVar9 != 4);
      if (2 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): total quick note num = %d\n");
        }
        else {
          ble_printk("%s(): total quick note num = %d\n","DashBoard_Reflash",iVar10,BLE_DEBUG);
        }
      }
      DAT_20004afa = (char)iVar10;
      iVar9 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      gui_bmp_bitmap_draw(0x3b,iVar9 + 0x10a,uVar4 + 2,0,0,0);
      if (iVar10 == 0) {
        iVar9 = FUN_000806de(&DAT_2000aa10);
        if ((-1 < iVar9 << 0x1e) || (DAT_20004b02 != '\x01')) goto LAB_00039194;
        DAT_20004b02 = (char)iVar10;
        pGVar7 = __get_dashboard_state();
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        iVar10 = FUN_000809e2();
        uVar5 = FUN_00080a3a();
        _clean_fb_data((int)&pGVar7->field_0xb90,0,iVar9 + 0x128,uVar4 + 1,iVar10 + 0x23a,
                       uVar5 + 0x1c);
        pGVar7 = __get_dashboard_state();
        iVar17 = *(int *)&pGVar7->field_0xeb4;
        pGVar7 = __get_dashboard_state();
        iVar18 = *(int *)&pGVar7->field_0xeb8;
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        iVar10 = FUN_000809e2();
        uVar5 = FUN_00080a3a();
        _reflash_fb_data_to_lcd(iVar17,iVar18,iVar9 + 0x128,uVar4 + 1,iVar10 + 0x23a,uVar5 + 0x1c);
        pGVar7 = __get_dashboard_state();
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        iVar10 = FUN_000809e2();
        uVar5 = FUN_00080a3a();
        _clean_fb_data((int)&pGVar7->field_0xb90,0,iVar9 + 0x10a,uVar4 + 0x1c,iVar10 + 0x232,
                       uVar5 + 0x88);
        pGVar7 = __get_dashboard_state();
        iVar17 = *(int *)&pGVar7->field_0xeb4;
        pGVar7 = __get_dashboard_state();
        iVar18 = *(int *)&pGVar7->field_0xeb8;
        iVar9 = FUN_000809e2();
        uVar5 = FUN_00080a3a();
        iVar10 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        iVar10 = iVar10 + 0x232;
LAB_00039182:
        _reflash_fb_data_to_lcd(iVar17,iVar18,iVar9 + 0x10a,uVar5 + 0x1c,iVar10,uVar4 + 0x88);
LAB_00039194:
        FUN_00038b00();
        FUN_000386c0();
        return;
      }
      DAT_20004b02 = '\x01';
      memset(&local_80,0,0x20);
      snprintf((char *)&local_80,0x20,"%d/%d",DAT_20004af9 + 1,iVar10);
      uVar8 = (uint)DAT_20004af9;
      iVar18 = *(int *)(param_2 + 0x1030);
      iVar9 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      iVar17 = FUN_000809e2();
      uVar5 = FUN_00080a3a();
      gui_utf_draw(0,(char *)(iVar18 + uVar8 * 0x143 + 4),0,iVar9 + 0x128,uVar4 + 1,iVar17 + 0x212,
                   uVar5 + 0x1c,1,0,0,(undefined *)0x0,0);
      if (iVar10 == 1) {
        iVar10 = FUN_000809e2();
        uVar5 = FUN_00080a3a();
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        pcVar14 = " ";
      }
      else {
        iVar10 = FUN_000809e2();
        uVar5 = FUN_00080a3a();
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        pcVar14 = (char *)&local_80;
      }
      gui_utf_draw(0,pcVar14,0,iVar10 + 0x218,uVar5 + 1,iVar9 + 0x23a,uVar4 + 0x1c,1,0,0,
                   (undefined *)0x0,0);
      pcVar14 = (char *)(uVar8 * 0x143 + 0x2d + *(int *)(param_2 + 0x1030));
      iVar9 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      iVar10 = FUN_000809e2();
      uVar5 = FUN_00080a3a();
      iVar10 = iVar10 + 0x238;
      iVar9 = iVar9 + 0x10a;
LAB_000398be:
      iVar17 = uVar5 + 0x88;
      iVar18 = uVar4 + 0x1c;
      goto LAB_0003a208;
    }
    if (uVar8 == 1) {
      iVar9 = 0;
      iVar10 = 0;
      do {
        iVar17 = iVar9 * 0x7f2;
        iVar9 = iVar9 + 1;
        if ((&DAT_2000e104)[iVar17] == '\x01') {
          iVar10 = iVar10 + 1;
        }
      } while (iVar9 != 4);
      cVar3 = *(char *)(param_1 + 0x69);
      if (cVar3 != '\0') {
        if (cVar3 == '\x01') {
          if (DAT_20004b19 != '\x01') {
            DAT_20004b19 = cVar3;
            iVar9 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            iVar17 = FUN_000809e2();
            uVar5 = FUN_00080a3a();
            gui_area_clear(iVar9 + 0x100,(uint)uVar4,iVar17 + 0x23c,uVar5 + 0x88);
          }
          if (2 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): db_info->stocks_disp_mode = %d\n");
            }
            else {
              ble_printk("%s(): db_info->stocks_disp_mode = %d\n","DashBoard_Reflash",
                         (uint)*(byte *)(param_1 + 0x69),BLE_DEBUG);
            }
          }
          if (iVar10 == 0) {
            cleanStocksIndex();
          }
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          uVar8 = 0x43;
LAB_00039a6e:
          gui_bmp_bitmap_draw(uVar8,iVar9 + 0x10a,uVar4 + 2,0,0,0);
          pcVar14 = get_string(0x4b);
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          iVar10 = FUN_000809e2();
          uVar5 = FUN_00080a3a();
          gui_utf_draw_middle(0,pcVar14,0,iVar9 + 0x10a,uVar4 + 0x2a,iVar10 + 0x234,uVar5 + 0x45,1,0
                              ,0,(undefined *)0x0,0);
          pcVar14 = get_string(0x4c);
          iVar10 = FUN_000809e2();
          uVar5 = FUN_00080a3a();
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          iVar10 = iVar10 + 0x10a;
          goto LAB_00039af2;
        }
        if (cVar3 != '\x02') {
          return;
        }
        if (DAT_20004b19 != '\x02') {
          DAT_20004b19 = cVar3;
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          iVar10 = FUN_000809e2();
          uVar5 = FUN_00080a3a();
          gui_area_clear(iVar9 + 0x100,uVar4 + 4,iVar10 + 0x23c,uVar5 + 0x88);
        }
        iVar9 = 0;
        iVar10 = 0;
        do {
          iVar17 = iVar9 * 0x7f2;
          iVar9 = iVar9 + 1;
          if ((&DAT_2000e104)[iVar17] == '\x01') {
            iVar10 = iVar10 + 1;
          }
        } while (iVar9 != 4);
        DAT_20004afc = (undefined1)iVar10;
        uVar8 = (uint)DAT_20004afb;
        cVar3 = (&DAT_2000e105)[uVar8 * 0x7f2];
        if (cVar3 == '\0') {
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          iVar17 = uVar4 + 2;
          uVar15 = 0x46;
          iVar9 = iVar9 + 0x10a;
LAB_00039b98:
          gui_bmp_bitmap_draw(uVar15,iVar9,iVar17,0,0,0);
        }
        else {
          if (cVar3 == '\x01') {
            iVar9 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            iVar17 = uVar4 + 2;
            uVar15 = 0x44;
            iVar9 = iVar9 + 0x10a;
            goto LAB_00039b98;
          }
          if (cVar3 == '\x02') {
            iVar9 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            iVar17 = uVar4 + 2;
            uVar15 = 0x45;
            iVar9 = iVar9 + 0x10a;
            goto LAB_00039b98;
          }
        }
        if (iVar10 == 0) {
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          iVar10 = FUN_000809e2();
          uVar5 = FUN_00080a3a();
          gui_area_clear(iVar9 + 0x218,uVar4 + 1,iVar10 + 0x23a,uVar5 + 0x1c);
        }
        else {
          local_80 = 0;
          memset(local_7c,0,0x1c);
          snprintf((char *)&local_80,0x20,"%d/%d",uVar8 + 1,iVar10);
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          iVar10 = FUN_000809e2();
          uVar5 = FUN_00080a3a();
          gui_utf_draw(0,(char *)&local_80,0,iVar9 + 0x218,uVar4 + 1,iVar10 + 0x23a,uVar5 + 0x1c,1,0
                       ,0,(undefined *)0x0,0);
        }
        iVar17 = uVar8 * 0x7f2;
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        iVar10 = FUN_000809e2();
        uVar5 = FUN_00080a3a();
        gui_utf_draw(0,(char *)(iVar17 + 0x2000e108),0,iVar9 + 0x126,(uint)uVar4,iVar10 + 0x200,
                     uVar5 + 0x1b,1,0,0,(undefined *)0x0,0);
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        iVar10 = FUN_000809e2();
        uVar5 = FUN_00080a3a();
        gui_utf_draw(0,(char *)(iVar17 + 0x2000e128),0,iVar9 + 0x10a,uVar4 + 0x1b,iVar10 + 0x232,
                     uVar5 + 0x36,1,0,0,(undefined *)0x0,0);
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        iVar10 = FUN_000809e2();
        uVar5 = FUN_00080a3a();
        gui_utf_draw_align_right
                  (0,(char *)(iVar17 + 0x2000e168),0,iVar9 + 0x1d2,uVar4 + 0x36,iVar10 + 0x232,
                   uVar5 + 0x51,1,0,0,(undefined *)0x0,0);
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        iVar10 = FUN_000809e2();
        uVar5 = FUN_00080a3a();
        gui_utf_draw_align_right
                  (0,(char *)(iVar17 + 0x2000e178),0,iVar9 + 0x1d2,uVar4 + 0x51,iVar10 + 0x232,
                   uVar5 + 0x6c,1,0,0,(undefined *)0x0,0);
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        iVar10 = FUN_000809e2();
        uVar5 = FUN_00080a3a();
        gui_utf_draw_align_right
                  (0,(char *)(iVar17 + 0x2000e188),0,iVar9 + 0x1d2,uVar4 + 0x6c,iVar10 + 0x232,
                   uVar5 + 0x87,1,0,0,(undefined *)0x0,0);
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        iVar10 = FUN_000809e2();
        uVar5 = FUN_00080a3a();
        iVar10 = iVar10 + 0x1c2;
        uVar8 = iVar9 + 0x10a;
        goto LAB_00039d7e;
      }
      if (2 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): db_info->stocks_disp_mode = %d\n","DashBoard_Reflash");
        }
        else {
          ble_printk("%s(): db_info->stocks_disp_mode = %d\n","DashBoard_Reflash",0,0);
        }
      }
      if (DAT_20004b19 != *(char *)(param_1 + 0x69)) {
        DAT_20004b19 = *(char *)(param_1 + 0x69);
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        iVar17 = FUN_000809e2();
        uVar5 = FUN_00080a3a();
        gui_area_clear(iVar9 + 0x100,uVar4 + 4,iVar17 + 0x23c,uVar5 + 0x88);
      }
      if (iVar10 == 0) {
        cleanStocksIndex();
      }
      iVar9 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      iVar10 = uVar4 + 2;
      uVar8 = 0x43;
      iVar9 = iVar9 + 0x10a;
LAB_0003999e:
      gui_bmp_bitmap_draw(uVar8,iVar9,iVar10,0,0,0);
      pcVar14 = get_string(0x4d);
      iVar10 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      iVar9 = FUN_000809e2();
      uVar5 = FUN_00080a3a();
      uVar8 = 1;
      iVar17 = uVar5 + 0x51;
LAB_000399ce:
      iVar18 = uVar4 + 0x36;
    }
    else {
      if (uVar8 == 2) {
        iVar9 = 0;
        local_80 = 0;
        iVar10 = 0;
        memset(local_7c,0,0x1c);
        do {
          if ((&DAT_20011281)[iVar10 * 0x159] == '\x01') {
            if (2 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): news num.%d is vaild\n");
              }
              else {
                ble_printk("%s(): news num.%d is vaild\n","DashBoard_Reflash",iVar10,BLE_DEBUG);
              }
            }
            iVar9 = iVar9 + 1;
          }
          iVar10 = iVar10 + 1;
        } while (iVar10 != 4);
        cVar3 = *(char *)(param_1 + 0x6a);
        if (cVar3 == '\0') {
          if (DAT_20004b1a != '\0') {
            DAT_20004b1a = cVar3;
            iVar10 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            iVar17 = FUN_000809e2();
            uVar5 = FUN_00080a3a();
            gui_area_clear(iVar10 + 0x100,uVar4 + 4,iVar17 + 0x23c,uVar5 + 0x88);
          }
          if (iVar9 == 0) {
            cleanNewsIndex();
          }
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          iVar10 = uVar4 + 2;
          uVar8 = 0x47;
          iVar9 = iVar9 + 0x10a;
          goto LAB_0003999e;
        }
        if (cVar3 == '\x01') {
          if (DAT_20004b1a != '\x01') {
            DAT_20004b1a = cVar3;
            iVar10 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            iVar17 = FUN_000809e2();
            uVar5 = FUN_00080a3a();
            gui_area_clear(iVar10 + 0x100,(uint)uVar4,iVar17 + 0x23c,uVar5 + 0x88);
          }
          if (iVar9 == 0) {
            cleanNewsIndex();
          }
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          uVar8 = 0x47;
          goto LAB_00039a6e;
        }
        if (cVar3 != '\x04') {
          if (cVar3 != '\x02') {
            return;
          }
          if (DAT_20004b1a != '\x02') {
            DAT_20004b1a = cVar3;
            iVar10 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            iVar17 = FUN_000809e2();
            uVar5 = FUN_00080a3a();
            gui_area_clear(iVar10 + 0x100,(uint)uVar4,iVar17 + 0x23c,uVar5 + 0x88);
          }
          if (2 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): total news num = %d\n");
            }
            else {
              ble_printk("%s(): total news num = %d\n","DashBoard_Reflash",iVar9,BLE_DEBUG);
            }
          }
          DAT_20004afe = (char)iVar9;
          iVar10 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          gui_bmp_bitmap_draw(0x47,iVar10 + 0x10a,uVar4 + 2,0,0,0);
          if (iVar9 != 0) {
            DAT_20004b03 = '\x01';
            memset(&local_80,0,0x20);
            snprintf((char *)&local_80,0x20,"%d/%d",DAT_20004afd + 1,iVar9);
            uVar8 = (uint)DAT_20004afd;
            iVar10 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            iVar17 = FUN_000809e2();
            uVar5 = FUN_00080a3a();
            gui_utf_draw(0,(char *)(uVar8 * 0x159 + 0x20011282),0,iVar10 + 0x128,uVar4 + 1,
                         iVar17 + 0x212,uVar5 + 0x1c,1,0,0,(undefined *)0x0,0);
            if (iVar9 == 1) {
              iVar10 = FUN_000809e2();
              uVar5 = FUN_00080a3a();
              iVar9 = FUN_000809e2();
              uVar4 = FUN_00080a3a();
              pcVar14 = " ";
            }
            else {
              iVar10 = FUN_000809e2();
              uVar5 = FUN_00080a3a();
              iVar9 = FUN_000809e2();
              uVar4 = FUN_00080a3a();
              pcVar14 = (char *)&local_80;
            }
            gui_utf_draw(0,pcVar14,0,iVar10 + 0x218,uVar5 + 1,iVar9 + 0x23a,uVar4 + 0x1c,1,0,0,
                         (undefined *)0x0,0);
            iVar9 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            iVar10 = FUN_000809e2();
            uVar5 = FUN_00080a3a();
            iVar17 = uVar5 + 0x88;
            iVar10 = iVar10 + 0x238;
            iVar18 = uVar4 + 0x1c;
            iVar9 = iVar9 + 0x10a;
            pcVar14 = (char *)(uVar8 * 0x159 + 0x200112c2);
            goto LAB_0003a208;
          }
          iVar10 = FUN_000806de(&DAT_2000aa10);
          if ((-1 < iVar10 << 0x1e) || (DAT_20004b03 != '\x01')) goto LAB_0003a10c;
          DAT_20004b03 = (char)iVar9;
          pGVar7 = __get_dashboard_state();
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          iVar10 = FUN_000809e2();
          uVar5 = FUN_00080a3a();
          _clean_fb_data((int)&pGVar7->field_0xb90,0,iVar9 + 0x128,uVar4 + 1,iVar10 + 0x23a,
                         uVar5 + 0x1c);
          pGVar7 = __get_dashboard_state();
          iVar17 = *(int *)&pGVar7->field_0xeb4;
          pGVar7 = __get_dashboard_state();
          iVar18 = *(int *)&pGVar7->field_0xeb8;
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          iVar10 = FUN_000809e2();
          uVar5 = FUN_00080a3a();
          _reflash_fb_data_to_lcd(iVar17,iVar18,iVar9 + 0x128,uVar4 + 1,iVar10 + 0x23a,uVar5 + 0x1c)
          ;
          pGVar7 = __get_dashboard_state();
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          iVar10 = FUN_000809e2();
          uVar5 = FUN_00080a3a();
          _clean_fb_data((int)&pGVar7->field_0xb90,0,iVar9 + 0x10a,uVar4 + 0x1c,iVar10 + 0x232,
                         uVar5 + 0x88);
          pGVar7 = __get_dashboard_state();
          iVar17 = *(int *)&pGVar7->field_0xeb4;
          pGVar7 = __get_dashboard_state();
          iVar18 = *(int *)&pGVar7->field_0xeb8;
          iVar9 = FUN_000809e2();
          uVar5 = FUN_00080a3a();
          iVar10 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          iVar10 = iVar10 + 0x232;
          iVar9 = iVar9 + 0x10a;
          goto LAB_0003a104;
        }
        if (DAT_20004b1a != '\x04') {
          DAT_20004b1a = '\x04';
          iVar10 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          iVar17 = FUN_000809e2();
          uVar5 = FUN_00080a3a();
          gui_area_clear(iVar10 + 0x100,(uint)uVar4,iVar17 + 0x23c,uVar5 + 0x88);
        }
        if (iVar9 == 0) {
          cleanNewsIndex();
        }
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        gui_bmp_bitmap_draw(0x47,iVar9 + 0x10a,uVar4 + 2,0,0,0);
        pcVar14 = get_string(0x51);
        iVar10 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        iVar9 = FUN_000809e2();
        uVar5 = FUN_00080a3a();
        uVar8 = 2;
        iVar17 = uVar5 + 0x6c;
        goto LAB_000399ce;
      }
      if (uVar8 != 4) {
        return;
      }
      cVar3 = *(char *)(param_1 + 0x6b);
      if (cVar3 == '\0') {
LAB_0003a260:
        if (DAT_20004b1b != cVar3) {
          DAT_20004b1b = cVar3;
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          iVar10 = FUN_000809e2();
          uVar5 = FUN_00080a3a();
          gui_area_clear(iVar9 + 0x100,(uint)uVar4,iVar10 + 0x23c,uVar5 + 0x88);
        }
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        iVar10 = uVar4 + 2;
        uVar8 = 0x48;
        iVar9 = iVar9 + 0x10a;
        goto LAB_0003999e;
      }
      if (DAT_20004b1c == '\0') {
        if (DAT_2001111d == '\0') goto LAB_0003a260;
        if (cVar3 != '\x01') {
          if (cVar3 != '\x03') {
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
      else if (cVar3 != '\x01') {
        if (cVar3 != '\x03') {
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
        pGVar7 = __get_dashboard_state();
        pGVar7->glasses_state_struct_0FF0->field_0x71 = 0;
LAB_0003a324:
        if (DAT_20004b1b != *(char *)(param_1 + 0x6b)) {
          DAT_20004b1b = *(char *)(param_1 + 0x6b);
          iVar9 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          iVar10 = FUN_000809e2();
          uVar5 = FUN_00080a3a();
          gui_area_clear(iVar9 + 0x100,(uint)uVar4,iVar10 + 0x23c,uVar5 + 0x88);
        }
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        iVar10 = FUN_000809e2();
        uVar5 = FUN_00080a3a();
        gui_bitmap_draw(iVar9 + 0x10a,(uint)uVar4,iVar10 + 0x232,uVar5 + 0x88,0x200143cf,2);
        iVar9 = FUN_000809e2();
        uVar8 = iVar9 + 0x10a + (uint)*(ushort *)(param_1 + 0x6d);
        uVar4 = FUN_00080a3a();
        iVar17 = (uint)*(ushort *)(param_1 + 0x6f) + (uint)uVar4;
        iVar9 = FUN_000809e2();
        uVar4 = *(ushort *)(param_1 + 0x6d);
        uVar5 = FUN_00080a3a();
        puVar16 = &DAT_20015777;
        iVar10 = (uint)uVar4 + iVar9 + 0x12a;
        iVar9 = (uint)*(ushort *)(param_1 + 0x6f) + (uint)uVar5;
        goto LAB_0003a3c2;
      }
      if (DAT_20004b1b != '\x01') {
        DAT_20004b1b = '\x01';
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        iVar10 = FUN_000809e2();
        uVar5 = FUN_00080a3a();
        gui_area_clear(iVar9 + 0x100,(uint)uVar4,iVar10 + 0x23c,uVar5 + 0x88);
      }
      iVar9 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      gui_bmp_bitmap_draw(0x48,iVar9 + 0x10a,uVar4 + 2,0,0,0);
      pcVar14 = get_string(0x50);
      iVar10 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      iVar9 = FUN_000809e2();
      uVar5 = FUN_00080a3a();
      iVar17 = uVar5 + 0x60;
      uVar8 = 2;
      iVar18 = uVar4 + 0x2a;
    }
    iVar10 = iVar10 + 0x10a;
LAB_000399e0:
    iVar9 = iVar9 + 0x234;
  }
LAB_000399e2:
  gui_utf_draw_middle(0,pcVar14,0,iVar10,iVar18,iVar9,iVar17,uVar8,0,0,(undefined *)0x0,0);
switchD_0003b01c_default:
  return;
}


