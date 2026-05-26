/*
 * Function: ipc0_ept_bound
 * Entry:    00027d54
 * Prototype: undefined __stdcall ipc0_ept_bound(void)
 */


void ipc0_ept_bound(void)

{
  k_sem_give((k_sem *)&DAT_20003b68);
  return;
}


