/*
 * Function: ui_raster_height_task
 * Entry:    000451ec
 * Prototype: undefined4 __stdcall ui_raster_height_task(int param_1, undefined4 param_2, int param_3)
 */


undefined4 ui_raster_height_task(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  GlassesState *pGVar3;
  int horizontal_offset;
  int vertical_offset;
  
  horizontal_offset = -1;
  vertical_offset = -1;
  if (param_3 == 2) {
    if (2 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): ui_raster_height_task exit...\n","ui_raster_height_task");
      }
      else {
        ble_printk("%s(): ui_raster_height_task exit...\n");
      }
    }
    __ui_DashBoard_task(param_1,param_2,2);
    CURRENT_HORIZONTAL_OFFSET = -1;
    CURRENT_VERTICAL_OFFSET = -1;
  }
  else {
    cal_panel_canvas_coord(&horizontal_offset,&vertical_offset);
    iVar1 = horizontal_offset;
    if ((horizontal_offset != CURRENT_HORIZONTAL_OFFSET) ||
       (vertical_offset != CURRENT_VERTICAL_OFFSET)) {
      if (2 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): ui_raster_height_task reflash...\n","ui_raster_height_task");
        }
        else {
          ble_printk("%s(): ui_raster_height_task reflash...\n");
        }
      }
      gui_screen_clear();
      __set_screen_cleared();
      iVar2 = vertical_offset;
      CURRENT_HORIZONTAL_OFFSET = iVar1;
      CURRENT_VERTICAL_OFFSET = vertical_offset;
      pGVar3 = __get_dashboard_state();
      *(int *)&(pGVar3->jdb_panel_context).field_0x358 = iVar1;
      pGVar3 = __get_dashboard_state();
      (pGVar3->jdb_panel_context).current_column = iVar2;
      pGVar3 = __get_dashboard_state();
      pGVar3->dashboard_ts->field_0x73 = 1;
      __ui_DashBoard_task(param_1,param_2,1);
      pGVar3 = __get_dashboard_state();
      *(undefined4 *)&pGVar3->field_0x1060 = 0x26;
      pGVar3 = __get_dashboard_state();
      k_sem_give(&pGVar3->dashboard_position_sem);
    }
  }
  return 0;
}


