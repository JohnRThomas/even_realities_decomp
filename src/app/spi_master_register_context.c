/*
 * Function: spi_master_register_context
 * Entry:    00028678
 * Prototype: undefined __stdcall spi_master_register_context(spi_master_callbacks * param_1)
 */


void spi_master_register_context(spi_master_callbacks *param_1)

{
  param_1->init_cb = 0x284f5;
  param_1->rx_tx = 0x28389;
  param_1->deinit = 0x28415;
  return;
}


