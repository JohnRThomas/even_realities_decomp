/*
 * Function: $_send_cmd
 * Entry:    00080ece
 * Prototype: undefined __stdcall $_send_cmd(JBD013VGA_SPI cmd)
 */


void __send_cmd(JBD013VGA_SPI cmd)

{
  jbd_panel_context *pjVar1;
  JBD013VGA_SPI local_11 [5];
  undefined1 local_c [4];
  
  local_c[0] = 0;
  local_11[0] = cmd;
  pjVar1 = get_jdb_panel_context();
  __lock_lcd_mutex(-1);
  (*(code *)pjVar1->spi_callbacks->rx_tx)(pjVar1->spi_callbacks,local_11,1,local_c,1);
  __unlock_lcd_mutex();
  return;
}


