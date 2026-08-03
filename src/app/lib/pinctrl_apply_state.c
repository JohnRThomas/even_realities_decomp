/*
 * Function: pinctrl_apply_state
 * Entry:    000882c4
 * Prototype: int __stdcall pinctrl_apply_state(pinctrl_dev_config * config, uint8_t id)
 */


/* exclude_from_export */

int pinctrl_apply_state(pinctrl_dev_config *config,uint8_t id)

{
  int iVar1;
  pinctrl_state *local_c;
  
  local_c = (pinctrl_state *)(uint)id;
  iVar1 = pinctrl_lookup_state(config,id,&local_c);
  if (-1 < iVar1) {
    iVar1 = pinctrl_configure_pins((pinctrl_soc_pin_t *)*local_c,(uint8_t)local_c[1],*config);
  }
  return iVar1;
}


