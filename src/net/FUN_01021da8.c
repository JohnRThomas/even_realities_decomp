/*
 * Function: FUN_01021da8
 * Entry:    01021da8
 * Prototype: undefined __stdcall FUN_01021da8(uint param_1)
 */


void FUN_01021da8(uint param_1)

{
  if (0 < (int)param_1) {
    Peripherals::VREQCTRL_NS.VREGRADIO_VREQH = 1;
    Peripherals::RADIO_NS.TXPOWER = param_1 - 3 & 0xff;
    return;
  }
  Peripherals::VREQCTRL_NS.VREGRADIO_VREQH = 0;
  Peripherals::RADIO_NS.TXPOWER = param_1 & 0xff;
  return;
}


