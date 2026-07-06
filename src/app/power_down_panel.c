/*
 * Function: power_down_panel
 * Entry:    0001607c
 * Prototype: undefined4 __stdcall power_down_panel(void)
 */


undefined4 power_down_panel(void)

{
  int iVar1;
  char *fmt;
  
  sleep(2);
  panel_gpio_disable();
  if (0 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): turn off -2v for panel.\n","power_down_panel");
    }
    else {
      ble_printk("%s(): turn off -2v for panel.\n");
    }
  }
  sleep(16);
  iVar1 = i2c_write_dt((i2c_dt_spec *)&PTR_s_pmic_6b_0008b430,&Reset,3);
  if (iVar1 < 0) {
    if (LOG_LEVEL < 1) {
      return 0;
    }
    fmt = "%s(): Could not set buck2.\n";
  }
  else {
    if (0 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): disable buck2 1.2v\n","power_down_panel");
      }
      else {
        ble_printk("%s(): disable buck2 1.2v\n");
      }
    }
    sleep(5);
    iVar1 = i2c_write_dt((i2c_dt_spec *)&PTR_s_pmic_6b_0008b430,&NMI,1);
    if (iVar1 < 0) {
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
    printk(fmt,"power_down_panel");
  }
  else {
    ble_printk(fmt);
  }
  return 0;
}


