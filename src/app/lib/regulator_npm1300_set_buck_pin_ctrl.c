/*
 * Function: regulator_npm1300_set_buck_pin_ctrl
 * Entry:    000879ac
 * Prototype: int __stdcall regulator_npm1300_set_buck_pin_ctrl(device * dev, uint8_t chan, uint8_t pin, uint8_t inv, npm1300_gpio_type type)
 */


/* exclude_from_export */

int regulator_npm1300_set_buck_pin_ctrl
              (device *dev,uint8_t chan,uint8_t pin,uint8_t inv,npm1300_gpio_type type)

{
  byte bVar1;
  int iVar2;
  byte bVar3;
  uint8_t mask;
  uint8_t offset;
  npm1300_gpio_type nVar4;
  
  bVar3 = pin + 1;
  if (chan == '\x01') {
    bVar3 = bVar3 * '\b';
  }
  nVar4 = type & 0xff;
  if (chan == '\x01') {
    bVar1 = inv << 7;
    mask = 0xb8;
  }
  else {
    bVar1 = inv << 6;
    mask = 'G';
  }
  if (nVar4 == NPM1300_GPIO_TYPE_RETENTION) {
    offset = '\r';
  }
  else if (nVar4 == NPM1300_GPIO_TYPE_PWM) {
    offset = '\x0e';
  }
  else {
    if (nVar4 != NPM1300_GPIO_TYPE_ENABLE) {
      return -0x86;
    }
    offset = '\f';
  }
  iVar2 = mfd_npm1300_reg_update((device *)dev[1].config,'\x04',offset,bVar3 | bVar1,mask);
  return iVar2;
}


