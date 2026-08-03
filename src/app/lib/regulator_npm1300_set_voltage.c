/*
 * Function: regulator_npm1300_set_voltage
 * Entry:    00087af8
 * Prototype: int __stdcall regulator_npm1300_set_voltage(device * dev, int32_t min_uv, int32_t max_uv)
 */


/* exclude_from_export */

int regulator_npm1300_set_voltage(device *dev,int32_t min_uv,int32_t max_uv)

{
  device *dev_00;
  int iVar1;
  uint8_t chan;
  uint uVar2;
  
  dev_00 = (device *)dev->config;
  switch(*(undefined1 *)&dev_00[1].api) {
  case 0:
    uVar2 = 0;
    break;
  case 1:
    uVar2 = 1;
    break;
  case 2:
    chan = '\0';
    goto LAB_00087b24;
  case 3:
    chan = '\x01';
LAB_00087b24:
    iVar1 = ldo_set_voltage(dev_00,chan,min_uv,max_uv);
    return iVar1;
  default:
    return -0x13;
  }
  iVar1 = buck_set_voltage((int)dev_00,uVar2,(linear_range *)min_uv,max_uv);
  return iVar1;
}


