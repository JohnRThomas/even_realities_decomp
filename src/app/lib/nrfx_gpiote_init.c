/*
 * Function: nrfx_gpiote_init
 * Entry:    00068be8
 * Prototype: nrfx_err_t __stdcall nrfx_gpiote_init(uint8_t interrupt_priority)
 */


/* exclude_from_export */

nrfx_err_t nrfx_gpiote_init(uint8_t interrupt_priority)

{
  uint uVar1;
  nrfx_err_t nVar2;
  nrf_gpiote_event_t nVar3;
  int iVar4;
  
  if (DAT_20002c58 == '\0') {
    memset(&DAT_20002bf0,0,0x60);
    iVar4 = 0;
    do {
      nVar3 = nrf_gpiote_in_event_get((uint8_t)iVar4);
      if (nVar3 - 0x100U >> 2 == 0x1f) {
        *(undefined4 *)((int)&Peripherals::GPIOTE0_S.TASKS_OUT_0_ + nVar3) = 0;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 != 8);
    Peripherals::GPIOTE0_S.EVENTS_PORT = 0;
    uVar1 = Peripherals::GPIOTE0_S.EVENTS_PORT;
    arch_irq_enable(0xd);
    Peripherals::GPIOTE0_S.INTENSET = 0x80000000;
    nVar2 = NRFX_SUCCESS;
    DAT_20002c58 = '\x01';
    DAT_20002c54 = 1;
  }
  else {
    nVar2 = NRFX_ERROR_INVALID_STATE;
  }
  return nVar2;
}


