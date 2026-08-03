/*
 * Function: regulator_npm1300_disable
 * Entry:    00087968
 * Prototype: int __stdcall regulator_npm1300_disable(device * dev)
 */


/* exclude_from_export */

int regulator_npm1300_disable(device *dev)

{
  int iVar1;
  uint8_t *buf;
  uint32_t num_bytes;
  
  switch(dev->config[0x20]) {
  case 0:
    num_bytes = 1;
    break;
  case 1:
    num_bytes = 3;
    break;
  case 2:
    num_bytes = 1;
    goto LAB_00087990;
  case 3:
    num_bytes = 3;
LAB_00087990:
    buf = &NMI;
    goto LAB_00087980;
  default:
    return 0;
  }
  buf = &Reset;
LAB_00087980:
  iVar1 = i2c_write_dt(*(i2c_dt_spec **)(dev->config + 0x1c),buf,num_bytes);
  return iVar1;
}


