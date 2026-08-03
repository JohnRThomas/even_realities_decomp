/*
 * Function: nrfx_gppi_event_endpoint_clear
 * Entry:    00068250
 * Prototype: void __stdcall nrfx_gppi_event_endpoint_clear(uint8_t channel, uint32_t eep)
 */


/* exclude_from_export */

void nrfx_gppi_event_endpoint_clear(uint8_t channel,uint32_t eep)

{
  if (eep == 0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","eep",
            "WEST_TOPDIR/modules/hal/nordic/nrfx/helpers/nrfx_gppi_dppi.c",92);
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  *(undefined4 *)(eep + 0x80) = 0;
  return;
}


