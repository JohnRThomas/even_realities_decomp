/*
 * Function: power_down
 * Entry:    00066f68
 * Prototype: undefined __stdcall power_down(undefined4 param_1, undefined4 param_2)
 */


/* exclude_from_export */

void power_down(undefined4 param_1,undefined4 param_2)

{
  k_timeout_t delay;
  
  if (power_state != '\0') {
    power_state = 0;
    power_down_counter_reset();
    return;
  }
  power_down_interval_counter = power_down_interval_counter + 1;
  if (power_down_interval_counter < 3) {
    delay.ticks._4_4_ = 0x8000;
    delay.ticks._0_4_ = param_2;
    k_work_reschedule((k_work_delayable *)&power_down_trigger,delay);
    return;
  }
  power_down();
  return;
}


