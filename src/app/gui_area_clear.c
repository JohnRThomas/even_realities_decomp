/*
 * Function: gui_area_clear
 * Entry:    00045364
 * Prototype: undefined4 __stdcall gui_area_clear(int param_1, int param_2, int param_3, int param_4)
 */


undefined4 gui_area_clear(int param_1,int param_2,int param_3,int param_4)

{
  undefined1 *puVar1;
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
  puVar1 = __get_something_from_glasses_state();
  if (*(int *)(puVar1 + 0x35c) == 0) {
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
    _clean_fb_data((int)&pGVar3->field_0xb90,0,param_1,param_2,param_3,param_4);
    pGVar3 = __get_dashboard_state();
    iVar4 = *(int *)&pGVar3->field_0xeb4;
    pGVar3 = __get_dashboard_state();
    _reflash_fb_data_to_lcd(iVar4,*(int *)&pGVar3->field_0xeb8,param_1,param_2,param_3,param_4);
    uVar2 = 0;
  }
  return uVar2;
}


