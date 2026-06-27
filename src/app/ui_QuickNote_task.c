/*
 * Function: ui_QuickNote_task
 * Entry:    0003d7c0
 * Prototype: undefined4 __stdcall ui_QuickNote_task(int param_1, undefined4 param_2, uint param_3)
 */


undefined4 ui_QuickNote_task(int param_1,undefined4 param_2,uint param_3)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  ushort uVar4;
  ushort uVar5;
  GlassesState *pGVar6;
  GlassesState *pGVar7;
  undefined1 *extraout_r0;
  undefined1 *puVar8;
  int iVar9;
  char *pcVar10;
  int iVar11;
  undefined1 *extraout_r0_00;
  undefined4 uVar12;
  undefined4 extraout_r0_01;
  undefined4 extraout_r0_02;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  undefined4 extraout_r1_02;
  undefined4 extraout_r1_03;
  undefined4 extraout_r1_04;
  undefined4 extraout_r1_05;
  undefined4 extraout_r1_06;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 extraout_r2_02;
  undefined4 extraout_r2_03;
  undefined4 uVar13;
  undefined4 extraout_r2_04;
  undefined4 extraout_r2_05;
  undefined4 extraout_r2_06;
  undefined4 extraout_r2_07;
  undefined4 extraout_r2_08;
  undefined4 extraout_r2_09;
  undefined4 extraout_r2_10;
  undefined4 extraout_r2_11;
  undefined4 extraout_r2_12;
  undefined4 extraout_r2_13;
  undefined4 extraout_r2_14;
  undefined4 extraout_r2_15;
  int extraout_r2_16;
  int extraout_r2_17;
  uint uVar14;
  int iVar15;
  int *buffer;
  uint uVar16;
  int iVar17;
  bool bVar18;
  undefined8 uVar19;
  longlong lVar20;
  byte local_30 [12];
  
  pGVar6 = __get_dashboard_state();
  bVar2 = get_current_language();
  buffer = (int *)(param_1 + 0x24);
  FUN_000452f0(buffer);
  FUN_0004540c();
  if (DAT_20004b20 != '\x01') {
    if (DAT_20004b20 != '\x02') {
      lVar20 = CONCAT44(DAT_20004b2c,DAT_20004b28);
      if (DAT_20004b20 == '\0') {
        if (2 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): QUICK NOTE INIT.....\n");
          }
          else {
            ble_printk("%s(): QUICK NOTE INIT.....\n","ui_QuickNote_task",extraout_r2,BLE_DEBUG);
          }
        }
        memset(&DAT_20004b20,0,0x20);
        uVar12 = extraout_r2_00;
        if (2 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            pGVar7 = __get_dashboard_state();
            printk("%s(): GLOBAL->quicknote_show_info->enable = %d\n","ui_QuickNote_task",
                   (uint)*(byte *)(*(int *)&pGVar7->field_0x1034 + 1));
            uVar12 = extraout_r2_04;
          }
          else {
            pGVar7 = __get_dashboard_state();
            ble_printk("%s(): GLOBAL->quicknote_show_info->enable = %d\n","ui_QuickNote_task",
                       (uint)*(byte *)(*(int *)&pGVar7->field_0x1034 + 1),
                       *(int *)&pGVar7->field_0x1034);
            uVar12 = extraout_r2_01;
          }
        }
        if (param_3 == 1) {
          pGVar7 = __get_dashboard_state();
          puVar8 = &pGVar7->field_0x1000;
          lVar20 = CONCAT44(DAT_20004b2c,DAT_20004b28);
          if (*(char *)(*(int *)&pGVar7->field_0x1034 + 1) == '\x01') {
            uVar12 = extraout_r1;
            uVar13 = extraout_r2_02;
            if (2 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): quick note function start ...\n");
                puVar8 = extraout_r0_00;
                uVar12 = extraout_r1_01;
                uVar13 = extraout_r2_05;
              }
              else {
                ble_printk("%s(): quick note function start ...\n","ui_QuickNote_task",
                           extraout_r2_02,BLE_DEBUG);
                puVar8 = extraout_r0;
                uVar12 = extraout_r1_00;
                uVar13 = extraout_r2_03;
              }
            }
            gui_screen_clear(puVar8,uVar12,uVar13);
            iVar15 = 0;
            DAT_20004b20 = '\x01';
            DAT_20004b30 = pGVar6->field_0xf2;
            DAT_20004b31 = '\0';
            DAT_2001c4e7 = '\0';
            FUN_00045444();
            FUN_00045428();
            do {
              if (pGVar6->field_0xf2 == '\n') {
                DAT_2001c4e7 = '\x01';
                uVar19 = FUN_0008078e();
                DAT_20004b2c = (int)((ulonglong)uVar19 >> 0x20);
                DAT_20004b28 = (uint)uVar19;
                if (pGVar6->field_0xf3 == '\x02') {
                  if (bVar2 == 6) {
                    iVar17 = 0xc6;
                  }
                  else if (bVar2 == 5) {
                    iVar17 = 0xcc;
                  }
                  else if (bVar2 == 7) {
                    iVar17 = 0xd6;
                  }
                  else if (bVar2 == 0xe) {
                    iVar17 = 0xd0;
                  }
                  else {
                    iVar17 = 0xcc;
                  }
                  iVar9 = FUN_000809e2();
                  uVar4 = FUN_00080a3a();
                  gui_bmp_bitmap_draw(0x4a,iVar9 + iVar17,uVar4 + 0x3a,0,0,0);
                  pcVar10 = get_string(0x52);
                  iVar9 = FUN_000809e2();
                  uVar4 = FUN_00080a3a();
                  iVar11 = FUN_000809e2();
                  uVar5 = FUN_00080a3a();
                  gui_utf_draw(0,pcVar10,0,iVar9 + iVar17 + 0x2c,uVar4 + 0x36,iVar11 + 0x240,
                               uVar5 + 0x88,1,0,0,(undefined *)0x0,0);
                  uVar19 = CONCAT44(DAT_20004b2c,DAT_20004b28);
                }
              }
              else {
                pcVar10 = get_string(0x44);
                iVar17 = FUN_000809e2();
                uVar4 = FUN_00080a3a();
                iVar9 = FUN_000809e2();
                uVar5 = FUN_00080a3a();
                gui_utf_draw_middle(0,pcVar10,0,iVar17,uVar4 + 0x36,iVar9 + 0x240,uVar5 + 0x51,1,0,0
                                    ,(undefined *)0x0,0);
                uVar19 = CONCAT44(DAT_20004b2c,DAT_20004b28);
                if (pGVar6->field_0xf1 == '\0') {
                  pcVar10 = get_string(0x45);
                  iVar17 = FUN_000809e2();
                  uVar4 = FUN_00080a3a();
                  iVar9 = FUN_000809e2();
                  uVar5 = FUN_00080a3a();
                  gui_utf_draw_middle(0,pcVar10,0,iVar17,uVar4 + 0x6c,iVar9 + 0x240,uVar5 + 0x87,1,0
                                      ,0,(undefined *)0x0,0);
                  uVar19 = CONCAT44(DAT_20004b2c,DAT_20004b28);
                }
              }
              uVar16 = 0;
              do {
                iVar17 = 0;
                do {
                  DAT_20004b2c = (int)((ulonglong)uVar19 >> 0x20);
                  DAT_20004b28 = (uint)uVar19;
                  local_30[0] = 1;
                  local_30[1] = 3;
                  local_30[2] = 5;
                  local_30[3] = 7;
                  local_30[4] = 7;
                  local_30[5] = 7;
                  local_30[6] = 7;
                  local_30[7] = 7;
                  bVar1 = *(byte *)(buffer[uVar16] + iVar17);
                  if (bVar1 != 0) {
                    *(byte *)(buffer[uVar16] + iVar17) =
                         bVar1 & (&DAT_000accab)
                                 [iVar17 + (uint)local_30[iVar15] * 0x140 + (uVar16 % 0x1a) * 0xa00]
                    ;
                    uVar19 = CONCAT44(DAT_20004b2c,DAT_20004b28);
                  }
                  DAT_20004b2c = (int)((ulonglong)uVar19 >> 0x20);
                  DAT_20004b28 = (uint)uVar19;
                  iVar17 = iVar17 + 1;
                } while (iVar17 != 0x140);
                uVar16 = uVar16 + 1;
              } while (uVar16 != 199);
              pGVar7 = __get_dashboard_state();
              iVar17 = *(int *)&(pGVar7->jdb_panel_context).field_0x348;
              pGVar7 = __get_dashboard_state();
              iVar15 = iVar15 + 1;
              _reflash_fb_data_to_lcd
                        (iVar17,*(int *)&(pGVar7->jdb_panel_context).field_0x34c,0,0,0x280,199);
            } while (iVar15 != 4);
            FUN_0004540c();
            pGVar6 = __get_dashboard_state();
            lVar20 = CONCAT44(DAT_20004b2c,DAT_20004b28);
            if (*(char *)pGVar6 == '\x01') {
              if (DAT_20004b31 == '\x01') {
                cVar3 = FUN_00030440();
                lVar20 = CONCAT44(DAT_20004b2c,DAT_20004b28);
                if (cVar3 == '\x01') {
                  FUN_0008040c();
                  lVar20 = CONCAT44(DAT_20004b2c,DAT_20004b28);
                }
              }
              else {
                if (DAT_20008558 == 1) {
                  cVar3 = FUN_00030440();
                  lVar20 = CONCAT44(DAT_20004b2c,DAT_20004b28);
                  if (cVar3 != '\x01') goto LAB_0003da02;
                }
                dmic_record_start();
                lVar20 = CONCAT44(DAT_20004b2c,DAT_20004b28);
              }
            }
          }
        }
        else {
          lVar20 = CONCAT44(DAT_20004b2c,DAT_20004b28);
          if (param_3 == 2) {
            if (0 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): quick init,exec function exit ...\n");
              }
              else {
                ble_printk("%s(): quick init,exec function exit ...\n","ui_QuickNote_task",uVar12,
                           BLE_DEBUG);
              }
            }
            pGVar6 = __get_dashboard_state();
            uVar19 = CONCAT44(extraout_r1_02,pGVar6);
            uVar12 = extraout_r2_06;
            if (*(char *)pGVar6 == '\x01') {
              if (DAT_20004b31 == '\x01') {
                uVar12 = FUN_00030458();
                uVar19 = CONCAT44(extraout_r1_03,uVar12);
                uVar12 = extraout_r2_07;
              }
              else {
                uVar19 = FUN_0003d790();
                uVar12 = extraout_r2_08;
              }
            }
            gui_screen_clear((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),uVar12);
            pGVar6 = __get_dashboard_state();
            *(undefined1 *)(*(int *)&pGVar6->field_0x1034 + 1) = 0;
            memset(&DAT_20004b20,0,0x20);
            DAT_2001c4e7 = '\0';
            lVar20 = CONCAT44(DAT_20004b2c,DAT_20004b28);
          }
        }
      }
      goto LAB_0003da02;
    }
    if (LOG_LEVEL < 3) {
      if (param_3 != 2) goto LAB_0003e0a4;
LAB_0003df4c:
      pGVar6 = __get_dashboard_state();
      if (*(char *)pGVar6 == '\x01') {
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
        printk("%s(): quick note process exec.....\n");
        uVar12 = extraout_r2_15;
      }
      else {
        ble_printk("%s(): quick note process exec.....\n","ui_QuickNote_task",extraout_r2,BLE_DEBUG)
        ;
        uVar12 = extraout_r2_14;
      }
      if (param_3 == 2) {
        if (2 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): quick note function exit ...\n");
          }
          else {
            ble_printk("%s(): quick note function exit ...\n","ui_QuickNote_task",uVar12,BLE_DEBUG);
          }
        }
        goto LAB_0003df4c;
      }
