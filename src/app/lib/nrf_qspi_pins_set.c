/*
 * Function: nrf_qspi_pins_set
 * Entry:    00069a2c
 * Prototype: void __stdcall nrf_qspi_pins_set(NRF_QSPI_Type * p_reg, nrf_qspi_pins_t * p_pins)
 */


/* exclude_from_export */

void nrf_qspi_pins_set(NRF_QSPI_Type *p_reg,nrf_qspi_pins_t *p_pins)

{
  int iVar1;
  
  iVar1 = *(int *)p_reg->opaque;
  if (iVar1 == 0xff) {
    iVar1 = -1;
  }
  Peripherals::QSPI_S._1316_4_ = iVar1;
  iVar1 = *(int *)p_reg[1].opaque;
  if (iVar1 == 0xff) {
    iVar1 = -1;
  }
  Peripherals::QSPI_S._1320_4_ = iVar1;
  iVar1 = *(int *)p_reg[2].opaque;
  if (iVar1 == 0xff) {
    iVar1 = -1;
  }
  Peripherals::QSPI_S._1328_4_ = iVar1;
  iVar1 = *(int *)p_reg[3].opaque;
  if (iVar1 == 0xff) {
    iVar1 = -1;
  }
  Peripherals::QSPI_S._1332_4_ = iVar1;
  iVar1 = *(int *)p_reg[4].opaque;
  if (iVar1 == 0xff) {
    iVar1 = -1;
  }
  Peripherals::QSPI_S._1336_4_ = iVar1;
  iVar1 = *(int *)p_reg[5].opaque;
  if (iVar1 == 0xff) {
    iVar1 = -1;
  }
  Peripherals::QSPI_S._1340_4_ = iVar1;
  return;
}


