/*
 * Function: init_watchdog
 * Entry:    0002cf14
 * Prototype: undefined4 __stdcall init_watchdog(void)
 */


/* See: /media/files/ncs/v2.5.1/zephyr/samples/drivers/watchdog/src/main.c */

undefined4 init_watchdog(void)

{
  bool bVar1;
  char *fmt;
  int iVar2;
  int iVar3;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 uVar4;
  undefined4 extraout_r2_01;
  wdt_timeout_cfg wStack_28;
  
  bVar1 = z_device_is_ready(&wdt_device);
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
  memset(&wStack_28,0,0x10);
  wStack_28.window.max = 30000;
  wStack_28.flags = '\x02';
  wdt_0_channel_id = wdt_npm1300_install_timeout(&wdt_device,&wStack_28);
  uVar4 = extraout_r2;
  if (wdt_0_channel_id == -0x86) {
    if (0 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): Callback support rejected, continuing anyway\n");
      }
      else {
        ble_printk("%s(): Callback support rejected, continuing anyway\n","init_watchdog",
                   extraout_r2,BLE_DEBUG);
      }
    }
    wStack_28.callback = (wdt_callback_t *)0x0;
    wdt_0_channel_id = wdt_npm1300_install_timeout(&wdt_device,&wStack_28);
    uVar4 = extraout_r2_00;
  }
  if (wdt_0_channel_id < 0) {
    if (LOG_LEVEL < 1) {
      return 0;
    }
    fmt = "%s(): Watchdog install error\n";
  }
  else {
    iVar2 = wdt_npm1300_setup(&wdt_device,'\x02');
    if (-1 < iVar2) {
      iVar2 = 5;
      do {
        iVar3 = wdt_npm1300_feed(&wdt_device,wdt_0_channel_id);
        if (iVar3 == 0) {
          return 0;
        }
        z_impl_k_sleep((k_timeout_t)0x667);
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
      return 0;
    }
    if (LOG_LEVEL < 1) {
      return 0;
    }
    fmt = "%s(): Watchdog setup error\n";
    uVar4 = extraout_r2_01;
  }
  if (BLE_DEBUG == 0) {
    printk(fmt);
  }
  else {
    ble_printk(fmt,"init_watchdog",uVar4,BLE_DEBUG);
  }
  return 0;
}


