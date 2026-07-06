/*
 * Function: navigation_panoramic_map_display
 * Entry:    00040b08
 * Prototype: undefined __stdcall navigation_panoramic_map_display(undefined4 param_1, int param_2)
 */


void navigation_panoramic_map_display(undefined4 param_1,int param_2)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  GlassesState *pGVar5;
  int iVar6;
  dashboard_ts_context *pdVar7;
  int iVar8;
  int iVar9;
  char *pcVar10;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  byte **buffer;
  uint32_t uVar11;
  int iVar12;
  uint32_t uVar13;
  uint uVar14;
  k_timeout_t timeout;
  k_timeout_t timeout_00;
  byte local_30 [12];
  
  if (DAT_20004d74 == '\0') {
    if (2 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): reflash panoramic map to lcd\n","navigation_panoramic_map_display");
      }
      else {
        ble_printk("%s(): reflash panoramic map to lcd\n");
      }
    }
    pGVar5 = __get_dashboard_state();
    iVar12 = 0x640;
    buffer = &(pGVar5->jdb_panel_context).__panel_buffer;
    while( true ) {
      uVar14 = 0;
      do {
        iVar9 = 0;
        do {
          bVar1 = buffer[uVar14][iVar9];
          if (bVar1 != 0) {
            buffer[uVar14][iVar9] =
                 bVar1 & (&DAT_000accab)[iVar9 + (uVar14 % 0x1a) * 0xa00 + iVar12];
          }
          iVar9 = iVar9 + 1;
        } while (iVar9 != 0x140);
        uVar14 = uVar14 + 1;
      } while (uVar14 != 199);
      pGVar5 = __get_dashboard_state();
      uVar11 = (pGVar5->jdb_panel_context).current_row;
      pGVar5 = __get_dashboard_state();
      _reflash_fb_data_to_lcd(uVar11,(pGVar5->jdb_panel_context).current_column,0,0,0x280,199);
      if (iVar12 == 0x500) break;
      iVar12 = 0x500;
    }
    __clear_showing_notification_on_gui();
    iVar12 = 1;
    do {
      _clean_fb_data((byte *)buffer,0,0,0,0x280,199);
      if (DAT_20010dc0 == '\x01') {
        iVar9 = FUN_000809e2();
        uVar2 = FUN_00080a3a();
        iVar6 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        gui_bitmps_merge_draw
                  (iVar9 + 0x58,(uint)uVar2,iVar6 + 0x240,uVar3 + 0x88,(int)&DAT_20012a4f,
                   (int)&DAT_20014ab7,2,0xf);
        uVar2 = *(ushort *)(param_2 + 8);
        if ((uVar2 < 0x1e9) && (*(ushort *)(param_2 + 10) < 0x89)) {
          iVar9 = FUN_000809e2();
          uVar3 = *(ushort *)(param_2 + 10);
          uVar4 = FUN_00080a3a();
          gui_4bit_bitmap_override(0x5f,(uint)uVar2 + iVar9 + 0x52,(uVar3 - 6) + (uint)uVar4);
        }
        else if (0 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): APP send navigation offset overstep ,stop draw....\n",
                   "navigation_panoramic_map_display");
          }
          else {
            ble_printk("%s(): APP send navigation offset overstep ,stop draw....\n");
          }
        }
        iVar9 = FUN_000809e2();
        uVar2 = FUN_00080a3a();
        iVar6 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        gui_utf_draw(0,(char *)(param_2 + 0x95),0,iVar9,uVar2 + 0x37,iVar6 + 0x4c,uVar3 + 0x52,1,0,0
                     ,(undefined *)0x0,0);
        iVar9 = FUN_000809e2();
        uVar2 = FUN_00080a3a();
        iVar6 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        gui_utf_draw(0,(char *)(param_2 + 0xd),0,iVar9,uVar2 + 0x52,iVar6 + 0x4c,uVar3 + 0x6d,1,0,0,
                     (undefined *)0x0,0);
        iVar9 = FUN_000809e2();
        uVar2 = FUN_00080a3a();
        iVar6 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        gui_utf_draw(0,(char *)(param_2 + 0x25),0,iVar9,uVar2 + 0x6d,iVar6 + 0x4c,uVar3 + 0x88,1,0,0
                     ,(undefined *)0x0,0);
        DAT_2001c74d = '\x01';
      }
      else {
        pcVar10 = get_string(0x48);
        iVar9 = FUN_000809e2();
        uVar2 = FUN_00080a3a();
        iVar6 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        gui_utf_draw(0,pcVar10,0,iVar9,uVar2 + 0x37,iVar6 + 0x240,uVar3 + 0x88,3,0,0,
                     (undefined *)0x0,0);
        DAT_2001c74d = '\0';
      }
      pGVar5 = __get_dashboard_state();
      iVar9 = pGVar5->dashboard_ts->time_disp_mode;
      pdVar7 = (dashboard_ts_context *)FUN_00080732();
      iVar6 = FUN_000809e2();
      uVar2 = FUN_00080a3a();
      iVar8 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      gui_clock_draw(pdVar7,iVar6,uVar2 + 2,iVar8 + 0x4c,uVar3 + 0x1d,3,(char)iVar9 != '\x01');
      uVar14 = 0;
      do {
        iVar9 = 0;
        do {
          local_30[0] = 1;
          local_30[1] = 3;
          local_30[2] = 5;
          local_30[3] = 7;
          local_30[4] = 7;
          local_30[5] = 7;
          local_30[6] = 7;
          local_30[7] = 7;
          bVar1 = buffer[uVar14][iVar9];
          if (bVar1 != 0) {
            buffer[uVar14][iVar9] =
                 bVar1 & (&DAT_000accab)
                         [iVar9 + (uint)local_30[iVar12] * 0x140 + (uVar14 % 0x1a) * 0xa00];
          }
          iVar9 = iVar9 + 1;
        } while (iVar9 != 0x140);
        uVar14 = uVar14 + 1;
      } while (uVar14 != 199);
      pGVar5 = __get_dashboard_state();
      uVar11 = (pGVar5->jdb_panel_context).current_row;
      pGVar5 = __get_dashboard_state();
      iVar12 = iVar12 + 1;
      _reflash_fb_data_to_lcd(uVar11,(pGVar5->jdb_panel_context).current_column,0,0,0x280,199);
    } while (iVar12 != 4);
    __set_showing_notification_on_gui();
    if (DAT_20010dc0 == '\x01') {
      iVar12 = FUN_000809e2();
      uVar2 = FUN_00080a3a();
      iVar9 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      gui_utf_draw(0,(char *)(param_2 + 0x95),0,iVar12,uVar2 + 0x37,iVar9 + 0x4c,uVar3 + 0x52,1,0,0,
                   (undefined *)0x0,0);
      iVar12 = FUN_000809e2();
      uVar2 = FUN_00080a3a();
      iVar9 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      gui_utf_draw(0,(char *)(param_2 + 0xd),0,iVar12,uVar2 + 0x52,iVar9 + 0x4c,uVar3 + 0x6d,1,0,0,
                   (undefined *)0x0,0);
      iVar12 = FUN_000809e2();
      uVar2 = FUN_00080a3a();
      iVar9 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      gui_utf_draw(0,(char *)(param_2 + 0x25),0,iVar12,uVar2 + 0x6d,iVar9 + 0x4c,uVar3 + 0x88,1,0,0,
                   (undefined *)0x0,0);
    }
    pGVar5 = __get_dashboard_state();
    iVar12 = pGVar5->dashboard_ts->time_disp_mode;
    pdVar7 = (dashboard_ts_context *)FUN_00080732();
    iVar9 = FUN_000809e2();
    uVar2 = FUN_00080a3a();
    iVar6 = FUN_000809e2();
    uVar3 = FUN_00080a3a();
    gui_clock_draw(pdVar7,iVar9,uVar2 + 2,iVar6 + 0x4c,uVar3 + 0x1d,3,(char)iVar12 != '\x01');
  }
  if ((DAT_20010dbd == '\x01') || (DAT_20010dbc == '\x01')) {
    if (DAT_20010dbd == '\x01') {
      DAT_20010dbd = '\0';
    }
    if (DAT_20010dbc == '\x01') {
      DAT_20010dbc = '\0';
    }
    if (DAT_20010dc0 == '\x01') {
      iVar12 = FUN_000809e2();
      uVar2 = FUN_00080a3a();
      iVar9 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      gui_bitmps_merge_draw
                (iVar12 + 0x58,(uint)uVar2,iVar9 + 0x240,uVar3 + 0x88,(int)&DAT_20012a4f,
                 (int)&DAT_20014ab7,2,0xf);
      uVar2 = *(ushort *)(param_2 + 8);
      if ((uVar2 < 0x1e9) && (*(ushort *)(param_2 + 10) < 0x89)) {
        iVar12 = FUN_000809e2();
        uVar3 = *(ushort *)(param_2 + 10);
        uVar4 = FUN_00080a3a();
        gui_4bit_bitmap_override(0x5f,(uint)uVar2 + iVar12 + 0x52,(uVar3 - 6) + (uint)uVar4);
      }
      else if (0 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): APP send navigation offset overstep ,stop draw....\n",
                 "navigation_panoramic_map_display");
        }
        else {
          ble_printk("%s(): APP send navigation offset overstep ,stop draw....\n");
        }
      }
      if (DAT_2001c74d != '\0') goto LAB_000410ba;
      iVar12 = FUN_000809e2();
      uVar2 = FUN_00080a3a();
      iVar9 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      gui_utf_draw(0,(char *)(param_2 + 0x95),0,iVar12,uVar2 + 0x37,iVar9 + 0x4c,uVar3 + 0x52,1,0,0,
                   (undefined *)0x0,0);
      iVar12 = FUN_000809e2();
      uVar2 = FUN_00080a3a();
      iVar9 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      gui_utf_draw(0,(char *)(param_2 + 0xd),0,iVar12,uVar2 + 0x52,iVar9 + 0x4c,uVar3 + 0x6d,1,0,0,
                   (undefined *)0x0,0);
      iVar12 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      iVar9 = FUN_000809e2();
      uVar2 = FUN_00080a3a();
      iVar9 = iVar9 + 0x4c;
      iVar6 = uVar3 + 0x6d;
      uVar14 = 1;
      pcVar10 = (char *)(param_2 + 0x25);
    }
    else {
      pGVar5 = __get_dashboard_state();
      iVar12 = FUN_000809e2();
      uVar2 = FUN_00080a3a();
      iVar9 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      _clean_fb_data((byte *)&(pGVar5->jdb_panel_context).__panel_buffer,0,iVar12 + 0x58,(uint)uVar2
                     ,iVar9 + 0x240,uVar3 + 0x88);
      pGVar5 = __get_dashboard_state();
      uVar11 = (pGVar5->jdb_panel_context).current_row;
      pGVar5 = __get_dashboard_state();
      uVar13 = (pGVar5->jdb_panel_context).current_column;
      iVar12 = FUN_000809e2();
      uVar2 = FUN_00080a3a();
      iVar9 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      _reflash_fb_data_to_lcd(uVar11,uVar13,iVar12 + 0x58,(uint)uVar2,iVar9 + 0x240,uVar3 + 0x88);
      pcVar10 = get_string(0x48);
      iVar12 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      iVar9 = FUN_000809e2();
      uVar2 = FUN_00080a3a();
      iVar9 = iVar9 + 0x240;
      iVar6 = uVar3 + 0x37;
      uVar14 = 3;
    }
    gui_utf_draw(0,pcVar10,0,iVar12,iVar6,iVar9,uVar2 + 0x88,uVar14,0,0,(undefined *)0x0,0);
  }