LAB_0003e0a4:
      uVar19 = FUN_0008078e();
      lVar20 = CONCAT44(DAT_20004b2c,DAT_20004b28);
      iVar15 = (int)((ulonglong)uVar19 >> 0x20);
      uVar16 = (uint)uVar19;
      uVar14 = DAT_20004b24 + DAT_20004b28;
      iVar17 = DAT_20004b2c + ((int)DAT_20004b24 >> 0x1f) + (uint)CARRY4(DAT_20004b24,DAT_20004b28);
      if ((int)((iVar17 - iVar15) - (uint)(uVar14 < uVar16)) < 0 ==
          (SBORROW4(iVar17,iVar15) != SBORROW4(iVar17 - iVar15,(uint)(uVar14 < uVar16)))) {
        iVar9 = (iVar17 - ((int)DAT_200024ec >> 0x1f)) - (uint)(uVar14 < DAT_200024ec);
        bVar18 = uVar14 - DAT_200024ec < uVar16;
        iVar17 = (iVar9 - iVar15) - (uint)bVar18;
        if (iVar17 < 0 == (SBORROW4(iVar9,iVar15) != SBORROW4(iVar9 - iVar15,(uint)bVar18))) {
          if (DAT_2001c4e7 == '\0') {
            iVar15 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            gui_bmp_dynamic_bitmap_draw(9,iVar15,uVar4 + 0x36);
            iVar15 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            iVar17 = FUN_000809e2();
            uVar5 = FUN_00080a3a();
            gui_utf_draw_darkword_by_lines
                      (0,&pGVar6->field_0xf7,0,iVar15 + 100,(uint)uVar4,iVar17 + 0x1dc,uVar5 + 0x88,
                       5,5,0,(undefined *)0x0,0);
            lVar20 = CONCAT44(DAT_20004b2c,DAT_20004b28);
          }
        }
        else {
          lVar20 = CONCAT44(DAT_20004b2c,DAT_20004b28);
          if (DAT_2001c4e7 == '\0') {
            if (2 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): exec quick note exit display...\n");
                uVar19 = CONCAT44(extraout_r1_06,extraout_r0_02);
                iVar17 = extraout_r2_17;
              }
              else {
                ble_printk("%s(): exec quick note exit display...\n","ui_QuickNote_task",iVar17,
                           BLE_DEBUG);
                uVar19 = CONCAT44(extraout_r1_05,extraout_r0_01);
                iVar17 = extraout_r2_16;
              }
            }
            gui_screen_clear((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),iVar17);
            iVar15 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            gui_bmp_bitmap_draw(0x3b,iVar15,uVar4 + 0x36,0,0,0);
            pcVar10 = get_string(0x46);
            iVar15 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            iVar17 = FUN_000809e2();
            uVar5 = FUN_00080a3a();
            gui_utf_draw_middle(0,pcVar10,0,iVar15 + 0x24,uVar4 + 0x36,iVar17 + 0x21c,uVar5 + 0x6c,2
                                ,0,0,(undefined *)0x0,0);
            lVar20 = CONCAT44(DAT_20004b2c,DAT_20004b28);
            DAT_2001c4e7 = '\x01';
          }
        }
        goto LAB_0003da02;
      }
      if (2 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): quick note function exit -164 ...\n");
        }
        else {
          ble_printk("%s(): quick note function exit -164 ...\n","ui_QuickNote_task",iVar17,
                     BLE_DEBUG);
        }
      }
    }
    FUN_00045968();
    pGVar6 = __get_dashboard_state();
    *(undefined1 *)(*(int *)&pGVar6->field_0x1034 + 1) = 0;
    memset(&DAT_20004b20,0,0x20);
    DAT_2001c4e7 = '\0';
    lVar20 = CONCAT44(DAT_20004b2c,DAT_20004b28);
    goto LAB_0003da02;
  }
  if (2 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): QUICK NOTE RUNING.....\n");
    }
    else {
      ble_printk("%s(): QUICK NOTE RUNING.....\n","ui_QuickNote_task",extraout_r2,BLE_DEBUG);
    }
  }
  pGVar7 = __get_dashboard_state();
  lVar20 = CONCAT44(DAT_20004b2c,DAT_20004b28);
  if (*(char *)(*(int *)&pGVar7->field_0x1034 + 1) == '\x01') {
    if (param_3 == 1) {
      cVar3 = pGVar6->field_0xf2;
      if (cVar3 == '\b') {
        if (DAT_20004b30 != '\b') {
          DAT_20004b30 = cVar3;
          iVar15 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          iVar17 = FUN_000809e2();
          uVar5 = FUN_00080a3a();
          _clean_fb_data(buffer,0,iVar15 + 0x14,(uint)uVar4,iVar17 + 0x240,uVar5 + 0x88);
        }
        lVar20 = CONCAT44(DAT_20004b2c,DAT_20004b28);
        if (pGVar6->field_0xf3 == '\0') {
          pcVar10 = &pGVar6->field_0xf7;
          if (pGVar6->field_0xf4 == '\x01') {
            iVar15 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            iVar17 = FUN_000809e2();
            uVar5 = FUN_00080a3a();
            FUN_00046544(0,pcVar10,0,iVar15 + 100,(uint)uVar4,iVar17 + 0x1dc,uVar5 + 0x88,5,0);
            lVar20 = CONCAT44(DAT_20004b2c,DAT_20004b28);
          }
          else {
            iVar15 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            uVar16 = (uint)uVar4;
            iVar9 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            uVar14 = 5;
            iVar9 = iVar9 + 0x1dc;
            iVar15 = iVar15 + 100;
LAB_0003dce8:
            gui_utf_draw(0,pcVar10,0,iVar15,uVar16,iVar9,uVar4 + 0x88,uVar14,0,0,(undefined *)0x0,0)
            ;
            lVar20 = CONCAT44(DAT_20004b2c,DAT_20004b28);
          }
        }
      }
      else {
        lVar20 = CONCAT44(DAT_20004b2c,DAT_20004b28);
        if ((cVar3 == '\n') && (lVar20 = CONCAT44(DAT_20004b2c,DAT_20004b28), DAT_2001c4e7 == '\0'))
        {
          DAT_2001c4e7 = '\x01';
          gui_screen_clear(&pGVar7->field_0x1000,extraout_r1_04,extraout_r2_09);
          lVar20 = FUN_0008078e();
          DAT_20004b2c = (int)((ulonglong)lVar20 >> 0x20);
          DAT_20004b28 = (uint)lVar20;
          if (pGVar6->field_0xf3 == '\x01') {
            pcVar10 = get_string(0x60);
            iVar15 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            iVar17 = FUN_000809e2();
            uVar5 = FUN_00080a3a();
            gui_utf_draw_middle(0,pcVar10,0,iVar15,uVar4 + 0x36,iVar17 + 0x240,uVar5 + 0x88,3,0,0,
                                (undefined *)0x0,0);
            lVar20 = CONCAT44(DAT_20004b2c,DAT_20004b28);
          }
          else if (pGVar6->field_0xf3 == '\x02') {
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
            iVar17 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            gui_bmp_bitmap_draw(0x4a,iVar17 + iVar15,uVar4 + 0x3a,0,0,0);
            pcVar10 = get_string(0x52);
            iVar17 = FUN_000809e2();
            uVar5 = FUN_00080a3a();
            iVar9 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            uVar14 = 1;
            iVar9 = iVar9 + 0x240;
            uVar16 = uVar5 + 0x36;
            iVar15 = iVar17 + iVar15 + 0x2c;
            goto LAB_0003dce8;
          }
        }
      }
    }
    else if (1 < param_3) goto LAB_0003de14;
    DAT_20004b2c = (int)((ulonglong)lVar20 >> 0x20);
    DAT_20004b28 = (uint)lVar20;
    if (1 < (byte)pGVar6->field_0xf2 - 7) {
      if (DAT_2001c4e7 == '\0') goto LAB_0003da02;
LAB_0003dc7e:
      DAT_20004b2c = (int)((ulonglong)lVar20 >> 0x20);
      DAT_20004b28 = (uint)lVar20;
      iVar17 = (int)((ulonglong)(lVar20 + 3999) >> 0x20);
      uVar19 = FUN_0008078e();
      iVar15 = (int)((ulonglong)uVar19 >> 0x20);
      bVar18 = (uint)(lVar20 + 3999) < (uint)uVar19;
      uVar12 = extraout_r2_11;
      if ((int)((iVar17 - iVar15) - (uint)bVar18) < 0 !=
          (SBORROW4(iVar17,iVar15) != SBORROW4(iVar17 - iVar15,(uint)bVar18))) {
        pGVar6 = __get_dashboard_state();
        uVar12 = 0;
        *(undefined1 *)(*(int *)&pGVar6->field_0x1034 + 1) = 0;
      }
      goto LAB_0003de1e;
    }
    iVar15 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    gui_bmp_dynamic_bitmap_draw(1,iVar15,uVar4 + 0x36);
    lVar20 = CONCAT44(DAT_20004b2c,DAT_20004b28);
    if (DAT_2001c4e7 != '\0') goto LAB_0003dc7e;
    uVar12 = extraout_r2_10;
    if (param_3 != 2) goto LAB_0003da02;
  }
  else {
LAB_0003de14:
    uVar12 = extraout_r2_09;
    if (DAT_2001c4e7 != '\0') goto LAB_0003dc7e;
LAB_0003de1e:
    lVar20 = CONCAT44(DAT_20004b2c,DAT_20004b28);
    if (param_3 != 2) {
      if (param_3 == 3) {
        if (2 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): quick note function delay exit ...\n");
          }
          else {
            ble_printk("%s(): quick note function delay exit ...\n","ui_QuickNote_task",uVar12,
                       BLE_DEBUG);
          }
        }
        pGVar6 = __get_dashboard_state();
        if (*(char *)pGVar6 == '\x01') {
          if (DAT_20004b31 == '\x01') {
            FUN_00030458();
          }
          else {
            FUN_0003d790();
          }
        }
        DAT_20004b24 = FUN_0004c410();
        uVar19 = FUN_0008078e();
        DAT_20004b2c = (int)((ulonglong)uVar19 >> 0x20);
        DAT_20004b28 = (uint)uVar19;
        gui_screen_clear(DAT_20004b28,DAT_20004b2c,extraout_r2_12);
        DAT_20004b20 = '\x02';
        DAT_2001c4e7 = '\0';
        FUN_00045444();
        lVar20 = CONCAT44(DAT_20004b2c,DAT_20004b28);
        if (2 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): exec even logo reflash....\n");
            lVar20 = CONCAT44(DAT_20004b2c,DAT_20004b28);
          }
          else {
            ble_printk("%s(): exec even logo reflash....\n","ui_QuickNote_task",extraout_r2_13,
                       BLE_DEBUG);
            lVar20 = CONCAT44(DAT_20004b2c,DAT_20004b28);
          }
        }
      }
      goto LAB_0003da02;
    }
  }
  if (2 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): quick note function exit ...\n");
    }
    else {
      ble_printk("%s(): quick note function exit ...\n","ui_QuickNote_task",uVar12,BLE_DEBUG);
    }
  }
  pGVar6 = __get_dashboard_state();
  if (*(char *)pGVar6 == '\x01') {
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
  lVar20 = CONCAT44(DAT_20004b2c,DAT_20004b28);
  DAT_2001c4e7 = '\0';
LAB_0003da02:
  DAT_20004b2c = (int)((ulonglong)lVar20 >> 0x20);
  DAT_20004b28 = (uint)lVar20;
  return 0;
}


