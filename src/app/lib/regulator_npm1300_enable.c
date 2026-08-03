/*
 * Function: regulator_npm1300_enable
 * Entry:    00087932
 * Prototype: int __stdcall regulator_npm1300_enable(device * dev)
 */


/* exclude_from_export */

int regulator_npm1300_enable(device *dev)

{
  int iVar1;
  uint8_t *buf;
  uint32_t num_bytes;
  
  switch(dev->config[0x20]) {
  case 0:
    num_bytes = 0;
    break;
  case 1:
    num_bytes = 2;
    break;
  case 2:
    num_bytes = 0;
    goto LAB_0008795a;
  case 3:
    num_bytes = 2;
LAB_0008795a:
    buf = &NMI;
    goto LAB_0008794a;
  default:
    return 0;
  }
  buf = &Reset;
LAB_0008794a:
  iVar1 = i2c_write_dt(*(i2c_dt_spec **)(dev->config + 0x1c),buf,num_bytes);
  return iVar1;
}


