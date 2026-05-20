/*
 * Function: adc_nfc_run
 * Entry:    00026e30
 * Prototype: uint __stdcall adc_nfc_run(void)
 */


uint adc_nfc_run(void)

{
  int iVar1;
  undefined4 extraout_r2;
  uint uVar2;
  ushort local_2a;
  int local_28;
  adc_sequence aaStack_24 [2];
  ushort *local_1c;
  undefined4 local_18;
  undefined1 local_14;
  
  memset(aaStack_24,0,0x14);
  local_1c = &local_2a;
  local_18 = 2;
  aaStack_24[1] = 8;
  local_14 = 0xc;
  iVar1 = adc_nrfx_read((device *)&adc_nfc_device,aaStack_24);
  if (iVar1 < 0) {
    if (0 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): Could not read (%d)\n\n");
      }
      else {
        ble_printk("%s(): Could not read (%d)\n\n","adc_nfc_run",iVar1,BLE_DEBUG);
      }
    }
  }
  else {
    uVar2 = (uint)local_2a;
    local_28 = uVar2 * 600;
    iVar1 = adc_raw_to_millivolts_dt(ADC_GAIN_1_6,&local_28);
    if (iVar1 == 0) {
      uVar2 = local_28 >> 0xc;
    }
    else if (iVar1 < 0) {
      if (LOG_LEVEL < 1) {
        return 0;
      }
      if (BLE_DEBUG != 0) {
        ble_printk("%s():  (value in mV not available)\n\n","adc_nfc_run",extraout_r2,BLE_DEBUG);
        return 0;
      }
      printk("%s():  (value in mV not available)\n\n");
      return 0;
    }
    if (uVar2 - 1 < 0x4af) {
      return uVar2;
    }
  }
  return 0;
}


