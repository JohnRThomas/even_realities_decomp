/*
 * Function: FUN_0002c278
 * Entry:    0002c278
 * Prototype: undefined __stdcall FUN_0002c278(void)
 */


void FUN_0002c278(void)

{
  if (IS_SILENT_MODE != '\0') {
    k_sem_give((k_sem *)&DAT_200084fc);
    return;
  }
  return;
}


