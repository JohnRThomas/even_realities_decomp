/*
 * Function: clock_control_async_on
 * Entry:    0006374c
 * Prototype: uint __stdcall clock_control_async_on(int param_1, byte param_2)
 */


/* exclude_from_export_ai */

uint clock_control_async_on(int param_1,byte param_2)

{
  if (3 < param_2) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","type < CLOCK_CONTROL_NRF_TYPE_COUNT",
            "WEST_TOPDIR/zephyr/drivers/clock_control/clock_control_nrf.c",0x7a);
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  return *(uint *)((uint)param_2 * 0xc + *(int *)(param_1 + 0x10) + 0x88) & 7;
}


