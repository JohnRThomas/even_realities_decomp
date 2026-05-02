/*
 * Function: ?_change_termination_voltage
 * Entry:    0002ff00
 * Prototype: undefined4 __stdcall ?_change_termination_voltage(void)
 */


undefined4 __change_termination_voltage(void)

{
  nrfx_err_t nVar1;
  undefined4 uVar2;
  
  nVar1 = nrfx_gpiote_channel_get(0x8b430,(uint8_t *)0x3);
  if ((int)nVar1 < 0) {
    printk("Could not change termination voltage to 4.2V\n");
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


