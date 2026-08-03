/*
 * Function: nrfx_gppi_event_endpoint_setup
 * Entry:    000681f0
 * Prototype: void __stdcall nrfx_gppi_event_endpoint_setup(uint8_t channel, uint32_t eep)
 */


/* exclude_from_export */

void nrfx_gppi_event_endpoint_setup(uint8_t channel,uint32_t eep)

{
  if (eep == 0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","eep",
            "WEST_TOPDIR/modules/hal/nordic/nrfx/helpers/nrfx_gppi_dppi.c",68);
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  *(uint *)(eep + 0x80) = channel | 0x80000000;
  return;
}


