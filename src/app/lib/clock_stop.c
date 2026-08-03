/*
 * Function: clock_stop
 * Entry:    000682a8
 * Prototype: void __stdcall clock_stop(nrf_clock_domain_t domain)
 */


/* exclude_from_export */

void clock_stop(nrf_clock_domain_t domain)

{
  uint uVar1;
  uint uVar2;
  uint in_r1;
  byte *pbVar3;
  int iVar4;
  undefined4 uStack_14;
  
  switch(domain) {
  case NRF_CLOCK_DOMAIN_LFCLK:
    Peripherals::CLOCK_S.INTENCLR = 2;
    Peripherals::CLOCK_S.EVENTS_LFCLKSTARTED = 0;
    uVar1 = Peripherals::CLOCK_S.EVENTS_LFCLKSTARTED;
    Peripherals::CLOCK_S.TASKS_LFCLKSTOP = 1;
    break;
  case NRF_CLOCK_DOMAIN_HFCLK:
    Peripherals::CLOCK_S.INTENCLR = 1;
    Peripherals::CLOCK_S.EVENTS_HFCLKSTARTED = 0;
    uVar1 = Peripherals::CLOCK_S.EVENTS_HFCLKSTARTED;
    pbVar3 = (byte *)((int)&uStack_14 + 3);
    Peripherals::CLOCK_S.TASKS_HFCLKSTOP = 1;
    goto LAB_000682e6;
  case NRF_CLOCK_DOMAIN_HFCLK192M:
    Peripherals::CLOCK_S.INTENCLR = 0x200;
    Peripherals::CLOCK_S.EVENTS_HFCLK192MSTARTED = 0;
    uVar1 = Peripherals::CLOCK_S.EVENTS_HFCLK192MSTARTED;
    Peripherals::CLOCK_S.TASKS_HFCLK192MSTOP = 1;
    break;
  case NRF_CLOCK_DOMAIN_HFCLKAUDIO:
    Peripherals::CLOCK_S.INTENCLR = 0x100;
    Peripherals::CLOCK_S.EVENTS_HFCLKAUDIOSTARTED = 0;
    uVar1 = Peripherals::CLOCK_S.EVENTS_HFCLKAUDIOSTARTED;
    Peripherals::CLOCK_S.TASKS_HFCLKAUDIOSTOP = 1;
    break;
  default:
    uStack_14 = in_r1;
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","0",
            "WEST_TOPDIR/modules/hal/nordic/nrfx/drivers/src/nrfx_clock.c",216);
    goto LAB_00068334;
  }
  pbVar3 = (byte *)0x0;
LAB_000682e6:
  uStack_14 = CONCAT13(1,(int3)in_r1);
  switch(domain) {
  case NRF_CLOCK_DOMAIN_LFCLK:
    iVar4 = 10000;
    do {
      uVar1 = Peripherals::CLOCK_S.LFCLKSTAT;
      if (pbVar3 == (byte *)0x0) {
        if ((uVar1 & 0x10000) == 0) {
          return;
        }
      }
      else {
        uVar2 = Peripherals::CLOCK_S.LFCLKSTAT;
        *pbVar3 = (byte)uVar2 & 3;
        if ((uVar1 & 0x10000) == 0) {
          return;
        }
        if (uStack_14 >> 0x18 != 1) {
          return;
        }
      }
      arch_busy_wait(1);
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    break;
  case NRF_CLOCK_DOMAIN_HFCLK:
    iVar4 = 10000;
    do {
      uVar1 = Peripherals::CLOCK_S.HFCLKSTAT;
      if (pbVar3 == (byte *)0x0) {
        if ((uVar1 & 0x10000) == 0) {
          return;
        }
      }
      else {
        uVar2 = Peripherals::CLOCK_S.HFCLKSTAT;
        *pbVar3 = (byte)uVar2 & 1;
        if ((uVar1 & 0x10000) == 0) {
          return;
        }
        if (uStack_14 >> 0x18 != 1) {
          return;
        }
      }
      arch_busy_wait(1);
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    break;
  case NRF_CLOCK_DOMAIN_HFCLK192M:
    iVar4 = 10000;
    do {
      uVar1 = Peripherals::CLOCK_S.HFCLK192MSTAT;
      if (pbVar3 == (byte *)0x0) {
        if ((uVar1 & 0x10000) == 0) {
          return;
        }
      }
      else {
        uVar2 = Peripherals::CLOCK_S.HFCLK192MSTAT;
        *pbVar3 = (byte)uVar2 & 1;
        if ((uVar1 & 0x10000) == 0) {
          return;
        }
        if (uStack_14 >> 0x18 != 1) {
          return;
        }
      }
      arch_busy_wait(1);
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    break;
  case NRF_CLOCK_DOMAIN_HFCLKAUDIO:
    iVar4 = 10000;
    do {
      uVar1 = Peripherals::CLOCK_S.HFCLKAUDIOSTAT;
      if (-1 < (int)(uVar1 << 0xf)) {
        return;
      }
      if ((pbVar3 != (byte *)0x0) && (uStack_14 >> 0x18 != 1)) {
        return;
      }
      arch_busy_wait(1);
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    break;
  default:
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","0",
            "WEST_TOPDIR/modules/hal/nordic/nrfx/hal/nrf_clock.h",971);
LAB_00068334:
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  return;
}


