/*
 * Function: ui_set_imu_pitch_task
 * Entry:    00049304
 * Prototype: undefined4 __stdcall ui_set_imu_pitch_task(int param_1, undefined4 param_2, int param_3)
 */


undefined4 ui_set_imu_pitch_task(int param_1,undefined4 param_2,int param_3)

{
  byte bVar1;
  char cVar2;
  undefined4 uVar3;
  GlassesState *pGVar4;
  undefined4 extraout_r0;
  undefined4 extraout_r0_00;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  undefined4 uVar5;
  undefined4 extraout_r1_02;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 uVar6;
  undefined4 extraout_r2_02;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  byte local_30 [12];
  
  __get_dashboard_state();
  FUN_000452f0(param_1 + 0x24);
  uVar3 = FUN_0004540c();
  if ((char)DAT_2001dd01 == '\0') {
    if (param_3 == 1) {
      cVar2 = DAT_2001dd01._1_1_;
      if (DAT_2001dd01._1_1_ != '\0') {
        return 0;
      }
      uVar3 = FUN_000809d0();
      gui_screen_clear(uVar3,extraout_r1_00,extraout_r2_00);
      FUN_00045834();
      DAT_2001dd03 = cVar2;
      DAT_2001dd01._0_1_ = cVar2;
      DAT_2001dd01._1_1_ = 1;
      FUN_00045444();
      DAT_2001dd01 = CONCAT11(DAT_2001dd01._1_1_,1);
      FUN_00045428();
      iVar8 = 0;
      do {
        set_imu_pitch_reflash();
        uVar9 = 0;
        do {
          iVar7 = 0;
          do {
            iVar10 = *(int *)(param_1 + 0x24 + uVar9 * 4);
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
                           [iVar7 + (uint)local_30[iVar8] * 0x140 + (uVar9 % 0x1a) * 0xa00];
            }
            iVar7 = iVar7 + 1;
          } while (iVar7 != 0x140);
          uVar9 = uVar9 + 1;
        } while (uVar9 != 199);
        pGVar4 = __get_dashboard_state();
        iVar7 = *(int *)&pGVar4->field_0xeb4;
        pGVar4 = __get_dashboard_state();
        iVar8 = iVar8 + 1;
        _reflash_fb_data_to_lcd(iVar7,*(int *)&pGVar4->field_0xeb8,0,0,0x280,199);
      } while (iVar8 != 8);
      FUN_0004540c();
      return 0;
    }
    if (param_3 != 2) {
      return 0;
    }
    uVar5 = extraout_r1;
    uVar6 = extraout_r2;
    if (2 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): set_imu_pitch process received exit packet ...\n");
        uVar3 = extraout_r0_00;
        uVar5 = extraout_r1_02;
        uVar6 = extraout_r2_02;
      }
      else {
        ble_printk("%s(): set_imu_pitch process received exit packet ...\n","ui_set_imu_pitch_task",
                   extraout_r2,BLE_DEBUG);
        uVar3 = extraout_r0;
        uVar5 = extraout_r1_01;
        uVar6 = extraout_r2_01;
      }
    }
    gui_screen_clear(uVar3,uVar5,uVar6);
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
        printk("%s(): set_imu_pitch process received exit packet ...\n");
      }
      else {
        ble_printk("%s(): set_imu_pitch process received exit packet ...\n","ui_set_imu_pitch_task",
                   extraout_r2,BLE_DEBUG);
      }
    }
    FUN_00045968();
  }
  FUN_000809d0();
  DAT_2001dd03 = 0;
  DAT_2001dd01 = 0;
  return 0;
}


