/*
 * Function: nrfx_clock_start
 * Entry:    000684d4
 * Prototype: void __stdcall nrfx_clock_start(nrf_clock_domain_t domain)
 */


/* exclude_from_export */

void nrfx_clock_start(nrf_clock_domain_t domain)

{
  uint uVar1;
  uint uVar2;
  
  if (!m_clock_cb.module_initialized) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","m_clock_cb.module_initialized",
            "WEST_TOPDIR/modules/hal/nordic/nrfx/drivers/src/nrfx_clock.c",360);
LAB_000684ee:
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  switch(domain) {
  case NRF_CLOCK_DOMAIN_LFCLK:
    uVar1 = Peripherals::CLOCK_S.LFCLKSTAT;
    uVar2 = Peripherals::CLOCK_S.LFCLKSTAT;
    if ((int)(uVar1 << 0xf) < 0) {
      uVar2 = uVar2 & 3;
      if (uVar2 != 2) {
        if (uVar2 != 1) goto LAB_0006851c;
        goto LAB_00068522;
      }
    }
    else {
      uVar1 = Peripherals::CLOCK_S.LFCLKRUN;
      if ((int)(uVar1 << 0x1f) < 0) {
        uVar1 = Peripherals::CLOCK_S.LFCLKSRCCOPY;
        if ((uVar1 & 3) - 1 < 2) {
          Peripherals::CLOCK_S.INTENSET = 2;
          return;
        }
LAB_0006851c:
        clock_stop(NRF_CLOCK_DOMAIN_LFCLK);
      }
LAB_00068522:
      uVar2 = 1;
    }
    Peripherals::CLOCK_S.LFCLKSRC = uVar2;
    Peripherals::CLOCK_S.EVENTS_LFCLKSTARTED = 0;
    uVar1 = Peripherals::CLOCK_S.EVENTS_LFCLKSTARTED;
    Peripherals::CLOCK_S.INTENSET = 2;
    Peripherals::CLOCK_S.TASKS_LFCLKSTART = 1;
    break;
  case NRF_CLOCK_DOMAIN_HFCLK:
    Peripherals::CLOCK_S.EVENTS_HFCLKSTARTED = 0;
    uVar1 = Peripherals::CLOCK_S.EVENTS_HFCLKSTARTED;
    Peripherals::CLOCK_S.INTENSET = 1;
    Peripherals::CLOCK_S.TASKS_HFCLKSTART = 1;
    break;
  case NRF_CLOCK_DOMAIN_HFCLK192M:
    Peripherals::CLOCK_S.EVENTS_HFCLK192MSTARTED = 0;
    uVar1 = Peripherals::CLOCK_S.EVENTS_HFCLK192MSTARTED;
    Peripherals::CLOCK_S.INTENSET = 0x200;
    Peripherals::CLOCK_S.TASKS_HFCLK192MSTART = 1;
    break;
  case NRF_CLOCK_DOMAIN_HFCLKAUDIO:
    Peripherals::CLOCK_S.EVENTS_HFCLKAUDIOSTARTED = 0;
    uVar1 = Peripherals::CLOCK_S.EVENTS_HFCLKAUDIOSTARTED;
    Peripherals::CLOCK_S.INTENSET = 0x100;
    Peripherals::CLOCK_S.TASKS_HFCLKAUDIOSTART = 1;
    break;
  default:
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","0",
            "WEST_TOPDIR/modules/hal/nordic/nrfx/drivers/src/nrfx_clock.c",422);
    goto LAB_000684ee;
  }
  return;
}


