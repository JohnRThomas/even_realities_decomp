/*
 * Function: ui_new_message_come_on_task
 * Entry:    000384c4
 * Prototype: undefined4 __stdcall ui_new_message_come_on_task(int param_1, undefined4 param_2, int param_3)
 */


undefined4 ui_new_message_come_on_task(int param_1,undefined4 param_2,int param_3)

{
  char cVar1;
  byte bVar2;
  ushort uVar3;
  GlassesState *pGVar4;
  undefined4 extraout_r0;
  undefined4 extraout_r0_00;
  undefined4 uVar5;
  uint uVar6;
  char *pcVar7;
  int iVar8;
  char *extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 uVar9;
  undefined4 extraout_r1_01;
  undefined4 extraout_r1_02;
  char *extraout_r1_03;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 uVar10;
  undefined4 extraout_r2_01;
  undefined4 extraout_r2_02;
  undefined4 extraout_r2_03;
  undefined4 extraout_r2_04;
  int iVar11;
  int iVar12;
  byte local_30 [12];
  
  pGVar4 = __get_dashboard_state();
  bVar2 = FUN_00035a78();
  cVar1 = DAT_2001c4e2;
  uVar6 = (uint)bVar2;
  if (uVar6 != 4) {
    if (param_3 == 2) {
      if (BLE_DEBUG == 0) {
        printk("ui_new_message_come_on_task exit !");
        uVar5 = extraout_r0_00;
        uVar9 = extraout_r1_01;
        uVar10 = extraout_r2_01;
      }
      else {
        ble_printk("ui_new_message_come_on_task exit !",extraout_r1,extraout_r2,BLE_DEBUG);
        uVar5 = extraout_r0;
        uVar9 = extraout_r1_00;
        uVar10 = extraout_r2_00;
      }
      gui_screen_clear(uVar5,uVar9,uVar10);
      DAT_2001c4e2 = '\0';
      DAT_2001c4e1 = '\0';
    }
    else if (param_3 != 0) {
      pcVar7 = extraout_r1;
      uVar5 = extraout_r2;
      if (DAT_2001c4e2 == '\0') {
        DAT_2001c4e2 = '\x01';
        FUN_000452f0(param_1 + 0x24);
        uVar5 = FUN_0004540c();
        uVar6 = gui_screen_clear(uVar5,extraout_r1_02,extraout_r2_02);
        DAT_2001c4e1 = cVar1;
        pcVar7 = extraout_r1_03;
        uVar5 = extraout_r2_03;
      }
      if ((byte)pGVar4->field_0xf6 < 2) {
        DAT_2001c4e1 = '\0';
        gui_screen_clear(uVar6,pcVar7,uVar5);
      }
      else {
        pGVar4 = __get_dashboard_state();
        pcVar7 = (char *)FUN_00035ed8((byte)pGVar4->field_0xdd - 1 & 0xff);
        if (BLE_DEBUG == 0) {
          printk("new msgType is %d \n");
        }
        else {
          ble_printk("new msgType is %d \n",pcVar7,extraout_r2_04,BLE_DEBUG);
        }
        if (DAT_2001c4e1 == '\0') {
          FUN_00045428();
          iVar12 = 0;
          do {
            switch(pcVar7) {
            case (char *)0x1:
              iVar8 = FUN_000809e2();
              uVar3 = FUN_00080a3a();
              iVar11 = uVar3 + 0x3a;
              uVar6 = 0x37;
              break;
            case (char *)0x2:
              iVar8 = FUN_000809e2();
              uVar3 = FUN_00080a3a();
              iVar11 = uVar3 + 0x3a;
              uVar6 = 0x36;
              break;
            case (char *)0x3:
              iVar8 = FUN_000809e2();
              uVar3 = FUN_00080a3a();
              iVar11 = uVar3 + 0x3a;
              uVar6 = 0x3a;
              break;
            case (char *)0x4:
              iVar8 = FUN_000809e2();
              uVar3 = FUN_00080a3a();
              iVar11 = uVar3 + 0x3a;
              uVar6 = 0x39;
              break;
            default:
              iVar8 = FUN_000809e2();
              uVar3 = FUN_00080a3a();
              iVar11 = uVar3 + 0x3a;
              uVar6 = 0x38;
            }
            gui_bmp_bitmap_draw(uVar6,iVar8,iVar11,0,0,0);
            uVar6 = 0;
            do {
              iVar8 = 0;
              do {
                local_30[0] = 1;
                local_30[1] = 2;
                local_30[2] = 3;
                local_30[3] = 4;
                local_30[4] = 5;
                local_30[5] = 6;
                local_30[6] = 7;
                local_30[7] = 7;
                iVar11 = *(int *)(param_1 + 0x24 + uVar6 * 4);
                bVar2 = *(byte *)(iVar11 + iVar8);
                if (bVar2 != 0) {
                  *(byte *)(iVar11 + iVar8) =
                       bVar2 & (&DAT_000accab)
                               [iVar8 + (uint)local_30[iVar12] * 0x140 + (uVar6 % 0x1a) * 0xa00];
                }
                iVar8 = iVar8 + 1;
              } while (iVar8 != 0x140);
              uVar6 = uVar6 + 1;
            } while (uVar6 != 199);
            pGVar4 = __get_dashboard_state();
            iVar8 = *(int *)&pGVar4->field_0xeb4;
            pGVar4 = __get_dashboard_state();
            iVar12 = iVar12 + 1;
            _reflash_fb_data_to_lcd(iVar8,*(int *)&pGVar4->field_0xeb8,0,0,0x280,199);
          } while (iVar12 != 8);
          FUN_0004540c();
          DAT_2001c4e1 = '\x01';
        }
      }
    }
  }
  return 0;
}


