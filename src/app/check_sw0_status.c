/*
 * Function: check_sw0_status
 * Entry:    0002ca94
 * Prototype: undefined __stdcall check_sw0_status(void)
 */


void check_sw0_status(void)

{
  int iVar1;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 uVar2;
  undefined4 extraout_r2_01;
  
  iVar1 = gpio_pin_get_config();
  if (iVar1 == 0) {
    uVar2 = extraout_r2;
    if (1 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): interrupt line low!!!\n");
        uVar2 = extraout_r2_01;
      }
      else {
        ble_printk("%s(): interrupt line low!!!\n","check_sw0_status",extraout_r2,BLE_DEBUG);
        uVar2 = extraout_r2_00;
      }
    }
    DAT_200084d0 = DAT_200084d0 + 1;
    if (3 < DAT_200084d0) {
      if (1 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): interrupt line abnormal, now reset\n");
        }
        else {
          ble_printk("%s(): interrupt line abnormal, now reset\n","check_sw0_status",uVar2,BLE_DEBUG
                    );
        }
      }
      aw93203_init();
      return;
    }
  }
  else {
    DAT_200084d0 = 0;
  }
  return;
}


