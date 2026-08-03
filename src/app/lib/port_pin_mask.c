/*
 * Function: port_pin_mask
 * Entry:    00017a3c
 * Prototype: undefined __stdcall port_pin_mask(undefined4 param_1, undefined4 param_2, gpio_flags_t param_3)
 */


/* exclude_from_export_ai */

void port_pin_mask(undefined4 param_1,undefined4 param_2,gpio_flags_t param_3)

{
  GlassesState *pGVar1;
  gpio_flags_t extraout_r2;
  gpio_flags_t extraout_r2_00;
  gpio_flags_t flags;
  
  z_impl_gpio_pin_interrupt_configure((device *)&button_irq_gpio_spec,0,param_3);
  flags = extraout_r2;
  if ((param_3 == 0x200) && (g_aw9320x_func.delay != (aw9320x_delay_t *)0x0)) {
    DAT_20006be0 = 1;
    pGVar1 = __get_dashboard_state();
    k_sem_give(&pGVar1->sem_8);
    flags = extraout_r2_00;
  }
  z_impl_gpio_pin_interrupt_configure((device *)&button_irq_gpio_spec,0,flags);
  return;
}


