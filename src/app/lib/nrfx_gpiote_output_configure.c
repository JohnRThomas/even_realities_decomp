/*
 * Function: nrfx_gpiote_output_configure
 * Entry:    00068a8c
 * Prototype: nrfx_err_t __stdcall nrfx_gpiote_output_configure(nrfx_gpiote_pin_t pin, nrfx_gpiote_output_config_t * p_config, nrfx_gpiote_task_config_t * p_task_config)
 */


/* exclude_from_export */

nrfx_err_t
nrfx_gpiote_output_configure
          (nrfx_gpiote_pin_t pin,nrfx_gpiote_output_config_t *p_config,
          nrfx_gpiote_task_config_t *p_task_config)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  bool bVar4;
  nrfx_err_t nVar5;
  int extraout_r1;
  nrf_gpio_pin_drive_t *p_drive;
  int iVar6;
  ushort uVar7;
  undefined1 local_19 [5];
  
  bVar3 = get_pin_idx(pin);
  if (extraout_r1 == 0) {
LAB_00068ae8:
    if (p_task_config != (nrfx_gpiote_task_config_t *)0x0) {
      bVar4 = pin_is_output(pin);
      if (!bVar4) goto LAB_00068b72;
      bVar2 = p_task_config->opaque[0];
      iVar6 = bVar3 + 8;
      uVar7 = *(ushort *)((int)&DAT_20002be0 + iVar6 * 2) & 0x1fdf;
      (&Peripherals::GPIOTE0_S.CONFIG_0_)[bVar2] = 0;
      *(ushort *)((int)&DAT_20002be0 + iVar6 * 2) = uVar7;
      (&Peripherals::GPIOTE0_S.CONFIG_0_)[bVar2] = 0;
      bVar3 = p_task_config->opaque[1];
      if (bVar3 != 0) {
        bVar1 = p_task_config->opaque[2];
        (&Peripherals::GPIOTE0_S.CONFIG_0_)[bVar2] =
             (&Peripherals::GPIOTE0_S.CONFIG_0_)[bVar2] & 0xffecc0ff;
        (&Peripherals::GPIOTE0_S.CONFIG_0_)[bVar2] =
             (pin & 0x3f) << 8 | (bVar3 & 3) << 0x10 | (&Peripherals::GPIOTE0_S.CONFIG_0_)[bVar2] |
             (bVar1 & 1) << 0x14;
        *(ushort *)((int)&DAT_20002be0 + iVar6 * 2) = uVar7 | (ushort)bVar2 << 0xd | 0x20;
      }
    }
    nVar5 = NRFX_SUCCESS;
  }
  else {
    bVar4 = pin_is_output(pin);
    if (((bVar4) || (bVar4 = pin_in_use_by_te(pin), !bVar4)) &&
       ((bVar4 = pin_has_trigger(pin), !bVar4 || (*(char *)((int)p_drive + 1) != '\x01')))) {
      local_19[0] = 1;
      nrf_gpio_reconfigure
                (pin,(nrf_gpio_pin_dir_t *)local_19,(nrf_gpio_pin_input_t *)((int)p_drive + 1),
                 (nrf_gpio_pin_pull_t *)((int)p_drive + 2),p_drive,(nrf_gpio_pin_sense_t *)0x0);
      iVar6 = bVar3 + 8;
      *(ushort *)((int)&DAT_20002be0 + iVar6 * 2) = *(ushort *)((int)&DAT_20002be0 + iVar6 * 2) | 3;
      goto LAB_00068ae8;
    }
LAB_00068b72:
    nVar5 = NRFX_ERROR_INVALID_PARAM;
  }
  return nVar5;
}


