/*
 * Function: FUN_0007fdb6
 * Entry:    0007fdb6
 * Prototype: undefined __stdcall FUN_0007fdb6(int param_1, int param_2)
 */


void FUN_0007fdb6(int param_1,int param_2)

{
  if (*(int *)(param_1 + 0x18) != param_2) {
    *(int *)(param_1 + 0x18) = param_2;
  }
  return;
}


