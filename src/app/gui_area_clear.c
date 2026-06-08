/*
 * Function: gui_area_clear
 * Entry:    00045364
 * Prototype: undefined4 __stdcall gui_area_clear(int param_1, int param_2, int param_3, int param_4)
 */


/* WARNING: Struct "GlassesState": ignoring multiple overlapping fields */

undefined4 gui_area_clear(int param_1,int param_2,int param_3,int param_4)

{
  jdb_panel_context *pjVar1;
  undefined4 uVar2;
  GlassesState *pGVar3;
  undefined4 extraout_r2;
  int iVar4;
  
  if (2 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): exec area clear command....\n");
    }
    else {
      ble_printk("%s(): exec area clear command....\n","gui_area_clear",param_3,BLE_DEBUG);
    }
  }
  pjVar1 = get_jdb_panel_context();
  if (pjVar1->__initialized == 0) {
    if (0 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): c->init_done = 0,init failed, can\'t write data!\n");
      }
      else {
        ble_printk("%s(): c->init_done = 0,init failed, can\'t write data!\n","gui_area_clear",
                   extraout_r2,BLE_DEBUG);
      }
    }
    uVar2 = 0xffffffff;
  }
  else {
    pGVar3 = __get_dashboard_state();
    _clean_fb_data(&(pGVar3->jdb_panel_context).field9_0x24,0,param_1,param_2,param_3,param_4);
    pGVar3 = __get_dashboard_state();
    iVar4 = *(int *)&(pGVar3->jdb_panel_context).field_0x348;
    pGVar3 = __get_dashboard_state();
    _reflash_fb_data_to_lcd
              (iVar4,*(int *)&(pGVar3->jdb_panel_context).field_0x34c,param_1,param_2,param_3,
               param_4);
    uVar2 = 0;
  }
  return uVar2;
}


