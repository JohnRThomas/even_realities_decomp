/*
 * Function: wdt_npm1300_install_timeout
 * Entry:    00066c2c
 * Prototype: int __stdcall wdt_npm1300_install_timeout(device * dev, wdt_timeout_cfg * timeout)
 */


/* exclude_from_export */

int wdt_npm1300_install_timeout(device *dev,wdt_timeout_cfg *timeout)

{
  int iVar1;
  char *pcVar2;
  undefined4 *puVar3;
  
  pcVar2 = dev->data;
  puVar3 = (undefined4 *)dev->config;
  if (*pcVar2 != '\0') {
    return -0xc;
  }
  if ((timeout->window).min == 0) {
    iVar1 = mfd_npm1300_set_timer((device *)*puVar3,(timeout->window).max);
    if (iVar1 < 0) {
      return iVar1;
    }
    if ((timeout->flags & 3) != 3) {
      iVar1 = i2c_write_dt((i2c_dt_spec *)*puVar3,&DAT_00000007,5);
      if (iVar1 < 0) {
        return iVar1;
      }
      *pcVar2 = '\x01';
      return 0;
    }
  }
  return -0x16;
}


