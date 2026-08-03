/*
 * Function: wdt_nrf_feed
 * Entry:    0008848a
 * Prototype: undefined4 __stdcall wdt_nrf_feed(int param_1, uint param_2)
 */


/* exclude_from_export */

undefined4 wdt_nrf_feed(int param_1,uint param_2)

{
  undefined4 uVar1;
  
  if ((int)(uint)*(byte *)(*(int *)(param_1 + 0x10) + 0x24) < (int)param_2) {
    uVar1 = 0xffffffea;
  }
  else {
    nrfx_wdt_channel_feed(*(nrfx_wdt_t **)(param_1 + 4),param_2 & 0xff);
    uVar1 = 0;
  }
  return uVar1;
}


