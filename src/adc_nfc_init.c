/*
 * Function: adc_nfc_init
 * Entry:    00026db4
 * Prototype: undefined4 __stdcall adc_nfc_init(void)
 */


undefined4 adc_nfc_init(void)

{
  bool bVar1;
  int iVar2;
  
  bVar1 = z_device_is_ready(&adc_nfc_device);
  if (bVar1) {
    iVar2 = adc_nrfx_channel_setup(&adc_nfc_device,&adc_channel_cfg_0008c1da);
    if ((iVar2 < 0) && (0 < LOG_LEVEL)) {
      if (BLE_DEBUG == 0) {
        printk("%s(): Could not setup channel #%d (%d)\n\n","adc_nfc_init");
      }
      else {
        ble_printk("%s(): Could not setup channel #%d (%d)\n\n","adc_nfc_init",0,iVar2);
      }
    }
  }
  else if (0 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): ADC controller device %s not ready\n\n");
    }
    else {
      ble_printk("%s(): ADC controller device %s not ready\n\n","adc_nfc_init","adc@e000",BLE_DEBUG)
      ;
    }
  }
  return 0;
}


