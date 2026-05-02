/*
 * Function: aging_test_thread
 * Entry:    00034448
 * Prototype: undefined __stdcall aging_test_thread(undefined4 param_1, undefined4 param_2, undefined4 param_3)
 */


void aging_test_thread(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 extraout_r2;
  
  do {
    if (DAT_2001abc0 == '\x01') {
      if (1 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): $$$$$$$$$$$$$$$$$$$$$enter agemode!$$$$$$$$$$$$$$$$$$$$$\n");
        }
        else {
          ble_printk("%s(): $$$$$$$$$$$$$$$$$$$$$enter agemode!$$$$$$$$$$$$$$$$$$$$$\n",
                     "aging_test_thread",param_3,BLE_DEBUG);
        }
      }
      FUN_00080638();
      while (DAT_2001abc0 == '\x01') {
        FUN_00038234(0);
        sleep(3000);
        FUN_00038234(2);
        sleep(1000);
        aging_charge_test(4);
      }
    }
    else if (DAT_2001abc0 == '\x02') {
      FUN_00038250();
      DAT_2001abc0 = '\0';
    }
    check_sw0_status();
    sleep(100);
    param_3 = extraout_r2;
  } while( true );
}


