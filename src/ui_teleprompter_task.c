/*
 * Function: ui_teleprompter_task
 * Entry:    0003f24c
 * Prototype: undefined4 __stdcall ui_teleprompter_task(int param_1, undefined4 param_2, int param_3)
 */


undefined4 ui_teleprompter_task(int param_1,undefined4 param_2,int param_3)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  GlassesState *pGVar7;
  undefined4 uVar8;
  undefined4 extraout_r0;
  undefined4 extraout_r0_00;
  GlassesState *extraout_r0_01;
  GlassesState *extraout_r0_02;
  GlassesState *extraout_r0_03;
  GlassesState *pGVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  GlassesState *extraout_r0_04;
  int iVar13;
  char *pcVar14;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 uVar15;
  undefined4 extraout_r1_01;
  undefined4 extraout_r1_02;
  undefined4 extraout_r1_03;
  undefined4 extraout_r1_04;
  undefined4 extraout_r1_05;
  undefined4 extraout_r1_06;
  undefined4 extraout_r1_07;
  undefined4 extraout_r1_08;
  undefined4 extraout_r1_09;
  undefined4 extraout_r1_10;
  undefined4 extraout_r1_11;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 uVar16;
  undefined4 extraout_r2_01;
  undefined4 extraout_r2_02;
  undefined4 extraout_r2_03;
  undefined4 extraout_r2_04;
  undefined4 extraout_r2_05;
  undefined4 extraout_r2_06;
  undefined4 extraout_r2_07;
  undefined4 extraout_r2_08;
  undefined4 extraout_r2_09;
  undefined4 extraout_r2_10;
  int extraout_r2_11;
  int extraout_r2_12;
  int extraout_r2_13;
  undefined4 extraout_r2_14;
  undefined4 extraout_r2_15;
  undefined4 extraout_r2_16;
  undefined4 extraout_r2_17;
  undefined4 extraout_r2_18;
  undefined4 extraout_r2_19;
  undefined4 extraout_r2_20;
  undefined4 extraout_r2_21;
  undefined4 extraout_r2_22;
  undefined4 extraout_r2_23;
  undefined4 extraout_r2_24;
  undefined4 extraout_r2_25;
  undefined4 extraout_r2_26;
  int iVar17;
  int extraout_r3;
  int extraout_r3_00;
  int iVar18;
  bool bVar19;
  k_timeout_t timeout;
  k_timeout_t timeout_00;
  longlong lVar20;
  undefined8 uVar21;
  undefined8 uVar22;
  uint uVar23;
  undefined2 local_6c [2];
  undefined4 local_68;
  undefined4 auStack_64 [16];
  
  pGVar7 = __get_dashboard_state();
  iVar17 = param_1 + 0x24;
  FUN_000452f0(iVar17);
  uVar8 = FUN_0004540c();
  uVar22 = CONCAT44(DAT_20004b4c,DAT_20004b48);
  uVar15 = extraout_r1;
  uVar16 = extraout_r2;
  switch(DAT_20004b40) {
  case 0:
    if (LOG_LEVEL < 3) {
      if (param_3 != 2) goto LAB_0003f2f8;
    }
    else {
      if (BLE_DEBUG == 0) {
        printk("%s(): running  TELEPROMPTER_DISPLAY_IDLE STATUS.\n");
        uVar8 = extraout_r0_00;
        uVar15 = extraout_r1_01;
        uVar16 = extraout_r2_01;
      }
      else {
        ble_printk("%s(): running  TELEPROMPTER_DISPLAY_IDLE STATUS.\n","ui_teleprompter_task",
                   extraout_r2,BLE_DEBUG);
        uVar8 = extraout_r0;
        uVar15 = extraout_r1_00;
        uVar16 = extraout_r2_00;
      }
      if (param_3 != 2) {
        if (2 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            pGVar9 = __get_dashboard_state();
            printk("%s(): GLOBAL->temeprompter_info->enable = %d\n","ui_teleprompter_task",
                   (uint)*(byte *)(*(int *)&pGVar9->field_0x1000 + 1));
          }
          else {
            pGVar9 = __get_dashboard_state();
            ble_printk("%s(): GLOBAL->temeprompter_info->enable = %d\n","ui_teleprompter_task",
                       (uint)*(byte *)(*(int *)&pGVar9->field_0x1000 + 1),
                       *(int *)&pGVar9->field_0x1000);
          }
        }
LAB_0003f2f8:
        uVar22 = CONCAT44(DAT_20004b4c,DAT_20004b48);
        if (param_3 == 1) {
          pGVar9 = __get_dashboard_state();
          uVar22 = CONCAT44(DAT_20004b4c,DAT_20004b48);
          if ((*(char *)(*(int *)&pGVar9->field_0x1000 + 1) == '\x01') &&
             (uVar22 = CONCAT44(DAT_20004b4c,DAT_20004b48), pGVar7->field_0xf0 == '\x01')) {
            if (2 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): setp1: received teleprompter command.\n");
              }
              else {
                ble_printk("%s(): setp1: received teleprompter command.\n","ui_teleprompter_task",
                           extraout_r2_02,BLE_DEBUG);
              }
            }
            pGVar9 = __get_dashboard_state();
            uVar8 = extraout_r1_02;
            uVar15 = extraout_r2_03;
            if (*(char *)pGVar9 == '\x01') {
              pGVar9 = (GlassesState *)
                       send_response_data_to_ble(pGVar9,extraout_r1_02,extraout_r2_03,1);
              uVar8 = extraout_r1_03;
              uVar15 = extraout_r2_04;
            }
            if (2 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): received teleprompter counter down timer start event..\n");
                pGVar9 = extraout_r0_02;
                uVar8 = extraout_r1_06;
                uVar15 = extraout_r2_06;
              }
              else {
                ble_printk("%s(): received teleprompter counter down timer start event..\n",
                           "ui_teleprompter_task",uVar15,BLE_DEBUG);
                pGVar9 = extraout_r0_01;
                uVar8 = extraout_r1_04;
                uVar15 = extraout_r2_05;
              }
            }
            gui_screen_clear(pGVar9,uVar8,uVar15);
            memset(&DAT_20004b40,0,0x230);
            DAT_20004b40 = 1;
            uVar22 = FUN_00080894();
            DAT_20004b4c = (int)((ulonglong)uVar22 >> 0x20);
            DAT_20004b48 = (uint)uVar22;
            uVar22 = FUN_00080894();
            DAT_20004b54 = (undefined4)((ulonglong)uVar22 >> 0x20);
            DAT_20004b50 = (int)uVar22;
            DAT_20004b58 = 0;
            DAT_20004b41 = '\n';
            DAT_20004b65 = pGVar7->field_0xfb;
            DAT_2000a9d0 = 0;
            DAT_2000a9cc = 0;
            DAT_2000a9c8 = 0;
            DAT_2000a9c4 = 0;
            DAT_2000a9c0 = 0;
            DAT_2000a9bc = 0;
            memset(&DAT_20004b70,0,0x200);
            timeout.ticks._4_4_ = 0xffffffff;
            timeout.ticks._0_4_ = extraout_r1_05;
            z_impl_k_mutex_lock(&k_mutex_2000851c,timeout);
            memcpy(&DAT_20004b70,&pGVar7->field_0x106,0x200);
            bVar3 = pGVar7->field_0xfc;
            uVar4 = *(ushort *)&pGVar7->field_0xfd;
            DAT_20004b64 = pGVar7->field_0xef;
            DAT_20004b65 = pGVar7->field_0xfb;
            z_impl_k_mutex_unlock(&k_mutex_2000851c);
            uVar22 = FUN_00080894();
            uVar10 = (char)pGVar7->field_0xfb * 1000;
            uVar23 = uVar10 + (uint)uVar22;
            DAT_20004b68 = uVar23 - 0x15e;
            DAT_20004b6c = (int)((ulonglong)uVar22 >> 0x20) +
                           ((int)uVar10 >> 0x1f) + (uint)CARRY4(uVar10,(uint)uVar22) + -1 +
                           (uint)(0x15d < uVar23);
            if (2 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): teleprompter work mode = %d\n");
              }
              else {
                ble_printk("%s(): teleprompter work mode = %d\n","ui_teleprompter_task",
                           (uint)DAT_20004b64,BLE_DEBUG);
              }
            }
            FUN_00045428();
            iVar11 = 0;
            do {
              iVar12 = FUN_000809e2();
              uVar5 = FUN_00080a3a();
              iVar13 = FUN_000809e2();
              uVar6 = FUN_00080a3a();
              uVar10 = 0;
              gui_utf_draw(0,&DAT_20004b70,0,iVar12 + 0x58,uVar5 + 1,iVar13 + 0x230,uVar6 + 0x88,5,
                           (uint)uVar4,0,(undefined *)0x0,0);
              pGVar7 = __get_dashboard_state();
              cVar1 = pGVar7->glasses_state_struct_0FF0->field_0x5e;
              uVar23 = FUN_00080732();
              iVar12 = FUN_000809e2();
              uVar5 = FUN_00080a3a();
              iVar13 = FUN_000809e2();
              uVar6 = FUN_00080a3a();
              gui_clock_draw(uVar23,iVar12,uVar5 + 2,iVar13 + 0x3f,uVar6 + 0x1d,3,cVar1 != '\x01');
              iVar12 = FUN_000809e2();
              uVar5 = FUN_00080a3a();
              iVar13 = FUN_000809e2();
              uVar6 = FUN_00080a3a();
              gui_verticalLine_process_bar
                        (iVar12 + 0x23c,(uint)uVar5,iVar13 + 0x23c,uVar6 + 0x88,1,bVar3);
              iVar12 = FUN_000809e2();
              uVar5 = FUN_00080a3a();
              gui_bmp_bitmap_draw(0x18,iVar12,uVar5 + 0x36,0,0,0);
              do {
                iVar12 = 0;
                do {
                  local_68 = 0x7050301;
                  auStack_64[0] = 0x7070707;
                  iVar13 = *(int *)(iVar17 + uVar10 * 4);
                  bVar2 = *(byte *)(iVar13 + iVar12);
                  if (bVar2 != 0) {
                    *(byte *)(iVar13 + iVar12) =
                         bVar2 & (&DAT_000accab)
                                 [iVar12 + (uint)*(byte *)((int)auStack_64 + iVar11 + -4) * 0x140 +
                                           (uVar10 % 0x1a) * 0xa00];
                  }
                  iVar12 = iVar12 + 1;
                } while (iVar12 != 0x140);
                uVar10 = uVar10 + 1;
              } while (uVar10 != 199);
              pGVar7 = __get_dashboard_state();
              iVar12 = *(int *)&pGVar7->field_0xeb4;
              pGVar7 = __get_dashboard_state();
              iVar11 = iVar11 + 1;
              _reflash_fb_data_to_lcd(iVar12,*(int *)&pGVar7->field_0xeb8,0,0,0x280,199);
            } while (iVar11 != 4);
            FUN_0004540c();
            z_impl_k_sleep((k_timeout_t)0x1334);
            FUN_00045444();
            uVar22 = CONCAT44(DAT_20004b4c,DAT_20004b48);
          }
        }
        goto switchD_0003f274_default;
      }
    }
