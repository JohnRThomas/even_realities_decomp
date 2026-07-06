/*
 * Function: ui_set_imu_pitch_task
 * Entry:    00049304
 * Prototype: undefined4 __stdcall ui_set_imu_pitch_task(int param_1, undefined4 param_2, int param_3)
 */


undefined4 ui_set_imu_pitch_task(int param_1,undefined4 param_2,int param_3)

{
  byte bVar1;
  char cVar2;
  GlassesState *pGVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint32_t uVar7;
  int iVar8;
  byte local_30 [12];
  
  __get_dashboard_state();
  __set_frame_buffer(param_1 + 0x24);
  __set_showing_notification_on_gui();
  if ((char)DAT_2001dd01 == '\0') {
    if (param_3 == 1) {
      cVar2 = DAT_2001dd01._1_1_;
      if (DAT_2001dd01._1_1_ != '\0') {
        return 0;
      }
      FUN_000809d0();
      gui_screen_clear();
      FUN_00045834();
      DAT_2001dd03 = cVar2;
      DAT_2001dd01._0_1_ = cVar2;
      DAT_2001dd01._1_1_ = 1;
      FUN_00045444();
      DAT_2001dd01 = CONCAT11(DAT_2001dd01._1_1_,1);
      __clear_showing_notification_on_gui();
      iVar5 = 0;
      do {
        set_imu_pitch_reflash();
        uVar6 = 0;
        do {
          iVar4 = 0;
          do {
            iVar8 = *(int *)(param_1 + 0x24 + uVar6 * 4);
            bVar1 = *(byte *)(iVar8 + iVar4);
            local_30[0] = 1;
            local_30[1] = 2;
            local_30[2] = 3;
            local_30[3] = 4;
            local_30[4] = 5;
            local_30[5] = 6;
            local_30[6] = 7;
            local_30[7] = 7;
            if (bVar1 != 0) {
              *(byte *)(iVar8 + iVar4) =
                   bVar1 & (&DAT_000accab)
                           [iVar4 + (uint)local_30[iVar5] * 0x140 + (uVar6 % 0x1a) * 0xa00];
            }
            iVar4 = iVar4 + 1;
          } while (iVar4 != 0x140);
          uVar6 = uVar6 + 1;
        } while (uVar6 != 199);
        pGVar3 = __get_dashboard_state();
        uVar7 = (pGVar3->jdb_panel_context).current_row;
        pGVar3 = __get_dashboard_state();
        iVar5 = iVar5 + 1;
        _reflash_fb_data_to_lcd(uVar7,(pGVar3->jdb_panel_context).current_column,0,0,0x280,199);
      } while (iVar5 != 8);
      __set_showing_notification_on_gui();
      return 0;
    }
    if (param_3 != 2) {
      return 0;
    }
    if (2 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): set_imu_pitch process received exit packet ...\n","ui_set_imu_pitch_task");
      }
      else {
        ble_printk("%s(): set_imu_pitch process received exit packet ...\n");
      }
    }
    gui_screen_clear();
  }
  else {
    if ((char)DAT_2001dd01 != '\x01') {
      return 0;
    }
    if (param_3 == 1) {
      set_imu_pitch_reflash();
      return 0;
    }
    if (param_3 != 2) {
      return 0;
    }
    if (2 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): set_imu_pitch process received exit packet ...\n","ui_set_imu_pitch_task");
      }
      else {
        ble_printk("%s(): set_imu_pitch process received exit packet ...\n");
      }
    }
    FUN_00045968();
  }
  FUN_000809d0();
  DAT_2001dd03 = 0;
  DAT_2001dd01 = 0;
  return 0;
}


