/*
 * Function: set_brightness_to_panel_reg
 * Entry:    0004a830
 * Prototype: undefined __stdcall set_brightness_to_panel_reg(uint param_1, uint param_2)
 */


void set_brightness_to_panel_reg(uint param_1,uint param_2)

{
  undefined4 uStack_c;
  
  uStack_c = param_2;
  if (2 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): set brightness level = %d\n","set_brightness_to_panel_reg",param_1,0,param_1);
    }
    else {
      ble_printk("%s(): set brightness level = %d\n");
    }
  }
  __update_brightness_level_for_jdb_panel
            (param_1,(uint16_t *)((int)&uStack_c + 2),(uint8_t *)((int)&uStack_c + 1));
  __send_cmd(SPI_WR_ENABLE);
  __send_cmd(SPI_DISPLAY_DISABLE);
  __wr_lum_reg(uStack_c._2_2_);
  __wr_cur_reg(uStack_c._1_1_);
  __wr_status_reg(SPI_WR_STATUS_REG2,'\x04');
  __send_cmd(SPI_DISPLAY_ENABLE);
  __send_cmd(SPI_SYNC);
  delay_ms(1);
  return;
}


