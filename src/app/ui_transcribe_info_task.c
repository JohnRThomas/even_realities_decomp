/*
 * Function: ui_transcribe_info_task
 * Entry:    00049804
 * Prototype: undefined4 __stdcall ui_transcribe_info_task(int param_1, undefined4 param_2, int param_3)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Struct "GlassesState": ignoring multiple overlapping fields */

undefined4 ui_transcribe_info_task(int param_1,undefined4 param_2,int param_3)

{
  byte bVar1;
  longlong lVar2;
  undefined4 uVar3;
  undefined4 extraout_r0;
  undefined4 extraout_r0_00;
  GlassesState *pGVar4;
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
  int *piVar9;
  int iVar10;
  ulonglong uVar11;
  undefined8 uVar12;
  byte local_30 [12];
  
  piVar9 = (int *)(param_1 + 0x24);
  __get_dashboard_state();
  FUN_000452f0(piVar9);
  uVar3 = FUN_0004540c();
  if (DAT_20004dc0 == '\0') {
    if (param_3 == 1) {
      if (DAT_20004dc1 != '\0') {
        return 0;
      }
      uVar3 = FUN_000809d0();
      gui_screen_clear(uVar3,extraout_r1_00,extraout_r2_00);
      FUN_00045834();
      memset(&DAT_20004dc0,0,0x10);
      FUN_00045444();
      FUN_00045428();
      iVar10 = 0;
      do {
        FUN_000496b0(piVar9,1);
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
            bVar1 = *(byte *)(piVar9[uVar6] + iVar8);
            if (bVar1 != 0) {
              *(byte *)(piVar9[uVar6] + iVar8) =
                   bVar1 & (&DAT_000accab)
                           [iVar8 + (uint)local_30[iVar10] * 0x140 + (uVar6 % 0x1a) * 0xa00];
            }
            iVar8 = iVar8 + 1;
          } while (iVar8 != 0x140);
          uVar6 = uVar6 + 1;
        } while (uVar6 != 199);
        pGVar4 = __get_dashboard_state();
        iVar8 = *(int *)&(pGVar4->jdb_panel_context).field_0x348;
        pGVar4 = __get_dashboard_state();
        iVar10 = iVar10 + 1;
        _reflash_fb_data_to_lcd
                  (iVar8,*(int *)&(pGVar4->jdb_panel_context).field_0x34c,0,0,0x280,199);
      } while (iVar10 != 8);
      FUN_0004540c();
      _DAT_20004dc0 = 0x101;
      uVar11 = sys_clock_tick_get();
      lVar2 = (uVar11 & 0xffffffff) * 1000;
      uVar6 = (int)(uVar11 >> 0x20) * 1000 + (int)((ulonglong)lVar2 >> 0x20);
      DAT_20004dc8 = (uint)lVar2 >> 0xf | uVar6 * 0x20000;
      DAT_20004dcc = uVar6 >> 0xf;
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
        uVar3 = extraout_r0_00;
        uVar5 = extraout_r1_02;
        uVar7 = extraout_r2_02;
      }
      else {
        ble_printk("%s(): set_imu_pitch process received exit packet ...\n",
                   "ui_transcribe_info_task",extraout_r2,BLE_DEBUG);
        uVar3 = extraout_r0;
        uVar5 = extraout_r1_01;
        uVar7 = extraout_r2_01;
      }
    }
    gui_screen_clear(uVar3,uVar5,uVar7);
    FUN_000809d0();
    memset(&DAT_20004dc0,0,0x10);
  }
  else {
    if (DAT_20004dc0 != '\x01') {
      return 0;
    }
    if ((param_3 == 1) || (param_3 == 0)) {
      FUN_000496b0(piVar9,param_3);
    }
    else if (param_3 == 2) {
      if (2 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): set_imu_pitch process received exit packet ...\n");
        }
        else {
          ble_printk("%s(): set_imu_pitch process received exit packet ...\n",
                     "ui_transcribe_info_task",extraout_r2,BLE_DEBUG);
        }
      }
      FUN_00045968();
      FUN_000809d0();
      memset(&DAT_20004dc0,0,0x10);
      FUN_00030458();
    }
    pGVar4 = __get_dashboard_state();
    if (*(char *)pGVar4 != '\x01') {
      return 0;
    }
    uVar11 = sys_clock_tick_get();
    lVar2 = (uVar11 & 0xffffffff) * 1000;
    uVar6 = (int)(uVar11 >> 0x20) * 1000 + (int)((ulonglong)lVar2 >> 0x20);
    uVar12 = FUN_000809b6((uint)lVar2 >> 0xf | uVar6 * 0x20000,uVar6 >> 0xf,DAT_20004dc8,
                          DAT_20004dcc);
    if ((int)((ulonglong)uVar12 >> 0x20) < (int)(uint)((uint)uVar12 < 0x3e9)) {
      return 0;
    }
    DAT_20004dc2 = DAT_20004dc2 + 1;
    uVar11 = sys_clock_tick_get();
    lVar2 = (uVar11 & 0xffffffff) * 1000;
    uVar6 = (int)(uVar11 >> 0x20) * 1000 + (int)((ulonglong)lVar2 >> 0x20);
    DAT_20004dc8 = (uint)lVar2 >> 0xf | uVar6 * 0x20000;
    DAT_20004dcc = uVar6 >> 0xf;
    if (DAT_20004dc2 < 0x1e) {
      return 0;
    }
    pGVar4 = __get_dashboard_state();
    *pGVar4->___multi_packet_data_buffer = '\0';
  }
  FUN_00030458();
  return 0;
}