LAB_0003f2a0:
    gui_screen_clear(uVar8,uVar15,uVar16);
    memset(&DAT_20004b40,0,0x230);
    uVar22 = CONCAT44(DAT_20004b4c,DAT_20004b48);
    goto switchD_0003f274_default;
  case 1:
    if (param_3 == 2) goto LAB_0003f2a0;
    if (param_3 == 1) {
      if (2 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): counter down break,received sync message...\n");
        }
        else {
          ble_printk("%s(): counter down break,received sync message...\n","ui_teleprompter_task",
                     extraout_r2,BLE_DEBUG);
        }
      }
      if ((byte)pGVar7->field_0xf9 - 2 < 2) {
        uVar22 = FUN_00080894();
        DAT_20004b4c = (int)((ulonglong)uVar22 >> 0x20);
        DAT_20004b48 = (uint)uVar22;
        DAT_20004b40 = 2;
        uVar22 = FUN_00080894();
        DAT_20004b54 = (undefined4)((ulonglong)uVar22 >> 0x20);
        DAT_20004b50 = (int)uVar22;
        iVar11 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        iVar12 = FUN_000809e2();
        uVar5 = FUN_00080a3a();
        _clean_fb_data(iVar17,0,iVar11,uVar4 + 0x36,iVar12 + 0x24,uVar5 + 0x52);
        if (DAT_20004b64 == 1) {
          iVar17 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          uVar23 = 0x1a;
        }
        else {
          if (DAT_20004b64 != 0) goto LAB_0003f6a0;
          iVar17 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          uVar23 = 0x19;
        }
        gui_bmp_bitmap_draw(uVar23,iVar17,uVar4 + 0x36,0,0,0);
      }
