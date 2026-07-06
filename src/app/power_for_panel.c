/*
 * Function: power_for_panel
 * Entry:    00015e94
 * Prototype: undefined4 __stdcall power_for_panel(void)
 */


undefined4 power_for_panel(void)

{
  int iVar1;
  char *pcVar2;
  
  iVar1 = i2c_write_dt((i2c_dt_spec *)&PTR_s_pmic_6b_0008b430,&NMI,0);
  if (iVar1 < 0) {
    if (LOG_LEVEL < 1) {
      return 0;
    }
    pcVar2 = "%s(): Could not set ldsw1.\n";
    goto LAB_00015eba;
  }
  if (0 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): enable ldsw1 1.8v for panel\n","power_for_panel");
    }
    else {
      ble_printk("%s(): enable ldsw1 1.8v for panel\n");
    }
  }
  sleep(1);
  if ((GLOBAL_STATE->jdb_panel_context).field_0x368 == '\x01') {
    iVar1 = i2c_write_dt((i2c_dt_spec *)&PTR_s_pmic_6b_0008b430,&Reset,10);
    if (iVar1 < 0) {
      if (LOG_LEVEL < 1) {
        return 0;
      }
      pcVar2 = "%s(): Could not set buck2 to 1.1v.\n";
      goto LAB_00015eba;
    }
    if (0 < LOG_LEVEL) {
      pcVar2 = "%s(): set buck2 to 1.1v\n";
LAB_00015f22:
      if (BLE_DEBUG == 0) {
        printk(pcVar2,"power_for_panel");
      }
      else {
        ble_printk(pcVar2);
      }
    }
  }
  else {
    iVar1 = i2c_write_dt((i2c_dt_spec *)&PTR_s_pmic_6b_0008b430,&Reset,10);
    if (iVar1 < 0) {
      if (LOG_LEVEL < 1) {
        return 0;
      }
      pcVar2 = "%s(): Could not set buck2 to 1.2v.\n";
      goto LAB_00015eba;
    }
    if (0 < LOG_LEVEL) {
      pcVar2 = "%s(): set buck2 to 1.2v\n";
      goto LAB_00015f22;
    }
  }
  iVar1 = mfd_npm1300_reg_update((device *)&PTR_s_pmic_6b_0008b430,4,0xf,2,2);
  if (iVar1 < 0) {
    if (LOG_LEVEL < 1) {
      return 0;
    }
    pcVar2 = "%s(): Could not enable software control\n";
  }
  else {
    iVar1 = i2c_write_dt((i2c_dt_spec *)&PTR_s_pmic_6b_0008b430,&Reset,2);
    if (iVar1 < 0) {
      if (LOG_LEVEL < 1) {
        return 0;
      }
      pcVar2 = "%s(): Could not set buck2.\n";
    }
    else {
      if (0 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): enable buck2.\n","power_for_panel");
        }
        else {
          ble_printk("%s(): enable buck2.\n");
        }
      }
      sleep(1);
      panel_gpio_enable();
      sleep(0xf);
      if (LOG_LEVEL < 1) {
        return 0;
      }
      pcVar2 = "%s(): turn on -2v for panel.\n";
    }
  }
LAB_00015eba:
  if (BLE_DEBUG == 0) {
    printk(pcVar2,"power_for_panel");
  }
  else {
    ble_printk(pcVar2);
  }
  return 0;
}


