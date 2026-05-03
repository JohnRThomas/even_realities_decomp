/*
 * Function: FUN_00087082
 * Entry:    00087082
 * Prototype: undefined __stdcall FUN_00087082(int param_1, int param_2)
 */


void FUN_00087082(int param_1,int param_2)

{
  if (param_1 == 0) {
    k_sem_give((k_sem *)(param_2 + 0x30));
    return;
  }
  return;
}


