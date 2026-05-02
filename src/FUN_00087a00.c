/*
 * Function: FUN_00087a00
 * Entry:    00087a00
 * Prototype: nrfx_err_t __stdcall FUN_00087a00(int param_1, undefined4 param_2, int param_3)
 */


nrfx_err_t FUN_00087a00(int param_1,undefined4 param_2,int param_3)

{
  nrfx_err_t nVar1;
  
  if ((param_3 != 2) && (param_3 != 3)) {
    return 0xffffff7a;
  }
  nVar1 = nrfx_gpiote_channel_get(*(nrfx_gpiote_pin_t *)(param_1 + 0x1c),&NMI);
  return nVar1;
}


