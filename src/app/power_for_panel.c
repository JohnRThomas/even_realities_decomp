/*
 * Function: power_for_panel
 * Entry:    00015e94
 * Prototype: undefined4 __stdcall power_for_panel(void)
 */


/* WARNING: Struct "GlassesState": ignoring multiple overlapping fields */

undefined4 power_for_panel(void)

{
  int iVar1;
  char *pcVar2;
  undefined4 extraout_r2;
  undefined4 uVar3;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 extraout_r2_02;
  undefined4 extraout_r2_03;
  undefined4 extraout_r2_04;
  
  iVar1 = i2c_write_dt((i2c_dt_spec *)&PTR_s_pmic_6b_0008b430,&NMI,0);
  if (iVar1 < 0) {
    if (LOG_LEVEL < 1) {
      return 0;
    }
    pcVar2 = "%s(): Could not set ldsw1.\n";
    uVar3 = extraout_r2;
    goto LAB_00015eba;
  }
  if (0 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): enable ldsw1 1.8v for panel\n");
    }
    else {
      ble_printk("%s(): enable ldsw1 1.8v for panel\n","power_for_panel",extraout_r2,BLE_DEBUG);
    }
  }
  sleep(1);
  if (*(char *)(GLOBAL_STATE._0_4_ + 0xed4) == '\x01') {
    iVar1 = i2c_write_dt((i2c_dt_spec *)&PTR_s_pmic_6b_0008b430,&Reset,10);
    if (iVar1 < 0) {
      if (LOG_LEVEL < 1) {
        return 0;
      }
      pcVar2 = "%s(): Could not set buck2 to 1.1v.\n";
      uVar3 = extraout_r2_00;
      goto LAB_00015eba;
    }
    if (0 < LOG_LEVEL) {
      pcVar2 = "%s(): set buck2 to 1.1v\n";
      uVar3 = extraout_r2_00;
LAB_00015f22:
      if (BLE_DEBUG == 0) {
        printk(pcVar2);
      }
      else {
        ble_printk(pcVar2,"power_for_panel",uVar3,BLE_DEBUG);
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
      uVar3 = extraout_r2_02;
      goto LAB_00015eba;
    }
    if (0 < LOG_LEVEL) {
      pcVar2 = "%s(): set buck2 to 1.2v\n";
      uVar3 = extraout_r2_02;
      goto LAB_00015f22;
    }
  }
  iVar1 = mfd_npm1300_reg_update((device *)&PTR_s_pmic_6b_0008b430,4,0xf,2,2);
  if (iVar1 < 0) {
    if (LOG_LEVEL < 1) {
      return 0;
    }
    pcVar2 = "%s(): Could not enable software control\n";
    uVar3 = extraout_r2_01;
  }
  else {
    iVar1 = i2c_write_dt((i2c_dt_spec *)&PTR_s_pmic_6b_0008b430,&Reset,2);
    if (iVar1 < 0) {
      if (LOG_LEVEL < 1) {
        return 0;
      }
      pcVar2 = "%s(): Could not set buck2.\n";
      uVar3 = extraout_r2_03;
    }
    else {
      if (0 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): enable buck2.\n");
        }
        else {
          ble_printk("%s(): enable buck2.\n","power_for_panel",extraout_r2_03,BLE_DEBUG);
        }
      }
      sleep(1);
      panel_gpio_enable();
      sleep(0xf);
      if (LOG_LEVEL < 1) {
        return 0;
      }
      pcVar2 = "%s(): turn on -2v for panel.\n";
      uVar3 = extraout_r2_04;
    }
  }
LAB_00015eba:
  if (BLE_DEBUG == 0) {
    printk(pcVar2);
  }
  else {
    ble_printk(pcVar2,"power_for_panel",uVar3,BLE_DEBUG);
  }
  return 0;
}


