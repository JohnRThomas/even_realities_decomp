/*
 * Function: ?_wdt_feed
 * Entry:    0002d020
 * Prototype: int __stdcall ?_wdt_feed(void)
 */


int __wdt_feed(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 5;
  do {
    iVar1 = wdt_npm1300_feed(&wdt_device,wdt_0_channel_id);
    if (iVar1 == 0) {
      return 0;
    }
    z_impl_k_sleep((k_timeout_t)1639);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return iVar1;
}


