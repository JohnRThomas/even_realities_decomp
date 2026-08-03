/*
 * Function: set_power_state
 * Entry:    00066ebc
 * Prototype: void __stdcall set_power_state(power_state state)
 */


/* exclude_from_export */

void set_power_state(power_state state)

{
  if (power_state_2001e2d7 == POWER_STATE_IDLE) {
    if (state != POWER_STATE_IDLE) {
      k_work_cancel_delayable((k_work_delayable *)&power_down_trigger);
    }
  }
  else if (state == POWER_STATE_IDLE) {
    power_down_counter_reset();
  }
  power_state_2001e2d7 = state;
  return;
}


