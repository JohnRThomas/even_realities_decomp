/*
 * Function: FUN_000879ac
 * Entry:    000879ac
 * Prototype: nrfx_err_t __stdcall FUN_000879ac(int param_1)
 */


nrfx_err_t FUN_000879ac(int param_1)

{
  nrfx_err_t nVar1;
  uint32_t uVar2;
  char in_stack_00000000;
  
  if (in_stack_00000000 == '\x01') {
    uVar2 = 0xd;
  }
  else if (in_stack_00000000 == '\x02') {
    uVar2 = 0xe;
  }
  else {
    if (in_stack_00000000 != '\0') {
      return 0xffffff7a;
    }
    uVar2 = 0xc;
  }
  nVar1 = FUN_000875be(*(nrfx_twim_t **)(param_1 + 0x1c),(nrfx_twim_xfer_desc_t *)&Reset,uVar2);
  return nVar1;
}


