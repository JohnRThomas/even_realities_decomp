/*
 * Function: set_brightness_to_panel_reg_in_running
 * Entry:    0004aa30
 * Prototype: undefined __stdcall set_brightness_to_panel_reg_in_running(uint brightness_level, uint param_2)
 */


void set_brightness_to_panel_reg_in_running(uint brightness_level,uint param_2)

{
  GlassesState *pGVar1;
  undefined4 uStack_c;
  
  uStack_c = param_2;
  if (2 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): set brightness level = %d\n","set_brightness_to_panel_reg_in_running",
             brightness_level,0,brightness_level);
    }
    else {
      ble_printk("%s(): set brightness level = %d\n");
    }
  }
  pGVar1 = __get_dashboard_state();
  if ((pGVar1->jdb_panel_context).init_done != 0) {
    __update_brightness_level_for_jdb_panel
              (brightness_level,(uint16_t *)((int)&uStack_c + 2),(uint8_t *)((int)&uStack_c + 1));
    __send_cmd(SPI_WR_ENABLE);
    __send_cmd(SPI_DISPLAY_DISABLE);
    __wr_lum_and_cur_reg(uStack_c >> 16,uStack_c >> 8 & 0xff);
    __wr_status_reg(SPI_WR_STATUS_REG2,'\x04');
    __send_cmd(SPI_DISPLAY_ENABLE);
    __send_cmd(SPI_SYNC);
    delay_ms(1);
    return;
  }
  return;
}


