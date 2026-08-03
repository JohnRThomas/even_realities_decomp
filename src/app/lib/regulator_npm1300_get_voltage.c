/*
 * Function: regulator_npm1300_get_voltage
 * Entry:    00087b3c
 * Prototype: int __stdcall regulator_npm1300_get_voltage(device * dev, int32_t * volt_uv)
 */


/* exclude_from_export */

int regulator_npm1300_get_voltage(device *dev,int32_t *volt_uv)

{
  int iVar1;
  device *dev_00;
  uint16_t dev_addr;
  uint32_t in_stack_00000000;
  undefined4 uStack_c;
  
  dev_00 = (device *)dev->config;
  switch((uint8_t *)(uint)*(byte *)&dev_00[1].api) {
  case (uint8_t *)0x0:
    dev_addr = 0;
    break;
  case (uint8_t *)0x1:
    dev_addr = 1;
    break;
  case (uint8_t *)0x2:
    uStack_c = 0;
    goto LAB_00087b5c;
  case (uint8_t *)0x3:
    uStack_c = 1;
LAB_00087b5c:
    iVar1 = i2c_write_read_dt((i2c_dt_spec *)dev_00[1].config,&NMI,uStack_c + 0xc,
                              (void *)((int)&uStack_c + 3),(size_t)dev_00);
    if (-1 < iVar1) {
      if (uStack_c >> 0x18 < 0x18) {
        iVar1 = 0;
        *volt_uv = (int32_t)("failed to set gyroscope full-scale\r\n" +
                            (uStack_c >> 0x18) * 100000 + 0xd);
      }
      else {
        iVar1 = -0x16;
      }
    }
    return iVar1;
  default:
    return -0x13;
  }
  iVar1 = i2c_burst_read(dev_00,dev_addr,(uint8_t)volt_uv,(uint8_t *)(uint)*(byte *)&dev_00[1].api,
                         in_stack_00000000);
  return iVar1;
}


