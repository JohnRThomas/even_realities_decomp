/*
 * Function: navigation_overview_map_display
 * Entry:    0004036c
 * Prototype: undefined __stdcall navigation_overview_map_display(undefined4 param_1, int param_2)
 */


void navigation_overview_map_display(undefined4 param_1,int param_2)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  GlassesState *pGVar4;
  int iVar5;
  dashboard_ts_context *pdVar6;
  int iVar7;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  undefined4 extraout_r1_02;
  int iVar8;
  int iVar9;
  byte **buffer;
  uint32_t uVar10;
  uint uVar11;
  k_timeout_t timeout;
  k_timeout_t timeout_00;
  k_timeout_t timeout_01;
  k_timeout_t timeout_02;
  byte local_30 [12];
  
  if (DAT_20004d75 == '\0') {
    if (2 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): reflash overview map && text\n","navigation_overview_map_display");
      }
      else {
        ble_printk("%s(): reflash overview map && text\n");
      }
    }
    pGVar4 = __get_dashboard_state();
    iVar9 = 0x640;
    buffer = &(pGVar4->jdb_panel_context).__panel_buffer;
    while( true ) {
      uVar11 = 0;
      do {
        iVar8 = 0;
        do {
          bVar1 = buffer[uVar11][iVar8];
          if (bVar1 != 0) {
            buffer[uVar11][iVar8] = bVar1 & (&DAT_000accab)[iVar8 + (uVar11 % 0x1a) * 0xa00 + iVar9]
            ;
          }
          iVar8 = iVar8 + 1;
        } while (iVar8 != 0x140);
        uVar11 = uVar11 + 1;
      } while (uVar11 != 199);
      pGVar4 = __get_dashboard_state();
      uVar10 = (pGVar4->jdb_panel_context).current_row;
      pGVar4 = __get_dashboard_state();
      _reflash_fb_data_to_lcd(uVar10,(pGVar4->jdb_panel_context).current_column,0,0,0x280,199);
      if (iVar9 == 0x500) break;
      iVar9 = 0x500;
    }
    if ((DAT_20010dc1 == '\x01') && (DAT_2001c74e == '\0')) {
      if (*(int *)(param_2 + 0xb1) == 0x1210) {
        if (2 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): Data is in raw format.\n","navigation_overview_map_display");
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
            printk("%s(): Data is in rle compress raw format.\n","navigation_overview_map_display");
          }
          else {
            ble_printk("%s(): Data is in rle compress raw format.\n");
          }
        }
        memset(&DAT_2001c74f,0,0x1210);
        timeout_01.ticks._4_4_ = 0xffffffff;
        timeout_01.ticks._0_4_ = extraout_r1_01;
        z_impl_k_mutex_lock(&k_mutex_20007f54,timeout_01);
        FUN_000811c6(&DAT_20016b1f,*(uint *)(param_2 + 0xb1),(int)&DAT_2001c74f);
      }
      DAT_2001c74e = '\x01';
      z_impl_k_mutex_unlock(&k_mutex_20007f54);
    }
    __clear_showing_notification_on_gui();
    iVar9 = 1;
    do {
      _clean_fb_data((byte *)buffer,0,0,0,0x280,199);
      iVar8 = FUN_000809e2();
      uVar2 = FUN_00080a3a();
      iVar5 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      gui_bitmps_merge_draw
                (iVar8 + 0x1b6,(uint)uVar2,iVar5 + 0x240,uVar3 + 0x88,0x2001c74f,(int)&DAT_2001d057,
                 2,0xf);
      memset(&DAT_2001c6cd,0,0x80);
      snprintf(&DAT_2001c6cd,0x80,"%s %s",(char *)(param_2 + 0xd),(char *)(param_2 + 0x25));
      iVar8 = FUN_000809e2();
      uVar2 = FUN_00080a3a();
      iVar5 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      gui_utf_draw(0,&DAT_2001c6cd,0,iVar8 + 0xe8,(uint)uVar2,iVar5 + 0x1ae,uVar3 + 0x1b,1,0,0,
                   (undefined *)0x0,0);
      iVar8 = FUN_000809e2();
      uVar2 = FUN_00080a3a();
      iVar5 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      gui_utf_draw(0,(char *)(param_2 + 0x7d),0,iVar8,uVar2 + 0x6c,iVar5 + 200,uVar3 + 0x87,1,0,0,
                   (undefined *)0x0,0);
      iVar8 = FUN_000809e2();
      uVar2 = FUN_00080a3a();
      iVar5 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      gui_utf_draw(0,(char *)(param_2 + 0x3d),0,iVar8,uVar2 + 0x1d,iVar5 + 0x1ae,uVar3 + 0x38,1,0,0,
                   (undefined *)0x0,0);
      pGVar4 = __get_dashboard_state();
      iVar8 = pGVar4->dashboard_ts->time_disp_mode;
      pdVar6 = (dashboard_ts_context *)FUN_00080732();
      iVar5 = FUN_000809e2();
      uVar2 = FUN_00080a3a();
      iVar7 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      gui_clock_draw(pdVar6,iVar5,uVar2 + 2,iVar7 + 0x4c,uVar3 + 0x1d,3,(char)iVar8 != '\x01');
      navigation_direction_img_display((uint)*(byte *)(param_2 + 1));
      uVar11 = 0;
      do {
        iVar8 = 0;
        do {
          local_30[0] = 1;
          local_30[1] = 3;
          local_30[2] = 5;
          local_30[3] = 7;
          local_30[4] = 7;
          local_30[5] = 7;
          local_30[6] = 7;
          local_30[7] = 7;
          bVar1 = buffer[uVar11][iVar8];
          if (bVar1 != 0) {
            buffer[uVar11][iVar8] =
                 bVar1 & (&DAT_000accab)
                         [iVar8 + (uint)local_30[iVar9] * 0x140 + (uVar11 % 0x1a) * 0xa00];
          }
          iVar8 = iVar8 + 1;
        } while (iVar8 != 0x140);
        uVar11 = uVar11 + 1;
      } while (uVar11 != 199);
      pGVar4 = __get_dashboard_state();
      uVar10 = (pGVar4->jdb_panel_context).current_row;
      pGVar4 = __get_dashboard_state();
      iVar9 = iVar9 + 1;
      _reflash_fb_data_to_lcd(uVar10,(pGVar4->jdb_panel_context).current_column,0,0,0x280,199);
    } while (iVar9 != 4);
    __set_showing_notification_on_gui();
    iVar9 = FUN_000809e2();
    uVar2 = FUN_00080a3a();
    iVar8 = FUN_000809e2();
    uVar3 = FUN_00080a3a();
    gui_utf_draw(0,&DAT_2001c6cd,0,iVar9 + 0xe8,(uint)uVar2,iVar8 + 0x1ae,uVar3 + 0x1b,1,0,0,
                 (undefined *)0x0,0);
    iVar9 = FUN_000809e2();
    uVar2 = FUN_00080a3a();
    iVar8 = FUN_000809e2();
    uVar3 = FUN_00080a3a();
    gui_utf_draw(0,(char *)(param_2 + 0x7d),0,iVar9,uVar2 + 0x6c,iVar8 + 200,uVar3 + 0x87,1,0,0,
                 (undefined *)0x0,0);
    iVar9 = FUN_000809e2();
    uVar2 = FUN_00080a3a();
    iVar8 = FUN_000809e2();
    uVar3 = FUN_00080a3a();
    gui_utf_draw(0,(char *)(param_2 + 0x3d),0,iVar9,uVar2 + 0x1d,iVar8 + 0x1ae,uVar3 + 0x38,1,0,0,
                 (undefined *)0x0,0);
    pGVar4 = __get_dashboard_state();
    iVar9 = pGVar4->dashboard_ts->time_disp_mode;
    pdVar6 = (dashboard_ts_context *)FUN_00080732();
    iVar8 = FUN_000809e2();
    uVar2 = FUN_00080a3a();
    iVar5 = FUN_000809e2();
    uVar3 = FUN_00080a3a();
    gui_clock_draw(pdVar6,iVar8,uVar2 + 2,iVar5 + 0x4c,uVar3 + 0x1d,3,(char)iVar9 != '\x01');
  }
  if (DAT_20010dbe != '\x01') goto LAB_00040954;
  if (DAT_20010dc1 == '\x01') {
    if (2 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): reflash overview map ....\n","navigation_overview_map_display");
      }
      else {
        ble_printk("%s(): reflash overview map ....\n");
      }
    }
    if (*(int *)(param_2 + 0xb1) == 0x1210) {
      if (2 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): Data is in raw format.\n","navigation_overview_map_display");
        }
        else {
          ble_printk("%s(): Data is in raw format.\n");
        }
      }
      memset(&DAT_2001c74f,0,0x1210);
      timeout_00.ticks._4_4_ = 0xffffffff;
      timeout_00.ticks._0_4_ = extraout_r1_00;
      z_impl_k_mutex_lock(&k_mutex_20007f54,timeout_00);
      memcpy(&DAT_2001c74f,&DAT_20016b1f,0x1210);
    }
    else {
      if (2 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): Data is in rle compress raw format.\n","navigation_overview_map_display");
        }
        else {
          ble_printk("%s(): Data is in rle compress raw format.\n");
        }
      }
      memset(&DAT_2001c74f,0,0x1210);
      timeout_02.ticks._4_4_ = 0xffffffff;
      timeout_02.ticks._0_4_ = extraout_r1_02;
      z_impl_k_mutex_lock(&k_mutex_20007f54,timeout_02);
      FUN_000811c6(&DAT_20016b1f,*(uint *)(param_2 + 0xb1),(int)&DAT_2001c74f);
    }
    DAT_2001c74e = '\x01';
    z_impl_k_mutex_unlock(&k_mutex_20007f54);
