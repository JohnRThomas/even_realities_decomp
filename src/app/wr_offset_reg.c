/*
 * Function: $_wr_offset_reg
 * Entry:    00080d20
 * Prototype: void __stdcall $_wr_offset_reg(uint8_t row, uint8_t col)
 */


void __wr_offset_reg(uint8_t row,uint8_t col)

{
  undefined4 local_c;
  
  local_c = (uint)CONCAT11(col,row);
  spi_tx_frame(SPI_WR_OFFSET_REG,&local_c,2);
  __send_cmd(SPI_SYNC);
  delay_ms(1);
  return;
}


