/*
 * Function: $_wr_status_reg
 * Entry:    00080d0a
 * Prototype: void __stdcall $_wr_status_reg(JBD013VGA_SPI regAddr, uint8_t data)
 */


void __wr_status_reg(JBD013VGA_SPI regAddr,uint8_t data)

{
  undefined1 local_9 [5];
  
  spi_tx_frame(regAddr,local_9,1);
  return;
}