LAB_0004087c:
    iVar9 = FUN_000809e2();
    uVar2 = FUN_00080a3a();
    iVar8 = FUN_000809e2();
    uVar3 = FUN_00080a3a();
    gui_bitmps_merge_draw
              (iVar9 + 0x1b6,(uint)uVar2,iVar8 + 0x240,uVar3 + 0x88,0x2001c74f,(int)&DAT_2001d057,2,
               0xf);
  }
  else if (DAT_2001c74e == '\x01') goto LAB_0004087c;
  DAT_20010dbe = '\0';
LAB_00040954:
  if (DAT_20010dbf == '\x01') {
    if (2 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): reflash text info ....\n","navigation_overview_map_display");
      }
      else {
        ble_printk("%s(): reflash text info ....\n");
      }
    }
    memset(&DAT_2001c6cd,0,0x80);
    snprintf(&DAT_2001c6cd,0x80,"%s %s",(char *)(param_2 + 0xd),(char *)(param_2 + 0x25));
    iVar9 = FUN_000809e2();
    uVar2 = FUN_00080a3a();
    iVar8 = FUN_000809e2();
    uVar3 = FUN_00080a3a();
    gui_utf_draw(0,&DAT_2001c6cd,0,iVar9 + 0xe8,(uint)uVar2,iVar8 + 0x1ae,uVar3 + 0x1b,1,0,0,
                 (undefined *)0x0,0);
    iVar9 = FUN_000809e2();
    uVar2 = FUN_00080a3a();
    iVar8 = FUN_000809e2();
    uVar3 = FUN_00080a3a();
    gui_utf_draw(0,(char *)(param_2 + 0x3d),0,iVar9,uVar2 + 0x1d,iVar8 + 0x1ae,uVar3 + 0x38,1,0,0,
                 (undefined *)0x0,0);
    iVar9 = FUN_000809e2();
    uVar2 = FUN_00080a3a();
    iVar8 = FUN_000809e2();
    uVar3 = FUN_00080a3a();
    gui_utf_draw(0,(char *)(param_2 + 0x7d),0,iVar9,uVar2 + 0x6c,iVar8 + 200,uVar3 + 0x87,1,0,0,
                 (undefined *)0x0,0);
    pGVar4 = __get_dashboard_state();
    iVar9 = pGVar4->dashboard_ts->time_disp_mode;
    pdVar6 = (dashboard_ts_context *)FUN_00080732();
    iVar8 = FUN_000809e2();
    uVar2 = FUN_00080a3a();
    iVar5 = FUN_000809e2();
    uVar3 = FUN_00080a3a();
    gui_clock_draw(pdVar6,iVar8,uVar2 + 2,iVar5 + 0x4c,uVar3 + 0x1d,3,(char)iVar9 != '\x01');
    navigation_direction_img_display((uint)*(byte *)(param_2 + 1));
    DAT_20010dbf = '\0';
  }
  DAT_20004d74 = 0;
  DAT_20004d75 = 1;
  DAT_20004d85 = 0;
  return;
}


