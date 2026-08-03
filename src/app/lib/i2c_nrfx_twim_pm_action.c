/*
 * Function: i2c_nrfx_twim_pm_action
 * Entry:    000874ac
 * Prototype: int __stdcall i2c_nrfx_twim_pm_action(int * dev, int action)
 */


/* exclude_from_export */

int i2c_nrfx_twim_pm_action(int *dev,int action)

{
  int iVar1;
  nrfx_twim_t *p_instance;
  
  p_instance = (nrfx_twim_t *)dev[1];
  if (action != 0) {
    if (action == 1) {
      iVar1 = pinctrl_apply_state((pinctrl_dev_config *)p_instance[8],'\0');
      if (-1 < iVar1) {
        nrfx_twim_enable(p_instance);
      }
    }
    else {
      iVar1 = -0x86;
    }
    return iVar1;
  }
  nrfx_twim_disable(p_instance);
  iVar1 = pinctrl_apply_state((pinctrl_dev_config *)p_instance[8],'\x01');
  return iVar1;
}


