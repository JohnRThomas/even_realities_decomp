/*
 * Function: FUN_00080dbc
 * Entry:    00080dbc
 * Prototype: undefined __stdcall FUN_00080dbc(int param_1)
 */


void FUN_00080dbc(int param_1)

{
  __clr_cache(param_1);
  __send_cmd(SPI_SYNC);
  delay_ms(1);
  return;
}


