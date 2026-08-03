/*
 * Function: qspi_configure
 * Entry:    00069af8
 * Prototype: nrfx_err_t __stdcall qspi_configure(nrfx_qspi_config_t * p_config)
 */


/* exclude_from_export */

nrfx_err_t qspi_configure(nrfx_qspi_config_t *p_config)

{
  nrf_qspi_pins_t *extraout_r1;
  nrf_qspi_pins_t *extraout_r1_00;
  nrf_qspi_pins_t *extraout_r1_01;
  nrf_qspi_pins_t *p_pins;
  nrfx_qspi_config_t input;
  nrf_gpio_pin_input_t input_00;
  nrf_gpio_pin_input_t input_01;
  nrf_gpio_pin_input_t input_02;
  nrf_gpio_pin_input_t input_03;
  nrf_gpio_pin_input_t extraout_r2;
  nrf_gpio_pin_input_t input_04;
  nrf_gpio_pin_pull_t pull;
  nrf_gpio_pin_pull_t pull_00;
  nrf_gpio_pin_pull_t pull_01;
  nrf_gpio_pin_pull_t pull_02;
  nrf_gpio_pin_pull_t extraout_r3;
  nrf_gpio_pin_pull_t pull_03;
  uint uVar1;
  nrf_gpio_pin_drive_t unaff_r4;
  nrf_gpio_pin_sense_t unaff_r5;
  
  if ((*(char *)((int)p_config + 0x29) == '\0') || (*(char *)((int)p_config + 0x2a) == '\0')) {
    if (((p_config[1] == 0xff) ||
        ((((p_config[2] == 0xff || (p_config[3] == 0xff)) || (p_config[4] != 0xe)) ||
         ((p_config[1] != 0x11 || (p_config[2] != 0x12)))))) ||
       ((p_config[3] != 0xd ||
        (((p_config[5] != 0xff && (p_config[5] != 0xf)) ||
         ((input = p_config[6], input != 0xff && (input != 0x10)))))))) {
      return NRFX_ERROR_INVALID_PARAM;
    }
    p_pins = (nrf_qspi_pins_t *)&DAT_00000012;
    if (*(char *)((int)p_config + 0x29) == '\0') {
      nrf_gpio_cfg(0x11,3,input,0,unaff_r4,unaff_r5);
      nrf_gpio_cfg(p_config[2],3,input_00,pull,unaff_r4,unaff_r5);
      nrf_gpio_cfg(p_config[3],3,input_01,pull_00,unaff_r4,unaff_r5);
      nrf_gpio_cfg(p_config[4],3,input_02,pull_01,unaff_r4,unaff_r5);
      p_pins = extraout_r1;
      input_04 = input_03;
      pull_03 = pull_02;
      if (p_config[5] != 0xff) {
        nrf_gpio_cfg(p_config[5],3,input_03,pull_02,unaff_r4,unaff_r5);
        p_pins = extraout_r1_00;
        input_04 = extraout_r2;
        pull_03 = extraout_r3;
      }
      if (p_config[6] != 0xff) {
        nrf_gpio_cfg(p_config[6],3,input_04,pull_03,unaff_r4,unaff_r5);
        p_pins = extraout_r1_01;
      }
    }
    if (*(char *)((int)p_config + 0x2a) == '\0') {
      nrf_qspi_pins_set((NRF_QSPI_Type *)(p_config + 1),p_pins);
    }
  }
  qspi_m_cb.timeout = p_config[9];
  qspi_m_cb.skip_gpio_cfg = *(bool *)((int)p_config + 0x29);
  Peripherals::QSPI_S.INTENCLR = 1;
  qspi_workaround_apply();
  Peripherals::QSPI_S.XIPOFFSET = *p_config;
  Peripherals::QSPI_S.IFCONFIG0 =
       (uint)*(byte *)((int)p_config + 0x1e) << 6 | (uint)*(byte *)((int)p_config + 0x1d) << 3 |
       (uint)(byte)p_config[7] | (uint)*(byte *)((int)p_config + 0x1f) << 7;
  uVar1 = Peripherals::QSPI_S.IFCONFIG0;
  if (*(char *)((int)p_config + 0x23) == '\0') {
    uVar1 = uVar1 | 0x30000;
  }
  else {
    uVar1 = uVar1 & 0xfffdffff | 0x10000;
  }
  Peripherals::QSPI_S.IFCONFIG0 = uVar1;
  Peripherals::QSPI_S.IFTIMING = 0x600;
  uVar1 = Peripherals::QSPI_S.IFCONFIG1;
  Peripherals::QSPI_S.IFCONFIG1 =
       (uint)(byte)p_config[8] | uVar1 & 0xffff00 | (uint)*(byte *)((int)p_config + 0x21) << 0x18 |
       (uint)*(byte *)((int)p_config + 0x22) << 0x19 | (uint)*(byte *)((int)p_config + 0x23) << 0x1c
  ;
  if (qspi_m_cb.handler != (nrfx_qspi_handler_t *)0x0) {
    arch_irq_enable(0x2b);
  }
  return NRFX_SUCCESS;
}


