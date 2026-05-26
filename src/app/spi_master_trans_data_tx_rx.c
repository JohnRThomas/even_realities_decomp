/*
 * Function: spi_master_trans_data_tx_rx
 * Entry:    00028388
 * Prototype: undefined4 __stdcall spi_master_trans_data_tx_rx(int param_1, nrfx_spim_xfer_desc_t param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5)
 */


undefined4
spi_master_trans_data_tx_rx
          (int param_1,nrfx_spim_xfer_desc_t param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5)

{
  nrfx_err_t nVar1;
  nrfx_spim_xfer_desc_t local_18;
  undefined4 uStack_14;
  undefined4 local_10;
  undefined4 local_c;
  
  local_c = param_5;
  local_18 = param_2;
  uStack_14 = param_3;
  local_10 = param_4;
  if (*(int *)(param_1 + 0x14) == 0) {
    if (0 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): wait init_done.\n");
      }
      else {
        ble_printk("%s(): wait init_done.\n","spi_master_trans_data_tx_rx",param_3,BLE_DEBUG);
      }
    }
  }
  else {
    nVar1 = nrfx_spim_xfer((nrfx_spim_t *)(param_1 + 0xc),&local_18,0);
    if ((undefined1 *)(uint)nVar1 == &DAT_0bad0000) {
      return 0;
    }
    if (0 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): sipm(bus=%d)-sync fail: status: %d -- %d\n");
      }
      else {
        ble_printk("%s(): sipm(bus=%d)-sync fail: status: %d -- %d\n","spi_master_trans_data_tx_rx",
                   (uint)*(byte *)(param_1 + 0x18),(undefined1 *)(uint)nVar1);
      }
    }
  }
  return 0xffffffff;
}


