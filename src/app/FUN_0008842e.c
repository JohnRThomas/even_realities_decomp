/*
 * Function: FUN_0008842e
 * Entry:    0008842e
 * Prototype: nrfx_err_t __stdcall FUN_0008842e(int param_1, int param_2)
 */


nrfx_err_t FUN_0008842e(int param_1,int param_2)

{
  nrfx_err_t nVar1;
  
  if (param_2 == 0) {
    nVar1 = nrfx_gpiote_channel_get(**(nrfx_gpiote_pin_t **)(param_1 + 4),&DAT_00000007);
    return nVar1;
  }
  return 0xffffffea;
}


