/*
 * Function: panel_init
 * Entry:    00080e3a
 * Prototype: undefined __stdcall panel_init(void)
 */


void panel_init(void)

{
  __panel_rst();
  __send_cmd(SPI_WR_ENABLE);
  __wr_status_reg(SPI_WR_STATUS_REG1,16);
  __clr_cache(0);
  __wr_offset_reg(0,0);
  __wr_offset_reg(0,20);
  __wr_offset_reg(24,0);
  __wr_offset_reg(24,20);
  __wr_offset_reg(12,10);
  __send_cmd(SPI_DISPLAY_DEFAULT_MODE);
  __send_cmd(SPI_SYNC);
  delay_ms(1);
  __send_cmd(SPI_DISPLAY_RL);
  __send_cmd(SPI_SYNC);
  delay_ms(1);
  __wr_cur_reg(0xf);
  __wr_status_reg(SPI_WR_STATUS_REG2,4);
  __send_cmd(SPI_DISPLAY_ENABLE);
  __send_cmd(SPI_SYNC);
  delay_ms(1);
  return;
}


