/*
 * Function: low_speed_peripheral_dispatch_thread_for_test
 * Entry:    00028938
 * Prototype: undefined __stdcall low_speed_peripheral_dispatch_thread_for_test(size_t param_1, uint param_2, undefined4 param_3)
 */


void low_speed_peripheral_dispatch_thread_for_test(size_t param_1,uint param_2,undefined4 param_3)

{
  size_t extraout_r0;
  uint uVar1;
  size_t extraout_r0_00;
  size_t sVar2;
  uint extraout_r1;
  uint extraout_r1_00;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 extraout_r2_02;
  int iVar3;
  k_timeout_t timeout;
  uint extraout_r1_01;
  
  sVar2 = param_1;
  if (1 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): #enter\n");
      sVar2 = extraout_r0_00;
      param_2 = extraout_r1_00;
      param_3 = extraout_r2_00;
    }
    else {
      ble_printk("%s(): #enter\n","low_speed_peripheral_dispatch_thread_for_test",param_3,BLE_DEBUG)
      ;
      sVar2 = extraout_r0;
      param_2 = extraout_r1;
      param_3 = extraout_r2;
    }
  }
  iVar3 = 0;
  *(undefined2 *)(param_1 + 0xfc4) = 0;
  *(undefined2 *)(param_1 + 0xfc8) = 0x8000;
  do {
    if (*(char *)(param_1 + 1) == '\x01') {
      __wdt_disable();
      FUN_00033e2c(0);
      FUN_00030458();
      if (0x22 < iVar3) {
        if (0 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): reboot because dfu exceed time\r\n\n");
          }
          else {
            ble_printk("%s(): reboot because dfu exceed time\r\n\n",
                       "low_speed_peripheral_dispatch_thread_for_test",extraout_r2_01,BLE_DEBUG);
          }
        }
        k_msleep(500);
                    /* WARNING: Subroutine does not return */
        sys_reboot(1);
      }
      uVar1 = 0x28000;
      iVar3 = iVar3 + 1;
    }
    else {
      FUN_00027744(sVar2,param_2,param_3);
      if (DAT_2000304f == '\0') {
        __wdt_disable();
      }
      else if (DAT_20019a5e == '\0') {
        __wdt_feed();
      }
      fuel_gauge_update((device *)&PTR_s_charger_0008b520);
      FUN_000344c8();
      uVar1 = 0x8000;
    }
    timeout.ticks._4_4_ = 0;
    timeout.ticks._0_4_ = uVar1;
    sVar2 = z_impl_k_sleep(timeout);
    param_2 = extraout_r1_01;
    param_3 = extraout_r2_02;
  } while( true );
}


