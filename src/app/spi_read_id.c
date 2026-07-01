/*
 * Function: spi_read_id
 * Entry:    0004afdc
 * Prototype: ushort __stdcall spi_read_id(undefined4 param_1, undefined4 param_2, undefined4 param_3)
 */


ushort spi_read_id(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  jdb_panel_context *pjVar1;
  undefined4 local_10;
  undefined4 local_c;
  
  local_c = 0;
  local_10 = param_3;
  pjVar1 = get_jdb_panel_context();
  local_10 = 0x9f;
  __lock_lcd_mutex(-1);
  (*(code *)pjVar1->spi_callbacks->rx_tx)(pjVar1->spi_callbacks,&local_10,4,&local_c,4,param_2);
  __unlock_lcd_mutex();
  if (2 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): jbd panel devicve id: %02x, %02x, %02x, %02x\n");
    }
    else {
      ble_printk("%s(): jbd panel devicve id: %02x, %02x, %02x, %02x\n","spi_read_id",local_c & 0xff
                 ,local_c >> 8 & 0xff,local_c >> 0x10 & 0xff,local_c >> 0x18);
    }
  }
  return local_c._2_2_ << 8 | local_c._2_2_ >> 8;
}


