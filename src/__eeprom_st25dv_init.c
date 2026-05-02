/*
 * Function: ?_eeprom_st25dv_init
 * Entry:    00027be0
 * Prototype: st25dv_context * __stdcall ?_eeprom_st25dv_init(void)
 */


st25dv_context * __eeprom_st25dv_init(void)

{
  bool bVar1;
  char *fmt;
  st25dv_context *psVar2;
  
  global_st25dv_context.callbacks = &st25dv_callbacks_0008c1e8;
  st25dv_device.config._0_2_ = 0x53;
  st25dv_device.api._0_2_ = 0x53;
  st25dv_device.state = (undefined *)0x1000;
  global_st25dv_context.mutex = &st25dv_mutex;
  global_st25dv_context.device = &st25dv_device;
  z_impl_k_mutex_init(&st25dv_mutex);
  bVar1 = z_device_is_ready((device *)st25dv_device.name);
  if (bVar1) {
    fmt = "eeprom_st25dv_init ready\r\n";
  }
  else {
    fmt = "parent bus device not ready\r\n";
  }
  printk(fmt);
  bVar1 = z_device_is_ready((device *)st25dv_device.name);
  if (bVar1) {
    printk("update_eeprom_interface\r\n");
    psVar2 = &global_st25dv_context;
  }
  else {
    printk("\nError: Device \"%s\" is not ready; check the driver initialization logs for errors.\n"
           ,*(undefined4 *)st25dv_device.name);
    psVar2 = (st25dv_context *)0x0;
  }
  return psVar2;
}


