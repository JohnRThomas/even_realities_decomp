/*
 * Function: ui_even_ai_task
 * Entry:    0003e2d4
 * Prototype: int __stdcall ui_even_ai_task(int param_1, undefined4 param_2, int param_3)
 */


int ui_even_ai_task(int param_1,undefined4 param_2,int param_3)

{
  char cVar1;
  byte bVar2;
  ushort uVar3;
  ushort uVar4;
  GlassesState *pGVar5;
  uint uVar6;
  undefined4 extraout_r0;
  undefined4 extraout_r0_00;
  int iVar7;
  GlassesState *pGVar8;
  GlassesState *pGVar9;
  int iVar10;
  undefined4 extraout_r1;
  char *pcVar11;
  undefined4 extraout_r1_00;
  undefined4 uVar12;
  undefined4 extraout_r1_01;
  undefined4 extraout_r1_02;
  undefined4 extraout_r1_03;
  int iVar13;
  undefined4 extraout_r2;
  undefined4 uVar14;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 extraout_r2_02;
  undefined4 extraout_r2_03;
  undefined4 extraout_r2_04;
  undefined4 extraout_r2_05;
  undefined4 uVar15;
  undefined4 extraout_r2_06;
  uint uVar16;
  undefined4 *puVar17;
  undefined1 *puVar18;
  int iVar19;
  char *pcVar20;
  int iVar21;
  bool bVar22;
  k_timeout_t timeout;
  char *local_4c;
  byte local_30 [12];
  
  pGVar5 = __get_dashboard_state();
  bVar2 = get_current_language();
  puVar17 = (undefined4 *)(uint)(byte)pGVar5->field_0xef;
  bVar22 = puVar17 != (undefined4 *)0x7;
  uVar14 = extraout_r2;
  if (bVar22) {
    uVar14 = 0xffffffff;
    puVar17 = &DAT_200024f0;
  }
  uVar6 = bVar2 - 4 & 0xff;
  if (bVar22) {
    *puVar17 = uVar14;
  }
  if (uVar6 < 0xb) {
    pcVar20 = (&PTR_DAT_0008db64)[uVar6];
    local_4c = (&PTR_DAT_0008db38)[uVar6];
  }
  else {
    pcVar20 = &DAT_20003660;
    local_4c = &DAT_20003634;
  }
  iVar21 = param_1 + 0x24;
  FUN_000452f0(iVar21);
  uVar14 = FUN_0004540c();
  if ((char)DAT_2001c6c9 == '\0') {
    if (param_3 == 1) {
      memset(&DAT_2001c4e9,0,0x1e0);
      uVar14 = extraout_r2_01;
      if (0 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): ENTER evenai INIT process...\n");
          uVar14 = extraout_r2_04;
        }
        else {
          ble_printk("%s(): ENTER evenai INIT process...\n","ui_even_ai_task",extraout_r2_01,
                     BLE_DEBUG);
          uVar14 = extraout_r2_02;
        }
      }
      if (DAT_2001c6c9._1_1_ != '\0') {
        return 0;
      }
      if (0 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): SYNC_AREA_REFALSH Upgrade ....\n");
        }
        else {
          ble_printk("%s(): SYNC_AREA_REFALSH Upgrade ....\n","ui_even_ai_task",uVar14,BLE_DEBUG);
        }
      }
      uVar14 = FUN_000809d0();
      if ((byte)pGVar5->field_0xef < 0xc) {
        gui_screen_clear(uVar14,extraout_r1,extraout_r2_03);
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
      iVar7 = FUN_00045428();
      do {
        uVar6 = (uint)(byte)pGVar5->field_0xef;
        if (uVar6 == 0xb) {
          iVar7 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          gui_bmp_bitmap_draw(0x4a,iVar7,uVar3 + 0x36,0,0,0);
          iVar13 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          iVar7 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          iVar7 = iVar7 + 0x230;
          iVar13 = iVar13 + 0x58;
          pcVar11 = local_4c;
LAB_0003e42a:
          gui_utf_draw_middle(0,pcVar11,0,iVar13,uVar3 + 0x36,iVar7,uVar4 + 0x87,3,0,0,
                              (undefined *)0x0,0);
        }
        else {
          if (uVar6 - 0xc < 3) {
            if (uVar6 != 0xe) {
              return iVar7;
            }
            pGVar5 = __get_dashboard_state();
            iVar21 = *(int *)&pGVar5->field_0xeb4;
            pGVar5 = __get_dashboard_state();
            _reflash_fb_data_to_lcd(iVar21,*(int *)&pGVar5->field_0xeb8,0,0,0x27f,199);
            break;
          }
          if (1 < uVar6 - 0xf) {
            iVar13 = FUN_000809e2();
            uVar3 = FUN_00080a3a();
            iVar7 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            iVar7 = iVar7 + 0x236;
            pcVar11 = pcVar20;
            goto LAB_0003e42a;
          }
          if (uVar6 != 0x10) {
            return iVar7;
          }
          memcpy(&DAT_2001c4e9,&pGVar5->field_0xf6,(uint)*(ushort *)&pGVar5->field_0x2d6);
          iVar7 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          iVar13 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          gui_utf_draw(0,&DAT_2001c4e9,0,iVar7,(uint)uVar3,iVar13 + 0x240,uVar4 + 0x88,5,0,0,
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
            iVar13 = *(int *)(iVar21 + uVar6 * 4);
            bVar2 = *(byte *)(iVar13 + iVar7);
            if (bVar2 != 0) {
              *(byte *)(iVar13 + iVar7) =
                   bVar2 & (&DAT_000accab)
                           [iVar7 + (uint)local_30[iVar10] * 0x140 + (uVar6 % 0x1a) * 0xa00];
            }
            iVar7 = iVar7 + 1;
          } while (iVar7 != 0x140);
          uVar6 = uVar6 + 1;
        } while (uVar6 != 199);
        pGVar8 = __get_dashboard_state();
        iVar7 = *(int *)&pGVar8->field_0xeb4;
        pGVar8 = __get_dashboard_state();
        iVar10 = iVar10 + 1;
        iVar7 = _reflash_fb_data_to_lcd(iVar7,*(int *)&pGVar8->field_0xeb8,0,0,0x280,199);
      } while (iVar10 != 8);
LAB_0003e470:
      FUN_0004540c();
      return 0;
    }
    if (param_3 != 2) {
      return 0;
    }
    uVar12 = 0;
    uVar15 = extraout_r2_00;
    if (2 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): evenai process received exit packet ...\n");
        uVar14 = extraout_r0_00;
        uVar12 = extraout_r1_01;
        uVar15 = extraout_r2_06;
      }
      else {
        ble_printk("%s(): evenai process received exit packet ...\n","ui_even_ai_task",
                   extraout_r2_00,BLE_DEBUG);
        uVar14 = extraout_r0;
        uVar12 = extraout_r1_00;
        uVar15 = extraout_r2_05;
      }
    }
    gui_screen_clear(uVar14,uVar12,uVar15);
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
  puVar18 = &pGVar5->field_0xef;
  if (param_3 != 1) {
    if (param_3 == 0) {
      FUN_0003e10c(puVar18);
      return 0;
    }
    if (param_3 != 2) {
      return 0;
    }
    if (2 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): evenai process received exit packet ...\n");
      }
      else {
        ble_printk("%s(): evenai process received exit packet ...\n","ui_even_ai_task",
                   extraout_r2_00,BLE_DEBUG);
      }
    }
    FUN_00045968();
    goto LAB_0003e5c8;
  }
  memset(&DAT_2001c4e9,0,0x1e0);
  timeout.ticks._4_4_ = 0xffffffff;
  timeout.ticks._0_4_ = extraout_r1_02;
  z_impl_k_mutex_lock(&k_mutex_2000851c,timeout);
  cVar1 = pGVar5->field_0xf0;
  iVar7 = z_impl_k_mutex_unlock(&k_mutex_2000851c);
  uVar6 = (uint)(byte)pGVar5->field_0xef;
  if (uVar6 == 7) {
    if ((DAT_200024f0 == 0xffffffff) && (cVar1 == '\x03')) {
      DAT_200024f0 = (uint)(byte)pGVar5->field_0xf5;
      iVar7 = 0;
      FUN_00045428();
      do {
        memcpy(&DAT_2001c4e9,&pGVar5->field_0xf6,(uint)*(ushort *)&pGVar5->field_0x2d6);
        iVar10 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        iVar13 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        gui_utf_draw(0,&DAT_2001c4e9,0,iVar10 + 0x58,(uint)uVar3,iVar13 + 0x230,uVar4 + 0x88,5,0,0,
                     (undefined *)0x0,0);
        if (pGVar5->field_0xf4 != '\x01') {
          iVar10 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          iVar13 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          gui_verticalLine_process_bar
                    (iVar10 + 0x23c,(uint)uVar3,iVar13 + 0x23c,uVar4 + 0x88,1,pGVar5->field_0xf3);
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
            iVar13 = *(int *)(iVar21 + uVar6 * 4);
            bVar2 = *(byte *)(iVar13 + iVar10);
            if (bVar2 != 0) {
              *(byte *)(iVar13 + iVar10) =
                   bVar2 & (&DAT_000accab)
                           [iVar10 + (uint)local_30[iVar7] * 0x140 + (uVar6 % 0x1a) * 0xa00];
            }
            iVar10 = iVar10 + 1;
          } while (iVar10 != 0x140);
          uVar6 = uVar6 + 1;
        } while (uVar6 != 199);
        pGVar8 = __get_dashboard_state();
        iVar10 = *(int *)&pGVar8->field_0xeb4;
        pGVar8 = __get_dashboard_state();
        iVar7 = iVar7 + 1;
        _reflash_fb_data_to_lcd(iVar10,*(int *)&pGVar8->field_0xeb8,0,0,0x280,199);
      } while (iVar7 != 8);
      goto LAB_0003e470;
    }
    if (cVar1 == '\x04') goto LAB_0003e67a;
  }
  else {
    if (cVar1 == '\x04') {
LAB_0003e67a:
      DAT_200024f0 = (uint)(byte)pGVar5->field_0xf5;
      iVar21 = 0x640;
      pGVar8 = __get_dashboard_state();
      while( true ) {
        uVar3 = FUN_00080a3a();
        for (uVar6 = (uint)uVar3; uVar3 = FUN_00080a3a(), (int)uVar6 <= (int)(uVar3 + 0x87);
            uVar6 = uVar6 + 1) {
          iVar7 = FUN_000809e2();
          for (iVar7 = iVar7 + 0x58; iVar10 = FUN_000809e2(), iVar7 < (iVar10 + 0x230) / 2;
              iVar7 = iVar7 + 1) {
            iVar10 = *(int *)(&pGVar8->field_0xb90 + uVar6 * 4);
            bVar2 = *(byte *)(iVar10 + iVar7);
            if (bVar2 != 0) {
              *(byte *)(iVar10 + iVar7) =
                   bVar2 & (&DAT_000accab)[iVar7 + ((int)uVar6 % 0x1a) * 0xa00 + iVar21];
            }
          }
        }
        pGVar9 = __get_dashboard_state();
        iVar19 = *(int *)&pGVar9->field_0xeb4;
        pGVar9 = __get_dashboard_state();
        iVar13 = *(int *)&pGVar9->field_0xeb8;
        iVar7 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        iVar10 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        _reflash_fb_data_to_lcd(iVar19,iVar13,iVar7 + 0x58,(uint)uVar3,iVar10 + 0x230,uVar4 + 0x88);
        if (iVar21 == 0x500) break;
        iVar21 = 0x500;
      }
      _clean_fb_data((int)&pGVar8->field_0xb90,0,0,0x10,0x280,0xb8);
      FUN_0003e10c(puVar18);
      iVar21 = FUN_00045428();
      uVar6 = (uint)(byte)pGVar5->field_0xef;
      if (uVar6 < 6) {
        iVar21 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        iVar7 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        iVar7 = iVar7 + 0x236;
        local_4c = pcVar20;
      }
      else {
        if (uVar6 != 0xb) {
          if (uVar6 - 0xc < 3) {
            if (uVar6 != 0xe) {
              return iVar21;
            }
            pGVar5 = __get_dashboard_state();
            iVar21 = *(int *)&pGVar5->field_0xeb4;
            pGVar5 = __get_dashboard_state();
            _reflash_fb_data_to_lcd(iVar21,*(int *)&pGVar5->field_0xeb8,0,0,0x27f,199);
          }
          else if (uVar6 - 0xf < 2) {
            if (uVar6 != 0x10) {
              return iVar21;
            }
            memcpy(&DAT_2001c4e9,&pGVar5->field_0xf6,(uint)*(ushort *)&pGVar5->field_0x2d6);
            iVar21 = FUN_000809e2();
            uVar3 = FUN_00080a3a();
            iVar7 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            gui_utf_draw(0,&DAT_2001c4e9,0,iVar21,(uint)uVar3,iVar7 + 0x240,uVar4 + 0x88,5,0,0,
                         (undefined *)0x0,0);
          }
          else {
            memcpy(&DAT_2001c4e9,&pGVar5->field_0xf6,(uint)*(ushort *)&pGVar5->field_0x2d6);
            iVar21 = FUN_000809e2();
            uVar3 = FUN_00080a3a();
            iVar7 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            gui_utf_draw(0,&DAT_2001c4e9,0,iVar21 + 0x58,(uint)uVar3,iVar7 + 0x230,uVar4 + 0x88,5,0,
                         0,(undefined *)0x0,0);
            if (pGVar5->field_0xf4 != '\x01') {
              iVar21 = FUN_000809e2();
              uVar3 = FUN_00080a3a();
              iVar7 = FUN_000809e2();
              uVar4 = FUN_00080a3a();
              gui_verticalLine_process_bar
                        (iVar21 + 0x23c,(uint)uVar3,iVar7 + 0x23c,uVar4 + 0x88,1,pGVar5->field_0xf3)
              ;
            }
          }
          goto LAB_0003e75a;
        }
        iVar21 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        gui_bmp_bitmap_draw(0x4a,iVar21,uVar3 + 0x36,0,0,0);
        iVar21 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        iVar7 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        iVar7 = iVar7 + 0x230;
        iVar21 = iVar21 + 0x58;
      }
      gui_utf_draw_middle(0,local_4c,0,iVar21,uVar3 + 0x36,iVar7,uVar4 + 0x87,3,0,0,(undefined *)0x0
                          ,0);
LAB_0003e75a:
      iVar21 = 0;
      do {
        iVar7 = FUN_000809e2();
        iVar7 = iVar7 + 0x58;
        iVar10 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        uVar6 = (uint)uVar3;
        uVar3 = FUN_00080a3a();
        for (uVar16 = 0; (int)uVar16 < (int)((uVar3 + 0x88) - uVar6); uVar16 = uVar16 + 1) {
          for (iVar13 = 0; iVar13 < ((iVar10 + 0x230) - iVar7) / 2; iVar13 = iVar13 + 1) {
            local_30[0] = 1;
            local_30[1] = 2;
            local_30[2] = 3;
            local_30[3] = 4;
            local_30[4] = 5;
            local_30[5] = 6;
            local_30[6] = 7;
            local_30[7] = 7;
            iVar19 = iVar7 / 2 + iVar13;
            bVar2 = *(byte *)(*(int *)(&pGVar8->field_0xb90 + uVar16 * 4 + uVar6 * 4) + iVar19);
            if (bVar2 != 0) {
              *(byte *)(*(int *)(&pGVar8->field_0xb90 + uVar16 * 4 + uVar6 * 4) + iVar19) =
                   bVar2 & (&DAT_000accab)
                           [iVar13 + (uint)local_30[iVar21] * 0x140 + (uVar16 % 0x1a) * 0xa00];
            }
          }
        }
        pGVar5 = __get_dashboard_state();
        iVar13 = *(int *)&pGVar5->field_0xeb4;
        pGVar5 = __get_dashboard_state();
        iVar21 = iVar21 + 1;
        _reflash_fb_data_to_lcd
                  (iVar13,*(int *)&pGVar5->field_0xeb8,iVar7,uVar6,iVar10 + 0x230,uVar3 + 0x88);
      } while (iVar21 != 8);
      FUN_0004540c();
      FUN_0003e10c(puVar18);
      DAT_2000a9b8 = 1;
      return 0;
    }
    if (uVar6 < 5) {
      if (DAT_2000a9b8 != 0) {
        DAT_2000a9b8 = 0;
        gui_screen_clear(iVar7,extraout_r1_03,0);
      }
      iVar21 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      iVar7 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      iVar7 = iVar7 + 0x236;
      local_4c = pcVar20;
LAB_0003e94e:
      gui_utf_draw_middle(0,local_4c,0,iVar21,uVar4 + 0x36,iVar7,uVar3 + 0x87,3,0,0,(undefined *)0x0
                          ,0);
      return 0;
    }
    if (uVar6 == 0xb) {
      if (DAT_2000a9b8 != 0) {
        DAT_2000a9b8 = 0;
        gui_screen_clear(iVar7,extraout_r1_03,0);
      }
      iVar21 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      gui_bmp_bitmap_draw(0x4a,iVar21,uVar3 + 0x36,0,0,0);
      iVar21 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      iVar7 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      iVar7 = iVar7 + 0x230;
      iVar21 = iVar21 + 0x58;
      goto LAB_0003e94e;
    }
    if (uVar6 - 0xc < 3) {
      if (uVar6 != 0xe) {
        return iVar7;
      }
      pGVar5 = __get_dashboard_state();
      iVar21 = *(int *)&pGVar5->field_0xeb4;
      pGVar5 = __get_dashboard_state();
      _reflash_fb_data_to_lcd(iVar21,*(int *)&pGVar5->field_0xeb8,0,0,0x27f,199);
      return 0;
    }
    if (uVar6 - 0xf < 2) {
      if (uVar6 != 0x10) {
        return iVar7;
      }
      memcpy(&DAT_2001c4e9,&pGVar5->field_0xf6,(uint)*(ushort *)&pGVar5->field_0x2d6);
      iVar21 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      iVar7 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      gui_utf_draw(0,&DAT_2001c4e9,0,iVar21,(uint)uVar3,iVar7 + 0x240,uVar4 + 0x88,5,0,0,
                   (undefined *)0x0,0);
      return 0;
    }
    if (uVar6 < 7) {
      iVar21 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      iVar7 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      gui_utf_draw(0," ",0,iVar21 + 0x58,uVar3 + 0x36,iVar7 + 0x230,uVar4 + 0x87,5,0,0,
                   (undefined *)0x0,0);
      DAT_2000a9b4 = 0;
      DAT_2000a9b8 = 1;
      return 0;
    }
  }
  memset(&DAT_2001c4e9,0,0x1e0);
  memcpy(&DAT_2001c4e9,&pGVar5->field_0xf6,(uint)*(ushort *)&pGVar5->field_0x2d6);
  if ((1 < (byte)pGVar5->field_0xef - 8) && (DAT_2000a9b4 != 0)) {
    DAT_2001c4e8 = 1;
    iVar21 = FUN_000809e2();
    uVar3 = FUN_00080a3a();
    iVar7 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    FUN_00046544(0,&DAT_2001c4e9,0,iVar21 + 0x58,uVar3 + 1,iVar7 + 0x230,uVar4 + 0x88,5,0);
    DAT_2001c4e8 = 0;
    goto LAB_0003edd4;
  }
  uVar3 = FUN_00080a3a();
  if (uVar3 < 0x21) {
    iVar7 = FUN_000809e2();
    uVar3 = FUN_00080a3a();
    iVar13 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    iVar10 = uVar4 + 0xa3;
    iVar19 = uVar3 + 0x88;
LAB_0003ed84:
    _clean_fb_data(iVar21,0,iVar7 + 0x58,iVar19,iVar13 + 0x230,iVar10);
  }
  else {
    uVar3 = FUN_00080a3a();
    if (0x20 < uVar3) {
      iVar7 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      iVar13 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      iVar10 = uVar4 + 1;
      iVar19 = uVar3 - 0x1a;
      goto LAB_0003ed84;
    }
  }
  iVar21 = FUN_000809e2();
  uVar3 = FUN_00080a3a();
  iVar7 = FUN_000809e2();
  uVar4 = FUN_00080a3a();
  gui_utf_draw(0,&DAT_2001c4e9,0,iVar21 + 0x58,(uint)uVar3,iVar7 + 0x230,uVar4 + 0x88,5,0,0,
               (undefined *)0x0,0);
  if (DAT_2000a9b4 == 0) {
    DAT_2000a9b4 = 1;
  }
LAB_0003edd4:
  if (pGVar5->field_0xf4 != '\x01') {
    iVar21 = FUN_000809e2();
    uVar3 = FUN_00080a3a();
    iVar7 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    gui_verticalLine_process_bar
              (iVar21 + 0x23c,(uint)uVar3,iVar7 + 0x23c,uVar4 + 0x88,1,pGVar5->field_0xf3);
  }
  DAT_2000a9b8 = 1;
  return 0;
}


