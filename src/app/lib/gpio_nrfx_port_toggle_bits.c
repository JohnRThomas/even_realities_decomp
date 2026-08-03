/*
 * Function: gpio_nrfx_port_toggle_bits
 * Entry:    0008737a
 * Prototype: undefined __stdcall gpio_nrfx_port_toggle_bits(size_t param_1, uint param_2, undefined4 param_3)
 */


/* exclude_from_export_ai */

void gpio_nrfx_port_toggle_bits(size_t param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  uint local_14;
  undefined4 uStack_10;
  
  local_14 = param_2;
  uStack_10 = param_3;
  iVar1 = gpio_nrfx_port_get_raw(param_1,&local_14);
  if (-1 < iVar1) {
    gpio_nrfx_port_set_masked_raw(param_1,param_2);
    return;
  }
  return;
}


