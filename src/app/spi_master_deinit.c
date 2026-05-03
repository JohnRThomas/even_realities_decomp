/*
 * Function: spi_master_deinit
 * Entry:    00028414
 * Prototype: undefined4 __stdcall spi_master_deinit(int param_1)
 */


undefined4 spi_master_deinit(int param_1)

{
  int iVar1;
  SPIM4_S *pSVar2;
  uint uVar3;
  SPIM4_S **ppSVar4;
  SPIM3_S *local_30;
  undefined1 local_2c;
  SPIM4_S *local_28;
  undefined1 local_24;
  
  iVar1 = LOG_LEVEL;
  local_30 = &Peripherals::SPIM3_S;
  local_2c = 0;
  local_28 = &Peripherals::SPIM4_S;
  local_24 = 1;
  if (*(int *)(param_1 + 0x14) != 0) {
    uVar3 = (uint)*(byte *)(param_1 + 0x18);
    if (uVar3 == 3) {
      ppSVar4 = (SPIM4_S **)&local_30;
    }
    else {
      if (uVar3 != 4) {
        if (LOG_LEVEL < 1) {
          return 0;
        }
        if (BLE_DEBUG != 0) {
          ble_printk("%s():  SPIM BUS ERR!\n","spi_master_deinit",uVar3,BLE_DEBUG);
          return 0;
        }
        printk("%s():  SPIM BUS ERR!\n");
        return 0;
      }
      ppSVar4 = &local_28;
    }
    pSVar2 = ppSVar4[1];
    *(SPIM4_S **)(param_1 + 0xc) = *ppSVar4;
    *(SPIM4_S **)(param_1 + 0x10) = pSVar2;
    if (2 < iVar1) {
      if (BLE_DEBUG == 0) {
        printk("%s(): *SPIM(%d)speed=%dM, sck=%d, mosi=%d, miso=%d, ss=%d\n","spi_master_deinit",
               uVar3,(uint)*(byte *)(param_1 + 0x1d),(uint)*(byte *)(param_1 + 0x19),
               (uint)*(byte *)(param_1 + 0x1a),(uint)*(byte *)(param_1 + 0x1b),
               (uint)*(byte *)(param_1 + 0x1c));
      }
      else {
        ble_printk("%s(): *SPIM(%d)speed=%dM, sck=%d, mosi=%d, miso=%d, ss=%d\n","spi_master_deinit"
                   ,uVar3,(uint)*(byte *)(param_1 + 0x1d));
      }
    }
    nrfx_spim_uninit((nrfx_spim_t *)(param_1 + 0xc));
    if (2 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): spim(bus=%d): uninit finish\n");
      }
      else {
        ble_printk("%s(): spim(bus=%d): uninit finish\n","spi_master_deinit",
                   (uint)*(byte *)(param_1 + 0x18),BLE_DEBUG);
      }
    }
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  return 0;
}


