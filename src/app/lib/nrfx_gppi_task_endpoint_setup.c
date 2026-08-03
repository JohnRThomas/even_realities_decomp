/*
 * Function: nrfx_gppi_task_endpoint_setup
 * Entry:    00068220
 * Prototype: void __stdcall nrfx_gppi_task_endpoint_setup(uint8_t channel, uint32_t tep)
 */


/* exclude_from_export */

void nrfx_gppi_task_endpoint_setup(uint8_t channel,uint32_t tep)

{
  if (tep == 0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","tep",
            "WEST_TOPDIR/modules/hal/nordic/nrfx/helpers/nrfx_gppi_dppi.c",74);
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  *(uint *)(tep + 0x80) = channel | 0x80000000;
  return;
}


