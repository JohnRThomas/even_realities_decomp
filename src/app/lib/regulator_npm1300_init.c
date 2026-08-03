/*
 * Function: regulator_npm1300_init
 * Entry:    00087bc8
 * Prototype: int __stdcall regulator_npm1300_init(device * dev)
 */


/* exclude_from_export */

int regulator_npm1300_init(device *dev)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  linear_range *r;
  uint16_t *idx;
  regulator_npm1300_config *puVar4;
  undefined *puVar5;
  undefined1 local_1a [6];
  
  puVar4 = (regulator_npm1300_config *)dev->config;
  bVar2 = z_device_is_ready(puVar4->mfd);
  if (bVar2) {
    iVar3 = regulator_common_init(dev,false);
    if (-1 < iVar3) {
      r = (linear_range *)puVar4->retention_uv;
      if (r != (linear_range *)0x0) {
        puVar5 = dev->config;
        cVar1 = puVar5[0x20];
        if ((cVar1 != '\0') && (cVar1 != '\x01')) {
          return -0x86;
        }
        iVar3 = linear_range_get_win_index(r,(int32_t)r,(int32_t)local_1a,idx);
        if (iVar3 == -0x16) {
          return -0x16;
        }
        iVar3 = i2c_write_dt(*(i2c_dt_spec **)(puVar5 + 0x1c),&Reset,
                             (uint)(byte)(cVar1 * '\x02' + 9));
        if (iVar3 != 0) {
          return iVar3;
        }
      }
      iVar3 = regulator_npm1300_set_pin_ctrl(dev,&puVar4->enable_gpios,NPM1300_GPIO_TYPE_ENABLE);
      if ((iVar3 == 0) &&
         (iVar3 = regulator_npm1300_set_pin_ctrl
                            (dev,&puVar4->retention_gpios,NPM1300_GPIO_TYPE_RETENTION), iVar3 == 0))
      {
        iVar3 = regulator_npm1300_set_pin_ctrl(dev,&puVar4->pwm_gpios,NPM1300_GPIO_TYPE_PWM);
        return iVar3;
      }
    }
  }
  else {
    iVar3 = -0x13;
  }
  return iVar3;
}