LAB_0003f6a0:
      pGVar7 = __get_dashboard_state();
      uVar22 = CONCAT44(DAT_20004b4c,DAT_20004b48);
      if (*(char *)pGVar7 == '\x01') {
        send_response_data_to_ble(pGVar7,extraout_r1_07,extraout_r2_07,1);
        uVar22 = CONCAT44(DAT_20004b4c,DAT_20004b48);
      }
      goto switchD_0003f274_default;
    }
    uVar22 = CONCAT44(DAT_20004b4c,DAT_20004b48);
    if (param_3 != 0) goto switchD_0003f274_default;
    if (2 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): na sync arar reflash,update counter down timer\n");
      }
      else {
        ble_printk("%s(): na sync arar reflash,update counter down timer\n","ui_teleprompter_task",
                   extraout_r2,BLE_DEBUG);
      }
    }
    uVar22 = FUN_00080894();
    iVar11 = (int)((ulonglong)uVar22 >> 0x20);
    uVar23 = (uint)uVar22;
    if ((int)((iVar11 - DAT_20004b6c) - (uint)(uVar23 < DAT_20004b68)) < 0 ==
        (SBORROW4(iVar11,DAT_20004b6c) !=
        SBORROW4(iVar11 - DAT_20004b6c,(uint)(uVar23 < DAT_20004b68)))) {
      if (2 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): counter down timeout . exit counter down status ,switch TEXT DISPLAY \n");
        }
        else {
          ble_printk("%s(): counter down timeout . exit counter down status ,switch TEXT DISPLAY \n"
                     ,"ui_teleprompter_task",DAT_20004b68,BLE_DEBUG);
        }
      }
      uVar22 = FUN_00080894();
      DAT_20004b54 = (undefined4)((ulonglong)uVar22 >> 0x20);
      DAT_20004b50 = (int)uVar22;
      DAT_20004b40 = 2;
      uVar22 = FUN_00080894();
      DAT_20004b4c = (int)((ulonglong)uVar22 >> 0x20);
      DAT_20004b48 = (uint)uVar22;
      iVar11 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      iVar12 = FUN_000809e2();
      uVar5 = FUN_00080a3a();
      _clean_fb_data(iVar17,0,iVar11,uVar4 + 0x36,iVar12 + 0x1e,uVar5 + 0x50);
      pGVar7 = __get_dashboard_state();
      iVar13 = *(int *)&pGVar7->field_0xeb4;
      pGVar7 = __get_dashboard_state();
      iVar18 = *(int *)&pGVar7->field_0xeb8;
      iVar17 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      iVar11 = FUN_000809e2();
      uVar5 = FUN_00080a3a();
      iVar12 = uVar5 + 0x50;
      iVar11 = iVar11 + 0x1e;
