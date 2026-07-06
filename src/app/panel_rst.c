/*
 * Function: $_panel_rst
 * Entry:    00080e16
 * Prototype: undefined __stdcall $_panel_rst(void)
 */


void __panel_rst(void)

{
  delay_ms(1);
  __send_cmd(SPI_RST_EN);
  delay_ms(1);
  __send_cmd(SPI_RST);
  delay_ms(10);
  return;
}


