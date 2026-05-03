/*
 * Function: set_shipmode
 * Entry:    00016868
 * Prototype: undefined4 __stdcall set_shipmode(void)
 */


undefined4 set_shipmode(void)

{
  nrfx_err_t nVar1;
  char *fmt;
  
  power_down_panel();
  power_down_imu_and_mic();
  sleep(2000);
  nVar1 = nrfx_gpiote_channel_get(0x8b430,(uint8_t *)0xb);
  if ((int)nVar1 < 0) {
    fmt = "Could not set shipmode.\n";
  }
  else {
    fmt = "enable for shipmode\n";
  }
  printk(fmt);
  return 0;
}


