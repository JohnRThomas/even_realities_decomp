/*
 * Function: erase_audio_buffer
 * Entry:    000304a8
 * Prototype: int __stdcall erase_audio_buffer(void)
 */


int erase_audio_buffer(void)

{
  int iVar1;
  
  iVar1 = qspi_nor_erase((device *)&PTR_s_mx25r6435f_0_0008b3a0,0x400000,0x10000);
  if (iVar1 == 0) {
    DAT_20002404 = 0x400000;
    if (2 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): Flash erase ok \n\n");
      }
      else {
        ble_printk("%s(): Flash erase ok \n\n","erase_audio_buffer",&DAT_20002404,BLE_DEBUG);
      }
    }
  }
  else if (0 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): Flash erase failed! %d\n\n");
    }
    else {
      ble_printk("%s(): Flash erase failed! %d\n\n","erase_audio_buffer",iVar1,BLE_DEBUG);
    }
  }
  return iVar1;
}


