/*
 * Function: navigation_overview_map_display
 * Entry:    0004036c
 * Prototype: undefined __stdcall navigation_overview_map_display(undefined4 param_1, int param_2, undefined4 param_3)
 */


void navigation_overview_map_display(undefined4 param_1,int param_2,undefined4 param_3)

{
  char cVar1;
  byte bVar2;
  ushort uVar3;
  ushort uVar4;
  GlassesState *pGVar5;
  int iVar6;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  undefined4 extraout_r1_02;
  undefined4 extraout_r1_03;
  undefined4 extraout_r1_04;
  int iVar7;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 extraout_r2_02;
  int iVar8;
  undefined1 *puVar9;
  uint uVar10;
  k_timeout_t timeout;
  k_timeout_t timeout_00;
  k_timeout_t timeout_01;
  k_timeout_t timeout_02;
  byte local_30 [12];
  
  if (DAT_20004d75 == '\0') {
    if (2 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): reflash overview map && text\n");
      }
      else {
        ble_printk("%s(): reflash overview map && text\n","navigation_overview_map_display",param_3,
                   BLE_DEBUG);
      }
    }
    pGVar5 = __get_dashboard_state();
    iVar8 = 0x640;
    puVar9 = &pGVar5->field_0xb90;
    while( true ) {
      uVar10 = 0;
      do {
        iVar7 = 0;
        do {
          bVar2 = *(byte *)(*(int *)(puVar9 + uVar10 * 4) + iVar7);
          if (bVar2 != 0) {
            *(byte *)(*(int *)(puVar9 + uVar10 * 4) + iVar7) =
                 bVar2 & (&DAT_000accab)[iVar7 + (uVar10 % 0x1a) * 0xa00 + iVar8];
          }
          iVar7 = iVar7 + 1;
        } while (iVar7 != 0x140);
        uVar10 = uVar10 + 1;
      } while (uVar10 != 199);
      pGVar5 = __get_dashboard_state();
      iVar7 = *(int *)&pGVar5->field_0xeb4;
      pGVar5 = __get_dashboard_state();
      _reflash_fb_data_to_lcd(iVar7,*(int *)&pGVar5->field_0xeb8,0,0,0x280,199);
      if (iVar8 == 0x500) break;
      iVar8 = 0x500;
    }
    if ((DAT_20010dc1 == '\x01') && (DAT_2001c74e == '\0')) {
      if (*(int *)(param_2 + 0xb1) == 0x1210) {
        if (2 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): Data is in raw format.\n");
          }
          else {
            ble_printk("%s(): Data is in raw format.\n","navigation_overview_map_display",0x1210,
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
                       "navigation_overview_map_display",0x1210,BLE_DEBUG);
          }
        }
        memset(&DAT_2001c74f,0,0x1210);
        timeout_01.ticks._4_4_ = 0xffffffff;
        timeout_01.ticks._0_4_ = extraout_r1_02;
        z_impl_k_mutex_lock((k_mutex *)&DAT_20007f54,timeout_01);
        FUN_000811c6(&DAT_20016b1f,*(uint *)(param_2 + 0xb1),(int)&DAT_2001c74f);
      }
      DAT_2001c74e = '\x01';
      z_impl_k_mutex_unlock((k_mutex *)&DAT_20007f54);
    }
    FUN_00045428();
    iVar8 = 1;
    do {
      _clean_fb_data((int)puVar9,0,0,0,0x280,199);
      iVar7 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      iVar6 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      gui_bitmps_merge_draw
                (iVar7 + 0x1b6,(uint)uVar3,iVar6 + 0x240,uVar4 + 0x88,0x2001c74f,(int)&DAT_2001d057,
                 2,0xf);
      memset(&DAT_2001c6cd,0,0x80);
      snprintf(&DAT_2001c6cd,0x80,"%s %s",(char *)(param_2 + 0xd),(char *)(param_2 + 0x25));
      iVar7 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      iVar6 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      gui_utf_draw(0,&DAT_2001c6cd,0,iVar7 + 0xe8,(uint)uVar3,iVar6 + 0x1ae,uVar4 + 0x1b,1,0,0,
                   (undefined *)0x0,0);
      iVar7 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      iVar6 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      gui_utf_draw(0,(char *)(param_2 + 0x7d),0,iVar7,uVar3 + 0x6c,iVar6 + 200,uVar4 + 0x87,1,0,0,
                   (undefined *)0x0,0);
      iVar7 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      iVar6 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      gui_utf_draw(0,(char *)(param_2 + 0x3d),0,iVar7,uVar3 + 0x1d,iVar6 + 0x1ae,uVar4 + 0x38,1,0,0,
                   (undefined *)0x0,0);
      pGVar5 = __get_dashboard_state();
      cVar1 = pGVar5->glasses_state_struct_0FF0->field_0x5e;
      uVar10 = FUN_00080732();
      iVar7 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      iVar6 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      gui_clock_draw(uVar10,iVar7,uVar3 + 2,iVar6 + 0x4c,uVar4 + 0x1d,3,cVar1 != '\x01');
      navigation_direction_img_display((uint)*(byte *)(param_2 + 1),extraout_r1_00,extraout_r2);
      uVar10 = 0;
      do {
        iVar7 = 0;
        do {
          local_30[0] = 1;
          local_30[1] = 3;
          local_30[2] = 5;
          local_30[3] = 7;
          local_30[4] = 7;
          local_30[5] = 7;
          local_30[6] = 7;
          local_30[7] = 7;
          bVar2 = *(byte *)(*(int *)(puVar9 + uVar10 * 4) + iVar7);
          if (bVar2 != 0) {
            *(byte *)(*(int *)(puVar9 + uVar10 * 4) + iVar7) =
                 bVar2 & (&DAT_000accab)
                         [iVar7 + (uint)local_30[iVar8] * 0x140 + (uVar10 % 0x1a) * 0xa00];
          }
          iVar7 = iVar7 + 1;
        } while (iVar7 != 0x140);
        uVar10 = uVar10 + 1;
      } while (uVar10 != 199);
      pGVar5 = __get_dashboard_state();
      iVar7 = *(int *)&pGVar5->field_0xeb4;
      pGVar5 = __get_dashboard_state();
      iVar8 = iVar8 + 1;
      _reflash_fb_data_to_lcd(iVar7,*(int *)&pGVar5->field_0xeb8,0,0,0x280,199);
    } while (iVar8 != 4);
    FUN_0004540c();
    iVar8 = FUN_000809e2();
    uVar3 = FUN_00080a3a();
    iVar7 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    gui_utf_draw(0,&DAT_2001c6cd,0,iVar8 + 0xe8,(uint)uVar3,iVar7 + 0x1ae,uVar4 + 0x1b,1,0,0,
                 (undefined *)0x0,0);
    iVar8 = FUN_000809e2();
    uVar3 = FUN_00080a3a();
    iVar7 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    gui_utf_draw(0,(char *)(param_2 + 0x7d),0,iVar8,uVar3 + 0x6c,iVar7 + 200,uVar4 + 0x87,1,0,0,
                 (undefined *)0x0,0);
    iVar8 = FUN_000809e2();
    uVar3 = FUN_00080a3a();
    iVar7 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    gui_utf_draw(0,(char *)(param_2 + 0x3d),0,iVar8,uVar3 + 0x1d,iVar7 + 0x1ae,uVar4 + 0x38,1,0,0,
                 (undefined *)0x0,0);
    pGVar5 = __get_dashboard_state();
    cVar1 = pGVar5->glasses_state_struct_0FF0->field_0x5e;
    uVar10 = FUN_00080732();
    iVar8 = FUN_000809e2();
    uVar3 = FUN_00080a3a();
    iVar7 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    gui_clock_draw(uVar10,iVar8,uVar3 + 2,iVar7 + 0x4c,uVar4 + 0x1d,3,cVar1 != '\x01');
    param_3 = extraout_r2_00;
  }
  if (DAT_20010dbe != '\x01') goto LAB_00040954;
  if (DAT_20010dc1 == '\x01') {
    if (2 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): reflash overview map ....\n");
      }
      else {
        ble_printk("%s(): reflash overview map ....\n","navigation_overview_map_display",param_3,
                   BLE_DEBUG);
      }
    }
    if (*(int *)(param_2 + 0xb1) == 0x1210) {
      if (2 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): Data is in raw format.\n");
        }
        else {
          ble_printk("%s(): Data is in raw format.\n","navigation_overview_map_display",0x1210,
                     BLE_DEBUG);
        }
      }
      memset(&DAT_2001c74f,0,0x1210);
      timeout_00.ticks._4_4_ = 0xffffffff;
      timeout_00.ticks._0_4_ = extraout_r1_01;
      z_impl_k_mutex_lock((k_mutex *)&DAT_20007f54,timeout_00);
      memcpy(&DAT_2001c74f,&DAT_20016b1f,0x1210);
    }
    else {
      if (2 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): Data is in rle compress raw format.\n");
        }
        else {
          ble_printk("%s(): Data is in rle compress raw format.\n","navigation_overview_map_display"
                     ,0x1210,BLE_DEBUG);
        }
      }
      memset(&DAT_2001c74f,0,0x1210);
      timeout_02.ticks._4_4_ = 0xffffffff;
      timeout_02.ticks._0_4_ = extraout_r1_03;
      z_impl_k_mutex_lock((k_mutex *)&DAT_20007f54,timeout_02);
      FUN_000811c6(&DAT_20016b1f,*(uint *)(param_2 + 0xb1),(int)&DAT_2001c74f);
    }
    DAT_2001c74e = '\x01';
    z_impl_k_mutex_unlock((k_mutex *)&DAT_20007f54);
