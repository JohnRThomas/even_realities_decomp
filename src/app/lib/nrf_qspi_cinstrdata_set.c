/*
 * Function: nrf_qspi_cinstrdata_set
 * Entry:    000699c8
 * Prototype: void __stdcall nrf_qspi_cinstrdata_set(NRF_QSPI_Type * p_reg, nrf_qspi_cinstr_len_t length, void * p_tx_data)
 */


/* exclude_from_export */

void nrf_qspi_cinstrdata_set(NRF_QSPI_Type *p_reg,nrf_qspi_cinstr_len_t length,void *p_tx_data)

{
  uint uVar1;
  
  switch(p_reg) {
  case (NRF_QSPI_Type *)0x2:
    uVar1 = 0;
    goto LAB_00069a04;
  case (NRF_QSPI_Type *)0x3:
    uVar1 = 0;
    goto LAB_000699fe;
  case (NRF_QSPI_Type *)0x4:
    uVar1 = 0;
    goto LAB_000699f8;
  case (NRF_QSPI_Type *)0x5:
    goto switchD_000699ce_caseD_5;
  case (NRF_QSPI_Type *)0x6:
    uVar1 = 0;
    goto LAB_000699ea;
  case (NRF_QSPI_Type *)0x7:
    uVar1 = 0;
    goto LAB_000699e4;
  case (NRF_QSPI_Type *)0x8:
    uVar1 = 0;
    break;
  case (NRF_QSPI_Type *)0x9:
    uVar1 = (uint)*(byte *)(length + 7) << 0x18;
    break;
  default:
    goto switchD_000699ce_default;
  }
  uVar1 = uVar1 | (uint)*(byte *)(length + 6) << 0x10;
LAB_000699e4:
  uVar1 = uVar1 | (uint)*(byte *)(length + 5) << 8;
LAB_000699ea:
  Peripherals::QSPI_S.CINSTRDAT1 = uVar1 | *(byte *)(length + 4);
switchD_000699ce_caseD_5:
  uVar1 = (uint)*(byte *)(length + 3) << 0x18;
LAB_000699f8:
  uVar1 = uVar1 | (uint)*(byte *)(length + 2) << 0x10;
LAB_000699fe:
  uVar1 = uVar1 | (uint)*(byte *)(length + 1) << 8;
LAB_00069a04:
  Peripherals::QSPI_S.CINSTRDAT0 = uVar1 | *(byte *)length;
switchD_000699ce_default:
  return;
}


