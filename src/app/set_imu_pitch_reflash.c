/*
 * Function: set_imu_pitch_reflash
 * Entry:    00049180
 * Prototype: undefined4 __stdcall set_imu_pitch_reflash(void)
 */


undefined4 set_imu_pitch_reflash(void)

{
  ushort uVar1;
  ushort uVar2;
  GlassesState *pGVar3;
  undefined4 uVar4;
  int iVar5;
  char *pcVar6;
  int iVar7;
  uint string_id;
  undefined4 extraout_r1;
  undefined4 extraout_r2;
  
  pGVar3 = __get_dashboard_state();
  if ((byte)pGVar3->field20_0xc8[0x28] < 2) {
    if ((uint)DAT_2001dd03 != (uint)(byte)pGVar3->field20_0xc8[0x28]) {
      gui_screen_clear(pGVar3,extraout_r1,(uint)DAT_2001dd03);
      DAT_2001dd03 = pGVar3->field20_0xc8[0x28];
    }
    if (pGVar3->field20_0xc8[0x28] == '\x01') {
      iVar5 = FUN_000809e2();
      uVar1 = FUN_00080a3a();
      gui_bmp_bitmap_draw(0x87,iVar5 + 0x52,uVar1 + 0x65,0,0,0);
      pcVar6 = get_string(4);
      iVar5 = FUN_000809e2();
      uVar1 = FUN_00080a3a();
      iVar7 = FUN_000809e2();
      uVar2 = FUN_00080a3a();
      gui_utf_draw_middle(0,pcVar6,0,iVar5,uVar1 + 0x3c,iVar7 + 0x240,uVar2 + 0x57,1,0,0,
                          (undefined *)0x0,0);
      string_id = 5;
    }
    else {
      iVar5 = FUN_000809e2();
      uVar1 = FUN_00080a3a();
      gui_bmp_bitmap_draw(0x87,iVar5 + 0x52,uVar1 + 0x65,0,0,0);
      pcVar6 = get_string(2);
      iVar5 = FUN_000809e2();
      uVar1 = FUN_00080a3a();
      iVar7 = FUN_000809e2();
      uVar2 = FUN_00080a3a();
      gui_utf_draw_middle(0,pcVar6,0,iVar5,uVar1 + 0x3c,iVar7 + 0x240,uVar2 + 0x57,1,0,0,
                          (undefined *)0x0,0);
      string_id = 3;
    }
    pcVar6 = get_string(string_id);
    iVar5 = FUN_000809e2();
    uVar1 = FUN_00080a3a();
    iVar7 = FUN_000809e2();
    uVar2 = FUN_00080a3a();
    gui_utf_draw_middle(0,pcVar6,0,iVar5,uVar1 + 0x71,iVar7 + 0x240,uVar2 + 0x8c,1,0,0,
                        (undefined *)0x0,0);
    uVar4 = 0;
  }
  else {
    if (0 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): set_imu_pitch:horiz_step over E_IMU_PITCH_STEP_MAX\n");
      }
      else {
        ble_printk("%s(): set_imu_pitch:horiz_step over E_IMU_PITCH_STEP_MAX\n",
                   "set_imu_pitch_reflash",extraout_r2,BLE_DEBUG);
      }
    }
    uVar4 = 0xffffffff;
  }
  return uVar4;
}


