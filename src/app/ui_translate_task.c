/*
 * Function: ui_translate_task
 * Entry:    00041ffc
 * Prototype: undefined4 __stdcall ui_translate_task(int param_1, undefined4 param_2, uint param_3)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 ui_translate_task(int param_1,undefined4 param_2,uint param_3)

{
  byte bVar1;
  char cVar2;
  ushort uVar3;
  ushort uVar4;
  GlassesState *pGVar5;
  undefined4 uVar6;
  undefined4 extraout_r0;
  undefined4 extraout_r0_00;
  int iVar7;
  GlassesState *pGVar8;
  int iVar9;
  int iVar10;
  dashboard_ts_context *dashboard_ts_ctx;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  undefined4 uVar11;
  undefined4 extraout_r1_02;
  undefined4 extraout_r1_03;
  uint uVar12;
  int iVar13;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 uVar14;
  undefined4 extraout_r2_02;
  uint uVar15;
  undefined4 extraout_r2_03;
  undefined4 extraout_r2_04;
  int iVar16;
  int *buffer;
  int iVar17;
  k_timeout_t timeout;
  byte local_34 [6];
  short local_2e;
  uint local_2c;
  
  pGVar5 = __get_dashboard_state();
  FUN_000452f0(param_1 + 0x24);
  uVar6 = FUN_0004540c();
  if (DAT_200100da == '\0') {
    if (param_3 == 1) {
      if (DAT_200100db != '\0') {
        return 0;
      }
      if (2 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): SYNC_AREA_REFALSH Upgrade ....\n");
        }
        else {
          ble_printk("%s(): SYNC_AREA_REFALSH Upgrade ....\n","ui_translate_task",extraout_r2,
                     BLE_DEBUG);
        }
      }
      uVar6 = FUN_000809d0();
      gui_screen_clear(uVar6,extraout_r1_00,extraout_r2_00);
      FUN_00045834();
      memset(&DAT_200100dc,0,0x10);
      iVar7 = 0;
      DAT_2000aa34 = 0x80;
      DAT_2000aa20 = 0;
      DAT_2000aa24 = 0;
      DAT_2000aa18 = &DAT_2001db49;
      DAT_2000aa2c = 0;
      DAT_2000aa30 = 0;
      DAT_2000aa1c = 0;
      DAT_2000aa28 = 0;
      _DAT_200100da = 0x101;
      FUN_00045444();
      FUN_00045428();
      do {
        uVar15 = (uint)(byte)pGVar5->field20_0xc8[0x28];
        if (((uVar15 < 0x1a) &&
            (uVar12 = (byte)pGVar5->field20_0xc8[0x27] - 1, (uVar12 & 0xff) < 0x19)) &&
           (uVar15 != 0)) {
          local_34[0] = 0;
          local_34[1] = 0;
          local_34[2] = 0;
          local_34[3] = 0;
          stack0xffffffd0 = 0;
          local_2c = local_2c & 0xffff0000;
          snprintf((char *)local_34,10,"%s>%s",*(char **)(&DAT_200024f8 + (uVar15 - 1) * 4),
                   *(char **)(&DAT_200024f8 + uVar12 * 4));
          iVar9 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          iVar10 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          gui_utf_draw(0,(char *)local_34,3,iVar9,uVar3 + 0x6e,iVar10 + 0x50,uVar4 + 0x89,1,0,0,
                       (undefined *)0x0,0);
          DAT_200100eb = pGVar5->field20_0xc8[0x28];
          DAT_200100ea = pGVar5->field20_0xc8[0x27];
        }
        else if (0 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): translate language type error! trans_info->original_type %d trans_info->translation_type %d\n"
                   ,"ui_translate_task");
          }
          else {
            ble_printk("%s(): translate language type error! trans_info->original_type %d trans_info->translation_type %d\n"
                       ,"ui_translate_task",uVar15,(uint)(byte)pGVar5->field20_0xc8[0x27]);
          }
        }
        pGVar8 = __get_dashboard_state();
        cVar2 = pGVar8->dashboard_ts->field_0x5e;
        uVar15 = FUN_00080732();
        iVar9 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        iVar10 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        gui_clock_draw(uVar15,iVar9,uVar3 + 2,iVar10 + 0x50,uVar4 + 0x1d,3,cVar2 != '\x01');
        uVar15 = 0;
        do {
          iVar9 = 0;
          do {
            local_34[0] = 1;
            local_34[1] = 3;
            local_34[2] = 5;
            local_34[3] = 7;
            stack0xffffffd0 = 0x7070707;
            iVar10 = *(int *)(param_1 + 0x24 + uVar15 * 4);
            bVar1 = *(byte *)(iVar10 + iVar9);
            if (bVar1 != 0) {
              *(byte *)(iVar10 + iVar9) =
                   bVar1 & (&DAT_000accab)
                           [iVar9 + (uint)local_34[iVar7] * 0x140 + (uVar15 % 0x1a) * 0xa00];
            }
            iVar9 = iVar9 + 1;
          } while (iVar9 != 0x140);
          uVar15 = uVar15 + 1;
        } while (uVar15 != 199);
        pGVar8 = __get_dashboard_state();
        iVar9 = *(int *)&(pGVar8->jdb_panel_context).field_0x348;
        pGVar8 = __get_dashboard_state();
        iVar7 = iVar7 + 1;
        _reflash_fb_data_to_lcd
                  (iVar9,*(int *)&(pGVar8->jdb_panel_context).field_0x34c,0,0,0x280,199);
      } while (iVar7 != 4);
      FUN_0004540c();
      return 0;
    }
    if (param_3 != 2) {
      return 0;
    }
    uVar11 = extraout_r1;
    uVar14 = extraout_r2;
    if (2 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): translate process received exit packet ...\n");
        uVar6 = extraout_r0_00;
        uVar11 = extraout_r1_02;
        uVar14 = extraout_r2_02;
      }
      else {
        ble_printk("%s(): translate process received exit packet ...\n","ui_translate_task",
                   extraout_r2,BLE_DEBUG);
        uVar6 = extraout_r0;
        uVar11 = extraout_r1_01;
        uVar14 = extraout_r2_01;
      }
    }
    gui_screen_clear(uVar6,uVar11,uVar14);
    goto LAB_00042252;
  }
  if (DAT_200100da != '\x01') {
    return 0;
  }
  bVar1 = pGVar5->field20_0xc8[0x2a];
  if (bVar1 == 5) {
    if (param_3 == 1) {
      if (DAT_2001d95f == 5) {
        return 0;
      }
      iVar7 = 0;
LAB_00042292:
      DAT_2001d95f = bVar1;
      FUN_00041ef4(iVar7);
      return 0;
    }
  }
  else if (bVar1 == 6) {
    if (param_3 == 1) {
      if (DAT_2001d95f == 6) {
        return 0;
      }
      iVar7 = 1;
      goto LAB_00042292;
    }
  }
  else if (param_3 < 2) {
    uVar15 = (uint)DAT_2001d95f;
    if (uVar15 - 5 < 2) {
      DAT_2001d95f = bVar1;
      gui_screen_clear(uVar6,extraout_r1,uVar15 - 5);
    }
    if (param_3 != 1) goto LAB_000426ee;
    memset(&DAT_2001d960,0,0x1e0);
    timeout.ticks._4_4_ = 0xffffffff;
    timeout.ticks._0_4_ = extraout_r1_03;
    z_impl_k_mutex_lock(&k_mutex_2000851c,timeout);
    DAT_200100dc = pGVar5->field20_0xc8[0x29];
    DAT_2001d95f = pGVar5->field20_0xc8[0x2a];
    memcpy(&DAT_2001d960,pGVar5->field20_0xc8 + 0x2d,0x1e0);
    z_impl_k_mutex_unlock(&k_mutex_2000851c);
    if (DAT_200100dc == '\x01') {
      if (2 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): suspend_en is 1, reflash suspend icon\n");
        }
        else {
          ble_printk("%s(): suspend_en is 1, reflash suspend icon\n","ui_translate_task",
                     extraout_r2_03,BLE_DEBUG);
        }
      }
      iVar7 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      gui_bmp_bitmap_draw(0x1b,iVar7,uVar3 + 0x36,0,0,0);
    }
    uVar15 = (uint)(byte)pGVar5->field20_0xc8[0x28];
    if (uVar15 < 0x1a) {
      uVar12 = (byte)pGVar5->field20_0xc8[0x27] - 1;
      if ((0x18 < (uVar12 & 0xff)) || (uVar15 == 0)) goto LAB_000423a4;
      if ((DAT_200100eb != uVar15) || ((uint)DAT_200100ea != (uint)(byte)pGVar5->field20_0xc8[0x27])
         ) {
        local_34[0] = 0;
        local_34[1] = 0;
        local_34[2] = 0;
        local_34[3] = 0;
        stack0xffffffd0 = 0;
        local_2c = local_2c & 0xffff0000;
        snprintf((char *)local_34,10,"%s>%s",*(char **)(&DAT_200024f8 + (uVar15 - 1) * 4),
                 *(char **)(&DAT_200024f8 + uVar12 * 4));
        if (3 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): draw translate type content\n");
          }
          else {
            ble_printk("%s(): draw translate type content\n","ui_translate_task",extraout_r2_04,
                       BLE_DEBUG);
          }
        }
        iVar7 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        gui_utf_draw(0,(char *)local_34,3,iVar7,uVar3 + 0x6e,iVar9 + 0x50,uVar4 + 0x89,1,0,0,
                     (undefined *)0x0,0);
        DAT_200100eb = pGVar5->field20_0xc8[0x28];
        DAT_200100ea = pGVar5->field20_0xc8[0x27];
      }
    }
    else {
LAB_000423a4:
      if (0 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): translate language type error! trans_info->original_type %d trans_info->translation_type %d\n"
                 ,"ui_translate_task");
        }
        else {
          ble_printk("%s(): translate language type error! trans_info->original_type %d trans_info->translation_type %d\n"
                     ,"ui_translate_task",uVar15,(uint)(byte)pGVar5->field20_0xc8[0x27]);
        }
      }
    }
    if (DAT_2001d95f - 3 < 2) {
      pGVar5 = __get_dashboard_state();
      iVar7 = 0x640;
      buffer = &(pGVar5->jdb_panel_context).field9_0x24;
      while( true ) {
        uVar3 = FUN_00080a3a();
        for (uVar15 = (uint)uVar3; uVar3 = FUN_00080a3a(), (int)uVar15 <= (int)(uVar3 + 0x87);
            uVar15 = uVar15 + 1) {
          iVar9 = FUN_000809e2();
          for (iVar9 = iVar9 + 0x58; iVar10 = FUN_000809e2(), iVar9 < (iVar10 + 0x240) / 2;
              iVar9 = iVar9 + 1) {
            iVar10 = buffer[uVar15];
            bVar1 = *(byte *)(iVar10 + iVar9);
            if (bVar1 != 0) {
              *(byte *)(iVar10 + iVar9) =
                   bVar1 & (&DAT_000accab)[iVar9 + ((int)uVar15 % 0x1a) * 0xa00 + iVar7];
            }
          }
        }
        pGVar8 = __get_dashboard_state();
        iVar16 = *(int *)&(pGVar8->jdb_panel_context).field_0x348;
        pGVar8 = __get_dashboard_state();
        iVar13 = *(int *)&(pGVar8->jdb_panel_context).field_0x34c;
        iVar9 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        iVar10 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        _reflash_fb_data_to_lcd(iVar16,iVar13,iVar9 + 0x58,(uint)uVar3,iVar10 + 0x240,uVar4 + 0x88);
        if (iVar7 == 0x500) break;
        iVar7 = 0x500;
      }
      iVar7 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      iVar9 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      _clean_fb_data(buffer,0,iVar7 + 0x58,(uint)uVar3,iVar9 + 0x240,uVar4 + 0x88);
      if (DAT_200100dc == '\0') {
        iVar7 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        gui_bmp_dynamic_bitmap_draw(1,iVar7,uVar3 + 0x36);
      }
      FUN_00045428();
      iVar7 = 2;
      while( true ) {
        iVar9 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        iVar10 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        gui_utf_draw(0,&DAT_2001d960,0,iVar9 + 0x58,(uint)uVar3,iVar10 + 0x240,uVar4 + 0x88,5,0,0,
                     (undefined *)0x0,0);
        iVar9 = FUN_000809e2();
        iVar9 = iVar9 + 0x58;
        iVar10 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        uVar15 = (uint)uVar3;
        uVar3 = FUN_00080a3a();
        for (uVar12 = 0; (int)uVar12 < (int)((uVar3 + 0x88) - uVar15); uVar12 = uVar12 + 1) {
          for (iVar13 = 0; iVar13 < ((iVar10 + 0x240) - iVar9) / 2; iVar13 = iVar13 + 1) {
            local_34[0] = 1;
            local_34[1] = 3;
            local_34[2] = 5;
            local_34[3] = 7;
            stack0xffffffd0 = 0x7070707;
            iVar16 = iVar13 + iVar9 / 2;
            iVar17 = (&(pGVar5->jdb_panel_context).field9_0x24)[uVar15 + uVar12];
            bVar1 = *(byte *)(iVar17 + iVar16);
            if (bVar1 != 0) {
              *(byte *)(iVar17 + iVar16) =
                   bVar1 & (&DAT_000accab)
                           [iVar13 + (uint)local_34[iVar7] * 0x140 + (uVar12 % 0x1a) * 0xa00];
            }
          }
        }
        pGVar8 = __get_dashboard_state();
        iVar13 = *(int *)&(pGVar8->jdb_panel_context).field_0x348;
        pGVar8 = __get_dashboard_state();
        _reflash_fb_data_to_lcd
                  (iVar13,*(int *)&(pGVar8->jdb_panel_context).field_0x34c,iVar9,uVar15,
                   iVar10 + 0x240,uVar3 + 0x88);
        if (iVar7 != 2) break;
        iVar7 = 3;
      }
      FUN_0004540c();
    }
    else {
      iVar7 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      iVar9 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      gui_utf_draw(0,&DAT_2001d960,0,iVar7 + 0x58,(uint)uVar3,iVar9 + 0x240,uVar4 + 0x88,5,0,0,
                   (undefined *)0x0,0);
    }
LAB_000426ee:
    if (DAT_200100dc == '\0') {
      iVar7 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      gui_bmp_dynamic_bitmap_draw(1,iVar7,uVar3 + 0x36);
    }
    local_34[0] = 0;
    local_34[1] = 0;
    local_34[2] = 0;
    local_34[3] = 0;
    stack0xffffffd0 = 0;
    local_2c = 0;
    dashboard_ts_ctx = (dashboard_ts_context *)FUN_00080732();
    __init_burial_point_date(dashboard_ts_ctx,(undefined2 *)local_34);
    if (((uint)DAT_200100e6 == (local_2c & 0xffff)) && (DAT_200100e4 == local_2e)) {
      return 0;
    }
    DAT_200100e6 = (undefined2)local_2c;
    DAT_200100e4 = local_2e;
    pGVar5 = __get_dashboard_state();
    cVar2 = pGVar5->dashboard_ts->field_0x5e;
    uVar15 = FUN_00080732();
    iVar7 = FUN_000809e2();
    uVar3 = FUN_00080a3a();
    iVar9 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    gui_clock_draw(uVar15,iVar7,uVar3 + 2,iVar9 + 0x50,uVar4 + 0x1d,3,cVar2 != '\x01');
    return 0;
  }
  if (param_3 != 2) {
    return 0;
  }
  if (2 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): translate process received exit packet ...\n");
    }
    else {
      ble_printk("%s(): translate process received exit packet ...\n","ui_translate_task",
                 extraout_r2,BLE_DEBUG);
    }
  }
  FUN_00045968();
LAB_00042252:
  FUN_000809d0();
  DAT_2000aa20 = 0;
  DAT_2000aa24 = 0;
  DAT_2000aa2c = 0;
  DAT_2000aa30 = 0;
  DAT_2000aa1c = 0;
  DAT_2000aa28 = 0;
  memset(&DAT_200100da,0,0x12);
  return 0;
}


