/*
 * Function: navigation_panoramic_map_display
 * Entry:    00040b08
 * Prototype: undefined __stdcall navigation_panoramic_map_display(undefined4 param_1, int param_2, undefined4 param_3)
 */


void navigation_panoramic_map_display(undefined4 param_1,int param_2,undefined4 param_3)

{
  byte bVar1;
  char cVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  GlassesState *pGVar6;
  int iVar7;
  int iVar8;
  char *pcVar9;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  int *buffer;
  int iVar10;
  int iVar11;
  uint uVar12;
  k_timeout_t timeout;
  k_timeout_t timeout_00;
  byte local_30 [12];
  
  if (DAT_20004d74 == '\0') {
    if (2 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): reflash panoramic map to lcd\n");
      }
      else {
        ble_printk("%s(): reflash panoramic map to lcd\n","navigation_panoramic_map_display",param_3
                   ,BLE_DEBUG);
      }
    }
    pGVar6 = __get_dashboard_state();
    iVar10 = 0x640;
    buffer = &(pGVar6->jdb_panel_context).field9_0x24;
    while( true ) {
      uVar12 = 0;
      do {
        iVar8 = 0;
        do {
          bVar1 = *(byte *)(buffer[uVar12] + iVar8);
          if (bVar1 != 0) {
            *(byte *)(buffer[uVar12] + iVar8) =
                 bVar1 & (&DAT_000accab)[iVar8 + (uVar12 % 0x1a) * 0xa00 + iVar10];
          }
          iVar8 = iVar8 + 1;
        } while (iVar8 != 0x140);
        uVar12 = uVar12 + 1;
      } while (uVar12 != 199);
      pGVar6 = __get_dashboard_state();
      iVar8 = *(int *)&(pGVar6->jdb_panel_context).field_0x348;
      pGVar6 = __get_dashboard_state();
      _reflash_fb_data_to_lcd(iVar8,*(int *)&(pGVar6->jdb_panel_context).field_0x34c,0,0,0x280,199);
      if (iVar10 == 0x500) break;
      iVar10 = 0x500;
    }
    FUN_00045428();
    iVar10 = 1;
    do {
      _clean_fb_data(buffer,0,0,0,0x280,199);
      if (DAT_20010dc0 == '\x01') {
        iVar8 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        iVar7 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        gui_bitmps_merge_draw
                  (iVar8 + 0x58,(uint)uVar3,iVar7 + 0x240,uVar4 + 0x88,(int)&DAT_20012a4f,
                   (int)&DAT_20014ab7,2,0xf);
        uVar3 = *(ushort *)(param_2 + 8);
        if ((uVar3 < 0x1e9) && (*(ushort *)(param_2 + 10) < 0x89)) {
          iVar8 = FUN_000809e2();
          uVar4 = *(ushort *)(param_2 + 10);
          uVar5 = FUN_00080a3a();
          gui_4bit_bitmap_override(0x5f,(uint)uVar3 + iVar8 + 0x52,(uVar4 - 6) + (uint)uVar5);
        }
        else if (0 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): APP send navigation offset overstep ,stop draw....\n");
          }
          else {
            ble_printk("%s(): APP send navigation offset overstep ,stop draw....\n",
                       "navigation_panoramic_map_display",extraout_r2,BLE_DEBUG);
          }
        }
        iVar8 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        iVar7 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        gui_utf_draw(0,(char *)(param_2 + 0x95),0,iVar8,uVar3 + 0x37,iVar7 + 0x4c,uVar4 + 0x52,1,0,0
                     ,(undefined *)0x0,0);
        iVar8 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        iVar7 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        gui_utf_draw(0,(char *)(param_2 + 0xd),0,iVar8,uVar3 + 0x52,iVar7 + 0x4c,uVar4 + 0x6d,1,0,0,
                     (undefined *)0x0,0);
        iVar8 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        iVar7 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        gui_utf_draw(0,(char *)(param_2 + 0x25),0,iVar8,uVar3 + 0x6d,iVar7 + 0x4c,uVar4 + 0x88,1,0,0
                     ,(undefined *)0x0,0);
        DAT_2001c74d = '\x01';
      }
      else {
        pcVar9 = get_string(0x48);
        iVar8 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        iVar7 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        gui_utf_draw(0,pcVar9,0,iVar8,uVar3 + 0x37,iVar7 + 0x240,uVar4 + 0x88,3,0,0,(undefined *)0x0
                     ,0);
        DAT_2001c74d = '\0';
      }
      pGVar6 = __get_dashboard_state();
      cVar2 = pGVar6->glasses_state_struct_0FF0->field_0x5e;
      uVar12 = FUN_00080732();
      iVar8 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      iVar7 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      gui_clock_draw(uVar12,iVar8,uVar3 + 2,iVar7 + 0x4c,uVar4 + 0x1d,3,cVar2 != '\x01');
      uVar12 = 0;
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
          bVar1 = *(byte *)(buffer[uVar12] + iVar8);
          if (bVar1 != 0) {
            *(byte *)(buffer[uVar12] + iVar8) =
                 bVar1 & (&DAT_000accab)
                         [iVar8 + (uint)local_30[iVar10] * 0x140 + (uVar12 % 0x1a) * 0xa00];
          }
          iVar8 = iVar8 + 1;
        } while (iVar8 != 0x140);
        uVar12 = uVar12 + 1;
      } while (uVar12 != 199);
      pGVar6 = __get_dashboard_state();
      iVar8 = *(int *)&(pGVar6->jdb_panel_context).field_0x348;
      pGVar6 = __get_dashboard_state();
      iVar10 = iVar10 + 1;
      _reflash_fb_data_to_lcd(iVar8,*(int *)&(pGVar6->jdb_panel_context).field_0x34c,0,0,0x280,199);
    } while (iVar10 != 4);
    FUN_0004540c();
    if (DAT_20010dc0 == '\x01') {
      iVar10 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      iVar8 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      gui_utf_draw(0,(char *)(param_2 + 0x95),0,iVar10,uVar3 + 0x37,iVar8 + 0x4c,uVar4 + 0x52,1,0,0,
                   (undefined *)0x0,0);
      iVar10 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      iVar8 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      gui_utf_draw(0,(char *)(param_2 + 0xd),0,iVar10,uVar3 + 0x52,iVar8 + 0x4c,uVar4 + 0x6d,1,0,0,
                   (undefined *)0x0,0);
      iVar10 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      iVar8 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      gui_utf_draw(0,(char *)(param_2 + 0x25),0,iVar10,uVar3 + 0x6d,iVar8 + 0x4c,uVar4 + 0x88,1,0,0,
                   (undefined *)0x0,0);
    }
    pGVar6 = __get_dashboard_state();
    cVar2 = pGVar6->glasses_state_struct_0FF0->field_0x5e;
    uVar12 = FUN_00080732();
    iVar10 = FUN_000809e2();
    uVar3 = FUN_00080a3a();
    iVar8 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    gui_clock_draw(uVar12,iVar10,uVar3 + 2,iVar8 + 0x4c,uVar4 + 0x1d,3,cVar2 != '\x01');
  }
  if ((DAT_20010dbd == '\x01') || (DAT_20010dbc == '\x01')) {
    if (DAT_20010dbd == '\x01') {
      DAT_20010dbd = '\0';
    }
    if (DAT_20010dbc == '\x01') {
      DAT_20010dbc = '\0';
    }
    if (DAT_20010dc0 == '\x01') {
      iVar10 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      iVar8 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      gui_bitmps_merge_draw
                (iVar10 + 0x58,(uint)uVar3,iVar8 + 0x240,uVar4 + 0x88,(int)&DAT_20012a4f,
                 (int)&DAT_20014ab7,2,0xf);
      uVar3 = *(ushort *)(param_2 + 8);
      if ((uVar3 < 0x1e9) && (*(ushort *)(param_2 + 10) < 0x89)) {
        iVar10 = FUN_000809e2();
        uVar4 = *(ushort *)(param_2 + 10);
        uVar5 = FUN_00080a3a();
        gui_4bit_bitmap_override(0x5f,(uint)uVar3 + iVar10 + 0x52,(uVar4 - 6) + (uint)uVar5);
      }
      else if (0 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): APP send navigation offset overstep ,stop draw....\n");
        }
        else {
          ble_printk("%s(): APP send navigation offset overstep ,stop draw....\n",
                     "navigation_panoramic_map_display",extraout_r2_00,BLE_DEBUG);
        }
      }
      if (DAT_2001c74d != '\0') goto LAB_000410ba;
      iVar10 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      iVar8 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      gui_utf_draw(0,(char *)(param_2 + 0x95),0,iVar10,uVar3 + 0x37,iVar8 + 0x4c,uVar4 + 0x52,1,0,0,
                   (undefined *)0x0,0);
      iVar10 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      iVar8 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      gui_utf_draw(0,(char *)(param_2 + 0xd),0,iVar10,uVar3 + 0x52,iVar8 + 0x4c,uVar4 + 0x6d,1,0,0,
                   (undefined *)0x0,0);
      iVar10 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      iVar8 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      iVar8 = iVar8 + 0x4c;
      iVar7 = uVar4 + 0x6d;
      uVar12 = 1;
      pcVar9 = (char *)(param_2 + 0x25);
    }
    else {
      pGVar6 = __get_dashboard_state();
      iVar10 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      iVar8 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      _clean_fb_data(&(pGVar6->jdb_panel_context).field9_0x24,0,iVar10 + 0x58,(uint)uVar3,
                     iVar8 + 0x240,uVar4 + 0x88);
      pGVar6 = __get_dashboard_state();
      iVar7 = *(int *)&(pGVar6->jdb_panel_context).field_0x348;
      pGVar6 = __get_dashboard_state();
      iVar11 = *(int *)&(pGVar6->jdb_panel_context).field_0x34c;
      iVar10 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      iVar8 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      _reflash_fb_data_to_lcd(iVar7,iVar11,iVar10 + 0x58,(uint)uVar3,iVar8 + 0x240,uVar4 + 0x88);
      pcVar9 = get_string(0x48);
      iVar10 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      iVar8 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      iVar8 = iVar8 + 0x240;
      iVar7 = uVar4 + 0x37;
      uVar12 = 3;
    }
    gui_utf_draw(0,pcVar9,0,iVar10,iVar7,iVar8,uVar3 + 0x88,uVar12,0,0,(undefined *)0x0,0);
  }
