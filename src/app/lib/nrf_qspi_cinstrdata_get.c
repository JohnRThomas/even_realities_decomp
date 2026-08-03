/*
 * Function: nrf_qspi_cinstrdata_get
 * Entry:    00069988
 * Prototype: void __stdcall nrf_qspi_cinstrdata_get(NRF_QSPI_Type * p_reg, nrf_qspi_cinstr_len_t length, void * p_rx_data)
 */


/* exclude_from_export */

void nrf_qspi_cinstrdata_get(NRF_QSPI_Type *p_reg,nrf_qspi_cinstr_len_t length,void *p_rx_data)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = Peripherals::QSPI_S.CINSTRDAT1;
  uVar1 = Peripherals::QSPI_S.CINSTRDAT0;
  switch(p_reg) {
  case (NRF_QSPI_Type *)0x9:
    *(char *)(length + 7) = (char)(uVar2 >> 0x18);
  case (NRF_QSPI_Type *)0x8:
    *(char *)(length + 6) = (char)(uVar2 >> 0x10);
  case (NRF_QSPI_Type *)0x7:
    *(char *)(length + 5) = (char)(uVar2 >> 8);
  case (NRF_QSPI_Type *)0x6:
    *(char *)(length + 4) = (char)uVar2;
  case (NRF_QSPI_Type *)0x5:
    *(char *)(length + 3) = (char)(uVar1 >> 0x18);
  case (NRF_QSPI_Type *)0x4:
    *(char *)(length + 2) = (char)(uVar1 >> 0x10);
  case (NRF_QSPI_Type *)0x3:
    *(char *)(length + 1) = (char)(uVar1 >> 8);
  case (NRF_QSPI_Type *)0x2:
    *(char *)length = (char)uVar1;
    return;
  default:
    return;
  }
}


