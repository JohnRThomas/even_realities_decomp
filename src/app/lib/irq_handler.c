/*
 * Function: irq_handler
 * Entry:    0006b208
 * Prototype: void __stdcall irq_handler(NRF_WDT_Type * p_reg, wdt_control_block_t * p_cb)
 */


/* exclude_from_export */

void irq_handler(NRF_WDT_Type *p_reg,wdt_control_block_t *p_cb)

{
  uint uVar1;
  uint requests;
  
  requests = Peripherals::WDT0_S.REQSTATUS;
  uVar1 = Peripherals::WDT0_S.EVENTS_TIMEOUT;
  if (uVar1 != 0) {
    Peripherals::WDT0_S.EVENTS_TIMEOUT = 0;
    uVar1 = Peripherals::WDT0_S.EVENTS_TIMEOUT;
                    /* WARNING: Could not recover jumptable at 0x0006b222. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*wdt_m_cb.wdt_event_handler)(requests);
    return;
  }
  return;
}


