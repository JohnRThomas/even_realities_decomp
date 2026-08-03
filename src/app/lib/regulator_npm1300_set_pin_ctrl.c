/*
 * Function: regulator_npm1300_set_pin_ctrl
 * Entry:    00087b6a
 * Prototype: int __stdcall regulator_npm1300_set_pin_ctrl(device * dev, gpio_dt_spec * spec, npm1300_gpio_type type)
 */


/* exclude_from_export */

int regulator_npm1300_set_pin_ctrl(device *dev,gpio_dt_spec *spec,npm1300_gpio_type type)

{
  device *dev_00;
  int iVar1;
  uint8_t chan;
  gpio_pin_t pin;
  uint32_t num_bytes;
  
  if (spec->port == (device *)0x0) {
    return 0;
  }
  dev_00 = (device *)dev->config;
  switch(*(undefined1 *)&dev_00[1].api) {
  case 0:
    pin = spec->pin;
    chan = '\0';
    break;
  case 1:
    pin = spec->pin;
    chan = '\x01';
    break;
  case 2:
    if (type != NPM1300_GPIO_TYPE_ENABLE) {
      return -0x86;
    }
    num_bytes = 5;
    goto LAB_00087ba6;
  case 3:
    if (type != NPM1300_GPIO_TYPE_ENABLE) {
      return -0x86;
    }
    num_bytes = 6;
LAB_00087ba6:
    iVar1 = i2c_write_dt((i2c_dt_spec *)dev_00[1].config,&NMI,num_bytes);
    return iVar1;
  default:
    return -0x13;
  }
  iVar1 = regulator_npm1300_set_buck_pin_ctrl(dev_00,chan,pin,(byte)spec->dt_flags & 1,type);
  return iVar1;
}


