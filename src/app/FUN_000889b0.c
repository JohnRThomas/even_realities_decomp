/*
 * Function: FUN_000889b0
 * Entry:    000889b0
 * Prototype: undefined __stdcall FUN_000889b0(void * param_1, size_t param_2, uint32_t param_3)
 */


void FUN_000889b0(void *param_1,size_t param_2,uint32_t param_3)

{
  qspi_xfer(param_1,param_2,param_3,2);
  return;
}


