/*
 * Function: pinctrl_lookup_state
 * Entry:    00087668
 * Prototype: int __stdcall pinctrl_lookup_state(pinctrl_dev_config * config, uint8_t id, pinctrl_state * * state)
 */


/* exclude_from_export */

int pinctrl_lookup_state(pinctrl_dev_config *config,uint8_t id,pinctrl_state **state)

{
  pinctrl_state *ppVar1;
  
  ppVar1 = (pinctrl_state *)config[1];
  while( true ) {
    *state = ppVar1;
    if ((pinctrl_state *)(config[1] + (uint)*(byte *)(config + 2) * 8) <= ppVar1) {
      return -2;
    }
    if (*(uint8_t *)((int)ppVar1 + 5) == id) break;
    ppVar1 = ppVar1 + 2;
  }
  return 0;
}


