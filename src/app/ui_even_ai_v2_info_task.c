/*
 * Function: ui_even_ai_v2_info_task
 * Entry:    0004a4b0
 * Prototype: undefined4 __stdcall ui_even_ai_v2_info_task(int param_1, undefined4 param_2, int param_3)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 ui_even_ai_v2_info_task(int param_1,undefined4 param_2,int param_3)

{
  byte bVar1;
  longlong lVar2;
  GlassesState *pGVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint32_t uVar8;
  int iVar9;
  ulonglong uVar10;
  undefined8 uVar11;
  byte local_30 [12];
  
  pGVar3 = __get_dashboard_state();
  iVar6 = param_1 + 0x24;
  __set_frame_buffer(iVar6);
  __set_showing_notification_on_gui();
  if (DAT_20004dd0 == '\0') {
    if (param_3 == 1) {
      if (pGVar3->field20_0xc8[0x28] == '\0') {
        return 0;
      }
      if (DAT_20004dd1 != '\0') {
        return 0;
      }
      FUN_000809d0();
      gui_screen_clear();
      FUN_00045834();
      memset(&DAT_20004dd0,0,0x18);
      FUN_00045444();
      __clear_showing_notification_on_gui();
      iVar7 = 0;
      do {
        even_ai_v2_info_reflash(iVar6,1);
        uVar4 = 0;
        do {
          iVar5 = 0;
          do {
            iVar9 = *(int *)(iVar6 + uVar4 * 4);
            local_30[0] = 1;
            local_30[1] = 2;
            local_30[2] = 3;
            local_30[3] = 4;
            local_30[4] = 5;
            local_30[5] = 6;
            local_30[6] = 7;
            local_30[7] = 7;
            bVar1 = *(byte *)(iVar9 + iVar5);
            if (bVar1 != 0) {
              *(byte *)(iVar9 + iVar5) =
                   bVar1 & (&DAT_000accab)
                           [iVar5 + (uint)local_30[iVar7] * 0x140 + (uVar4 % 0x1a) * 0xa00];
            }
            iVar5 = iVar5 + 1;
          } while (iVar5 != 0x140);
          uVar4 = uVar4 + 1;
        } while (uVar4 != 199);
        pGVar3 = __get_dashboard_state();
        uVar8 = (pGVar3->jdb_panel_context).current_row;
        pGVar3 = __get_dashboard_state();
        iVar7 = iVar7 + 1;
        _reflash_fb_data_to_lcd(uVar8,(pGVar3->jdb_panel_context).current_column,0,0,0x280,199);
      } while (iVar7 != 8);
      __set_showing_notification_on_gui();
      _DAT_20004dd0 = 0x101;
      uVar10 = sys_clock_tick_get();
      lVar2 = (uVar10 & 0xffffffff) * 1000;
      uVar4 = (int)(uVar10 >> 0x20) * 1000 + (int)((ulonglong)lVar2 >> 0x20);
      DAT_20004dd8 = (uint)lVar2 >> 0xf | uVar4 * 0x20000;
      DAT_20004ddc = uVar4 >> 0xf;
      return 0;
    }
    if (param_3 != 2) {
      return 0;
    }
    if (2 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): set_imu_pitch process received exit packet ...\n","ui_even_ai_v2_info_task");
      }
      else {
        ble_printk("%s(): set_imu_pitch process received exit packet ...\n");
      }
    }
    gui_screen_clear();
    FUN_000809d0();
    memset(&DAT_20004dd0,0,0x18);
  }
  else {
    if (DAT_20004dd0 != '\x01') {
      return 0;
    }
    if ((param_3 == 1) || (param_3 == 0)) {
      even_ai_v2_info_reflash(iVar6,param_3);
    }
    else if (param_3 == 2) {
      if (2 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): set_imu_pitch process received exit packet ...\n","ui_even_ai_v2_info_task")
          ;
        }
        else {
          ble_printk("%s(): set_imu_pitch process received exit packet ...\n");
        }
      }
      FUN_00045968();
      FUN_000809d0();
      memset(&DAT_20004dd0,0,0x18);
      FUN_00030458();
    }
    pGVar3 = __get_dashboard_state();
    if (pGVar3->is_master != true) {
      return 0;
    }
    uVar10 = sys_clock_tick_get();
    lVar2 = (uVar10 & 0xffffffff) * 1000;
    uVar4 = (int)(uVar10 >> 0x20) * 1000 + (int)((ulonglong)lVar2 >> 0x20);
    uVar11 = FUN_000809b6((uint)lVar2 >> 0xf | uVar4 * 0x20000,uVar4 >> 0xf,DAT_20004dd8,
                          DAT_20004ddc);
    if ((int)((ulonglong)uVar11 >> 0x20) < (int)(uint)((uint)uVar11 < 0x3e9)) {
      return 0;
    }
    DAT_20004dd2 = DAT_20004dd2 + 1;
    uVar10 = sys_clock_tick_get();
    lVar2 = (uVar10 & 0xffffffff) * 1000;
    uVar4 = (int)(uVar10 >> 0x20) * 1000 + (int)((ulonglong)lVar2 >> 0x20);
    DAT_20004dd8 = (uint)lVar2 >> 0xf | uVar4 * 0x20000;
    DAT_20004ddc = uVar4 >> 0xf;
    if (DAT_20004dd2 < 0x14) {
      return 0;
    }
    pGVar3 = __get_dashboard_state();
    **(undefined1 **)&pGVar3->field_0x1014 = 0;
  }
  FUN_00030458();
  return 0;
}


