/*
 * Function: display_image
 * Entry:    00080dd2
 * Prototype: void __stdcall display_image(uint16_t row, uint16_t col, uint8_t * pBuf, uint32_t len)
 */


void display_image(uint16_t row,uint16_t col,uint8_t *pBuf,uint32_t len)

{
  for (; 0xf000 < (int)len; len = len - 61440) {
    spi_wr_buffer(row,col,pBuf,0xf000);
    col = col + 192;
  }
  spi_wr_buffer(row,col,pBuf,len);
  __send_cmd(SPI_SYNC);
  delay_ms(1);
  return;
}


