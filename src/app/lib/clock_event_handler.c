/*
 * Function: clock_event_handler
 * Entry:    000638d8
 * Prototype: void __stdcall clock_event_handler(nrfx_clock_evt_type_t event)
 */


/* exclude_from_export */

void clock_event_handler(nrfx_clock_evt_type_t event)

{
  int iVar1;
  
  switch(event) {
  case NRFX_CLOCK_EVT_HFCLK_STARTED:
    iVar1 = 0;
    if (((uint)__CLOCK_DEVICE.api & 7) != 0) {
      return;
    }
    break;
  case NRFX_CLOCK_EVT_LFCLK_STARTED:
    iVar1 = 1;
    break;
  default:
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","0",
            "WEST_TOPDIR/zephyr/drivers/clock_control/clock_control_nrf.c",626);
    goto LAB_0006391c;
  case NRFX_CLOCK_EVT_CAL_DONE:
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","0",
            "WEST_TOPDIR/zephyr/drivers/clock_control/clock_control_nrf.c",0x26e);
LAB_0006391c:
                    /* WARNING: Subroutine does not return */
    k_panic();
  case NRFX_CLOCK_EVT_HFCLKAUDIO_STARTED:
    iVar1 = 3;
    break;
  case NRFX_CLOCK_EVT_HFCLK192M_STARTED:
    iVar1 = 2;
  }
  clkstarted_handle(iVar1);
  return;
}


