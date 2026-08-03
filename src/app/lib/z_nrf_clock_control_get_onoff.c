/*
 * Function: z_nrf_clock_control_get_onoff
 * Entry:    00063a1c
 * Prototype: onoff_manager * __stdcall z_nrf_clock_control_get_onoff(clock_control_subsys_t sys)
 */


/* exclude_from_export */

onoff_manager * z_nrf_clock_control_get_onoff(clock_control_subsys_t sys)

{
  return (onoff_manager *)(&DAT_2000ba80 + (sys & 0xffU) * 0x20);
}


