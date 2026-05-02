/*
 * Function: FUN_00087a26
 * Entry:    00087a26
 * Prototype: nrfx_err_t __stdcall FUN_00087a26(int param_1, undefined4 param_2, int param_3)
 */


nrfx_err_t FUN_00087a26(int param_1,undefined4 param_2,int param_3)

{
  nrfx_err_t nVar1;
  
  if ((param_3 != 0) && (param_3 != 1)) {
    return 0xffffff7a;
  }
  nVar1 = nrfx_gpiote_channel_get(*(nrfx_gpiote_pin_t *)(param_1 + 0x1c),&Reset);
  return nVar1;
}


