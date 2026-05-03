/*
 * Function: FUN_000288e4
 * Entry:    000288e4
 * Prototype: float __stdcall FUN_000288e4(int param_1)
 */


float FUN_000288e4(int param_1)

{
  if (*(char *)(param_1 + 0x28) == '\0') {
    FUN_0007fe2e(param_1);
  }
  return *(float *)(param_1 + 0x30) * 57.295;
}


