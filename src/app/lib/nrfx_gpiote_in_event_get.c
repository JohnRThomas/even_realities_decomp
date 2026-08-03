/*
 * Function: nrfx_gpiote_in_event_get
 * Entry:    000688c8
 * Prototype: nrf_gpiote_event_t __stdcall nrfx_gpiote_in_event_get(nrfx_gpiote_pin_t pin)
 */


/* exclude_from_export_ai */

nrf_gpiote_event_t nrfx_gpiote_in_event_get(nrfx_gpiote_pin_t pin)

{
  nrf_gpiote_event_t nVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  
  iVar4 = 0;
  uVar5 = 0;
  do {
    nVar1 = nrf_gpiote_in_event_get((uint8_t)iVar4);
    uVar2 = 1 << (nVar1 - 0x100U >> 2 & 0xff);
    if (((pin & uVar2) != 0) &&
       (piVar3 = (int *)((int)&Peripherals::GPIOTE0_S.TASKS_OUT_0_ + nVar1), *piVar3 != 0)) {
      *piVar3 = 0;
      uVar5 = uVar5 | uVar2;
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 != 8);
  uVar2 = Peripherals::GPIOTE0_S.EVENTS_PORT;
  if (uVar2 != 0) {
    Peripherals::GPIOTE0_S.EVENTS_PORT = 0;
    uVar2 = Peripherals::GPIOTE0_S.EVENTS_PORT;
    uVar5 = uVar5 | 0x80000000;
  }
  return uVar5;
}


