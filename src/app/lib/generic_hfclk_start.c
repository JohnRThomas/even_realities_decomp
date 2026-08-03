/*
 * Function: generic_hfclk_start
 * Entry:    00063948
 * Prototype: undefined __stdcall generic_hfclk_start(void)
 */


/* exclude_from_export */

void generic_hfclk_start(void)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 extraout_r1;
  
  uVar3 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar3 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x20 < uVar2)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  if ((int)(DAT_2000bb30 << 0x1f) < 0) {
    uVar2 = Peripherals::CLOCK_S.HFCLKSTAT;
    uVar2 = Peripherals::CLOCK_S.HFCLKSTAT;
    if ((int)(uVar2 << 0x1f) < 0) {
      DAT_2000bb30 = DAT_2000bb30 | 2;
      set_on_state((uint32_t *)&__CLOCK_DEVICE.api);
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        setBasePriority(extraout_r1);
      }
      InstructionSynchronizationBarrier(0xf);
      clkstarted_handle(0);
      return;
    }
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar3);
  }
  InstructionSynchronizationBarrier(0xf);
  DAT_2000bb30 = DAT_2000bb30 | 2;
  nrfx_clock_start(NRF_CLOCK_DOMAIN_HFCLK);
  return;
}


