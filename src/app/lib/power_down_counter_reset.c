/*
 * Function: power_down_counter_reset
 * Entry:    00066e88
 * Prototype: void __stdcall power_down_counter_reset(void)
 */


/* exclude_from_export */

void power_down_counter_reset(void)

{
  bool bVar1;
  undefined4 extraout_r1;
  power_state uVar2;
  k_timeout_t delay;
  
  _uVar2 = (uint)power_state_2001e2d7;
  if ((_uVar2 == 0) && (bVar1 = check_if_power_state_allowed(POWER_MANAGER_LEVEL_SUSPENDED), bVar1))
  {
    delay.ticks._4_4_ = 0x8000;
    delay.ticks._0_4_ = extraout_r1;
    power_down_interval_counter = _uVar2;
    k_work_reschedule((k_work_delayable *)&power_down_trigger,delay);
    return;
  }
  return;
}


