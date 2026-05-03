/*
 * Function: power_down_panel
 * Entry:    0001607c
 * Prototype: undefined4 __stdcall power_down_panel(void)
 */


undefined4 power_down_panel(void)

{
  nrfx_err_t nVar1;
  char *fmt;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 uVar2;
  undefined4 extraout_r2_01;
  
  sleep(2);
  panel_gpio_disable();
  if (0 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): turn off -2v for panel.\n");
    }
    else {
      ble_printk("%s(): turn off -2v for panel.\n","power_down_panel",extraout_r2,BLE_DEBUG);
    }
  }
  sleep(16);
  nVar1 = nrfx_gpiote_channel_get(0x8b430,&Reset);
  if ((int)nVar1 < 0) {
    if (LOG_LEVEL < 1) {
      return 0;
    }
    fmt = "%s(): Could not set buck2.\n";
    uVar2 = extraout_r2_00;
  }
  else {
    if (0 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): disable buck2 1.2v\n");
      }
      else {
        ble_printk("%s(): disable buck2 1.2v\n","power_down_panel",extraout_r2_00,BLE_DEBUG);
      }
    }
    sleep(5);
    nVar1 = nrfx_gpiote_channel_get(0x8b430,&NMI);
    uVar2 = extraout_r2_01;
    if ((int)nVar1 < 0) {
      if (LOG_LEVEL < 1) {
        return 0;
      }
      fmt = "%s(): Could not set ldsw1.\n";
    }
    else {
      if (LOG_LEVEL < 1) {
        return 0;
      }
      fmt = "%s(): disable ldsw1 1.8v for panel\n";
    }
  }
  if (BLE_DEBUG == 0) {
    printk(fmt);
  }
  else {
    ble_printk(fmt,"power_down_panel",uVar2,BLE_DEBUG);
  }
  return 0;
}