LAB_0003f7c6:
      _reflash_fb_data_to_lcd(iVar13,iVar18,iVar17,uVar4 + 0x36,iVar11,iVar12);
      if (DAT_20004b64 == 1) {
        iVar17 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        uVar23 = 0x1a;
      }
      else {
        uVar22 = CONCAT44(DAT_20004b4c,DAT_20004b48);
        if (DAT_20004b64 != 0) goto switchD_0003f274_default;
        iVar17 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        uVar23 = 0x19;
      }
      gui_bmp_bitmap_draw(uVar23,iVar17,uVar4 + 0x36,0,0,0);
      uVar22 = CONCAT44(DAT_20004b4c,DAT_20004b48);
      goto switchD_0003f274_default;
    }
    lVar20 = __aeabi_ldivmod(DAT_20004b68 - uVar23,
                             (DAT_20004b6c - iVar11) - (uint)(DAT_20004b68 < uVar23),1000,0);
    iVar11 = (int)((ulonglong)lVar20 >> 0x20);
    bVar19 = (uint)(int)(char)DAT_20004b65 < (uint)lVar20;
    iVar12 = (int)((uint)DAT_20004b65 << 0x18) >> 0x1f;
    if ((int)((iVar12 - iVar11) - (uint)bVar19) < 0 !=
        (SBORROW4(iVar12,iVar11) != SBORROW4(iVar12 - iVar11,(uint)bVar19))) {
      lVar20 = CONCAT44((int)((uint)DAT_20004b65 << 0x18) >> 0x1f,(int)(char)DAT_20004b65);
    }
    if (lVar20 == 0) {
      if (2 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): remain time end ,switch text display ...\n");
        }
        else {
          ble_printk("%s(): remain time end ,switch text display ...\n","ui_teleprompter_task",0,
                     BLE_DEBUG);
        }
      }
      uVar22 = FUN_00080894();
      DAT_20004b54 = (undefined4)((ulonglong)uVar22 >> 0x20);
      DAT_20004b50 = (int)uVar22;
      uVar22 = FUN_00080894();
      DAT_20004b4c = (int)((ulonglong)uVar22 >> 0x20);
      DAT_20004b48 = (uint)uVar22;
      DAT_20004b40 = 2;
      iVar11 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      iVar12 = FUN_000809e2();
      uVar5 = FUN_00080a3a();
      _clean_fb_data(iVar17,0,iVar11,uVar4 + 0x36,iVar12 + 0x24,uVar5 + 0x52);
      pGVar7 = __get_dashboard_state();
      iVar13 = *(int *)&pGVar7->field_0xeb4;
      pGVar7 = __get_dashboard_state();
      iVar18 = *(int *)&pGVar7->field_0xeb8;
      iVar17 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      iVar11 = FUN_000809e2();
      uVar5 = FUN_00080a3a();
      iVar12 = uVar5 + 0x52;
      iVar11 = iVar11 + 0x24;
      goto LAB_0003f7c6;
    }
    local_68 = (uint)local_68._3_1_ << 0x18;
    snprintf((char *)&local_68,3,"%d",(int)lVar20);
    if (2 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): upgrade counterdown timer = %s\n");
      }
      else {
        ble_printk("%s(): upgrade counterdown timer = %s\n","ui_teleprompter_task",&local_68,
                   BLE_DEBUG);
      }
    }
    iVar17 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    iVar11 = FUN_000809e2();
    uVar5 = FUN_00080a3a();
    iVar12 = uVar5 + 0x50;
    iVar11 = iVar11 + 0x1e;
    iVar13 = uVar4 + 0x36;
    pcVar14 = (char *)&local_68;
    break;
  case 2:
    if (LOG_LEVEL < 3) {
      if (param_3 == 2) goto LAB_0003f98a;
    }
    else {
      if (BLE_DEBUG == 0) {
        printk("%s(): running TELEPROMPTER_TEXT_DISPLAY STATUS.\n");
        uVar8 = extraout_r2_09;
      }
      else {
        ble_printk("%s(): running TELEPROMPTER_TEXT_DISPLAY STATUS.\n","ui_teleprompter_task",
                   extraout_r2,BLE_DEBUG);
        uVar8 = extraout_r2_08;
      }
      if (param_3 == 2) goto joined_r0x0003ffd8;
    }
    bVar3 = DAT_20004b5d;
    if (DAT_20004b5d == 1) {
      uVar23 = DAT_20004b58;
      if (DAT_20004b5c == 0) {
        uVar22 = FUN_00080894();
        DAT_20004b58 = (DAT_20004b58 - DAT_20004b50) + (int)uVar22;
        DAT_20004b5c = bVar3;
        uVar23 = DAT_20004b58;
      }
    }
    else if (DAT_20004b5c == 0) {
      uVar22 = FUN_00080894();
      uVar23 = ((int)uVar22 - DAT_20004b50) + DAT_20004b58;
    }
    else {
      uVar22 = FUN_00080894();
      DAT_20004b50 = (int)uVar22;
      DAT_20004b54 = 0;
      DAT_20004b60 = DAT_20004b58;
      DAT_20004b5c = 0;
      uVar23 = DAT_20004b60;
    }
    DAT_20004b60 = uVar23;
    pGVar9 = __get_dashboard_state();
    bVar19 = pGVar9->glasses_state_struct_0FF0->field_0x5e != '\x01';
    uVar23 = (uint)bVar19;
    uVar10 = FUN_00080732();
    iVar11 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    iVar12 = FUN_000809e2();
    uVar5 = FUN_00080a3a();
    gui_clock_draw(uVar10,iVar11,uVar4 + 2,iVar12 + 0x3f,uVar5 + 0x1d,3,bVar19);
    if (param_3 == 1) {
      pGVar9 = __get_dashboard_state();
      if (*(char *)pGVar9 == '\x01') {
        uVar8 = extraout_r1_09;
        uVar15 = extraout_r2_25;
        iVar11 = LOG_LEVEL;
        if (2 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): received sync area command ,send store cache data to app\n");
            pGVar9 = extraout_r0_03;
            uVar8 = extraout_r1_08;
            uVar15 = extraout_r2_10;
            iVar11 = extraout_r3;
          }
          else {
            ble_printk("%s(): received sync area command ,send store cache data to app\n",
                       "ui_teleprompter_task",extraout_r2_25,BLE_DEBUG);
            pGVar9 = extraout_r0_04;
            uVar8 = extraout_r1_10;
            uVar15 = extraout_r2_26;
            iVar11 = extraout_r3_00;
          }
        }
        send_response_data_to_ble(pGVar9,uVar8,uVar15,iVar11);
        if (DAT_20004b41 < '\x14') {
          DAT_20004b41 = '\x13';
        }
      }
      memset(&DAT_20004b70,0,0x200);
      timeout_00.ticks._4_4_ = 0xffffffff;
      timeout_00.ticks._0_4_ = extraout_r1_11;
      z_impl_k_mutex_lock(&k_mutex_2000851c,timeout_00);
      memcpy(&DAT_20004b70,&pGVar7->field_0x106,0x200);
      bVar3 = pGVar7->field_0xfc;
      cVar1 = pGVar7->field_0xff;
      uVar4 = *(ushort *)&pGVar7->field_0xfd;
      iVar11 = *(int *)&pGVar7->field_0x100;
      z_impl_k_mutex_unlock(&k_mutex_2000851c);
      if (DAT_20010f05 == '\x01') {
        DAT_20010f05 = '\0';
        iVar12 = FUN_000809e2();
        uVar5 = FUN_00080a3a();
        iVar13 = FUN_000809e2();
        uVar6 = FUN_00080a3a();
        FUN_00046544(0,&DAT_20004b70,0,iVar12 + 0x58,uVar5 + 1,iVar13 + 0x230,uVar6 + 0x88,5,
                     (uint)uVar4);
      }
      else {
        iVar12 = FUN_000809e2();
        uVar5 = FUN_00080a3a();
        iVar13 = FUN_000809e2();
        uVar6 = FUN_00080a3a();
        gui_utf_draw(0,&DAT_20004b70,0,iVar12 + 0x58,uVar5 + 1,iVar13 + 0x230,uVar6 + 0x88,5,
                     (uint)uVar4,0,(undefined *)0x0,0);
      }
      iVar12 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      iVar13 = FUN_000809e2();
      uVar5 = FUN_00080a3a();
      uVar23 = 0;
      gui_verticalLine_process_bar(iVar12 + 0x23c,(uint)uVar4,iVar13 + 0x23c,uVar5 + 0x88,1,bVar3);
      if (cVar1 == '\x01') {
        if (DAT_2000aa10 << 0x1e < 0) {
          iVar12 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          iVar13 = FUN_000809e2();
          uVar5 = FUN_00080a3a();
          _clean_fb_data(iVar17,0,iVar12,uVar4 + 0x36,iVar13 + 0x24,uVar5 + 0x52);
        }
        if (DAT_2000aa10 << 0x1e < 0) {
          pGVar7 = __get_dashboard_state();
          iVar13 = *(int *)&pGVar7->field_0xeb4;
          pGVar7 = __get_dashboard_state();
          iVar18 = *(int *)&pGVar7->field_0xeb8;
          iVar17 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          iVar12 = FUN_000809e2();
          uVar5 = FUN_00080a3a();
          _reflash_fb_data_to_lcd(iVar13,iVar18,iVar17,uVar4 + 0x36,iVar12 + 0x24,uVar5 + 0x52);
        }
        iVar17 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        gui_bmp_bitmap_draw(0x1b,iVar17,uVar4 + 0x36,0,0,0);
        DAT_20004b5d = 1;
        DAT_20004b58 = iVar11 * 1000;
        uVar22 = FUN_00080894();
        iVar11 = (int)uVar22;
        DAT_20004b54 = 0;
        DAT_20004b50 = iVar11;
        if (LOG_LEVEL < 3) goto LAB_0004026c;
        pcVar14 = "%s(): suspend enable...\n";
      }
      else {
        DAT_20004b5d = 0;
        iVar11 = DAT_2000aa10 << 0x1e;
        if (iVar11 < 0) {
          iVar11 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          iVar12 = FUN_000809e2();
          uVar5 = FUN_00080a3a();
          _clean_fb_data(iVar17,0,iVar11,uVar4 + 0x36,iVar12 + 0x24,uVar5 + 0x52);
          iVar11 = extraout_r2_11;
        }
        if (DAT_2000aa10 << 0x1e < 0) {
          pGVar7 = __get_dashboard_state();
          iVar12 = *(int *)&pGVar7->field_0xeb4;
          pGVar7 = __get_dashboard_state();
          iVar13 = *(int *)&pGVar7->field_0xeb8;
          iVar17 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          iVar11 = FUN_000809e2();
          uVar5 = FUN_00080a3a();
          _reflash_fb_data_to_lcd(iVar12,iVar13,iVar17,uVar4 + 0x36,iVar11 + 0x24,uVar5 + 0x52);
          iVar11 = extraout_r2_12;
        }
        if (DAT_20004b64 == 1) {
          iVar17 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          uVar10 = 0x1a;
LAB_0003fac8:
          gui_bmp_bitmap_draw(uVar10,iVar17,uVar4 + 0x36,0,0,0);
          iVar11 = extraout_r2_13;
        }
        else if (DAT_20004b64 == 0) {
          iVar17 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          uVar10 = 0x19;
          goto LAB_0003fac8;
        }
        if (LOG_LEVEL < 3) goto LAB_0004026c;
        pcVar14 = "%s(): suspend cancel...\n";
      }
      if (BLE_DEBUG == 0) {
        printk(pcVar14);
      }
      else {
        ble_printk(pcVar14,"ui_teleprompter_task",iVar11,BLE_DEBUG);
      }
    }
