/*
 * Function: gui_area_clear
 * Entry:    00045364
 * Prototype: undefined4 __stdcall gui_area_clear(int param_1, int param_2, int param_3, int param_4)
 */


undefined4 gui_area_clear(int param_1,int param_2,int param_3,int param_4)

{
  jbd_panel_context *pjVar1;
  undefined4 uVar2;
  GlassesState *pGVar3;
  uint32_t uVar4;
  
  if (2 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): exec area clear command....\n","gui_area_clear",param_3,0,param_1,param_2);
    }
    else {
      ble_printk("%s(): exec area clear command....\n");
    }
  }
  pjVar1 = get_jdb_panel_context();
  if (pjVar1->init_done == 0) {
    if (0 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): c->init_done = 0,init failed, can\'t write data!\n","gui_area_clear");
      }
      else {
        ble_printk("%s(): c->init_done = 0,init failed, can\'t write data!\n");
      }
    }
    uVar2 = 0xffffffff;
  }
  else {
    pGVar3 = __get_dashboard_state();
    _clean_fb_data((byte *)&(pGVar3->jdb_panel_context).__panel_buffer,0,param_1,param_2,param_3,
                   param_4);
    pGVar3 = __get_dashboard_state();
    uVar4 = (pGVar3->jdb_panel_context).current_row;
    pGVar3 = __get_dashboard_state();
    _reflash_fb_data_to_lcd
              (uVar4,(pGVar3->jdb_panel_context).current_column,param_1,param_2,param_3,param_4);
    uVar2 = 0;
  }
  return uVar2;
}


