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
  undefined4 uVar4;
  undefined4 extraout_r0;
  undefined4 extraout_r0_00;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  undefined4 uVar5;
  undefined4 extraout_r1_02;
  uint uVar6;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 uVar7;
  undefined4 extraout_r2_02;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  ulonglong uVar12;
  undefined8 uVar13;
  byte local_30 [12];
  
  pGVar3 = __get_dashboard_state();
  iVar9 = param_1 + 0x24;
  FUN_000452f0(iVar9);
  uVar4 = FUN_0004540c();
  if (DAT_20004dd0 == '\0') {
    if (param_3 == 1) {
      if (pGVar3->field_0xf0 == '\0') {
        return 0;
      }
      if (DAT_20004dd1 != '\0') {
        return 0;
      }
      uVar4 = FUN_000809d0();
      gui_screen_clear(uVar4,extraout_r1_00,extraout_r2_00);
      FUN_00045834();
      memset(&DAT_20004dd0,0,0x18);
      FUN_00045444();
      FUN_00045428();
      iVar10 = 0;
      do {
        even_ai_v2_info_reflash(iVar9,1);
        uVar6 = 0;
        do {
          iVar8 = 0;
          do {
            iVar11 = *(int *)(iVar9 + uVar6 * 4);
            local_30[0] = 1;
            local_30[1] = 2;
            local_30[2] = 3;
            local_30[3] = 4;
            local_30[4] = 5;
            local_30[5] = 6;
            local_30[6] = 7;
            local_30[7] = 7;
            bVar1 = *(byte *)(iVar11 + iVar8);
            if (bVar1 != 0) {
              *(byte *)(iVar11 + iVar8) =
                   bVar1 & (&DAT_000accab)
                           [iVar8 + (uint)local_30[iVar10] * 0x140 + (uVar6 % 0x1a) * 0xa00];
            }
            iVar8 = iVar8 + 1;
          } while (iVar8 != 0x140);
          uVar6 = uVar6 + 1;
        } while (uVar6 != 199);
        pGVar3 = __get_dashboard_state();
        iVar8 = *(int *)&(pGVar3->jdb_panel_context).field_0x348;
        pGVar3 = __get_dashboard_state();
        iVar10 = iVar10 + 1;
        _reflash_fb_data_to_lcd
                  (iVar8,*(int *)&(pGVar3->jdb_panel_context).field_0x34c,0,0,0x280,199);
      } while (iVar10 != 8);
      FUN_0004540c();
      _DAT_20004dd0 = 0x101;
      uVar12 = sys_clock_tick_get();
      lVar2 = (uVar12 & 0xffffffff) * 1000;
      uVar6 = (int)(uVar12 >> 0x20) * 1000 + (int)((ulonglong)lVar2 >> 0x20);
      DAT_20004dd8 = (uint)lVar2 >> 0xf | uVar6 * 0x20000;
      DAT_20004ddc = uVar6 >> 0xf;
      return 0;
    }
    if (param_3 != 2) {
      return 0;
    }
    uVar5 = extraout_r1;
    uVar7 = extraout_r2;
    if (2 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): set_imu_pitch process received exit packet ...\n");
        uVar4 = extraout_r0_00;
        uVar5 = extraout_r1_02;
        uVar7 = extraout_r2_02;
      }
      else {
        ble_printk("%s(): set_imu_pitch process received exit packet ...\n",
                   "ui_even_ai_v2_info_task",extraout_r2,BLE_DEBUG);
        uVar4 = extraout_r0;
        uVar5 = extraout_r1_01;
        uVar7 = extraout_r2_01;
      }
    }
    gui_screen_clear(uVar4,uVar5,uVar7);
    FUN_000809d0();
    memset(&DAT_20004dd0,0,0x18);
  }
  else {
    if (DAT_20004dd0 != '\x01') {
      return 0;
    }
    if ((param_3 == 1) || (param_3 == 0)) {
      even_ai_v2_info_reflash(iVar9,param_3);
    }
    else if (param_3 == 2) {
      if (2 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): set_imu_pitch process received exit packet ...\n");
        }
        else {
          ble_printk("%s(): set_imu_pitch process received exit packet ...\n",
                     "ui_even_ai_v2_info_task",extraout_r2,BLE_DEBUG);
        }
      }
      FUN_00045968();
      FUN_000809d0();
      memset(&DAT_20004dd0,0,0x18);
      FUN_00030458();
    }
    pGVar3 = __get_dashboard_state();
    if (*(char *)pGVar3 != '\x01') {
      return 0;
    }
    uVar12 = sys_clock_tick_get();
    lVar2 = (uVar12 & 0xffffffff) * 1000;
    uVar6 = (int)(uVar12 >> 0x20) * 1000 + (int)((ulonglong)lVar2 >> 0x20);
    uVar13 = FUN_000809b6((uint)lVar2 >> 0xf | uVar6 * 0x20000,uVar6 >> 0xf,DAT_20004dd8,
                          DAT_20004ddc);
    if ((int)((ulonglong)uVar13 >> 0x20) < (int)(uint)((uint)uVar13 < 0x3e9)) {
      return 0;
    }
    DAT_20004dd2 = DAT_20004dd2 + 1;
    uVar12 = sys_clock_tick_get();
    lVar2 = (uVar12 & 0xffffffff) * 1000;
    uVar6 = (int)(uVar12 >> 0x20) * 1000 + (int)((ulonglong)lVar2 >> 0x20);
    DAT_20004dd8 = (uint)lVar2 >> 0xf | uVar6 * 0x20000;
    DAT_20004ddc = uVar6 >> 0xf;
    if (DAT_20004dd2 < 0x14) {
      return 0;
    }
    pGVar3 = __get_dashboard_state();
    **(undefined1 **)&pGVar3->field_0x1014 = 0;
  }
  FUN_00030458();
  return 0;
}