LAB_0004026c:
    if ((DAT_20004b64 == 2) && (uVar10 = (uint)DAT_20004b5d, uVar10 == 0)) {
      iVar17 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      gui_bmp_dynamic_bitmap_draw(1,iVar17,uVar4 + 0x36);
      uVar23 = uVar10;
    }
    DAT_20004b60 = DAT_20004b60 / 1000;
    if (DAT_20004b60 < 0x3c) {
      DAT_2000a9c8 = DAT_20004b60 % 0x3c;
    }
    else if (DAT_20004b60 < 0xe10) {
      DAT_2000a9c8 = DAT_20004b60 % 0x3c;
      DAT_2000a9cc = DAT_20004b60 / 0x3c;
    }
    else if (DAT_20004b60 < 360000) {
      DAT_2000a9d0 = DAT_20004b60 / 0xe10;
      DAT_2000a9cc = (DAT_20004b60 % 0xe10) / 0x3c;
      DAT_2000a9c8 = (DAT_20004b60 % 0xe10) % 0x3c;
    }
    else {
      DAT_2000a9d0 = 99;
      DAT_2000a9c8 = 0x3b;
      DAT_2000a9cc = 0x3b;
    }
    local_68 = 0;
    memset(auStack_64,0,0x3c);
    if ((int)DAT_2000a9d0 < 10) {
      pcVar14 = "%d:%02d:%02d";
    }
    else {
      pcVar14 = "%02d:%02d:%02d";
    }
    snprintf((char *)&local_68,0x40,pcVar14,DAT_2000a9d0,DAT_2000a9cc,DAT_2000a9c8,uVar23);
    if (((DAT_2000a9d0 != DAT_2000a9c4) || (DAT_2000a9cc != DAT_2000a9c0)) ||
       (DAT_2000a9c8 != DAT_2000a9bc)) {
      iVar17 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      iVar11 = FUN_000809e2();
      uVar5 = FUN_00080a3a();
      gui_utf_draw(0,(char *)&local_68,0,iVar17,uVar4 + 0x6e,iVar11 + 0x50,uVar5 + 0x88,1,0,0,
                   (undefined *)0x0,0);
      DAT_2000a9c4 = DAT_2000a9d0;
      DAT_2000a9c0 = DAT_2000a9cc;
      DAT_2000a9bc = DAT_2000a9c8;
    }
    pGVar7 = __get_dashboard_state();
    if (*(char *)pGVar7 == '\x01') {
      if ((0 < DAT_20007f44) && (DAT_20007f44 = 0, DAT_20004b41 < '\x14')) {
        DAT_20004b41 = '\x13';
      }
      uVar22 = FUN_00080894();
      uVar21 = FUN_000809b6((uint)uVar22,(int)((ulonglong)uVar22 >> 0x20),DAT_20004b48,DAT_20004b4c)
      ;
      uVar22 = CONCAT44(DAT_20004b4c,DAT_20004b48);
      if ((int)((ulonglong)uVar21 >> 0x20) < (int)(uint)((uint)uVar21 < 0x3e9))
      goto switchD_0003f274_default;
      uVar22 = FUN_00080894();
      DAT_20004b4c = (int)((ulonglong)uVar22 >> 0x20);
      DAT_20004b48 = (uint)uVar22;
      DAT_20004b41 = DAT_20004b41 + -1;
      uVar8 = extraout_r2_15;
      if (2 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): DECETED TIMEOUT ...... _tpm_thread_prv_data.sync_cnt = %d\n");
          uVar22 = CONCAT44(DAT_20004b4c,DAT_20004b48);
          uVar8 = extraout_r2_19;
        }
        else {
          ble_printk("%s(): DECETED TIMEOUT ...... _tpm_thread_prv_data.sync_cnt = %d\n",
                     "ui_teleprompter_task",(int)DAT_20004b41,BLE_DEBUG);
          uVar22 = CONCAT44(DAT_20004b4c,DAT_20004b48);
          uVar8 = extraout_r2_16;
        }
      }
      DAT_20004b4c = (int)((ulonglong)uVar22 >> 0x20);
      DAT_20004b48 = (uint)uVar22;
      if ('\0' < DAT_20004b41) goto switchD_0003f274_default;
      if (1 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk(
                "%s(): There is a disconnection between the AR Glasses and the Bluetooth application!\n"
                );
          uVar22 = CONCAT44(DAT_20004b4c,DAT_20004b48);
          uVar8 = extraout_r2_20;
        }
        else {
          ble_printk("%s(): There is a disconnection between the AR Glasses and the Bluetooth application!\n"
                     ,"ui_teleprompter_task",uVar8,BLE_DEBUG);
          uVar22 = CONCAT44(DAT_20004b4c,DAT_20004b48);
          uVar8 = extraout_r2_17;
        }
      }
      DAT_20004b4c = (int)((ulonglong)uVar22 >> 0x20);
      DAT_20004b48 = (uint)uVar22;
      if (2 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): bluetooth connect is break,Send Stop Teleprompter command to slave.\n");
          uVar22 = CONCAT44(DAT_20004b4c,DAT_20004b48);
        }
        else {
          ble_printk("%s(): bluetooth connect is break,Send Stop Teleprompter command to slave.\n",
                     "ui_teleprompter_task",uVar8,BLE_DEBUG);
          uVar22 = CONCAT44(DAT_20004b4c,DAT_20004b48);
        }
      }
      DAT_20004b4c = (int)((ulonglong)uVar22 >> 0x20);
      DAT_20004b48 = (uint)uVar22;
      local_6c[0] = 0x103;
      pGVar7 = __get_dashboard_state();
      uVar23 = sync_to_slave((char *)pGVar7,6,(undefined4 *)local_6c,2);
      if (4999 < (int)uVar23) {
        uVar22 = CONCAT44(DAT_20004b4c,DAT_20004b48);
        if (0 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk(
                  "%s(): SYNC TO Slave failed...,don\'t exec teleprompter exit action,master auto exit...\n"
                  );
            uVar22 = CONCAT44(DAT_20004b4c,DAT_20004b48);
          }
          else {
            ble_printk("%s(): SYNC TO Slave failed...,don\'t exec teleprompter exit action,master auto exit...\n"
                       ,"ui_teleprompter_task",extraout_r2_18,BLE_DEBUG);
            uVar22 = CONCAT44(DAT_20004b4c,DAT_20004b48);
          }
        }
        goto switchD_0003f274_default;
      }
      DAT_20004b40 = 3;
      uVar22 = FUN_00080894();
      DAT_20004b4c = (int)((ulonglong)uVar22 >> 0x20);
      DAT_20004b48 = (uint)uVar22;
      gui_screen_clear(DAT_20004b48,DAT_20004b4c,extraout_r2_21);
      iVar17 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      gui_bmp_bitmap_draw(0x3f,iVar17,uVar4 + 0x3a,0,0,0);
      bVar3 = get_current_language();
      if (bVar3 == 6) {
        iVar17 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        iVar11 = FUN_000809e2();
        uVar5 = FUN_00080a3a();
        gui_utf_draw(0,"Teleprompter aufgrund einer",0,iVar17 + 0xa0,uVar4 + 0x37,iVar11 + 0x23a,
                     uVar5 + 0x52,1,0,0,(undefined *)0x0,0);
        iVar17 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        iVar12 = FUN_000809e2();
        uVar5 = FUN_00080a3a();
        iVar11 = uVar5 + 0x6d;
        iVar13 = uVar4 + 0x52;
        pcVar14 = "App-Trennung gestoppt.";
        iVar17 = iVar17 + 0xb4;
      }
      else {
        iVar17 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        iVar12 = FUN_000809e2();
        uVar5 = FUN_00080a3a();
        iVar11 = uVar5 + 0x88;
        iVar13 = uVar4 + 0x37;
        pcVar14 = "Teleprompt stopped due to app disconnection";
        iVar17 = iVar17 + 0x4e;
      }
      gui_utf_draw(0,pcVar14,0,iVar17,iVar13,iVar12 + 0x23a,iVar11,1,0,0,(undefined *)0x0,0);
      goto LAB_0003f99a;
    }
    uVar22 = CONCAT44(DAT_20004b4c,DAT_20004b48);
    if (param_3 != 5) goto switchD_0003f274_default;
    if (2 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): Received exit command from master, exit teleprompter mode\n");
      }
      else {
        ble_printk("%s(): Received exit command from master, exit teleprompter mode\n",
                   "ui_teleprompter_task",extraout_r2_14,BLE_DEBUG);
      }
    }
    DAT_20004b40 = 3;
    uVar22 = FUN_00080894();
    DAT_20004b4c = (int)((ulonglong)uVar22 >> 0x20);
    DAT_20004b48 = (uint)uVar22;
    gui_screen_clear(DAT_20004b48,DAT_20004b4c,extraout_r2_22);
    iVar17 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    gui_bmp_bitmap_draw(0x3f,iVar17,uVar4 + 0x3a,0,0,0);
    bVar3 = get_current_language();
    if (bVar3 == 6) {
      iVar17 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      iVar11 = FUN_000809e2();
      uVar5 = FUN_00080a3a();
      gui_utf_draw(0,"Teleprompter aufgrund einer",0,iVar17 + 0xa0,uVar4 + 0x37,iVar11 + 0x23a,
                   uVar5 + 0x52,1,0,0,(undefined *)0x0,0);
      iVar17 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      iVar11 = FUN_000809e2();
      uVar5 = FUN_00080a3a();
      iVar11 = iVar11 + 0x23a;
      iVar12 = uVar5 + 0x6d;
      iVar13 = uVar4 + 0x52;
      pcVar14 = "App-Trennung gestoppt.";
      iVar17 = iVar17 + 0xb4;
    }
    else {
      iVar17 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      iVar11 = FUN_000809e2();
      uVar5 = FUN_00080a3a();
      iVar12 = uVar5 + 0x88;
      iVar11 = iVar11 + 0x23a;
      iVar13 = uVar4 + 0x37;
      pcVar14 = "Teleprompt stopped due to app disconnection";
      iVar17 = iVar17 + 0x4e;
    }
    break;
  case 3:
    if (1 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): running TELEPROMPTER_DISPLAY_ABNORMAL_EXIT STATUS.\n");
      }
      else {
        ble_printk("%s(): running TELEPROMPTER_DISPLAY_ABNORMAL_EXIT STATUS.\n",
                   "ui_teleprompter_task",extraout_r2,BLE_DEBUG);
      }
    }
    uVar22 = FUN_00080894();
    uVar22 = FUN_000809b6((uint)uVar22,(int)((ulonglong)uVar22 >> 0x20),DAT_20004b48,DAT_20004b4c);
    uVar8 = extraout_r2_23;
    if ((int)(uint)((uint)uVar22 < 0x1f41) <= (int)((ulonglong)uVar22 >> 0x20)) {
      if (1 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): The teleprompter automatically shuts down due to disconnection.\n");
        }
        else {
          ble_printk("%s(): The teleprompter automatically shuts down due to disconnection.\n",
                     "ui_teleprompter_task",extraout_r2_23,BLE_DEBUG);
        }
      }
      pGVar7 = __get_dashboard_state();
      memset(*(void **)&pGVar7->field_0x1000,0,0x217);
      FUN_00045968();
      pGVar7 = __get_dashboard_state();
      *(undefined1 *)(*(int *)&pGVar7->field_0x1000 + 1) = 0;
      memset(&DAT_20004b40,0,0x230);
      uVar8 = extraout_r2_24;
    }
    uVar22 = CONCAT44(DAT_20004b4c,DAT_20004b48);
    if (param_3 != 2) goto switchD_0003f274_default;
