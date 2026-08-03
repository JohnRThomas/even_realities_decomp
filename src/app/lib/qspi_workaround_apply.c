/*
 * Function: qspi_workaround_apply
 * Entry:    00069a88
 * Prototype: void __stdcall qspi_workaround_apply(void)
 */


/* exclude_from_export */

void qspi_workaround_apply(void)

{
  uint uVar1;
  nrf_qspi_pins_t *p_pins;
  NRF_QSPI_Type local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  NRF_QSPI_Type local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 local_18;
  undefined4 uStack_14;
  
  local_28.opaque[0] = 0xff;
  local_28.opaque[1] = 0;
  local_28.opaque[2] = 0;
  local_28.opaque[3] = 0;
  uStack_24 = 0xff;
  uStack_20 = 0xff;
  uStack_1c = 0xff;
  local_18 = 0xff;
  uStack_14 = 0xff;
  uVar1 = Peripherals::QSPI_S._1316_4_;
  local_40.opaque = (byte  [4])(uVar1 & 0xff);
  local_3c = Peripherals::QSPI_S._1320_4_;
  local_3c = local_3c & 0xff;
  local_38 = Peripherals::QSPI_S._1328_4_;
  local_38 = local_38 & 0xff;
  local_34 = Peripherals::QSPI_S._1332_4_;
  local_34 = local_34 & 0xff;
  local_30 = Peripherals::QSPI_S._1336_4_;
  local_30 = local_30 & 0xff;
  local_2c = Peripherals::QSPI_S._1340_4_;
  local_2c = local_2c & 0xff;
  nrf_qspi_pins_set(&local_28,(nrf_qspi_pins_t *)&Peripherals::QSPI_S);
  *(undefined4 *)p_pins[0x40].opaque = 0;
  *(undefined4 *)p_pins->opaque = 1;
  do {
  } while (*(int *)p_pins[0x40].opaque == 0);
  nrf_qspi_pins_set(&local_40,p_pins);
  return;
}


