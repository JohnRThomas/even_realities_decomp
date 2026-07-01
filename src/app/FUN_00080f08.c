/*
 * Function: FUN_00080f08
 * Entry:    00080f08
 * Prototype: undefined __stdcall FUN_00080f08(int param_1, uint param_2)
 */


void FUN_00080f08(int param_1,uint param_2)

{
  jdb_panel_context *pjVar1;
  int iVar2;
  undefined1 local_24 [8];
  
  pjVar1 = get_jdb_panel_context();
  local_24[0] = 0;
  iVar2 = param_1 + (param_2 / 0xf000) * 0xf000;
  for (; param_1 != iVar2; param_1 = param_1 + 0xf000) {
    __lock_lcd_mutex(-1);
    (*(code *)pjVar1->spi_callbacks->rx_tx)(pjVar1->spi_callbacks,param_1,0xf000,local_24,1);
    __unlock_lcd_mutex();
  }
  __lock_lcd_mutex(-1);
  (*(code *)pjVar1->spi_callbacks->rx_tx)(pjVar1->spi_callbacks,param_1,param_2 % 0xf000,local_24,1)
  ;
  __unlock_lcd_mutex();
  return;
}


