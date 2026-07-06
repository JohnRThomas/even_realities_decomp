/*
 * Function: spi_tx_frame
 * Entry:    00080f80
 * Prototype: int __stdcall spi_tx_frame(JBD013VGA_SPI param_1, void * param_2, size_t param_3)
 */


int spi_tx_frame(JBD013VGA_SPI param_1,void *param_2,size_t param_3)

{
  int iVar1;
  undefined4 local_10;
  void *pvStack_c;
  
  local_10 = (uint)param_1;
  pvStack_c = param_2;
  memcpy((void *)((int)&local_10 + 1),param_2,param_3);
  iVar1 = __jdb_api_FUN_00080f08((int)&local_10,param_3 + 1);
  return iVar1;
}


