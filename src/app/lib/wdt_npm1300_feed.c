/*
 * Function: wdt_npm1300_feed
 * Entry:    0008842e
 * Prototype: int __stdcall wdt_npm1300_feed(device * dev, int channel_id)
 */


/* exclude_from_export */

int wdt_npm1300_feed(device *dev,int channel_id)

{
  int iVar1;
  
  if (channel_id == 0) {
    iVar1 = i2c_write_dt(*(i2c_dt_spec **)dev->config,&DAT_00000007,4);
    return iVar1;
  }
  return -0x16;
}


