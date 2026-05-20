/*
 * Function: FUN_00088444
 * Entry:    00088444
 * Prototype: undefined __stdcall FUN_00088444(int param_1)
 */


void FUN_00088444(int param_1)

{
  nrfx_err_t nVar1;
  undefined1 *puVar2;
  
  puVar2 = *(undefined1 **)(param_1 + 0x10);
  nVar1 = nrfx_gpiote_channel_get(**(nrfx_gpiote_pin_t **)(param_1 + 4),&DAT_00000007);
  if (-1 < (int)nVar1) {
    *puVar2 = 0;
  }
  return;
}


