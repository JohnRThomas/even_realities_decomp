/*
 * Function: init_watchdog
 * Entry:    0002cf14
 * Prototype: undefined4 __stdcall init_watchdog(void)
 */


undefined4 init_watchdog(void)

{
  bool bVar1;
  char *fmt;
  nrfx_err_t nVar2;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 uVar3;
  undefined4 extraout_r2_01;
  int iVar4;
  undefined1 auStack_28 [4];
  undefined4 local_24;
  undefined4 local_20;
  undefined1 local_1c;
  
  bVar1 = z_device_is_ready((device *)&PTR_s_watchdog_0008b478);
  if (!bVar1) {
    if (LOG_LEVEL < 1) {
      return 0;
    }
    if (BLE_DEBUG != 0) {
      ble_printk("%s(): %s: device not ready.\n","init_watchdog","watchdog",BLE_DEBUG);
      return 0;
    }
    printk("%s(): %s: device not ready.\n");
    return 0;
  }
  memset(auStack_28,0,0x10);
  local_24 = 30000;
  local_1c = 2;
  DAT_20008530 = wdt_nrf_setup((device *)&PTR_s_watchdog_0008b478,(uint8_t)auStack_28);
  uVar3 = extraout_r2;
  if (DAT_20008530 == -0x86) {
    if (0 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): Callback support rejected, continuing anyway\n");
      }
      else {
        ble_printk("%s(): Callback support rejected, continuing anyway\n","init_watchdog",
                   extraout_r2,BLE_DEBUG);
      }
    }
    local_20 = 0;
    DAT_20008530 = wdt_nrf_setup((device *)&PTR_s_watchdog_0008b478,(uint8_t)auStack_28);
    uVar3 = extraout_r2_00;
  }
  if (DAT_20008530 < 0) {
    if (LOG_LEVEL < 1) {
      return 0;
    }
    fmt = "%s(): Watchdog install error\n";
  }
  else {
    nVar2 = FUN_00088460(0x8b478);
    if (-1 < (int)nVar2) {
      iVar4 = 5;
      do {
        nVar2 = FUN_0008842e(0x8b478,DAT_20008530);
        if (nVar2 == 0) {
          return 0;
        }
        z_impl_k_sleep((k_timeout_t)0x667);
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
      return 0;
    }
    if (LOG_LEVEL < 1) {
      return 0;
    }
    fmt = "%s(): Watchdog setup error\n";
    uVar3 = extraout_r2_01;
  }
  if (BLE_DEBUG == 0) {
    printk(fmt);
  }
  else {
    ble_printk(fmt,"init_watchdog",uVar3,BLE_DEBUG);
  }
  return 0;
}


