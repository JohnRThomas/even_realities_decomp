/*
 * Function: ui_QuickNote_task
 * Entry:    0003d7c0
 * Prototype: undefined4 __stdcall ui_QuickNote_task(int param_1, undefined4 param_2, uint param_3)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 ui_QuickNote_task(int param_1,undefined4 param_2,uint param_3)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  ushort uVar4;
  ushort uVar5;
  GlassesState *pGVar6;
  GlassesState *pGVar7;
  int iVar8;
  char *pcVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  byte *buffer;
  uint uVar13;
  uint32_t uVar14;
  int iVar15;
  bool bVar16;
  undefined8 uVar17;
  longlong lVar18;
  byte local_30 [12];
  
  pGVar6 = __get_dashboard_state();
  bVar2 = get_current_language();
  buffer = (byte *)(param_1 + 0x24);
  __set_frame_buffer(buffer);
  __set_showing_notification_on_gui();
  if (DAT_20004b20 != '\x01') {
    if (DAT_20004b20 != '\x02') {
      lVar18 = CONCAT44(DAT_20004b2c,DAT_20004b28);
      if (DAT_20004b20 == '\0') {
        if (2 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): QUICK NOTE INIT.....\n","ui_QuickNote_task");
          }
          else {
            ble_printk("%s(): QUICK NOTE INIT.....\n");
          }
        }
        memset(&DAT_20004b20,0,0x20);
        if (2 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            pGVar7 = __get_dashboard_state();
            printk("%s(): GLOBAL->quicknote_show_info->enable = %d\n","ui_QuickNote_task",
                   (uint)*(byte *)(*(int *)&pGVar7->field_0x1034 + 1));
          }
          else {
            pGVar7 = __get_dashboard_state();
            ble_printk("%s(): GLOBAL->quicknote_show_info->enable = %d\n","ui_QuickNote_task",
                       (uint)*(byte *)(*(int *)&pGVar7->field_0x1034 + 1));
          }
        }
        if (param_3 == 1) {
          pGVar7 = __get_dashboard_state();
          lVar18 = CONCAT44(DAT_20004b2c,DAT_20004b28);
          if (*(char *)(*(int *)&pGVar7->field_0x1034 + 1) == '\x01') {
            if (2 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): quick note function start ...\n","ui_QuickNote_task");
              }
              else {
                ble_printk("%s(): quick note function start ...\n");
              }
            }
            gui_screen_clear();
            iVar12 = 0;
            DAT_20004b20 = '\x01';
            DAT_20004b30 = pGVar6->field20_0xc8[0x2a];
            DAT_20004b31 = '\0';
            DAT_2001c4e7 = '\0';
            FUN_00045444();
            __clear_showing_notification_on_gui();
            do {
              if (pGVar6->field20_0xc8[0x2a] == '\n') {
                DAT_2001c4e7 = '\x01';
                uVar17 = FUN_0008078e();
                DAT_20004b2c = (int)((ulonglong)uVar17 >> 0x20);
                DAT_20004b28 = (uint)uVar17;
                if (pGVar6->field20_0xc8[0x2b] == '\x02') {
                  if (bVar2 == 6) {
                    iVar15 = 0xc6;
                  }
                  else if (bVar2 == 5) {
                    iVar15 = 0xcc;
                  }
                  else if (bVar2 == 7) {
                    iVar15 = 0xd6;
                  }
                  else if (bVar2 == 0xe) {
                    iVar15 = 0xd0;
                  }
                  else {
                    iVar15 = 0xcc;
                  }
                  iVar8 = FUN_000809e2();
                  uVar4 = FUN_00080a3a();
                  gui_bmp_bitmap_draw(0x4a,iVar8 + iVar15,uVar4 + 0x3a,0,0,0);
                  pcVar9 = get_string(0x52);
                  iVar8 = FUN_000809e2();
                  uVar4 = FUN_00080a3a();
                  iVar10 = FUN_000809e2();
                  uVar5 = FUN_00080a3a();
                  gui_utf_draw(0,pcVar9,0,iVar8 + iVar15 + 0x2c,uVar4 + 0x36,iVar10 + 0x240,
                               uVar5 + 0x88,1,0,0,(undefined *)0x0,0);
                  uVar17 = CONCAT44(DAT_20004b2c,DAT_20004b28);
                }
              }
              else {
                pcVar9 = get_string(0x44);
                iVar15 = FUN_000809e2();
                uVar4 = FUN_00080a3a();
                iVar8 = FUN_000809e2();
                uVar5 = FUN_00080a3a();
                gui_utf_draw_middle(0,pcVar9,0,iVar15,uVar4 + 0x36,iVar8 + 0x240,uVar5 + 0x51,1,0,0,
                                    (undefined *)0x0,0);
                uVar17 = CONCAT44(DAT_20004b2c,DAT_20004b28);
                if (pGVar6->field20_0xc8[0x29] == '\0') {
                  pcVar9 = get_string(0x45);
                  iVar15 = FUN_000809e2();
                  uVar4 = FUN_00080a3a();
                  iVar8 = FUN_000809e2();
                  uVar5 = FUN_00080a3a();
                  gui_utf_draw_middle(0,pcVar9,0,iVar15,uVar4 + 0x6c,iVar8 + 0x240,uVar5 + 0x87,1,0,
                                      0,(undefined *)0x0,0);
                  uVar17 = CONCAT44(DAT_20004b2c,DAT_20004b28);
                }
              }
              uVar13 = 0;
              do {
                iVar15 = 0;
                do {
                  DAT_20004b2c = (int)((ulonglong)uVar17 >> 0x20);
                  DAT_20004b28 = (uint)uVar17;
                  local_30[0] = 1;
                  local_30[1] = 3;
                  local_30[2] = 5;
                  local_30[3] = 7;
                  local_30[4] = 7;
                  local_30[5] = 7;
                  local_30[6] = 7;
                  local_30[7] = 7;
                  bVar1 = *(byte *)(*(int *)(buffer + uVar13 * 4) + iVar15);
                  if (bVar1 != 0) {
                    *(byte *)(*(int *)(buffer + uVar13 * 4) + iVar15) =
                         bVar1 & (&DAT_000accab)
                                 [iVar15 + (uint)local_30[iVar12] * 0x140 + (uVar13 % 0x1a) * 0xa00]
                    ;
                    uVar17 = CONCAT44(DAT_20004b2c,DAT_20004b28);
                  }
                  DAT_20004b2c = (int)((ulonglong)uVar17 >> 0x20);
                  DAT_20004b28 = (uint)uVar17;
                  iVar15 = iVar15 + 1;
                } while (iVar15 != 0x140);
                uVar13 = uVar13 + 1;
              } while (uVar13 != 199);
              pGVar7 = __get_dashboard_state();
              uVar14 = (pGVar7->jdb_panel_context).current_row;
              pGVar7 = __get_dashboard_state();
              iVar12 = iVar12 + 1;
              _reflash_fb_data_to_lcd
                        (uVar14,(pGVar7->jdb_panel_context).current_column,0,0,0x280,199);
            } while (iVar12 != 4);
            __set_showing_notification_on_gui();
            pGVar6 = __get_dashboard_state();
            lVar18 = CONCAT44(DAT_20004b2c,DAT_20004b28);
            if (pGVar6->is_master == true) {
              if (DAT_20004b31 == '\x01') {
                cVar3 = FUN_00030440();
                lVar18 = CONCAT44(DAT_20004b2c,DAT_20004b28);
                if (cVar3 == '\x01') {
                  FUN_0008040c();
                  lVar18 = CONCAT44(DAT_20004b2c,DAT_20004b28);
                }
              }
              else {
                if (DAT_20008558 == 1) {
                  cVar3 = FUN_00030440();
                  lVar18 = CONCAT44(DAT_20004b2c,DAT_20004b28);
                  if (cVar3 != '\x01') goto LAB_0003da02;
                }
                dmic_record_start();
                lVar18 = CONCAT44(DAT_20004b2c,DAT_20004b28);
              }
            }
          }
        }
        else {
          lVar18 = CONCAT44(DAT_20004b2c,DAT_20004b28);
          if (param_3 == 2) {
            if (0 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): quick init,exec function exit ...\n","ui_QuickNote_task");
              }
              else {
                ble_printk("%s(): quick init,exec function exit ...\n");
              }
            }
            pGVar6 = __get_dashboard_state();
            if (pGVar6->is_master == true) {
              if (DAT_20004b31 == '\x01') {
                FUN_00030458();
              }
              else {
                FUN_0003d790();
              }
            }
            gui_screen_clear();
            pGVar6 = __get_dashboard_state();
            *(undefined1 *)(*(int *)&pGVar6->field_0x1034 + 1) = 0;
            memset(&DAT_20004b20,0,0x20);
            DAT_2001c4e7 = '\0';
            lVar18 = CONCAT44(DAT_20004b2c,DAT_20004b28);
          }
        }
      }
      goto LAB_0003da02;
    }
    if (LOG_LEVEL < 3) {
      if (param_3 != 2) goto LAB_0003e0a4;
LAB_0003df4c:
      pGVar6 = __get_dashboard_state();
      if (pGVar6->is_master == true) {
        if (DAT_20004b31 == '\x01') {
          FUN_00030458();
        }
        else {
          FUN_0003d790();
        }
      }
    }
    else {
      if (BLE_DEBUG == 0) {
        printk("%s(): quick note process exec.....\n","ui_QuickNote_task");
      }
      else {
        ble_printk("%s(): quick note process exec.....\n");
      }
      if (param_3 == 2) {
        if (2 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): quick note function exit ...\n","ui_QuickNote_task");
          }
          else {
            ble_printk("%s(): quick note function exit ...\n");
          }
        }
        goto LAB_0003df4c;
      }
LAB_0003e0a4:
      uVar17 = FUN_0008078e();
      lVar18 = CONCAT44(DAT_20004b2c,DAT_20004b28);
      iVar12 = (int)((ulonglong)uVar17 >> 0x20);
      uVar13 = (uint)uVar17;
      uVar11 = DAT_20004b24 + DAT_20004b28;
      iVar15 = DAT_20004b2c + ((int)DAT_20004b24 >> 0x1f) + (uint)CARRY4(DAT_20004b24,DAT_20004b28);
      if ((int)((iVar15 - iVar12) - (uint)(uVar11 < uVar13)) < 0 ==
          (SBORROW4(iVar15,iVar12) != SBORROW4(iVar15 - iVar12,(uint)(uVar11 < uVar13)))) {
        iVar15 = (iVar15 - ((int)_DAT_200024ec >> 0x1f)) - (uint)(uVar11 < _DAT_200024ec);
        bVar16 = uVar11 - _DAT_200024ec < uVar13;
        if ((int)((iVar15 - iVar12) - (uint)bVar16) < 0 ==
            (SBORROW4(iVar15,iVar12) != SBORROW4(iVar15 - iVar12,(uint)bVar16))) {
          if (DAT_2001c4e7 == '\0') {
            iVar12 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            gui_bmp_dynamic_bitmap_draw(9,iVar12,uVar4 + 0x36);
            iVar12 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            iVar15 = FUN_000809e2();
            uVar5 = FUN_00080a3a();
            gui_utf_draw_darkword_by_lines
                      (0,pGVar6->field20_0xc8 + 0x2f,0,iVar12 + 100,(uint)uVar4,iVar15 + 0x1dc,
                       uVar5 + 0x88,5,5,0,(undefined *)0x0,0);
            lVar18 = CONCAT44(DAT_20004b2c,DAT_20004b28);
          }
        }
        else {
          lVar18 = CONCAT44(DAT_20004b2c,DAT_20004b28);
          if (DAT_2001c4e7 == '\0') {
            if (2 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): exec quick note exit display...\n","ui_QuickNote_task");
              }
              else {
                ble_printk("%s(): exec quick note exit display...\n");
              }
            }
            gui_screen_clear();
            iVar12 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            gui_bmp_bitmap_draw(0x3b,iVar12,uVar4 + 0x36,0,0,0);
            pcVar9 = get_string(0x46);
            iVar12 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            iVar15 = FUN_000809e2();
            uVar5 = FUN_00080a3a();
            gui_utf_draw_middle(0,pcVar9,0,iVar12 + 0x24,uVar4 + 0x36,iVar15 + 0x21c,uVar5 + 0x6c,2,
                                0,0,(undefined *)0x0,0);
            lVar18 = CONCAT44(DAT_20004b2c,DAT_20004b28);
            DAT_2001c4e7 = '\x01';
          }
        }
        goto LAB_0003da02;
      }
      if (2 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): quick note function exit -164 ...\n","ui_QuickNote_task");
        }
        else {
          ble_printk("%s(): quick note function exit -164 ...\n");
        }
      }
    }
    FUN_00045968();
    pGVar6 = __get_dashboard_state();
    *(undefined1 *)(*(int *)&pGVar6->field_0x1034 + 1) = 0;
    memset(&DAT_20004b20,0,0x20);
    DAT_2001c4e7 = '\0';
    lVar18 = CONCAT44(DAT_20004b2c,DAT_20004b28);
    goto LAB_0003da02;
  }
  if (2 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): QUICK NOTE RUNING.....\n","ui_QuickNote_task");
    }
    else {
      ble_printk("%s(): QUICK NOTE RUNING.....\n");
    }
  }
  pGVar7 = __get_dashboard_state();
  lVar18 = CONCAT44(DAT_20004b2c,DAT_20004b28);
  if (*(char *)(*(int *)&pGVar7->field_0x1034 + 1) == '\x01') {
    if (param_3 == 1) {
      cVar3 = pGVar6->field20_0xc8[0x2a];
      if (cVar3 == '\b') {
        if (DAT_20004b30 != '\b') {
          DAT_20004b30 = cVar3;
          iVar12 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          iVar15 = FUN_000809e2();
          uVar5 = FUN_00080a3a();
          _clean_fb_data(buffer,0,iVar12 + 0x14,(uint)uVar4,iVar15 + 0x240,uVar5 + 0x88);
        }
        lVar18 = CONCAT44(DAT_20004b2c,DAT_20004b28);
        if (pGVar6->field20_0xc8[0x2b] == '\0') {
          pcVar9 = pGVar6->field20_0xc8 + 0x2f;
          if (pGVar6->field20_0xc8[0x2c] == '\x01') {
            iVar12 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            iVar15 = FUN_000809e2();
            uVar5 = FUN_00080a3a();
            FUN_00046544(0,pcVar9,0,iVar12 + 100,(uint)uVar4,iVar15 + 0x1dc,uVar5 + 0x88,5,0);
            lVar18 = CONCAT44(DAT_20004b2c,DAT_20004b28);
          }
          else {
            iVar12 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            uVar13 = (uint)uVar4;
            iVar8 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            uVar11 = 5;
            iVar8 = iVar8 + 0x1dc;
            iVar12 = iVar12 + 100;
LAB_0003dce8:
            gui_utf_draw(0,pcVar9,0,iVar12,uVar13,iVar8,uVar4 + 0x88,uVar11,0,0,(undefined *)0x0,0);
            lVar18 = CONCAT44(DAT_20004b2c,DAT_20004b28);
          }
        }
      }
      else {
        lVar18 = CONCAT44(DAT_20004b2c,DAT_20004b28);
        if ((cVar3 == '\n') && (lVar18 = CONCAT44(DAT_20004b2c,DAT_20004b28), DAT_2001c4e7 == '\0'))
        {
          DAT_2001c4e7 = '\x01';
          gui_screen_clear();
          lVar18 = FUN_0008078e();
          DAT_20004b2c = (int)((ulonglong)lVar18 >> 0x20);
          DAT_20004b28 = (uint)lVar18;
          if (pGVar6->field20_0xc8[0x2b] == '\x01') {
            pcVar9 = get_string(0x60);
            iVar12 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            iVar15 = FUN_000809e2();
            uVar5 = FUN_00080a3a();
            gui_utf_draw_middle(0,pcVar9,0,iVar12,uVar4 + 0x36,iVar15 + 0x240,uVar5 + 0x88,3,0,0,
                                (undefined *)0x0,0);
            lVar18 = CONCAT44(DAT_20004b2c,DAT_20004b28);
          }
          else if (pGVar6->field20_0xc8[0x2b] == '\x02') {
            if (bVar2 == 6) {
              iVar12 = 0xc6;
            }
            else if (bVar2 == 5) {
              iVar12 = 0xcc;
            }
            else if (bVar2 == 7) {
              iVar12 = 0xd6;
            }
            else if (bVar2 == 0xe) {
              iVar12 = 0xd0;
            }
            else {
              iVar12 = 0xcc;
            }
            iVar15 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            gui_bmp_bitmap_draw(0x4a,iVar15 + iVar12,uVar4 + 0x3a,0,0,0);
            pcVar9 = get_string(0x52);
            iVar15 = FUN_000809e2();
            uVar5 = FUN_00080a3a();
            iVar8 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            uVar11 = 1;
            iVar8 = iVar8 + 0x240;
            uVar13 = uVar5 + 0x36;
            iVar12 = iVar15 + iVar12 + 0x2c;
            goto LAB_0003dce8;
          }
        }
      }
    }
    else if (1 < param_3) goto LAB_0003de14;
    DAT_20004b2c = (int)((ulonglong)lVar18 >> 0x20);
    DAT_20004b28 = (uint)lVar18;
    if (1 < (byte)pGVar6->field20_0xc8[0x2a] - 7) {
      if (DAT_2001c4e7 == '\0') goto LAB_0003da02;
LAB_0003dc7e:
      DAT_20004b2c = (int)((ulonglong)lVar18 >> 0x20);
      DAT_20004b28 = (uint)lVar18;
      iVar15 = (int)((ulonglong)(lVar18 + 3999) >> 0x20);
      uVar17 = FUN_0008078e();
      iVar12 = (int)((ulonglong)uVar17 >> 0x20);
      bVar16 = (uint)(lVar18 + 3999) < (uint)uVar17;
      if ((int)((iVar15 - iVar12) - (uint)bVar16) < 0 !=
          (SBORROW4(iVar15,iVar12) != SBORROW4(iVar15 - iVar12,(uint)bVar16))) {
        pGVar6 = __get_dashboard_state();
        *(undefined1 *)(*(int *)&pGVar6->field_0x1034 + 1) = 0;
      }
      goto LAB_0003de1e;
    }
    iVar12 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    gui_bmp_dynamic_bitmap_draw(1,iVar12,uVar4 + 0x36);
    lVar18 = CONCAT44(DAT_20004b2c,DAT_20004b28);
    if (DAT_2001c4e7 != '\0') goto LAB_0003dc7e;
    if (param_3 != 2) goto LAB_0003da02;
  }
  else {
LAB_0003de14:
    if (DAT_2001c4e7 != '\0') goto LAB_0003dc7e;
LAB_0003de1e:
    lVar18 = CONCAT44(DAT_20004b2c,DAT_20004b28);
    if (param_3 != 2) {
      if (param_3 == 3) {
        if (2 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): quick note function delay exit ...\n","ui_QuickNote_task");
          }
          else {
            ble_printk("%s(): quick note function delay exit ...\n");
          }
        }
        pGVar6 = __get_dashboard_state();
        if (pGVar6->is_master == true) {
          if (DAT_20004b31 == '\x01') {
            FUN_00030458();
          }
          else {
            FUN_0003d790();
          }
        }
        DAT_20004b24 = FUN_0004c410();
        uVar17 = FUN_0008078e();
        DAT_20004b2c = (int)((ulonglong)uVar17 >> 0x20);
        DAT_20004b28 = (uint)uVar17;
        gui_screen_clear();
        DAT_20004b20 = '\x02';
        DAT_2001c4e7 = '\0';
        FUN_00045444();
        lVar18 = CONCAT44(DAT_20004b2c,DAT_20004b28);
        if (2 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): exec even logo reflash....\n","ui_QuickNote_task");
            lVar18 = CONCAT44(DAT_20004b2c,DAT_20004b28);
          }
          else {
            ble_printk("%s(): exec even logo reflash....\n");
            lVar18 = CONCAT44(DAT_20004b2c,DAT_20004b28);
          }
        }
      }
      goto LAB_0003da02;
    }
  }
  if (2 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): quick note function exit ...\n","ui_QuickNote_task");
    }
    else {
      ble_printk("%s(): quick note function exit ...\n");
    }
  }
  pGVar6 = __get_dashboard_state();
  if (pGVar6->is_master == true) {
    if (DAT_20004b31 == '\x01') {
      FUN_00030458();
    }
    else {
      FUN_0003d790();
    }
  }
  FUN_00045968();
  pGVar6 = __get_dashboard_state();
  *(undefined1 *)(*(int *)&pGVar6->field_0x1034 + 1) = 0;
  memset(&DAT_20004b20,0,0x20);
  lVar18 = CONCAT44(DAT_20004b2c,DAT_20004b28);
  DAT_2001c4e7 = '\0';
LAB_0003da02:
  DAT_20004b2c = (int)((ulonglong)lVar18 >> 0x20);
  DAT_20004b28 = (uint)lVar18;
  return 0;
}


