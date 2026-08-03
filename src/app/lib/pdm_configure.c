/*
 * Function: pdm_configure
 * Entry:    000692f8
 * Prototype: void __stdcall pdm_configure(nrfx_pdm_config_t * p_config)
 */


/* exclude_from_export */

void pdm_configure(nrfx_pdm_config_t *p_config)

{
  uint uVar1;
  int extraout_r0;
  int extraout_r0_00;
  int iVar2;
  int extraout_r0_01;
  nrf_gpio_pin_dir_t in_r1;
  nrf_gpio_pin_dir_t dir;
  nrf_gpio_pin_dir_t dir_00;
  nrf_gpio_pin_input_t in_r2;
  nrf_gpio_pin_input_t input;
  nrfx_pdm_config_t nVar3;
  nrfx_pdm_config_t pull;
  nrfx_pdm_config_t *drive;
  
  if (*(char *)((int)p_config + 0x15) == '\0') {
    nVar3 = p_config[1];
    drive = p_config;
    nrf_gpio_cfg((uint32_t)&stack0xffffffe4,in_r1,in_r2,nVar3,(nrf_gpio_pin_drive_t)p_config,nVar3);
    *(int *)(extraout_r0 + 0xc) = 1 << (nVar3 & 0xff);
    pull = p_config[1];
    nrf_gpio_cfg((uint32_t)&stack0xffffffe4,dir,nVar3,pull,(nrf_gpio_pin_drive_t)drive,pull);
    iVar2 = extraout_r0_00 + pull * 4;
    *(uint *)(iVar2 + 0x200) = *(uint *)(iVar2 + 0x200) & 0xfffcf0f0 | 3;
    nVar3 = p_config[2];
    nrf_gpio_cfg((uint32_t)&stack0xffffffe4,dir_00,input,nVar3,(nrf_gpio_pin_drive_t)drive,nVar3);
    iVar2 = extraout_r0_01 + nVar3 * 4;
    *(uint *)(iVar2 + 0x200) = *(uint *)(iVar2 + 0x200) & 0xfffcf0f0;
  }
  if (*(char *)((int)p_config + 0x16) == '\0') {
    Peripherals::PDM0_S._1344_4_ = p_config[1];
    Peripherals::PDM0_S._1348_4_ = p_config[2];
  }
  Peripherals::PDM0_S.RATIO = (uint)*(byte *)((int)p_config + 0x13);
  Peripherals::PDM0_S.MCLKCONFIG = (uint)(byte)p_config[5];
  Peripherals::PDM0_S.PDMCLKCTRL = p_config[3];
  Peripherals::PDM0_S.MODE = (*(byte *)((int)p_config + 1) & 1) << 1 | (byte)*p_config & 1;
  Peripherals::PDM0_S.GAINL = (uint)(byte)p_config[4];
  Peripherals::PDM0_S.GAINR = (uint)*(byte *)((int)p_config + 0x11);
  if (*(char *)((int)p_config + 0x16) == '\0') {
    Peripherals::PDM0_S._1344_4_ = p_config[1];
    Peripherals::PDM0_S._1348_4_ = p_config[2];
  }
  Peripherals::PDM0_S.EVENTS_STARTED = 0;
  uVar1 = Peripherals::PDM0_S.EVENTS_STARTED;
  Peripherals::PDM0_S.EVENTS_STOPPED = 0;
  uVar1 = Peripherals::PDM0_S.EVENTS_STOPPED;
  arch_irq_enable(38);
  Peripherals::PDM0_S.INTENSET = 3;
  return;
}


