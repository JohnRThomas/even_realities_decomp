/*
 * Function: ui_even_ai_task
 * Entry:    0003e2d4
 * Prototype: int __stdcall ui_even_ai_task(int param_1, undefined4 param_2, int param_3)
 */


/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int ui_even_ai_task(int param_1,undefined4 param_2,int param_3)

{
  char cVar1;
  byte bVar2;
  ushort uVar3;
  ushort uVar4;
  GlassesState *pGVar5;
  uint uVar6;
  int iVar7;
  GlassesState *pGVar8;
  GlassesState *pGVar9;
  int iVar10;
  int iVar11;
  char *pcVar12;
  undefined4 extraout_r1;
  uint32_t uVar13;
  undefined4 extraout_r2;
  undefined4 uVar14;
  uint uVar15;
  undefined4 *puVar16;
  byte *pbVar17;
  uint32_t uVar18;
  char *pcVar19;
  byte **buffer;
  byte *pbVar20;
  int iVar21;
  int iVar22;
  bool bVar23;
  k_timeout_t timeout;
  char *local_4c;
  byte local_30 [12];
  
  pGVar5 = __get_dashboard_state();
  bVar2 = get_current_language();
  puVar16 = (undefined4 *)(uint)(byte)pGVar5->field20_0xc8[0x27];
  bVar23 = puVar16 != (undefined4 *)&DAT_00000007;
  uVar14 = extraout_r2;
  if (bVar23) {
    uVar14 = 0xffffffff;
    puVar16 = (undefined4 *)&DAT_200024f0;
  }
  uVar6 = bVar2 - 4 & 0xff;
  if (bVar23) {
    *puVar16 = uVar14;
  }
  if (uVar6 < 0xb) {
    pcVar19 = (&PTR_DAT_0008db64)[uVar6];
    local_4c = (&PTR_DAT_0008db38)[uVar6];
  }
  else {
    pcVar19 = &DAT_20003660;
    local_4c = &DAT_20003634;
  }
  pbVar20 = (byte *)(param_1 + 0x24);
  __set_frame_buffer(pbVar20);
  __set_showing_notification_on_gui();
  if ((char)DAT_2001c6c9 == '\0') {
    if (param_3 == 1) {
      memset(&DAT_2001c4e9,0,0x1e0);
      if (0 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): ENTER evenai INIT process...\n","ui_even_ai_task");
        }
        else {
          ble_printk("%s(): ENTER evenai INIT process...\n");
        }
      }
      if (DAT_2001c6c9._1_1_ != '\0') {
        return 0;
      }
      if (0 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): SYNC_AREA_REFALSH Upgrade ....\n","ui_even_ai_task");
        }
        else {
          ble_printk("%s(): SYNC_AREA_REFALSH Upgrade ....\n");
        }
      }
      FUN_000809d0();
      if ((byte)pGVar5->field20_0xc8[0x27] < 0xc) {
        gui_screen_clear();
      }
      iVar10 = 0;
      DAT_2000a9b8 = 0;
      FUN_00045834();
      DAT_2000aa34 = 0x80;
      DAT_2000aa20 = 0;
      DAT_2000aa24 = 0;
      DAT_2000aa18 = &DAT_2001db49;
      DAT_2000aa2c = 0;
      DAT_2000aa30 = 0;
      DAT_2000aa1c = 0;
      DAT_2000aa28 = 0;
      DAT_2001c6c9 = 0x101;
      FUN_00045444();
      iVar7 = __clear_showing_notification_on_gui();
      do {
        uVar6 = (uint)(byte)pGVar5->field20_0xc8[0x27];
        if (uVar6 == 0xb) {
          iVar7 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          gui_bmp_bitmap_draw(0x4a,iVar7,uVar3 + 0x36,0,0,0);
          iVar11 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          iVar7 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          iVar7 = iVar7 + 0x230;
          iVar11 = iVar11 + 0x58;
          pcVar12 = local_4c;
LAB_0003e42a:
          gui_utf_draw_middle(0,pcVar12,0,iVar11,uVar3 + 0x36,iVar7,uVar4 + 0x87,3,0,0,
                              (undefined *)0x0,0);
        }
        else {
          if (uVar6 - 0xc < 3) {
            if (uVar6 != 0xe) {
              return iVar7;
            }
            pGVar5 = __get_dashboard_state();
            uVar13 = (pGVar5->jdb_panel_context).current_row;
            pGVar5 = __get_dashboard_state();
            _reflash_fb_data_to_lcd(uVar13,(pGVar5->jdb_panel_context).current_column,0,0,0x27f,199)
            ;
            break;
          }
          if (1 < uVar6 - 0xf) {
            iVar11 = FUN_000809e2();
            uVar3 = FUN_00080a3a();
            iVar7 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            iVar7 = iVar7 + 0x236;
            pcVar12 = pcVar19;
            goto LAB_0003e42a;
          }
          if (uVar6 != 0x10) {
            return iVar7;
          }
          memcpy(&DAT_2001c4e9,pGVar5->field20_0xc8 + 0x2e,
                 (uint)*(ushort *)(pGVar5->field20_0xc8 + 0x20e));
          iVar7 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          iVar11 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          gui_utf_draw(0,&DAT_2001c4e9,0,iVar7,(uint)uVar3,iVar11 + 0x240,uVar4 + 0x88,5,0,0,
                       (undefined *)0x0,0);
        }
        uVar6 = 0;
        do {
          iVar7 = 0;
          do {
            local_30[0] = 1;
            local_30[1] = 2;
            local_30[2] = 3;
            local_30[3] = 4;
            local_30[4] = 5;
            local_30[5] = 6;
            local_30[6] = 7;
            local_30[7] = 7;
            bVar2 = *(byte *)(*(int *)(pbVar20 + uVar6 * 4) + iVar7);
            if (bVar2 != 0) {
              *(byte *)(*(int *)(pbVar20 + uVar6 * 4) + iVar7) =
                   bVar2 & (&DAT_000accab)
                           [iVar7 + (uint)local_30[iVar10] * 0x140 + (uVar6 % 0x1a) * 0xa00];
            }
            iVar7 = iVar7 + 1;
          } while (iVar7 != 0x140);
          uVar6 = uVar6 + 1;
        } while (uVar6 != 199);
        pGVar8 = __get_dashboard_state();
        uVar13 = (pGVar8->jdb_panel_context).current_row;
        pGVar8 = __get_dashboard_state();
        iVar10 = iVar10 + 1;
        iVar7 = _reflash_fb_data_to_lcd
                          (uVar13,(pGVar8->jdb_panel_context).current_column,0,0,0x280,199);
      } while (iVar10 != 8);
