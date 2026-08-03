/*
 * Function: nrfx_gppi_task_endpoint_clear
 * Entry:    0006827c
 * Prototype: void __stdcall nrfx_gppi_task_endpoint_clear(uint8_t channel, uint32_t tep)
 */


/* exclude_from_export */

void nrfx_gppi_task_endpoint_clear(uint8_t channel,uint32_t tep)

{
  if (tep == 0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","tep",
            "WEST_TOPDIR/modules/hal/nordic/nrfx/helpers/nrfx_gppi_dppi.c",99);
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  *(undefined4 *)(tep + 0x80) = 0;
  return;
}


