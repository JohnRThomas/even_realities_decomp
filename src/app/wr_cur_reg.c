/*
 * Function: $_wr_cur_reg
 * Entry:    00080d46
 * Prototype: void __stdcall $_wr_cur_reg(uint8_t param)
 */


void __wr_cur_reg(uint8_t param)

{
  undefined1 local_9 [5];
  
  spi_tx_frame(SPI_WR_CURRENT_REG,local_9,1);
  return;
}


