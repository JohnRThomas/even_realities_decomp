/*
 * Function: ui_prompt_info_task
 * Entry:    00049508
 * Prototype: undefined4 __stdcall ui_prompt_info_task(int param_1, undefined4 param_2, int param_3)
 */


/* WARNING: Struct "GlassesState": ignoring multiple overlapping fields */

undefined4 ui_prompt_info_task(int param_1,undefined4 param_2,int param_3)

{
  byte bVar1;
  longlong lVar2;
  char cVar3;
  undefined4 uVar4;
  GlassesState *pGVar5;
  global_state_struct_1028 *pgVar6;
  undefined4 extraout_r0;
  undefined4 extraout_r0_00;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  uint uVar7;
  undefined4 extraout_r1_01;
  undefined4 uVar8;
  undefined4 extraout_r1_02;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 uVar9;
  undefined4 extraout_r2_02;
  int iVar10;
  int iVar11;
  int iVar12;
  ulonglong uVar13;
  byte local_30 [12];
  
  __get_dashboard_state();
  FUN_000452f0(param_1 + 0x24);
  uVar4 = FUN_0004540c();
  if ((char)DAT_2001dd04 == '\0') {
    if (param_3 == 1) {
      cVar3 = DAT_2001dd04._1_1_;
      if (DAT_2001dd04._1_1_ != '\0') {
        return 0;
      }
      uVar4 = FUN_000809d0();
      gui_screen_clear(uVar4,extraout_r1_00,extraout_r2_00);
      FUN_00045834();
      DAT_2001dd04._0_1_ = cVar3;
      DAT_2001dd04._1_1_ = 1;
      uVar13 = sys_clock_tick_get();
      pGVar5 = __get_dashboard_state();
      lVar2 = (uVar13 & 0xffffffff) * 1000;
      uVar7 = (int)(uVar13 >> 0x20) * 1000 + (int)((ulonglong)lVar2 >> 0x20);
      pgVar6 = pGVar5->field_global_state_struct_1028;
      *(uint *)((int)&pgVar6->field0_0x0 + 2) = (uint)lVar2 >> 0xf | uVar7 * 0x20000;
      *(uint *)((int)&pgVar6->field1_0x4 + 2) = uVar7 >> 0xf;
      FUN_00045444();
      DAT_2001dd04 = CONCAT11(DAT_2001dd04._1_1_,1);
      FUN_00045428();
      iVar11 = 0;
      do {
        prompt_info_reflash();
        uVar7 = 0;
        do {
          iVar10 = 0;
          do {
            iVar12 = *(int *)(param_1 + 0x24 + uVar7 * 4);
            bVar1 = *(byte *)(iVar12 + iVar10);
            local_30[0] = 1;
            local_30[1] = 2;
            local_30[2] = 3;
            local_30[3] = 4;
            local_30[4] = 5;
            local_30[5] = 6;
            local_30[6] = 7;
            local_30[7] = 7;
            if (bVar1 != 0) {
              *(byte *)(iVar12 + iVar10) =
                   bVar1 & (&DAT_000accab)
                           [iVar10 + (uint)local_30[iVar11] * 0x140 + (uVar7 % 0x1a) * 0xa00];
            }
            iVar10 = iVar10 + 1;
          } while (iVar10 != 0x140);
          uVar7 = uVar7 + 1;
        } while (uVar7 != 199);
        pGVar5 = __get_dashboard_state();
        iVar10 = *(int *)&(pGVar5->jdb_panel_context).field_0x348;
        pGVar5 = __get_dashboard_state();
        iVar11 = iVar11 + 1;
        _reflash_fb_data_to_lcd
                  (iVar10,*(int *)&(pGVar5->jdb_panel_context).field_0x34c,0,0,0x280,199);
      } while (iVar11 != 8);
      FUN_0004540c();
      return 0;
    }
    if (param_3 != 2) {
      return 0;
    }
    uVar8 = extraout_r1;
    uVar9 = extraout_r2;
    if (2 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): set_imu_pitch process received exit packet ...\n");
        uVar4 = extraout_r0_00;
        uVar8 = extraout_r1_02;
        uVar9 = extraout_r2_02;
      }
      else {
        ble_printk("%s(): set_imu_pitch process received exit packet ...\n","ui_prompt_info_task",
                   extraout_r2,BLE_DEBUG);
        uVar4 = extraout_r0;
        uVar8 = extraout_r1_01;
        uVar9 = extraout_r2_01;
      }
    }
    gui_screen_clear(uVar4,uVar8,uVar9);
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
        printk("%s(): set_imu_pitch process received exit packet ...\n");
      }
      else {
        ble_printk("%s(): set_imu_pitch process received exit packet ...\n","ui_prompt_info_task",
                   extraout_r2,BLE_DEBUG);
      }
    }
    FUN_00045968();
  }
  FUN_000809d0();
  DAT_2001dd04 = 0;
  return 0;
}


