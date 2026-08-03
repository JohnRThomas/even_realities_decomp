/*
 * Function: clkstarted_handle
 * Entry:    000638a0
 * Prototype: undefined __stdcall clkstarted_handle(int param_1)
 */


/* exclude_from_export */

void clkstarted_handle(int param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = (code *)(&__CLOCK_DEVICE.name)[param_1 * 3];
  (&__CLOCK_DEVICE.name)[param_1 * 3] = (undefined *)0x0;
  set_on_state((uint32_t *)(&__CLOCK_DEVICE.api + param_1 * 3));
  if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000638ca. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(&PTR_s_clock_5000_0008b2e0);
    return;
  }
  return;
}


