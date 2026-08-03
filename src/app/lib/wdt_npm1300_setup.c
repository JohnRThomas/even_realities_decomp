/*
 * Function: wdt_npm1300_setup
 * Entry:    00088460
 * Prototype: int __stdcall wdt_npm1300_setup(device * dev, uint8_t options)
 */


/* exclude_from_export */

int wdt_npm1300_setup(device *dev,uint8_t options)

{
  int iVar1;
  
  if (*dev->data != '\0') {
    iVar1 = i2c_write_dt(*(i2c_dt_spec **)dev->config,&DAT_00000007,0);
    return iVar1;
  }
  return -0x16;
}