LAB_0004087c:
    iVar8 = FUN_000809e2();
    uVar3 = FUN_00080a3a();
    iVar7 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    gui_bitmps_merge_draw
              (iVar8 + 0x1b6,(uint)uVar3,iVar7 + 0x240,uVar4 + 0x88,0x2001c74f,(int)&DAT_2001d057,2,
               0xf);
    param_3 = extraout_r2_01;
  }
  else if (DAT_2001c74e == '\x01') goto LAB_0004087c;
  DAT_20010dbe = '\0';
LAB_00040954:
  if (DAT_20010dbf == '\x01') {
    if (2 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): reflash text info ....\n");
      }
      else {
        ble_printk("%s(): reflash text info ....\n","navigation_overview_map_display",param_3,
                   BLE_DEBUG);
      }
    }
    memset(&DAT_2001c6cd,0,0x80);
    snprintf(&DAT_2001c6cd,0x80,"%s %s",(char *)(param_2 + 0xd),(char *)(param_2 + 0x25));
    iVar8 = FUN_000809e2();
    uVar3 = FUN_00080a3a();
    iVar7 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    gui_utf_draw(0,&DAT_2001c6cd,0,iVar8 + 0xe8,(uint)uVar3,iVar7 + 0x1ae,uVar4 + 0x1b,1,0,0,
                 (undefined *)0x0,0);
    iVar8 = FUN_000809e2();
    uVar3 = FUN_00080a3a();
    iVar7 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    gui_utf_draw(0,(char *)(param_2 + 0x3d),0,iVar8,uVar3 + 0x1d,iVar7 + 0x1ae,uVar4 + 0x38,1,0,0,
                 (undefined *)0x0,0);
    iVar8 = FUN_000809e2();
    uVar3 = FUN_00080a3a();
    iVar7 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    gui_utf_draw(0,(char *)(param_2 + 0x7d),0,iVar8,uVar3 + 0x6c,iVar7 + 200,uVar4 + 0x87,1,0,0,
                 (undefined *)0x0,0);
    pGVar5 = __get_dashboard_state();
    cVar1 = pGVar5->glasses_state_struct_0FF0->field_0x5e;
    uVar10 = FUN_00080732();
    iVar8 = FUN_000809e2();
    uVar3 = FUN_00080a3a();
    iVar7 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    gui_clock_draw(uVar10,iVar8,uVar3 + 2,iVar7 + 0x4c,uVar4 + 0x1d,3,cVar1 != '\x01');
    navigation_direction_img_display((uint)*(byte *)(param_2 + 1),extraout_r1_04,extraout_r2_02);
    DAT_20010dbf = '\0';
  }
  DAT_20004d74 = 0;
  DAT_20004d75 = 1;
  DAT_20004d85 = 0;
  return;
}


