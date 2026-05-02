/*
 * Function: check_sw0_status
 * Entry:    0002ca94
 * Prototype: undefined __stdcall check_sw0_status(void)
 */


void check_sw0_status(void)

{
  undefined4 extraout_r0;
  undefined4 extraout_r0_00;
  undefined4 uVar1;
  undefined4 extraout_r0_01;
  undefined4 extraout_r0_02;
  printbuffer *extraout_r1;
  printbuffer *extraout_r1_00;
  printbuffer *ppVar2;
  printbuffer *extraout_r1_01;
  printbuffer *extraout_r1_02;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 uVar3;
  undefined4 extraout_r2_01;
  undefined8 uVar4;
  
  uVar4 = gpio_pin_get_config();
  ppVar2 = (printbuffer *)((ulonglong)uVar4 >> 0x20);
  if ((int)uVar4 == 0) {
    uVar1 = 0;
    uVar3 = extraout_r2;
    if (1 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): interrupt line low!!!\n");
        uVar1 = extraout_r0_01;
        ppVar2 = extraout_r1_01;
        uVar3 = extraout_r2_01;
      }
      else {
        ble_printk("%s(): interrupt line low!!!\n","check_sw0_status",extraout_r2,BLE_DEBUG);
        uVar1 = extraout_r0;
        ppVar2 = extraout_r1;
        uVar3 = extraout_r2_00;
      }
    }
    DAT_200084d0 = DAT_200084d0 + 1;
    if (3 < DAT_200084d0) {
      if (1 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): interrupt line abnormal, now reset\n");
          uVar1 = extraout_r0_02;
          ppVar2 = extraout_r1_02;
        }
        else {
          ble_printk("%s(): interrupt line abnormal, now reset\n","check_sw0_status",uVar3,BLE_DEBUG
                    );
          uVar1 = extraout_r0_00;
          ppVar2 = extraout_r1_00;
        }
      }
      FUN_00032130(uVar1,ppVar2);
      return;
    }
  }
  else {
    DAT_200084d0 = 0;
  }
  return;
}


