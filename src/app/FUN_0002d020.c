/*
 * Function: FUN_0002d020
 * Entry:    0002d020
 * Prototype: nrfx_err_t __stdcall FUN_0002d020(void)
 */


nrfx_err_t FUN_0002d020(void)

{
  nrfx_err_t nVar1;
  int iVar2;
  
  iVar2 = 5;
  do {
    nVar1 = FUN_0008842e(0x8b478,DAT_20008530);
    if (nVar1 == 0) {
      return 0;
    }
    z_impl_k_sleep((k_timeout_t)0x667);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return nVar1;
}


