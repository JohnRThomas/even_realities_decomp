/*
 * Function: adc_context_start_sampling
 * Entry:    000628e4
 * Prototype: void __stdcall adc_context_start_sampling(adc_context * ctx)
 */


/* exclude_from_export */

void adc_context_start_sampling(adc_context *ctx)

{
  Peripherals::SAADC_S.ENABLE = 1;
  if ((char)ctx[3].options != '\0') {
    Peripherals::SAADC_S.TASKS_CALIBRATEOFFSET = 1;
    return;
  }
  Peripherals::SAADC_S.TASKS_START = 1;
  Peripherals::SAADC_S.TASKS_SAMPLE = 1;
  return;
}


