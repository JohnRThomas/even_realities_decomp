/*
 * Function: $_wr_lum_reg
 * Entry:    00080d5e
 * Prototype: void __stdcall $_wr_lum_reg(uint16_t param)
 */


void __wr_lum_reg(uint16_t param)

{
  undefined4 in_r1;
  ushort local_c;
  undefined2 uStack_a;
  
  _local_c = CONCAT22((short)((uint)in_r1 >> 0x10),param << 8 | param >> 8);
  spi_tx_frame(SPI_WR_LUM_REG,&local_c,2);
  return;
}


