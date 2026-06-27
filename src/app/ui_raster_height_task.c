/*
 * Function: ui_raster_height_task
 * Entry:    000451ec
 * Prototype: undefined4 __stdcall ui_raster_height_task(int param_1, undefined4 param_2, int param_3)
 */


undefined4 ui_raster_height_task(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 extraout_r0;
  GlassesState *pGVar2;
  undefined4 extraout_r0_00;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  int extraout_r2;
  int extraout_r2_00;
  int iVar3;
  int extraout_r2_01;
  undefined8 uVar4;
  int local_20;
  int local_1c;
  
  local_20 = -1;
  local_1c = -1;
  if (param_3 == 2) {
    if (2 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): ui_raster_height_task exit...\n");
      }
      else {
        ble_printk("%s(): ui_raster_height_task exit...\n","ui_raster_height_task",2,BLE_DEBUG);
      }
    }
    __ui_DashBoard_task(param_1,param_2,2);
    DAT_20002560 = -1;
    DAT_2000255c = -1;
  }
  else {
    uVar4 = cal_panel_canvas_coord(&local_20,&local_1c);
    iVar1 = local_20;
    iVar3 = extraout_r2;
    if ((local_20 != DAT_20002560) || (iVar3 = local_1c, local_1c != DAT_2000255c)) {
      if (2 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): ui_raster_height_task reflash...\n");
          uVar4 = CONCAT44(extraout_r1_00,extraout_r0_00);
          iVar3 = extraout_r2_01;
        }
        else {
          ble_printk("%s(): ui_raster_height_task reflash...\n","ui_raster_height_task",iVar3,
                     BLE_DEBUG);
          uVar4 = CONCAT44(extraout_r1,extraout_r0);
          iVar3 = extraout_r2_00;
        }
      }
      gui_screen_clear((int)uVar4,(int)((ulonglong)uVar4 >> 0x20),iVar3);
      FUN_0003cc54();
      iVar3 = local_1c;
      DAT_20002560 = iVar1;
      DAT_2000255c = local_1c;
      pGVar2 = __get_dashboard_state();
      *(int *)&(pGVar2->jdb_panel_context).field_0x358 = iVar1;
      pGVar2 = __get_dashboard_state();
      *(int *)&(pGVar2->jdb_panel_context).field_0x34c = iVar3;
      pGVar2 = __get_dashboard_state();
      pGVar2->glasses_state_struct_0FF0->field_0x73 = 1;
      __ui_DashBoard_task(param_1,param_2,1);
      pGVar2 = __get_dashboard_state();
      *(undefined4 *)&pGVar2->field_0x1060 = 0x26;
      pGVar2 = __get_dashboard_state();
      k_sem_give(&pGVar2->sem_6);
    }
  }
  return 0;
}