joined_r0x0003ffd8:
    if (2 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): received exit command,clear screen...\n");
      }
      else {
        ble_printk("%s(): received exit command,clear screen...\n","ui_teleprompter_task",uVar8,
                   BLE_DEBUG);
      }
    }
LAB_0003f98a:
    FUN_00045968();
    memset(&DAT_20004b40,0,0x230);
LAB_0003f99a:
    pGVar7 = __get_dashboard_state();
    uVar22 = CONCAT44(DAT_20004b4c,DAT_20004b48);
    if ((*(char *)pGVar7 == '\x01') &&
       (uVar22 = CONCAT44(DAT_20004b4c,DAT_20004b48), DAT_20004b64 == 2)) {
      FUN_00030458();
      uVar22 = CONCAT44(DAT_20004b4c,DAT_20004b48);
    }
  default:
    goto switchD_0003f274_default;
  }
  gui_utf_draw(0,pcVar14,0,iVar17,iVar13,iVar11,iVar12,1,0,0,(undefined *)0x0,0);
  uVar22 = CONCAT44(DAT_20004b4c,DAT_20004b48);
switchD_0003f274_default:
  DAT_20004b4c = (int)((ulonglong)uVar22 >> 0x20);
  DAT_20004b48 = (uint)uVar22;
  return 0;
}