LAB_000410ba:
  if (DAT_20010dbf == '\x01') {
    DAT_20010dbf = '\0';
    if (DAT_20010dc0 == '\x01') {
      iVar10 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      iVar8 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      gui_utf_draw(0,(char *)(param_2 + 0x95),0,iVar10,uVar3 + 0x37,iVar8 + 0x4c,uVar4 + 0x52,1,0,0,
                   (undefined *)0x0,0);
      iVar10 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      iVar8 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      gui_utf_draw(0,(char *)(param_2 + 0xd),0,iVar10,uVar3 + 0x52,iVar8 + 0x4c,uVar4 + 0x6d,1,0,0,
                   (undefined *)0x0,0);
      iVar10 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      iVar8 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      gui_utf_draw(0,(char *)(param_2 + 0x25),0,iVar10,uVar3 + 0x6d,iVar8 + 0x4c,uVar4 + 0x88,1,0,0,
                   (undefined *)0x0,0);
    }
    pGVar6 = __get_dashboard_state();
    cVar2 = pGVar6->glasses_state_struct_0FF0->field_0x5e;
    uVar12 = FUN_00080732();
    iVar10 = FUN_000809e2();
    uVar3 = FUN_00080a3a();
    iVar8 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    gui_clock_draw(uVar12,iVar10,uVar3 + 2,iVar8 + 0x4c,uVar4 + 0x1d,3,cVar2 != '\x01');
  }
  if (DAT_20010dbe == '\x01') {
    DAT_20010dbe = '\0';
    if (*(int *)(param_2 + 0xb1) == 0x1210) {
      if (2 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): Data is in raw format.\n");
        }
        else {
          ble_printk("%s(): Data is in raw format.\n","navigation_panoramic_map_display",0x1210,
                     BLE_DEBUG);
        }
      }
      memset(&DAT_2001c74f,0,0x1210);
      timeout.ticks._4_4_ = 0xffffffff;
      timeout.ticks._0_4_ = extraout_r1;
      z_impl_k_mutex_lock((k_mutex *)&DAT_20007f54,timeout);
      memcpy(&DAT_2001c74f,&DAT_20016b1f,0x1210);
    }
    else {
      if (2 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): Data is in rle compress raw format.\n");
        }
        else {
          ble_printk("%s(): Data is in rle compress raw format.\n",
                     "navigation_panoramic_map_display",0x1210,BLE_DEBUG);
        }
      }
      memset(&DAT_2001c74f,0,0x1210);
      timeout_00.ticks._4_4_ = 0xffffffff;
      timeout_00.ticks._0_4_ = extraout_r1_00;
      z_impl_k_mutex_lock((k_mutex *)&DAT_20007f54,timeout_00);
      FUN_000811c6(&DAT_20016b1f,*(uint *)(param_2 + 0xb1),(int)&DAT_2001c74f);
    }
    DAT_2001c74e = 1;
    z_impl_k_mutex_unlock((k_mutex *)&DAT_20007f54);
  }
  DAT_20004d74 = 1;
  DAT_20004d75 = 0;
  DAT_20004d85 = 0;
  return;
}


