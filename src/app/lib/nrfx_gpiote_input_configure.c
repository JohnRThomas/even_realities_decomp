/*
 * Function: nrfx_gpiote_input_configure
 * Entry:    00068924
 * Prototype: nrfx_err_t __stdcall nrfx_gpiote_input_configure(nrfx_gpiote_pin_t pin, nrfx_gpiote_input_config_t * p_input_config, nrfx_gpiote_trigger_config_t * p_trigger_config, nrfx_gpiote_handler_config_t * p_handler_config)
 */


/* exclude_from_export */

nrfx_err_t
nrfx_gpiote_input_configure
          (nrfx_gpiote_pin_t pin,nrfx_gpiote_input_config_t *p_input_config,
          nrfx_gpiote_trigger_config_t *p_trigger_config,
          nrfx_gpiote_handler_config_t *p_handler_config)

{
  byte bVar1;
  byte bVar2;
  bool bVar3;
  nrfx_err_t nVar4;
  nrf_gpio_pin_pull_t *p_pull;
  int extraout_r1;
  ushort uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  undefined4 uStack_1c;
  uint uVar5;
  
  uStack_1c = p_handler_config;
  bVar2 = get_pin_idx(pin);
  uVar5 = (uint)bVar2;
  if (p_pull == (nrf_gpio_pin_pull_t *)0x0) {
LAB_00068972:
    if (p_trigger_config != (nrfx_gpiote_trigger_config_t *)0x0) {
      bVar2 = p_trigger_config->opaque[0];
      uVar8 = (uint)bVar2;
      bVar3 = pin_is_output(pin);
      if (bVar3) {
        if (extraout_r1 != 0) goto LAB_0006898a;
      }
      else {
        iVar7 = uVar5 + 8;
        uVar6 = *(ushort *)((int)&DAT_20002be0 + iVar7 * 2) & 0x1fdf;
        *(ushort *)((int)&DAT_20002be0 + iVar7 * 2) = uVar6;
        if (extraout_r1 != 0) {
          if (3 < uVar8) goto LAB_0006898a;
          bVar1 = **(byte **)p_trigger_config[1].opaque;
          if (uVar8 == 0) {
            (&Peripherals::GPIOTE0_S.CONFIG_0_)[bVar1] = 0;
            (&Peripherals::GPIOTE0_S.CONFIG_0_)[bVar1] = 0;
          }
          else {
            (&Peripherals::GPIOTE0_S.CONFIG_0_)[bVar1] =
                 (&Peripherals::GPIOTE0_S.CONFIG_0_)[bVar1] & 0xfffffffc;
            (&Peripherals::GPIOTE0_S.CONFIG_0_)[bVar1] =
                 (&Peripherals::GPIOTE0_S.CONFIG_0_)[bVar1] & 0xfffcc0ff;
            (&Peripherals::GPIOTE0_S.CONFIG_0_)[bVar1] =
                 (pin & 0x3f) << 8 | (&Peripherals::GPIOTE0_S.CONFIG_0_)[bVar1] | uVar8 << 0x10;
            *(ushort *)((int)&DAT_20002be0 + iVar7 * 2) = uVar6 | (ushort)bVar1 << 0xd | 0x20;
          }
        }
      }
      *(ushort *)((int)&DAT_20002be0 + (uVar5 + 8) * 2) =
           *(ushort *)((int)&DAT_20002be0 + (uVar5 + 8) * 2) & 0xffe3 | (ushort)bVar2 << 2;
    }
    if (p_handler_config != (nrfx_gpiote_handler_config_t *)0x0) {
      iVar9 = *(int *)p_handler_config->opaque;
      iVar7 = *(int *)p_handler_config[1].opaque;
      release_handler((lv_obj_t *)pin);
      if (iVar9 != 0) {
        if ((iVar9 == DAT_20002be0) && (iVar7 == DAT_20002be4)) {
          uVar8 = 0;
        }
        else {
          nVar4 = nrfx_flag32_alloc(&DAT_20002c54,(uint8_t *)((int)&uStack_1c + 3));
          if ((undefined1 *)(uint)nVar4 != &DAT_0bad0000) {
            return nVar4;
          }
          uVar8 = (uint)uStack_1c >> 0x18;
        }
        (&DAT_20002be4)[uVar8 * 2] = iVar7;
        uVar6 = *(ushort *)((int)&DAT_20002be0 + (uVar5 + 8) * 2);
        (&DAT_20002be0)[uVar8 * 2] = iVar9;
        *(ushort *)((int)&DAT_20002be0 + (uVar5 + 8) * 2) = uVar6 | (ushort)(uVar8 << 9) | 0x100;
      }
    }
    nVar4 = NRFX_SUCCESS;
  }
  else {
    bVar3 = pin_is_task_output(pin);
    if (!bVar3) {
      uStack_1c = (nrfx_gpiote_handler_config_t *)
                  CONCAT13(bVar3,CONCAT12(bVar3,(undefined2)uStack_1c));
      nrf_gpio_reconfigure
                (pin,(nrf_gpio_pin_dir_t *)((int)&uStack_1c + 2),
                 (nrf_gpio_pin_input_t *)((int)&uStack_1c + 3),p_pull,(nrf_gpio_pin_drive_t *)0x0,
                 (nrf_gpio_pin_sense_t *)0x0);
      *(ushort *)((int)&DAT_20002be0 + (uVar5 + 8) * 2) =
           *(ushort *)((int)&DAT_20002be0 + (uVar5 + 8) * 2) & 0xfffd | 1;
      goto LAB_00068972;
    }
LAB_0006898a:
    nVar4 = NRFX_ERROR_INVALID_PARAM;
  }
  return nVar4;
}


