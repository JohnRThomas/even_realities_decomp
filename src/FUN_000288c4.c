/*
 * Function: FUN_000288c4
 * Entry:    000288c4
 * Prototype: float __stdcall FUN_000288c4(int param_1)
 */


float FUN_000288c4(int param_1)

{
  if (*(char *)(param_1 + 0x28) == '\0') {
    FUN_0007fe2e(param_1);
  }
  return *(float *)(param_1 + 0x2c) * 57.295;
}


