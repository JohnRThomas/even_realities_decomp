/*
 * Function: ?_disable_power_for_panel
 * Entry:    0002fdd8
 * Prototype: undefined4 __stdcall ?_disable_power_for_panel(void)
 */


undefined4 __disable_power_for_panel(void)

{
  nrfx_err_t nVar1;
  undefined4 extraout_r0;
  undefined4 extraout_r1;
  undefined4 extraout_r2;
  
  nVar1 = nrfx_gpiote_channel_get(0x8b430,&NMI);
  if ((int)nVar1 < 0) {
    printk("Could not set ldsw1.\n");
  }
  else {
    printk("disable ldsw1 1.8v for panel\n");
    opt3007_chip_deinit(extraout_r0,extraout_r1,extraout_r2);
  }
  return 0;
}