LAB_0003e470:
      __set_showing_notification_on_gui();
      return 0;
    }
    if (param_3 != 2) {
      return 0;
    }
    if (2 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): evenai process received exit packet ...\n","ui_even_ai_task");
      }
      else {
        ble_printk("%s(): evenai process received exit packet ...\n");
      }
    }
    gui_screen_clear();
LAB_0003e5c8:
    FUN_000809d0();
    DAT_2000aa1c = 0;
    DAT_2000aa20 = 0;
    DAT_2000aa24 = 0;
    DAT_2000aa28 = 0;
    DAT_2000aa2c = 0;
    DAT_2000aa30 = 0;
    DAT_2001c6c9 = 0;
    return 0;
  }
  if ((char)DAT_2001c6c9 != '\x01') {
    return 0;
  }
  pbVar17 = pGVar5->field20_0xc8 + 0x27;
  if (param_3 != 1) {
    if (param_3 == 0) {
      FUN_0003e10c(pbVar17);
      return 0;
    }
    if (param_3 != 2) {
      return 0;
    }
    if (2 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): evenai process received exit packet ...\n","ui_even_ai_task");
      }
      else {
        ble_printk("%s(): evenai process received exit packet ...\n");
      }
    }
    FUN_00045968();
    goto LAB_0003e5c8;
  }
  memset(&DAT_2001c4e9,0,0x1e0);
  timeout.ticks._4_4_ = 0xffffffff;
  timeout.ticks._0_4_ = extraout_r1;
  z_impl_k_mutex_lock(&k_mutex_2000851c,timeout);
  cVar1 = pGVar5->field20_0xc8[0x28];
  iVar7 = z_impl_k_mutex_unlock(&k_mutex_2000851c);
  uVar6 = (uint)(byte)pGVar5->field20_0xc8[0x27];
  if (uVar6 == 7) {
    if ((_DAT_200024f0 == 0xffffffff) && (cVar1 == '\x03')) {
      _DAT_200024f0 = (uint)(byte)pGVar5->field20_0xc8[0x2d];
      iVar7 = 0;
      __clear_showing_notification_on_gui();
      do {
        memcpy(&DAT_2001c4e9,pGVar5->field20_0xc8 + 0x2e,
               (uint)*(ushort *)(pGVar5->field20_0xc8 + 0x20e));
        iVar10 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        iVar11 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        gui_utf_draw(0,&DAT_2001c4e9,0,iVar10 + 0x58,(uint)uVar3,iVar11 + 0x230,uVar4 + 0x88,5,0,0,
                     (undefined *)0x0,0);
        if (pGVar5->field20_0xc8[0x2c] != '\x01') {
          iVar10 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          iVar11 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          gui_verticalLine_process_bar
                    (iVar10 + 0x23c,(uint)uVar3,iVar11 + 0x23c,uVar4 + 0x88,1,
                     pGVar5->field20_0xc8[0x2b]);
        }
        uVar6 = 0;
        do {
          iVar10 = 0;
          do {
            local_30[0] = 1;
            local_30[1] = 2;
            local_30[2] = 3;
            local_30[3] = 4;
            local_30[4] = 5;
            local_30[5] = 6;
            local_30[6] = 7;
            local_30[7] = 7;
            bVar2 = *(byte *)(*(int *)(pbVar20 + uVar6 * 4) + iVar10);
            if (bVar2 != 0) {
              *(byte *)(*(int *)(pbVar20 + uVar6 * 4) + iVar10) =
                   bVar2 & (&DAT_000accab)
                           [iVar10 + (uint)local_30[iVar7] * 0x140 + (uVar6 % 0x1a) * 0xa00];
            }
            iVar10 = iVar10 + 1;
          } while (iVar10 != 0x140);
          uVar6 = uVar6 + 1;
        } while (uVar6 != 199);
        pGVar8 = __get_dashboard_state();
        uVar13 = (pGVar8->jdb_panel_context).current_row;
        pGVar8 = __get_dashboard_state();
        iVar7 = iVar7 + 1;
        _reflash_fb_data_to_lcd(uVar13,(pGVar8->jdb_panel_context).current_column,0,0,0x280,199);
      } while (iVar7 != 8);
      goto LAB_0003e470;
    }
    if (cVar1 == '\x04') goto LAB_0003e67a;
  }
  else {
    if (cVar1 == '\x04') {
LAB_0003e67a:
      _DAT_200024f0 = (uint)(byte)pGVar5->field20_0xc8[0x2d];
      iVar7 = 0x640;
      pGVar8 = __get_dashboard_state();
      buffer = &(pGVar8->jdb_panel_context).__panel_buffer;
      while( true ) {
        uVar3 = FUN_00080a3a();
        for (uVar6 = (uint)uVar3; uVar3 = FUN_00080a3a(), (int)uVar6 <= (int)(uVar3 + 0x87);
            uVar6 = uVar6 + 1) {
          iVar10 = FUN_000809e2();
          for (iVar10 = iVar10 + 0x58; iVar11 = FUN_000809e2(), iVar10 < (iVar11 + 0x230) / 2;
              iVar10 = iVar10 + 1) {
            pbVar20 = buffer[uVar6];
            bVar2 = pbVar20[iVar10];
            if (bVar2 != 0) {
              pbVar20[iVar10] =
                   bVar2 & (&DAT_000accab)[iVar10 + ((int)uVar6 % 0x1a) * 0xa00 + iVar7];
            }
          }
        }
        pGVar9 = __get_dashboard_state();
        uVar18 = (pGVar9->jdb_panel_context).current_row;
        pGVar9 = __get_dashboard_state();
        uVar13 = (pGVar9->jdb_panel_context).current_column;
        iVar10 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        iVar11 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        _reflash_fb_data_to_lcd(uVar18,uVar13,iVar10 + 0x58,(uint)uVar3,iVar11 + 0x230,uVar4 + 0x88)
        ;
        if (iVar7 == 0x500) break;
        iVar7 = 0x500;
      }
      _clean_fb_data((byte *)buffer,0,0,0x10,0x280,0xb8);
      FUN_0003e10c(pbVar17);
      iVar7 = __clear_showing_notification_on_gui();
      uVar6 = (uint)(byte)pGVar5->field20_0xc8[0x27];
      if (uVar6 < 6) {
        iVar7 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        iVar10 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        iVar10 = iVar10 + 0x236;
        local_4c = pcVar19;
      }
      else {
        if (uVar6 != 0xb) {
          if (uVar6 - 0xc < 3) {
            if (uVar6 != 0xe) {
              return iVar7;
            }
            pGVar5 = __get_dashboard_state();
            uVar13 = (pGVar5->jdb_panel_context).current_row;
            pGVar5 = __get_dashboard_state();
            _reflash_fb_data_to_lcd(uVar13,(pGVar5->jdb_panel_context).current_column,0,0,0x27f,199)
            ;
          }
          else if (uVar6 - 0xf < 2) {
            if (uVar6 != 0x10) {
              return iVar7;
            }
            memcpy(&DAT_2001c4e9,pGVar5->field20_0xc8 + 0x2e,
                   (uint)*(ushort *)(pGVar5->field20_0xc8 + 0x20e));
            iVar7 = FUN_000809e2();
            uVar3 = FUN_00080a3a();
            iVar10 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            gui_utf_draw(0,&DAT_2001c4e9,0,iVar7,(uint)uVar3,iVar10 + 0x240,uVar4 + 0x88,5,0,0,
                         (undefined *)0x0,0);
          }
          else {
            memcpy(&DAT_2001c4e9,pGVar5->field20_0xc8 + 0x2e,
                   (uint)*(ushort *)(pGVar5->field20_0xc8 + 0x20e));
            iVar7 = FUN_000809e2();
            uVar3 = FUN_00080a3a();
            iVar10 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            gui_utf_draw(0,&DAT_2001c4e9,0,iVar7 + 0x58,(uint)uVar3,iVar10 + 0x230,uVar4 + 0x88,5,0,
                         0,(undefined *)0x0,0);
            if (pGVar5->field20_0xc8[0x2c] != '\x01') {
              iVar7 = FUN_000809e2();
              uVar3 = FUN_00080a3a();
              iVar10 = FUN_000809e2();
              uVar4 = FUN_00080a3a();
              gui_verticalLine_process_bar
                        (iVar7 + 0x23c,(uint)uVar3,iVar10 + 0x23c,uVar4 + 0x88,1,
                         pGVar5->field20_0xc8[0x2b]);
            }
          }
          goto LAB_0003e75a;
        }
        iVar7 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        gui_bmp_bitmap_draw(0x4a,iVar7,uVar3 + 0x36,0,0,0);
        iVar7 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        iVar10 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        iVar10 = iVar10 + 0x230;
        iVar7 = iVar7 + 0x58;
      }
      gui_utf_draw_middle(0,local_4c,0,iVar7,uVar3 + 0x36,iVar10,uVar4 + 0x87,3,0,0,(undefined *)0x0
                          ,0);
LAB_0003e75a:
      iVar7 = 0;
      do {
        iVar10 = FUN_000809e2();
        iVar10 = iVar10 + 0x58;
        iVar11 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        uVar6 = (uint)uVar3;
        uVar3 = FUN_00080a3a();
        for (uVar15 = 0; (int)uVar15 < (int)((uVar3 + 0x88) - uVar6); uVar15 = uVar15 + 1) {
          for (iVar21 = 0; iVar21 < ((iVar11 + 0x230) - iVar10) / 2; iVar21 = iVar21 + 1) {
            local_30[0] = 1;
            local_30[1] = 2;
            local_30[2] = 3;
            local_30[3] = 4;
            local_30[4] = 5;
            local_30[5] = 6;
            local_30[6] = 7;
            local_30[7] = 7;
            iVar22 = iVar10 / 2 + iVar21;
            pbVar20 = (&(pGVar8->jdb_panel_context).__panel_buffer)[uVar6 + uVar15];
            bVar2 = pbVar20[iVar22];
            if (bVar2 != 0) {
              pbVar20[iVar22] =
                   bVar2 & (&DAT_000accab)
                           [iVar21 + (uint)local_30[iVar7] * 0x140 + (uVar15 % 0x1a) * 0xa00];
            }
          }
        }
        pGVar5 = __get_dashboard_state();
        uVar13 = (pGVar5->jdb_panel_context).current_row;
        pGVar5 = __get_dashboard_state();
        iVar7 = iVar7 + 1;
        _reflash_fb_data_to_lcd
                  (uVar13,(pGVar5->jdb_panel_context).current_column,iVar10,uVar6,iVar11 + 0x230,
                   uVar3 + 0x88);
      } while (iVar7 != 8);
      __set_showing_notification_on_gui();
      FUN_0003e10c(pbVar17);
      DAT_2000a9b8 = 1;
      return 0;
    }
    if (uVar6 < 5) {
      if (DAT_2000a9b8 != 0) {
        DAT_2000a9b8 = 0;
        gui_screen_clear();
      }
      iVar7 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      iVar10 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      iVar10 = iVar10 + 0x236;
      local_4c = pcVar19;
LAB_0003e94e:
      gui_utf_draw_middle(0,local_4c,0,iVar7,uVar4 + 0x36,iVar10,uVar3 + 0x87,3,0,0,(undefined *)0x0
                          ,0);
      return 0;
    }
    if (uVar6 == 0xb) {
      if (DAT_2000a9b8 != 0) {
        DAT_2000a9b8 = 0;
        gui_screen_clear();
      }
      iVar7 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      gui_bmp_bitmap_draw(0x4a,iVar7,uVar3 + 0x36,0,0,0);
      iVar7 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      iVar10 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      iVar10 = iVar10 + 0x230;
      iVar7 = iVar7 + 0x58;
      goto LAB_0003e94e;
    }
    if (uVar6 - 0xc < 3) {
      if (uVar6 != 0xe) {
        return iVar7;
      }
      pGVar5 = __get_dashboard_state();
      uVar13 = (pGVar5->jdb_panel_context).current_row;
      pGVar5 = __get_dashboard_state();
      _reflash_fb_data_to_lcd(uVar13,(pGVar5->jdb_panel_context).current_column,0,0,0x27f,199);
      return 0;
    }
    if (uVar6 - 0xf < 2) {
      if (uVar6 != 0x10) {
        return iVar7;
      }
      memcpy(&DAT_2001c4e9,pGVar5->field20_0xc8 + 0x2e,
             (uint)*(ushort *)(pGVar5->field20_0xc8 + 0x20e));
      iVar7 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      iVar10 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      gui_utf_draw(0,&DAT_2001c4e9,0,iVar7,(uint)uVar3,iVar10 + 0x240,uVar4 + 0x88,5,0,0,
                   (undefined *)0x0,0);
      return 0;
    }
    if (uVar6 < 7) {
      iVar7 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      iVar10 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      gui_utf_draw(0," ",0,iVar7 + 0x58,uVar3 + 0x36,iVar10 + 0x230,uVar4 + 0x87,5,0,0,
                   (undefined *)0x0,0);
      DAT_2000a9b4 = 0;
      DAT_2000a9b8 = 1;
      return 0;
    }
  }
  memset(&DAT_2001c4e9,0,0x1e0);
  memcpy(&DAT_2001c4e9,pGVar5->field20_0xc8 + 0x2e,(uint)*(ushort *)(pGVar5->field20_0xc8 + 0x20e));
  if ((1 < (byte)pGVar5->field20_0xc8[0x27] - 8) && (DAT_2000a9b4 != 0)) {
    DAT_2001c4e8 = 1;
    iVar7 = FUN_000809e2();
    uVar3 = FUN_00080a3a();
    iVar10 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    FUN_00046544(0,&DAT_2001c4e9,0,iVar7 + 0x58,uVar3 + 1,iVar10 + 0x230,uVar4 + 0x88,5,0);
    DAT_2001c4e8 = 0;
    goto LAB_0003edd4;
  }
  uVar3 = FUN_00080a3a();
  if (uVar3 < 0x21) {
    iVar7 = FUN_000809e2();
    uVar3 = FUN_00080a3a();
    iVar11 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    iVar10 = uVar4 + 0xa3;
    iVar21 = uVar3 + 0x88;
LAB_0003ed84:
    _clean_fb_data(pbVar20,0,iVar7 + 0x58,iVar21,iVar11 + 0x230,iVar10);
  }
  else {
    uVar3 = FUN_00080a3a();
    if (0x20 < uVar3) {
      iVar7 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      iVar11 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      iVar10 = uVar4 + 1;
      iVar21 = uVar3 - 0x1a;
      goto LAB_0003ed84;
    }
  }
  iVar7 = FUN_000809e2();
  uVar3 = FUN_00080a3a();
  iVar10 = FUN_000809e2();
  uVar4 = FUN_00080a3a();
  gui_utf_draw(0,&DAT_2001c4e9,0,iVar7 + 0x58,(uint)uVar3,iVar10 + 0x230,uVar4 + 0x88,5,0,0,
               (undefined *)0x0,0);
  if (DAT_2000a9b4 == 0) {
    DAT_2000a9b4 = 1;
  }
LAB_0003edd4:
  if (pGVar5->field20_0xc8[0x2c] != '\x01') {
    iVar7 = FUN_000809e2();
    uVar3 = FUN_00080a3a();
    iVar10 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    gui_verticalLine_process_bar
              (iVar7 + 0x23c,(uint)uVar3,iVar10 + 0x23c,uVar4 + 0x88,1,pGVar5->field20_0xc8[0x2b]);
  }
  DAT_2000a9b8 = 1;
  return 0;
}


