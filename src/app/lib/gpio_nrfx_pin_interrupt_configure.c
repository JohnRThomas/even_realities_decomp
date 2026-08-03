/*
 * Function: gpio_nrfx_pin_interrupt_configure
 * Entry:    0006470c
 * Prototype: int __stdcall gpio_nrfx_pin_interrupt_configure(device * port, gpio_pin_t pin, gpio_int_mode mode, gpio_int_trig trig)
 */


/* exclude_from_export */

int gpio_nrfx_pin_interrupt_configure
              (device *port,gpio_pin_t pin,gpio_int_mode mode,gpio_int_trig trig)

{
  uint8_t *puVar1;
  nrfx_err_t nVar2;
  P1_S *pPVar3;
  uint uVar4;
  uint pin_00;
  uint uVar5;
  uint8_t uStack_19;
  nrfx_gpiote_trigger_config_t local_18;
  uint8_t *local_14;
  
  uVar4 = pin & 0x1f;
  uVar5 = (uint)(byte)port->config[0xc];
  pin_00 = uVar4 | uVar5 << 5;
  if (mode == 0x200000) {
    nrfx_gpiote_trigger_disable(pin_00);
  }
  else {
    local_14 = (uint8_t *)0x0;
    puVar1 = local_14;
    if (mode == 0x400000) {
      if (trig == 0x2000000) {
        local_18.opaque[0] = 4;
      }
      else {
        local_18.opaque[0] = 5;
      }
      local_18.opaque[1] = 0;
      local_18.opaque[2] = 0;
      local_18.opaque[3] = 0;
    }
    else {
      if (trig == 0x6000000) {
        local_18.opaque[0] = 3;
      }
      else if (trig == 0x2000000) {
        local_18.opaque[0] = 2;
      }
      else {
        local_18.opaque[0] = 1;
      }
      local_18.opaque[1] = 0;
      local_18.opaque[2] = 0;
      local_18.opaque[3] = 0;
      if ((-1 < (int)((*(uint *)(port->config + 8) >> (uint)pin) << 0x1f)) && (mode == 0x1400000)) {
        if (uVar5 == 0) {
          if (-1 < (int)((0xffffffffU >> uVar4) << 0x1f)) goto LAB_0006479c;
          pPVar3 = (P1_S *)&Peripherals::P0_S;
        }
        else {
          if ((uVar5 != 1) || (-1 < (int)((0xffffU >> uVar4) << 0x1f))) {
LAB_0006479c:
            _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","nrf_gpio_pin_present_check(*p_pin)",
                    s_WEST_TOPDIR_modules_hal_nordic_n_000ee9e7,815);
                    /* WARNING: Subroutine does not return */
            k_panic();
          }
          pPVar3 = &Peripherals::P1_S;
        }
        if (-1 < (int)((&((P0_S *)pPVar3)->PIN_CNF_0_)[uVar4] << 0x1f)) {
          nVar2 = nrfx_gpiote_channel_get(pin_00,&uStack_19);
          puVar1 = &uStack_19;
          if ((nVar2 == 0xbad0004) &&
             (nVar2 = nrfx_gpiote_channel_alloc(&uStack_19),
             (undefined1 *)(uint)nVar2 != &DAT_0bad0000)) {
            return -0xc;
          }
        }
      }
    }
    local_14 = puVar1;
    nVar2 = nrfx_gpiote_input_configure
                      (pin_00,(nrfx_gpiote_input_config_t *)0x0,&local_18,
                       (nrfx_gpiote_handler_config_t *)0x0);
    if ((undefined1 *)(uint)nVar2 != &DAT_0bad0000) {
      return -0x16;
    }
    nrfx_gpiote_trigger_enable(pin_00,true);
  }
  return 0;
}


