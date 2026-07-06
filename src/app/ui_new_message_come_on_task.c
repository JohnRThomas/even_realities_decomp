/*
 * Function: ui_new_message_come_on_task
 * Entry:    000384c4
 * Prototype: undefined4 __stdcall ui_new_message_come_on_task(int param_1, undefined4 param_2, int param_3)
 */


undefined4 ui_new_message_come_on_task(int param_1,undefined4 param_2,int param_3)

{
  byte bVar1;
  char cVar2;
  char cVar3;
  ushort uVar4;
  GlassesState *pGVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  uint32_t uVar11;
  byte local_30 [12];
  
  pGVar5 = __get_dashboard_state();
  cVar3 = FUN_00035a78();
  cVar2 = DAT_2001c4e2;
  if (cVar3 != '\x04') {
    if (param_3 == 2) {
      if (BLE_DEBUG == 0) {
        printk("ui_new_message_come_on_task exit !");
      }
      else {
        ble_printk("ui_new_message_come_on_task exit !");
      }
      gui_screen_clear();
      DAT_2001c4e2 = '\0';
      DAT_2001c4e1 = '\0';
    }
    else if (param_3 != 0) {
      if (DAT_2001c4e2 == '\0') {
        DAT_2001c4e2 = '\x01';
        __set_frame_buffer(param_1 + 0x24);
        __set_showing_notification_on_gui();
        gui_screen_clear();
        DAT_2001c4e1 = cVar2;
      }
      if ((byte)pGVar5->field20_0xc8[0x2e] < 2) {
        DAT_2001c4e1 = '\0';
        gui_screen_clear();
      }
      else {
        pGVar5 = __get_dashboard_state();
        uVar6 = __parse_message_type((byte)pGVar5->field20_0xc8[0x15] - 1 & 0xff);
        if (BLE_DEBUG == 0) {
          printk("new msgType is %d \n",uVar6);
        }
        else {
          ble_printk("new msgType is %d \n");
        }
        if (DAT_2001c4e1 == '\0') {
          __clear_showing_notification_on_gui();
          iVar10 = 0;
          do {
            switch(uVar6) {
            case 1:
              iVar7 = FUN_000809e2();
              uVar4 = FUN_00080a3a();
              iVar9 = uVar4 + 0x3a;
              uVar8 = 0x37;
              break;
            case 2:
              iVar7 = FUN_000809e2();
              uVar4 = FUN_00080a3a();
              iVar9 = uVar4 + 0x3a;
              uVar8 = 0x36;
              break;
            case 3:
              iVar7 = FUN_000809e2();
              uVar4 = FUN_00080a3a();
              iVar9 = uVar4 + 0x3a;
              uVar8 = 0x3a;
              break;
            case 4:
              iVar7 = FUN_000809e2();
              uVar4 = FUN_00080a3a();
              iVar9 = uVar4 + 0x3a;
              uVar8 = 0x39;
              break;
            default:
              iVar7 = FUN_000809e2();
              uVar4 = FUN_00080a3a();
              iVar9 = uVar4 + 0x3a;
              uVar8 = 0x38;
            }
            gui_bmp_bitmap_draw(uVar8,iVar7,iVar9,0,0,0);
            uVar8 = 0;
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
                iVar9 = *(int *)(param_1 + 0x24 + uVar8 * 4);
                bVar1 = *(byte *)(iVar9 + iVar7);
                if (bVar1 != 0) {
                  *(byte *)(iVar9 + iVar7) =
                       bVar1 & (&DAT_000accab)
                               [iVar7 + (uint)local_30[iVar10] * 0x140 + (uVar8 % 0x1a) * 0xa00];
                }
                iVar7 = iVar7 + 1;
              } while (iVar7 != 0x140);
              uVar8 = uVar8 + 1;
            } while (uVar8 != 199);
            pGVar5 = __get_dashboard_state();
            uVar11 = (pGVar5->jdb_panel_context).current_row;
            pGVar5 = __get_dashboard_state();
            iVar10 = iVar10 + 1;
            _reflash_fb_data_to_lcd(uVar11,(pGVar5->jdb_panel_context).current_column,0,0,0x280,199)
            ;
          } while (iVar10 != 8);
          __set_showing_notification_on_gui();
          DAT_2001c4e1 = '\x01';
        }
      }
    }
  }
  return 0;
}


