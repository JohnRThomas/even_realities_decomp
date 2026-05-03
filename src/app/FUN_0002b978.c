/*
 * Function: FUN_0002b978
 * Entry:    0002b978
 * Prototype: undefined __stdcall FUN_0002b978(void)
 */


void FUN_0002b978(void)

{
  int iVar1;
  
  iVar1 = z_impl_k_sem_init((k_sem *)&DAT_200084fc,0,5);
  if (iVar1 == 0) {
    IS_SILENT_MODE = 1;
  }
  return;
}


