/*
 * Function: ui_translate_task
 * Entry:    00041ffc
 * Prototype: undefined4 __stdcall ui_translate_task(int param_1, undefined4 param_2, uint param_3)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 ui_translate_task(int param_1,undefined4 param_2,uint param_3)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  GlassesState *pGVar4;
  int iVar5;
  GlassesState *pGVar6;
  int iVar7;
  int iVar8;
  dashboard_ts_context *pdVar9;
  undefined4 extraout_r1;
  uint uVar10;
  uint32_t uVar11;
  uint uVar12;
  int iVar13;
  uint32_t uVar14;
  byte **buffer;
  int iVar15;
  byte *pbVar16;
  k_timeout_t timeout;
  byte local_34 [6];
  short local_2e;
  uint local_2c;
  
  pGVar4 = __get_dashboard_state();
  __set_frame_buffer(param_1 + 0x24);
  __set_showing_notification_on_gui();
  if (DAT_200100da == '\0') {
    if (param_3 == 1) {
      if (DAT_200100db != '\0') {
        return 0;
      }
      if (2 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): SYNC_AREA_REFALSH Upgrade ....\n","ui_translate_task");
        }
        else {
          ble_printk("%s(): SYNC_AREA_REFALSH Upgrade ....\n");
        }
      }
      FUN_000809d0();
      gui_screen_clear();
      FUN_00045834();
      memset(&DAT_200100dc,0,0x10);
      iVar5 = 0;
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
      __clear_showing_notification_on_gui();
      do {
        uVar12 = (uint)(byte)pGVar4->field20_0xc8[0x28];
        if (((uVar12 < 0x1a) &&
            (uVar10 = (byte)pGVar4->field20_0xc8[0x27] - 1, (uVar10 & 0xff) < 0x19)) &&
           (uVar12 != 0)) {
          local_34[0] = 0;
          local_34[1] = 0;
          local_34[2] = 0;
          local_34[3] = 0;
          stack0xffffffd0 = 0;
          local_2c = local_2c & 0xffff0000;
          snprintf((char *)local_34,10,"%s>%s",*(char **)(&DAT_200024f8 + (uVar12 - 1) * 4),
                   *(char **)(&DAT_200024f8 + uVar10 * 4));
          iVar7 = FUN_000809e2();
          uVar2 = FUN_00080a3a();
          iVar8 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          gui_utf_draw(0,(char *)local_34,3,iVar7,uVar2 + 0x6e,iVar8 + 0x50,uVar3 + 0x89,1,0,0,
                       (undefined *)0x0,0);
          DAT_200100eb = pGVar4->field20_0xc8[0x28];
          DAT_200100ea = pGVar4->field20_0xc8[0x27];
        }
        else if (0 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): translate language type error! trans_info->original_type %d trans_info->translation_type %d\n"
                   ,"ui_translate_task",uVar12,(uint)(byte)pGVar4->field20_0xc8[0x27]);
          }
          else {
            ble_printk("%s(): translate language type error! trans_info->original_type %d trans_info->translation_type %d\n"
                       ,"ui_translate_task");
          }
        }
        pGVar6 = __get_dashboard_state();
        iVar7 = pGVar6->dashboard_ts->time_disp_mode;
        pdVar9 = (dashboard_ts_context *)FUN_00080732();
        iVar8 = FUN_000809e2();
        uVar2 = FUN_00080a3a();
        iVar13 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        gui_clock_draw(pdVar9,iVar8,uVar2 + 2,iVar13 + 0x50,uVar3 + 0x1d,3,(char)iVar7 != '\x01');
        uVar12 = 0;
        do {
          iVar7 = 0;
          do {
            local_34[0] = 1;
            local_34[1] = 3;
            local_34[2] = 5;
            local_34[3] = 7;
            stack0xffffffd0 = 0x7070707;
            iVar8 = *(int *)(param_1 + 0x24 + uVar12 * 4);
            bVar1 = *(byte *)(iVar8 + iVar7);
            if (bVar1 != 0) {
              *(byte *)(iVar8 + iVar7) =
                   bVar1 & (&DAT_000accab)
                           [iVar7 + (uint)local_34[iVar5] * 0x140 + (uVar12 % 0x1a) * 0xa00];
            }
            iVar7 = iVar7 + 1;
          } while (iVar7 != 0x140);
          uVar12 = uVar12 + 1;
        } while (uVar12 != 199);
        pGVar6 = __get_dashboard_state();
        uVar11 = (pGVar6->jdb_panel_context).current_row;
        pGVar6 = __get_dashboard_state();
        iVar5 = iVar5 + 1;
        _reflash_fb_data_to_lcd(uVar11,(pGVar6->jdb_panel_context).current_column,0,0,0x280,199);
      } while (iVar5 != 4);
      __set_showing_notification_on_gui();
      return 0;
    }
    if (param_3 != 2) {
      return 0;
    }
    if (2 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): translate process received exit packet ...\n","ui_translate_task");
      }
      else {
        ble_printk("%s(): translate process received exit packet ...\n");
      }
    }
    gui_screen_clear();
    goto LAB_00042252;
  }
  if (DAT_200100da != '\x01') {
    return 0;
  }
  bVar1 = pGVar4->field20_0xc8[0x2a];
  if (bVar1 == 5) {
    if (param_3 == 1) {
      if (DAT_2001d95f == 5) {
        return 0;
      }
      iVar5 = 0;
LAB_00042292:
      DAT_2001d95f = bVar1;
      FUN_00041ef4(iVar5);
      return 0;
    }
  }
  else if (bVar1 == 6) {
    if (param_3 == 1) {
      if (DAT_2001d95f == 6) {
        return 0;
      }
      iVar5 = 1;
      goto LAB_00042292;
    }
  }
  else if (param_3 < 2) {
    if (DAT_2001d95f - 5 < 2) {
      DAT_2001d95f = bVar1;
      gui_screen_clear();
    }
    if (param_3 != 1) goto LAB_000426ee;
    memset(&DAT_2001d960,0,0x1e0);
    timeout.ticks._4_4_ = 0xffffffff;
    timeout.ticks._0_4_ = extraout_r1;
    z_impl_k_mutex_lock(&k_mutex_2000851c,timeout);
    DAT_200100dc = pGVar4->field20_0xc8[0x29];
    DAT_2001d95f = pGVar4->field20_0xc8[0x2a];
    memcpy(&DAT_2001d960,pGVar4->field20_0xc8 + 0x2d,0x1e0);
    z_impl_k_mutex_unlock(&k_mutex_2000851c);
    if (DAT_200100dc == '\x01') {
      if (2 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): suspend_en is 1, reflash suspend icon\n","ui_translate_task");
        }
        else {
          ble_printk("%s(): suspend_en is 1, reflash suspend icon\n");
        }
      }
      iVar5 = FUN_000809e2();
      uVar2 = FUN_00080a3a();
      gui_bmp_bitmap_draw(0x1b,iVar5,uVar2 + 0x36,0,0,0);
    }
    uVar12 = (uint)(byte)pGVar4->field20_0xc8[0x28];
    if (uVar12 < 0x1a) {
      uVar10 = (byte)pGVar4->field20_0xc8[0x27] - 1;
      if ((0x18 < (uVar10 & 0xff)) || (uVar12 == 0)) goto LAB_000423a4;
      if ((DAT_200100eb != uVar12) || ((uint)DAT_200100ea != (uint)(byte)pGVar4->field20_0xc8[0x27])
         ) {
        local_34[0] = 0;
        local_34[1] = 0;
        local_34[2] = 0;
        local_34[3] = 0;
        stack0xffffffd0 = 0;
        local_2c = local_2c & 0xffff0000;
        snprintf((char *)local_34,10,"%s>%s",*(char **)(&DAT_200024f8 + (uVar12 - 1) * 4),
                 *(char **)(&DAT_200024f8 + uVar10 * 4));
        if (3 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): draw translate type content\n","ui_translate_task");
          }
          else {
            ble_printk("%s(): draw translate type content\n");
          }
        }
        iVar5 = FUN_000809e2();
        uVar2 = FUN_00080a3a();
        iVar7 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        gui_utf_draw(0,(char *)local_34,3,iVar5,uVar2 + 0x6e,iVar7 + 0x50,uVar3 + 0x89,1,0,0,
                     (undefined *)0x0,0);
        DAT_200100eb = pGVar4->field20_0xc8[0x28];
        DAT_200100ea = pGVar4->field20_0xc8[0x27];
      }
    }
    else {
LAB_000423a4:
      if (0 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): translate language type error! trans_info->original_type %d trans_info->translation_type %d\n"
                 ,"ui_translate_task",uVar12,(uint)(byte)pGVar4->field20_0xc8[0x27]);
        }
        else {
          ble_printk("%s(): translate language type error! trans_info->original_type %d trans_info->translation_type %d\n"
                     ,"ui_translate_task");
        }
      }
    }
    if (DAT_2001d95f - 3 < 2) {
      pGVar4 = __get_dashboard_state();
      iVar5 = 0x640;
      buffer = &(pGVar4->jdb_panel_context).__panel_buffer;
      while( true ) {
        uVar2 = FUN_00080a3a();
        for (uVar12 = (uint)uVar2; uVar2 = FUN_00080a3a(), (int)uVar12 <= (int)(uVar2 + 0x87);
            uVar12 = uVar12 + 1) {
          iVar7 = FUN_000809e2();
          for (iVar7 = iVar7 + 0x58; iVar8 = FUN_000809e2(), iVar7 < (iVar8 + 0x240) / 2;
              iVar7 = iVar7 + 1) {
            pbVar16 = buffer[uVar12];
            bVar1 = pbVar16[iVar7];
            if (bVar1 != 0) {
              pbVar16[iVar7] = bVar1 & (&DAT_000accab)[iVar7 + ((int)uVar12 % 0x1a) * 0xa00 + iVar5]
              ;
            }
          }
        }
        pGVar6 = __get_dashboard_state();
        uVar14 = (pGVar6->jdb_panel_context).current_row;
        pGVar6 = __get_dashboard_state();
        uVar11 = (pGVar6->jdb_panel_context).current_column;
        iVar7 = FUN_000809e2();
        uVar2 = FUN_00080a3a();
        iVar8 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        _reflash_fb_data_to_lcd(uVar14,uVar11,iVar7 + 0x58,(uint)uVar2,iVar8 + 0x240,uVar3 + 0x88);
        if (iVar5 == 0x500) break;
        iVar5 = 0x500;
      }
      iVar5 = FUN_000809e2();
      uVar2 = FUN_00080a3a();
      iVar7 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      _clean_fb_data((byte *)buffer,0,iVar5 + 0x58,(uint)uVar2,iVar7 + 0x240,uVar3 + 0x88);
      if (DAT_200100dc == '\0') {
        iVar5 = FUN_000809e2();
        uVar2 = FUN_00080a3a();
        gui_bmp_dynamic_bitmap_draw(1,iVar5,uVar2 + 0x36);
      }
      __clear_showing_notification_on_gui();
      iVar5 = 2;
      while( true ) {
        iVar7 = FUN_000809e2();
        uVar2 = FUN_00080a3a();
        iVar8 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        gui_utf_draw(0,&DAT_2001d960,0,iVar7 + 0x58,(uint)uVar2,iVar8 + 0x240,uVar3 + 0x88,5,0,0,
                     (undefined *)0x0,0);
        iVar7 = FUN_000809e2();
        iVar7 = iVar7 + 0x58;
        iVar8 = FUN_000809e2();
        uVar2 = FUN_00080a3a();
        uVar12 = (uint)uVar2;
        uVar2 = FUN_00080a3a();
        for (uVar10 = 0; (int)uVar10 < (int)((uVar2 + 0x88) - uVar12); uVar10 = uVar10 + 1) {
          for (iVar13 = 0; iVar13 < ((iVar8 + 0x240) - iVar7) / 2; iVar13 = iVar13 + 1) {
            local_34[0] = 1;
            local_34[1] = 3;
            local_34[2] = 5;
            local_34[3] = 7;
            stack0xffffffd0 = 0x7070707;
            iVar15 = iVar13 + iVar7 / 2;
            pbVar16 = (&(pGVar4->jdb_panel_context).__panel_buffer)[uVar12 + uVar10];
            bVar1 = pbVar16[iVar15];
            if (bVar1 != 0) {
              pbVar16[iVar15] =
                   bVar1 & (&DAT_000accab)
                           [iVar13 + (uint)local_34[iVar5] * 0x140 + (uVar10 % 0x1a) * 0xa00];
            }
          }
        }
        pGVar6 = __get_dashboard_state();
        uVar11 = (pGVar6->jdb_panel_context).current_row;
        pGVar6 = __get_dashboard_state();
        _reflash_fb_data_to_lcd
                  (uVar11,(pGVar6->jdb_panel_context).current_column,iVar7,uVar12,iVar8 + 0x240,
                   uVar2 + 0x88);
        if (iVar5 != 2) break;
        iVar5 = 3;
      }
      __set_showing_notification_on_gui();
    }
    else {
      iVar5 = FUN_000809e2();
      uVar2 = FUN_00080a3a();
      iVar7 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      gui_utf_draw(0,&DAT_2001d960,0,iVar5 + 0x58,(uint)uVar2,iVar7 + 0x240,uVar3 + 0x88,5,0,0,
                   (undefined *)0x0,0);
    }
LAB_000426ee:
    if (DAT_200100dc == '\0') {
      iVar5 = FUN_000809e2();
      uVar2 = FUN_00080a3a();
      gui_bmp_dynamic_bitmap_draw(1,iVar5,uVar2 + 0x36);
    }
    local_34[0] = 0;
    local_34[1] = 0;
    local_34[2] = 0;
    local_34[3] = 0;
    stack0xffffffd0 = 0;
    local_2c = 0;
    pdVar9 = (dashboard_ts_context *)FUN_00080732();
    __init_burial_point_date(pdVar9,(undefined2 *)local_34);
    if (((uint)DAT_200100e6 == (local_2c & 0xffff)) && (DAT_200100e4 == local_2e)) {
      return 0;
    }
    DAT_200100e6 = (undefined2)local_2c;
    DAT_200100e4 = local_2e;
    pGVar4 = __get_dashboard_state();
    iVar5 = pGVar4->dashboard_ts->time_disp_mode;
    pdVar9 = (dashboard_ts_context *)FUN_00080732();
    iVar7 = FUN_000809e2();
    uVar2 = FUN_00080a3a();
    iVar8 = FUN_000809e2();
    uVar3 = FUN_00080a3a();
    gui_clock_draw(pdVar9,iVar7,uVar2 + 2,iVar8 + 0x50,uVar3 + 0x1d,3,(char)iVar5 != '\x01');
    return 0;
  }
  if (param_3 != 2) {
    return 0;
  }
  if (2 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): translate process received exit packet ...\n","ui_translate_task");
    }
    else {
      ble_printk("%s(): translate process received exit packet ...\n");
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


