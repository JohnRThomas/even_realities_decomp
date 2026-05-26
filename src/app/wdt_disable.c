/*
 * Function: ?_wdt_disable
 * Entry:    0002d050
 * Prototype: int __stdcall ?_wdt_disable(void)
 */


int __wdt_disable(void)

{
  int iVar1;
  int iVar2;
  
  if (wdt_0_channel_id < 0) {
LAB_0002d082:
    iVar1 = 0;
  }
  else {
    iVar2 = 5;
    do {
      iVar1 = wdt_npm1300_disable(&wdt_device);
      if (iVar1 == 0) {
        wdt_0_channel_id = -0x10;
        goto LAB_0002d082;
      }
      z_impl_k_sleep((k_timeout_t)0x667);
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return iVar1;
}


