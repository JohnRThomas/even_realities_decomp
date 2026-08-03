/*
 * Function: nrfx_wdt_enable
 * Entry:    0006b0d8
 * Prototype: void __stdcall nrfx_wdt_enable(nrfx_wdt_t * p_instance)
 */


/* exclude_from_export */

void nrfx_wdt_enable(nrfx_wdt_t *p_instance)

{
  byte bVar1;
  
  bVar1 = (byte)p_instance[1];
  if ((&wdt_m_cb)[bVar1].alloc_index == '\0') {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","p_cb->alloc_index != 0",
            "WEST_TOPDIR/modules/hal/nordic/nrfx/drivers/src/nrfx_wdt.c",140);
  }
  else {
    if ((&wdt_m_cb.state)[bVar1] == NRFX_DRV_STATE_INITIALIZED) {
      *(undefined4 *)*p_instance = 1;
      (&wdt_m_cb.state)[bVar1] = NRFX_DRV_STATE_POWERED_ON;
      return;
    }
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","p_cb->state == NRFX_DRV_STATE_INITIALIZED",
            "WEST_TOPDIR/modules/hal/nordic/nrfx/drivers/src/nrfx_wdt.c",141);
  }
                    /* WARNING: Subroutine does not return */
  k_panic();
}


