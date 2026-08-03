/*
 * Function: nrfx_clock_enable
 * Entry:    00068480
 * Prototype: void __stdcall nrfx_clock_enable(void)
 */


/* exclude_from_export */

void nrfx_clock_enable(void)

{
  int iVar1;
  char *in_r1;
  metal_device **in_r2;
  
  if (!m_clock_cb.module_initialized) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","m_clock_cb.module_initialized",
            "WEST_TOPDIR/modules/hal/nordic/nrfx/drivers/src/nrfx_clock.c",302);
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  iVar1 = metal_generic_dev_open((metal_bus *)&DAT_00000005,in_r1,in_r2);
  if (iVar1 == 0) {
    arch_irq_enable(5);
  }
  Peripherals::CLOCK_S.LFCLKSRC = 1;
  Peripherals::CLOCK_S.HFCLKSRC = 1;
  Peripherals::CLOCK_S.HFCLK192MSRC = 1;
  return;
}