LAB_000410ba:
  if (DAT_20010dbf == '\x01') {
    DAT_20010dbf = '\0';
    if (DAT_20010dc0 == '\x01') {
      iVar12 = FUN_000809e2();
      uVar2 = FUN_00080a3a();
      iVar9 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      gui_utf_draw(0,(char *)(param_2 + 0x95),0,iVar12,uVar2 + 0x37,iVar9 + 0x4c,uVar3 + 0x52,1,0,0,
                   (undefined *)0x0,0);
      iVar12 = FUN_000809e2();
      uVar2 = FUN_00080a3a();
      iVar9 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      gui_utf_draw(0,(char *)(param_2 + 0xd),0,iVar12,uVar2 + 0x52,iVar9 + 0x4c,uVar3 + 0x6d,1,0,0,
                   (undefined *)0x0,0);
      iVar12 = FUN_000809e2();
      uVar2 = FUN_00080a3a();
      iVar9 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      gui_utf_draw(0,(char *)(param_2 + 0x25),0,iVar12,uVar2 + 0x6d,iVar9 + 0x4c,uVar3 + 0x88,1,0,0,
                   (undefined *)0x0,0);
    }
    pGVar5 = __get_dashboard_state();
    iVar12 = pGVar5->dashboard_ts->time_disp_mode;
    pdVar7 = (dashboard_ts_context *)FUN_00080732();
    iVar9 = FUN_000809e2();
    uVar2 = FUN_00080a3a();
    iVar6 = FUN_000809e2();
    uVar3 = FUN_00080a3a();
    gui_clock_draw(pdVar7,iVar9,uVar2 + 2,iVar6 + 0x4c,uVar3 + 0x1d,3,(char)iVar12 != '\x01');
  }
  if (DAT_20010dbe == '\x01') {
    DAT_20010dbe = '\0';
    if (*(int *)(param_2 + 0xb1) == 0x1210) {
      if (2 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): Data is in raw format.\n","navigation_panoramic_map_display");
        }
        else {
          ble_printk("%s(): Data is in raw format.\n");
        }
      }
      memset(&DAT_2001c74f,0,0x1210);
      timeout.ticks._4_4_ = 0xffffffff;
      timeout.ticks._0_4_ = extraout_r1;
      z_impl_k_mutex_lock(&k_mutex_20007f54,timeout);
      memcpy(&DAT_2001c74f,&DAT_20016b1f,0x1210);
    }
    else {
      if (2 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): Data is in rle compress raw format.\n","navigation_panoramic_map_display");
        }
        else {
          ble_printk("%s(): Data is in rle compress raw format.\n");
        }
      }
      memset(&DAT_2001c74f,0,0x1210);
      timeout_00.ticks._4_4_ = 0xffffffff;
      timeout_00.ticks._0_4_ = extraout_r1_00;
      z_impl_k_mutex_lock(&k_mutex_20007f54,timeout_00);
      FUN_000811c6(&DAT_20016b1f,*(uint *)(param_2 + 0xb1),(int)&DAT_2001c74f);
    }
    DAT_2001c74e = 1;
    z_impl_k_mutex_unlock(&k_mutex_20007f54);
  }
  DAT_20004d74 = 1;
  DAT_20004d75 = 0;
  DAT_20004d85 = 0;
  return;
}


