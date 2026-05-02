/*
 * Function: FUN_0002c6dc
 * Entry:    0002c6dc
 * Prototype: undefined __stdcall FUN_0002c6dc(void)
 */


void FUN_0002c6dc(void)

{
  if (DAT_20019a56 != '\0') {
    k_sem_give(&nfc_msg_sem);
    return;
  }
  return;
}


