/*
 * Function: ui_prompt_info_task
 * Entry:    00049508
 * Prototype: undefined4 __stdcall ui_prompt_info_task(int param_1, undefined4 param_2, int param_3)
 */


undefined4 ui_prompt_info_task(int param_1,undefined4 param_2,int param_3)

{
  byte bVar1;
  longlong lVar2;
  char cVar3;
  GlassesState *pGVar4;
  global_state_struct_1028 *pgVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint32_t uVar9;
  int iVar10;
  ulonglong uVar11;
  byte local_30 [12];
  
  __get_dashboard_state();
  __set_frame_buffer(param_1 + 0x24);
  __set_showing_notification_on_gui();
  if ((char)DAT_2001dd04 == '\0') {
    if (param_3 == 1) {
      cVar3 = DAT_2001dd04._1_1_;
      if (DAT_2001dd04._1_1_ != '\0') {
        return 0;
      }
      FUN_000809d0();
      gui_screen_clear();
      FUN_00045834();
      DAT_2001dd04._0_1_ = cVar3;
      DAT_2001dd04._1_1_ = 1;
      uVar11 = sys_clock_tick_get();
      pGVar4 = __get_dashboard_state();
      lVar2 = (uVar11 & 0xffffffff) * 1000;
      uVar6 = (int)(uVar11 >> 0x20) * 1000 + (int)((ulonglong)lVar2 >> 0x20);
      pgVar5 = pGVar4->field_global_state_struct_1028;
      *(uint *)((int)&pgVar5->field0_0x0 + 2) = (uint)lVar2 >> 0xf | uVar6 * 0x20000;
      *(uint *)((int)&pgVar5->field1_0x4 + 2) = uVar6 >> 0xf;
      FUN_00045444();
      DAT_2001dd04 = CONCAT11(DAT_2001dd04._1_1_,1);
      __clear_showing_notification_on_gui();
      iVar8 = 0;
      do {
        prompt_info_reflash();
        uVar6 = 0;
        do {
          iVar7 = 0;
          do {
            iVar10 = *(int *)(param_1 + 0x24 + uVar6 * 4);
            bVar1 = *(byte *)(iVar10 + iVar7);
            local_30[0] = 1;
            local_30[1] = 2;
            local_30[2] = 3;
            local_30[3] = 4;
            local_30[4] = 5;
            local_30[5] = 6;
            local_30[6] = 7;
            local_30[7] = 7;
            if (bVar1 != 0) {
              *(byte *)(iVar10 + iVar7) =
                   bVar1 & (&DAT_000accab)
                           [iVar7 + (uint)local_30[iVar8] * 0x140 + (uVar6 % 0x1a) * 0xa00];
            }
            iVar7 = iVar7 + 1;
          } while (iVar7 != 0x140);
          uVar6 = uVar6 + 1;
        } while (uVar6 != 199);
        pGVar4 = __get_dashboard_state();
        uVar9 = (pGVar4->jdb_panel_context).current_row;
        pGVar4 = __get_dashboard_state();
        iVar8 = iVar8 + 1;
        _reflash_fb_data_to_lcd(uVar9,(pGVar4->jdb_panel_context).current_column,0,0,0x280,199);
      } while (iVar8 != 8);
      __set_showing_notification_on_gui();
      return 0;
    }
    if (param_3 != 2) {
      return 0;
    }
    if (2 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): set_imu_pitch process received exit packet ...\n","ui_prompt_info_task");
      }
      else {
        ble_printk("%s(): set_imu_pitch process received exit packet ...\n");
      }
    }
    gui_screen_clear();
  }
  else {
    if ((char)DAT_2001dd04 != '\x01') {
      return 0;
    }
    if (param_3 == 1) {
      prompt_info_reflash();
      return 0;
    }
    if (param_3 != 2) {
      return 0;
    }
    if (2 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): set_imu_pitch process received exit packet ...\n","ui_prompt_info_task");
      }
      else {
        ble_printk("%s(): set_imu_pitch process received exit packet ...\n");
      }
    }
    FUN_00045968();
  }
  FUN_000809d0();
  DAT_2001dd04 = 0;
  return 0;
}


