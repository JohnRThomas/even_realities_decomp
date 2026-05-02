/*
 * Function: FUN_00088460
 * Entry:    00088460
 * Prototype: nrfx_err_t __stdcall FUN_00088460(int param_1)
 */


nrfx_err_t FUN_00088460(int param_1)

{
  nrfx_err_t nVar1;
  
  if (**(char **)(param_1 + 0x10) != '\0') {
    nVar1 = nrfx_gpiote_channel_get(**(nrfx_gpiote_pin_t **)(param_1 + 4),(uint8_t *)0x7);
    return nVar1;
  }
  return 0xffffffea;
}


