/*
 * Function: i2c_nrfx_twim_recover_bus
 * Entry:    00064a30
 * Prototype: int __stdcall i2c_nrfx_twim_recover_bus(device * dev)
 */


/* exclude_from_export_ai */

int i2c_nrfx_twim_recover_bus(device *dev)

{
  nrfx_err_t nVar1;
  int iVar2;
  undefined4 in_r1;
  nrfx_twim_t *p_instance;
  uint32_t scl_pin;
  uint32_t sda_pin;
  char cStack_11;
  
  cStack_11 = (char)((uint)in_r1 >> 0x18);
  p_instance = (nrfx_twim_t *)dev->config;
  scl_pin = *(uint32_t *)(*p_instance + 0x508);
  sda_pin = *(uint32_t *)(*p_instance + 0x50c);
  pm_device_state_get(dev,(pm_device_state *)&cStack_11);
  if (cStack_11 == '\0') {
    nrfx_twim_disable(p_instance);
  }
  nVar1 = nrfx_twim_bus_recover(scl_pin,sda_pin);
  if (cStack_11 == '\0') {
    pinctrl_apply_state((pinctrl_dev_config *)p_instance[8],'\0');
    nrfx_twim_enable(p_instance);
  }
  if ((undefined1 *)(uint)nVar1 == &DAT_0bad0000) {
    iVar2 = 0;
  }
  else {
    iVar2 = -0x10;
  }
  return iVar2;
}


