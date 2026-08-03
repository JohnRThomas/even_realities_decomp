/*
 * Function: nrfx_qspi_uninit
 * Entry:    00069dcc
 * Prototype: void __stdcall nrfx_qspi_uninit(void)
 */


/* exclude_from_export */

void nrfx_qspi_uninit(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  if (qspi_m_cb.state == NRFX_QSPI_STATE_UNINITIALIZED) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","m_cb.state != NRFX_QSPI_STATE_UNINITIALIZED",
            "WEST_TOPDIR/modules/hal/nordic/nrfx/drivers/src/nrfx_qspi.c",689);
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  arch_irq_disable(0x2b);
  qspi_deactivate();
  if (qspi_m_cb.skip_gpio_cfg == false) {
    uVar1 = Peripherals::QSPI_S._1316_4_;
    uVar2 = Peripherals::QSPI_S._1320_4_;
    uVar3 = Peripherals::QSPI_S._1328_4_;
    uVar4 = Peripherals::QSPI_S._1332_4_;
    uVar5 = Peripherals::QSPI_S._1336_4_;
    uVar6 = Peripherals::QSPI_S._1340_4_;
    nrf_gpio_cfg_default(uVar1 & 0xff);
    nrf_gpio_cfg_default(uVar2 & 0xff);
    nrf_gpio_cfg_default(uVar3 & 0xff);
    nrf_gpio_cfg_default(uVar4 & 0xff);
    if ((uVar5 & 0xff) != 0xff) {
      nrf_gpio_cfg_default(uVar5 & 0xff);
    }
    if ((uVar6 & 0xff) != 0xff) {
      nrf_gpio_cfg_default(uVar6 & 0xff);
    }
  }
  qspi_m_cb.state = NRFX_QSPI_STATE_UNINITIALIZED;
  return;
}


