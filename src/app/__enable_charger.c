/*
 * Function: ?_enable_charger
 * Entry:    0002ff30
 * Prototype: undefined4 __stdcall ?_enable_charger(void)
 */


undefined4 __enable_charger(void)

{
  nrfx_err_t nVar1;
  undefined4 uVar2;
  
  nVar1 = nrfx_gpiote_channel_get(0x8b430,(uint8_t *)0x3);
  if ((int)nVar1 < 0) {
    printk("Could not enable charger\n");
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


